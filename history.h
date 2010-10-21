#ifndef HISTORY_H
#define HISTORY_H

#include <QString>
#include <QMap>
#include <QDataStream>
#include <QFile>

class History
{
public:
    History();
    void add(QString &s);
    void read(QFile &);
    void write(QFile &);

    friend QDataStream &operator <<(QDataStream &stream, const History &);
    friend QDataStream &operator >>(QDataStream &stream, History &);

private:
    QMap<QString, QString> searches;
};

#endif // HISTORY_H
