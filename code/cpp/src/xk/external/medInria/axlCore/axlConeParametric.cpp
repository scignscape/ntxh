/* axlConeParametric.cpp ---
 *
 * Author: Hung NGUYEN.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlConeParametric.h"
#include "axlCone.h"
#include "axlPoint.h"

#include <dtkCoreSupport/dtkGlobal.h>

// /////////////////////////////////////////////////////////////////
// axlConeParametricPrivate
// /////////////////////////////////////////////////////////////////

class axlConeParametricPrivate {
public:
    axlCone* cone;
    axlPoint* v;
    axlPoint* r;
    axlPoint* w;
};

// /////////////////////////////////////////////////////////////////
// axlConeParametric implementation
// /////////////////////////////////////////////////////////////////

axlConeParametric::axlConeParametric(axlAbstractSurfaceParametric* parent) :
    axlAbstractSurfaceParametric(),
    d(new axlConeParametricPrivate) {

    DTK_UNUSED(parent);

    this->setObjectName(this->identifier());

    d->cone = new axlCone;
    d->v = new axlPoint(*(d->cone->apex()) - (d->cone->basePoint()));
    d->v->normalize();
    d->r = new axlPoint;
    d->w = new axlPoint;
}

axlConeParametric::axlConeParametric(axlCone* cone, axlPoint* r) :
    axlAbstractSurfaceParametric(),
    d(new axlConeParametricPrivate) {

    this->setObjectName(this->identifier());

    d->cone = new axlCone(*cone);
    d->v = new axlPoint(*(d->cone->apex()) - (d->cone->basePoint()));
    d->v->normalize();
    d->r = new axlPoint(r);
    d->r->normalize();
    d->w = new axlPoint(axlPoint::crossProduct(d->v, r));
    d->w->normalize();
}

axlConeParametric::axlConeParametric(const axlCone& cone, const axlPoint& r) :
    axlAbstractSurfaceParametric(),
    d(new axlConeParametricPrivate) {

    this->setObjectName(this->identifier());

    d->cone = new axlCone(cone);
    d->v = new axlPoint(*(d->cone->apex()) - *(d->cone->basePoint()));
    d->v->normalize();
    d->r = new axlPoint(r);
    d->r->normalize();
    d->w = new axlPoint(axlPoint::crossProduct(d->v, r));
    d->w->normalize();
}

axlConeParametric::axlConeParametric(const axlConeParametric& other) :
    axlAbstractSurfaceParametric(),
    d(new axlConeParametricPrivate) {

    this->setObjectName(this->identifier());
    this->setParent(other.parent());

    d->cone = new axlCone(other.d->cone);
    d->v = new axlPoint(other.d->v);
    d->v->normalize();
    d->r = new axlPoint(other.d->r);
    d->r->normalize();
    d->w = new axlPoint(other.d->w);
    d->w->normalize();
}

axlConeParametric::~axlConeParametric(void) {
    delete d->cone;
    d->cone = NULL;
    delete d->v;
    d->v = NULL;
    delete d->r;
    d->r = NULL;
    delete d->w;
    d->w = NULL;

    delete d;
    d = NULL;
}

QString axlConeParametric::description(void) const {
    QString result = "axlConeParametric";
    result.append("\nCone :\n" + d->cone->description()
                + "\nv :\n" + d->v->description()
                + "\nr :\n" + d->r->description()
                + "\nw :\n" + d->w->description());
    return result;
}

QString axlConeParametric::identifier(void) const {
    return "axlConeParametric";
}

axlPoint* axlConeParametric::getR(void) const {
    return d->r;
}

void axlConeParametric::setR(axlPoint* r) {
    *(d->r) = *r;
    d->r->normalize();
    *(d->w) = axlPoint::crossProduct(*(d->v), *(d->r));
    d->w->normalize();
}

axlConeParametric& axlConeParametric::operator=(const axlConeParametric& other) {
    *(d->cone) = *(other.d->cone);
    *(d->v) = *(other.d->v);
    *(d->r) = *(other.d->r);
    *(d->w) = *(other.d->w);

    return *this;
}

void axlConeParametric::modifyR(double* r) {
    d->r->coordinates()[0] = r[0];
    d->r->coordinates()[1] = r[1];
    d->r->coordinates()[2] = r[2];
}

axlCone* axlConeParametric::getCone(void) const {
    return d->cone;
}

void axlConeParametric::setCone(const axlCone& cone) {
    *(d->cone) = cone;
    *(d->v) = (*(cone.apex()) - *(cone.basePoint()));
    d->v->normalize();
    *(d->w) = axlPoint::crossProduct(*(d->v), *(d->r));
    d->w->normalize();
}

axlPoint axlConeParametric::eval(double u, double v) {
	double height = axlPoint::distance(d->cone->apex(),d->cone->basePoint());
    return *(d->cone->basePoint()) + *(d->v)*(height - height*u/d->cone->radius())*std::cos(v) + *(d->r)*(height - height*u/d->cone->radius())*std::sin(v) + *(d->w)*u;
}

void axlConeParametric::eval(axlPoint *point, double u,double v) {
	double height = axlPoint::distance(d->cone->apex(),d->cone->basePoint());
    axlPoint p(*(d->cone->basePoint()) + *(d->v)*(height - height*u/d->cone->radius())*std::cos(v) + *(d->r)*(height - height*u/d->cone->radius())*std::sin(v) + *(d->w)*u);
    point->setCoordinates(p.x(), p.y(), p.z());
}

void axlConeParametric::eval(double& x, double& y, double& z, double u,double v) {
	double height = axlPoint::distance(d->cone->apex(),d->cone->basePoint());
    axlPoint p(*(d->cone->basePoint()) + *(d->v)*(height - height*u/d->cone->radius())*std::cos(v) + *(d->r)*(height - height*u/d->cone->radius())*std::sin(v) + *(d->w)*u);
    x = p.x();
    y = p.y();
    z = p.z();
}

void axlConeParametric::parameterOf(const axlPoint& point, double& um, double& vm) {
    axlPoint* o = d->cone->basePoint();

    axlPoint op = point - *o;
    um = axlPoint::dotProduct(op, d->v);
    vm = std::atan2(axlPoint::dotProduct(op, d->w), axlPoint::dotProduct(op, d->r));
}


// /////////////////////
// Slots
// /////////////////////
void axlConeParametric::onConeChanged(axlCone* cone) {
    *(d->cone) = *cone;
}

void axlConeParametric::onRChanged(axlPoint* r) {
    *(d->r) = *r;
}
