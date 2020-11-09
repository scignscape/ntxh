/* axlAbstractSurfaceNurbs.h ---
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

#ifndef AXLABSTRACTSURFACENURBS_H
#define AXLABSTRACTSURFACENURBS_H

#include "axlAbstractSurfaceBSpline.h"
#include "axlCoreExport.h"

class axlAbstractSurfaceNurbsPrivate;

class AXLCORE_EXPORT axlAbstractSurfaceNurbs : public axlAbstractSurfaceBSpline
{
    Q_OBJECT

public:
    axlAbstractSurfaceNurbs(void);
    virtual ~axlAbstractSurfaceNurbs(void);




private:
    axlAbstractSurfaceNurbsPrivate *d;
};
#endif

