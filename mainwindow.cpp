#include "mainwindow.h"
#include <QFileDialog>
#include <QApplication>
#include <QMessageBox>
#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "kanjidicdb.h"
#include "kanji.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    createWidgets();
    setCentralWidget(kanjidic);

    createActions();
    createMenus();

    statusBar()->showMessage(tr("Ready"));

    setWindowTitle(tr("Kanjidic tool"));
    resize(480, 320);
}

void MainWindow::open(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::Text | QFile::ReadOnly)) {
        QMessageBox::warning(this, tr("Kanjidic file"),
                          tr("Cannot read file %1:\n%2.")
                          .arg(fileName)
                          .arg(file.errorString()));
        return;
    }

    if (kanjidic->read(&file))
        statusBar()->showMessage(tr("File loaded"), 2000);
}

void MainWindow::open()
{
    QString fileName =
        QFileDialog::getOpenFileName(this, tr("Open Kanjidic file"),
                                      QDir::currentPath(),
                                      tr("XML Kanjidic file (*.xml)"));
    if (fileName.isEmpty())
        return;

    open(fileName);
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(exitAct);

}

void MainWindow::createWidgets()
{
    kanjidic = new KanjidicDB;

    unicodeLabel = new QLabel(tr("&Unicode (hex):"));
    unicodeField = new QLineEdit;
    unicodeLabel->setBuddy(unicodeField);
    jis208Label = new QLabel(tr("JIS20&8 (nn-nn):"));
    jis208Field = new QLineEdit;
    jis208Label->setBuddy(jis208Field);
    jis212Label = new QLabel(tr("JIS21&2 (nn-nn):"));
    jis212Field = new QLineEdit;
    jis212Label->setBuddy(jis212Field);
    jis213Label = new QLabel(tr("JIS21&3 (p-nn-nn):"));
    jis213Field = new QLineEdit;
    jis213Label->setBuddy(jis213Field);
    connect(unicodeField, SIGNAL(textChanged(const QString &)), this, SLOT(clearOtherFields()));
    connect(unicodeField, SIGNAL(returnPressed()), this, SLOT(searchUCS()));
    connect(jis208Field, SIGNAL(textChanged(const QString &)), this, SLOT(clearOtherFields()));
    connect(jis208Field, SIGNAL(returnPressed()), this, SLOT(searchJIS208()));
    connect(jis212Field, SIGNAL(textChanged(const QString &)), this, SLOT(clearOtherFields()));
    connect(jis212Field, SIGNAL(returnPressed()), this, SLOT(searchJIS212()));
    connect(jis213Field, SIGNAL(textChanged(const QString &)), this, SLOT(clearOtherFields()));
    connect(jis213Field, SIGNAL(returnPressed()), this, SLOT(searchJIS213()));

    searchCodeButton = new QPushButton(tr("&Search code"));
    connect(searchCodeButton, SIGNAL(clicked()), this, SLOT(searchCode()));

    strokeLabel = new QLabel(tr("&Strokes:"));
    strokeField = new QLineEdit;
    strokeLabel->setBuddy(strokeField);
    jlptLabel = new QLabel(tr("&JLPT:"));
    jlptField = new QLineEdit;
    jlptLabel->setBuddy(jlptField);
    gradeLabel = new QLabel(tr("&Grade:"));
    gradeField = new QLineEdit;
    gradeLabel->setBuddy(gradeField);
    radicalLabel = new QLabel(tr("&Radical:"));
    radicalField = new QLineEdit;
    radicalLabel->setBuddy(radicalField);
    connect(strokeField, SIGNAL(returnPressed()), this, SLOT(search()));
    connect(jlptField, SIGNAL(returnPressed()), this, SLOT(search()));
    connect(gradeField, SIGNAL(returnPressed()), this, SLOT(search()));
    connect(radicalField, SIGNAL(returnPressed()), this, SLOT(search()));

    searchButton = new QPushButton(tr("&Search"));
    connect(searchButton, SIGNAL(clicked()), this, SLOT(search()));

    QHBoxLayout *codesLayout = new QHBoxLayout();
    codesLayout->addWidget(unicodeLabel);
    codesLayout->addWidget(unicodeField);
    codesLayout->addWidget(jis208Label);
    codesLayout->addWidget(jis208Field);
    codesLayout->addWidget(jis212Label);
    codesLayout->addWidget(jis212Field);
    codesLayout->addWidget(jis213Label);
    codesLayout->addWidget(jis213Field);

    QHBoxLayout *searchCodeLayout = new QHBoxLayout();
    searchCodeLayout->addWidget(searchCodeButton, 0, Qt::AlignRight);

    QHBoxLayout *strokeLayout = new QHBoxLayout();
    strokeLayout->addWidget(strokeLabel);
    strokeLayout->addWidget(strokeField);
    strokeLayout->addWidget(jlptLabel);
    strokeLayout->addWidget(jlptField);
    strokeLayout->addWidget(gradeLabel);
    strokeLayout->addWidget(gradeField);
    strokeLayout->addWidget(radicalLabel);
    strokeLayout->addWidget(radicalField);

    QHBoxLayout *searchLayout = new QHBoxLayout();
    searchLayout->addWidget(searchButton, 0, Qt::AlignRight);

    resultWidgets.append(new QLabel("none"));

    resultLayout = new QVBoxLayout();
    resultLayout->addWidget(resultWidgets.at(0), 0, Qt::AlignTop);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(codesLayout);
    mainLayout->addLayout(searchCodeLayout);
    mainLayout->addLayout(strokeLayout);
    mainLayout->addLayout(searchLayout);
    mainLayout->addLayout(resultLayout);
    kanjidic->setLayout(mainLayout);

}

