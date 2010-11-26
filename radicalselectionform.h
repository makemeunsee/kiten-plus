#ifndef RADICALSELECTIONFORM_H
#define RADICALSELECTIONFORM_H

#include "partselectionform.h"
#include "checkablelabel.h"

namespace Ui {
    class RadicalSelectionForm;
}

class RadicalSelectionForm : public PartSelectionForm
{
    Q_OBJECT

public:
    explicit RadicalSelectionForm(QPushButton *triggerButton, QWidget *parent = 0);
    virtual ~RadicalSelectionForm();
    virtual void setKanjiDB(const KanjiDB &);
    virtual const QPushButton *searchButton() const;
    virtual const QPushButton *searchAndCloseButton() const;
    virtual QList<QString> selectedComponents() const;
    virtual const QString &getSearchKey() const;

public slots:
    void sortRadicalsByIndex(bool);
    void limitToRad(bool);

protected:
    virtual void clearSelection();
    virtual void clearLayout();

private:
    Ui::RadicalSelectionForm *ui;
    QMap<unsigned int, CheckableLabel *> radButtonsById;
    QMap<unsigned int, QList<CheckableLabel *> *> radButtonsByStrokes;
    FlowLayout *radLayout;
};

#endif // RADICALSELECTIONFORM_H
