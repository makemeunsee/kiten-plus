#include "mainwindow.h"
#include <QFileDialog>
#include <QApplication>
#include <QMessageBox>
#include <QStatusBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QScrollArea>
#include "../JapaneseDB/kanjidb.h"
#include "../JapaneseDB/kanji.h"
#include "../JapaneseDB/radicals.h"
#include "resultsbuffer.h"
#include "kanjidetails.h"
#include "searchbar.h"
#include "ui_searchbar.h"
#include <QMessageBox>
//#include <QTextStream>
//#include <QTextCodec>

const int MainWindow::searchLimit = 20;
const QString MainWindow::historyFilename("kitenplus.history");

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    prefDial = new PreferencesDialog(this);
    icon = QIcon("icons/katen.png");
    prefIcon = QIcon("icons/tool.png");
    setWindowIcon(icon);
    buffer = new ResultsBuffer(history);
    createWidgets();
    setWindowTitle(tr("Kiten+"));
    resize(600, 400);
    statusBar()->showMessage(tr("Ready"));
    searchThread = new SearchThread;
    // listen to end of search to display results
    qRegisterMetaType<KanjiSet*>("KanjiSet*");
    connect(searchThread, SIGNAL(searchFinished(QString *, KanjiSet *)), this, SLOT(done(QString *, KanjiSet *)));
    // debug popup info
    //connect(searchThread, SIGNAL(threadInfo(QString)), this, SLOT(popUpInfo(QString)));
    searchBar->setFocus();
    move(320,240);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QFile historyFile(historyFullPath);
    if (historyFile.open(QIODevice::WriteOnly)) {
        history.write(historyFile);
        historyFile.close();
    } else
    {
        //TODO log: history unwritable
    }
    QMainWindow::closeEvent(event);
}

void MainWindow::moveEvent(QMoveEvent *e)
{
    searchBar->movePopup(e);
}

void MainWindow::setUserResourceDir(const QString &dirname)
{
    resourceDir = QDir(dirname);
    readResources();
}

void MainWindow::readResources()
{
    QDir portableDir = QDir::currentPath();

    int kanjidicState = kanjidic.readResources(portableDir);
    if(kanjidicState == KanjiDB::noDataRead)
    {
        //TODO log not portable mode
        kanjidicState = kanjidic.readResources(resourceDir);
    } else {
        resourceDir = portableDir;
    }

    if(kanjidicState == KanjiDB::noDataRead)
        QMessageBox::warning(this, tr("Kanjidic resources"),
                          tr("Unable to read resources. No kanji data will be available.\nError message:\n%1")
                          .arg(kanjidic.errorString()));
    else
    {
        if(kanjidicState == KanjiDB::baseDataRead)
            QMessageBox::warning(this, tr("Kanjidic resources"),
                              tr("Unable to read some resources, some radical functionalities will be missing.\nError message:\n%1")
                              .arg(kanjidic.errorString()));
        else if(kanjidicState == KanjiDB::allDataReadButNotSaved)
            QMessageBox::warning(this, tr("Kanjidic resources"),
                              tr("Unable to save resource indexes. Error message:\n%1")
                              .arg(kanjidic.errorString()));

        statusBar()->showMessage(tr("File loaded"), 2000);
        searchBar->radicalSelectionForm()->setKanjiDB(kanjidic);
        searchBar->componentSelectionForm()->setKanjiDB(kanjidic);
        QFile historyFile(resourceDir.absolutePath().append("/").append(historyFilename));
        historyFullPath = historyFile.fileName();
        if (historyFile.open(QIODevice::ReadOnly)) {
            history.read(historyFile);
            historyFile.close();
        } else
        {
            //TODO log: no history found
        }
    }


//    QFile tmp1("out_components");
//    tmp1.open(QIODevice::WriteOnly);
//    QTextStream stream1(&tmp1);
//    stream1.setCodec(QTextCodec::codecForName("UTF-8"));
//    for(int i = 0; i < kanjidic.getAllComponents().size(); ++i)
//        stream1 << QString::number(kanjidic.getComponentById(i)->getUnicode()) << " " << kanjidic.getComponentById(i)->getLiteral() << endl;
//    tmp1.close();

//    QFile tmp2("out_radicals");
//    tmp2.open(QIODevice::WriteOnly);
//    QTextStream stream2(&tmp2);
//    stream2.setCodec(QTextCodec::codecForName("UTF-8"));
//    for(int i = 0; i < Radicals::radicalsSize; ++i)
//    {
//        QChar ch = Radicals::radicals[i].at(0);
//        stream2 << QString::number(ch.unicode()) << " " << ch << endl;
//        foreach(Unicode c, kanjidic.getRadicalVariant(ch.unicode())->getUnicodeVariants())
//            stream2 << QString::number(c) << " " << kanjidic.getRadicalVariant(c)->getLiteral() << endl;
//    }
//    tmp2.close();
}

