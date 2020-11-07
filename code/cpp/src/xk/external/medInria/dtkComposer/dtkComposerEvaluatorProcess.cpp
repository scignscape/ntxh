/* dtkComposerEvaluatorProcess.cpp ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2012 - Nicolas Niclausse, Inria.
 * Created: 2013/10/07 10:25:39
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "dtkComposerEvaluatorProcess.h"

#include "dtkComposer.h"
#include "dtkComposerEvaluator.h"
#include "dtkComposerGraph.h"
#include "dtkComposerGraphNode.h"
#include "dtkComposerNodeFactory.h"
#include "dtkComposerReaderNoScene.h"
#include "dtkComposerNodeSpawn.h"
#include "dtkComposerNodeSpawnEmbedded.h"

#include <dtkMeta/dtkMetaContainerSequential.h>

#include <dtkDistributed/dtkDistributedCommunicator.h>
#include <dtkDistributed/dtkDistributedMapper.h>

#include <dtkLog/dtkLog.h>

class dtkComposerEvaluatorProcessPrivate
{
public:
    dtkDistributedCommunicator *comm;
    dtkMetaContainerSequential *container;
    QVariant out_var_container;
    QVariant var_container;

public:
    QString application;

public:
    int status;

public:
    dtkComposerNodeFactory   *factory;
    QString     composition;
    dtkComposerNodeComposite  *parent;
};

dtkComposerEvaluatorProcess::dtkComposerEvaluatorProcess(void) : QRunnable(), d(new dtkComposerEvaluatorProcessPrivate)
{
    d->factory   = &(dtkComposer::node::factory());

    d->status    = 0;
    d->container = NULL;

}

dtkComposerEvaluatorProcess::~dtkComposerEvaluatorProcess(void)
{
    delete d;

    d = NULL;
}

void dtkComposerEvaluatorProcess::setApplication(QString application)
{
    d->application = application;
}

void dtkComposerEvaluatorProcess::setComposition(QString composition)
{
    d->composition = composition;
}

void dtkComposerEvaluatorProcess::setCommunicator(dtkDistributedCommunicator *communicator)
{
    d->comm = communicator;
}

void dtkComposerEvaluatorProcess::setContainer(QVariant var_container)
{
    d->var_container = var_container;
    //FIXME : is it efficient ?
    d->container = new dtkMetaContainerSequential(var_container.value<dtkMetaContainerSequential>());
}

void dtkComposerEvaluatorProcess::setOutputContainer(QVariant container)
{
    d->out_var_container = container;
}

void dtkComposerEvaluatorProcess::setParent(dtkComposerNodeComposite *parent)
{
    d->parent = parent;
}

int dtkComposerEvaluatorProcess::exec(void)
{
    run();
    return d->status;
}

void dtkComposerEvaluatorProcess::run(void)
{

    d->status = 0;

    if (!d->factory) {
        dtkFatal() << "No factory set ! abort process execution";
        d->status = 1;
        return;
    }

    bool new_composition;

    if (d->composition == "not-modified") {
        dtkInfo() << "composition hasn't changed";
        new_composition = false;
    } else {
        new_composition = true;
    }

    if (new_composition && d->composition.isEmpty()) {
        dtkFatal() << "Empty composition, abort" ;
        d->status = 1;
        return;
    }

    // FIXME: cache the previous graph.
    // if (new_composition) {
    //     dtkDebug() << "parse composition" ;

    // }
    dtkComposerGraph     graph;
    dtkComposerReaderNoScene  reader;
    dtkComposerEvaluator evaluator;
    evaluator.setGraph(&graph);
    evaluator.setNotify(false);
    evaluator.setMessageLog(false);

    reader.setGraph(&graph);
    reader.setFactory(d->factory);
    reader.readString(d->composition);
    // We have to get the Spawn node, ie. the only successor of the root node.
    dtkComposerNode *first_node = graph.root()->successors().first()->wrapee();

    dtkComposerNodeSpawn *spawn_node;
    dtkComposerNodeSpawnEmbedded *embedded_spawn_node = dynamic_cast<dtkComposerNodeSpawnEmbedded *>(first_node);

    if (!embedded_spawn_node) {
        dtkDebug() << "Not en embedded spawn, try to cast as a spawn";
        spawn_node = dynamic_cast<dtkComposerNodeSpawn *>(first_node);
        if (!spawn_node) {
            dtkFatal() << "First node of spawned node should be a dtkComposerNodeSpawn node" << first_node;
        }
    }

    if (embedded_spawn_node) {
        embedded_spawn_node->setContainer(d->var_container);
        embedded_spawn_node->setOutputContainer(d->out_var_container);
        embedded_spawn_node->setParentNode(d->parent);
        embedded_spawn_node->setCommunicator(d->comm);
    } else {
        spawn_node->setParentNode(d->parent);
        spawn_node->setCommunicator(d->comm);
    }

    dtkDebug() << "run composition on rank" << d->comm->rank() ;
    if (!embedded_spawn_node) {
        evaluator.run();
    } else {
        dtkDistributedMapper mapper;
        mapper.setMapping(d->container->size(), d->comm->size());
        qlonglong first = mapper.firstIndex(d->comm->rank());
        qlonglong last = mapper.lastIndex(d->comm->rank());
        qDebug() << "mapper:" <<first << last <<d->comm->rank();
        for (qlonglong i = first; i <= last; i++) {
            embedded_spawn_node->setContainerIndex(i);
            evaluator.run();
        }
    }
    dtkDebug() << "finished on rank "<< d->comm->rank() ;
}
