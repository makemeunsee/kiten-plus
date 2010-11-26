#include "componentselectionform.h"
#include "ui_componentselectionform.h"

ComponentSelectionForm::ComponentSelectionForm(QPushButton *triggerButton, QWidget *parent) :
    PartSelectionForm(triggerButton, parent),
    ui(new Ui::ComponentSelectionForm)
{
    ui->setupUi(this);
    compLayout = new FlowLayout(ui->componentContainer, 0, 0, 0);
    ui->componentContainer->setLayout(compLayout);
}

ComponentSelectionForm::~ComponentSelectionForm()
{
    delete ui;
    foreach(QList<CheckableLabel *> *list, compButtonsByStrokes.values())
    {
        foreach(CheckableLabel *l, *list)
            delete l;
        delete list;
    }
    compButtonsByStrokes.clear();
}

const QString &ComponentSelectionForm::getSearchKey() const
{
    return KanjiDB::componentKey;
}

void ComponentSelectionForm::clearSelection()
{
    foreach(QList<CheckableLabel *> *list, compButtonsByStrokes.values())
        foreach(CheckableLabel *l, *list)
            l->setChecked(false);
}

const QPushButton *ComponentSelectionForm::searchButton() const
{
    return ui->searchButton;
}

const QPushButton *ComponentSelectionForm::searchAndCloseButton() const
{
    return ui->searchAndCloseButton;
}

QList<QString> ComponentSelectionForm::selectedComponents() const
{
    QList<QString> result;
    foreach(QList<CheckableLabel *> *list, compButtonsByStrokes.values())
        foreach(CheckableLabel *l, *list)
            if(l->isChecked())
                result.append(l->text());
    return result;
}

void ComponentSelectionForm::clearLayout()
{
    QMapIterator<unsigned int, QList<CheckableLabel *> *> it(compButtonsByStrokes);
    while(it.hasNext())
    {
        it.next();
        strokeStones[it.key()]->layout()->itemAt(0)->widget()->hide();
        compLayout->removeWidget(strokeStones[it.key()]);
        foreach(CheckableLabel *l, *it.value())
            {
               compLayout->removeWidget(l);
               l->hide();
            }
    }
}

void ComponentSelectionForm::setKanjiDB(const KanjiDB &kanjiDB)
{
    kanjiDBSet = false;
    foreach(Kanji *component, kanjiDB.getAllComponents())
    {
        QString comp = component->getLiteral();
        CheckableLabel *cl = new CheckableLabel(comp, this);
        cl->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        cl->setAlignment(Qt::AlignCenter);
        cl->setFixedSize(23, 23);
        cl->setFont(font);
        if(kanjiDB.getFaultyComponents().contains(comp.at(0).unicode()))
            cl->setIconTooltip(kanjiDB.getFaultyComponents().value(comp.at(0).unicode()));
        unsigned char strokes = component->getStrokeCount();
        if(compButtonsByStrokes.value(strokes) == 0)
        {
            QLabel *l = new QLabel(QString::number(strokes), this);
            l->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            l->setAlignment(Qt::AlignCenter);
            l->setFixedSize(15, 15);
            l->setFont(strokeFont);
            l->setAutoFillBackground(true);
            l->setPalette(strokePalette);
            QWidget *w = new QWidget(ui->componentContainer);
            FlowLayout *flow = new FlowLayout(w, 4, 0, 0);
            w->setLayout(flow);
            flow->addWidget(l);
            strokeStones.insert(strokes, w);
            compButtonsByStrokes[strokes] = new QList<CheckableLabel *>;
        }
        compButtonsByStrokes.value(strokes)->append(cl);
    }
    kanjiDBSet = true;
    QMapIterator<unsigned int, QList<CheckableLabel *> *> i(compButtonsByStrokes);
    while(i.hasNext())
    {
        i.next();
        compLayout->addWidget(strokeStones.value(i.key()));
        strokeStones[i.key()]->layout()->itemAt(0)->widget()->show();
        foreach(CheckableLabel *p, *i.value())
        {
            compLayout->addWidget(p);
            p->show();
        }
    }
    adjustSize();
}
