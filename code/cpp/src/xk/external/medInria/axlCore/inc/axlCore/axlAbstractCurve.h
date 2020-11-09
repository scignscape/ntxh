/* axlAbstractCurve.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:32:45 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 22
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTCURVE_H
#define AXLABSTRACTCURVE_H

#include "axlCoreExport.h"
#include <axlCore/axlAbstractData.h>

#include <QtCore>

class axlAbstractCurvePrivate;

class AXLCORE_EXPORT axlAbstractCurve : public axlAbstractData
{
    Q_OBJECT

public:
             axlAbstractCurve(void);
    virtual ~axlAbstractCurve(void);

    virtual int dimension(void) const;
    virtual bool isPlanar(void) const;


public:
    virtual void *curve(void);

private:
    axlAbstractCurvePrivate *d;
};
#endif
