#ifndef RADICALSELECTIONFORM_H
#define RADICALSELECTIONFORM_H

#include <QWidget>
#include <QMap>
#include <QPushButton>
#include <QLabel>
#include "flowlayout.h"
#include "../JapaneseDB/kanjidb.h"
#include "checkablelabel.h"

namespace Ui {
    class RadicalSelectionForm;
}

class RadicalSelectionForm : public QWidget
{
    Q_OBJECT

public:
    explicit RadicalSelectionForm(QWidget *radButton, QWidget *parent = 0);
    ~RadicalSelectionForm();
    void setKanjiDB(const KanjiDB &kanjiDB);
    const QPushButton *searchButton() const;
    void moveEvent();
    QList<QString> selectedComponents() const;

public slots:
    void sortRadicalsByIndex(bool);
    void limitToRad(bool);
    void checkedSlot(bool, const QString &);

protected:
    virtual void moveEvent(QMoveEvent *);
    virtual void showEvent(QShowEvent *);
    virtual void closeEvent(QCloseEvent *);

private:
    void clearLayout();
    void putInPlace();

    Ui::RadicalSelectionForm *ui;
    bool kanjiDBSet;
    QFont font;
    QFont strokeFont;
    QColor strokeBackground;
    QPalette strokePalette;
    FlowLayout *radLayout;
    QMap<unsigned int, CheckableLabel *> radButtonsById;
    QMap<unsigned int, QList<CheckableLabel *> *> radButtonsByStrokes;
    QMap<unsigned int, QWidget *> strokeStones;

    QWidget *radButtonRef;
};

#endif // RADICALSELECTIONFORM_H
