/* axlCone.cpp ---
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

#include "axlCone.h"

#include "axlPoint.h"

#include <dtkCoreSupport/dtkGlobal.h>

// /////////////////////////////////////////////////////////////////
// axlConePrivate
// /////////////////////////////////////////////////////////////////

class axlConePrivate
{
public:
    axlPoint *apex;
    axlPoint *basePoint;
    double radius;
};

// /////////////////////////////////////////////////////////////////
// axlCone implementation
// /////////////////////////////////////////////////////////////////

//! Constructs a axel cone of with apex and basePoint point are NULL and 1.0 radius with parent \a parent of QObject type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel cone with no parent.
 */
axlCone::axlCone(QObject *parent) : axlAbstractData(), d(new axlConePrivate)
{
    this->setObjectName(this->identifier());

    d->apex = new axlPoint();
    d->basePoint = new axlPoint(1.0, 0.0, 0.0);
    d->radius = 1.0;
}

//! Constructs a axel cone of two axlPoint \a apex \a basePoint and radius \a radius with parent \a parent of QObject type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel point with no parent.
 */
axlCone::axlCone(axlPoint *apex, axlPoint *basePoint, double radius, QObject *parent) : axlAbstractData(), d(new axlConePrivate)
{
    this->setObjectName(this->identifier());

    d->apex = new axlPoint(apex);
    d->basePoint = new axlPoint(basePoint);
    d->radius = radius;
}

//! Constructs an axel cone from two axlPoint \a apex \a basePoint and its radius \a radius with parent \a parent.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel point with no parent.
 */
axlCone::axlCone(const axlPoint &apex, const axlPoint &basePoint, double radius, QObject *parent) : axlAbstractData(), d(new axlConePrivate) {
    this->setObjectName(this->identifier());

    d->apex = new axlPoint(apex);
    d->basePoint = new axlPoint(basePoint);
    d->radius = radius;
}

//! Constructs a copy of \a other with same axlPoints.
/*!
 *
 */
axlCone::axlCone(const axlCone& other) : axlAbstractData(), d(new axlConePrivate)
{
    this->setObjectName(this->identifier());
    this->setParent(other.parent());
    d->apex = new axlPoint(other.d->apex);
    d->basePoint = new axlPoint(other.d->basePoint);
    d->radius = other.radius();
}

//! Destroys the axel cone.
/*!
 *
 */
axlCone::~axlCone(void)
{
    if (d->apex)
    {
        delete d->apex;
        d->apex = NULL;
    }
    if (d->basePoint)
    {
        delete d->basePoint;
        d->basePoint = NULL;
    }
    delete d;
    d = NULL;
}

//! Assigns other to this cone and returns a reference to this cone.
/*!
 *
 */
axlCone& axlCone::operator=(const axlCone& other)
{
    *(d->apex) = *(other.d->apex);
    *(d->basePoint) = *(other.d->basePoint);
    d->radius = other.radius();

    return (*this);
}

//! Returns apex of the cone.
/*!
 *
 */
axlPoint *axlCone::apex(void) const
{
    return d->apex;
}

//! Returns basePoint point of the cone.
/*!
 *
 */
axlPoint *axlCone::basePoint(void) const
{
    return d->basePoint;
}

//! Returns radius of the cone.
/*!
 *
 */
double axlCone::radius(void) const
{
    return d->radius;
}

//! Returns length of the cone.
/*!
 *
 */
double axlCone::length(void) const
{
    return axlPoint::distance(d->apex, d->basePoint);
}

//! Change apex and basePoint of this cone.
/*!
 *
 */
void axlCone::setValues(axlPoint *apex, axlPoint *basePoint, double radius)
{
    *(d->apex) = *apex;
    *(d->basePoint) = *basePoint;
    d->radius = radius;

    //this->touchGeometry();
}

//! Change apex of this cone.
/*!
 *
 */
void axlCone::setApex(axlPoint *apex)
{
    *(d->apex) = *apex;

    //this->touchGeometry();
}

void axlCone::setApex(double *apex)
{
    d->apex->coordinates()[0] = apex[0];
    d->apex->coordinates()[1] = apex[1];
    d->apex->coordinates()[2] = apex[2];
}

//! Change base point of this cone.
/*!
 *
 */
