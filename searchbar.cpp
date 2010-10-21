#include "searchbar.h"
#include "ui_searchbar.h"
#include "mainwindow.h"

SearchBar::SearchBar(MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::SearchBar)
{
    ui->setupUi(this);
    searchWindow = parent;
    connect(ui->searchLine, SIGNAL(returnPressed()), this, SLOT(search()));
    connect(ui->backButton, SIGNAL(clicked()), searchWindow, SLOT(back()));
    connect(ui->forthButton, SIGNAL(clicked()), searchWindow, SLOT(forth()));
}

SearchBar::~SearchBar()
{
    delete ui;
}

void SearchBar::search()
{
    searchWindow->search(ui->searchLine->text());
}

QString SearchBar::text() const
{
    return ui->searchLine->text();
}

void SearchBar::setText(const QString &s)
{
    ui->searchLine->setText(s);
}

void SearchBar::setFocus()
{
    ui->searchLine->setFocus();
}

void SearchBar::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void SearchBar::updateBackAndForth()
{
    if(searchWindow->resultsBuffer()->hasNext())
        ui->forthButton->setEnabled(true);
    else
        ui->forthButton->setEnabled(false);
    if(searchWindow->resultsBuffer()->hasPrevious())
        ui->backButton->setEnabled(true);
    else
        ui->backButton->setEnabled(false);
}

void SearchBar::lock(bool lock)
{
    ui->backButton->setEnabled(!lock);
    ui->forthButton->setEnabled(!lock);
    ui->searchLine->setEnabled(!lock);
//    ui->stopButton->setEnabled(lock);
}

//const QPushButton *SearchBar::stopButton()
//{
//    return ui->stopButton;
//}
