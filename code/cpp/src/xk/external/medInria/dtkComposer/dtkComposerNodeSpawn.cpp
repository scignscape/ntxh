// Version: $Id: 9a72326dbd83ae56feb6029909c8e1983793db13 $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include "dtkComposerNodeSpawn.h"
#include "dtkComposerNodeSpawn_p.h"

#include "dtkComposerTransmitter.h"
#include "dtkComposerEvaluatorProcess.h"

#include "dtkComposerTransmitterEmitter.h"
#include "dtkComposerTransmitterReceiver.h"
#include "dtkComposerTransmitterProxyVariant.h"

#include <dtkDistributed/dtkDistributed.h>

#include <dtkLog>

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeSpawn implementation
// /////////////////////////////////////////////////////////////////

dtkComposerNodeSpawn::dtkComposerNodeSpawn(void) : dtkComposerNodeRemote(),  d(new dtkComposerNodeSpawnPrivate)
{
    this->removeReceiver(1);
    this->removeReceiver(0);
    this->removeEmitter(0);

    this->appendReceiver(&(d->nthreads_receiver));
    this->appendReceiver(&(d->internal_comm_emitter));
    this->appendReceiver(&(d->rank_emitter));

    d->is_parent    = true;
    d->first_run        = true;
    d->rank = -1;
    d->np   = -1;

    d->application = "dtkComposerEvaluator";
}

dtkComposerNodeSpawn::~dtkComposerNodeSpawn(void)
{

    delete d;

    d = NULL;
}

bool dtkComposerNodeSpawn::isSlave(void)
{
    return !d->is_parent;
}

void dtkComposerNodeSpawn::setApplication(QString app)
{
    d->application = app;
}

void dtkComposerNodeSpawn::setComposition(QDomDocument document)
{
    d->composition  = document.toString();
    d->current_hash = QCryptographicHash::hash(d->composition.toUtf8(),QCryptographicHash::Md5);
}

void dtkComposerNodeSpawn::setParentNode(dtkComposerNodeComposite *parent)
{
    d->parent = parent;
    d->is_parent = false;
}

void dtkComposerNodeSpawn::begin(void)
{
    // first time execution on the parent thread
    bool first_time = (d->first_run && d->is_parent );
    if (first_time) {
        d->first_run = false;
        // we are running on the controller, for the first time:
        // need to spawn processes
        if (d->nthreads_receiver.isEmpty()) {
            d->np =  QThread::idealThreadCount();
            dtkInfo() << "Set number of spawned processes to" << d->np;
        } else {
            d->np = d->nthreads_receiver.data();
        }

        d->policy.setNWorkers(d->np);
        this->setCommunicator(dtkDistributed::communicator::instance());
        QMap<QString, QString> options;
        this->communicator()->spawn(d->policy.hosts(), "", options);

        d->rank = this->communicator()->rank();
        d->rank_emitter.setData(d->rank);

        d->p.setCommunicator(this->communicator());
        d->p.setComposition(d->composition);
        d->p.setParent(this);
        this->communicator()->exec(&(d->p));
        return;
    } else if (d->is_parent) {
        dtkTrace() << "communicator exists,  no spawn";
    }

    int first_transmitter = 3;

    if (d->is_parent) {

        // TODO: handle not modified in evaluator process
        // if (d->current_hash != d->last_sent_hash){
            // send sub-composition to rank 0 on remote node
        d->p.setComposition(d->composition);
        d->last_sent_hash=d->current_hash;
        // } else {
        //     dtkDebug() << "composition hash hasn't changed, send 'not-modified' to slave";
        //     d->p.setComposition(QString("not-modified"));
        // }

        this->communicator()->exec(&(d->p));
    } else {

        d->internal_comm_emitter.setData(this->communicator());
        d->rank_emitter.setData(this->communicator()->rank());
        dtkTrace() << "get transmitter data";
        // running on the slave, receive data and set transmitters
        QList<dtkComposerTransmitter*> parent_receivers = d->parent->receivers();
        QList<dtkComposerTransmitter*> receivers = this->dtkComposerNodeComposite::receivers();
        int max  = parent_receivers.count();

        dtkComposerTransmitterProxyVariant *parent_t = NULL;
        dtkComposerTransmitterProxyVariant *t = NULL;
        for (int i = first_transmitter; i < max; ++i) {
            parent_t = reinterpret_cast<dtkComposerTransmitterProxyVariant*>(parent_receivers.at(i));
            t = reinterpret_cast<dtkComposerTransmitterProxyVariant*>(receivers.at(i));

            t->clearData();
            t->enableEmitter();
            t->setVariant(parent_t->variant());

        }
    }
}

void dtkComposerNodeSpawn::end(void)
{
    qint16 tag = 0;

    if (d->is_parent) {
        dtkDebug() << "running node spawn end statement on the parent thread";
        //FIXME: should we unspawn ?
    } else {
        dtkTrace() << "run barrier in spawn end statement" ;
        this->communicator()->barrier();
        if (this->communicator()->rank() == 0) {
            // running on the slave, send data and set transmitters
            dtkDebug() << "running node spawn end statement on rank" << this->communicator()->rank() ;

            QList<dtkComposerTransmitter*> parent_emitters = d->parent->emitters();
            QList<dtkComposerTransmitter*> emitters = this->dtkComposerNodeComposite::emitters();

            int max  = parent_emitters.count();

            dtkComposerTransmitterProxyVariant *parent_t = NULL;
            dtkComposerTransmitterProxyVariant *t = NULL;
            for (int i = 1; i < max; i++) {
                parent_t = reinterpret_cast<dtkComposerTransmitterProxyVariant*>(parent_emitters.at(i));
                t = reinterpret_cast<dtkComposerTransmitterProxyVariant*>(emitters.at(i));
                parent_t->clearData();
                parent_t->enableEmitter();
                parent_t->setVariant(t->variant());
            }
        }
    }
}

//
// dtkComposerNodeSpawn.cpp ends here
