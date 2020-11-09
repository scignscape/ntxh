/* axlPoint.cpp ---
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

#include "axlPoint.h"

#include <dtkCoreSupport/dtkGlobal.h>

// /////////////////////////////////////////////////////////////////
// axlPointPrivate
// /////////////////////////////////////////////////////////////////

class axlPointPrivate
{
public:
    double coordinates[3];

};

// /////////////////////////////////////////////////////////////////
// axlPoint implementation
// /////////////////////////////////////////////////////////////////

//! Constructs an axel point of zero coordinates with parent \a parent of QObject type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel point with no parent.
 */
axlPoint::axlPoint(QObject *parent) : axlAbstractData(), d(new axlPointPrivate)
{
    this->setObjectName(this->identifier());
    d->coordinates[0] = 0.0;
    d->coordinates[1] = 0.0;
    d->coordinates[2] = 0.0;
}

//! Constructs a axel point of coordinates (\a x, \a y, \a z) with parent \a parent of QObject type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel point with no parent.
 */
axlPoint::axlPoint(double x, double y, double z, QObject *parent) : axlAbstractData(), d(new axlPointPrivate)
{
    this->setObjectName(this->identifier());
    d->coordinates[0] = x;
    d->coordinates[1] = y;
    d->coordinates[2] = z;
}

//! Constructs a copy of \a other.
/*!
 *
 */
axlPoint::axlPoint(const axlPoint& other) : axlAbstractData(), d(new axlPointPrivate)
{
    this->setObjectName(this->identifier());
    this->setParent(other.parent());
    d->coordinates[0] = other.d->coordinates[0];
    d->coordinates[1] = other.d->coordinates[1];
    d->coordinates[2] = other.d->coordinates[2];
}

//! Constructs a copy of \a other.
/*!
 *
 */
axlPoint::axlPoint(const axlPoint *other) : axlAbstractData(), d(new axlPointPrivate)
{
    this->setObjectName(this->identifier());
    this->setParent(other->parent());
    d->coordinates[0] = other->d->coordinates[0];
    d->coordinates[1] = other->d->coordinates[1];
    d->coordinates[2] = other->d->coordinates[2];
}


axlPoint::axlPoint(double *p, QObject *parent): d(new axlPointPrivate)
{
    // There is no verification of p;
    this->setObjectName(this->identifier());
    d->coordinates[0] = p[0];
    d->coordinates[1] = p[1];
    d->coordinates[2] = p[2];
}

//! Destroys the axel point.
/*!
 *
 */
axlPoint::~axlPoint(void)
{
    delete d;

    d = NULL;
}

//! Assigns other to this point and returns a reference to this point.
/*!
 *
 */
axlPoint& axlPoint::operator=(const axlPoint& other)
{
    d->coordinates[0] = other.d->coordinates[0];
    d->coordinates[1] = other.d->coordinates[1];
    d->coordinates[2] = other.d->coordinates[2];

    return (*this);
}

//! Adds the coordinates of the other point to this point and returns a reference to this point.
/*!
 *
 */
axlPoint& axlPoint::operator+=(const axlPoint& other)
{
    d->coordinates[0] += other.d->coordinates[0];
    d->coordinates[1] += other.d->coordinates[1];
    d->coordinates[2] += other.d->coordinates[2];

    return (*this);
}

//! Substracts the coordinates of the other point to this point and returns a reference to this point.
/*!
 *
 */
axlPoint& axlPoint::operator-=(const axlPoint& other)
{
    d->coordinates[0] -= other.d->coordinates[0];
    d->coordinates[1] -= other.d->coordinates[1];
    d->coordinates[2] -= other.d->coordinates[2];

    return (*this);
}

//! Multiplies the coordinates of this point by a scalar value and returns a reference to this point.
/*!
 *
 */
axlPoint& axlPoint::operator*=(double scalar)
{
    d->coordinates[0] *= scalar;
    d->coordinates[1] *= scalar;
    d->coordinates[2] *= scalar;

    return (*this);
}

//! Divides the coordinates of this point by a scalar value and returns a reference to this point.
/*!
 *  If the scalar value is zero, the point remains unchanged.
 */
