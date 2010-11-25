#include "radicalselectionform.h"
#include "ui_radicalselectionform.h"
#include "../JapaneseDB/radicals.h"

RadicalSelectionForm::RadicalSelectionForm(QWidget *radButton, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RadicalSelectionForm),
    kanjiDBSet(false),
    radButtonRef(radButton)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    radLayout = new FlowLayout(ui->radicalContainer, 0, 0, 0);
    ui->radicalContainer->setLayout(radLayout);
    font.setPointSize(12);
    strokeFont.setPointSize(9);
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
    foreach(CheckableLabel *p, radButtonsById.values())
    {
        delete p;
    }
    radButtonsById.clear();
    foreach(QList<CheckableLabel *> *l, radButtonsByStrokes.values())
    {
        delete l;
    }
    radButtonsByStrokes.clear();
}

void RadicalSelectionForm::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape && isVisible())
        hide();
    else
        QWidget::keyPressEvent(e);
}

void RadicalSelectionForm::closeEvent(QCloseEvent *e)
{
    e->ignore();
}

void RadicalSelectionForm::moveEvent()
{
    putInPlace();
}

void RadicalSelectionForm::moveEvent(QMoveEvent *)
{
    putInPlace();
}

void RadicalSelectionForm::showEvent(QShowEvent *)
{
    emit shown(true);
    putInPlace();
}

void RadicalSelectionForm::hideEvent(QHideEvent *)
{
    emit shown(false);
    clearSelection();
}

void RadicalSelectionForm::clearSelection()
{
    QMapIterator<unsigned int, CheckableLabel *> i(radButtonsById);
    while(i.hasNext())
        i.next().value()->setChecked(false);
}

void RadicalSelectionForm::putInPlace()
{
    QPoint p = radButtonRef->mapToGlobal(QPoint(0, radButtonRef->height()));
    setGeometry(p.x(), p.y(), width(), height());
}

const QPushButton *RadicalSelectionForm::searchButton() const
{
    return ui->searchButton;
}

const QPushButton *RadicalSelectionForm::searchAndCloseButton() const
{
    return ui->searchAndCloseButton;
}

QList<QString> RadicalSelectionForm::selectedComponents() const
{
    QList<QString> result;
    QMapIterator<unsigned int, CheckableLabel *> i(radButtonsById);
    while(i.hasNext())
    {
        CheckableLabel *button = i.next().value();
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
        QMapIterator<unsigned int, CheckableLabel *> i(radButtonsById);
        while(i.hasNext())
        {
            radLayout->addWidget(i.next().value());
            i.value()->show();
        }
    } else {
        QMapIterator<unsigned int, QList<CheckableLabel *> *> i(radButtonsByStrokes);
        while(i.hasNext())
        {
            i.next();
            radLayout->addWidget(strokeStones[i.key()]);
            strokeStones[i.key()]->layout()->itemAt(0)->widget()->show();
            foreach(CheckableLabel *p, *i.value())
            {
                radLayout->addWidget(p);
                p->show();
            }
        }
    }
    adjustSize();
}

void RadicalSelectionForm::clearLayout()
{
    QMapIterator<unsigned int, CheckableLabel *> i(radButtonsById);
    while(i.hasNext())
    {
       radLayout->removeWidget(i.next().value());
       i.value()->hide();
   }
    QMapIterator<unsigned int, QList<CheckableLabel *> *> i2(radButtonsByStrokes);
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
    for(unsigned int i = 0; i < Radicals::radicalsSize; ++i)
    {
        const Kanji *radical = kanjiDB.getRadicalById(i+1);
        QString rad = radical->getLiteral();
        CheckableLabel *cl = new CheckableLabel(rad, this);
        cl->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        cl->setAlignment(Qt::AlignCenter);
        cl->setFixedSize(23, 23);
        cl->setFont(font);
        QString s_tooltip = "n." + QString::number(i+1);
        const QSet<Unicode> &variants = radical->getUnicodeVariants();
        if(variants.size() > 0)
        {
            s_tooltip.append("\n").append(tr("Variants:"));
            foreach(Unicode u, variants)
                s_tooltip.append(" ").append(kanjiDB.getRadicalVariant(u)->getLiteral());
        }
        cl->setToolTip(s_tooltip);
        radButtonsById.insert(i, cl);
        unsigned char strokes = radical->getStrokeCount();
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
            radButtonsByStrokes[strokes] = new QList<CheckableLabel *>;
        }
        radButtonsByStrokes[strokes]->append(cl);
    }
    kanjiDBSet = true;
    ui->sortBox->setCheckState(Qt::Unchecked);
}
