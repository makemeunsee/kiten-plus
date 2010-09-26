#############################################################################
# Makefile for building: kiten+
# Generated by qmake (2.01a) (Qt 4.6.2) on: Fri Sep 24 13:11:00 2010
# Project:  kiten+.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile kiten+.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtXml -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -L../JapaneseDB -lJapaneseDB -lQtXml -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		kanjidetails.cpp \
		tests/kanjidetailsscrollareatestwindow.cpp \
		readingmeaninggroupwidget.cpp \
		resultsbuffer.cpp \
		searchablelabel.cpp \
		searchbar.cpp moc_mainwindow.cpp \
		moc_kanjidetails.cpp \
		moc_kanjidetailsscrollareatestwindow.cpp \
		moc_readingmeaninggroupwidget.cpp \
		moc_resultsbuffer.cpp \
		moc_searchablelabel.cpp \
		moc_searchbar.cpp
OBJECTS       = main.o \
		mainwindow.o \
		kanjidetails.o \
		kanjidetailsscrollareatestwindow.o \
		readingmeaninggroupwidget.o \
		resultsbuffer.o \
		searchablelabel.o \
		searchbar.o \
		moc_mainwindow.o \
		moc_kanjidetails.o \
		moc_kanjidetailsscrollareatestwindow.o \
		moc_readingmeaninggroupwidget.o \
		moc_resultsbuffer.o \
		moc_searchablelabel.o \
		moc_searchbar.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		kiten+.pro
QMAKE_TARGET  = kiten+
DESTDIR       = 
TARGET        = kiten+

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_kanjidetails.h ui_readingmeaninggroupwidget.h ui_searchbar.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: kiten+.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtXml.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile kiten+.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtXml.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile kiten+.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/kiten+1.0.0 || $(MKDIR) .tmp/kiten+1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/kiten+1.0.0/ && $(COPY_FILE) --parents mainwindow.h kanjidetails.h tests/kanjidetailsscrollareatestwindow.h readingmeaninggroupwidget.h searchablelabel.h searchbar.h .tmp/kiten+1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp kanjidetails.cpp tests/kanjidetailsscrollareatestwindow.cpp readingmeaninggroupwidget.cpp searchablelabel.cpp searchbar.cpp .tmp/kiten+1.0.0/ && $(COPY_FILE) --parents kanjidetails.ui readingmeaninggroupwidget.ui searchbar.ui .tmp/kiten+1.0.0/ && (cd `dirname .tmp/kiten+1.0.0` && $(TAR) kiten+1.0.0.tar kiten+1.0.0 && $(COMPRESS) kiten+1.0.0.tar) && $(MOVE) `dirname .tmp/kiten+1.0.0`/kiten+1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/kiten+1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core

####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_kanjidetails.cpp moc_kanjidetailsscrollareatestwindow.cpp moc_readingmeaninggroupwidget.cpp moc_resultsbuffer.cpp moc_searchablelabel.cpp moc_searchbar.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_kanjidetails.cpp moc_kanjidetailsscrollareatestwindow.cpp moc_readingmeaninggroupwidget.cpp moc_resultsbuffer.cpp moc_searchablelabel.cpp moc_searchbar.cpp
moc_mainwindow.cpp: mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_kanjidetails.cpp: kanjidetails.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) kanjidetails.h -o moc_kanjidetails.cpp

moc_kanjidetailsscrollareatestwindow.cpp: tests/kanjidetailsscrollareatestwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) tests/kanjidetailsscrollareatestwindow.h -o moc_kanjidetailsscrollareatestwindow.cpp

moc_readingmeaninggroupwidget.cpp: readingmeaninggroupwidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) readingmeaninggroupwidget.h -o moc_readingmeaninggroupwidget.cpp

moc_resultsbuffer.cpp: resultsbuffer.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) resultsbuffer.h -o moc_resultsbuffer.cpp

moc_searchablelabel.cpp: searchablelabel.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) searchablelabel.h -o moc_searchablelabel.cpp

moc_searchbar.cpp: searchbar.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) searchbar.h -o moc_searchbar.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_kanjidetails.h ui_readingmeaninggroupwidget.h ui_searchbar.h
compiler_uic_clean:
	-$(DEL_FILE) ui_kanjidetails.h ui_readingmeaninggroupwidget.h ui_searchbar.h
ui_kanjidetails.h: kanjidetails.ui
	/usr/bin/uic-qt4 kanjidetails.ui -o ui_kanjidetails.h

ui_readingmeaninggroupwidget.h: readingmeaninggroupwidget.ui
	/usr/bin/uic-qt4 readingmeaninggroupwidget.ui -o ui_readingmeaninggroupwidget.h

ui_searchbar.h: searchbar.ui
	/usr/bin/uic-qt4 searchbar.ui -o ui_searchbar.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		../JapaneseDB/kanjidb.h \
		../JapaneseDB/kanji.h \
		kanjidetails.h \
		resultsbuffer.h \
		searchbar.h \
		ui_searchbar.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

kanjidetails.o: kanjidetails.cpp kanjidetails.h \
		mainwindow.h \
		ui_kanjidetails.h \
		readingmeaninggroupwidget.h \
		ui_readingmeaninggroupwidget.h \
		../JapaneseDB/kanji.h \
		../JapaneseDB/kanjidb.h \
		../JapaneseDB/readingmeaninggroup.h \
		searchablelabel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o kanjidetails.o kanjidetails.cpp

kanjidetailsscrollareatestwindow.o: tests/kanjidetailsscrollareatestwindow.cpp tests/kanjidetailsscrollareatestwindow.h \
		kanjidetails.h \
		../JapaneseDB/kanjidb.h \
		../JapaneseDB/kanji.h \
		../JapaneseDB/readingmeaninggroup.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o kanjidetailsscrollareatestwindow.o tests/kanjidetailsscrollareatestwindow.cpp

readingmeaninggroupwidget.o: readingmeaninggroupwidget.cpp readingmeaninggroupwidget.h \
		ui_readingmeaninggroupwidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o readingmeaninggroupwidget.o readingmeaninggroupwidget.cpp

searchablelabel.o: searchablelabel.cpp searchablelabel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o searchablelabel.o searchablelabel.cpp

searchbar.o: searchbar.cpp searchbar.h \
		resultsbuffer.h \
		ui_searchbar.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o searchbar.o searchbar.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_kanjidetails.o: moc_kanjidetails.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_kanjidetails.o moc_kanjidetails.cpp

moc_kanjidetailsscrollareatestwindow.o: moc_kanjidetailsscrollareatestwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_kanjidetailsscrollareatestwindow.o moc_kanjidetailsscrollareatestwindow.cpp

moc_readingmeaninggroupwidget.o: moc_readingmeaninggroupwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_readingmeaninggroupwidget.o moc_readingmeaninggroupwidget.cpp

moc_resultsbuffer.o: moc_resultsbuffer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_resultsbuffer.o moc_resultsbuffer.cpp

moc_searchablelabel.o: moc_searchablelabel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_searchablelabel.o moc_searchablelabel.cpp

moc_searchbar.o: moc_searchbar.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_searchbar.o moc_searchbar.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

