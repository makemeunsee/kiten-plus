#ifndef PARTSELECTIONFORM_H
#define PARTSELECTIONFORM_H

#include <QWidget>
#include "flowlayout.h"
#include "../JapaneseDB/kanjidb.h"
#include <QPushButton>

class PartSelectionForm : public QWidget
{
    Q_OBJECT
public:
    explicit PartSelectionForm(QPushButton *triggerButton, QWidget *parent = 0);
    virtual ~PartSelectionForm();
    virtual void setKanjiDB(const KanjiDB &) = 0;
    virtual const QPushButton *searchButton() const = 0;
    virtual const QPushButton *searchAndCloseButton() const = 0;
    void moveEvent();
    virtual QList<QString> selectedComponents() const = 0;
    virtual const QString &getSearchKey() const = 0;
    QPushButton *getButtonRef();

signals:
    void shown(bool);

protected:
    virtual void moveEvent(QMoveEvent *);
    virtual void showEvent(QShowEvent *);
    virtual void closeEvent(QCloseEvent *);
    virtual void hideEvent(QHideEvent *);
    virtual void keyPressEvent(QKeyEvent *);
    virtual void clearSelection() = 0;
    virtual void clearLayout() = 0;
    virtual void putInPlace();

    bool kanjiDBSet;
    QFont font;
    QFont strokeFont;
    QColor strokeBackground;
    QPalette strokePalette;
    QMap<unsigned int, QWidget *> strokeStones;
    QPushButton *triggerButtonRef;
};

#endif // PARTSELECTIONFORM_H
