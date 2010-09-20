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
    ui->englishMeaningsLayout->addWidget(new QLabel(s));
}

void ReadingMeaningGroupWidget::addFrenchMeaning(QString &s)
{
    ui->frenchMeaningsLayout->addWidget(new QLabel(s));
}

void ReadingMeaningGroupWidget::addKunReading(QString &s)
{
    ui->kunReadingsLayout->addWidget(new QLabel(s));
}

void ReadingMeaningGroupWidget::addOnReading(QString &s)
{
    ui->onReadingsLayout->addWidget(new QLabel(s));
}
