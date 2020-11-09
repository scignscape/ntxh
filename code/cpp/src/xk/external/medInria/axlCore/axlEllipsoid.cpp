/* axlEllipsoid.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:09:38 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlEllipsoid.h"

#include "axlPoint.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkMathSupport/dtkQuaternion.h>

// /////////////////////////////////////////////////////////////////
// axlEllipsoidPrivate
// /////////////////////////////////////////////////////////////////

class axlEllipsoidPrivate
{
public:
    axlPoint *center;
    axlPoint *semiX;
    axlPoint *semiY;
    axlPoint *semiZ;
};

// /////////////////////////////////////////////////////////////////
// axlEllipsoid implementation
// /////////////////////////////////////////////////////////////////

//! Constructs a axel ellipsoid of with firstPoint and second point are NULL and 1.0 radius with parent \a parent of QObject type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel ellipsoid with no parent.
 */
axlEllipsoid::axlEllipsoid(QObject *parent) : axlAbstractData(), d(new axlEllipsoidPrivate)
{
    this->setObjectName(this->identifier());

    d->center = new axlPoint();
    d->semiX = new axlPoint(1.0, 0.0, 0.0);
    d->semiY = new axlPoint(0.0, 1.0, 0.0);
    d->semiZ = new axlPoint(0.0, 0.0, 1.0);
}

//! Constructs a axel ellipsoid of two axlPoint \a center \a p2 and radius \a radius with parent \a parent of QObject type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel point with no parent.
 */
axlEllipsoid::axlEllipsoid(axlPoint *center, axlPoint *semiX, axlPoint *semiY, axlPoint *semiZ, QObject *parent) : axlAbstractData(), d(new axlEllipsoidPrivate)
{
    this->setObjectName(this->identifier());

    d->center = new axlPoint(center);
    d->semiX = new axlPoint(semiX);
    d->semiY = new axlPoint(semiY);
    d->semiZ = new axlPoint(semiZ);
}

//! Constructs a axel ellipsoid from two axlPoint \a center \a p2 and radius \a radius with parent \a parent.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel point with no parent.
 */
axlEllipsoid::axlEllipsoid(const axlPoint& center, const axlPoint& semiX, const axlPoint& semiY, const axlPoint& semiZ, QObject *parent) : axlAbstractData(), d(new axlEllipsoidPrivate)
{
    this->setObjectName(this->identifier());

    d->center =new axlPoint(center);
    d->semiX = new axlPoint(semiX);
    d->semiY = new axlPoint(semiY);
    d->semiZ = new axlPoint(semiZ);
}

//! Constructs a copy of \a other with same axlPoints.
/*!
 *
 */
axlEllipsoid::axlEllipsoid(const axlEllipsoid& other) : axlAbstractData(), d(new axlEllipsoidPrivate)
{
    this->setObjectName(this->identifier());
    this->setParent(other.parent());

    d->center = new axlPoint(other.d->center);
    d->semiX = new axlPoint(other.d->semiX);
    d->semiY = new axlPoint(other.d->semiY);
    d->semiZ = new axlPoint(other.d->semiZ);
}

//! Destroys the axel ellipsoid.
/*!
 *
 */
axlEllipsoid::~axlEllipsoid(void)
{
    if (d->center) {
        delete d->center;
        d->center = NULL;
    }

    if (d->semiX) {
        delete d->semiX;
        d->semiX = NULL;
    }

    if (d->semiY) {
        delete d->semiY;
        d->semiY = NULL;
    }

    if (d->semiZ) {
        delete d->semiZ;
        d->semiZ = NULL;
    }

    delete d;

    d = NULL;
}

//! Assigns other to this ellipsoid and returns a reference to this ellipsoid.
/*!
 *
 */
axlEllipsoid& axlEllipsoid::operator=(const axlEllipsoid& other)
{
    *(d->center) = *(other.d->center);
    *(d->semiX) = *(other.d->semiX);
    *(d->semiY) = *(other.d->semiY);
    *(d->semiZ) = *(other.d->semiZ);

    return (*this);
}

//! Returns center of the ellipsoid.
/*!
 *
 */
axlPoint *axlEllipsoid::center(void) const
{
    return d->center;
}

//! Returns semi x axe value of the ellipsoid.
/*!
 *
 */
axlPoint *axlEllipsoid::semiX(void) const
{
    return d->semiX;
}

//! Returns semi y axe value of the ellipsoid.
/*!
 *
 */
axlPoint *axlEllipsoid::semiY(void) const
{
    return d->semiY;
}

//! Returns semi z axe value of the ellipsoid.
/*!
 *
 */
axlPoint *axlEllipsoid::semiZ(void) const
{
    return d->semiZ;
}

