/* axlAbstractCurveRational.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Nov 22 14:28:23 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 20
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTCURVERATIONAL_H
#define AXLABSTRACTCURVERATIONAL_H

#include "axlAbstractCurveParametric.h"
#include "axlCoreExport.h"

class axlAbstractCurveRationalPrivate;

class AXLCORE_EXPORT axlAbstractCurveRational : public axlAbstractCurveParametric
{
    Q_OBJECT

public:
             axlAbstractCurveRational(void);
    virtual ~axlAbstractCurveRational(void);



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
    axlAbstractCurveRationalPrivate *d;
};
#endif

