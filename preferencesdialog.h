#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>

namespace Ui {
    class PreferencesDialog;
}

class PreferencesDialog : public QDialog {
    Q_OBJECT
public:
    PreferencesDialog(QWidget *parent = 0);
    ~PreferencesDialog();

    static const int noLimit = 120;

public slots:
    void resultLimitChanged(int);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::PreferencesDialog *ui;
};

#endif // PREFERENCESDIALOG_H
