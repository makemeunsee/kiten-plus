#ifndef RESULTSBUFFER_H
#define RESULTSBUFFER_H

#include <QObject>
#include <QStack>
#include <QSet>
#include <QString>
#include "../JapaneseDB/kanji.h"
#include "history.h"

class ResultsBuffer : public QObject
{
    Q_OBJECT

public:
    ResultsBuffer(History &h);
    const KanjiSet *getCurrentResults() const;
    const QString *getCurrentRequest() const;
    bool hasPrevious();
    bool hasNext();
    void previous();
    void next();
    void newRequestAndResult(QString *, KanjiSet *);

signals:
    void changed();

private:
    History &history;
    KanjiSet *currentResults;
    QString *currentRequest;
    QStack<KanjiSet *> previousResults;
    QStack<KanjiSet *> nextResults;
    QStack<QString *> previousRequests;
    QStack<QString *> nextRequests;
};

#endif // RESULTSBUFFER_H
