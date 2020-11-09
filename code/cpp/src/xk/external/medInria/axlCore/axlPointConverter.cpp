/* axlPointConverter.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Jan 24 11:03:18 2012 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Jan 24 11:27:25 2012 (+0100)
 *           By: Julien Wintz
 *     Update #: 50
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlMesh.h"
#include "axlPoint.h"
#include "axlPointConverter.h"
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

class axlPointConverterPrivate
{
public:
    axlPoint *data;
};

axlPointConverter::axlPointConverter(void) : axlAbstractDataConverter(), d(new axlPointConverterPrivate)
{
    d->data = NULL;
}

axlPointConverter::~axlPointConverter(void)
{
    delete d;

    d = NULL;
}

QString axlPointConverter::description(void) const
{
    return "Converter from axlPointConverter to axlMesh";
}

QStringList axlPointConverter::fromTypes(void) const
{
    return QStringList() << "axlPointConverter" << "axlPoint";
}

QString axlPointConverter::toType (void) const
{
    return "axlMesh";
}

bool axlPointConverter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataConverterType("axlPointConverter", QStringList(), "axlMesh", createaxlPointConverter);
}

axlMesh *axlPointConverter::toMesh(void)
{
    if(!d->data)
        return NULL;

    axlMesh *mesh = new axlMesh;

    mesh->push_back_vertex(d->data);

    return mesh;
}

void axlPointConverter::setData(dtkAbstractData *data)
{
    if(axlPoint *point = dynamic_cast<axlPoint *>(data))
        d->data = point;
}

dtkAbstractDataConverter *createaxlPointConverter(void)
{
    return new axlPointConverter;
}
