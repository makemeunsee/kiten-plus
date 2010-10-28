#include "searchlineedit.h"
#include <QKeyEvent>
#include <QAbstractItemView>
#include <QScrollBar>

SearchLineEdit::SearchLineEdit(QWidget *parent)
: QLineEdit(parent), keyC(0), historyC(0), historyMode(true), keyMode(false)
{
}

SearchLineEdit::~SearchLineEdit()
{
}

void SearchLineEdit::setKeywordCompleter(SearchCompleter *completer)
{
    keyC = completer;
    if (!keyC)
        return;
    keyC->setWidget(this);
    keyC->setCompletionMode(QCompleter::PopupCompletion);
    connect(keyC, SIGNAL(activated(const QString&)), this, SLOT(insertCompletion(const QString&)));
}

void SearchLineEdit::setHistoryCompleter(QCompleter *completer)
{
    historyC = completer;
    if (!historyC)
        return;
    historyC->setWidget(this);
    historyC->setCompletionMode(QCompleter::PopupCompletion);
    connect(historyC, SIGNAL(activated(const QString&)), this, SLOT(insertCompletion(const QString&)));
}

void SearchLineEdit::insertCompletion(const QString& completion)
{
    setText(completion);
    if(keyMode && !keyC->isCorrect(completion))
    {
        keyC->update(completion);
        keyC->popup()->setCurrentIndex(keyC->completionModel()->index(0, 0));
        keyC->complete();
    }
}

void SearchLineEdit::keyPressEvent(QKeyEvent *e)
{
    if ((historyC && historyC->popup()->isVisible()) || (keyC && keyC->popup()->isVisible())) {
        // The following keys are forwarded by the completer to the widget
        switch (e->key()) {
        case Qt::Key_Enter:
        case Qt::Key_Return:
        case Qt::Key_Escape:
        case Qt::Key_Tab:
        case Qt::Key_Backtab:
            e->ignore();
            return; // let the completer do default behavior
        default:
            break;
        }
    }

    bool isHistoryShortcut = (e->modifiers() == Qt::NoModifier) && (e->key() == Qt::Key_Down); // down
    bool isKeywordShortcut = (e->modifiers() == Qt::NoModifier) && (e->key() == Qt::Key_Up); // up
    bool isNotHandledKey = e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return || e->key() == Qt::Key_Escape;
    if(!isHistoryShortcut && !isKeywordShortcut)
    {
        QLineEdit::keyPressEvent(e);

    }

    QString completionPrefix = text();
    if(!isHistoryShortcut && !isKeywordShortcut && (isNotHandledKey || e->text().isEmpty() || completionPrefix.length() < 1))
    {
        historyC->popup()->hide();
        keyC->popup()->hide();
        return;
    }

    if(isHistoryShortcut && !historyC)
        return;
    if(isKeywordShortcut && !keyC)
        return;
    if(isHistoryShortcut || isKeywordShortcut)
    {
        historyMode = isHistoryShortcut;
        keyMode = isKeywordShortcut;
    }
    if(historyMode)
    {
        keyC->popup()->hide();
        if(completionPrefix != historyC->completionPrefix())
        {
            historyC->setCompletionPrefix(completionPrefix);
            historyC->popup()->setCurrentIndex(historyC->completionModel()->index(0, 0));
        }
        historyC->complete();
    }
    if(keyMode)
    {
        historyC->popup()->hide();
        keyC->update(completionPrefix);
        keyC->popup()->setCurrentIndex(keyC->completionModel()->index(0, 0));
        keyC->complete();
    }
}
