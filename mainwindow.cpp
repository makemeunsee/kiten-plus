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
#include "resultsbuffer.h"
#include "kanjidetails.h"
#include "searchbar.h"
#include "ui_searchbar.h"
#include <QMessageBox>
#include <QDataStream>


const int MainWindow::searchLimit = 20;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    buffer = new ResultsBuffer;
    createWidgets();
    setWindowTitle(tr("Kiten+"));
    resize(600, 400);
    statusBar()->showMessage(tr("Ready"));
    searchThread = new SearchThread;
    // listen to end of search to display results
    qRegisterMetaType<KanjiSet*>("KanjiSet*");
    connect(searchThread, SIGNAL(searchFinished(const QString &, KanjiSet *)), this, SLOT(done(const QString &, KanjiSet *)));
    // listen to stop button (connect thread to clicked of stop button)
    //connect(searchBar->stopButton(), SIGNAL(clicked()), searchThread, SLOT(killSearch()));
    // debug popup info
    //connect(searchThread, SIGNAL(threadInfo(QString)), this, SLOT(popUpInfo(QString)));
    searchBar->setFocus();
}

void MainWindow::open(const QString &fileName)
{
    QString indexName = fileName + ".index";
    QFile index(indexName);
    if (index.open(QIODevice::ReadOnly)) {
        if(kanjidic.readIndex(&index))
            return;
        else
        {
            //TODO log: index unreadable
        }
        index.close();
    } else
    {
        //TODO log: no index found
    }

    QFile file(fileName);
    if (!file.open(QIODevice::Text | QIODevice::ReadOnly)) {
        QMessageBox::warning(this, tr("Kanjidic file"),
                          tr("Cannot read file %1:\n%2.")
                          .arg(fileName)
                          .arg(file.errorString()));
        return;
    }

    if (kanjidic.readKanjiDic(&file))
    {
        statusBar()->showMessage(tr("File loaded"), 2000);
        if(!index.open(QIODevice::WriteOnly))
        {
            //TODO log: no index could be written
        } else
        {
            kanjidic.writeIndex(&index);
            index.close();
        }
    }
    else
        QMessageBox::warning(this, tr("Kanjidic file"),
                          tr("Cannot read kanjidic file %1:\n%2.")
                          .arg(fileName)
                          .arg(kanjidic.errorString()));
    file.close();
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

    searchBar = new SearchBar(this);
    connect(buffer, SIGNAL(changed()), searchBar, SLOT(updateBackAndForth()));

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(searchBar);
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

void MainWindow::done(const QString &s, KanjiSet *results)
{
    // reactivate all widgets, deactivate stop button
    lockGui(false);

    showSearchResults(s, *results);
    buffer->newRequestAndResult(s, *results);
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
            statusBar()->showMessage(tr("Too many results, displaying only %1 first results of %2").arg(searchLimit).arg(size));
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
        statusBar()->showMessage(tr("No result").arg(size));
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
    showSearchResults(buffer->getCurrentRequest(), buffer->getCurrentResults());
}

void MainWindow::forth()
{
    buffer->next();
    showSearchResults(buffer->getCurrentRequest(), buffer->getCurrentResults());
}


ResultsBuffer *MainWindow::resultsBuffer()
{
    return buffer;
}

const ResultsBuffer *MainWindow::resultsBuffer() const
{
    return buffer;
}
