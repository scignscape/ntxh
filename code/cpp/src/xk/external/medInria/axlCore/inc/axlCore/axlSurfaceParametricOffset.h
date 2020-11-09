/* axlSurfaceParametricOffset.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Mar 29 09:43:43 2011 (+0200)
 *           By: Julien Wintz
 *     Update #: 24
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef axlSurfaceParametricOffset_H
#define axlSurfaceParametricOffset_H

#include "axlAbstractSurfaceParametric.h"
#include "axlCoreExport.h"

#include <dtkMathSupport/dtkVector3D.h>

class axlSurfaceParametricOffsetPrivate;

class AXLCORE_EXPORT axlSurfaceParametricOffset : public axlAbstractSurfaceParametric
{
    Q_OBJECT

public:
    axlSurfaceParametricOffset(axlAbstractSurfaceParametric *surfaceParam, double offset = 0.0);
    axlSurfaceParametricOffset(const axlSurfaceParametricOffset &other);

    virtual ~axlSurfaceParametricOffset(void);

    double offset(void);
    void setOffset(double offset);
    axlAbstractSurfaceParametric *surfaceParam(void);

    axlSurfaceParametricOffset &operator =(const axlSurfaceParametricOffset &other);

    friend QDebug operator<<(QDebug dbg, axlSurfaceParametricOffset  sphere);
    friend QDebug operator<<(QDebug dbg, axlSurfaceParametricOffset& sphere);
    friend QDebug operator<<(QDebug dbg, axlSurfaceParametricOffset *sphere);




    virtual QString description(void) const;
    virtual QString identifier(void) const;



private:
    axlSurfaceParametricOffsetPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlSurfaceParametricOffset  sphere);
QDebug operator<<(QDebug dbg, axlSurfaceParametricOffset& sphere);
QDebug operator<<(QDebug dbg, axlSurfaceParametricOffset *sphere);

#endif
