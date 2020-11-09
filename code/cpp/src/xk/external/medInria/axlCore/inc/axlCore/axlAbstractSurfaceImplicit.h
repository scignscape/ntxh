/* axlAbstractSurfaceImplicit.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:09:38 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTSURFACEIMPLICIT_H
#define AXLABSTRACTSURFACEIMPLICIT_H

#include "axlAbstractSurface.h"
#include "axlCoreExport.h"

class axlAbstractSurfaceImplicitPrivate;

class AXLCORE_EXPORT axlAbstractSurfaceImplicit : public axlAbstractSurface
{
    Q_OBJECT

public:
    axlAbstractSurfaceImplicit(void);
    virtual ~axlAbstractSurfaceImplicit(void);

    virtual double eval(double *point) const;

private:
    axlAbstractSurfaceImplicitPrivate *d;
};
#endif


