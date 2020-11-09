/* axlCircleArc.cpp ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008 - Valentin Michelet, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:09:38 2010 (+0100)
 *           By: Valentin Michelet
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlCircleArc.h"

#include "axlPoint.h"

#include <dtkCoreSupport/dtkGlobal.h>


// /////////////////////////////////////////////////////////////////
// axlCircleArcPrivate
// /////////////////////////////////////////////////////////////////

class axlCircleArcPrivate {
public:
    axlPoint point1;
    axlPoint point2;
    axlPoint normal;
    axlPoint center;

    bool direct;
};

// /////////////////////////////////////////////////////////////////
// axlCircleArc implementation
// /////////////////////////////////////////////////////////////////

axlCircleArc::axlCircleArc(QObject *parent) :
    axlAbstractCurveParametric(),
    d(new axlCircleArcPrivate) {

    this->setObjectName(this->identifier());

    d->point1 = axlPoint();
    d->point2 = axlPoint();
    d->center = axlPoint();
    d->normal = axlPoint();

    d->direct = true;
}

axlCircleArc::axlCircleArc(const axlPoint& point1, const axlPoint& point2, const axlPoint& center, const axlPoint& normal, bool direct) :
    axlAbstractCurveParametric(),
    d(new axlCircleArcPrivate) {

    this->setObjectName(this->identifier());

    d->point1 = axlPoint(point1);
    d->point2 = axlPoint(point2);
    d->center = axlPoint(center);
    d->normal = axlPoint(normal);

    d->direct = direct;

    calculateRadius();
}

axlCircleArc::axlCircleArc(const axlCircleArc& other) :
    axlAbstractCurveParametric(),
    d(new axlCircleArcPrivate) {

    this->setObjectName(this->identifier());
    this->setParent(other.parent());
    d->point1 = other.d->point1;
    d->point2 = other.d->point2;
    d->center = other.d->center;
    d->normal = other.d->normal;

    d->direct = other.d->direct;
}

axlCircleArc::~axlCircleArc(void) {
    delete d;
    d = NULL;
}

QString axlCircleArc::description(void) const {
    QString res = "axlCircleArc";
    res.append("\nPoint1: " + d->point1.description());
    res.append("\nPoint2: " + d->point2.description());
    res.append("\nNormal: " + d->normal.description());
    res.append("\nCenter: " + d->center.description());
    res.append("\nDirect: " + QString::number(d->direct));
    res.append("\nRadius: " + QString::number(calculateRadius()));
    return res;
}

QString axlCircleArc::identifier(void) const {
    return "axlCircleArc";
}

double axlCircleArc::calculateRadius(void) const {
    return axlPoint::distance(d->point1, d->center);
}

axlPoint axlCircleArc::calculateNormal(void) const {
    int direct = -1;
    if (d->direct)
        direct = 1;
    return axlPoint::crossProduct(d->point1-d->center, d->point2-d->center) * direct;
}

axlPoint axlCircleArc::point1(void) const {
    return d->point1;
}

axlPoint axlCircleArc::point2(void) const {
    return d->point2;
}

axlPoint axlCircleArc::normal(void) const {
    return d->normal;
}

axlPoint axlCircleArc::center(void) const {
    return d->center;
}

bool axlCircleArc::isDirect(void) const {
    return d->direct;
}

void axlCircleArc::setValues(const axlPoint& point1, const axlPoint& point2, const axlPoint& center, const axlPoint& normal, bool direct) {
    d->point1 = point1;
    d->point2 = point2;
    d->center = center;
    d->normal = normal;

    d->direct = direct;
    axlPoint newNormal = calculateNormal().normalized();
    if (newNormal.norm() > 0.001)
        setNormal(newNormal);
}

void axlCircleArc::setPoint1(const axlPoint& point1) {
    d->point1 = point1;
}

void axlCircleArc::setPoint2(const axlPoint& point2) {
    d->point2 = point2;
}

void axlCircleArc::setCenter(const axlPoint& center) {
    d->center = center;
}

void axlCircleArc::setNormal(const axlPoint& normal) {
    d->normal = normal;
}

void axlCircleArc::setDirect(bool direct) {
    d->direct = direct;
}

void axlCircleArc::modifyPoint1(double* point1) {
    d->point1.coordinates()[0] = point1[0];
    d->point1.coordinates()[1] = point1[1];
    d->point1.coordinates()[2] = point1[2];
}

void axlCircleArc::modifyPoint2(double* point2) {
    d->point2.coordinates()[0] = point2[0];
    d->point2.coordinates()[1] = point2[1];
    d->point2.coordinates()[2] = point2[2];
}

void axlCircleArc::modifyCenter(double *center) {
    d->center.coordinates()[0] = center[0];
    d->center.coordinates()[1] = center[1];
    d->center.coordinates()[2] = center[2];
}

void axlCircleArc::modifyNormal(double* normal) {
    d->normal.coordinates()[0] = normal[0];
    d->normal.coordinates()[1] = normal[1];
    d->normal.coordinates()[2] = normal[2];
}

axlCircleArc& axlCircleArc::operator=(const axlCircleArc& other) {
    d->point1 = other.d->point1;
    d->point2 = other.d->point2;
    d->normal = other.d->normal;
    d->center = other.d->center;

    d->direct = other.d->direct;

    return (*this);
}

QDebug operator<<(QDebug dbg, axlCircleArc arc) {
    dbg.nospace() << arc.description();
    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlCircleArc& arc) {
    dbg.nospace() << arc.description();
    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlCircleArc* arc) {
    dbg.nospace() << arc->description();
    return dbg.space();
}

void axlCircleArc::applyMatrix(double* matrix) {
    d->point1.transformAsPoint(matrix);
    d->point2.transformAsPoint(matrix);
    d->center.transformAsPoint(matrix);
    d->normal.transformAsVector(matrix);
}

void axlCircleArc::onPoint1XChanged(double x) {
    d->point1.x() = x;
}

void axlCircleArc::onPoint1YChanged(double y) {
    d->point1.y() = y;
}

void axlCircleArc::onPoint1ZChanged(double z) {
    d->point1.z() = z;
}

void axlCircleArc::onPoint2XChanged(double x) {
    d->point2.x() = x;
}

void axlCircleArc::onPoint2YChanged(double y) {
    d->point2.y() = y;
}

void axlCircleArc::onPoint2ZChanged(double z) {
    d->point2.z() = z;
}

void axlCircleArc::onCenterXChanged(double x) {
    d->center.x() = x;
}

void axlCircleArc::onCenterYChanged(double y) {
    d->center.y() = y;
}

void axlCircleArc::onCenterZChanged(double z) {
    d->center.z() = z;
}

void axlCircleArc::onNormalXChanged(double x) {
    d->normal.x() = x;
}

void axlCircleArc::onNormalYChanged(double y) {
    d->normal.y() = y;
}

void axlCircleArc::onNormalZChanged(double z) {
    d->normal.z() = z;
}

void axlCircleArc::onDirectChanged(bool direct) {
    d->direct = direct;
    axlPoint newNormal = calculateNormal().normalized();
    if (newNormal.norm() > 0.001)
        setNormal(newNormal);
}

QVariantList axlCircleArc::convertDataToQVariant(void) const{
    QVariantList list;
    QVariant id = QVariant::fromValue(identifier());
    QVariant direct = QVariant::fromValue(d->direct);
    QVariantList center = d->center.convertDataToQVariant();
    QVariantList point1 = d->point1.convertDataToQVariant();
    QVariantList point2 = d->point2.convertDataToQVariant();
    QVariantList normal = d->normal.convertDataToQVariant();
    list.append(id);
    list.append(center);
    list.append(point1);
    list.append(point2);
    list.append(normal);
    list.append(direct);
    QVariant name = QVariant::fromValue(objectName());
    list.append(name);
    return list;

}

int axlCircleArc::convertQVariantToData(const QVariantList& data){
    QVariantList center;
    center.append(data.at(1));
    center.append(data.at(2));
    center.append(data.at(3));
    center.append(data.at(4));
    center.append(data.at(5));
    d->center.convertQVariantToData(center);
    QVariantList point1;
    point1.append(data.at(6));
    point1.append(data.at(7));
    point1.append(data.at(8));
    point1.append(data.at(9));
    point1.append(data.at(10));
    d->point1.convertQVariantToData(point1);
    QVariantList point2;
    point2.append(data.at(11));
    point2.append(data.at(12));
    point2.append(data.at(13));
    point2.append(data.at(14));
    point2.append(data.at(15));
    d->point2.convertQVariantToData(point2);
    QVariantList normal;
    normal.append(data.at(16));
    normal.append(data.at(17));
    normal.append(data.at(18));
    normal.append(data.at(19));
    normal.append(data.at(20));
    d->normal.convertQVariantToData(normal);
    setDirect(data.at(21).toBool());
    setObjectName(data.last().toString());
    return 1;
}

//to be registered to the data factory.
dtkAbstractData *createaxlCircleArc(void)
{
    return new axlCircleArc;
}
