#ifndef SEARCHTHREAD_H
#define SEARCHTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include "../JapaneseDB/kanjidb.h"

class SearchThread : public QThread
{
    Q_OBJECT
public:
    explicit SearchThread(QObject *parent = 0);
    void search(const KanjiDB *, QString *, KanjiSet *);

signals:
    void searchFinished(QString *, KanjiSet *);
    void threadInfo(QString);

public slots:
    void killSearch();

protected:
    void run();

private:
    QMutex mutex;
    const KanjiDB *kanjiDic;
    QString *searchString;
    KanjiSet *resultSet;
};

#endif // SEARCHTHREAD_H
