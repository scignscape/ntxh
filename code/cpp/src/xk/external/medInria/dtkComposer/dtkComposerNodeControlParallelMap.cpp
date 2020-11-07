
#include "dtkComposerNodeControlParallelMap.h"

#include "dtkComposerNodeMetaData.h"
#include "dtkComposerNodeComposite.h"
#include "dtkComposerNodeSpawnEmbedded.h"
#include "dtkComposerNodeProxy.h"

#include "dtkComposerTransmitter.h"
#include "dtkComposerTransmitterEmitter.h"
#include "dtkComposerTransmitterReceiver.h"
#include "dtkComposerTransmitterProxy.h"
#include "dtkComposerTransmitterProxyLoop.h"

#include <dtkMeta/dtkMetaContainerSequential.h>

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeControlParallelMapPrivate interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeControlParallelMapPrivate
{
public:
    dtkComposerNodeMetaData header_md;
    dtkComposerNodeProxy header;

    dtkComposerNodeMetaData footer_md;
    dtkComposerNodeProxy footer;

    dtkComposerNodeMetaData body_block_md;
    dtkComposerNodeSpawnEmbedded *body_block;

public:
    dtkComposerTransmitterReceiverVariant header_rcv;
    dtkComposerTransmitterReceiverVariant footer_rcv;
    dtkComposerTransmitterEmitterVariant  footer_emit;

public:
    qlonglong counter;
    qlonglong size;
    QVariant output_var;

    bool first_iteration;

    dtkMetaContainerSequential *container;
    dtkMetaContainerSequential *out_container;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeControlParallelMap implementation
// /////////////////////////////////////////////////////////////////

dtkComposerNodeControlParallelMap::dtkComposerNodeControlParallelMap(void) : dtkComposerNodeControl(), d(new dtkComposerNodeControlParallelMapPrivate)
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
    d->body_block_md.setType("spawnEmbedded");
    d->body_block_md.appendInputLabel("container");
    d->body_block_md.appendInputLabel("size");
    d->body_block_md.appendInputLabel("index");
    d->body_block_md.appendInputLabel("item");
    d->body_block_md.appendOutputLabel("newItem");

    d->body_block = new dtkComposerNodeSpawnEmbedded();
    d->body_block->setNodeMetaData(&d->body_block_md);

    d->footer.emitters().first()->appendNext(&(d->footer_emit));

    d->container = NULL;
    d->out_container = NULL;
    d->counter = 0;
    d->size = -1;
}

dtkComposerNodeControlParallelMap::~dtkComposerNodeControlParallelMap(void)
{
    delete d;

    d = NULL;
}

int dtkComposerNodeControlParallelMap::blockCount(void)
{
    return 1;
}

dtkComposerNodeLeaf *dtkComposerNodeControlParallelMap::header(void)
{
    return &(d->header);
}

dtkComposerNodeLeaf *dtkComposerNodeControlParallelMap::footer(void)
{
    return &(d->footer);
}

dtkComposerNodeComposite *dtkComposerNodeControlParallelMap::block(int id)
{
    if(id == 0)
        return d->body_block;

    return NULL;
}

void dtkComposerNodeControlParallelMap::setInputs(void)
{
    // UNUSED
}

void dtkComposerNodeControlParallelMap::setOutputs(void)
{
    // UNUSED
}

void dtkComposerNodeControlParallelMap::setVariables(void)
{
    // UNUSED
}

int dtkComposerNodeControlParallelMap::selectBranch(void)
{
    // UNUSED
    return 0;
}

void dtkComposerNodeControlParallelMap::begin(void)
{
    if (d->header_rcv.isEmpty())
        return;

    QVariant var_container = d->header_rcv.variant();

    d->container = new dtkMetaContainerSequential(var_container.value<dtkMetaContainerSequential>());
    d->counter = 0;
    d->size = d->container->size();

    d->body_block->setContainer(var_container);

    d->output_var = d->footer_rcv.variant();

    if (d->output_var.isNull()) {
        dtkInfo() << "No output container, build a container based on input container" ;

        dtkMetaType::destroyPointer(d->output_var);
        d->output_var = dtkMetaType::createEmptyContainer(var_container);
        d->footer_emit.setData(d->output_var);
        d->out_container = new dtkMetaContainerSequential(d->output_var.value<dtkMetaContainerSequential>());
        d->out_container->resize(d->size);
        if (d->out_container->size() ==0) {
            dtkWarn() << "Can't resize out container, must build it by hand" ;
            for (qlonglong i = 0; i < d->size; ++i) {
                d->out_container->append(d->container->at(i));
            }
        }
    } else {
        d->out_container =  new dtkMetaContainerSequential(d->output_var.value<dtkMetaContainerSequential>());
        d->footer_emit.setData(d->output_var);
    }
    d->body_block->setOutputContainer(d->output_var);
}

void dtkComposerNodeControlParallelMap::end(void)
{
    // delete d->container;
    // delete d->out_container;
}

qlonglong dtkComposerNodeControlParallelMap::size(void)
{
    return d->size;
}

// 
// dtkComposerNodeControlParallelMap.cpp ends here
