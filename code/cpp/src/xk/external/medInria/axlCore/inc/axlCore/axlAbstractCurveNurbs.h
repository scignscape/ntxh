/* axlAbstractCurveNurbs.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Nov 22 14:30:35 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 20
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTCURVENURBS_H
#define AXLABSTRACTCURVENURBS_H

#include "axlAbstractCurveBSpline.h"
#include "axlCoreExport.h"

class axlAbstractCurveNurbsPrivate;

class AXLCORE_EXPORT axlAbstractCurveNurbs : public axlAbstractCurveBSpline
{
    Q_OBJECT

public:
    axlAbstractCurveNurbs(void);
    virtual ~axlAbstractCurveNurbs(void);




private:
    axlAbstractCurveNurbsPrivate *d;
};
#endif
