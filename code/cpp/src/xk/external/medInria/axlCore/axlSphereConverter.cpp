/* axlSphereConverter.cpp ---
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
#include "axlSphere.h"
#include "axlSphereConverter.h"
#include <dtkCoreSupport/dtkAbstractDataFactory.h>

class axlSphereConverterPrivate
{
public:
    axlSphere *data;
};

axlSphereConverter::axlSphereConverter(void) : axlAbstractDataConverter(), d(new axlSphereConverterPrivate)
{
    d->data = NULL;
}

axlSphereConverter::~axlSphereConverter(void)
{
    delete d;

    d = NULL;
}

QString axlSphereConverter::description(void) const
{
    return "Converter from axlSphereConverter to axlMesh";
}

QStringList axlSphereConverter::fromTypes(void) const
{
    return QStringList() << "axlSphereConverter" << "axlSphere";
}

QString axlSphereConverter::toType (void) const
{
    return "axlMesh";
}

bool axlSphereConverter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataConverterType("axlSphereConverter", QStringList(), "axlMesh", createaxlSphereConverter);
}

axlMesh *axlSphereConverter::toMesh(void)
{
    if(!d->data)
        return NULL;

    axlMesh *mesh = new axlMesh;

    double x= d->data->x(),
            y=d->data->y(),
            z=d->data->z(),
            r=d->data->radius();
    double pi=3.1415;
    unsigned N1=50, N2=50;

    for(unsigned i=0;i<N1;i++)
        for(unsigned j=0;j<N2;j++)
            mesh->push_back_vertex(x+r*cos(2*pi*i/N1)*cos(2*pi*j/N2),
                                   y+r*sin(2*pi*i/N1)*cos(2*pi*j/N2),
                                   z+r*sin(2*pi*j/N2));
    for(unsigned i=0;i<N1;i++)
        for(unsigned j=0;j<N2;j++){
            axlMesh::Face f;
            f.push_back(i+N1*j);
            f.push_back((i+1)%N1+N1*j);
            f.push_back((i+1)%N1+N1*((j+1)%N2));
            f.push_back(i+N1*((j+1)%N2));;
            mesh->push_back_face(f);
        }

    return mesh;
}

void axlSphereConverter::setData(dtkAbstractData *data)
{
    if(axlSphere *sphere = dynamic_cast<axlSphere *>(data))
        d->data = sphere;
}

dtkAbstractDataConverter *createaxlSphereConverter(void)
{
    return new axlSphereConverter;
}
