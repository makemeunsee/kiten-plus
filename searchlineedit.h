#ifndef SEARCHLINEEDIT_H
#define SEARCHLINEEDIT_H

#include <QLineEdit>
#include "searchcompleter.h"

class SearchLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    SearchLineEdit(QWidget *parent = 0);
    ~SearchLineEdit();

    void setKeywordCompleter(SearchCompleter *c);
    void setHistoryCompleter(QCompleter *c);

public slots:
    void insertCompletion(const QString& completion);

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    SearchCompleter *keyC;
    QCompleter *historyC;
    bool historyMode;
    bool keyMode;
};

#endif // SEARCHLINEEDIT_H
