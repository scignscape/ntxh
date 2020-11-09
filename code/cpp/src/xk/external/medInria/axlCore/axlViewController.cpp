/* axlViewController.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:09:38 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlViewController.h"
#include <axlCore/axlAbstractActor.h>
#include <axlCore/axlAbstractData.h>
#include <axlCore/axlAbstractField.h>
#include <axlCore/axlAbstractActorField.h>
#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkGlobal.h>

class axlViewControllerPrivate
{
public:
    QHash<dtkAbstractData *, axlAbstractActor *> actors;
    QHash<axlAbstractField *, axlAbstractActorField *> actorFields;
};

// /////////////////////////////////////////////////////////////////
// axlViewController
// /////////////////////////////////////////////////////////////////

axlViewController::axlViewController(void) : QObject(), d(new axlViewControllerPrivate)
{

}

axlViewController::~axlViewController(void)
{
    delete d;

    d = NULL;
}

dtkAbstractData *axlViewController::data(axlAbstractActor *actor)
{
    return d->actors.key(actor);
}

axlAbstractActor *axlViewController::actor(dtkAbstractData *data)
{
    return d->actors.value(data);
}

bool axlViewController::insert(dtkAbstractData *data, axlAbstractActor *actor)
{
    if(!data) {
        qDebug() << DTK_PRETTY_FUNCTION << " no data !";
        return false;
    }

    if(!actor) {
        qDebug() << DTK_PRETTY_FUNCTION << " no actor !";
        return false;
    }

    d->actors.insert(data,actor);

    emit inserted();

    return true;
}


void axlViewController::remove(dtkAbstractData *data)
{
    d->actors.remove(data);
}

int axlViewController::size(void)
{
    return d->actors.size();
}

QList<dtkAbstractData *> axlViewController::data(void)
{
    return d->actors.keys();
}

bool axlViewController::contains(axlAbstractData *data)
{
    return d->actors.contains(data);
}

// FIELD QHASH

axlAbstractField *axlViewController::dataField(axlAbstractActorField *actorField)
{
    return d->actorFields.key(actorField);
}

axlAbstractActorField *axlViewController::actorField(axlAbstractField *dataField)
{
    return d->actorFields.value(dataField);
}

bool axlViewController::insertField(axlAbstractField *dataField, axlAbstractActorField *actorField)
{
    if(!dataField) {
        qDebug() << DTK_PRETTY_FUNCTION << " no dataField !";
        return false;
    }

    if(!actorField) {
        qDebug() << DTK_PRETTY_FUNCTION << " no actorField !";
        return false;
    }

    d->actorFields.insert(dataField, actorField);

    emit insertedField();

    return true;
}

void axlViewController::removeField(axlAbstractField *dataField)
{
    d->actorFields.remove(dataField);
}

int axlViewController::sizeField(void)
{
    return d->actorFields.size();
}

QList<axlAbstractField *> axlViewController::dataField(void)
{
    return d->actorFields.keys();
}



QString axlViewController::description(void) const
{
    return "axlViewController";
}

