// Version: $Id: 99e846727e19d6c4646c0489747211972230394b $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#pragma once

#include <dtkComposerExport.h>

#include <QtCore>
#include <QtWidgets>

class dtkComposerWidget;
class dtkComposerGraphNode;
class dtkComposerEvaluatorToolBarPrivate;

class DTKCOMPOSER_EXPORT dtkComposerEvaluatorToolBar : public QToolBar
{
    Q_OBJECT

public:
             dtkComposerEvaluatorToolBar(const QString& title, QWidget *parent = 0);
             dtkComposerEvaluatorToolBar(QWidget *parent = 0);
    virtual ~dtkComposerEvaluatorToolBar(void);

public slots:
    void onEvaluatorFinished(void);
    void onEvaluatorStarted(void);
    void onEvaluatorPaused(dtkComposerGraphNode *node);

public:
    void setComposerWidget(dtkComposerWidget *composer);

public:
    QMenu *menu(QWidget *parent = 0);

private:
    dtkComposerEvaluatorToolBarPrivate *d;
};

//
// dtkComposerEvaluatorToolBar.h ends here
