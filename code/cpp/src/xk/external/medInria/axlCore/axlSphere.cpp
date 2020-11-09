/* axlSphere.cpp ---
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

#include "axlSphere.h"

#include <dtkCoreSupport/dtkGlobal.h>

// /////////////////////////////////////////////////////////////////
// axlSpherePrivate
// /////////////////////////////////////////////////////////////////

class axlSpherePrivate
{
public:
    double coordinates[3];
    double radius;

};

// /////////////////////////////////////////////////////////////////
// axlSphere implementation
// /////////////////////////////////////////////////////////////////

//! Constructs a axel sphere of zero coordinates and 1.0 radius with parent \a parent of QObject type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel sphere with no parent.
 */
axlSphere::axlSphere(QObject *parent) : axlAbstractData(), d(new axlSpherePrivate)
{
    this->setObjectName(this->identifier());
    d->coordinates[0] = 0.0;
    d->coordinates[1] = 0.0;
    d->coordinates[2] = 0.0;
    d->radius = 1.0;
}

//! Constructs a axel sphere of coordinates (\a x, \a y, \a z) and radius (\a radius) with parent \a parent of QObject type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel sphere with no parent.
 */
axlSphere::axlSphere(double x, double y, double z, double radius, QObject *parent) : axlAbstractData(), d(new axlSpherePrivate)
{
    this->setObjectName(this->identifier());
    d->coordinates[0] = x;
    d->coordinates[1] = y;
    d->coordinates[2] = z;
    d->radius = radius;

}

//! Constructs a copy of \a other.
/*!
 *
 */
axlSphere::axlSphere(const axlSphere& other) : axlAbstractData(), d(new axlSpherePrivate)
{
    this->setObjectName(this->identifier());
    this->setParent(other.parent());
    d->coordinates[0] = other.d->coordinates[0];
    d->coordinates[1] = other.d->coordinates[1];
    d->coordinates[2] = other.d->coordinates[2];
    d->radius = other.d->radius;

}

//! Destroys the axel sphere.
/*!
 *
 */
axlSphere::~axlSphere(void)
{
    delete d;

    d = NULL;
}

//! Assigns other to this sphere and returns a reference to this sphere.
/*!
 *
 */
axlSphere& axlSphere::operator=(const axlSphere& other)
{
    d->coordinates[0] = other.d->coordinates[0];
    d->coordinates[1] = other.d->coordinates[1];
    d->coordinates[2] = other.d->coordinates[2];
    d->radius = other.d->radius;

    return (*this);
}

//! Adds the coordinates and radius of the other sphere to this sphere and returns a reference to this sphere.
/*!
 *
 */
axlSphere& axlSphere::operator+=(const axlSphere& other)
{
    d->coordinates[0] += other.d->coordinates[0];
    d->coordinates[1] += other.d->coordinates[1];
    d->coordinates[2] += other.d->coordinates[2];
    d->radius += other.d->radius;

    return (*this);
}

//! Substracts the coordinates and radius of the other sphere to this sphere and returns a reference to this sphere.
/*!
 *
 */
axlSphere& axlSphere::operator-=(const axlSphere& other)
{
    d->coordinates[0] -= other.d->coordinates[0];
    d->coordinates[1] -= other.d->coordinates[1];
    d->coordinates[2] -= other.d->coordinates[2];
    d->radius -= other.d->radius;

    return (*this);
}

//! Multiplies the coordinates and radius of this sphere by a scalar value and returns a reference to this sphere.
/*!
 *
 */
axlSphere& axlSphere::operator*=(double scalar)
{
    d->coordinates[0] *= scalar;
    d->coordinates[1] *= scalar;
    d->coordinates[2] *= scalar;
    d->radius *= scalar;

    return (*this);
}

//! Divides the coordinates and radius of this sphere by a scalar value and returns a reference to this sphere.
/*!
 *  If the scalar value is zero, the sphere remains unchanged.
 */
axlSphere& axlSphere::operator/=(double scalar)
{
    if(!(scalar != 0.)) {
        qWarning() << DTK_PRETTY_FUNCTION << "Preventing division by 0. Operand not affected.";
        return (*this);
    }

    d->coordinates[0] /= scalar;
    d->coordinates[1] /= scalar;
    d->coordinates[2] /= scalar;
    d->radius /= scalar;

    return (*this);
}

