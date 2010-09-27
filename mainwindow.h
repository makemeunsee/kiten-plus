#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQueue>
#include <QSet>
#include <resultsbuffer.h>
#include <../JapaneseDB/kanjidb.h>

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

public slots:
    void back();
    void forth();
    void open();
    void open(const QString &);
    void search(const QString &);

private:
    void clearPreviousSearch();
    void showSearchResults(const QString &, const QSet<Kanji *> &);
    void createWidgets();

    KanjiDB kanjidic;
    ResultsBuffer *buffer;

    SearchBar *searchBar;
    QQueue<QWidget *> resultWidgets;
    QVBoxLayout *resultLayout;
 };

#endif // MAINWINDOW_H
