#include "kanjidetailsscrollareatestwindow.h"
#include "../kanjidetails.h"
#include "../../JapaneseDB/kanjidb.h"
#include "../../JapaneseDB/kanji.h"
#include <QScrollArea>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <iostream>

KanjiDetailsScrollAreaTestWindow::KanjiDetailsScrollAreaTestWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createKanjis();
    QWidget *centralWidget = new QWidget;
    QHBoxLayout *centralLayout = new QHBoxLayout;
    centralWidget->setLayout(centralLayout);
    kanjiDB = new KanjiDB;
    kanjiDetails = new KanjiDetails(0, ten, kanjiDB);
    buttonTen = new QPushButton(QString::fromUtf8("天"));
    buttonVrac = new QPushButton("Vrac");
    QVBoxLayout *editLayout = new QVBoxLayout;
    editLayout->addWidget(buttonTen);
    editLayout->addWidget(buttonVrac);
    QScrollArea *scrollArea = new QScrollArea;
    QWidget *scrollWidget = new QWidget;
    scrollLayout = new QVBoxLayout;
    scrollLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
    scrollWidget->setLayout(scrollLayout);
    scrollLayout->addWidget(kanjiDetails);
    QLabel *temoin = new QLabel(QString::fromUtf8("美しい"));
    scrollLayout->addWidget(temoin);
    scrollArea->setWidget(scrollWidget);
    centralLayout->addLayout(editLayout);
    centralLayout->addWidget(scrollArea);
    setCentralWidget(centralWidget);

    connect(buttonTen, SIGNAL(clicked()), this, SLOT(setTen()));
    connect(buttonVrac, SIGNAL(clicked()), this, SLOT(setVrac()));

    setWindowTitle(tr("Test kanji details"));
    resize(730, 480);
}

KanjiDetailsScrollAreaTestWindow::~KanjiDetailsScrollAreaTestWindow()
{

}

void KanjiDetailsScrollAreaTestWindow::createKanjis()
{
    ten = new Kanji(QString::fromUtf8("天"));
    ten->addNameAsRadical("ten");
    ten->setStrokeCount(4);
    ten->setUnicode(9873);
    ten->setClassicalRadical(4);
    ten->setFrequency(1);
    ten->setGrade(1);
    ten->setJLPT(3);
    ten->setNelsonRadical(5);

    vrac = new Kanji(QString::fromUtf8("重"));
    vrac->addNameAsRadical("VRACAFKHDFJHSDJGHSDJHGSLJFHG");
    vrac->setStrokeCount(18);
    vrac->setUnicode(666);
    vrac->setClassicalRadical(0);
    vrac->setFrequency(0);
    vrac->setGrade(0);
    vrac->setJLPT(0);
    vrac->setNelsonRadical(0);
}

void KanjiDetailsScrollAreaTestWindow::setTen()
{
    scrollLayout->removeWidget(kanjiDetails);
    delete kanjiDetails;
    kanjiDetails = new KanjiDetails(0, ten, kanjiDB);
    scrollLayout->addWidget(kanjiDetails);
}

void KanjiDetailsScrollAreaTestWindow::setVrac()
{
    scrollLayout->removeWidget(kanjiDetails);
    delete kanjiDetails;
    kanjiDetails = new KanjiDetails(0, vrac, kanjiDB);
    scrollLayout->addWidget(kanjiDetails);
}
