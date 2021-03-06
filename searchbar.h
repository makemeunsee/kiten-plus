#ifndef SEARCHBAR_H
#define SEARCHBAR_H

#include <QWidget>
#include <QPushButton>
#include <QShortcut>
#include "searchcompleter.h"
#include "history.h"
#include "radicalselectionform.h"
#include "componentselectionform.h"

namespace Ui {
    class SearchBar;
}

class MainWindow;

class SearchBar : public QWidget {
    Q_OBJECT
public:
    SearchBar(History &h, MainWindow *parent);
    ~SearchBar();
    virtual void setFocus();
    QString text() const;
    void setText(const QString &);
//    const QPushButton *stopButton();
    void lock(bool);
    PartSelectionForm *radicalSelectionForm();
    PartSelectionForm *componentSelectionForm();
    void movePopup(QMoveEvent *);

public slots:
    void search();
    void updateBackAndForth();
    void showRadDialog(bool);
    void searchRad();
    void searchRadAndClose();
    void showCompDialog(bool);
    void searchComp();
    void searchCompAndClose();

protected:
    virtual void changeEvent(QEvent *);
    virtual void keyPressEvent(QKeyEvent *);

private:
    void search(const PartSelectionForm *);
    void searchAndCloseForm(PartSelectionForm *);

    Ui::SearchBar *ui;
    MainWindow *searchWindow;
    QShortcut *back;
    QShortcut *forth;
    SearchCompleter *completer;
    RadicalSelectionForm *radForm;
    ComponentSelectionForm *compForm;
    QIcon backIcon, forthIcon;
};

#endif // SEARCHBAR_H
