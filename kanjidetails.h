#ifndef KANJIDETAILS_H
#define KANJIDETAILS_H

#include <QWidget>

class Kanji;
class KanjiDB;
class QString;
class QLabel;

namespace Ui {
    class KanjiDetails;
}

class KanjiDetails : public QWidget {
    Q_OBJECT
public:
    KanjiDetails(QWidget *parent, Kanji *k, KanjiDB *kanjiDB);
    ~KanjiDetails();

protected:
    void changeEvent(QEvent *e);

private:
    void hideWidget(QWidget *w);
    void updateLabel(QLabel *l, QString s);
    Ui::KanjiDetails *ui;
};

#endif // KANJIDETAILS_H
