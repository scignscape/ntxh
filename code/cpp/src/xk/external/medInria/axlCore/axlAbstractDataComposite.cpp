/* axlAbstractDataComposite.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 17:03:56 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:31:57 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 21
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractDataComposite.h"

#include <dtkCoreSupport/dtkGlobal.h>
#include <QtGui>

class axlAbstractDataCompositePrivate
{
public:
    QList<dtkAbstractData *> composite;
};

axlAbstractDataComposite::axlAbstractDataComposite(void) : axlAbstractData(), d(new axlAbstractDataCompositePrivate)
{
    this->setObjectName(this->description());
    setColor(Qt::white);
    setOpacity(1.0);
    setShader("");
}

axlAbstractDataComposite::~axlAbstractDataComposite(void)
{
    delete d;

    d = NULL;
}

void axlAbstractDataComposite::add(dtkAbstractData *data)
{
    d->composite << data;
}

bool axlAbstractDataComposite::get(dtkAbstractData * data)
{
    return d->composite.contains(data);
}


void axlAbstractDataComposite::set(QList<dtkAbstractData *> data)
{
    if(d->composite.isEmpty())
        d->composite = data;
}

void axlAbstractDataComposite::remove(dtkAbstractData *data)
{
    d->composite.removeOne(data);
}

int axlAbstractDataComposite::count(void)
{
    return d->composite.size();
}

dtkAbstractData *axlAbstractDataComposite::get(int i)
{
    return d->composite.at(i);
}

QString axlAbstractDataComposite::description(void) const
{
    return "DataComposite";
}

QString axlAbstractDataComposite::identifier(void) const
{
    return "axlDataComposite";
}
