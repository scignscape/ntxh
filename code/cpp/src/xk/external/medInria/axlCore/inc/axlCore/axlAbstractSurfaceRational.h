/* axlAbstractSurfaceRational.h ---
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

#ifndef AXLABSTRACTSURFACERATIONAL_H
#define AXLABSTRACTSURFACERATIONAL_H

#include "axlAbstractSurfaceParametric.h"
#include "axlCoreExport.h"

class axlAbstractSurfaceRationalPrivate;

class AXLCORE_EXPORT axlAbstractSurfaceRational : public axlAbstractSurfaceParametric
{
    Q_OBJECT

public:
    axlAbstractSurfaceRational(void);
    virtual ~axlAbstractSurfaceRational(void);



    virtual QString write_domain(void) const;
    virtual QString write_numerator(unsigned index) const;
    virtual QString write_denominator(void) const;
    virtual void setDomain(const QString& domain);
    virtual void setDomain(const QVector<double> domain);
    virtual void setNumerator(int index, const QString& numerator);
    virtual void setDenominator(const QString& denominator);
    virtual void setNumAndDenom(QStringList numAndDenom);
    virtual void setSurface(QVector<double> domain, QStringList numAndDenom);

private:
    axlAbstractSurfaceRationalPrivate *d;
};
#endif

