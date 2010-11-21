#include "kanjidetailsscrollareatestwindow.h"
#include "../kanjidetails.h"
#include "../../JapaneseDB/kanji.h"
#include "../../JapaneseDB/readingmeaninggroup.h"
#include <QScrollArea>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

KanjiDetailsScrollAreaTestWindow::KanjiDetailsScrollAreaTestWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createKanjis();
    QWidget *centralWidget = new QWidget;
    QHBoxLayout *centralLayout = new QHBoxLayout;
    centralWidget->setLayout(centralLayout);
    kanjiDetails = new KanjiDetails(0, ten, kanjiDB);
    buttonTen = new QPushButton(QString::fromUtf8("天"));
    buttonVrac = new QPushButton("Vrac");
    QVBoxLayout *editLayout = new QVBoxLayout;
    editLayout->addWidget(buttonTen);
    editLayout->addWidget(buttonVrac);
    QScrollArea *scrollArea = new QScrollArea;
    scrollWidget = new QWidget;
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
    ReadingMeaningGroup *tenGroup = new ReadingMeaningGroup;
    tenGroup->addEnglishMeaning("heaven");
    tenGroup->addFrenchMeaning("ciel");
    tenGroup->addKunReading(QString::fromUtf8("あめ"));
    tenGroup->addOnReading(QString::fromUtf8("テン"));
    ten = new Kanji();
    ten->setLiteral(QString::fromUtf8("天"));
    ten->addNameAsRadical("ten");
    ten->setStrokeCount(4);
    ten->setUnicode(9873);
    ten->setClassicalRadical(4);
    ten->setFrequency(1);
    ten->setGrade(1);
    ten->setJLPT(3);
    ten->setNelsonRadical(5);
    ten->addReadingMeaningGroup(tenGroup);

    ReadingMeaningGroup *vracGroup = new ReadingMeaningGroup;
    vracGroup->addEnglishMeaning("random");
    vracGroup->addEnglishMeaning("random2");
    vracGroup->addEnglishMeaning("random3");
    vracGroup->addFrenchMeaning("bidule");
    vracGroup->addFrenchMeaning("bidule2");
    vracGroup->addFrenchMeaning("bidule3");
    vracGroup->addKunReading("capouet");
    vracGroup->addOnReading("dalalalalala");
    vracGroup->addOnReading("veryLongOnPronunciationIDoubtIWillEverSeeItsEndButIHaveToTryveryLongOnPronunciationIDoubtIWillEverSeeItsEndButIHaveToTryveryLongOnPronunciationIDoubtIWillEverSeeItsEndButIHaveToTryveryLongOnPronunciationIDoubtIWillEverSeeItsEndButIHaveToTryveryLongOnPronunciationIDoubtIWillEverSeeItsEndButIHaveToTryveryLongOnPronunciationIDoubtIWillEverSeeItsEndButIHaveToTryveryLongOnPronunciationIDoubtIWillEverSeeItsEndButIHaveToTry,Right?");
    vrac = new Kanji();
    vrac->setLiteral(QString::fromUtf8("重"));
    vrac->addNameAsRadical("VRACAFKHDFJHSDJGHSDJHGSLJdakfnsajghkszhkzfshgkz,fsglkszgfkzsldgfzsjFHG");
    vrac->setStrokeCount(18);
    vrac->setUnicode(666);
    vrac->setClassicalRadical(0);
    vrac->setFrequency(1000);
    vrac->setGrade(0);
    vrac->setJLPT(0);
    vrac->setNelsonRadical(0);
    vrac->addReadingMeaningGroup(vracGroup);
    vrac->addReadingMeaningGroup(vracGroup);
}

void KanjiDetailsScrollAreaTestWindow::setKanji(Kanji *k)
{
    scrollLayout->removeWidget(kanjiDetails);
    delete kanjiDetails;
    kanjiDetails = new KanjiDetails(0, k, kanjiDB);
    kanjiDetails->adjustSize();
    scrollLayout->addWidget(kanjiDetails);
    scrollWidget->adjustSize();
}

void KanjiDetailsScrollAreaTestWindow::setTen()
{
    setKanji(ten);
}

void KanjiDetailsScrollAreaTestWindow::setVrac()
{
    setKanji(vrac);
}
