#include "resultsbuffer.h"

ResultsBuffer::ResultsBuffer()
{
}

const QString &ResultsBuffer::getCurrentRequest() const
{
    return currentRequest;
}

const KanjiSet &ResultsBuffer::getCurrentResults() const
{
    return currentResults;
}

void ResultsBuffer::newRequestAndResult(QString request, KanjiSet results)
{
    nextRequests.clear();
    nextResults.clear();
    if(!currentRequest.isNull())
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

bool ResultsBuffer::hasNext()
{
    return !nextRequests.isEmpty();
}

bool ResultsBuffer::hasPrevious()
{
    return !previousRequests.isEmpty();
}
