/* axlAbstractVolumeRational.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2012 -Anais Ducoffe, Inria.
 * Created:
 * Version: $Id$
 * Last-Updated:
 *           By:
 *     Update #:
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTVOLUMERATIONAL_H
#define AXLABSTRACTVOLUMERATIONAL_H

#include "axlAbstractVolumeParametric.h"
#include "axlCoreExport.h"

class axlAbstractVolumeRationalPrivate;

class AXLCORE_EXPORT axlAbstractVolumeRational : public axlAbstractVolumeParametric
{
    Q_OBJECT

public:
    axlAbstractVolumeRational(void);
    virtual ~axlAbstractVolumeRational(void);



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
    axlAbstractVolumeRationalPrivate *d;
};
#endif
