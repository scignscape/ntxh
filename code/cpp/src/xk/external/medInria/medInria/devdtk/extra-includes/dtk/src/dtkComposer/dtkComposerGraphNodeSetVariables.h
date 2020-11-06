/* @(#)dtkComposerGraphNodeSetVariables.h ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2012 - Nicolas Niclausse, Inria.
 * Created: 2012/02/14 13:55:56
 * Version: $Id: 86cae8c0c4735db3dc47a0cf27ab8e76359ba263 $
 * Last-Updated: Thu Apr 11 10:28:16 2013 (+0200)
 *           By: Thibaud Kloczko
 *     Update #: 35
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
class dtkComposerGraphNodeSetVariablesPrivate;

// /////////////////////////////////////////////////////////////////
// dtkComposerGraphNodeSetVariables
// /////////////////////////////////////////////////////////////////

class dtkComposerGraphNodeSetVariables : public dtkComposerGraphNode
{
public:
    dtkComposerGraphNodeSetVariables(dtkComposerNode *node, const QString& title = "Set Variables");

public:
    dtkComposerGraphNode::Kind kind(void);

public:
    void eval(void);

public:
    dtkComposerNode *wrapee(void);

private:
    dtkComposerGraphNodeSetVariablesPrivate *d;
};


