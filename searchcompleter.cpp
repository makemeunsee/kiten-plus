#include "searchcompleter.h"

SearchCompleter::SearchCompleter(History &h, QObject *parent) :
    QCompleter(&h.getModel(), parent)
{
}
