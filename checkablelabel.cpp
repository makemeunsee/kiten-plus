#include "checkablelabel.h"
#include <QApplication>

CheckableLabel::CheckableLabel(const QString &text, QWidget *parent, Qt::WindowFlags f) :
        QLabel(text, parent, f), clickingOnMe(false), checked(false)
{
    palette = QApplication::palette();
    checkedColor.setRgb(255, 160, 160);
    uncheckedColor = palette.color(QPalette::Window);
    setMouseTracking(true);
    setAutoFillBackground(true);
    palette.setCurrentColorGroup(QPalette::Active);
}

void CheckableLabel::mouseMoveEvent(QMouseEvent *ev)
{
    if(clickingOnMe && !rect().contains(ev->pos()))
        clickingOnMe = false;
}

void CheckableLabel::mousePressEvent(QMouseEvent *)
{
    clickingOnMe = true;
}

void CheckableLabel::mouseReleaseEvent(QMouseEvent *)
{
    if(clickingOnMe)
    {
        clickingOnMe = false;
        toggle();
    }
}

void CheckableLabel::toggle()
{
    checked = !checked;
    if(checked)
        palette.setColor(QPalette::Window, checkedColor);
    else
        palette.setColor(QPalette::Window, uncheckedColor);
    setPalette(palette);
    emit checkedSignal(checked);
}

bool CheckableLabel::isChecked()
{
    return checked;
}

void CheckableLabel::setChecked(bool b)
{
    if(b != checked)
        toggle();
}

void CheckableLabel::setIconTooltip(const QString &s)
{
    //TODO
}
