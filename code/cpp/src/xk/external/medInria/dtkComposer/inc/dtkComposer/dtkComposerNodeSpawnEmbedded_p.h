/* @(#)dtkComposerNodeSpawnEmbedded_p.h ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2013 - Nicolas Niclausse, Inria.
 * Created: 2013/10/07 10:28:23
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#pragma once

#include "dtkComposerNodeRemote_p.h"
#include <dtkMeta/dtkMetaContainerSequential.h>

#include <dtkDistributed/dtkDistributedCommunicator.h>
#include <dtkDistributed/dtkDistributedPolicy.h>
#include "dtkComposerEvaluatorProcess.h"

class dtkComposerNodeControl;

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeSpawnEmbeddedPrivate interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeSpawnEmbeddedPrivate: public dtkComposerNodeRemotePrivate
{

public:
    qlonglong np;
    qlonglong rank;
    qlonglong index;

public:
    QString application;
    bool is_parent;
    bool first_run;

public:
    dtkDistributedPolicy policy;
    dtkComposerEvaluatorProcess p;
    dtkComposerNodeComposite *parent;
    dtkComposerNodeControl *control;
    QString composition;
    dtkMetaContainerSequential *container;
    dtkMetaContainerSequential *out_container;
    QVariant var_container;
    QVariant out_variant;

public:
    dtkComposerTransmitterEmitter<dtkDistributedCommunicator *> internal_comm_emitter;
    dtkComposerTransmitterEmitter<qlonglong > rank_emitter;
    dtkComposerTransmitterReceiver<qlonglong > nthreads_receiver;

public:
    dtkComposerTransmitterEmitterVariant     container_emitter;
    dtkComposerTransmitterEmitter<qlonglong> size_emitter;
    dtkComposerTransmitterEmitter<qlonglong> index_emitter;
    dtkComposerTransmitterEmitterVariant     item_emitter;
    dtkComposerTransmitterReceiverVariant    newitem_emitter;

};
