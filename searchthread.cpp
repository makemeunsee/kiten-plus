#include "searchthread.h"

SearchThread::SearchThread(QObject *parent) :
    QThread(parent)
{
}

void SearchThread::search(const KanjiDB *dic, const QString *s, KanjiSet *results)
{
    QMutexLocker locker(&mutex);

    kanjiDic = dic;
    searchString = s;
    resultSet = results;

    if (!isRunning())
        start(LowPriority);
    else
        emit threadInfo(QString("thread already started"));

}

void SearchThread::killSearch()
{
    if(isRunning())
    {
        emit threadInfo(QString("thread killed"));
        terminate();
        wait();
        resultSet->clear();
        emit searchFinished(*searchString, resultSet);
    }
}

void SearchThread::run()
{
    kanjiDic->search(*searchString, *resultSet);
    emit searchFinished(*searchString, resultSet);
}