axlPoint& axlPoint::operator/=(double scalar)
{
    if(!(scalar != 0.)) {
        qWarning() << DTK_PRETTY_FUNCTION << "Preventing division by 0. Operand not affected.";
        return (*this);
    }

    d->coordinates[0] /= scalar;
    d->coordinates[1] /= scalar;
    d->coordinates[2] /= scalar;

    return (*this);
}



//! Returns a point that results from the addition of this point and the other point.
/*!
 *
 */
axlPoint axlPoint::operator+(const axlPoint& other) const
{
    axlPoint result(d->coordinates[0] + other.d->coordinates[0],
            d->coordinates[1] + other.d->coordinates[1],
            d->coordinates[2] + other.d->coordinates[2] );
    return result;
}

//! Returns a point that results from the substraction of this point and the other point.
/*!
 *
 */
axlPoint axlPoint::operator-(const axlPoint& other) const
{
    axlPoint result(d->coordinates[0] - other.d->coordinates[0],
            d->coordinates[1] - other.d->coordinates[1],
            d->coordinates[2] - other.d->coordinates[2]);
    return result;
}

//! Returns a point that results from the multiplication of the scalar with this point.
/*!
 *
 */
axlPoint axlPoint::operator*(double scalar) const
{
    axlPoint result(d->coordinates[0] * scalar,
            d->coordinates[1] * scalar,
            d->coordinates[2] * scalar);
    return result;
}

//! Compute the inner product of the two vectors.
/*!
 *
 */
double axlPoint::operator*(const axlPoint& other) const
{
    return (d->coordinates[0] * other[0]
            + d->coordinates[1] * other[1]
            + d->coordinates[2] * other[2]);

}
/** @brief order on axlPoints.
 *  Compare the coordinates (x,y,z) by lexicographic order.
 */
bool axlPoint::operator<(const axlPoint& other) const{
    return  (d->coordinates[0] < other.x()
            || (!(other.x() == d->coordinates[0]) && d->coordinates[1] < other.y())
            || (!(other.x() == d->coordinates[0]) && !(other.y() == d->coordinates[1]) && d->coordinates[2] < other.z()));
}



//! Returns a point that results from the division of the scalar with this point.
/*!
 *  If the scalar value is zero, it returns a default point.
 */
axlPoint axlPoint::operator/(double scalar) const
{
    if(!(scalar != 0.)) {
        qWarning() << DTK_PRETTY_FUNCTION << "Preventing division by 0. Returning default point";
        return axlPoint();
    }

    axlPoint result(d->coordinates[0] / scalar,
            d->coordinates[1] / scalar,
            d->coordinates[2] / scalar);

    return result;
}

//! Multiplication by 3x3 left block (rotation part) and addition with 3x1 right block (translation part)
void axlPoint::transformAsPoint(double matrix[12]) {
    this->setCoordinates(
                d->coordinates[0] * matrix[0] + d->coordinates[1] * matrix[1] + d->coordinates[2] * matrix[2] + matrix[3],
            d->coordinates[0] * matrix[4] + d->coordinates[1] * matrix[5] + d->coordinates[2] * matrix[6] + matrix[7],
            d->coordinates[0] * matrix[8] + d->coordinates[1] * matrix[9] + d->coordinates[2] * matrix[10] + matrix[11]
            );
}

//! Multiplication by 3x3 left block (rotation part) and addition with 3x1 right block (translation part)
void axlPoint::transformAsVector(double matrix[12]) {
    this->setCoordinates(
                d->coordinates[0] * matrix[0] + d->coordinates[1] * matrix[1] + d->coordinates[2] * matrix[2],
            d->coordinates[0] * matrix[4] + d->coordinates[1] * matrix[5] + d->coordinates[2] * matrix[6],
            d->coordinates[0] * matrix[8] + d->coordinates[1] * matrix[9] + d->coordinates[2] * matrix[10]
            );
}


bool axlPoint::operator== (const axlPoint& point2) const {
    return (this->x() == point2.x()
            && this->y() == point2.y()
            && this->z() == point2.z());
}

bool axlPoint::operator !=(const axlPoint& point2) const {
    return !(*this == point2);
}


//! Returns x-coordinate of this point.
/*!
 *
 */
double axlPoint::x(void) const
{
    return d->coordinates[0];
}

//! Returns y-coordinate of this point.
/*!
 *
 */
