/* @(#)dtkComposerNodeSpawn_p.h ---
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

#include <dtkDistributed/dtkDistributedPolicy.h>
#include <dtkDistributed/dtkDistributedCommunicator.h>
#include "dtkComposerEvaluatorProcess.h"


// /////////////////////////////////////////////////////////////////
// dtkComposerNodeSpawnPrivate interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeSpawnPrivate: public dtkComposerNodeRemotePrivate
{

public:
    qlonglong np;
    qlonglong rank;

public:
    QString application;
    bool is_parent;
    bool first_run;

public:
    dtkDistributedPolicy policy;
    dtkComposerEvaluatorProcess p;
    dtkComposerNodeComposite *parent;
    QString composition;

public:
    dtkComposerTransmitterEmitter<dtkDistributedCommunicator *> internal_comm_emitter;
    dtkComposerTransmitterEmitter<qlonglong > rank_emitter;
    dtkComposerTransmitterReceiver<qlonglong > nthreads_receiver;

};
