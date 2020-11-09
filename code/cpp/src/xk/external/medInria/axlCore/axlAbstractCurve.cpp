/* axlAbstractCurve.cpp ---
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

#include "axlAbstractCurve.h"

#include <dtkCoreSupport/dtkGlobal.h>

class axlAbstractCurvePrivate
{

};

axlAbstractCurve::axlAbstractCurve(void) : axlAbstractData(), d(new axlAbstractCurvePrivate)
{

}

axlAbstractCurve::~axlAbstractCurve(void)
{
    delete d;

    d = NULL;
}

void *axlAbstractCurve::curve(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return NULL;
}

int axlAbstractCurve::dimension(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

bool axlAbstractCurve::isPlanar(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}
