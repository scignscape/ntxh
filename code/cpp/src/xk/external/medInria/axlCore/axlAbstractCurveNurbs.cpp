/* axlAbstractCurveNurbs.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 17:03:56 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Nov 22 14:31:00 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 18
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractCurveNurbs.h"

#include <dtkCoreSupport/dtkGlobal.h>

class axlAbstractCurveNurbsPrivate
{
public:
};

axlAbstractCurveNurbs::axlAbstractCurveNurbs(void) : axlAbstractCurveBSpline(), d(new axlAbstractCurveNurbsPrivate)
{

}

axlAbstractCurveNurbs::~axlAbstractCurveNurbs(void)
{
    delete d;

    d = NULL;
}
