/********************************************************************************
** Form generated from reading UI file 'kanjidetails.ui'
**
** Created: Sun Sep 12 16:15:47 2010
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
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_1;
    QHBoxLayout *horizontalLayout;
    QLabel *strokeCountLabel;
    QLabel *staticStrokeCountLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *staticGradeLabel;
    QLabel *staticGradeLabel2;
    QLabel *gradeLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *staticJlptLabel;
    QLabel *jlptLabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *freqLabel;
    QLabel *staticFreqLabel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *staticClasRadLabel;
    QLabel *radClasLabel;
    QHBoxLayout *horizontalLayout_6;
    QLabel *staticNelsonRadLabel;
    QLabel *radNelsonLabel;
    QSpacerItem *verticalSpacer;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *staticVariantsLabel;
    QLabel *variantsLabel;
    QHBoxLayout *horizontalLayout_8;
    QLabel *staticNameRadLabel;
    QLabel *nameRadLabel;
    QHBoxLayout *horizontalLayout_9;
    QLabel *staticUnicodeLabel;
    QLabel *ucsLabel;
    QHBoxLayout *horizontalLayout_10;
    QLabel *staticJIS208Label;
    QLabel *jis208Label;
    QHBoxLayout *horizontalLayout_11;
    QLabel *staticJIS212Label;
    QLabel *jis212Label;
    QHBoxLayout *horizontalLayout_12;
    QLabel *staticJIS213Label;
    QLabel *jis213Label;
    QSpacerItem *verticalSpacer_3;
    QLabel *literalLabel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *readMeanLayout;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *nanoriLayout;
    QLabel *nanoriLabel;
    QSpacerItem *verticalSpacer_2;
    QFrame *line;

    void setupUi(QWidget *KanjiDetails)
    {
        if (KanjiDetails->objectName().isEmpty())
            KanjiDetails->setObjectName(QString::fromUtf8("KanjiDetails"));
        KanjiDetails->resize(640, 261);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(KanjiDetails->sizePolicy().hasHeightForWidth());
        KanjiDetails->setSizePolicy(sizePolicy);
        KanjiDetails->setMinimumSize(QSize(640, 261));
        KanjiDetails->setMaximumSize(QSize(16777215, 16777215));
        verticalLayoutWidget_2 = new QWidget(KanjiDetails);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(150, 20, 281, 131));
        verticalLayout_1 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_1->setObjectName(QString::fromUtf8("verticalLayout_1"));
        verticalLayout_1->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        strokeCountLabel = new QLabel(verticalLayoutWidget_2);
        strokeCountLabel->setObjectName(QString::fromUtf8("strokeCountLabel"));
        sizePolicy.setHeightForWidth(strokeCountLabel->sizePolicy().hasHeightForWidth());
        strokeCountLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        strokeCountLabel->setFont(font);

        horizontalLayout->addWidget(strokeCountLabel);

        staticStrokeCountLabel = new QLabel(verticalLayoutWidget_2);
        staticStrokeCountLabel->setObjectName(QString::fromUtf8("staticStrokeCountLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(staticStrokeCountLabel->sizePolicy().hasHeightForWidth());
        staticStrokeCountLabel->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(staticStrokeCountLabel);


        verticalLayout_1->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        staticGradeLabel = new QLabel(verticalLayoutWidget_2);
        staticGradeLabel->setObjectName(QString::fromUtf8("staticGradeLabel"));
        sizePolicy.setHeightForWidth(staticGradeLabel->sizePolicy().hasHeightForWidth());
        staticGradeLabel->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(staticGradeLabel);

        staticGradeLabel2 = new QLabel(verticalLayoutWidget_2);
        staticGradeLabel2->setObjectName(QString::fromUtf8("staticGradeLabel2"));
        sizePolicy.setHeightForWidth(staticGradeLabel2->sizePolicy().hasHeightForWidth());
        staticGradeLabel2->setSizePolicy(sizePolicy);
        staticGradeLabel2->setFont(font);

        horizontalLayout_2->addWidget(staticGradeLabel2);

        gradeLabel = new QLabel(verticalLayoutWidget_2);
        gradeLabel->setObjectName(QString::fromUtf8("gradeLabel"));
        sizePolicy1.setHeightForWidth(gradeLabel->sizePolicy().hasHeightForWidth());
        gradeLabel->setSizePolicy(sizePolicy1);
        gradeLabel->setFont(font);

        horizontalLayout_2->addWidget(gradeLabel);


        verticalLayout_1->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        staticJlptLabel = new QLabel(verticalLayoutWidget_2);
        staticJlptLabel->setObjectName(QString::fromUtf8("staticJlptLabel"));
        sizePolicy.setHeightForWidth(staticJlptLabel->sizePolicy().hasHeightForWidth());
        staticJlptLabel->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(staticJlptLabel);

        jlptLabel = new QLabel(verticalLayoutWidget_2);
        jlptLabel->setObjectName(QString::fromUtf8("jlptLabel"));
        sizePolicy1.setHeightForWidth(jlptLabel->sizePolicy().hasHeightForWidth());
        jlptLabel->setSizePolicy(sizePolicy1);
        jlptLabel->setFont(font);

        horizontalLayout_3->addWidget(jlptLabel);


        verticalLayout_1->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        freqLabel = new QLabel(verticalLayoutWidget_2);
        freqLabel->setObjectName(QString::fromUtf8("freqLabel"));
        sizePolicy.setHeightForWidth(freqLabel->sizePolicy().hasHeightForWidth());
        freqLabel->setSizePolicy(sizePolicy);
        freqLabel->setFont(font);

        horizontalLayout_4->addWidget(freqLabel);

        staticFreqLabel = new QLabel(verticalLayoutWidget_2);
        staticFreqLabel->setObjectName(QString::fromUtf8("staticFreqLabel"));
        sizePolicy1.setHeightForWidth(staticFreqLabel->sizePolicy().hasHeightForWidth());
        staticFreqLabel->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(8);
        staticFreqLabel->setFont(font1);
        staticFreqLabel->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_4->addWidget(staticFreqLabel);


        verticalLayout_1->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        staticClasRadLabel = new QLabel(verticalLayoutWidget_2);
        staticClasRadLabel->setObjectName(QString::fromUtf8("staticClasRadLabel"));
        sizePolicy.setHeightForWidth(staticClasRadLabel->sizePolicy().hasHeightForWidth());
        staticClasRadLabel->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(staticClasRadLabel);

        radClasLabel = new QLabel(verticalLayoutWidget_2);
        radClasLabel->setObjectName(QString::fromUtf8("radClasLabel"));
        sizePolicy1.setHeightForWidth(radClasLabel->sizePolicy().hasHeightForWidth());
        radClasLabel->setSizePolicy(sizePolicy1);
        radClasLabel->setFont(font);

        horizontalLayout_5->addWidget(radClasLabel);


        verticalLayout_1->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        staticNelsonRadLabel = new QLabel(verticalLayoutWidget_2);
        staticNelsonRadLabel->setObjectName(QString::fromUtf8("staticNelsonRadLabel"));
        sizePolicy.setHeightForWidth(staticNelsonRadLabel->sizePolicy().hasHeightForWidth());
        staticNelsonRadLabel->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(staticNelsonRadLabel);

        radNelsonLabel = new QLabel(verticalLayoutWidget_2);
        radNelsonLabel->setObjectName(QString::fromUtf8("radNelsonLabel"));
        sizePolicy1.setHeightForWidth(radNelsonLabel->sizePolicy().hasHeightForWidth());
        radNelsonLabel->setSizePolicy(sizePolicy1);
        radNelsonLabel->setFont(font);

        horizontalLayout_6->addWidget(radNelsonLabel);


        verticalLayout_1->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_1->addItem(verticalSpacer);

        verticalLayoutWidget_3 = new QWidget(KanjiDetails);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(440, 20, 191, 131));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        staticVariantsLabel = new QLabel(verticalLayoutWidget_3);
        staticVariantsLabel->setObjectName(QString::fromUtf8("staticVariantsLabel"));
        staticVariantsLabel->setFont(font);

        horizontalLayout_7->addWidget(staticVariantsLabel);

        variantsLabel = new QLabel(verticalLayoutWidget_3);
        variantsLabel->setObjectName(QString::fromUtf8("variantsLabel"));
        sizePolicy1.setHeightForWidth(variantsLabel->sizePolicy().hasHeightForWidth());
        variantsLabel->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        variantsLabel->setFont(font2);

        horizontalLayout_7->addWidget(variantsLabel);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        staticNameRadLabel = new QLabel(verticalLayoutWidget_3);
        staticNameRadLabel->setObjectName(QString::fromUtf8("staticNameRadLabel"));
        staticNameRadLabel->setFont(font);

        horizontalLayout_8->addWidget(staticNameRadLabel);

        nameRadLabel = new QLabel(verticalLayoutWidget_3);
        nameRadLabel->setObjectName(QString::fromUtf8("nameRadLabel"));
        sizePolicy1.setHeightForWidth(nameRadLabel->sizePolicy().hasHeightForWidth());
        nameRadLabel->setSizePolicy(sizePolicy1);
        nameRadLabel->setFont(font2);

        horizontalLayout_8->addWidget(nameRadLabel);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        staticUnicodeLabel = new QLabel(verticalLayoutWidget_3);
        staticUnicodeLabel->setObjectName(QString::fromUtf8("staticUnicodeLabel"));
        staticUnicodeLabel->setFont(font);

        horizontalLayout_9->addWidget(staticUnicodeLabel);

        ucsLabel = new QLabel(verticalLayoutWidget_3);
        ucsLabel->setObjectName(QString::fromUtf8("ucsLabel"));
        sizePolicy1.setHeightForWidth(ucsLabel->sizePolicy().hasHeightForWidth());
        ucsLabel->setSizePolicy(sizePolicy1);
        ucsLabel->setFont(font2);

        horizontalLayout_9->addWidget(ucsLabel);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        staticJIS208Label = new QLabel(verticalLayoutWidget_3);
        staticJIS208Label->setObjectName(QString::fromUtf8("staticJIS208Label"));
        staticJIS208Label->setFont(font);

        horizontalLayout_10->addWidget(staticJIS208Label);

        jis208Label = new QLabel(verticalLayoutWidget_3);
        jis208Label->setObjectName(QString::fromUtf8("jis208Label"));
        sizePolicy1.setHeightForWidth(jis208Label->sizePolicy().hasHeightForWidth());
        jis208Label->setSizePolicy(sizePolicy1);
        jis208Label->setFont(font2);

        horizontalLayout_10->addWidget(jis208Label);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        staticJIS212Label = new QLabel(verticalLayoutWidget_3);
        staticJIS212Label->setObjectName(QString::fromUtf8("staticJIS212Label"));
        staticJIS212Label->setFont(font);

        horizontalLayout_11->addWidget(staticJIS212Label);

        jis212Label = new QLabel(verticalLayoutWidget_3);
        jis212Label->setObjectName(QString::fromUtf8("jis212Label"));
        sizePolicy1.setHeightForWidth(jis212Label->sizePolicy().hasHeightForWidth());
        jis212Label->setSizePolicy(sizePolicy1);
        jis212Label->setFont(font2);

        horizontalLayout_11->addWidget(jis212Label);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        staticJIS213Label = new QLabel(verticalLayoutWidget_3);
        staticJIS213Label->setObjectName(QString::fromUtf8("staticJIS213Label"));
        staticJIS213Label->setFont(font);

        horizontalLayout_12->addWidget(staticJIS213Label);

        jis213Label = new QLabel(verticalLayoutWidget_3);
        jis213Label->setObjectName(QString::fromUtf8("jis213Label"));
        sizePolicy1.setHeightForWidth(jis213Label->sizePolicy().hasHeightForWidth());
        jis213Label->setSizePolicy(sizePolicy1);
        jis213Label->setFont(font2);

        horizontalLayout_12->addWidget(jis213Label);


        verticalLayout_2->addLayout(horizontalLayout_12);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        literalLabel = new QLabel(KanjiDetails);
        literalLabel->setObjectName(QString::fromUtf8("literalLabel"));
        literalLabel->setGeometry(QRect(10, 10, 120, 120));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(120);
        sizePolicy2.setVerticalStretch(120);
        sizePolicy2.setHeightForWidth(literalLabel->sizePolicy().hasHeightForWidth());
        literalLabel->setSizePolicy(sizePolicy2);
        literalLabel->setMinimumSize(QSize(120, 120));
        literalLabel->setMaximumSize(QSize(120, 120));
        QFont font3;
        font3.setPointSize(80);
        literalLabel->setFont(font3);
        literalLabel->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(KanjiDetails);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 160, 231, 71));
        readMeanLayout = new QVBoxLayout(verticalLayoutWidget);
        readMeanLayout->setObjectName(QString::fromUtf8("readMeanLayout"));
        readMeanLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_4 = new QWidget(KanjiDetails);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(240, 160, 231, 71));
        nanoriLayout = new QVBoxLayout(verticalLayoutWidget_4);
        nanoriLayout->setObjectName(QString::fromUtf8("nanoriLayout"));
        nanoriLayout->setContentsMargins(0, 0, 0, 0);
        nanoriLabel = new QLabel(verticalLayoutWidget_4);
        nanoriLabel->setObjectName(QString::fromUtf8("nanoriLabel"));

        nanoriLayout->addWidget(nanoriLabel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        nanoriLayout->addItem(verticalSpacer_2);

        line = new QFrame(KanjiDetails);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 250, 601, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(KanjiDetails);

        QMetaObject::connectSlotsByName(KanjiDetails);
    } // setupUi

    void retranslateUi(QWidget *KanjiDetails)
    {
        KanjiDetails->setWindowTitle(QApplication::translate("KanjiDetails", "Form", 0, QApplication::UnicodeUTF8));
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
        literalLabel->setText(QApplication::translate("KanjiDetails", "\343\203\266", 0, QApplication::UnicodeUTF8));
        nanoriLabel->setText(QApplication::translate("KanjiDetails", "[nanori]", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class KanjiDetails: public Ui_KanjiDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KANJIDETAILS_H
