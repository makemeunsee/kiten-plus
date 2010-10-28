#ifndef SEARCHCOMPLETER_H
#define SEARCHCOMPLETER_H

#include <QCompleter>
#include "history.h"

class SearchCompleter : public QCompleter
{
    Q_OBJECT
public:
    explicit SearchCompleter(History &h, QObject *parent = 0);

signals:

public slots:

};

#endif // SEARCHCOMPLETER_H
