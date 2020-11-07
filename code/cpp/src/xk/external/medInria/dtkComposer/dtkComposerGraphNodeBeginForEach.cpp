/* @(#)dtkComposerGraphNodeBeginForEach.cpp ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2012 - Nicolas Niclausse, Inria.
 * Created: 2012/02/14 13:59:57
 * Version: $Id: 16cf6710ea40fec6a64c9a52a48b17c8044c4d46 $
 * Last-Updated: mar. févr.  5 18:11:18 2013 (+0100)
 *           By: Nicolas Niclausse
 *     Update #: 445
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include <dtkConfig.h>

#include "dtkComposerEvaluator.h"
#include "dtkComposerGraph.h"
#include "dtkComposerGraphNodeBeginForEach.h"
#include "dtkComposerGraphNode.h"
#include "dtkComposerNode.h"
#include "dtkComposerNodeControl.h"
#include "dtkComposerNodeControlForEach.h"

#include <dtkLog/dtkLog.h>

class dtkComposerGraphNodeBeginForEachPrivate
{
public:
    dtkComposerNodeControl *control_node;

public:
    QTime time;

};


dtkComposerGraphNodeBeginForEach::dtkComposerGraphNodeBeginForEach(dtkComposerNode *cnode, const QString& title) : dtkComposerGraphNodeBegin(cnode, title),d(new dtkComposerGraphNodeBeginForEachPrivate)
{

    d->control_node = dynamic_cast<dtkComposerNodeControl *>(cnode);

    this->setTitle(title);
}

QTime dtkComposerGraphNodeBeginForEach::startTime(void)
{
    return d->time;
}

void dtkComposerGraphNodeBeginForEach::eval(void)
{
    // d->time.start();
    d->control_node->begin();

    dtkComposerEvaluator evaluator ;

    evaluator.setGraph(dtkComposerGraphNode::graph());
    evaluator.setStartNode(dtkComposerGraphNode::successors().first());
    evaluator.setEndNode(dtkComposerGraphNodeBegin::end());
    evaluator.setNotify(false);
    this->setStatus(dtkComposerGraphNode::Done);

    d->control_node->setInputs();
    qlonglong size = dynamic_cast<dtkComposerNodeControlForEach *>(d->control_node)->size();
    for (qlonglong i = 0; i < size ; ++i) {
        d->control_node->setVariables();
        evaluator.run(false);
        d->control_node->setOutputs();
    }

}

dtkComposerGraphNodeList dtkComposerGraphNodeBeginForEach::successors(void)
{
    dtkComposerGraphNodeList list;
    list << dtkComposerGraphNodeBegin::end();
    return list;
//    return dtkComposerGraphNode::successors();
}
