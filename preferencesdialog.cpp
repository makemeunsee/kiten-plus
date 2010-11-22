#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"

PreferencesDialog::PreferencesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);
    connect(ui->resultLimitSlider, SIGNAL(valueChanged(int)), this, SLOT(resultLimitChanged(int)));
    ui->resultLimitSlider->setValue(20);
}

PreferencesDialog::~PreferencesDialog()
{
    delete ui;
}

void PreferencesDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void PreferencesDialog::resultLimitChanged(int i)
{
    QFont font = QFont(ui->resultLimitOut->font());
    QString s;
    if(i != noLimit)
    {
        font.setPointSize(9);
        s = QString::number(i);
    } else
    {
        font.setPointSize(18);
        s = QString::fromUtf8("∞");
    }
    ui->resultLimitOut->setFont(font);
    ui->resultLimitOut->setText(s);
}
