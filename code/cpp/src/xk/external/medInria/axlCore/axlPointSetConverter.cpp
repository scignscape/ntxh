/* axlPointSetConverter.cpp ---
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
#include "axlPointSetConverter.h"
#include "axlPointSet.h"
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

class axlPointSetConverterPrivate
{
public:
    axlPointSet *data;
};

axlPointSetConverter::axlPointSetConverter(void) : axlAbstractDataConverter(), d(new axlPointSetConverterPrivate)
{
    d->data = NULL;
}

axlPointSetConverter::~axlPointSetConverter(void)
{
    delete d;

    d = NULL;
}

QString axlPointSetConverter::description(void) const
{
    return "Converter from axlPointSetConverter to axlMesh";
}

QStringList axlPointSetConverter::fromTypes(void) const
{
    return QStringList() << "axlPointSetConverter" << "axlPointSet";
}

QString axlPointSetConverter::toType (void) const
{
    return "axlMesh";
}

bool axlPointSetConverter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataConverterType("axlPointSetConverter", QStringList(), "axlMesh", createaxlPointSetConverter);
}

axlMesh *axlPointSetConverter::toMesh(void)
{
    if(!d->data)
        return NULL;

    axlMesh *mesh = new axlMesh;

    for(int i = 0 ; i < d->data->numberOfPoints() ; i++)
        mesh->push_back_vertex(d->data->value(i));


    return mesh;
}

void axlPointSetConverter::setData(dtkAbstractData *data)
{
    if(axlPointSet *point = dynamic_cast<axlPointSet *>(data))
        d->data = point;
}

dtkAbstractDataConverter *createaxlPointSetConverter(void)
{
    return new axlPointSetConverter;
}
