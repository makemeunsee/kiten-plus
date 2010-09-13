#include "kanjidetails.h"
#include "ui_kanjidetails.h"
#include "../JapaneseDB/kanji.h"
#include "../JapaneseDB/kanjidb.h"

#include <iostream>

KanjiDetails::KanjiDetails(QWidget *parent, Kanji *k, KanjiDB *kanjiDB) :
    QWidget(parent),
    ui(new Ui::KanjiDetails)
{
    ui->setupUi(this);
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
    foreach(int i, k->getUnicodeVariants())
    {
        kanjiDB->searchByUnicode(i, variants);
    }
    foreach(QString s, k->getJis208Variants())
    {
        kanjiDB->searchByJIS208(s, variants);
    }
    foreach(QString s, k->getJis212Variants())
    {
        kanjiDB->searchByJIS212(s, variants);
    }
    foreach(QString s, k->getJis213Variants())
    {
        kanjiDB->searchByJIS213(s, variants);
    }
    if(variants.isEmpty())
    {
        hideWidget(ui->variantsLabel);
        hideWidget(ui->staticVariantsLabel);
    } else
    {
        QString s_variants;
        foreach(Kanji *k, variants)
            s_variants.append(k->getLiteral());
        updateLabel(ui->variantsLabel, s_variants);
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
}

KanjiDetails::~KanjiDetails()
{
    delete ui;
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
