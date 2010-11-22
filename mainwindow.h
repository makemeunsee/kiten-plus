#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQueue>
#include <QSet>
#include <resultsbuffer.h>
#include "../JapaneseDB/kanjidb.h"
#include "searchthread.h"
#include "history.h"
#include "preferencesdialog.h"

class Kanji;
class SearchBar;
class QLabel;
class QPushButton;
class QLineEdit;
class QVBoxLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    const ResultsBuffer *resultsBuffer() const;
    ResultsBuffer *resultsBuffer();
    void open(const QString &);

public slots:
    void back();
    void forth();
    void search(const QString &);
    void done(QString *, KanjiSet *);
    void popUpInfo(QString);
    void showPrefs();

protected:
    virtual void closeEvent(QCloseEvent *event);
    virtual void moveEvent(QMoveEvent *);

private:
    void clearPreviousSearch();
    void showSearchResults(const QString &, const KanjiSet &);
    void createWidgets();
    void lockGui(bool);

    KanjiDB kanjidic;
    ResultsBuffer *buffer;
    History history;
    QString historyFilename;

    PreferencesDialog *prefDial;
    SearchThread *searchThread;
    SearchBar *searchBar;
    QQueue<QWidget *> resultWidgets;
    QVBoxLayout *resultLayout;

    QIcon icon;

    static const int searchLimit;
};

#endif // MAINWINDOW_H
