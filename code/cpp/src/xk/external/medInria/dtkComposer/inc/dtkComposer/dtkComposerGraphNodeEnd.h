/* @(#)dtkComposerGraphNodeEnd.h ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2012 - Nicolas Niclausse, Inria.
 * Created: 2012/02/14 13:55:56
 * Version: $Id: 79798a88714bc14ec737aeccef48fbc2ebbb7ad2 $
 * Last-Updated: Thu Apr 11 10:25:20 2013 (+0200)
 *           By: Thibaud Kloczko
 *     Update #: 41
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#pragma once

#include "dtkComposerGraphNode.h"

class dtkComposerNode;
class dtkComposerGraphNodeBegin;
class dtkComposerGraphNodeEndPrivate;

// /////////////////////////////////////////////////////////////////
// dtkComposerGraphNodeEnd
// /////////////////////////////////////////////////////////////////

class dtkComposerGraphNodeEnd : public dtkComposerGraphNode
{
public:
    dtkComposerGraphNodeEnd(dtkComposerNode *node, const QString& title = "End");

public:
    dtkComposerGraphNode::Kind kind(void);

public:
    void eval(void);

public:
    dtkComposerNode *wrapee(void);

public:
    dtkComposerGraphNodeList predecessors(void);

public:
    void setBegin(dtkComposerGraphNodeBegin *begin);

private:
    dtkComposerGraphNodeEndPrivate *d;
};


