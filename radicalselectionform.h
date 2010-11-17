#ifndef RADICALSELECTIONFORM_H
#define RADICALSELECTIONFORM_H

#include <QDialog>
#include <QMap>
#include <QPushButton>
#include <QLabel>
#include "flowlayout.h"
#include "../JapaneseDB/kanjidb.h"

namespace Ui {
    class RadicalSelectionForm;
}

class RadicalSelectionForm : public QDialog
{
    Q_OBJECT

public:
    explicit RadicalSelectionForm(QWidget *parent = 0);
    ~RadicalSelectionForm();
    void setKanjiDB(const KanjiDB &kanjiDB);

public slots:
    void sortRadicalsByIndex(bool);

private:
    void clearLayout();

    Ui::RadicalSelectionForm *ui;
    bool kanjiDBSet;
    QFont font;
    FlowLayout *radLayout;
    QMap<unsigned int, QPushButton *> radButtonsById;
    QMap<unsigned int, QList<QPushButton *> *> radButtonsByStrokes;
    QMap<unsigned int, QLabel *> strokeStones;
};

#endif // RADICALSELECTIONFORM_H
