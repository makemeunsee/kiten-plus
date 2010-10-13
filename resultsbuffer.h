#ifndef RESULTSBUFFER_H
#define RESULTSBUFFER_H

#include <QObject>
#include <QStack>
#include <QSet>

class Kanji;
class QString;

class ResultsBuffer : public QObject
{
    Q_OBJECT

public:
    ResultsBuffer();
    const QSet<Kanji *> &getCurrentResults() const;
    const QString &getCurrentRequest() const;
    bool hasPrevious() const;
    bool hasNext() const;
    void previous();
    void next();
    void newRequestAndResult(QString, QSet<Kanji *>);

signals:
    void changed();

private:
    QSet<Kanji *> currentResults;
    QString currentRequest;
    QStack<QSet<Kanji *> > previousResults;
    QStack<QSet<Kanji *> > nextResults;
    QStack<QString> previousRequests;
    QStack<QString> nextRequests;
};

#endif // RESULTSBUFFER_H
