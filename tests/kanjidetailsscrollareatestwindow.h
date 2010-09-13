#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

class KanjiDetails;
class QPushButton;
class QVBoxLayout;
class Kanji;
class KanjiDB;

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
    void createKanjis();
    QVBoxLayout *scrollLayout;
    KanjiDB *kanjiDB;
    Kanji *ten;
    Kanji *vrac;
    QPushButton *buttonTen;
    QPushButton *buttonVrac;
    KanjiDetails *kanjiDetails;
};

#endif // MAINWINDOW_H