double axlPoint::y(void) const
{
    return d->coordinates[1];
}

//! Returns z-coordinate of this point.
/*!
 *
 */
double axlPoint::z(void) const
{
    return d->coordinates[2];
}

//! Returns i-th coordinate of this point.
/*!
 *
 */
double axlPoint::operator [] (int i) const
{
    //assert( i>=0 && i<3);
    return d->coordinates[i];
}

//! Returns x-coordinate of this point.
/*!
 *
 */
double& axlPoint::x(void)
{
    return d->coordinates[0];
}

//! Returns y-coordinate of this point.
/*!
 *
 */
double& axlPoint::y(void)
{
    return d->coordinates[1];
}

//! Returns z-coordinate of this point.
/*!
 *
 */
double& axlPoint::z(void)
{
    return d->coordinates[2];
}

//! Returns i-th coordinate of this point.
/*!
 *
 */
double& axlPoint::operator [] (int i)
{
    //assert( i>=0 && i<3);
    return d->coordinates[i];
}

//! Change coordinates of this point.
/*!
 *
 */
void axlPoint::setCoordinates(double x, double y, double z)
{
    d->coordinates[0] = x;
    d->coordinates[1] = y;
    d->coordinates[2] = z;
//    this->touchGeometry();
}


//! Change coordinates of this point.
/*!
 *
 */
//void axlPoint::updateCoordinates(double x, double y, double z)
//{
//    this->setCoordinates(x,y,z);
//    this->touchGeometry();
//}

void axlPoint::touchX(double x)
{
    d->coordinates[0] = x;

    this->touchGeometry();
}

void axlPoint::touchY(double y)
{
    d->coordinates[1] = y;

    this->touchGeometry();
}

void axlPoint::touchZ(double z)
{
    d->coordinates[2] = z;

    this->touchGeometry();
}

void axlPoint::normalize(void)
{
    double n = this->norm();
    if(n > 0.0005)
    {
        d->coordinates[0] /= n;
        d->coordinates[1] /= n;
        d->coordinates[2] /= n;
    }
}

axlPoint& axlPoint::normalized(void)  {
    double n = this->norm();
    if(n > 0.0005)
    {
        d->coordinates[0] /= n;
        d->coordinates[1] /= n;
        d->coordinates[2] /= n;
    }
    return *this;
}


//! Check if the point we apply the method on is equal to point.
/*!
 *
 */
bool axlPoint::isEqualTo(axlPoint *point){
    return (d->coordinates[0]==point->x() && d->coordinates[1]==point->y() && d->coordinates[2]==point->z());
}

//! Returns coordinates of this point.
/*!
 *
 */
double *axlPoint::coordinates(void) const
{
    return d->coordinates ;
}

double axlPoint::norm() const
{
    return sqrt(d->coordinates[0] * d->coordinates[0] + d->coordinates[1] * d->coordinates[1] + d->coordinates[2] * d->coordinates[2]);
}

//! Returns the distance between \a lhs point and \a rhs point.
/*!
 *  The distance is always positive.
 */
double axlPoint::distance(const axlPoint& lhs, const axlPoint& rhs)
{
    double dx = rhs.d->coordinates[0] - lhs.d->coordinates[0];
    double dy = rhs.d->coordinates[1] - lhs.d->coordinates[1];
    double dz = rhs.d->coordinates[2] - lhs.d->coordinates[2];

    return qSqrt(dx*dx + dy*dy + dz*dz);
}

//! Returns the distance between \a lhs point and \a rhs point.
/*!
 *  The distance is always positive.
 */
double axlPoint::distance(axlPoint *lhs, axlPoint *rhs)
{
    double dx = rhs->d->coordinates[0] - lhs->d->coordinates[0];
    double dy = rhs->d->coordinates[1] - lhs->d->coordinates[1];
    double dz = rhs->d->coordinates[2] - lhs->d->coordinates[2];

    return qSqrt(dx*dx + dy*dy + dz*dz);
}

//! Returns the cross product between \a lhs (coords) and \a rhs (coords).
/*!
 *
 */
