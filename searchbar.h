#ifndef SEARCHBAR_H
#define SEARCHBAR_H

#include <QWidget>
#include <QPushButton>
#include <QShortcut>
#include "searchcompleter.h"
#include "history.h"

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

public slots:
    void search();
    void updateBackAndForth();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::SearchBar *ui;
    MainWindow *searchWindow;
    QShortcut *back;
    QShortcut *forth;
    SearchCompleter *completer;
    QIcon backIcon, forthIcon;
};

#endif // SEARCHBAR_H
