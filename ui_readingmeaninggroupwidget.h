/********************************************************************************
** Form generated from reading UI file 'readingmeaninggroupwidget.ui'
**
** Created: Mon Sep 20 09:24:19 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READINGMEANINGGROUPWIDGET_H
#define UI_READINGMEANINGGROUPWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReadingMeaningGroupWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *onReadingsLabel;
    QLabel *kunReadingsLabel;
    QLabel *englishMeaningLabel;
    QLabel *frenchMeaningLabel;
    QVBoxLayout *onReadingsLayout;
    QVBoxLayout *kunReadingsLayout;
    QVBoxLayout *englishMeaningsLayout;
    QVBoxLayout *frenchMeaningsLayout;

    void setupUi(QWidget *ReadingMeaningGroupWidget)
    {
        if (ReadingMeaningGroupWidget->objectName().isEmpty())
            ReadingMeaningGroupWidget->setObjectName(QString::fromUtf8("ReadingMeaningGroupWidget"));
        ReadingMeaningGroupWidget->resize(249, 84);
        gridLayout = new QGridLayout(ReadingMeaningGroupWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        onReadingsLabel = new QLabel(ReadingMeaningGroupWidget);
        onReadingsLabel->setObjectName(QString::fromUtf8("onReadingsLabel"));
        onReadingsLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(onReadingsLabel, 0, 0, 1, 1);

        kunReadingsLabel = new QLabel(ReadingMeaningGroupWidget);
        kunReadingsLabel->setObjectName(QString::fromUtf8("kunReadingsLabel"));
        kunReadingsLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(kunReadingsLabel, 1, 0, 1, 1);

        englishMeaningLabel = new QLabel(ReadingMeaningGroupWidget);
        englishMeaningLabel->setObjectName(QString::fromUtf8("englishMeaningLabel"));
        englishMeaningLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(englishMeaningLabel, 2, 0, 1, 1);

        frenchMeaningLabel = new QLabel(ReadingMeaningGroupWidget);
        frenchMeaningLabel->setObjectName(QString::fromUtf8("frenchMeaningLabel"));
        frenchMeaningLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(frenchMeaningLabel, 3, 0, 1, 1);

        onReadingsLayout = new QVBoxLayout();
        onReadingsLayout->setObjectName(QString::fromUtf8("onReadingsLayout"));

        gridLayout->addLayout(onReadingsLayout, 0, 1, 1, 1);

        kunReadingsLayout = new QVBoxLayout();
        kunReadingsLayout->setObjectName(QString::fromUtf8("kunReadingsLayout"));

        gridLayout->addLayout(kunReadingsLayout, 1, 1, 1, 1);

        englishMeaningsLayout = new QVBoxLayout();
        englishMeaningsLayout->setObjectName(QString::fromUtf8("englishMeaningsLayout"));

        gridLayout->addLayout(englishMeaningsLayout, 2, 1, 1, 1);

        frenchMeaningsLayout = new QVBoxLayout();
        frenchMeaningsLayout->setObjectName(QString::fromUtf8("frenchMeaningsLayout"));

        gridLayout->addLayout(frenchMeaningsLayout, 3, 1, 1, 1);


        retranslateUi(ReadingMeaningGroupWidget);

        QMetaObject::connectSlotsByName(ReadingMeaningGroupWidget);
    } // setupUi

    void retranslateUi(QWidget *ReadingMeaningGroupWidget)
    {
        ReadingMeaningGroupWidget->setWindowTitle(QApplication::translate("ReadingMeaningGroupWidget", "Form", 0, QApplication::UnicodeUTF8));
        onReadingsLabel->setText(QApplication::translate("ReadingMeaningGroupWidget", "Readings on:", 0, QApplication::UnicodeUTF8));
        kunReadingsLabel->setText(QApplication::translate("ReadingMeaningGroupWidget", "Readings kun:", 0, QApplication::UnicodeUTF8));
        englishMeaningLabel->setText(QApplication::translate("ReadingMeaningGroupWidget", "English meanings:", 0, QApplication::UnicodeUTF8));
        frenchMeaningLabel->setText(QApplication::translate("ReadingMeaningGroupWidget", "French meanings:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ReadingMeaningGroupWidget: public Ui_ReadingMeaningGroupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READINGMEANINGGROUPWIDGET_H
