/* axlAbstractSurfaceNurbs.cpp ---
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

#include "axlAbstractSurfaceNurbs.h"

#include <dtkCoreSupport/dtkGlobal.h>

class axlAbstractSurfaceNurbsPrivate
{
public:
};

axlAbstractSurfaceNurbs::axlAbstractSurfaceNurbs(void) : axlAbstractSurfaceBSpline(), d(new axlAbstractSurfaceNurbsPrivate)
{

}

axlAbstractSurfaceNurbs::~axlAbstractSurfaceNurbs(void)
{
    delete d;

    d = NULL;
}
