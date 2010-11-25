#include "searchcompleter.h"
#include "../JapaneseDB/kanjidb.h"

SearchCompleter::SearchCompleter(QObject *parent) :
        QCompleter(parent), model(), completionRegexp(KanjiDB::searchRegexp)
{
    setModel(&model);
    completionRegexp.setPattern(completionRegexp.pattern()+KanjiDB::seps);
}

void SearchCompleter::update(const QString &text)
{
    model.removeRows(0, model.rowCount());
    if(text.isEmpty() || completionRegexp.exactMatch(text))
    {
        model.insertRows(0, KanjiDB::keyCount);
        for(int i = 0; i < KanjiDB::keyCount; ++i)
            model.setData(model.index(i), text+KanjiDB::allKeys[i]);
    } else {
        int lastId = text.lastIndexOf(QRegExp(KanjiDB::seps));
        QString right = text.mid(lastId+1);
        int j = 0;
        for(int i = 0; i < KanjiDB::keyCount; ++i)
            if(QRegExp(KanjiDB::allKeys[i]+"[a-zA-Z0-9\\-]+").exactMatch(right))
            {
                model.insertRows(j, 3);
                model.setData(model.index(j++), text);
                model.setData(model.index(j++), text+"&");
                model.setData(model.index(j++), text+",");
            } else if(QRegExp(right).indexIn(KanjiDB::allKeys[i]) == 0)
            {
                model.insertRow(j);
                model.setData(model.index(j++), text.left(lastId+1)+KanjiDB::allKeys[i]);
            }
    }
    setCompletionPrefix(text);
}

bool SearchCompleter::isCorrect(const QString &text)
{
    return KanjiDB::searchRegexp.exactMatch(text);
}
