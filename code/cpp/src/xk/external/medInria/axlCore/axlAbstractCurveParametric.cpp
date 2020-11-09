/* axlAbstractCurveParametric.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 17:03:56 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Nov 22 14:27:36 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 18
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractCurveParametric.h"


//#include <axlCore/axlAbstractVisitorParametric.h>

#include "axlPoint.h"
#include "axlMesh.h"

#include <dtkCoreSupport/dtkGlobal.h>

class axlAbstractCurveParametricPrivate
{
public:
    int samples;
    //axlAbstractVisitorParametric *visitor;
};

axlAbstractCurveParametric::axlAbstractCurveParametric(void) : axlAbstractCurve(), d(new axlAbstractCurveParametricPrivate)
{
    //d->visitor = NULL;

}

axlAbstractCurveParametric::~axlAbstractCurveParametric(void)
{
    delete d;

    d = NULL;
}

double axlAbstractCurveParametric::startParam(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

double axlAbstractCurveParametric::endParam(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 1;
}

axlPoint axlAbstractCurveParametric::eval(double u)
{
//    if(d->visitor){
//        return d->visitor->eval(u);
//    }

    return axlPoint();
}


//axlAbstractVisitorParametric *axlAbstractCurveParametric::getVisitor(void){
//    return d->visitor;
//}

//void axlAbstractCurveParametric::setVisitor(axlAbstractVisitorParametric *visitor){
//    d->visitor = visitor;
//}


axlMesh axlAbstractCurveParametric::eval(double u, int derivs, bool from_right)
{
    Q_UNUSED(u);
    Q_UNUSED(derivs);
    Q_UNUSED(from_right);

    return axlMesh();
}

void axlAbstractCurveParametric::eval(axlPoint *point, double u)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(point);
    DTK_UNUSED(u);
}


double axlAbstractCurveParametric::parameterOf(const axlPoint& point) {

    unsigned N=200;

    double du = (this->endParam()-this->startParam())/N;
    double um = this->startParam();

    axlPoint* P = new axlPoint;
    this->eval(P, um);

    double dm = axlPoint::distance(point,*P);
    double dd = dm;

    for (double u = um+du; u <= this->endParam(); u += du) {
        this->eval(P,u);
        if ((dd = axlPoint::distance(point,*P)) < dm) {
            dm = dd;
            um = u;
        }
    }

    delete P;

    return um;
}


double axlAbstractCurveParametric::length(double tol)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

int axlAbstractCurveParametric::numSamples(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

void axlAbstractCurveParametric::setNumSamples(int numSamples)
{
    Q_UNUSED(numSamples);
}

const int& axlAbstractCurveParametric::samples(void) const
{
    return d->samples;
}

void axlAbstractCurveParametric::onDirectChanged(bool direct) {
    DTK_UNUSED(direct);
}

void axlAbstractCurveParametric::setSamples(const int& samples)
{
    d->samples = samples;
}
