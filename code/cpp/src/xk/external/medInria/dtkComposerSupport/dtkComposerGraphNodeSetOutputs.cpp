/* @(#)dtkComposerGraphNodeSetOutputs.cpp ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2012 - Nicolas Niclausse, Inria.
 * Created: 2012/02/14 13:59:57
 * Version: $Id: 73cbd245254fe5ad9e09ab76c66dc3326a873000 $
 * Last-Updated: ven. mars  2 18:44:37 2012 (+0100)
 *           By: Nicolas Niclausse
 *     Update #: 53
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */


#include "dtkComposerGraphNodeSetOutputs.h"
#include "dtkComposerNode.h"
#include "dtkComposerNodeControl.h"

class dtkComposerGraphNodeSetOutputsPrivate
{
public:
    dtkComposerNodeControl *composer_node;

};


dtkComposerGraphNodeSetOutputs::dtkComposerGraphNodeSetOutputs(dtkComposerNode *cnode, const QString& title) : dtkComposerGraphNode(), d(new dtkComposerGraphNodeSetOutputsPrivate)
{
    d->composer_node = dynamic_cast<dtkComposerNodeControl *>(cnode);
    this->setTitle(title);
}


dtkComposerGraphNode::Kind dtkComposerGraphNodeSetOutputs::kind(void)
{
    return dtkComposerGraphNode::SetOutputs;
}

dtkComposerNode *dtkComposerGraphNodeSetOutputs::wrapee(void)
{
    return d->composer_node;
}

void dtkComposerGraphNodeSetOutputs::eval(void)
{
    if (d->composer_node == NULL)
        return;

    d->composer_node->setOutputs();
    this->setStatus(dtkComposerGraphNode::Done);
}


