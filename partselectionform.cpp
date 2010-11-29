#include "partselectionform.h"
#include <QApplication>
#include <QKeyEvent>
#include <QCloseEvent>

PartSelectionForm::PartSelectionForm(QPushButton *triggerButton, QWidget *parent) :
    QWidget(parent),
    kanjiDBSet(false),
    triggerButtonRef(triggerButton),
    clickingOnMe(false)
{
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    setMouseTracking(true);
    font.setPointSize(12);
    strokeFont.setPointSize(9);
    strokeFont.setBold(true);
    strokeBackground.setRgb(180, 180, 180);
    strokePalette = QApplication::palette();
    strokePalette.setCurrentColorGroup(QPalette::Active);
    strokePalette.setColor(QPalette::Window, strokeBackground);
}

PartSelectionForm::~PartSelectionForm()
{
    foreach(QWidget *stone, strokeStones.values())
        delete stone;
    strokeStones.clear();
}

void PartSelectionForm::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape && isVisible())
        hide();
    else
        QWidget::keyPressEvent(e);
}

void PartSelectionForm::closeEvent(QCloseEvent *e)
{
    e->ignore();
}

void PartSelectionForm::moveEvent()
{
    putInPlace();
}

void PartSelectionForm::moveEvent(QMoveEvent *)
{
    putInPlace();
}

void PartSelectionForm::showEvent(QShowEvent *)
{
    emit shown(true);
    putInPlace();
}

void PartSelectionForm::hideEvent(QHideEvent *)
{
    emit shown(false);
    clearSelection();
}

void PartSelectionForm::putInPlace()
{
    QPoint p = triggerButtonRef->mapToGlobal(QPoint(0, triggerButtonRef->height()));
    setGeometry(p.x(), p.y(), width(), height());
}

QPushButton *PartSelectionForm::getButtonRef()
{
    return triggerButtonRef;
}

void PartSelectionForm::mouseMoveEvent(QMouseEvent *ev)
{
    if(clickingOnMe)
    {
        resize(width() + ev->pos().x() - lastPoint.x(), height() + ev->y() - lastPoint.y());
        lastPoint = ev->pos();
    } else
        if(bottomRightCorner().contains(ev->pos()))
            setCursor(Qt::SizeFDiagCursor);
        else
            setCursor(Qt::ArrowCursor);
}

void PartSelectionForm::mousePressEvent(QMouseEvent *ev)
{
    if(bottomRightCorner().contains(ev->pos()))
    {
        grabMouse();
        clickingOnMe = true;
        lastPoint = ev->pos();
        ev->accept();
    } else
    {
        releaseMouse();
        clickingOnMe = false;
    }
}

void PartSelectionForm::mouseReleaseEvent(QMouseEvent *ev)
{
    if(clickingOnMe)
        ev->accept();
    clickingOnMe = false;
}

QRect PartSelectionForm::bottomRightCorner()
{
    return QRect(QPoint(width()-8, height()-8), QSize(8 ,8));
}