//! Change center, semi axes x, y, z values and quarternion of this ellipsoid.
/*!
 *
 */
void axlEllipsoid::setValues(axlPoint *center, axlPoint *semiX, axlPoint *semiY, axlPoint *semiZ)
{
    *(d->center) = *center;
    *(d->semiX) = *semiX;
    *(d->semiY) = *semiY;
    *(d->semiZ) = *semiZ;

    //this->touchGeometry();
}

//! Change center of this ellipsoid.
/*!
 *
 */
void axlEllipsoid::setCenter(axlPoint *center)
{
    *(d->center) = *center;

    //this->touchGeometry();
}

//! Change semi axes x value of this ellipsoid.
/*!
 *
 */
void axlEllipsoid::setSemiX(axlPoint *semiX)
{
    *(d->semiX) = *semiX;

    //this->touchGeometry();
}

//! Change semi axes y value of this ellipsoid.
/*!
 *
 */
void axlEllipsoid::setSemiY(axlPoint *semiY)
{
    *(d->semiY) = *semiY;

    //this->touchGeometry();
}

//! Change semi axes z value of this ellipsoid.
/*!
 *
 */
void axlEllipsoid::setSemiZ(axlPoint *semiZ)
{
    *(d->semiZ) = *semiZ;

    //this->touchGeometry();
}

void axlEllipsoid::touchCenter(axlPoint center)
{
    d->center->setCoordinates(center.x(),center.y(),center.z());
    this->touchGeometry();
}

void axlEllipsoid::touchSemiX(axlPoint semiX)
{
    d->semiX->setCoordinates(semiX.x(),semiX.y(),semiX.z());
    this->touchGeometry();
}

void axlEllipsoid::touchSemiY(axlPoint semiY)
{
    d->semiY->setCoordinates(semiY.x(),semiY.y(),semiY.z());
    this->touchGeometry();
}

void axlEllipsoid::touchSemiZ(axlPoint semiZ)
{
    d->semiZ->setCoordinates(semiZ.x(),semiZ.y(),semiZ.z());
    this->touchGeometry();
}

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlEllipsoid ellipsoid)
{
    dbg.nospace() << ellipsoid.description();

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlEllipsoid& ellipsoid)
{
    dbg.nospace() << ellipsoid.description();

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlEllipsoid *ellipsoid)
{
    dbg.nospace() << ellipsoid->description();

    return dbg.space();
}

QString axlEllipsoid::description(void) const
{
    QString result = "axlEllipsoid";

    result.append("\ncenter : "+d->center->description()
                  + "\nsemi axes X value : "+d->semiX->description()
                  + "\nsemi axes Y value : "+d->semiY->description()
                  + "\nsemi axes Z value : "+d->semiZ->description());

    return result;
}

QString axlEllipsoid::identifier(void) const
{
    return "axlEllipsoid";
}

//SLOT
void axlEllipsoid::onCenterChanged(axlPoint *center)
{
    *(d->center) = *center;
    this->touchGeometry();
}

void axlEllipsoid::onSemiXChanged(axlPoint *semiX)
{
    *(d->semiX) = *semiX;
    this->touchGeometry();
}

void axlEllipsoid::onSemiYChanged(axlPoint *semiY)
{
    *(d->semiY) = *semiY;
    this->touchGeometry();
}

void axlEllipsoid::onSemiZChanged(axlPoint *semiZ)
{
    *(d->semiZ) = *semiZ;
    this->touchGeometry();
}

//! modify Center of this Ellipsoid.
/*!
 *
 */
void axlEllipsoid::modifyCenter(double *center)
{
    d->center->setCoordinates(center[0], center[1], center[2]);
    this->touchGeometry();
}

//! modify X Center value of this Ellipsoid.
/*!
 *
 */
void axlEllipsoid::modifyCenterX(double x)
{
    d->center->coordinates()[0] = x;
    this->touchGeometry();
}

//! modify Y Center value of this Ellipsoid.
/*!
 *
 */
void axlEllipsoid::modifyCenterY(double y)
{
    d->center->coordinates()[1] = y;
    this->touchGeometry();
}

//! modify Z Center value of this Ellipsoid.
/*!
 *
 */
void axlEllipsoid::modifyCenterZ(double z)
{
    d->center->coordinates()[2] = z;
    this->touchGeometry();
}

//! modify SemiX of this Ellipsoid.
/*!
 *
 */
void axlEllipsoid::modifySemiX(double *semiX)
{
    d->semiX->setCoordinates(semiX[0], semiX[1], semiX[2]);
    this->touchGeometry();
}

//! modify X SemiX value of this Ellipsoid.
/*!
 *
 */
void axlEllipsoid::modifySemiXX(double x)
{
    d->semiX->coordinates()[0] = x;
    this->touchGeometry();
}

