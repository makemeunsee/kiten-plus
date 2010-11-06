# -------------------------------------------------
# Project created by QtCreator 2010-08-18T10:31:57
# -------------------------------------------------
QT += xml
CONFIG += console
TARGET = kiten+
SOURCES += main.cpp \
    mainwindow.cpp \
    kanjidetails.cpp \
    tests/kanjidetailsscrollareatestwindow.cpp \
    readingmeaninggroupwidget.cpp \
    searchablelabel.cpp \
    searchbar.cpp \
    history.cpp \
    resultsbuffer.cpp \
    searchthread.cpp \
    searchcompleter.cpp \
    searchlineedit.cpp
HEADERS += mainwindow.h \
    kanjidetails.h \
    tests/kanjidetailsscrollareatestwindow.h \
    readingmeaninggroupwidget.h \
    searchablelabel.h \
    searchbar.h \
    history.h \
    resultsbuffer.h \
    searchthread.h \
    searchcompleter.h \
    searchlineedit.h
FORMS += kanjidetails.ui \
    readingmeaninggroupwidget.ui \
    searchbar.ui
win32 { 
    debug:LIBS += -L../JapaneseDB/debug \
        -lJapaneseDB
    else:LIBS += -L../JapaneseDB/release \
        -lJapaneseDB
}
unix:LIBS += -L../JapaneseDB \
    -lJapaneseDB
OTHER_FILES += TODOs.txt \
    icons/right.png \
    icons/left.png \
    icons/katen.png \
    README
