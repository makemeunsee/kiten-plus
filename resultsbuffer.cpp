#include "resultsbuffer.h"

ResultsBuffer::ResultsBuffer(History &h) : history(h)
{
    currentRequest = 0;
}

const QString *ResultsBuffer::getCurrentRequest() const
{
    return currentRequest;
}

const KanjiSet *ResultsBuffer::getCurrentResults() const
{
    return currentResults;
}

void ResultsBuffer::newRequestAndResult(QString *request, KanjiSet *results)
{
    history.add(*request);

    foreach(QString *s, nextRequests)
        delete s;
    nextRequests.clear();
    foreach(KanjiSet *s, nextResults)
        delete s;
    nextResults.clear();
    if(currentRequest != 0)
    {
        previousRequests.push(currentRequest);
        previousResults.push(currentResults);
    }
    currentRequest = request;
    currentResults = results;
    emit changed();
}

void ResultsBuffer::previous()
{
    nextRequests.push(currentRequest);
    currentRequest = previousRequests.pop();
    nextResults.push(currentResults);
    currentResults = previousResults.pop();
    emit changed();
}

void ResultsBuffer::next()
{
    previousRequests.push(currentRequest);
    currentRequest = nextRequests.pop();
    previousResults.push(currentResults);
    currentResults = nextResults.pop();
    emit changed();
}

bool ResultsBuffer::hasNext() const
{
    return !nextRequests.isEmpty();
}

bool ResultsBuffer::hasPrevious() const
{
    return !previousRequests.isEmpty();
}