void MainWindow::createWidgets()
{
    resultWidgets.append(new QLabel(""));
    resultLayout = new QVBoxLayout();
    resultLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    resultLayout->addWidget(resultWidgets.at(0), 0, Qt::AlignTop);
    QScrollArea *area = new QScrollArea();
    QWidget *widget = new QWidget();
    widget->setLayout(resultLayout);
    area->setWidget(widget);

    searchBar = new SearchBar(history, this);
    connect(buffer, SIGNAL(changed()), searchBar, SLOT(updateBackAndForth()));

    QPushButton *preferences = new QPushButton(prefIcon, "");
    connect(preferences, SIGNAL(clicked()), this, SLOT(showPrefs()));

    QHBoxLayout *upperLayout = new QHBoxLayout();
    upperLayout->addWidget(searchBar);
    upperLayout->addWidget(preferences);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(upperLayout);
    mainLayout->addWidget(area);
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

void MainWindow::clearPreviousSearch()
{
    //clean previous search
    foreach(QWidget *resultWidget, resultWidgets)
    {
        resultLayout->removeWidget(resultWidget);
        delete resultWidget;
    }
    resultWidgets.clear();
}

void MainWindow::search(const QString &s)
{
    KanjiSet *results = new KanjiSet;
    QString *searchString = new QString(s);
    // deactivate all widgets except stop button
    lockGui(true);
    // execute search in separate thread
    searchThread->search(&kanjidic, searchString, results);
}

void MainWindow::popUpInfo(QString s)
{
    QMessageBox b;
    b.setText(s);
    b.exec();
}

void MainWindow::done(QString *s, KanjiSet *results)
{
    // reactivate all widgets, deactivate stop button
    lockGui(false);

    showSearchResults(*s, *results);
    buffer->newRequestAndResult(s, results);
}

void MainWindow::lockGui(bool lock)
{
    searchBar->lock(lock);
    resultLayout->setEnabled(!lock);
}

void MainWindow::showSearchResults(const QString &request, const KanjiSet &results)
{
    clearPreviousSearch();
    searchBar->setText(request);

    bool found = false;
    int size = results.size();
    if(size > 0)
    {
        if(size > searchLimit)
            statusBar()->showMessage(tr("Displaying %1 results of %2 found").arg(searchLimit).arg(size));
        else
            statusBar()->showMessage(tr("%1 results").arg(size));
        int count = 0;
        foreach(Kanji *k, results)
        {
            if(count == searchLimit)
                break;
            resultWidgets.append(new KanjiDetails(this, k, kanjidic));
            ++count;
        }
        found = true;
    } else
    {
        statusBar()->showMessage(tr("No result"));
        resultWidgets.append(new QLabel(tr("Request \"%1\" yielded no result.").arg(searchBar->text())));
    }

    foreach(QWidget *resultWidget, resultWidgets)
        resultLayout->addWidget(resultWidget, 0, Qt::AlignTop);
    resultLayout->parentWidget()->adjustSize();

    if(found)
        resultWidgets.at(0)->setFocus();
    else
        searchBar->setFocus();
}

void MainWindow::back()
{
    buffer->previous();
    showSearchResults(*buffer->getCurrentRequest(), *buffer->getCurrentResults());
}

void MainWindow::forth()
{
    buffer->next();
    showSearchResults(*buffer->getCurrentRequest(), *buffer->getCurrentResults());
}

void MainWindow::showPrefs()
{
    prefDial->show();
}

ResultsBuffer *MainWindow::resultsBuffer()
{
    return buffer;
}

const ResultsBuffer *MainWindow::resultsBuffer() const
{
    return buffer;
}