//! modify Y SemiX value of this Ellipsoid.
/*!
 *
 */
void axlEllipsoid::modifySemiXY(double y)
{
    d->semiX->coordinates()[1] = y;
    this->touchGeometry();
}

//! modify Z SemiX value of this Ellipsoid.
/*!
 *
 */
void axlEllipsoid::modifySemiXZ(double z)
{
    d->semiX->coordinates()[2] = z;
    this->touchGeometry();
}

//! modify SemiY of this Ellipsoid.
/*!
 *
 */
void axlEllipsoid::modifySemiY(double *semiY)
{
    d->semiY->setCoordinates(semiY[0], semiY[1], semiY[2]);
    this->touchGeometry();
}

//! modify X SemiY value of this Ellipsoid.
/*!
 *
 */
void axlEllipsoid::modifySemiYX(double x)
{
    d->semiY->coordinates()[0] = x;

    this->touchGeometry();
}

//! modify Y SemiY value of this Ellipsoid.
/*!
 *
 */
void axlEllipsoid::modifySemiYY(double y)
{
    d->semiY->coordinates()[1] = y;
    this->touchGeometry();
}

//! modify Z SemiY value of this Ellipsoid.
/*!
 *
 */
void axlEllipsoid::modifySemiYZ(double z)
{
    d->semiY->coordinates()[2] = z;
    this->touchGeometry();
}

//! modify SemiZ of this Ellipsoid.
/*!
 *
 */
void axlEllipsoid::modifySemiZ(double *semiZ)
{
    d->semiZ->setCoordinates(semiZ[0], semiZ[1], semiZ[2]);
    this->touchGeometry();
}

//! modify X SemiZ value of this Ellipsoid.
/*!
 *
 */
void axlEllipsoid::modifySemiZX(double x)
{
    d->semiZ->coordinates()[0] = x;

    this->touchGeometry();
}

//! modify Y SemiZ value of this Ellipsoid.
/*!
 *
 */
void axlEllipsoid::modifySemiZY(double y)
{
    d->semiZ->coordinates()[1] = y;

    this->touchGeometry();
}

//! modify Z SemiZ value of this Ellipsoid.
/*!
 *
 */
void axlEllipsoid::modifySemiZZ(double z)
{
    d->semiZ->coordinates()[2] = z;

    this->touchGeometry();
}

void axlEllipsoid::calculateYZ(void)
{
    axlPoint semix(d->semiX->coordinates());
    axlPoint startSemix(semix);

    semix.normalize();

    axlPoint semiy(d->semiY->coordinates());
    double semiyRadius = semiy.norm();

    semiy.normalize();

    axlPoint semiz(d->semiZ->coordinates());
    double semizRadius = semiz.norm();

    semiz.normalize();

    if (semix.norm() < 0.001) {
        axlPoint pv = axlPoint::crossProduct(semiy, semiz);
        if (pv.norm() < 0.001) {
            return;
        } else {
            semix = pv;
            semix.normalize();
            semiy = axlPoint::crossProduct(semiz, semix);
            semiy.normalize();
        }
    } else {
        axlPoint pv = axlPoint::crossProduct(semix, semiy);
        if (pv.norm() < 0.001) {
            pv = axlPoint::crossProduct(semiz, semix);
            if (pv.norm() < 0.001) {
                return;
            } else {
                semiy = pv;
                semiy.normalize();
                semiz = axlPoint::crossProduct(semix, semiy);
                semiz.normalize();
            }
        } else {
            semiz = pv;
            semiz.normalize();
            semiy = axlPoint::crossProduct(semiz, semix);
            semiy.normalize();
        }
    }

    modifySemiX(startSemix.coordinates());
    semiy *= semiyRadius;
    modifySemiY(semiy.coordinates());
    semiz *= semizRadius;
    modifySemiZ(semiz.coordinates());
}

void axlEllipsoid::calculateXZ(void)
{
    axlPoint semix(d->semiX->coordinates());
    double semixRadius = semix.norm();

    semix.normalize();

    axlPoint semiy(d->semiY->coordinates());
    axlPoint startSemiy(semiy);

    semiy.normalize();

    axlPoint semiz(d->semiZ->coordinates());
    double semizRadius = semiz.norm();

    semiz.normalize();

    if (semiy.norm() < 0.001) {
        axlPoint pv = axlPoint::crossProduct(semiz, semix);
        if (pv.norm() < 0.001) {
            return;
        } else {
            semiy = pv;
            semiy.normalize();
            semiz = axlPoint::crossProduct(semix, semiy);
            semiz.normalize();
        }
    } else {
        axlPoint pv = axlPoint::crossProduct(semiy, semiz);
        if (pv.norm() < 0.001) {
            pv = axlPoint::crossProduct(semix, semiy);
            if (pv.norm() < 0.001) {
                return;
            } else {
                semiz = pv;
                semiz.normalize();
                semix = axlPoint::crossProduct(semiy, semiz);
                semix.normalize();
            }
        } else {
            semix = pv;
            semix.normalize();
            semiz = axlPoint::crossProduct(semix, semiy);
            semiz.normalize();
        }
    }

    semix *= semixRadius;
    modifySemiX(semix.coordinates());
    modifySemiY(startSemiy.coordinates());
    semiz *= semizRadius;
    modifySemiZ(semiz.coordinates());
}

