#include "readingmeaninggroupwidget.h"
#include "ui_readingmeaninggroupwidget.h"

ReadingMeaningGroupWidget::ReadingMeaningGroupWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReadingMeaningGroupWidget)
{
    ui->setupUi(this);
}

ReadingMeaningGroupWidget::~ReadingMeaningGroupWidget()
{
    delete ui;
}

void ReadingMeaningGroupWidget::changeEvent(QEvent *e)
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

void ReadingMeaningGroupWidget::addEnglishMeaning(QString &s)
{
    QLabel *l = new QLabel(s);
    l->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
    ui->englishMeaningsLayout->addWidget(l, Qt::AlignLeft);
}

void ReadingMeaningGroupWidget::addFrenchMeaning(QString &s)
{
    QLabel *l = new QLabel(s);
    l->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
    ui->frenchMeaningsLayout->addWidget(l, Qt::AlignLeft);
}

void ReadingMeaningGroupWidget::addKunReading(QString &s)
{
    QLabel *l = new QLabel(s);
    l->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
    ui->kunReadingsLayout->addWidget(l, Qt::AlignLeft);
}

void ReadingMeaningGroupWidget::addOnReading(QString &s)
{
    QLabel *l = new QLabel(s);
    l->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
    ui->onReadingsLayout->addWidget(l, Qt::AlignLeft);
}
