/* axlAbstractCurveImplicit.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 17:03:56 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Nov 22 14:27:56 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 18
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractCurveImplicit.h"

#include <dtkCoreSupport/dtkGlobal.h>

class axlAbstractCurveImplicitPrivate
{
public:
};

axlAbstractCurveImplicit::axlAbstractCurveImplicit(void) : axlAbstractCurve(), d(new axlAbstractCurveImplicitPrivate)
{

}

axlAbstractCurveImplicit::~axlAbstractCurveImplicit(void)
{
    delete d;

    d = NULL;
}
