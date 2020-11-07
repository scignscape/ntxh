/* @(#)dtkComposerControlsListItemString.h ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2013 - Nicolas Niclausse, Inria.
 * Created: 2013/06/03 12:33:16
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#pragma once

#include "dtkComposerControlsListItem.h"

class dtkComposerSceneNode;
class dtkComposerControlsListItemStringPrivate;

class dtkComposerControlsListItemString: public dtkComposerControlsListItem
{
    Q_OBJECT

public:
    dtkComposerControlsListItemString(QWidget *parent = 0, dtkComposerSceneNode *node = NULL);
    virtual ~dtkComposerControlsListItemString(void);

public slots:
    void onValueChanged(QString value);

private:
    dtkComposerControlsListItemStringPrivate *d;
};




