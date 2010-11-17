#include "radicalselectionform.h"
#include "ui_radicalselectionform.h"
#include "../JapaneseDB/radicals.h"

#include <iostream>

using namespace std;

RadicalSelectionForm::RadicalSelectionForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RadicalSelectionForm),
    kanjiDBSet(false)
{
    ui->setupUi(this);
    setWindowTitle(tr("Radical selection"));
    radLayout = new FlowLayout(ui->radicalContainer, 0, 0, 0);
    ui->radicalContainer->setLayout(radLayout);
    font.setPointSize(12);
    connect(ui->indexButton, SIGNAL(toggled(bool)), this, SLOT(sortRadicalsByIndex(bool)));
}

RadicalSelectionForm::~RadicalSelectionForm()
{
    delete ui;
    foreach(QPushButton *p, radButtonsById.values())
    {
        delete p;
    }
    radButtonsById.clear();
    foreach(QList<QPushButton *> *l, radButtonsByStrokes.values())
    {
        delete l;
    }
    radButtonsByStrokes.clear();
}

void RadicalSelectionForm::sortRadicalsByIndex(bool b)
{
    if(!kanjiDBSet)
        return;
    clearLayout();
    if(b)
    {
        QMapIterator<unsigned int, QPushButton *> i(radButtonsById);
        while(i.hasNext())
           radLayout->addWidget(i.next().value());
    } else {
        QMapIterator<unsigned int, QList<QPushButton *> *> i(radButtonsByStrokes);
        while(i.hasNext())
        {
            i.next();
            radLayout->addWidget(strokeStones[i.key()]);
            strokeStones[i.key()]->show();
            foreach(QPushButton *p, *i.value())
                radLayout->addWidget(p);
        }
    }
}

void RadicalSelectionForm::clearLayout()
{
    QMapIterator<unsigned int, QPushButton *> i(radButtonsById);
    while(i.hasNext())
       radLayout->removeWidget(i.next().value());
    QMapIterator<unsigned int, QList<QPushButton *> *> i2(radButtonsByStrokes);
    while(i2.hasNext())
    {
        i2.next();
        radLayout->removeWidget(strokeStones[i2.key()]);
        strokeStones[i2.key()]->hide();
    }
}

void RadicalSelectionForm::setKanjiDB(const KanjiDB &kanjiDB)
{
    kanjiDBSet = false;
    for(unsigned int i = 0; i < radicalsSize; ++i)
    {
        QString rad = radicals[i];
        QPushButton *p = new QPushButton(rad, this);
        p->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        p->setFixedSize(23, 23);
        p->setCheckable(true);
        p->setFlat(true);
        p->setFont(font);
        radButtonsById.insert(i, p);
        unsigned char strokes = kanjiDB.getByUnicode(rad.at(0).unicode())->getStrokeCount();
        if(radButtonsByStrokes[strokes] == 0)
        {
            strokeStones.insert(strokes, new QLabel(QString::number(strokes), this));
            radButtonsByStrokes[strokes] = new QList<QPushButton *>;
        }
        radButtonsByStrokes[strokes]->append(p);
    }
    kanjiDBSet = true;
    ui->indexButton->toggle();
}

