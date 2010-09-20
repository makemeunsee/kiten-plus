# -------------------------------------------------
# Project created by QtCreator 2010-08-18T10:31:57
# -------------------------------------------------
QT += xml
TARGET = kiten+
SOURCES += main.cpp \
    mainwindow.cpp \
    kanjidetails.cpp \
    tests/kanjidetailsscrollareatestwindow.cpp \
    readingmeaninggroupwidget.cpp
HEADERS += mainwindow.h \
    kanjidetails.h \
    tests/kanjidetailsscrollareatestwindow.h \
    readingmeaninggroupwidget.h
FORMS += kanjidetails.ui \
    readingmeaninggroupwidget.ui
LIBS += -L../JapaneseDB \
    -lJapaneseDB
OTHER_FILES += TODOs.txt
