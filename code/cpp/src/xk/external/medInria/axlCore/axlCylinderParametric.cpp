/* axlCylinderParametric.cpp ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2013 - Valentin Michelet, Inria.
 * Created: Wed Jul 26 16:58:59 2013 (+0100)
 * Version: $Id$
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlCylinderParametric.h"
#include "axlCylinder.h"
#include "axlPoint.h"

#include <dtkCoreSupport/dtkGlobal.h>

// /////////////////////////////////////////////////////////////////
// axlCylinderParametricPrivate
// /////////////////////////////////////////////////////////////////

class axlCylinderParametricPrivate {
public:
    axlCylinder* cylinder;
    axlPoint* v;
    axlPoint* r;
    axlPoint* w;
};

// /////////////////////////////////////////////////////////////////
// axlCylinderParametric implementation
// /////////////////////////////////////////////////////////////////

axlCylinderParametric::axlCylinderParametric(axlAbstractSurfaceParametric* parent) :
    axlAbstractSurfaceParametric(),
    d(new axlCylinderParametricPrivate) {

    DTK_UNUSED(parent);

    this->setObjectName(this->identifier());

    d->cylinder = new axlCylinder;
    d->v = new axlPoint(*(d->cylinder->secondPoint()) - (d->cylinder->firstPoint()));
    d->v->normalize();
    d->r = new axlPoint;
    d->w = new axlPoint;
}

axlCylinderParametric::axlCylinderParametric(axlCylinder* cylinder, axlPoint* r) :
    axlAbstractSurfaceParametric(),
    d(new axlCylinderParametricPrivate) {

    this->setObjectName(this->identifier());

    d->cylinder = new axlCylinder(*cylinder);
    d->v = new axlPoint(*(d->cylinder->secondPoint()) - (d->cylinder->firstPoint()));
    d->v->normalize();
    d->r = new axlPoint(r);
    d->r->normalize();
    d->w = new axlPoint(axlPoint::crossProduct(d->v, r));
    d->w->normalize();
}

axlCylinderParametric::axlCylinderParametric(const axlCylinder& cylinder, const axlPoint& r) :
    axlAbstractSurfaceParametric(),
    d(new axlCylinderParametricPrivate) {

    this->setObjectName(this->identifier());

    d->cylinder = new axlCylinder(cylinder);
    d->v = new axlPoint(*(d->cylinder->secondPoint()) - (d->cylinder->firstPoint()));
    d->v->normalize();
    d->r = new axlPoint(r);
    d->r->normalize();
    d->w = new axlPoint(axlPoint::crossProduct(d->v, r));
    d->w->normalize();
}

axlCylinderParametric::axlCylinderParametric(const axlCylinderParametric& other) :
    axlAbstractSurfaceParametric(),
    d(new axlCylinderParametricPrivate) {

    this->setObjectName(this->identifier());
    this->setParent(other.parent());

    d->cylinder = new axlCylinder(other.d->cylinder);
    d->v = new axlPoint(other.d->v);
    d->v->normalize();
    d->r = new axlPoint(other.d->r);
    d->r->normalize();
    d->w = new axlPoint(other.d->w);
    d->w->normalize();
}

axlCylinderParametric::~axlCylinderParametric(void) {
    delete d->cylinder;
    d->cylinder = NULL;
    delete d->v;
    d->v = NULL;
    delete d->r;
    d->r = NULL;
    delete d->w;
    d->w = NULL;

    delete d;
    d = NULL;
}

QString axlCylinderParametric::description(void) const {
    QString result = "axlCylinderParametric";
    result.append("\nCylinder :\n" + d->cylinder->description()
                + "\nv :\n" + d->v->description()
                + "\nr :\n" + d->r->description()
                + "\nw :\n" + d->w->description());
    return result;
}

QString axlCylinderParametric::identifier(void) const {
    return "axlCylinderParametric";
}

axlPoint* axlCylinderParametric::getR(void) const {
    return d->r;
}

void axlCylinderParametric::setR(axlPoint* r) {
    *(d->r) = *r;
    d->r->normalize();
    *(d->w) = axlPoint::crossProduct(*(d->v), *(d->r));
    d->w->normalize();
}

axlCylinderParametric& axlCylinderParametric::operator=(const axlCylinderParametric& other) {
    *(d->cylinder) = *(other.d->cylinder);
    *(d->v) = *(other.d->v);
    *(d->r) = *(other.d->r);
    *(d->w) = *(other.d->w);

    return *this;
}

void axlCylinderParametric::modifyR(double* r) {
    d->r->coordinates()[0] = r[0];
    d->r->coordinates()[1] = r[1];
    d->r->coordinates()[2] = r[2];
}

axlCylinder* axlCylinderParametric::getCylinder(void) const {
    return d->cylinder;
}

void axlCylinderParametric::setCylinder(const axlCylinder& cylinder) {
    *(d->cylinder) = cylinder;
    *(d->v) = (*(cylinder.secondPoint()) - *(cylinder.firstPoint()));
    d->v->normalize();
    *(d->w) = axlPoint::crossProduct(*(d->v), *(d->r));
    d->w->normalize();
}

axlPoint axlCylinderParametric::eval(double u, double v) {
    return *(d->cylinder->firstPoint()) + *(d->v)*u + *(d->r)*d->cylinder->radius()*std::cos(v) + *(d->w)*d->cylinder->radius()*std::sin(v);
}

void axlCylinderParametric::eval(axlPoint *point, double u,double v) {
    axlPoint p(*(d->cylinder->firstPoint()) + *(d->v)*u + *(d->r)*d->cylinder->radius()*std::cos(v) + *(d->w)*d->cylinder->radius()*std::sin(v));
    point->setCoordinates(p.x(), p.y(), p.z());
}

void axlCylinderParametric::eval(double& x, double& y, double& z, double u,double v) {
    axlPoint p(*(d->cylinder->firstPoint()) + *(d->v)*u + *(d->r)*d->cylinder->radius()*std::cos(v) + *(d->w)*d->cylinder->radius()*std::sin(v));
    x = p.x();
    y = p.y();
    z = p.z();
}

void axlCylinderParametric::parameterOf(const axlPoint& point, double& um, double& vm) {
    axlPoint* o = d->cylinder->firstPoint();

    axlPoint op = point - *o;
    um = axlPoint::dotProduct(op, d->v);
    vm = std::atan2(axlPoint::dotProduct(op, d->w), axlPoint::dotProduct(op, d->r));
}


// /////////////////////
// Slots
// /////////////////////
void axlCylinderParametric::onCylinderChanged(axlCylinder* cylinder) {
    *(d->cylinder) = *cylinder;
}

void axlCylinderParametric::onRChanged(axlPoint* r) {
    *(d->r) = *r;
}
