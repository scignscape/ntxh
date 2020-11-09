/* axlPlaneParametric.cpp ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2013 - Valentin Michelet, Inria.
 * Created: Tue Jul 23 16:58:59 2013 (+0100)
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlPlaneParametric.h"
#include "axlPlane.h"
#include "axlPoint.h"

#include <dtkCoreSupport/dtkGlobal.h>

// /////////////////////////////////////////////////////////////////
// axlPlaneParametricPrivate
// /////////////////////////////////////////////////////////////////

class axlPlaneParametricPrivate {
public:
    axlPlane* plane;
    axlPoint* i;
    axlPoint* j;
};

// /////////////////////////////////////////////////////////////////
// axlPlaneParametric implementation
// /////////////////////////////////////////////////////////////////

axlPlaneParametric::axlPlaneParametric(axlAbstractSurfaceParametric* parent) :
    axlAbstractSurfaceParametric(),
    d(new axlPlaneParametricPrivate) {

    DTK_UNUSED(parent);

    this->setObjectName(this->identifier());

    d->plane = new axlPlane;
    d->i = new axlPoint;
    d->j = new axlPoint;
}

axlPlaneParametric::axlPlaneParametric(axlPlane* plane, axlPoint* i) :
    axlAbstractSurfaceParametric(),
    d(new axlPlaneParametricPrivate) {

    this->setObjectName(this->identifier());

    d->plane = new axlPlane(plane);
    d->i = new axlPoint(i);
    d->i->normalize();
    d->j = new axlPoint(axlPoint::crossProduct(plane->normal(), i));
    d->j->normalize();
}

axlPlaneParametric::axlPlaneParametric(const axlPlane& plane, const axlPoint& i) :
    axlAbstractSurfaceParametric(),
    d(new axlPlaneParametricPrivate) {

    this->setObjectName(this->identifier());

    d->plane = new axlPlane(plane);
    d->i = new axlPoint(i);
    d->i->normalize();
    d->j = new axlPoint(axlPoint::crossProduct(plane.normal(), i));
    d->j->normalize();
}

axlPlaneParametric::axlPlaneParametric(const axlPlaneParametric& other) :
    axlAbstractSurfaceParametric(),
    d(new axlPlaneParametricPrivate) {

    this->setObjectName(this->identifier());
    this->setParent(other.parent());

    d->plane = new axlPlane(other.d->plane);
    d->i = new axlPoint(other.d->i);
    d->i->normalize();
    d->j = new axlPoint(other.d->j);
    d->j->normalize();
}

axlPlaneParametric::~axlPlaneParametric(void) {
    delete d->plane;
    d->plane = NULL;
    delete d->i;
    d->i = NULL;
    delete d->j;
    d->j = NULL;

    delete d;
    d = NULL;
}

QString axlPlaneParametric::description(void) const {
    QString result = "axlPlaneParametric";
    result.append("\nPlane : " + d->plane->description()
                + "\nu : " + d->i->description()
                + "\nv : " + d->j->description());
    return result;
}

QString axlPlaneParametric::identifier(void) const {
    return "axlPlaneParametric";
}

void axlPlaneParametric::setPlane(const axlPlane& plane) {
    *(d->plane) = plane;
    *(d->j) = axlPoint::crossProduct(*(plane.normal()), *(d->i));
    d->j->normalize();
}

void axlPlaneParametric::setI(axlPoint* i) {
    *(d->i) = *i;
    d->i->normalize();
    *(d->j) = axlPoint::crossProduct(*(d->plane->normal()), *i);
    d->j->normalize();
}

void axlPlaneParametric::setJ(axlPoint* j) {
    *(d->j) = *j;
}

axlPlaneParametric& axlPlaneParametric::operator=(const axlPlaneParametric& other) {
    *(d->plane) = *(other.d->plane);
    *(d->i) = *(other.d->i);
    *(d->j) = *(other.d->j);

    return *this;
}

void axlPlaneParametric::modifyI(double* i) {
    d->i->coordinates()[0] = i[0];
    d->i->coordinates()[1] = i[1];
    d->i->coordinates()[2] = i[2];
}

void axlPlaneParametric::modifyJ(double* j) {
    d->j->coordinates()[0] = j[0];
    d->j->coordinates()[1] = j[1];
    d->j->coordinates()[2] = j[2];
}

axlPlane* axlPlaneParametric::getPlane(void) const {
    return d->plane;
}

axlPoint* axlPlaneParametric::getI(void) const {
    return d->i;
}

axlPoint* axlPlaneParametric::getJ(void) const {
    return d->j;
}


axlPoint axlPlaneParametric::eval(double u, double v) {
    return *(d->plane->point()) + *(d->i)*u + *(d->j)*v;
}

void axlPlaneParametric::eval(axlPoint* point, double u, double v) {
    axlPoint p = *(d->plane->point()) + *(d->i)*u + *(d->j)*v;
    point->setCoordinates(p.x(), p.y(), p.z());
}

void axlPlaneParametric::eval(double& x, double& y, double& z, double u, double v) {
    axlPoint p = *(d->plane->point()) + *(d->i)*u + *(d->j)*v;
    x = p.x();
    y = p.y();
    z = p.z();
}

void axlPlaneParametric::normal(axlPoint *normal, double, double) {
    *(normal) = *(d->plane->normal());
}

void axlPlaneParametric::parameterOf(const axlPoint& point, double& u, double& v) {
    axlPoint* o = d->plane->point();

    axlPoint op = point - *o;
    u = axlPoint::dotProduct(op, d->i);
    v = axlPoint::dotProduct(op, d->j);
}


// /////////////////////
// Slots
// /////////////////////
void axlPlaneParametric::onPlaneChanged(axlPlane* plane) {
    *(d->plane) = *plane;
}

void axlPlaneParametric::onIChanged(axlPoint* i) {
    *(d->i) = *i;
}

void axlPlaneParametric::onJChanged(axlPoint* j) {
    *(d->j) = *j;
}