//! Returns a sphere that results from the addition of this sphere and the other sphere.
/*!
 *
 */
axlSphere axlSphere::operator+(const axlSphere& other) const
{
    axlSphere result(d->coordinates[0] + other.d->coordinates[0],
                    d->coordinates[1] + other.d->coordinates[1],
                    d->coordinates[2] + other.d->coordinates[2],
                    d->radius + other.d->radius);
    return result;
}

//! Returns a sphere that results from the substraction of this sphere and the other sphere.
/*!
 *
 */
axlSphere axlSphere::operator-(const axlSphere& other) const
{
    axlSphere result(d->coordinates[0] - other.d->coordinates[0],
                    d->coordinates[1] - other.d->coordinates[1],
                    d->coordinates[2] - other.d->coordinates[2],
                    d->radius - other.d->radius);
    return result;
}

//! Returns a sphere that results from the multiplication of the scalar with this sphere.
/*!
 *
 */
axlSphere axlSphere::operator*(double scalar) const
{
    axlSphere result(d->coordinates[0] * scalar,
                    d->coordinates[1] * scalar,
                    d->coordinates[2] * scalar,
                    d->radius * scalar);
    return result;
}

//! Returns a sphere that results from the division of the scalar with this sphere.
/*!
 *  If the scalar value is zero, it returns a default sphere.
 */
axlSphere axlSphere::operator/(double scalar) const
{
    if(!(scalar != 0.)) {
        qWarning() << DTK_PRETTY_FUNCTION << "Preventing division by 0. Returning default sphere";
        return axlSphere();
    }

    axlSphere result(d->coordinates[0] / scalar,
                    d->coordinates[1] / scalar,
                    d->coordinates[2] / scalar,
                    d->radius / scalar);

    return result;
}

//! Returns x-coordinate of this sphere.
/*!
 *
 */
double axlSphere::x(void) const
{
    return d->coordinates[0];
}

//! Returns y-coordinate of this sphere.
/*!
 *
 */
double axlSphere::y(void) const
{
    return d->coordinates[1];
}

//! Returns z-coordinate of this sphere.
/*!
 *
 */
double axlSphere::z(void) const
{
    return d->coordinates[2];
}

double axlSphere::radius(void) const
{
    return d->radius;
}

void axlSphere::setRadius(double radius)
{
    d->radius = radius;
//    this->touchGeometry();
}

void axlSphere::touchRadius(double radius)
{
    d->radius = radius;
    this->touchGeometry();
}

void axlSphere::touchCenter(axlPoint center)
{
    d->coordinates[0] = center.x();
    d->coordinates[1] = center.y();
    d->coordinates[2] = center.z();

    this->touchGeometry();
}

axlPoint axlSphere::centerPoint(void)
{
    axlPoint center(d->coordinates);
//    return (new axlPoint(d->coordinates));
    return center;
}
//! Change coordinates of this sphere.
/*!
 *
 */
void axlSphere::setValues(double x, double y, double z, double radius)
{
    d->coordinates[0] = x;
    d->coordinates[1] = y;
    d->coordinates[2] = z;
    d->radius = radius;
    this->touchGeometry();
}

void axlSphere::setCenter(double x, double y, double z)
{
    d->coordinates[0] = x;
    d->coordinates[1] = y;
    d->coordinates[2] = z;
    this->touchGeometry();
}

void axlSphere::normalize()
{
    double norm = sqrt(d->coordinates[0] * d->coordinates[0] + d->coordinates[1] * d->coordinates[1] + d->coordinates[2] * d->coordinates[2]);
    d->coordinates[0] /= norm;
    d->coordinates[1] /= norm;
    d->coordinates[2] /= norm;
    d->radius /= norm;
}



//! Returns coordinates of this sphere.
/*!
 *
 */
double *axlSphere::coordinates(void) const
{
    return d->coordinates ;
}

//! Returns the distance between \a lhs sphere and \a rhs sphere.
/*!
 *  The distance is always positive.
 */
