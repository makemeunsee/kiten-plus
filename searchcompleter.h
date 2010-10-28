#ifndef SEARCHCOMPLETER_H
#define SEARCHCOMPLETER_H

#include <QCompleter>
#include <QStringListModel>
#include <QRegExp>

class SearchCompleter : public QCompleter
{
    Q_OBJECT
public:
    explicit SearchCompleter(QObject *parent = 0);
    void update(const QString &text);
    bool isCorrect(const QString &text);

signals:

public slots:

private:
    QStringListModel model;
    QRegExp completionRegexp;
};

#endif // SEARCHCOMPLETER_H
