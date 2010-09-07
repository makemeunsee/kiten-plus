#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQueue>
#include <QSet>

class Kanji;
class KanjidicDB;
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
     void search();
     void searchCode();
     void searchUCS();
     void searchJIS208();
     void searchJIS212();
     void searchJIS213();
     void clearOtherFields();

 private:
     void clearPreviousSearch();
     void showSearchResults(const QSet<Kanji *> &);
     void createActions();
     void createMenus();
     void createWidgets();

     KanjidicDB *kanjidic;

     QMenu *fileMenu;
     QAction *openAct;
     QAction *exitAct;

     QQueue<QWidget *> resultWidgets;
     QVBoxLayout *resultLayout;

     QLabel *unicodeLabel;
     QLineEdit *unicodeField;
     QLabel *jis208Label;
     QLineEdit *jis208Field;
     QLabel *jis212Label;
     QLineEdit *jis212Field;
     QLabel *jis213Label;
     QLineEdit *jis213Field;
     QPushButton *searchCodeButton;

     QLabel *strokeLabel;
     QLineEdit *strokeField;
     QLabel *jlptLabel;
     QLineEdit *jlptField;
     QLabel *gradeLabel;
     QLineEdit *gradeField;
     QLabel *radicalLabel;
     QLineEdit *radicalField;
     QPushButton *searchButton;

 };

#endif // MAINWINDOW_H
