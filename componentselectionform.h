#ifndef COMPONENTSELECTIONFORM_H
#define COMPONENTSELECTIONFORM_H

#include "partselectionform.h"
#include "checkablelabel.h"

namespace Ui {
    class ComponentSelectionForm;
}

class ComponentSelectionForm : public PartSelectionForm
{
    Q_OBJECT

public:
    explicit ComponentSelectionForm(QPushButton *triggerButton, QWidget *parent = 0);
    virtual ~ComponentSelectionForm();
    virtual void setKanjiDB(const KanjiDB &);
    virtual const QPushButton *searchButton() const;
    virtual const QPushButton *searchAndCloseButton() const;
    virtual QList<QString> selectedComponents() const;
    virtual const QString &getSearchKey() const;

protected:
    virtual void clearSelection();
    virtual void clearLayout();

private:
    Ui::ComponentSelectionForm *ui;

    QMap<unsigned int, QList<CheckableLabel *> *> compButtonsByStrokes;
    FlowLayout *compLayout;
};

#endif // COMPONENTSELECTIONFORM_H
