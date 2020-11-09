/* axlAbstractCurveRational.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 17:03:56 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Nov 22 14:28:30 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 18
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractCurveRational.h"

#include <dtkCoreSupport/dtkGlobal.h>

class axlAbstractCurveRationalPrivate
{
public:
};

axlAbstractCurveRational::axlAbstractCurveRational(void) : axlAbstractCurveParametric(), d(new axlAbstractCurveRationalPrivate)
{

}

axlAbstractCurveRational::~axlAbstractCurveRational(void)
{
    delete d;

    d = NULL;
}

QString axlAbstractCurveRational::write_domain(void) const {
    DTK_DEFAULT_IMPLEMENTATION;
    return "";
}

QString axlAbstractCurveRational::write_numerator(unsigned index) const {
    DTK_DEFAULT_IMPLEMENTATION;
    return "";
}

QString axlAbstractCurveRational::write_denominator(void) const {
    DTK_DEFAULT_IMPLEMENTATION;
    return "";
}

void axlAbstractCurveRational::setDomain(const QString& domain) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(domain);
}

void axlAbstractCurveRational::setDomain(const QVector<double> domain) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(domain);
}

void axlAbstractCurveRational::setNumerator(int index, const QString& numerator) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(index);
    DTK_UNUSED(numerator);
}

void axlAbstractCurveRational::setNumAndDenom(QStringList numAndDenom) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(numAndDenom);
}

void axlAbstractCurveRational::setDenominator(const QString& denominator) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(denominator);
}

void axlAbstractCurveRational::setSurface(QVector<double> domain, QStringList numAndDenom) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(domain);
    DTK_UNUSED(numAndDenom);
}