void MainWindow::clearOtherFields()
{
    QWidget *focused = QApplication::focusWidget();
    if(unicodeField != focused)
        unicodeField->clear();
    if(jis208Field != focused)
        jis208Field->clear();
    if(jis212Field != focused)
        jis212Field->clear();
    if(jis213Field != focused)
        jis213Field->clear();
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

void MainWindow::search()
{
    clearPreviousSearch();
    QSet<Kanji *> results;
    bool b;
    int strokeCount = strokeField->text().toInt(&b, 10);
    int jlpt = jlptField->text().toInt(&b, 10);
    int grade = gradeField->text().toInt(&b, 10);
    int radical = radicalField->text().toInt(&b, 10);
    kanjidic->search(strokeCount, jlpt, grade, radical, results);
    showSearchResults(results);
}

void MainWindow::searchCode()
{
    if(jis208Field->text().size() > 0)
        searchJIS208();
    else if(jis212Field->text().size() > 0)
        searchJIS212();
    else if(jis213Field->text().size() > 0)
        searchJIS213();
    else
        searchUCS();
}

void MainWindow::searchUCS()
{
    clearPreviousSearch();
    bool b;
    int unicode = unicodeField->text().toInt(&b, 16);
    QSet<Kanji *> results;
    if(b)
        kanjidic->searchByUnicode(unicode, results);
    showSearchResults(results);
}

void MainWindow::searchJIS208()
{
    clearPreviousSearch();
    QSet<Kanji *> results;
    kanjidic->searchByJIS208(jis208Field->text(), results);
    showSearchResults(results);
}

void MainWindow::searchJIS212()
{
    clearPreviousSearch();
    QSet<Kanji *> results;
    kanjidic->searchByJIS212(jis212Field->text(), results);
    showSearchResults(results);
}

void MainWindow::searchJIS213()
{
    clearPreviousSearch();
    QSet<Kanji *> results;
    kanjidic->searchByJIS213(jis213Field->text(), results);
    showSearchResults(results);
}

void MainWindow::showSearchResults(const QSet<Kanji *> &results)
{
    if(results.size() > 0)
    {
        foreach(Kanji *k, results)
        {
            resultWidgets.append(new QLabel(k->getLiteral()));
        }
    } else
    {
        resultWidgets.append(new QLabel("none"));
    }

    foreach(QWidget *resultWidget, resultWidgets)
    {
        resultLayout->addWidget(resultWidget, 0, Qt::AlignTop);
    }
}
