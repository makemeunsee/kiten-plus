#include "history.h"
#include <QDateTime>

History::History()
{
}

void History::add(QString &s)
{
    searches.insert(QString(s), QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));
}

void History::read(QFile &f)
{
    QDataStream out(&f);
    out >> *this;
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
