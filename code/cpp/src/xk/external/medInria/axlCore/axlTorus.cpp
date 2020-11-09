/* axlTorus.cpp ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2012 - Valentin Michelet, Inria.
 * Created: Tue Nov  9 16:58:59 2012 (+0100)
 * Version: $Id$
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlTorus.h"

#include "axlPoint.h"

#include <dtkCoreSupport/dtkGlobal.h>

// /////////////////////////////////////////////////////////////////
// axlTorusPrivate
// /////////////////////////////////////////////////////////////////

class axlTorusPrivate {
public:
    axlPoint* center;
    axlPoint* direction;
    double ringRadius;
    double crossSectionRadius;
};

// /////////////////////////////////////////////////////////////////
// axlTorus implementation
// /////////////////////////////////////////////////////////////////

axlTorus::axlTorus(QObject *parent) :
    axlAbstractData(),
    d(new axlTorusPrivate) {

    this->setObjectName(this->identifier());

    d->center = new axlPoint;
    d->direction = new axlPoint(1.0, 0.0, 0.0);
    d->ringRadius = 1.0;
    d->crossSectionRadius = 0.2;
}

axlTorus::axlTorus(axlPoint* center, axlPoint* direction, double ringRadius, double crossSectionRadius) :
    axlAbstractData(),
    d(new axlTorusPrivate) {

    this->setObjectName(this->identifier());

    d->center = new axlPoint(center);
    d->direction = new axlPoint(direction);
    d->ringRadius = ringRadius;
    d->crossSectionRadius = crossSectionRadius;
}

axlTorus::axlTorus(const axlPoint& center, const axlPoint& direction, double ringRadius, double crossSectionRadius) :
    axlAbstractData(),
    d(new axlTorusPrivate) {

    this->setObjectName(this->identifier());

    d->center = new axlPoint(center);
    d->direction = new axlPoint(direction);
    d->ringRadius = ringRadius;
    d->crossSectionRadius = crossSectionRadius;
}

axlTorus::axlTorus(const axlTorus& other) :
    axlAbstractData(),
    d(new axlTorusPrivate) {

    this->setObjectName(this->identifier());
    this->setParent(other.parent());
    d->center = new axlPoint(other.d->center);
    d->direction = new axlPoint(other.d->direction);
    d->ringRadius = other.d->ringRadius;
    d->crossSectionRadius = other.d->crossSectionRadius;
}

axlTorus::~axlTorus(void) {
    if(d->center) {
        delete d->center;
        d->center = NULL;
    }
    if(d->direction) {
        delete d->direction;
        d->direction = NULL;
    }
    delete d;
    d = NULL;
}

QString axlTorus::description(void) const {
    QString res = "axlTorus";
    res.append("\nCenter: " + d->center->description());
    res.append("\nDirection: " + d->direction->description());
    res.append("\nRing radius: " + QString::number(d->ringRadius));
    res.append("\nCross section radius: " + QString::number(d->crossSectionRadius));
    return res;
}

QString axlTorus::identifier(void) const {
    return "axlTorus";
}

axlPoint* axlTorus::centerPoint(void) const {
    return d->center;
}

axlPoint* axlTorus::direction(void) const {
    return d->direction;
}

double axlTorus::ringRadius(void) const {
    return d->ringRadius;
}

double axlTorus::crossSectionRadius(void) const {
    return d->crossSectionRadius;
}

void axlTorus::setValues(axlPoint *center, axlPoint *direction, double ringRadius, double crossSectionRadius) {
    *(d->center) = *center;
    *(d->direction) = *direction;
    d->ringRadius = ringRadius;
    d->crossSectionRadius = crossSectionRadius;
}

void axlTorus::setCenter(axlPoint* center) {
    *(d->center) = *center;
}

void axlTorus::setDirection(axlPoint* direction) {
    *(d->direction) = *direction;
}

void axlTorus::setRingRadius(double ringRadius) {
    d->ringRadius = ringRadius;
}

void axlTorus::setCrossSectionRadius(double crossSectionRadius) {
    d->crossSectionRadius = crossSectionRadius;
}

void axlTorus::setCenter(double* center) {
    d->center->coordinates()[0] = center[0];
    d->center->coordinates()[1] = center[1];
    d->center->coordinates()[2] = center[2];
    //this->touchGeometry();
}

void axlTorus::setDirection(double* direction) {
    d->direction->coordinates()[0] = direction[0];
    d->direction->coordinates()[1] = direction[1];
    d->direction->coordinates()[2] = direction[2];
    this->touchGeometry();
}

    void axlTorus::touchCenterPoint(axlPoint center)
    {
        d->center->setCoordinates(center.x(),center.y(),center.z());
        this->touchGeometry();
    }

    void axlTorus::touchDirection(axlPoint direction)
    {
        d->direction->setCoordinates(direction.x(),direction.y(),direction.z());
        this->touchGeometry();
    }

    void axlTorus::touchRingRadius(double ringRadius)
    {
        d->ringRadius = ringRadius;
        this->touchGeometry();
    }

    void axlTorus::touchCrossSectionRadius(double crossSectionRadius)
    {
        d->crossSectionRadius = crossSectionRadius;
        this->touchGeometry();
    }

axlTorus& axlTorus::operator=(const axlTorus& other) {
    *(d->center) = *(other.d->center);
    *(d->direction) = *(other.d->direction);
    d->ringRadius = other.d->ringRadius;
    d->crossSectionRadius = other.d->crossSectionRadius;

    return (*this);
}

QDebug operator<<(QDebug dbg, axlTorus torus) {
    dbg.nospace() << torus.description();
    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlTorus& torus) {
    dbg.nospace() << torus.description();
    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlTorus* torus) {
    dbg.nospace() << torus->description();
    return dbg.space();
}

void axlTorus::onCenterChanged(axlPoint *center) {
    *(d->center) = *center;
    this->touchGeometry();
}

void axlTorus::onDirectionChanged(axlPoint *direction) {
    *(d->direction) = *direction;
    this->touchGeometry();
}

void axlTorus::onRingRadiusChanged(double ringRadius) {
    d->ringRadius = ringRadius;
    this->touchGeometry();
}

void axlTorus::onCrossSectionRadiusChanged(double crossSectionRadius) {
    d->crossSectionRadius = crossSectionRadius;
    this->touchGeometry();
}

QVariantList axlTorus::convertDataToQVariant(void) const{
    QVariantList list;
    QVariant id = QVariant::fromValue(identifier());
    QVariant crossSectionRadius = QVariant::fromValue(d->crossSectionRadius);
    QVariant ringRadius = QVariant::fromValue(d->ringRadius);
    QVariantList center = d->center->convertDataToQVariant();
    QVariantList direction = d->direction->convertDataToQVariant();
    list.append(id);
    list.append(center);
    list.append(direction);
    list.append(crossSectionRadius);
    list.append(ringRadius);
    QVariant name = QVariant::fromValue(objectName());
    list.append(name);
    return list;

}

int axlTorus::convertQVariantToData(const QVariantList &data){
    QVariantList center;
    center.append(data.at(1));
    center.append(data.at(2));
    center.append(data.at(3));
    center.append(data.at(4));
    center.append(data.at(5));
    d->center->convertQVariantToData(center);
    QVariantList direction;
    direction.append(data.at(6));
    direction.append(data.at(7));
    direction.append(data.at(8));
    direction.append(data.at(9));
    direction.append(data.at(10));
    d->direction->convertQVariantToData(direction);
    setCrossSectionRadius(data.at(11).toDouble());
    setRingRadius(data.at(12).toDouble());
    setObjectName(data.last().toString());
    return 1;
}
//to be registered to the data factory.
dtkAbstractData *createaxlTorus(void)
{
    return new axlTorus;
}
