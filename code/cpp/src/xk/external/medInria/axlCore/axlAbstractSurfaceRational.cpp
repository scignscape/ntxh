/* axlAbstractSurfaceRational.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 17:03:56 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:10:22 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 17
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractSurfaceRational.h"

#include <dtkCoreSupport/dtkGlobal.h>

class axlAbstractSurfaceRationalPrivate
{
public:
};

axlAbstractSurfaceRational::axlAbstractSurfaceRational(void) : axlAbstractSurfaceParametric(), d(new axlAbstractSurfaceRationalPrivate)
{

}

axlAbstractSurfaceRational::~axlAbstractSurfaceRational(void)
{
    delete d;

    d = NULL;
}

QString axlAbstractSurfaceRational::write_domain(void) const {
    DTK_DEFAULT_IMPLEMENTATION;
    return "";
}

QString axlAbstractSurfaceRational::write_numerator(unsigned index) const {
    DTK_DEFAULT_IMPLEMENTATION;
    return "";
}

QString axlAbstractSurfaceRational::write_denominator(void) const {
    DTK_DEFAULT_IMPLEMENTATION;
    return "";
}

void axlAbstractSurfaceRational::setDomain(const QString& domain) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(domain);
}

void axlAbstractSurfaceRational::setDomain(const QVector<double> domain) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(domain);
}

void axlAbstractSurfaceRational::setNumerator(int index, const QString& numerator) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(index);
    DTK_UNUSED(numerator);
}

void axlAbstractSurfaceRational::setNumAndDenom(QStringList numAndDenom) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(numAndDenom);
}

void axlAbstractSurfaceRational::setDenominator(const QString& denominator) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(denominator);
}

void axlAbstractSurfaceRational::setSurface(QVector<double> domain, QStringList numAndDenom) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(domain);
    DTK_UNUSED(numAndDenom);
}
