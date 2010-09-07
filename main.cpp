#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWin;
    mainWin.show();
    //mainWin.open();
    mainWin.open("/home/markus/Documents/kanjidic2_light.xml");
    return app.exec();
}
