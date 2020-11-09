/* axlAbstractVolumeRational.cpp ---
 *
 * Author:Anais Ducoffe
 * Copyright (C) 2012 - Anais Ducoffe, Inria.
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

#include "axlAbstractVolumeRational.h"
#include <dtkCoreSupport/dtkGlobal.h>

class axlAbstractVolumeRationalPrivate
{
public:
};

axlAbstractVolumeRational::axlAbstractVolumeRational(void) : axlAbstractVolumeParametric(), d(new axlAbstractVolumeRationalPrivate)
{

}

axlAbstractVolumeRational::~axlAbstractVolumeRational(void)
{
    delete d;

    d = NULL;
}

QString axlAbstractVolumeRational::write_domain(void) const {
    DTK_DEFAULT_IMPLEMENTATION;
    return "";
}

QString axlAbstractVolumeRational::write_numerator(unsigned index) const {
    DTK_DEFAULT_IMPLEMENTATION;
    return "";
}

QString axlAbstractVolumeRational::write_denominator(void) const {
    DTK_DEFAULT_IMPLEMENTATION;
    return "";
}

void axlAbstractVolumeRational::setDomain(const QString& domain) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(domain);
}

void axlAbstractVolumeRational::setDomain(const QVector<double> domain) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(domain);
}

void axlAbstractVolumeRational::setNumerator(int index, const QString& numerator) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(index);
    DTK_UNUSED(numerator);
}

void axlAbstractVolumeRational::setNumAndDenom(QStringList numAndDenom) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(numAndDenom);
}

void axlAbstractVolumeRational::setDenominator(const QString& denominator) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(denominator);
}

void axlAbstractVolumeRational::setSurface(QVector<double> domain, QStringList numAndDenom) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(domain);
    DTK_UNUSED(numAndDenom);
}

