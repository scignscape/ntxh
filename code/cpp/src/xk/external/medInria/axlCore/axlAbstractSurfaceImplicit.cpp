/* axlAbstractSurfaceImplicit.cpp ---
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

#include "axlAbstractSurfaceImplicit.h"

#include <dtkCoreSupport/dtkGlobal.h>

class axlAbstractSurfaceImplicitPrivate
{
public:
};

axlAbstractSurfaceImplicit::axlAbstractSurfaceImplicit(void) : axlAbstractSurface(), d(new axlAbstractSurfaceImplicitPrivate)
{

}

axlAbstractSurfaceImplicit::~axlAbstractSurfaceImplicit(void)
{
    delete d;

    d = NULL;
}


double axlAbstractSurfaceImplicit::eval(double *point) const{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0.0;
}
