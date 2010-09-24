#ifndef KANJIDETAILS_H
#define KANJIDETAILS_H

#include <QWidget>

class Kanji;
class KanjiDB;
class MainWindow;
class QString;
class QLabel;

namespace Ui {
    class KanjiDetails;
}

class KanjiDetails : public QWidget {
    Q_OBJECT
public:
    KanjiDetails(MainWindow *parent, Kanji *k, KanjiDB *kanjiDB);
    ~KanjiDetails();

public slots:
    void search(const QString &);

protected:
    void changeEvent(QEvent *e);

private:
    void hideWidget(QWidget *w);
    void updateLabel(QLabel *l, QString s);
    Ui::KanjiDetails *ui;
    MainWindow *searchWindow;
};

#endif // KANJIDETAILS_H
