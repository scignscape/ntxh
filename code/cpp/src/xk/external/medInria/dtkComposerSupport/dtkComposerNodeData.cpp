// Version: $Id: fdccf984fe31daae75d28d544a862b907b8e4b6e $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include "dtkComposerNodeData.h"
#include "dtkComposerMetatype.h"

#include "dtkComposerTransmitterEmitter.h"
#include "dtkComposerTransmitterReceiver.h"

#include <dtkCoreSupport/dtkAbstractData>

#include <dtkLog>

#include <dtkMathSupport/dtkVector.h>

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeDataPrivate declaration
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeDataPrivate
{
public:
    dtkComposerTransmitterReceiver<dtkAbstractData> receiver_data;
    dtkComposerTransmitterReceiver<QString> receiver_string;
    dtkComposerTransmitterReceiver<dtkVectorReal> receiver_vector;

public:
    dtkComposerTransmitterEmitter<dtkAbstractData> emitter_data;

public:
    dtkAbstractData *data;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeData implementation
// /////////////////////////////////////////////////////////////////

dtkComposerNodeData::dtkComposerNodeData(void) : dtkComposerNodeLeafData(), d(new dtkComposerNodeDataPrivate)
{
    this->appendReceiver(&(d->receiver_string));
    this->appendReceiver(&(d->receiver_data));
    this->appendReceiver(&(d->receiver_vector));

    this->appendEmitter(&(d->emitter_data));

    d->data = NULL;
}

dtkComposerNodeData::~dtkComposerNodeData(void)
{
    if (d->data)
        delete d->data;

    delete d;

    d = NULL;
}

bool dtkComposerNodeData::isAbstractData(void) const
{
    return true;
}

QString dtkComposerNodeData::abstractDataType(void) const
{
    return "dtkAbstractData";
}

void dtkComposerNodeData::run(void)
{
    if (this->implementationHasChanged())
        d->data = this->data();

    if (!d->data) {
        dtkWarn() << "no data, abort " << this->currentImplementation();
        return;
    }

    if (!d->receiver_string.isEmpty())
        d->data->setParameter(*d->receiver_string.data());

    if (!d->receiver_vector.isEmpty())
        d->data->setParameter(*d->receiver_vector.data());

    d->data->update();

    d->emitter_data.setData(d->data);
}

QString dtkComposerNodeData::type(void)
{
    return "data";
}

QString dtkComposerNodeData::titleHint(void)
{
    return "Data";
}

QString dtkComposerNodeData::inputLabelHint(int port)
{
    switch (port) {
    case 0:
        return "string";

    case 1:
        return "data";

    case 2:
        return "vector";

    default:
        return dtkComposerNodeLeaf::inputLabelHint(port);
    }
}

QString dtkComposerNodeData::outputLabelHint(int port)
{
    switch (port) {
    case 0:
        return "data";

    default:
        return dtkComposerNodeLeaf::outputLabelHint(port);
    }
}

//
// dtkComposerNodeData.cpp ends here
