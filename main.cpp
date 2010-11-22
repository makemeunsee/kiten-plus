#include <QApplication>
#include "mainwindow.h"
#include <QProcessEnvironment>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

#ifdef __WIN32
    QString kitenPlusProfile = QProcessEnvironment::systemEnvironment().value("USERPROFILE")+"/.kiten+/";
#else
    QString kitenPlusProfile = QProcessEnvironment::systemEnvironment().value("HOME")+"/.kiten+/";
#endif

    MainWindow mainWin;
    mainWin.show();
    mainWin.setUserResourceDir(kitenPlusProfile);

    return app.exec();
}

//#include "tests/kanjidetailsscrollareatestwindow.h"
//
//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);
//    KanjiDetailsScrollAreaTestWindow mainWin;
//    mainWin.show();
//    return app.exec();
//}