axlPoint axlPoint::crossProduct(const axlPoint& lhs, const axlPoint& rhs)
{
    return axlPoint(
                lhs.d->coordinates[1]*rhs.d->coordinates[2] - lhs.d->coordinates[2]*rhs.d->coordinates[1],
            lhs.d->coordinates[2]*rhs.d->coordinates[0] - lhs.d->coordinates[0]*rhs.d->coordinates[2],
            lhs.d->coordinates[0]*rhs.d->coordinates[1] - lhs.d->coordinates[1]*rhs.d->coordinates[0]
            );
}

//! Returns the cross product between \a lhs (coords) and \a rhs (coords).
/*!
 *
 */
axlPoint* axlPoint::crossProduct(axlPoint *lhs, axlPoint *rhs)
{
    return new axlPoint(
                lhs->d->coordinates[1]*rhs->d->coordinates[2] - lhs->d->coordinates[2]*rhs->d->coordinates[1],
            lhs->d->coordinates[2]*rhs->d->coordinates[0] - lhs->d->coordinates[0]*rhs->d->coordinates[2],
            lhs->d->coordinates[0]*rhs->d->coordinates[1] - lhs->d->coordinates[1]*rhs->d->coordinates[0]
            );
}


double axlPoint::dotProduct(const axlPoint& lhs, const axlPoint& rhs) {
    return lhs.x()*rhs.x() + lhs.y()*rhs.y() + lhs.z()*rhs.z();
}

double axlPoint::dotProduct(axlPoint *lhs, axlPoint *rhs) {
    return lhs->x()*rhs->x() + lhs->y()*rhs->y() + lhs->z()*rhs->z();
}


// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlPoint point)
{
    dbg.nospace() << QString("axlPoint: (%1, %2, %3)").arg(point.x()).arg(point.y()).arg(point.z());

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlPoint& point)
{
    dbg.nospace() << QString("axlPoint: (%1, %2, %3)").arg(point.x()).arg(point.y()).arg(point.z());

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlPoint *point)
{
    dbg.nospace() << QString("axlPoint: (%1, %2, %3)").arg(point->x()).arg(point->y()).arg(point->z());

    return dbg.space();
}

QString axlPoint::description(void) const
{
    QString result = "axlPoint";
    result.append("\nX : "+QString::number(d->coordinates[0]) + "\nY : "+QString::number(d->coordinates[1]) + "\nZ : "+QString::number(d->coordinates[2]));
    return result;
}

QString axlPoint::identifier(void) const
{
    return "axlPoint";
}

////SLOT
//void axlPoint::onXChanged(double x)
//{
//    d->coordinates[0] = x;
//}

//void axlPoint::onYChanged(double y)
//{
//    d->coordinates[1] = y;
//}

//void axlPoint::onZChanged(double z)
//{
//    d->coordinates[2] = z;
//}


QVariantList axlPoint::convertDataToQVariant(void) const{
    QVariantList list;
    QVariant id = QVariant::fromValue(identifier());
    QVariant x = QVariant::fromValue(d->coordinates[0]);
    QVariant y = QVariant::fromValue(d->coordinates[1]);
    QVariant z = QVariant::fromValue(d->coordinates[2]);
    list.append(id);
    list.append(x);
    list.append(y);
    list.append(z);
    QVariant name = QVariant::fromValue(objectName());
    list.append(name);

    return list;

}

int axlPoint::convertQVariantToData(const QVariantList &data){
    QVariant x = data.at(1);
    QVariant y = data.at(2);
    QVariant z = data.at(3);
    QString name = data.last().toString();
    setObjectName(name);
    setCoordinates(qvariant_cast<double>(x),qvariant_cast<double>(y),qvariant_cast<double>(z) );
    return 1;
}

//to be registered to the data factory.
dtkAbstractData *createaxlPoint(void)
{
    return new axlPoint;
}

// /////////////////////////////////////////////////////////////////
// axlPoint documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlPoint
 *
 *  \brief Class axlPoint defines 3D points.
 *
 *  This class enables to represent and manipulate 3D points.
 *
 *  Example:
 *  \code
 *  axlPoint *A = new axlPoint(0.0, 0.0, 0.0);
 *  axlPoint *B = new axlPoint(1.0, 0.0, 0.0);
 *  double length = axlPoint::distance(A, B);
 *  axlPoint middle = *(A);
 *  middle += *(B);
 *  middle /= 2.;
 *  \endcode
 */
