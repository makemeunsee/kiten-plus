#ifndef SEARCHABLELABEL_H
#define SEARCHABLELABEL_H

#include <QLabel>

class SearchableLabel : public QLabel
{
    Q_OBJECT

public:
    SearchableLabel(const QString &s, QWidget *parent=0);

signals:
    void mouseClicked(const QString &s);

protected:
    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
};

#endif // SEARCHABLELABEL_H
