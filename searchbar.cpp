#include "searchbar.h"
#include "ui_searchbar.h"
#include "mainwindow.h"

SearchBar::SearchBar(History &h, MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::SearchBar)
{
    ui->setupUi(this);
    radForm = new RadicalSelectionForm(ui->radButton, this);
    searchWindow = parent;
    connect(ui->searchLine, SIGNAL(returnPressed()), this, SLOT(search()));
    connect(ui->backButton, SIGNAL(clicked()), searchWindow, SLOT(back()));
    connect(ui->forthButton, SIGNAL(clicked()), searchWindow, SLOT(forth()));
    connect(ui->radButton, SIGNAL(toggled(bool)), this, SLOT(showRadDialog(bool)));
    connect(radForm, SIGNAL(shown(bool)), ui->radButton, SLOT(setChecked(bool)));
    connect(radForm->searchButton(), SIGNAL(clicked()), this, SLOT(searchRad()));
    connect(radForm->searchAndCloseButton(), SIGNAL(clicked()), this, SLOT(searchRadAndClose()));
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

void SearchBar::movePopup(QMoveEvent *)
{
    radForm->moveEvent();
}

void SearchBar::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape && radForm->isVisible())
        ui->radButton->toggle();
    else
        QWidget::keyPressEvent(e);
}

void SearchBar::showRadDialog(bool show)
{
    radForm->setVisible(show);
}

void SearchBar::searchRad()
{
    ui->searchLine->setHistoryMode();
    ui->searchLine->clear();
    QString searchQuery("");
    foreach(QString comp, radForm->selectedComponents())
    {
        searchQuery.append(KanjiDB::radicalKey);
        searchQuery.append(comp);
        searchQuery.append("&");
    }
    if(searchQuery.length() > 1)
        searchQuery.remove(searchQuery.length()-1, 1);
    ui->searchLine->setText(searchQuery);
    search();
}

void SearchBar::searchRadAndClose()
{
    searchRad();
    if(radForm->isVisible())
        ui->radButton->toggle();
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
