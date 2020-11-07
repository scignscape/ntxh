// Version: $Id: 5fffcb5b310bd3308e285411ac51711e13dc0641 $
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
#include "dtkComposerViewWidget.h"

#include <QtCore>

class dtkComposerSceneNode;

class DTKCOMPOSER_EXPORT dtkComposerViewController : public QObject
{
    Q_OBJECT

public:
    static dtkComposerViewController *instance(void);

public:
    void insert(dtkComposerSceneNode *);

public:
    dtkComposerViewWidget *view(const QString& name);
    QStringList viewNames(void);

signals:
    void inserted(dtkComposerViewWidget *, const QString&);

protected:
    dtkComposerViewController(void);
    ~dtkComposerViewController(void);

private:
    static dtkComposerViewController *s_instance;

private:
    class dtkComposerViewControllerPrivate *d;
};

//
// dtkComposerViewController.h ends here
