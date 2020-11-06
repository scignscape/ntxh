/* dtkComposerGraphNodeBeginForEach.h ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2012 - Nicolas Niclausse, Inria.
 * Created: 2012/02/14 13:55:56
 */


#pragma once

#include "dtkComposerGraphNodeBegin.h"

class dtkComposerNode;
class dtkComposerGraphNodeBeginForEachPrivate;

// /////////////////////////////////////////////////////////////////
// dtkComposerGraphNodeBeginForEach
// /////////////////////////////////////////////////////////////////

class dtkComposerGraphNodeBeginForEach : public dtkComposerGraphNodeBegin
{
public:
    dtkComposerGraphNodeBeginForEach(dtkComposerNode *node, const QString& title = "Begin");

public:
    virtual QTime startTime(void);

public:
    void eval(void);

public:
    dtkComposerGraphNodeList successors(void);

private:
    dtkComposerGraphNodeBeginForEachPrivate *d;
};


