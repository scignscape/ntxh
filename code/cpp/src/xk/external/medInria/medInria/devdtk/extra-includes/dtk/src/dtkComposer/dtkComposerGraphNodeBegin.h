/* @(#)dtkComposerGraphNodeBegin.h ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2012 - Nicolas Niclausse, Inria.
 * Created: 2012/02/14 13:55:56
 * Version: $Id: db404515b86c4e5a2cc387c92732ad4393f3914f $
 * Last-Updated: Thu Apr 11 10:24:04 2013 (+0200)
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
class dtkComposerGraphNodeBeginPrivate;

// /////////////////////////////////////////////////////////////////
// dtkComposerGraphNodeBegin
// /////////////////////////////////////////////////////////////////

class dtkComposerGraphNodeBegin : public dtkComposerGraphNode
{
public:
    dtkComposerGraphNodeBegin(dtkComposerNode *node, const QString& title = "Begin");

public:
    virtual void eval(void);

public:
    virtual dtkComposerGraphNode::Kind kind(void);

    void setKind(dtkComposerGraphNode::Kind);

public:
    dtkComposerNode *wrapee(void);

public:
    virtual dtkComposerGraphNodeList successors(void);
    dtkComposerGraphNodeList evaluableChilds(void);

public:
    dtkComposerGraphNode *end(void);
    void setEnd(dtkComposerGraphNode *end);

private:
    dtkComposerGraphNodeBeginPrivate *d;
};

