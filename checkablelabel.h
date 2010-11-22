#ifndef CHECKABLELABEL_H
#define CHECKABLELABEL_H

#include <QLabel>
#include <QMouseEvent>

class CheckableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit CheckableLabel(const QString &text, QWidget *parent = 0, Qt::WindowFlags f = 0);
    bool isChecked();
    void setChecked(bool);

protected:
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    virtual void mouseMoveEvent(QMouseEvent *ev);

signals:
    void checkedSignal(bool);

public slots:

private:
    void toggle();
    bool clickingOnMe;
    bool checked;
    QPalette palette;
    QColor checkedColor;
    QColor uncheckedColor;

};

#endif // CHECKABLELABEL_H
