#ifndef READINGMEANINGGROUPWIDGET_H
#define READINGMEANINGGROUPWIDGET_H

#include <QWidget>
#include <QSet>

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
    void addOnReadings(const QSet<QString> &s);
    void addKunReadings(const QSet<QString> &s);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ReadingMeaningGroupWidget *ui;
};

#endif // READINGMEANINGGROUPWIDGET_H
