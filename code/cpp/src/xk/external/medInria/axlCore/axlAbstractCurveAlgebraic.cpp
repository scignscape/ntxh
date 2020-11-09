/* axlAbstractCurveAlgebraic.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 17:03:56 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:42:00 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 24
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractCurveAlgebraic.h"

#include <dtkCoreSupport/dtkGlobal.h>

typedef QMap<double, axlPoint> Sample;

class axlAbstractCurveAlgebraicPrivate
{
};

axlAbstractCurveAlgebraic::axlAbstractCurveAlgebraic(void) : axlAbstractCurveParametric(), d(new axlAbstractCurveAlgebraicPrivate)
{

}

axlAbstractCurveAlgebraic::~axlAbstractCurveAlgebraic(void)
{
    delete d;
    d = NULL;
}

void axlAbstractCurveAlgebraic::setData(const QList<double>&, const QString&)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

//Sample axlAbstractCurveAlgebraic::sampling(int n)
//{
//    DTK_DEFAULT_IMPLEMENTATION;

//    return Sample();
//}

QString axlAbstractCurveAlgebraic::description(void) const
{
   DTK_DEFAULT_IMPLEMENTATION;
   return "";
}

