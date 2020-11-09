/* axlCylinder.cpp ---
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

#include "axlCylinder.h"

#include "axlPoint.h"

#include <dtkCoreSupport/dtkGlobal.h>

// /////////////////////////////////////////////////////////////////
// axlCylinderPrivate
// /////////////////////////////////////////////////////////////////

class axlCylinderPrivate
{
public:
    axlPoint *p1;
    axlPoint *p2;
    double radius;

};

// /////////////////////////////////////////////////////////////////
// axlCylinder implementation
// /////////////////////////////////////////////////////////////////

//! Constructs a axel cylinder of with firstPoint and second point are NULL and 1.0 radius with parent \a parent of QObject type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel cylinder with no parent.
 */
axlCylinder::axlCylinder(QObject *parent) : axlAbstractData(), d(new axlCylinderPrivate)
{
    this->setObjectName(this->identifier());

    d->p1  = new axlPoint();
    d->p2  = new axlPoint(1.0, 0.0, 0.0);
    d->radius = 1.0;
}

//! Constructs a axel cylinder of two axlPoint \a p1 \a p2 and radius \a radius with parent \a parent of QObject type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel point with no parent.
 */
axlCylinder::axlCylinder(axlPoint *p1, axlPoint *p2, double radius, QObject *parent) : axlAbstractData(), d(new axlCylinderPrivate)
{
    this->setObjectName(this->identifier());

    d->p1 = new axlPoint(p1);
    d->p2 = new axlPoint(p2);
    d->radius = radius;
}

//! Constructs an axel cylinder from two axlPoint \a p1 \a p2 and radius \a radius with parent \a parent.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel point with no parent.
 */
axlCylinder::axlCylinder(const axlPoint& p1, const axlPoint& p2, double radius, QObject *parent) : axlAbstractData(), d(new axlCylinderPrivate) {
    this->setObjectName(this->identifier());

    d->p1 = new axlPoint(p1);
    d->p2 = new axlPoint(p2);
    d->radius = radius;
}

//! Constructs a copy of \a other with same axlPoints.
/*!
 *
 */
axlCylinder::axlCylinder(const axlCylinder& other) : axlAbstractData(), d(new axlCylinderPrivate)
{
    this->setObjectName(this->identifier());
    this->setParent(other.parent());
    d->p1 = new axlPoint(other.d->p1);
    d->p2 = new axlPoint(other.d->p2);
    d->radius = other.radius();
}

//! Destroys the axel cylinder.
/*!
 *
 */
axlCylinder::~axlCylinder(void)
{
    if (d->p1)
    {
        delete(d->p1);
        d->p1 = NULL;
    }
    if (d->p2)
    {
        delete(d->p2);
        d->p2 = NULL;
    }
    delete d;
    d = NULL;
}

//! Assigns other to this cylinder and returns a reference to this cylinder.
/*!
 *
 */
axlCylinder& axlCylinder::operator=(const axlCylinder& other)
{
    *(d->p1) = *(other.d->p1);
    *(d->p2) = *(other.d->p2);
    d->radius = other.radius();

    return (*this);
}

//! Returns first point of the cylinder.
/*!
 *
 */
axlPoint *axlCylinder::firstPoint(void) const
{
    return d->p1;
}

//! Returns second point of the cylinder.
/*!
 *
 */
axlPoint *axlCylinder::secondPoint(void) const
{
    return d->p2;
}

//! Returns radius of the cylinder.
/*!
 *
 */
double axlCylinder::radius(void) const
{
    return d->radius;
}

//! Returns length of the cylinder.
/*!
 *
 */
double axlCylinder::length(void) const
{
    return axlPoint::distance(d->p1, d->p2);
}


//! Change first point and second point of this cylinder.
/*!
 *
 */
void axlCylinder::setValues(axlPoint *p1, axlPoint *p2, double radius)
{
    *(d->p1) = *p1;
    *(d->p2) = *p2;
    d->radius = radius;

    //this->touchGeometry();

}

//! Change first point of this cylinder.
/*!
 *
 */
void axlCylinder::setFirstPoint(axlPoint *p1)
{
    *(d->p1) = *p1;

    //this->touchGeometry();
}

//! modify first point of this line.
/*!
 *
 */
void axlCylinder::setFirstPoint(double *p1)
{
    d->p1->coordinates()[0] = p1[0];
    d->p1->coordinates()[1] = p1[1];
    d->p1->coordinates()[2] = p1[2];
}

