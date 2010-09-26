#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQueue>
#include <QSet>

class Kanji;
class KanjiDB;
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

public slots:
    void open();
    void open(const QString &);
    void search(const QString &);

private:
    void clearPreviousSearch();
    void showSearchResults(const QSet<Kanji *> &);
    void createActions();
    void createMenus();
    void createWidgets();

    KanjiDB *kanjidic;

    QMenu *fileMenu;
    QAction *openAct;
    QAction *exitAct;

    SearchBar *searchBar;
    QQueue<QWidget *> resultWidgets;
    QVBoxLayout *resultLayout;
 };

#endif // MAINWINDOW_H
