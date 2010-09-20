#ifndef READINGMEANINGGROUPWIDGET_H
#define READINGMEANINGGROUPWIDGET_H

#include <QWidget>

namespace Ui {
    class ReadingMeaningGroupWidget;
}

class ReadingMeaningGroupWidget : public QWidget {
    Q_OBJECT
public:
    ReadingMeaningGroupWidget(QWidget *parent = 0);
    ~ReadingMeaningGroupWidget();
    void addEnglishMeaning(QString &s);
    void addFrenchMeaning(QString &s);
    void addOnReading(QString &s);
    void addKunReading(QString &s);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ReadingMeaningGroupWidget *ui;
};

#endif // READINGMEANINGGROUPWIDGET_H
