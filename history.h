#ifndef HISTORY_H
#define HISTORY_H

#include <QString>
#include <QMap>
#include <QDataStream>
#include <QFile>
#include <QStringListModel>

class History
{
public:
    explicit History();
    void add(QString &s);
    void read(QFile &);
    void write(QFile &);
    QStringListModel &getModel();

    friend QDataStream &operator <<(QDataStream &stream, const History &);
    friend QDataStream &operator >>(QDataStream &stream, History &);

private:
    void fillModel();
    QMap<QString, QString> searches;
    mutable QStringListModel model;
};

#endif // HISTORY_H