void axlCone::setBasePoint(axlPoint *basePoint)
{
    *(d->basePoint) = *basePoint;

    //this->touchGeometry();
}

void axlCone::setBasePoint(double *basePoint)
{
    d->basePoint->coordinates()[0] = basePoint[0];
    d->basePoint->coordinates()[1] = basePoint[1];
    d->basePoint->coordinates()[2] = basePoint[2];
}

//! Change radius of this cone.
/*!
 *
 */
void axlCone::setRadius(double radius)
{
    d->radius = radius;

    //this->touchGeometry();
}

//! Change length of this cone we considered then apex is the origin of the cone and we change base point in consequence.
/*!
 *
 */
void axlCone::setLength(double length)
{
    double oldLength = this->length();
    if(oldLength != 0)
    {
        (*d->basePoint) = *(d->apex) + (*(d->basePoint) - *(d->apex)) * (length/oldLength) ;
    }
    else
        qDebug()<< "cone is not correctly defined length = 0.0";

    this->touchGeometry();
}

void axlCone::touchRadius(double radius)
{
    d->radius = radius;
    this->touchGeometry();
}

void axlCone::touchBasePoint(axlPoint basePoint)
{
    d->basePoint->setCoordinates(basePoint.x(),basePoint.y(),basePoint.z());
    this->touchGeometry();
}

void axlCone::touchApex(axlPoint apex)
{
    d->apex->setCoordinates(apex.x(),apex.y(),apex.z());
    this->touchGeometry();
}

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlCone cone)
{
    dbg.nospace() << cone.description();

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlCone& cone)
{
    dbg.nospace() << cone.description();

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlCone *cone)
{
    dbg.nospace() << cone->description();

    return dbg.space();
}

QString axlCone::description(void) const
{
    QString result = "axlCone";
    if(!d->apex)
        return "Please set an apex";

    if(!d->basePoint)
        return "Please set a base point";

    result.append("\napex : "+d->apex->description() + "\nbase point : "+d->basePoint->description() + "\nradius : "+ QString::number(d->radius));
    return result;
}

QString axlCone::identifier(void) const
{
    return "axlCone";
}

//SLOT
void axlCone::onApexChanged(axlPoint *apex)
{
    *(d->apex) = *apex;
    this->touchGeometry();
}

void axlCone::onBasePointChanged(axlPoint *basePoint)
{
    *(d->basePoint) = *basePoint;
    this->touchGeometry();
}

void axlCone::onRadiusChanged(double radius)
{
    d->radius = radius;
    this->touchGeometry();
}


QVariantList axlCone::convertDataToQVariant(void) const
{
    QVariantList list;
    QVariant id = QVariant::fromValue(identifier());
    QVariant radius = QVariant::fromValue(d->radius);
    QVariantList base = d->basePoint->convertDataToQVariant();
    QVariantList apex = d->apex->convertDataToQVariant();
    list.append(id);
    list.append(radius);
    list.append(base);
    list.append(apex);
    QVariant name = QVariant::fromValue(objectName());
    list.append(name);
    return list;
}

int axlCone::convertQVariantToData(const QVariantList &data)
{
    setRadius(data.at(1).toDouble());
    QVariantList baseList;
    baseList.append(data.at(2));
    baseList.append(data.at(3));
    baseList.append(data.at(4));
    baseList.append(data.at(5));
    baseList.append(data.at(6));
    d->basePoint->convertQVariantToData(baseList);
    QVariantList apexList;
    apexList.append(data.at(7));
    apexList.append(data.at(8));
    apexList.append(data.at(9));
    apexList.append(data.at(10));
    d->apex->convertQVariantToData(apexList);
    setObjectName(data.last().toString());
    return 1;
}

//to be registered to the data factory.
dtkAbstractData *createaxlCone(void)
{
    return new axlCone;
}

// /////////////////////////////////////////////////////////////////
// axlCone documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlCone
 *
 *  \brief Class axlCone defines 3D cones.
 *
 *  This class enables to represent and manipulate 3D cones.
 *
 *  Example:
 *  \code
 *  axlPoint *apex = new axlPoint(0.0, 0.0, 0.0);
 *  axlPoint *basePoint = new axlPoint(1.0, 0.0, 0.0);
 *  double radius = 1.0;
 *  axlCone *A = new axlCone(apex, basePoint, radius);
 *  \endcode
 */
