#include "history.h"
#include <QDateTime>

History::History()
{
}

void History::fillModel()
{
    model.insertRows(0, searches.keys().size());
    int i = 0;
    foreach(QString s, searches.keys())
        model.setData(model.index(i++), s);
}

QStringListModel &History::getModel()
{
    return model;
}

void History::add(QString &s)
{
    QString copy(s);
    if(!searches.contains(copy))
    {
        model.insertRow(0);
        model.setData(model.index(0), s);
    }
    searches.insert(copy, QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));
}

void History::read(QFile &f)
{
    QDataStream out(&f);
    out >> *this;
    fillModel();
}

void History::write(QFile &f)
{
    QDataStream in(&f);
    in << *this;
}

QDataStream &operator <<(QDataStream &stream, const History &h)
{
    stream << h.searches;
    return stream;
}

QDataStream &operator >>(QDataStream &stream, History &h)
{
    stream >> h.searches;
    return stream;
}
