/********************************************************************************
** Form generated from reading UI file 'kanjidetails.ui'
**
** Created: Mon Sep 20 09:21:09 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KANJIDETAILS_H
#define UI_KANJIDETAILS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KanjiDetails
{
public:
    QGridLayout *gridLayout;
    QLabel *literalLabel;
    QVBoxLayout *leftColumnLayout;
    QHBoxLayout *strokeLayout;
    QLabel *strokeCountLabel;
    QLabel *staticStrokeCountLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *staticGradeLabel;
    QLabel *staticGradeLabel2;
    QLabel *gradeLabel;
    QHBoxLayout *jlptLayout;
    QLabel *staticJlptLabel;
    QLabel *jlptLabel;
    QHBoxLayout *freqLayout;
    QLabel *freqLabel;
    QLabel *staticFreqLabel;
    QHBoxLayout *radClasLayout;
    QLabel *staticClasRadLabel;
    QLabel *radClasLabel;
    QHBoxLayout *radNelsLayout;
    QLabel *staticNelsonRadLabel;
    QLabel *radNelsonLabel;
    QSpacerItem *leftColumnSpacer;
    QVBoxLayout *rightColumnLayout;
    QHBoxLayout *variantsLayout;
    QLabel *staticVariantsLabel;
    QLabel *variantsLabel;
    QHBoxLayout *nameRadLayout;
    QLabel *staticNameRadLabel;
    QLabel *nameRadLabel;
    QHBoxLayout *unicodeLayout;
    QLabel *staticUnicodeLabel;
    QLabel *ucsLabel;
    QHBoxLayout *jis208Layout;
    QLabel *staticJIS208Label;
    QLabel *jis208Label;
    QHBoxLayout *jis212Layout;
    QLabel *staticJIS212Label;
    QLabel *jis212Label;
    QHBoxLayout *jis213Layout;
    QLabel *staticJIS213Label;
    QLabel *jis213Label;
    QSpacerItem *rightColumnSpacer;
    QFrame *line;
    QVBoxLayout *readMeanLayout;

    void setupUi(QWidget *KanjiDetails)
    {
        if (KanjiDetails->objectName().isEmpty())
            KanjiDetails->setObjectName(QString::fromUtf8("KanjiDetails"));
        KanjiDetails->resize(620, 220);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(KanjiDetails->sizePolicy().hasHeightForWidth());
        KanjiDetails->setSizePolicy(sizePolicy);
        KanjiDetails->setMinimumSize(QSize(620, 220));
        KanjiDetails->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(KanjiDetails);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        literalLabel = new QLabel(KanjiDetails);
        literalLabel->setObjectName(QString::fromUtf8("literalLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(120);
        sizePolicy1.setVerticalStretch(120);
        sizePolicy1.setHeightForWidth(literalLabel->sizePolicy().hasHeightForWidth());
        literalLabel->setSizePolicy(sizePolicy1);
        literalLabel->setMinimumSize(QSize(120, 120));
        literalLabel->setMaximumSize(QSize(120, 120));
        QFont font;
        font.setPointSize(80);
        literalLabel->setFont(font);
        literalLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(literalLabel, 0, 0, 1, 1);

        leftColumnLayout = new QVBoxLayout();
        leftColumnLayout->setObjectName(QString::fromUtf8("leftColumnLayout"));
        strokeLayout = new QHBoxLayout();
        strokeLayout->setObjectName(QString::fromUtf8("strokeLayout"));
        strokeLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        strokeCountLabel = new QLabel(KanjiDetails);
        strokeCountLabel->setObjectName(QString::fromUtf8("strokeCountLabel"));
        sizePolicy.setHeightForWidth(strokeCountLabel->sizePolicy().hasHeightForWidth());
        strokeCountLabel->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        strokeCountLabel->setFont(font1);

        strokeLayout->addWidget(strokeCountLabel);

        staticStrokeCountLabel = new QLabel(KanjiDetails);
        staticStrokeCountLabel->setObjectName(QString::fromUtf8("staticStrokeCountLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(staticStrokeCountLabel->sizePolicy().hasHeightForWidth());
        staticStrokeCountLabel->setSizePolicy(sizePolicy2);

        strokeLayout->addWidget(staticStrokeCountLabel);


        leftColumnLayout->addLayout(strokeLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        staticGradeLabel = new QLabel(KanjiDetails);
        staticGradeLabel->setObjectName(QString::fromUtf8("staticGradeLabel"));
        sizePolicy.setHeightForWidth(staticGradeLabel->sizePolicy().hasHeightForWidth());
        staticGradeLabel->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(staticGradeLabel);

        staticGradeLabel2 = new QLabel(KanjiDetails);
        staticGradeLabel2->setObjectName(QString::fromUtf8("staticGradeLabel2"));
        sizePolicy.setHeightForWidth(staticGradeLabel2->sizePolicy().hasHeightForWidth());
        staticGradeLabel2->setSizePolicy(sizePolicy);
        staticGradeLabel2->setFont(font1);

        horizontalLayout_2->addWidget(staticGradeLabel2);

        gradeLabel = new QLabel(KanjiDetails);
        gradeLabel->setObjectName(QString::fromUtf8("gradeLabel"));
        sizePolicy2.setHeightForWidth(gradeLabel->sizePolicy().hasHeightForWidth());
        gradeLabel->setSizePolicy(sizePolicy2);
        gradeLabel->setFont(font1);

        horizontalLayout_2->addWidget(gradeLabel);


        leftColumnLayout->addLayout(horizontalLayout_2);

        jlptLayout = new QHBoxLayout();
        jlptLayout->setObjectName(QString::fromUtf8("jlptLayout"));
        jlptLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        staticJlptLabel = new QLabel(KanjiDetails);
        staticJlptLabel->setObjectName(QString::fromUtf8("staticJlptLabel"));
        sizePolicy.setHeightForWidth(staticJlptLabel->sizePolicy().hasHeightForWidth());
        staticJlptLabel->setSizePolicy(sizePolicy);

        jlptLayout->addWidget(staticJlptLabel);

        jlptLabel = new QLabel(KanjiDetails);
        jlptLabel->setObjectName(QString::fromUtf8("jlptLabel"));
        sizePolicy2.setHeightForWidth(jlptLabel->sizePolicy().hasHeightForWidth());
        jlptLabel->setSizePolicy(sizePolicy2);
        jlptLabel->setFont(font1);

        jlptLayout->addWidget(jlptLabel);


        leftColumnLayout->addLayout(jlptLayout);

        freqLayout = new QHBoxLayout();
        freqLayout->setObjectName(QString::fromUtf8("freqLayout"));
        freqLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        freqLabel = new QLabel(KanjiDetails);
        freqLabel->setObjectName(QString::fromUtf8("freqLabel"));
        sizePolicy.setHeightForWidth(freqLabel->sizePolicy().hasHeightForWidth());
        freqLabel->setSizePolicy(sizePolicy);
        freqLabel->setFont(font1);

        freqLayout->addWidget(freqLabel);

        staticFreqLabel = new QLabel(KanjiDetails);
        staticFreqLabel->setObjectName(QString::fromUtf8("staticFreqLabel"));
        sizePolicy2.setHeightForWidth(staticFreqLabel->sizePolicy().hasHeightForWidth());
        staticFreqLabel->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setPointSize(8);
        staticFreqLabel->setFont(font2);
        staticFreqLabel->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        freqLayout->addWidget(staticFreqLabel);


        leftColumnLayout->addLayout(freqLayout);

        radClasLayout = new QHBoxLayout();
        radClasLayout->setObjectName(QString::fromUtf8("radClasLayout"));
        radClasLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        staticClasRadLabel = new QLabel(KanjiDetails);
        staticClasRadLabel->setObjectName(QString::fromUtf8("staticClasRadLabel"));
        sizePolicy.setHeightForWidth(staticClasRadLabel->sizePolicy().hasHeightForWidth());
        staticClasRadLabel->setSizePolicy(sizePolicy);

        radClasLayout->addWidget(staticClasRadLabel);

        radClasLabel = new QLabel(KanjiDetails);
        radClasLabel->setObjectName(QString::fromUtf8("radClasLabel"));
        sizePolicy2.setHeightForWidth(radClasLabel->sizePolicy().hasHeightForWidth());
        radClasLabel->setSizePolicy(sizePolicy2);
        radClasLabel->setFont(font1);

        radClasLayout->addWidget(radClasLabel);


        leftColumnLayout->addLayout(radClasLayout);

        radNelsLayout = new QHBoxLayout();
        radNelsLayout->setObjectName(QString::fromUtf8("radNelsLayout"));
        radNelsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        staticNelsonRadLabel = new QLabel(KanjiDetails);
        staticNelsonRadLabel->setObjectName(QString::fromUtf8("staticNelsonRadLabel"));
        sizePolicy.setHeightForWidth(staticNelsonRadLabel->sizePolicy().hasHeightForWidth());
        staticNelsonRadLabel->setSizePolicy(sizePolicy);

        radNelsLayout->addWidget(staticNelsonRadLabel);

        radNelsonLabel = new QLabel(KanjiDetails);
        radNelsonLabel->setObjectName(QString::fromUtf8("radNelsonLabel"));
        sizePolicy2.setHeightForWidth(radNelsonLabel->sizePolicy().hasHeightForWidth());
        radNelsonLabel->setSizePolicy(sizePolicy2);
        radNelsonLabel->setFont(font1);

        radNelsLayout->addWidget(radNelsonLabel);


        leftColumnLayout->addLayout(radNelsLayout);

        leftColumnSpacer = new QSpacerItem(280, 12, QSizePolicy::Minimum, QSizePolicy::Expanding);

        leftColumnLayout->addItem(leftColumnSpacer);


        gridLayout->addLayout(leftColumnLayout, 0, 1, 1, 2);

        rightColumnLayout = new QVBoxLayout();
        rightColumnLayout->setObjectName(QString::fromUtf8("rightColumnLayout"));
        rightColumnLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        variantsLayout = new QHBoxLayout();
        variantsLayout->setObjectName(QString::fromUtf8("variantsLayout"));
        staticVariantsLabel = new QLabel(KanjiDetails);
        staticVariantsLabel->setObjectName(QString::fromUtf8("staticVariantsLabel"));
        staticVariantsLabel->setFont(font1);

        variantsLayout->addWidget(staticVariantsLabel);

        variantsLabel = new QLabel(KanjiDetails);
        variantsLabel->setObjectName(QString::fromUtf8("variantsLabel"));
        sizePolicy2.setHeightForWidth(variantsLabel->sizePolicy().hasHeightForWidth());
        variantsLabel->setSizePolicy(sizePolicy2);
        QFont font3;
        font3.setBold(false);
        font3.setWeight(50);
        variantsLabel->setFont(font3);

        variantsLayout->addWidget(variantsLabel);


        rightColumnLayout->addLayout(variantsLayout);

        nameRadLayout = new QHBoxLayout();
        nameRadLayout->setObjectName(QString::fromUtf8("nameRadLayout"));
        nameRadLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        staticNameRadLabel = new QLabel(KanjiDetails);
        staticNameRadLabel->setObjectName(QString::fromUtf8("staticNameRadLabel"));
        staticNameRadLabel->setFont(font1);

        nameRadLayout->addWidget(staticNameRadLabel);

        nameRadLabel = new QLabel(KanjiDetails);
        nameRadLabel->setObjectName(QString::fromUtf8("nameRadLabel"));
        sizePolicy2.setHeightForWidth(nameRadLabel->sizePolicy().hasHeightForWidth());
        nameRadLabel->setSizePolicy(sizePolicy2);
        nameRadLabel->setFont(font3);

        nameRadLayout->addWidget(nameRadLabel);


        rightColumnLayout->addLayout(nameRadLayout);

        unicodeLayout = new QHBoxLayout();
        unicodeLayout->setObjectName(QString::fromUtf8("unicodeLayout"));
        staticUnicodeLabel = new QLabel(KanjiDetails);
        staticUnicodeLabel->setObjectName(QString::fromUtf8("staticUnicodeLabel"));
        staticUnicodeLabel->setFont(font1);

        unicodeLayout->addWidget(staticUnicodeLabel);

        ucsLabel = new QLabel(KanjiDetails);
        ucsLabel->setObjectName(QString::fromUtf8("ucsLabel"));
        sizePolicy2.setHeightForWidth(ucsLabel->sizePolicy().hasHeightForWidth());
        ucsLabel->setSizePolicy(sizePolicy2);
        ucsLabel->setFont(font3);

        unicodeLayout->addWidget(ucsLabel);


        rightColumnLayout->addLayout(unicodeLayout);

        jis208Layout = new QHBoxLayout();
        jis208Layout->setObjectName(QString::fromUtf8("jis208Layout"));
        staticJIS208Label = new QLabel(KanjiDetails);
        staticJIS208Label->setObjectName(QString::fromUtf8("staticJIS208Label"));
        staticJIS208Label->setFont(font1);

        jis208Layout->addWidget(staticJIS208Label);

        jis208Label = new QLabel(KanjiDetails);
        jis208Label->setObjectName(QString::fromUtf8("jis208Label"));
        sizePolicy2.setHeightForWidth(jis208Label->sizePolicy().hasHeightForWidth());
        jis208Label->setSizePolicy(sizePolicy2);
        jis208Label->setFont(font3);

        jis208Layout->addWidget(jis208Label);


        rightColumnLayout->addLayout(jis208Layout);

        jis212Layout = new QHBoxLayout();
        jis212Layout->setObjectName(QString::fromUtf8("jis212Layout"));
        staticJIS212Label = new QLabel(KanjiDetails);
        staticJIS212Label->setObjectName(QString::fromUtf8("staticJIS212Label"));
        staticJIS212Label->setFont(font1);

        jis212Layout->addWidget(staticJIS212Label);

        jis212Label = new QLabel(KanjiDetails);
        jis212Label->setObjectName(QString::fromUtf8("jis212Label"));
        sizePolicy2.setHeightForWidth(jis212Label->sizePolicy().hasHeightForWidth());
        jis212Label->setSizePolicy(sizePolicy2);
        jis212Label->setFont(font3);

        jis212Layout->addWidget(jis212Label);


        rightColumnLayout->addLayout(jis212Layout);

        jis213Layout = new QHBoxLayout();
        jis213Layout->setObjectName(QString::fromUtf8("jis213Layout"));
        staticJIS213Label = new QLabel(KanjiDetails);
        staticJIS213Label->setObjectName(QString::fromUtf8("staticJIS213Label"));
        staticJIS213Label->setFont(font1);

        jis213Layout->addWidget(staticJIS213Label);

        jis213Label = new QLabel(KanjiDetails);
        jis213Label->setObjectName(QString::fromUtf8("jis213Label"));
        sizePolicy2.setHeightForWidth(jis213Label->sizePolicy().hasHeightForWidth());
        jis213Label->setSizePolicy(sizePolicy2);
        jis213Label->setFont(font3);

        jis213Layout->addWidget(jis213Label);


        rightColumnLayout->addLayout(jis213Layout);

        rightColumnSpacer = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Expanding);

        rightColumnLayout->addItem(rightColumnSpacer);


        gridLayout->addLayout(rightColumnLayout, 0, 3, 1, 1);

        line = new QFrame(KanjiDetails);
        line->setObjectName(QString::fromUtf8("line"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy3);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 4);

        readMeanLayout = new QVBoxLayout();
        readMeanLayout->setObjectName(QString::fromUtf8("readMeanLayout"));

        gridLayout->addLayout(readMeanLayout, 1, 1, 1, 2);


        retranslateUi(KanjiDetails);

        QMetaObject::connectSlotsByName(KanjiDetails);
    } // setupUi

    void retranslateUi(QWidget *KanjiDetails)
    {
        KanjiDetails->setWindowTitle(QApplication::translate("KanjiDetails", "Form", 0, QApplication::UnicodeUTF8));
        literalLabel->setText(QApplication::translate("KanjiDetails", "\343\203\266", 0, QApplication::UnicodeUTF8));
        strokeCountLabel->setText(QApplication::translate("KanjiDetails", "[stroke count]", 0, QApplication::UnicodeUTF8));
        staticStrokeCountLabel->setText(QApplication::translate("KanjiDetails", "strokes", 0, QApplication::UnicodeUTF8));
        staticGradeLabel->setText(QApplication::translate("KanjiDetails", "Taught in", 0, QApplication::UnicodeUTF8));
        staticGradeLabel2->setText(QApplication::translate("KanjiDetails", "grade", 0, QApplication::UnicodeUTF8));
        gradeLabel->setText(QApplication::translate("KanjiDetails", "[grade]", 0, QApplication::UnicodeUTF8));
        staticJlptLabel->setText(QApplication::translate("KanjiDetails", "JLPT level", 0, QApplication::UnicodeUTF8));
        jlptLabel->setText(QApplication::translate("KanjiDetails", "[jlpt]", 0, QApplication::UnicodeUTF8));
        freqLabel->setText(QApplication::translate("KanjiDetails", "[freq]", 0, QApplication::UnicodeUTF8));
        staticFreqLabel->setText(QApplication::translate("KanjiDetails", "of 2500 most used Kanjis in newspapers", 0, QApplication::UnicodeUTF8));
        staticClasRadLabel->setText(QApplication::translate("KanjiDetails", "Radical (KanXi):", 0, QApplication::UnicodeUTF8));
        radClasLabel->setText(QApplication::translate("KanjiDetails", "[radClas]", 0, QApplication::UnicodeUTF8));
        staticNelsonRadLabel->setText(QApplication::translate("KanjiDetails", "Radical (Nelson):", 0, QApplication::UnicodeUTF8));
        radNelsonLabel->setText(QApplication::translate("KanjiDetails", "[radNels]", 0, QApplication::UnicodeUTF8));
        staticVariantsLabel->setText(QApplication::translate("KanjiDetails", "Variant", 0, QApplication::UnicodeUTF8));
        variantsLabel->setText(QApplication::translate("KanjiDetails", "[variants]", 0, QApplication::UnicodeUTF8));
        staticNameRadLabel->setText(QApplication::translate("KanjiDetails", "Names as radical", 0, QApplication::UnicodeUTF8));
        nameRadLabel->setText(QApplication::translate("KanjiDetails", "[name]", 0, QApplication::UnicodeUTF8));
        staticUnicodeLabel->setText(QApplication::translate("KanjiDetails", "Unicode", 0, QApplication::UnicodeUTF8));
        ucsLabel->setText(QApplication::translate("KanjiDetails", "[unicode]", 0, QApplication::UnicodeUTF8));
        staticJIS208Label->setText(QApplication::translate("KanjiDetails", "JIS208", 0, QApplication::UnicodeUTF8));
        jis208Label->setText(QApplication::translate("KanjiDetails", "[jis208]", 0, QApplication::UnicodeUTF8));
        staticJIS212Label->setText(QApplication::translate("KanjiDetails", "JIS212", 0, QApplication::UnicodeUTF8));
        jis212Label->setText(QApplication::translate("KanjiDetails", "[jis212]", 0, QApplication::UnicodeUTF8));
        staticJIS213Label->setText(QApplication::translate("KanjiDetails", "JIS213", 0, QApplication::UnicodeUTF8));
        jis213Label->setText(QApplication::translate("KanjiDetails", "[jis213]", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class KanjiDetails: public Ui_KanjiDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KANJIDETAILS_H
