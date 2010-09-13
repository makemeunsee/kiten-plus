#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWin;
    mainWin.show();
    mainWin.open("/home/markus/Documents/kanjidic2_light.xml");
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
