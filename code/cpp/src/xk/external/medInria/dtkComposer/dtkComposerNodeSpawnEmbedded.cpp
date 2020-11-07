// Version: $Id: 4d9e3f2bae2e71d573d8852da4ca6975094f83b8 $
// 
// 

// Commentary: 
// 
// 

// Change Log:
// 
// 

// Code:

#include "dtkComposerNodeSpawnEmbedded.h"
#include "dtkComposerNodeSpawnEmbedded_p.h"

#include "dtkComposerTransmitter.h"
#include "dtkComposerEvaluatorProcess.h"

#include "dtkComposerTransmitterEmitter.h"
#include "dtkComposerTransmitterReceiver.h"
#include "dtkComposerTransmitterProxyVariant.h"

#include <dtkDistributed/dtkDistributed.h>

#include <dtkMeta/dtkMetaContainerSequential.h>

#include <dtkLog>

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeSpawn implementation
// /////////////////////////////////////////////////////////////////

dtkComposerNodeSpawnEmbedded::dtkComposerNodeSpawnEmbedded(void) : dtkComposerNodeRemote(),  d(new dtkComposerNodeSpawnEmbeddedPrivate)
{
    this->removeReceiver(1);
    this->removeReceiver(0);
    this->removeEmitter(0);

//    this->appendReceiver(&(d->nthreads_receiver));
    this->appendReceiver(&(d->container_emitter));
    this->appendReceiver(&(d->size_emitter));
    this->appendReceiver(&(d->index_emitter));
    this->appendReceiver(&(d->item_emitter));

    this->appendEmitter(&(d->newitem_emitter));

    d->is_parent    = true;
    d->first_run        = true;
    d->rank = -1;
    d->np   = -1;
    d->container      = NULL;
    d->out_container  = NULL;
}

dtkComposerNodeSpawnEmbedded::~dtkComposerNodeSpawnEmbedded(void)
{

    delete d;

    d = NULL;
}

bool dtkComposerNodeSpawnEmbedded::isSlave(void)
{
    return !d->is_parent;
}

void dtkComposerNodeSpawnEmbedded::setApplication(QString app)
{
    d->application = app;
}

void dtkComposerNodeSpawnEmbedded::setComposition(QDomDocument document)
{
    d->composition  = document.toString();
    dtkDebug() << "Spawn embedded: composition is" << d->composition;
    d->current_hash = QCryptographicHash::hash(d->composition.toUtf8(),QCryptographicHash::Md5);
}

void dtkComposerNodeSpawnEmbedded::setParentNode(dtkComposerNodeComposite *parent)
{
    d->parent = parent;
    d->is_parent = false;
}

void dtkComposerNodeSpawnEmbedded::setContainer(QVariant var_container)
{
    d->var_container = var_container;
    d->container = new dtkMetaContainerSequential(var_container.value<dtkMetaContainerSequential>());
}

void dtkComposerNodeSpawnEmbedded::setOutputContainer(QVariant var_container)
{
    d->out_variant = var_container;
    d->out_container = new dtkMetaContainerSequential(var_container.value<dtkMetaContainerSequential>());
}

QVariant dtkComposerNodeSpawnEmbedded::outputContainer(void)
{
   return  d->out_variant;
}

void dtkComposerNodeSpawnEmbedded::setContainerIndex(qlonglong index)
{
    d->index = index;
}

void dtkComposerNodeSpawnEmbedded::begin(void)
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
        if (d->container->size() < d->np) {
            d->np = d->container->size();
            dtkInfo() << "Container too small, reduce the number of threads to " << d->np;
        }
        if (d->np < 1) {
            dtkError() << "Empty container in parallel map, skip!" ;
            return;
        }

        d->policy.setNWorkers(d->np);
        this->setCommunicator(dtkDistributed::communicator::instance());
        QMap<QString, QString> options;
        this->communicator()->spawn(d->policy.hosts(), "", options);

        d->p.setCommunicator(this->communicator());
        d->p.setComposition(d->composition);
        d->p.setContainer(d->var_container);
        d->p.setOutputContainer(d->out_variant);
        d->p.setParent(this);
        this->communicator()->exec(&(d->p));
        return;
    } else if (d->is_parent) {
        dtkTrace() << "communicator exists,  no spawn";
    }

    int first_transmitter = 4;

    if (d->is_parent) {

        //TODO: handle not modified in evaluator process
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
        // d->nthreads_receiver.setData(this->communicator()->size());
        // running on the slave, receive data and set transmitters
        QList<dtkComposerTransmitter*> parent_receivers = d->parent->receivers();
        QList<dtkComposerTransmitter*> receivers = this->dtkComposerNodeComposite::receivers();
        int max  = parent_receivers.count();
        d->container_emitter.setData(d->var_container);
        d->size_emitter.setData(d->container->size());
        d->index_emitter.setData(d->index);
        d->item_emitter.setData(d->container->at(d->index));
        dtkComposerTransmitterProxyVariant *parent_t = NULL;
        dtkComposerTransmitterProxyVariant *t = NULL;
        if (first_transmitter  >= receivers.count() )
            return;
        for (int i = first_transmitter; i < max ; ++i) {
//            dtkDebug() << "setting transmitter "<< i << "on rank" << this->communicator()->rank() << receivers.count();
            parent_t = reinterpret_cast<dtkComposerTransmitterProxyVariant*>(parent_receivers.at(i));
            t = reinterpret_cast<dtkComposerTransmitterProxyVariant*>(receivers.at(i));

            t->clearData();
            t->enableEmitter();
            t->setVariant(parent_t->variant());

        }
    }
}

void dtkComposerNodeSpawnEmbedded::end(void)
{
    qint16 tag = 0;
    if (d->is_parent) {
        dtkDebug() << "running node spawn end statement on the parent thread";
        //FIXME: should we unspawn ?
    } else {
//        dtkDebug() << "set item" << d->index << d->newitem_emitter.variant()  << "on rank" << this->communicator()->rank() ;
        d->out_container->setAt(d->index, d->newitem_emitter.variant());

        // if (this->communicator()->rank() == 0) {
        //     // running on the slave, send data and set transmitters
        //     dtkDebug() << "running node spawn end statement on rank" << this->communicator()->rank() ;

        //     QList<dtkComposerTransmitter*> parent_emitters = d->parent->emitters();
        //     QList<dtkComposerTransmitter*> emitters = this->dtkComposerNodeComposite::emitters();

        //     int max  = parent_emitters.count();
        //     int first_transmitter = 0;

        //     dtkComposerTransmitterProxyVariant *parent_t = NULL;
        //     dtkComposerTransmitterProxyVariant *t = NULL;
        //     for (int i = first_transmitter; i < max; i++) {
        //         parent_t = reinterpret_cast<dtkComposerTransmitterProxyVariant*>(parent_emitters.at(i));
        //         t = reinterpret_cast<dtkComposerTransmitterProxyVariant*>(emitters.at(i));
        //         parent_t->clearData();
        //         parent_t->enableEmitter();
        //         parent_t->setVariant(t->variant());
        //     }
        // }
    }
}

// 
// dtkComposerNodeSpawnEmbedded.cpp ends here
