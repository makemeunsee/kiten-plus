#include "searchablelabel.h"
#include <QMouseEvent>

SearchableLabel::SearchableLabel(QWidget *parent) : QLabel(parent)
{
}

SearchableLabel::SearchableLabel(const QString &s, QWidget *parent) : QLabel(s, parent)
{
}

void SearchableLabel::enterEvent(QEvent *)
{
    setForegroundRole(QPalette::Link);
}

void SearchableLabel::leaveEvent(QEvent *)
{
    setForegroundRole(QPalette::Text);
}

void SearchableLabel::mouseReleaseEvent(QMouseEvent *e)
{
    if(contentsRect().contains(e->pos()))
        emit mouseClicked(text());
}
