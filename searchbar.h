#ifndef SEARCHBAR_H
#define SEARCHBAR_H

#include <QWidget>
#include <QPushButton>
#include <QShortcut>
#include "searchcompleter.h"
#include "history.h"
#include "radicalselectionform.h"

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
    RadicalSelectionForm *radicalSelectionForm();
    void movePopup(QMoveEvent *);

public slots:
    void search();
    void updateBackAndForth();
    void showRadDialog();
    void searchRad();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::SearchBar *ui;
    MainWindow *searchWindow;
    QShortcut *back;
    QShortcut *forth;
    SearchCompleter *completer;
    RadicalSelectionForm *radForm;
    QIcon backIcon, forthIcon;
};

#endif // SEARCHBAR_H
