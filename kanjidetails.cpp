#include "kanjidetails.h"
#include "mainwindow.h"
#include "ui_kanjidetails.h"
#include "readingmeaninggroupwidget.h"
#include "ui_readingmeaninggroupwidget.h"
#include "../JapaneseDB/kanji.h"
#include "../JapaneseDB/kanjidb.h"
#include "../JapaneseDB/readingmeaninggroup.h"
#include "searchablelabel.h"

#include <iostream>

KanjiDetails::KanjiDetails(MainWindow *parent, Kanji *k, KanjiDB &kanjiDB) :
    QWidget(parent),
    ui(new Ui::KanjiDetails)
{
    ui->setupUi(this);
    searchWindow = parent;
    ui->literalLabel->setText(k->getLiteral());
    ui->strokeCountLabel->setText(QString::number(k->getStrokeCount()));
    if(k->getGrade() > 0)
        updateLabel(ui->gradeLabel, QString::number(k->getGrade()));
    else
    {
        hideWidget(ui->gradeLabel);
        hideWidget(ui->staticGradeLabel);
        hideWidget(ui->staticGradeLabel2);
    }
    if(k->getJLPT() > 0)
        updateLabel(ui->jlptLabel, QString::number(k->getJLPT()));
    else
    {
        hideWidget(ui->jlptLabel);
        hideWidget(ui->staticJlptLabel);
    }
    if(k->getFrequency() > 0)
        updateLabel(ui->freqLabel, QString::number(k->getFrequency()));
    else
    {
        hideWidget(ui->freqLabel);
        hideWidget(ui->staticFreqLabel);
    }
    if(k->getClassicalRadical() > 0)
        updateLabel(ui->radClasLabel, QString::number(k->getClassicalRadical()));
    else
    {
        hideWidget(ui->radClasLabel);
        hideWidget(ui->staticClasRadLabel);
    }
    if(k->getNelsonRadical() > 0)
        updateLabel(ui->radNelsonLabel, QString::number(k->getNelsonRadical()));
    else
    {
        hideWidget(ui->radNelsonLabel);
        hideWidget(ui->staticNelsonRadLabel);
    }
    QSet<Kanji *> variants;
    kanjiDB.findVariants(k, variants);
    if(variants.isEmpty())
    {
        //hideWidget(ui->variantsLabel);
        hideWidget(ui->staticVariantsLabel);
    } else
    {
        QString s_variants;
        foreach(Kanji *k, variants)
        {
            SearchableLabel *l = new SearchableLabel(k->getLiteral());
            l->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::LinksAccessibleByMouse);
            connect(l, SIGNAL(mouseClicked(const QString &)), this, SLOT(search(const QString &)));
            ui->variantsLayout2->addWidget(l);
        }
    }

    if(k->getNamesAsRadical().isEmpty())
    {
        hideWidget(ui->nameRadLabel);
        hideWidget(ui->staticNameRadLabel);
    } else
    {
        QString s_names;
        foreach(QString s, k->getNamesAsRadical())
        {
            s_names.append(s);
            s_names.append(",");
        }
        s_names.resize(s_names.size()-1);;
        updateLabel(ui->nameRadLabel, s_names);
    }

    updateLabel(ui->ucsLabel, QString::number(k->getUnicode(), 16));
    if(!k->getJis208().isEmpty())
        ui->jis208Label->setText(k->getJis208());
    else
    {
        hideWidget(ui->jis208Label);
        hideWidget(ui->staticJIS208Label);
    }
    if(!k->getJis212().isEmpty())
        updateLabel(ui->jis212Label, k->getJis212());
    else
    {
        hideWidget(ui->jis212Label);
        hideWidget(ui->staticJIS212Label);
    }
    if(!k->getJis213().isEmpty())
        updateLabel(ui->jis208Label, k->getJis213());
    else
    {
        hideWidget(ui->jis213Label);
        hideWidget(ui->staticJIS213Label);
    }
    foreach(ReadingMeaningGroup *rmGroup, k->getReadingMeaningGroups())
    {
        ReadingMeaningGroupWidget *rmWidget = new ReadingMeaningGroupWidget();
        foreach(QString s, rmGroup->getEnglishMeanings())
        {
            rmWidget->addEnglishMeaning(s);
        }
        foreach(QString s, rmGroup->getFrenchMeanings())
        {
            rmWidget->addFrenchMeaning(s);
        }
        rmWidget->addKunReadings(rmGroup->getKunReadings());
        rmWidget->addOnReadings(rmGroup->getOnReadings());
        rmWidget->adjustSize();
        ui->readMeanLayout->addWidget(rmWidget);
    }
    adjustSize();
}

KanjiDetails::~KanjiDetails()
{
    delete ui;
}

void KanjiDetails::search(const QString &s)
{
    searchWindow->search(s);
}

void KanjiDetails::changeEvent(QEvent *e)
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

void KanjiDetails::hideWidget(QWidget *w)
{
    w->setVisible(false);
    w->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
}

void KanjiDetails::updateLabel(QLabel *l, QString text)
{
    l->setText(text);
}