double axlSphere::distance(const axlSphere& lhs, const axlSphere& rhs)
{
    double dx = rhs.d->coordinates[0] - lhs.d->coordinates[0];
    double dy = rhs.d->coordinates[1] - lhs.d->coordinates[1];
    double dz = rhs.d->coordinates[2] - lhs.d->coordinates[2];

    return qSqrt(dx*dx + dy*dy + dz*dz);
}

//! Returns the distance between \a lhs sphere and \a rhs sphere.
/*!
 *  The distance is always positive.
 */
double axlSphere::distance(axlSphere *lhs, axlSphere *rhs)
{
    double dx = rhs->d->coordinates[0] - lhs->d->coordinates[0];
    double dy = rhs->d->coordinates[1] - lhs->d->coordinates[1];
    double dz = rhs->d->coordinates[2] - lhs->d->coordinates[2];

    return qSqrt(dx*dx + dy*dy + dz*dz);
}


// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlSphere sphere)
{
    dbg.nospace() << QString("axlSphere: center: (%1, %2, %3) radius : (%4)").arg(sphere.x()).arg(sphere.y()).arg(sphere.z()).arg(sphere.radius());

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlSphere& sphere)
{
    dbg.nospace() << QString("axlSphere: center: (%1, %2, %3) radius : (%4)").arg(sphere.x()).arg(sphere.y()).arg(sphere.z()).arg(sphere.radius());

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlSphere *sphere)
{
    dbg.nospace() << QString("axlSphere: center: (%1, %2, %3) radius : (%4)").arg(sphere->x()).arg(sphere->y()).arg(sphere->z()).arg(sphere->radius());

    return dbg.space();
}

QString axlSphere::description(void) const
{
    QString result = "axlSphere";
    result.append("\nX : "+QString::number(d->coordinates[0]) + "\nY : "+QString::number(d->coordinates[1]) + "\nZ : "+QString::number(d->coordinates[2]) + "\nRadius : "+QString::number(d->radius));
    return result;
}

QString axlSphere::identifier(void) const
{
    return "axlSphere";
}

//void axlSphere::emitDataChanged(void)
//{
//    emit dataChanged();
//}

//SLOT
void axlSphere::onXChanged(double x)
{
    d->coordinates[0] = x;
}

void axlSphere::onYChanged(double y)
{
    d->coordinates[1] = y;
}

void axlSphere::onZChanged(double z)
{
    d->coordinates[2] = z;
}

void axlSphere::onRadiusChanged(double radius)
{
    d->radius = radius;
}


QVariantList axlSphere::convertDataToQVariant(void) const{
    QVariantList list;
    QVariant id = QVariant::fromValue(identifier());
    QVariant xcenter = QVariant::fromValue(d->coordinates[0]);
    QVariant ycenter = QVariant::fromValue(d->coordinates[1]);
    QVariant zcenter = QVariant::fromValue(d->coordinates[2]);
    QVariant radius = QVariant::fromValue(d->radius);
    list.append(id);
    list.append(xcenter);
    list.append(ycenter);
    list.append(zcenter);
    list.append(radius);
    QVariant name = QVariant::fromValue(objectName());
    list.append(name);
    return list;

}

int axlSphere::convertQVariantToData(const QVariantList &data){
    setCenter(data.at(1).toDouble(), data.at(2).toDouble(), data.at(3).toDouble());
    setRadius(data.at(4).toDouble());
    setObjectName(data.last().toString());
    return 1;
}

//to be registered to the data factory.
dtkAbstractData *createaxlSphere(void)
{
    return new axlSphere;
}


// /////////////////////////////////////////////////////////////////
// axlSphere documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlSphere
 *
 *  \brief Class axlSphere defines 3D spheres.
 *
 *  This class enables to represent and manipulate 3D spheres.
 *
 *  Example:
 *  \code
 *  axlSphere *A = new axlSphere(0.0, 0.0, 0.0);
 *  axlSphere *B = new axlSphere(1.0, 0.0, 0.0);
 *  double length = axlSphere::distance(A, B);
 *  axlSphere middle = *(A);
 *  middle += *(B);
 *  middle /= 2.;
 *  \endcode
 */
