#include <QApplication>
#include "mainwindow.h"
#include <QProcessEnvironment>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QDir dir = QDir::currentPath();
    QString kanjidic2Path = dir.path() + "/kanjidic2.xml";
    if(!QFile(kanjidic2Path).exists())
    {
#ifdef __WIN32
        QString userProfile = QProcessEnvironment::systemEnvironment().value("USERPROFILE");
#else
        QString userProfile = QProcessEnvironment::systemEnvironment().value("HOME");
#endif
        kanjidic2Path = userProfile+"/.kiten+/kanjidic2.xml";
    }
    MainWindow mainWin;
    mainWin.show();
    mainWin.open(kanjidic2Path);
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
