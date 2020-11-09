/* axlSurfaceParametricOffsetConverter.cpp ---
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
#include "axlSurfaceParametricOffset.h"
#include "axlSurfaceParametricOffsetConverter.h"

#include <dtkCoreSupport/dtkAbstractDataFactory.h>

class axlSurfaceParametricOffsetConverterPrivate
{
public:
    axlSurfaceParametricOffset *data;
};

axlSurfaceParametricOffsetConverter::axlSurfaceParametricOffsetConverter(void) : axlAbstractDataConverter(), d(new axlSurfaceParametricOffsetConverterPrivate)
{
    d->data = NULL;
}

axlSurfaceParametricOffsetConverter::~axlSurfaceParametricOffsetConverter(void)
{
    delete d;

    d = NULL;
}

QString axlSurfaceParametricOffsetConverter::description(void) const
{
    return "Converter from axlSurfaceParametricOffsetConverter to axlMesh";
}

QString axlSurfaceParametricOffsetConverter::identifier() const
{
    return "axlSurfaceParametricOffsetConverter";
}

QStringList axlSurfaceParametricOffsetConverter::fromTypes(void) const
{
    return QStringList() << "axlSurfaceParametricOffsetConverter" << "axlSurfaceParametricOffset";
}

QString axlSurfaceParametricOffsetConverter::toType (void) const
{
    return "axlMesh";
}

bool axlSurfaceParametricOffsetConverter::registered(void)
{
    return dtkAbstractDataFactory::instance()->registerDataConverterType("axlSurfaceParametricOffsetConverter", QStringList(), "axlMesh", createaxlSurfaceParametricOffsetConverter);
}

axlMesh *axlSurfaceParametricOffsetConverter::toMesh(void)
{
    if(!d->data)
        return NULL;

    axlMesh *mesh = new axlMesh;
    double uMin = d->data->surfaceParam()->startParam_u();
    double uMax = d->data->surfaceParam()->endParam_u();
    double vMin = d->data->surfaceParam()->startParam_v();
    double vMax = d->data->surfaceParam()->endParam_v();
    double stepu = (uMax-uMin)/40;
    double stepv = (vMax-vMin)/40;

    for(double u=uMin ;u < uMax ;u+=stepu ){
       for(double v=vMin ;v < vMax ;v+=stepv){
          axlPoint *currentNormal = new axlPoint;
          axlPoint *currentEval = new axlPoint;
          d->data->surfaceParam()->normal(currentNormal, u, v);
          d->data->surfaceParam()->eval(currentEval, u,v);
          currentNormal->normalize();
           axlPoint *currentResult = new axlPoint(*currentEval + *currentNormal * d->data->offset());
          mesh->push_back_vertex(currentResult);

          delete currentResult;
          delete currentNormal;
          delete currentEval;
        }
    }

    int n_u = 40; // Temporary
    int n_v = 40;

    int ind1, ind2;

    for(int j = 0; j < n_v - 1; j++) {

        for(int i= 0; i <n_u - 1; i++) {

            ind1 =  j * n_u + i;
            ind2 = ind1 + n_u;

            QVector<int> firstTriangle;
            QVector<int> secondTriamgle;

            firstTriangle.push_back(ind1);
            firstTriangle.push_back(ind1 + 1);
            firstTriangle.push_back(ind2);

            secondTriamgle.push_back(ind2);
            secondTriamgle.push_back(ind1 + 1);
            secondTriamgle.push_back(ind2 + 1);

            mesh->push_back_face(firstTriangle);
            mesh->push_back_face(secondTriamgle);
        }
    }

    mesh->setColor(d->data->color());
    mesh->setOpacity(d->data->opacity());
    mesh->setShader(d->data->shader());
    return mesh;
}

void axlSurfaceParametricOffsetConverter::setData(dtkAbstractData *data)
{
    if(axlSurfaceParametricOffset *surface = dynamic_cast<axlSurfaceParametricOffset *>(data))
        d->data = surface;
}

dtkAbstractDataConverter *createaxlSurfaceParametricOffsetConverter(void)
{
    return new axlSurfaceParametricOffsetConverter;
}
