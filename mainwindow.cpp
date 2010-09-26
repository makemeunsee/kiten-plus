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
#include <QScrollArea>
#include "../JapaneseDB/kanjidb.h"
#include "../JapaneseDB/kanji.h"
#include "resultsbuffer.h"
#include "kanjidetails.h"
#include "searchbar.h"
#include "ui_searchbar.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    buffer = new ResultsBuffer;
    createWidgets();
    createActions();
    createMenus();
    setWindowTitle(tr("Kiten+"));
    resize(680, 400);
    statusBar()->showMessage(tr("Ready"));
    searchBar->setFocus();
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

    if (kanjidic.read(&file))
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

    connect(buffer, SIGNAL(changed()), searchBar, SLOT(updateBackAndForth()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(exitAct);
}

void MainWindow::createWidgets()
{
    resultWidgets.append(new QLabel("-"));
    resultLayout = new QVBoxLayout();
    resultLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    resultLayout->addWidget(resultWidgets.at(0), 0, Qt::AlignTop);
    QScrollArea *area = new QScrollArea();
    QWidget *widget = new QWidget();
    widget->setLayout(resultLayout);
    area->setWidget(widget);

    searchBar = new SearchBar(this);

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
    QSet<Kanji *> results;
    kanjidic.search(s, results);
    showSearchResults(s, results);
    buffer->newRequestAndResult(s, results);
}

void MainWindow::showSearchResults(const QString &request, const QSet<Kanji *> &results)
{
    clearPreviousSearch();
    searchBar->setText(request);

    bool found = false;
    if(results.size() > 0)
    {
        foreach(Kanji *k, results)
            resultWidgets.append(new KanjiDetails(this, k, kanjidic));
        found = true;
    } else
        resultWidgets.append(new QLabel(QString("Request \"") + searchBar->text() + "\" yielded no result."));

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
