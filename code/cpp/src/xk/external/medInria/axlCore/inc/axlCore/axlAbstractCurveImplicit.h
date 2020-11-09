/* axlAbstractCurveImplicit.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Nov 22 14:28:03 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 21
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTCURVEIMPLICIT_H
#define AXLABSTRACTCURVEIMPLICIT_H

#include "axlAbstractCurve.h"
#include "axlCoreExport.h"

class axlAbstractCurveImplicitPrivate;

class AXLCORE_EXPORT axlAbstractCurveImplicit : public axlAbstractCurve
{
    Q_OBJECT

public:
    axlAbstractCurveImplicit(void);
    virtual ~axlAbstractCurveImplicit(void);




    private:
        axlAbstractCurveImplicitPrivate *d;
};
#endif
