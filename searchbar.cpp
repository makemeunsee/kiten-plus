#include "searchbar.h"
#include "ui_searchbar.h"
#include "mainwindow.h"

SearchBar::SearchBar(History &h, MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::SearchBar),
    radForm(new RadicalSelectionForm(this))
{
    ui->setupUi(this);
    searchWindow = parent;
    connect(ui->searchLine, SIGNAL(returnPressed()), this, SLOT(search()));
    connect(ui->backButton, SIGNAL(clicked()), searchWindow, SLOT(back()));
    connect(ui->forthButton, SIGNAL(clicked()), searchWindow, SLOT(forth()));
    connect(ui->radButton, SIGNAL(clicked()), this, SLOT(showRadDialog()));
    ui->backButton->setShortcut(QKeySequence(Qt::ALT + Qt::Key_Left));
    ui->forthButton->setShortcut(QKeySequence(Qt::ALT + Qt::Key_Right));
    backIcon = QIcon("icons/left.png");
    forthIcon = QIcon("icons/right.png");
    ui->backButton->setIcon(backIcon);
    ui->forthButton->setIcon(forthIcon);
    completer = new SearchCompleter(this);
    ui->searchLine->setKeywordCompleter(completer);
    ui->searchLine->setHistoryCompleter(new QCompleter(&h.getModel(), this));
}

SearchBar::~SearchBar()
{
    delete ui;
}

void SearchBar::showRadDialog()
{
    radForm->show();
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

RadicalSelectionForm *SearchBar::radicalSelectionForm()
{
    return radForm;
}

//const QPushButton *SearchBar::stopButton()
//{
//    return ui->stopButton;
//}