//! modify second point of this line.
/*!
 *
 */
void axlCylinder::setSecondPoint(double *p2)
{
    d->p2->coordinates()[0] = p2[0];
    d->p2->coordinates()[1] = p2[1];
    d->p2->coordinates()[2] = p2[2];
}


//! Change second point of this cylinder.
/*!
 *
 */
void axlCylinder::setSecondPoint(axlPoint *p2)
{
    *(d->p2) = *p2;

    //this->touchGeometry();
}

//! Change radius of this cylinder.
/*!
 *
 */
void axlCylinder::setRadius(double radius)
{
    d->radius = radius;

    this->touchGeometry();
}

//! Change length of this cylinder we considered then first point is the origin of the cylinder and we change secondPoint in consequence.
/*!
 *
 */
void axlCylinder::setLength(double length)
{
    double oldLength = this->length();
    if(oldLength != 0)
    {
        (*d->p2) = *(d->p1) + (*(d->p2) - *(d->p1)) * (length/oldLength) ;
        this->touchGeometry();
    }
    else
        qDebug()<< "cylinder is not correctly defined length = 0.0";
}

    void axlCylinder::touchFirstPoint(axlPoint p1)
    {
        d->p1->setCoordinates(p1.x(),p1.y(),p1.z());
        this->touchGeometry();
    }

    void axlCylinder::touchSecondPoint(axlPoint p2)
    {
        d->p2->setCoordinates(p2.x(),p2.y(),p2.z());
        this->touchGeometry();
    }

    void axlCylinder::touchRadius(double radius)
    {
        d->radius = radius;
        this->touchGeometry();
    }

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlCylinder cylinder)
{
    dbg.nospace() << cylinder.description();

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlCylinder& cylinder)
{
    dbg.nospace() << cylinder.description();

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlCylinder *cylinder)
{
    dbg.nospace() << cylinder->description();

    return dbg.space();
}

QString axlCylinder::description(void) const
{
    QString result = "axlCylinder";
    result.append("\nfirstPoint : "+d->p1->description() + "\nsecondPoint : "+d->p2->description() + "\nradius : "+ QString::number(d->radius));
    return result;
}

QString axlCylinder::identifier(void) const
{
    return "axlCylinder";
}

//SLOT
void axlCylinder::onFirstPointChanged(axlPoint *p1)
{
    *(d->p1) = *p1;
}

void axlCylinder::onSecondPointChanged(axlPoint *p2)
{
    *(d->p2) = *p2;
}

void axlCylinder::onRadiusChanged(double radius)
{
    d->radius = radius;
}


QVariantList axlCylinder::convertDataToQVariant(void) const{
    QVariantList list;
    QVariant id = QVariant::fromValue(identifier());
    QVariant radius = QVariant::fromValue(d->radius);
    QVariantList p1 = d->p1->convertDataToQVariant();
    QVariantList p2 = d->p2->convertDataToQVariant();
    list.append(id);
    list.append(radius);
    list.append(p1);
    list.append(p2);
    QVariant name = QVariant::fromValue(objectName());
    return list;

}

int axlCylinder::convertQVariantToData(const QVariantList &data){
    setRadius(data.at(1).toDouble());
    QVariantList p1List;
    p1List.append(data.at(2));
    p1List.append(data.at(3));
    p1List.append(data.at(4));
    p1List.append(data.at(5));
    p1List.append(data.at(6));
    d->p1->convertQVariantToData(p1List);
    QVariantList p2List;
    p2List.append(data.at(7));
    p2List.append(data.at(8));
    p2List.append(data.at(9));
    p2List.append(data.at(10));
    p2List.append(data.at(11));
    d->p2->convertQVariantToData(p2List);
    setObjectName(data.last().toString());
    return 1;

}

//to be registered to the data factory.
dtkAbstractData *createaxlCylinder(void)
{
    return new axlCylinder;
}

// /////////////////////////////////////////////////////////////////
// axlCylinder documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlCylinder
 *
 *  \brief Class axlCylinder defines 3D cylinders.
 *
 *  This class enables to represent and manipulate 3D cylinders.
 *
 *  Example:
 *  \code
 *  axlPoint *firstPoint = new axlPoint(0.0, 0.0, 0.0);
 *  axlPoint *secondPoint = new axlPoint(1.0, 0.0, 0.0);
 *  double radius = 1.0;
 *  axlCylinder *A = new axlCylinder(firstPoint, secondPoint, radius);
 *  \endcode
 */
