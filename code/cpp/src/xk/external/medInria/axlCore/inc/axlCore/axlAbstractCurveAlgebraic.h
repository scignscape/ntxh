/* axlAbstractCurveAlgebraic.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 16:07:03 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 42
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef axlAbstractCurveAlgebraic_H
#define axlAbstractCurveAlgebraic_H

#include "axlAbstractCurveParametric.h"
#include "axlCoreExport.h"

class axlAbstractCurveAlgebraicPrivate;

class AXLCORE_EXPORT axlAbstractCurveAlgebraic 
  : public axlAbstractCurveParametric   //? axlAbstractCurve
{
    Q_OBJECT

public:

    typedef QMap<double, axlPoint> Sample;

public:
             axlAbstractCurveAlgebraic(void);
    virtual ~axlAbstractCurveAlgebraic(void);

    virtual void setData(void *data);
    virtual void setData(const QList<double>& box, const QString&);

    //    virtual Sample sampling(int n);
    virtual QString description(void) const;

signals:
    void updated(void);
    void samplingChanged();

private:
    axlAbstractCurveAlgebraicPrivate *d;
};

#endif
