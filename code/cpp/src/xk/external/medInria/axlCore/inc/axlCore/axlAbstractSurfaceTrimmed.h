/* axlAbstractSurfaceTrimmed.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Mar 29 09:43:43 2011 (+0200)
 *           By: Meriadeg Perrinel
 *     Update #: 24
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTSURFACETrimmed_H
#define AXLABSTRACTSURFACETrimmed_H

#include "axlAbstractSurfaceBSpline.h"
#include "axlCoreExport.h"

class axlAbstractCurveBSpline;

class axlAbstractSurfaceTrimmedPrivate;

class AXLCORE_EXPORT axlAbstractSurfaceTrimmed : public axlAbstractSurfaceBSpline
{
    Q_OBJECT

public:
    axlAbstractSurfaceTrimmed(void);
    virtual ~axlAbstractSurfaceTrimmed(void);

    using   axlAbstractSurfaceBSpline::setSurface;
    virtual void setSurface(axlAbstractSurfaceBSpline *surface, QList<axlAbstractCurveBSpline *> boundaryCurveSet);
    virtual void setSurface(axlAbstractSurfaceBSpline *surface, QList<QList <axlAbstractCurveBSpline *> > boundaryCurveSetSet);


    virtual bool inDomain(double u, double v) const;


    virtual QString description(void) const;





private:
    axlAbstractSurfaceTrimmedPrivate *d;
};
#endif

