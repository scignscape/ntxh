/* axlTorusParametric.cpp ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2013 - Valentin Michelet, Inria.
 * Created: Tue Jul 30 16:58:59 2013 (+0100)
 * Version: $Id$
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlTorusParametric.h"
#include "axlTorus.h"
#include "axlPoint.h"

#include <dtkCoreSupport/dtkGlobal.h>

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

#ifndef M_PI_2
# define M_PI_2 1.57079632679489661923
#endif

// /////////////////////////////////////////////////////////////////
// axlTorusParametricPrivate
// /////////////////////////////////////////////////////////////////

class axlTorusParametricPrivate {
public:
    axlTorus* torus;
    axlPoint* v;
    axlPoint* r;
    axlPoint* w;
};

// /////////////////////////////////////////////////////////////////
// axlTorusParametric implementation
// /////////////////////////////////////////////////////////////////

axlTorusParametric::axlTorusParametric(axlAbstractSurfaceParametric* parent) :
    axlAbstractSurfaceParametric(),
    d(new axlTorusParametricPrivate) {

    DTK_UNUSED(parent);

    this->setObjectName(this->identifier());

    d->torus = new axlTorus;
    d->v = new axlPoint(*d->torus->direction());
    d->v->normalize();
    d->r = new axlPoint;
    d->w = new axlPoint;
}

axlTorusParametric::axlTorusParametric(axlTorus* torus, axlPoint* r) :
    axlAbstractSurfaceParametric(),
    d(new axlTorusParametricPrivate) {

    this->setObjectName(this->identifier());

    d->torus = new axlTorus(*torus);
    d->v = new axlPoint(*d->torus->direction());
    d->v->normalize();
    d->r = new axlPoint(r);
    d->r->normalize();
    d->w = new axlPoint(axlPoint::crossProduct(d->v, r));
    d->w->normalize();
}

axlTorusParametric::axlTorusParametric(const axlTorus& torus, const axlPoint& r) :
    axlAbstractSurfaceParametric(),
    d(new axlTorusParametricPrivate) {

    this->setObjectName(this->identifier());

    d->torus = new axlTorus(torus);
    d->v = new axlPoint(*torus.direction());
    d->v->normalize();
    d->r = new axlPoint(r);
    d->r->normalize();
    d->w = new axlPoint(axlPoint::crossProduct(d->v, r));
    d->w->normalize();
}

axlTorusParametric::axlTorusParametric(const axlTorusParametric& other) :
    axlAbstractSurfaceParametric(),
    d(new axlTorusParametricPrivate) {

    this->setObjectName(this->identifier());
    this->setParent(other.parent());

    d->torus = new axlTorus(other.d->torus);
    d->v = new axlPoint(other.d->v);
    d->v->normalize();
    d->r = new axlPoint(other.d->r);
    d->r->normalize();
    d->w = new axlPoint(other.d->w);
    d->w->normalize();
}

axlTorusParametric::~axlTorusParametric(void) {
    delete d->torus;
    d->torus = NULL;
    delete d->v;
    d->v = NULL;
    delete d->r;
    d->r = NULL;
    delete d->w;
    d->w = NULL;

    delete d;
    d = NULL;
}

QString axlTorusParametric::description(void) const {
    QString result = "axlTorusParametric";
    result.append("\nTorus : " + d->torus->description()
                + "\nv : " + d->v->description()
                + "\nr : " + d->r->description()
                + "\nw : " + d->w->description());
    return result;
}

QString axlTorusParametric::identifier(void) const {
    return "axlTorusParametric";
}

axlPoint* axlTorusParametric::getV(void) const {
    return d->v;
}

axlPoint* axlTorusParametric::getR(void) const {
    return d->r;
}

axlPoint* axlTorusParametric::getW(void) const {
    return d->w;
}

void axlTorusParametric::setTorus(const axlTorus& torus) {
    *(d->torus) = torus;
    *(d->v) = (*(torus.direction()));
    d->v->normalize();
    *(d->w) = axlPoint::crossProduct(*(d->v), *(d->r));
    d->w->normalize();
}

void axlTorusParametric::setR(axlPoint* r) {
    *(d->r) = *r;
    r->normalize();
    *(d->w) = axlPoint::crossProduct(*(d->v), *(d->r));
    d->w->normalize();
}

axlTorusParametric& axlTorusParametric::operator=(const axlTorusParametric& other) {
    *(d->torus) = *(other.d->torus);
    *(d->v) = *(other.d->v);
    *(d->r) = *(other.d->r);
    *(d->w) = *(other.d->w);

    return *this;
}

void axlTorusParametric::modifyR(double* r) {
    d->r->coordinates()[0] = r[0];
    d->r->coordinates()[1] = r[1];
    d->r->coordinates()[2] = r[2];
}

axlTorus* axlTorusParametric::getTorus(void) const {
    return d->torus;
}

axlPoint axlTorusParametric::eval(double u, double v) {
    double r = d->torus->crossSectionRadius();
    double a = d->torus->ringRadius();

    return *(d->torus->centerPoint()) + *(d->r)*(a + r*std::cos(u))*std::cos(v)
                                      + *(d->w)*(a + r*std::cos(u))*std::sin(v)
                                      + *(d->v)*r*sin(u);
}

void axlTorusParametric::eval(axlPoint *point, double u,double v) {
    double r = d->torus->crossSectionRadius();
    double a = d->torus->ringRadius();

    axlPoint p(*(d->torus->centerPoint()) + *(d->r)*(a + r*std::cos(u))*std::cos(v)
                                          + *(d->w)*(a + r*std::cos(u))*std::sin(v)
                                          + *(d->v)*r*sin(u));

    point->setCoordinates(p.x(), p.y(), p.z());
}

void axlTorusParametric::eval(double& x, double& y, double& z, double u,double v) {
    double r = d->torus->crossSectionRadius();
    double a = d->torus->ringRadius();

    axlPoint p(*(d->torus->centerPoint()) + *(d->r)*(a + r*std::cos(u))*std::cos(v)
                                          + *(d->w)*(a + r*std::cos(u))*std::sin(v)
                                          + *(d->v)*r*sin(u));

    x = p.x();
    y = p.y();
    z = p.z();
}

void axlTorusParametric::parameterOf(const axlPoint& point, double& um, double& vm) {
    double a = d->torus->ringRadius();
    double r = d->torus->crossSectionRadius();

    axlPoint* o = d->torus->centerPoint();

    axlPoint op = point - *o;

    double OPi = axlPoint::dotProduct(op, d->r);
    double OPj = axlPoint::dotProduct(op, d->w);
    double OPk = axlPoint::dotProduct(op, d->v);

    double u = std::asin(OPk/r);
    if (std::sqrt(std::pow(OPi ,2) + std::pow(OPj ,2)) < a)
        um = M_PI - u;
    else
        um = u;

    if (std::abs(OPi) < 0.001)
        (OPj < 0) ? (vm = -M_PI_2) : (vm = M_PI_2);
    else
        vm = std::atan2(OPj, OPi);
}


// /////////////////////
// Slots
// /////////////////////
void axlTorusParametric::onTorusChanged(axlTorus* torus) {
    *(d->torus) = *torus;
}

void axlTorusParametric::onRChanged(axlPoint* r) {
    *(d->r) = *r;
}
