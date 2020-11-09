/* axlAbstractSurface.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 17:03:56 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:10:22 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 17
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractSurface.h"
#include "axlMesh.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <QtGui>

class axlAbstractSurfacePrivate
{

};

axlAbstractSurface::axlAbstractSurface(void) : axlAbstractData(), d(new axlAbstractSurfacePrivate)
{

}

axlAbstractSurface::~axlAbstractSurface(void)
{
    delete d;

    d = NULL;
}

int axlAbstractSurface::dimension(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

axlMesh *axlAbstractSurface::toAxlMesh(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return NULL;
}

void *axlAbstractSurface::surface(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return NULL;
}
