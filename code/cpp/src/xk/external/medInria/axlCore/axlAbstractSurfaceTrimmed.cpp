/* axlAbstractSurfaceTrimmed.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 17:03:56 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Mar 29 09:43:31 2011 (+0200)
 *           By: Meriadeg Perrinel
 *     Update #: 36
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractCurveBSpline.h"
#include "axlAbstractSurfaceTrimmed.h"

#include <dtkCoreSupport/dtkGlobal.h>

class axlAbstractSurfaceTrimmedPrivate
{
public:
};

axlAbstractSurfaceTrimmed::axlAbstractSurfaceTrimmed(void) : axlAbstractSurfaceBSpline(), d(new axlAbstractSurfaceTrimmedPrivate)
{

}

axlAbstractSurfaceTrimmed::~axlAbstractSurfaceTrimmed(void)
{
    delete d;

    d = NULL;
}

void axlAbstractSurfaceTrimmed::setSurface(axlAbstractSurfaceBSpline *surface, QList<axlAbstractCurveBSpline *> boundaryCurveSet)
{
    Q_UNUSED(surface);
    Q_UNUSED(boundaryCurveSet);
}

void axlAbstractSurfaceTrimmed::setSurface(axlAbstractSurfaceBSpline *surface, QList<QList <axlAbstractCurveBSpline *> > boundaryCurveSetSet)
{
    Q_UNUSED(surface);
    Q_UNUSED(boundaryCurveSetSet);
}


bool axlAbstractSurfaceTrimmed::inDomain(double u, double v) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return false;
}



QString axlAbstractSurfaceTrimmed::description(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return "";
}
