// Version: $Id: 4ebe710f015a91ec5ddb68795b800ce3b04e1a5d $
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

#include <QtWidgets/QFrame>

class dtkComposerViewManagerPrivate;
class dtkComposerViewWidget;

class DTKCOMPOSER_EXPORT dtkComposerViewManager : public QFrame
{
    Q_OBJECT

public:
    dtkComposerViewManager(QWidget *parent = 0);
    ~dtkComposerViewManager(void);

signals:
    void focused(dtkComposerViewWidget *view);

public slots:
    void clear(void);

public slots:
    void onViewFocused(dtkComposerViewWidget *widget);
    void onViewUnfocused(dtkComposerViewWidget *widget);

private:
    dtkComposerViewManagerPrivate *d;
};

//
// dtkComposerViewManager.h ends here
