// Version: $Id: 6c188b38806bedb7107cfbdc68f363239a4692fc $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include "dtkComposerNodeControlMap.h"

#include "dtkComposerNodeMetaData.h"
#include "dtkComposerNodeComposite.h"
#include "dtkComposerNodeProxy.h"

#include "dtkComposerTransmitter.h"
#include "dtkComposerTransmitterEmitter.h"
#include "dtkComposerTransmitterReceiver.h"
#include "dtkComposerTransmitterProxy.h"
#include "dtkComposerTransmitterProxyLoop.h"

#include <dtkMeta>

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeControlMapPrivate definition
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeControlMapPrivate
{
public:
    dtkComposerNodeMetaData header_md;
    dtkComposerNodeProxy header;

    dtkComposerNodeMetaData footer_md;
    dtkComposerNodeProxy footer;

    dtkComposerNodeMetaData body_block_md;
    dtkComposerNodeComposite body_block;

public:
    dtkComposerTransmitterReceiverVariant header_rcv;
    dtkComposerTransmitterReceiverVariant footer_rcv;
    dtkComposerTransmitterEmitterVariant  footer_emit;

    dtkComposerTransmitterEmitterVariant     block_container;
    dtkComposerTransmitterEmitter<qlonglong> block_size;
    dtkComposerTransmitterEmitter<qlonglong> block_index;
    dtkComposerTransmitterEmitterVariant     block_item;
    dtkComposerTransmitterReceiverVariant    block_newitem;

public:
    qlonglong counter;
    qlonglong size;

    dtkMetaContainerSequential *container;
    dtkMetaContainerSequential *out_container;

    QVariant output_var;

public:
    bool first_iteration;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeControlMap implementation
// /////////////////////////////////////////////////////////////////

dtkComposerNodeControlMap::dtkComposerNodeControlMap(void) : dtkComposerNodeControl(), d(new dtkComposerNodeControlMapPrivate)
{
    dtkComposerTransmitter::TypeList type_list;
    type_list << qMetaTypeId<dtkMetaContainerSequentialHandler *>();
    d->header_rcv.setTypeList(type_list);

    d->header_md.setTitle("Header");
    d->header_md.setKind("proxy");
    d->header_md.setType("proxy");
    d->header_md.appendInputLabel("container");

    d->header.removeEmitter(0);
    d->header.removeReceiver(0);
    d->header.appendReceiver(&(d->header_rcv));
    d->header.setAsHeader(true);
    d->header.setNodeMetaData(&d->header_md);

    d->footer_md.setTitle("Footer");
    d->footer_md.setKind("proxy");
    d->footer_md.setType("proxy");
    d->footer_md.appendOutputLabel("container");
    d->footer_md.appendInputLabel("container");

    d->footer.removeReceiver(0);
    d->footer.removeEmitter(0);
    d->footer.appendEmitter(&(d->footer_emit));
    d->footer.appendReceiver(&(d->footer_rcv));
    d->footer.setAsFooter(true);
    d->footer.setNodeMetaData(&d->footer_md);

    d->body_block_md.setTitle("Body");
    d->body_block_md.setKind("composite");
    d->body_block_md.setType("composite");
    d->body_block_md.appendInputLabel("container");
    d->body_block_md.appendInputLabel("size");
    d->body_block_md.appendInputLabel("index");
    d->body_block_md.appendInputLabel("item");
    d->body_block_md.appendOutputLabel("newItem");

    d->body_block.appendReceiver(&(d->block_container));
    d->body_block.appendReceiver(&(d->block_size));
    d->body_block.appendReceiver(&(d->block_index));
    d->body_block.appendReceiver(&(d->block_item));
    d->body_block.appendEmitter(&(d->block_newitem));
    d->body_block.setNodeMetaData(&d->body_block_md);

    d->block_container.appendPrevious(&d->header_rcv);
    d->header_rcv.appendNext(&d->block_container);

    d->footer.emitters().first()->appendNext(&(d->footer_emit));

    d->container = NULL;
    d->out_container = NULL;
    d->counter = 0;
    d->size = -1;
}

dtkComposerNodeControlMap::~dtkComposerNodeControlMap(void)
{
    delete d;

    d = NULL;
}

int dtkComposerNodeControlMap::blockCount(void)
{
    return 1;
}

dtkComposerNodeLeaf *dtkComposerNodeControlMap::header(void)
{
    return &(d->header);
}

dtkComposerNodeLeaf *dtkComposerNodeControlMap::footer(void)
{
    return &(d->footer);
}

dtkComposerNodeComposite *dtkComposerNodeControlMap::block(int id)
{
    if (id == 0)
        return &(d->body_block);

    return NULL;
}

void dtkComposerNodeControlMap::setInputs(void)
{
    for (dtkComposerTransmitterProxyLoop *t : this->inputTwins()) {
        t->disableLoopMode();
    }

    d->first_iteration = true;
}


void dtkComposerNodeControlMap::setOutputs(void)
{
    if (d->first_iteration) {
        for (dtkComposerTransmitterProxyLoop *t : this->outputTwins()) {
            t->twin()->enableLoopMode();
        }

        d->first_iteration = false;
    }

    for (dtkComposerTransmitterProxyLoop *t : this->outputTwins()) {
        t->twin()->setVariant(t->variant());
    }

    d->out_container->setAt(d->counter, d->block_newitem.variant());
    ++(d->counter);
}

void dtkComposerNodeControlMap::setVariables(void)
{

    d->block_item.setData(d->container->at(d->counter));
    d->block_index.setData(d->counter);
}

int dtkComposerNodeControlMap::selectBranch(void)
{
    return static_cast<int>(!((d->counter) < d->size));
}

void dtkComposerNodeControlMap::begin(void)
{
    if (d->header_rcv.isEmpty())
        return;

    QVariant var_container = d->header_rcv.variant();
    d->block_container.setData(var_container);

    d->container = new dtkMetaContainerSequential(var_container.value<dtkMetaContainerSequential>());
    d->counter = 0;
    d->size = d->container->size();
    d->block_size.setData(d->size);

    d->output_var = d->footer_rcv.variant();

    if (d->output_var.isNull()) {
        dtkMetaType::destroyPointer(d->output_var);
        d->output_var = dtkMetaType::createEmptyContainer(var_container);
        d->footer_emit.setData(d->output_var);
        d->out_container = new dtkMetaContainerSequential(d->output_var.value<dtkMetaContainerSequential>());
        d->out_container->reserve(d->size);
        if (d->out_container->size() == 0) {
            dtkWarn() << "Can't resize out container, must build it by hand" ;
            for (qlonglong i = 0; i < d->size; ++i) {
                d->out_container->append(d->container->at(i));
            }
        }
    } else {
        d->out_container =  new dtkMetaContainerSequential(d->output_var.value<dtkMetaContainerSequential>());
        d->footer_emit.setData(d->output_var);
    }
}

void dtkComposerNodeControlMap::end(void)
{
    delete d->container;
    delete d->out_container;
}

//
// dtkComposerNodeControlMap.cpp ends here