void axlEllipsoid::calculateXY(void)
{
    axlPoint semix(d->semiX->coordinates());
    double semixRadius = semix.norm();

    semix.normalize();

    axlPoint semiy(d->semiY->coordinates());
    double semiyRadius = semiy.norm();

    semiy.normalize();

    axlPoint semiz(d->semiZ->coordinates());
    axlPoint startSemiz(semiz);

    semiz.normalize();

    if (semiz.norm() < 0.001) {
        axlPoint pv = axlPoint::crossProduct(semix, semiy);
        if (pv.norm() < 0.001) {
            return;
        } else {
            semiz = pv;
            semiz.normalize();
            semix = axlPoint::crossProduct(semiy, semiz);
            semix.normalize();
        }
    } else {
        axlPoint pv = axlPoint::crossProduct(semiz, semix);
        if (pv.norm() < 0.001) {
            pv = axlPoint::crossProduct(semiy, semiz);
            if (pv.norm() < 0.001) {
                return;
            } else {
                semix = pv;
                semix.normalize();
                semiy = axlPoint::crossProduct(semiz, semix);
                semiy.normalize();
            }
        } else {
            semiy = pv;
            semiy.normalize();
            semix = axlPoint::crossProduct(semiy, semiz);
            semix.normalize();
        }
    }

    semix *= semixRadius;
    modifySemiX(semix.coordinates());
    semiy *= semiyRadius;
    modifySemiY(semiy.coordinates());
    modifySemiZ(startSemiz.coordinates());
}

QVariantList axlEllipsoid::convertDataToQVariant(void) const
{
    QVariantList list;
    QVariant id = QVariant::fromValue(identifier());
    QVariantList center = d->center->convertDataToQVariant();
    QVariantList semiX = d->semiX->convertDataToQVariant();
    QVariantList semiY = d->semiY->convertDataToQVariant();
    QVariantList semiZ = d->semiZ->convertDataToQVariant();
    list.append(id);
    list.append(center);
    list.append(semiX);
    list.append(semiY);
    list.append(semiZ);
    QVariant name = QVariant::fromValue(objectName());
    list.append(name);
    return list;
}

int axlEllipsoid::convertQVariantToData(const QVariantList &data)
{
    QVariantList center;
    center.append(data.at(1));
    center.append(data.at(2));
    center.append(data.at(3));
    center.append(data.at(4));
    center.append(data.at(5));
    d->center->convertQVariantToData(center);
    QVariantList semiX;
    semiX.append(data.at(6));
    semiX.append(data.at(7));
    semiX.append(data.at(8));
    semiX.append(data.at(9));
    semiX.append(data.at(10));
    d->semiX->convertQVariantToData(semiX);
    QVariantList semiY;
    semiY.append(data.at(11));
    semiY.append(data.at(12));
    semiY.append(data.at(13));
    semiY.append(data.at(14));
    semiY.append(data.at(15));
    d->semiY->convertQVariantToData(semiY);
    QVariantList semiZ;
    semiZ.append(data.at(16));
    semiZ.append(data.at(17));
    semiZ.append(data.at(18));
    semiZ.append(data.at(19));
    semiZ.append(data.at(20));
    d->semiZ->convertQVariantToData(semiZ);
    setObjectName(data.last().toString());
    return 1;
}

dtkAbstractData *createaxlEllipsoid(void)
{
    return new axlEllipsoid;
}

// /////////////////////////////////////////////////////////////////
// axlEllipsoid documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlEllipsoid
 *
 *  \brief Class axlEllipsoid defines 3D ellipsoids.
 *
 *  This class enables to represent and manipulate 3D ellipsoids.
 *
 *  Example:
 *  \code
 *  axlPoint *center = new axlPoint(0.0, 0.0, 0.0);
 *  axlPoint *semiX = new axlPoint(1.0, 0.0, 0.0);
 *  axlPoint *semiX = new axlPoint(0.0, 1.0, 0.0);
 *  axlPoint *semiX = new axlPoint(0.0, 0.0, 1.0);
 *  axlEllipsoid *A = new axlEllipsoid(center, semiX, semiY, semiZ);
 *  \endcode
 */
