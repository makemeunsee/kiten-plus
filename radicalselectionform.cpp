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
    strokeFont.setPointSize(10);
    strokeFont.setBold(true);
    strokeBackground.setRgb(180, 180, 180);
    strokePalette = QApplication::palette();
    strokePalette.setCurrentColorGroup(QPalette::Active);
    strokePalette.setColor(QPalette::Window, strokeBackground);
    connect(ui->onlyRadBox, SIGNAL(toggled(bool)), this, SLOT(limitToRad(bool)));
    ui->onlyRadBox->setCheckState(Qt::Checked);
    //removed next line once components (radk/krad) are supported
    ui->onlyRadBox->setEnabled(false);
    ui->sortBox->setCheckState(Qt::Checked);
    connect(ui->sortBox, SIGNAL(toggled(bool)), this, SLOT(sortRadicalsByIndex(bool)));
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

const QPushButton *RadicalSelectionForm::searchButton() const
{
    return ui->searchButton;
}

QList<QString> RadicalSelectionForm::selectedComponents() const
{
    QList<QString> result;
    QMapIterator<unsigned int, QPushButton *> i(radButtonsById);
    while(i.hasNext())
    {
        QPushButton *button = i.next().value();
        if(button->isChecked())
            result.append(button->text());
    }
    return result;
}

void RadicalSelectionForm::limitToRad(bool b)
{
    if(!b)
        ui->sortBox->setCheckState(Qt::Unchecked);
    ui->sortBox->setEnabled(b);
    //more stuff to do once krad/radk supported
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
            strokeStones[i.key()]->layout()->itemAt(0)->widget()->show();
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
        strokeStones[i2.key()]->layout()->itemAt(0)->widget()->hide();
        radLayout->removeWidget(strokeStones[i2.key()]);
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
        p->setToolTip("n."+QString::number(i+1));
        radButtonsById.insert(i, p);
        unsigned char strokes = kanjiDB.getByUnicode(rad.at(0).unicode())->getStrokeCount();
        if(radButtonsByStrokes[strokes] == 0)
        {
            QLabel *l = new QLabel(QString::number(strokes), this);
            l->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            l->setAlignment(Qt::AlignCenter);
            l->setFixedSize(15, 15);
            l->setFont(strokeFont);
            l->setAutoFillBackground(true);
            l->setPalette(strokePalette);
            QWidget *w = new QWidget(ui->radicalContainer);
            FlowLayout *flow = new FlowLayout(w, 4, 0, 0);
            w->setLayout(flow);
            flow->addWidget(l);
            strokeStones.insert(strokes, w);
            radButtonsByStrokes[strokes] = new QList<QPushButton *>;
        }
        radButtonsByStrokes[strokes]->append(p);
    }
    kanjiDBSet = true;
    ui->sortBox->setCheckState(Qt::Unchecked);
}
