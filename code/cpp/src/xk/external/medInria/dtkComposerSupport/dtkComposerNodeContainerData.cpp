/* dtkComposerNodeContainerData.cpp ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Wed May  9 12:14:10 2012 (+0200)
 * Version: $Id: 9905e9e0e98b9578728755dbd086ad841b8169b4 $
 * Last-Updated: Fri Aug  3 10:45:37 2012 (+0200)
 *           By: tkloczko
 *     Update #: 62
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "dtkComposerNodeContainerData.h"
#include "dtkComposerTransmitterReceiver.h"
#include "dtkComposerTransmitterVariant.h"

#include <dtkCoreSupport/dtkAbstractData.h>

#include <dtkContainerSupport/dtkAbstractContainerWrapper.h>
#include <dtkContainerSupport/dtkContainerVectorWrapper.h>

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeContainerDataPrivate declaration
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeContainerDataPrivate
{
public:
    dtkComposerTransmitterReceiver<QString>   receiver_str;
    dtkComposerTransmitterReceiver<qlonglong> receiver_int;

public:
    dtkComposerTransmitterVariant emitter;

public:
    dtkAbstractContainerWrapper *container;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeContainerData implementation
// /////////////////////////////////////////////////////////////////

dtkComposerNodeContainerData::dtkComposerNodeContainerData(void) : dtkComposerNodeLeaf(), d(new dtkComposerNodeContainerDataPrivate)
{
    this->appendReceiver(&d->receiver_str);
    this->appendReceiver(&d->receiver_int);

    this->appendEmitter(&d->emitter);

    d->container = NULL;
}

dtkComposerNodeContainerData::~dtkComposerNodeContainerData(void)
{
    if (d->container)
        delete d->container;

    d->container = NULL;

    delete d;

    d = NULL;
}

QString dtkComposerNodeContainerData::inputLabelHint(int port)
{
    switch (port) {
    case 0:
        return "type";
        break;

    case 1:
        return "size";
        break;

    default:
        break;
    }

    return "port";
}

QString dtkComposerNodeContainerData::outputLabelHint(int port)
{
    switch (port) {
    case 0:
        return "container";
        break;

    default:
        break;
    }

    return "port";
}

void dtkComposerNodeContainerData::run(void)
{
    // QString type;
    // qlonglong size = 0;

    // if (!d->receiver_str.isEmpty())
    //     type = d->receiver_str.data();

    // if (!d->receiver_int.isEmpty())
    //     size = d->receiver_int.data();

    // // if (type == "list")
    // //     d->container = new dtkContainerListWrapper<dtkAbstractData *>(); // Not implemented yet
    // // else
    // d->container = new dtkContainerVectorWrapper<dtkAbstractData *>();

    // d->container->resize(size);

    // dtkAbstractData *data = NULL;
    // for(int i = 0; i < size; ++i) {
    //     data = new dtkAbstractData;
    //     data->setObjectName(QString("data #%1").arg(i));
    //     d->container->append(qVariantFromValue(data));
    // }

    // d->emitter.setData(*(d->container));
}
