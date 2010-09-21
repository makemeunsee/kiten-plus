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
    ui->englishMeaningsLayout->addWidget(l);
}

void ReadingMeaningGroupWidget::addFrenchMeaning(QString &s)
{
    QLabel *l = new QLabel(s);
    l->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
    ui->frenchMeaningsLayout->addWidget(l);
}

void ReadingMeaningGroupWidget::addKunReadings(const QSet<QString> &s)
{
    QString merged;
    foreach(QString reading, s)
    {
        merged.append(reading);
        merged.append(QString::fromUtf8("、　"));
    }
    if(merged.size() > 0)
        merged.resize(merged.size()-2);
    QLabel *l = new QLabel(merged);
    l->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
    ui->kunReadingsLayout->addWidget(l);
}

void ReadingMeaningGroupWidget::addOnReadings(const QSet<QString> &s)
{
    QString merged;
    foreach(QString reading, s)
    {
        merged.append(reading);
        merged.append(QString::fromUtf8("、　"));
    }
    if(merged.size() > 0)
        merged.resize(merged.size()-1);
    QLabel *l = new QLabel(merged);
    l->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
    ui->onReadingsLayout->addWidget(l);
}
