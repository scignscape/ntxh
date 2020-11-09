/* axlInspectorObjectController.h ---
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

#include "axlInspectorObjectController.h"

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkGlobal.h>
#include <axlCore/axlAbstractData.h>

#include <axlGui/axlInspectorObjectManagerTreeItem.h>

class axlInspectorObjectControllerPrivate
{
public:
    QHash<dtkAbstractData *, axlInspectorObjectManagerTreeItem *> items;
};

// /////////////////////////////////////////////////////////////////
// axlInspectorObjectController
// /////////////////////////////////////////////////////////////////

axlInspectorObjectController::axlInspectorObjectController(void) : QObject(), d(new axlInspectorObjectControllerPrivate)
{

}

axlInspectorObjectController::~axlInspectorObjectController(void)
{
    delete d;

    d = NULL;
}

dtkAbstractData *axlInspectorObjectController::data(axlInspectorObjectManagerTreeItem *item)
{
    return d->items.key(item);
}

axlInspectorObjectManagerTreeItem *axlInspectorObjectController::item(dtkAbstractData *data)
{
    return d->items.value(data);
}

dtkAbstractData *axlInspectorObjectController::data(QString dataname)
{
    // Be carefull, we considered here that two different data cannot have the same name.

    foreach(axlInspectorObjectManagerTreeItem *item, this->items())
    {
        if ((item->text(0)) == dataname)
            return data(item);
    }

    return NULL;
}


QList<axlInspectorObjectManagerTreeItem *> axlInspectorObjectController::items()
{
    return d->items.values();
}

QList<dtkAbstractData  *> axlInspectorObjectController::datas()
{
    return d->items.keys();
}

bool axlInspectorObjectController::insert(dtkAbstractData *data, axlInspectorObjectManagerTreeItem *item)
{
    if(!data) {
      qDebug() << DTK_PRETTY_FUNCTION << " no data !";
      return false;
    }

    if(!item) {
      qDebug() << DTK_PRETTY_FUNCTION << " no item !";
      return false;
    }

    d->items.insert(data, item);

    emit inserted();

    return true;
}

int axlInspectorObjectController::size(void)
{
    return d->items.size();
}

void axlInspectorObjectController::remove(dtkAbstractData *data)
{
    d->items.remove(data);
}

void axlInspectorObjectController::onDataRemoved(QList<dtkAbstractData *> dataToRemoved)
{
    foreach(dtkAbstractData *data, dataToRemoved)
        d->items.remove(data);
}


QString axlInspectorObjectController::description(void) const
{
    return "axlInspectorObjectController";
}
