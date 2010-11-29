#include "searchbar.h"
#include "ui_searchbar.h"
#include "mainwindow.h"

SearchBar::SearchBar(History &h, MainWindow *parent) :
    QWidget(parent),
    ui(new Ui::SearchBar)
{
    ui->setupUi(this);
    radForm = new RadicalSelectionForm(ui->radButton, this);
    compForm = new ComponentSelectionForm(ui->compButton, this);
    searchWindow = parent;
    connect(ui->searchLine, SIGNAL(returnPressed()), this, SLOT(search()));
    connect(ui->backButton, SIGNAL(clicked()), searchWindow, SLOT(back()));
    connect(ui->forthButton, SIGNAL(clicked()), searchWindow, SLOT(forth()));
    connect(ui->radButton, SIGNAL(toggled(bool)), this, SLOT(showRadDialog(bool)));
    connect(ui->compButton, SIGNAL(toggled(bool)), this, SLOT(showCompDialog(bool)));
    connect(radForm, SIGNAL(shown(bool)), ui->radButton, SLOT(setChecked(bool)));
    connect(radForm->searchButton(), SIGNAL(clicked()), this, SLOT(searchRad()));
    connect(radForm->searchAndCloseButton(), SIGNAL(clicked()), this, SLOT(searchRadAndClose()));
    connect(compForm, SIGNAL(shown(bool)), ui->compButton, SLOT(setChecked(bool)));
    connect(compForm->searchButton(), SIGNAL(clicked()), this, SLOT(searchComp()));
    connect(compForm->searchAndCloseButton(), SIGNAL(clicked()), this, SLOT(searchCompAndClose()));
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
    compForm->moveEvent();
}

void SearchBar::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape)
    {
        if(radForm->isVisible())
            ui->radButton->toggle();
        if(compForm->isVisible())
            ui->compButton->toggle();
    }
    else
        QWidget::keyPressEvent(e);
}

void SearchBar::showRadDialog(bool show)
{
    if(compForm->isVisible())
        compForm->setVisible(false);
    radForm->setVisible(show);
}

void SearchBar::showCompDialog(bool show)
{
    if(radForm->isVisible())
        radForm->setVisible(false);
    compForm->setVisible(show);
}

void SearchBar::searchRad()
{
    search(radForm);
}

void SearchBar::searchComp()
{
    search(compForm);
}

void SearchBar::search(const PartSelectionForm *form)
{
    ui->searchLine->setHistoryMode();
    ui->searchLine->clear();
    QString searchQuery;
    foreach(QString comp, form->selectedComponents())
    {
        searchQuery.append(form->getSearchKey());
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
    searchAndCloseForm(radForm);
}

void SearchBar::searchCompAndClose()
{
    searchAndCloseForm(compForm);
}

void SearchBar::searchAndCloseForm(PartSelectionForm *form)
{
    search(form);
    if(form->isVisible())
        form->getButtonRef()->toggle();
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
}

PartSelectionForm *SearchBar::radicalSelectionForm()
{
    return radForm;
}

PartSelectionForm *SearchBar::componentSelectionForm()
{
    return compForm;
}
