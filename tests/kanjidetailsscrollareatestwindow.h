#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "../../JapaneseDB/kanjidb.h"

class KanjiDetails;
class QPushButton;
class QVBoxLayout;

class KanjiDetailsScrollAreaTestWindow : public QMainWindow
{
    Q_OBJECT

public:
    KanjiDetailsScrollAreaTestWindow(QWidget *parent = 0);
    ~KanjiDetailsScrollAreaTestWindow();

public slots:
    void setTen();
    void setVrac();

private:
    void setKanji(Kanji *k);
    void createKanjis();
    QWidget *scrollWidget;
    QVBoxLayout *scrollLayout;
    KanjiDB kanjiDB;
    Kanji *ten;
    Kanji *vrac;
    QPushButton *buttonTen;
    QPushButton *buttonVrac;
    KanjiDetails *kanjiDetails;
};

#endif // MAINWINDOW_H
