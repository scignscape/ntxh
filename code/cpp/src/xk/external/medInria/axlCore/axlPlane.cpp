/* axlPlane.cpp ---
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

#include "axlPlane.h"

#include "axlPoint.h"

#include <dtkCoreSupport/dtkGlobal.h>

// /////////////////////////////////////////////////////////////////
// axlPlanePrivate
// /////////////////////////////////////////////////////////////////

class axlPlanePrivate
{
public:
    axlPoint *point;
    axlPoint *normal;
};

// /////////////////////////////////////////////////////////////////
// axlPlane implementation
// /////////////////////////////////////////////////////////////////

//! Constructs a axel plane of with point and normal vector are NULL with parent \a parent of QObject type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel plane with no parent.
 */
axlPlane::axlPlane(QObject *parent) : axlAbstractData(), d(new axlPlanePrivate)
{
    DTK_UNUSED(parent);

    this->setObjectName(this->identifier());

    d->point = new axlPoint;
    d->normal = new axlPoint;
}

//! Constructs a axel plane of two axlPoint, one for a point of on the plane \a point and one for the normal of the plane  \a normal with parent \a parent of QObject type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel point with no parent.
 */
axlPlane::axlPlane(axlPoint *point, axlPoint *normal, QObject *parent) : axlAbstractData(), d(new axlPlanePrivate)
{
    this->setObjectName(this->identifier());

    d->point = new axlPoint(point);
    d->normal = new axlPoint(normal);
}

//! Constructs an axel plane from two axlPoint, one for a point of on the plane \a point and one for the normal of the plane \a normal with parent \a parent.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel point with no parent.
 */
axlPlane::axlPlane(const axlPoint& point, const axlPoint& normal, QObject *parent) : axlAbstractData(), d(new axlPlanePrivate)
{
    this->setObjectName(this->identifier());

    d->point = new axlPoint(point);
    d->normal = new axlPoint(normal);
}

//! Constructs a copy of \a other with same point and normal.
/*!
 *
 */
axlPlane::axlPlane(const axlPlane& other) : axlAbstractData(), d(new axlPlanePrivate)
{
    this->setObjectName(this->identifier());
    this->setParent(other.parent());
    d->point = new axlPoint(other.d->point);
    d->normal = new axlPoint(other.d->normal);
}

//! Destroys the axel plane.
/*!
 *
 */
axlPlane::~axlPlane(void)
{
    if(d->normal)
    {
        delete d->normal;
        d->normal = NULL;
    }
    if(d->point)
    {
        delete d->point;
        d->point = NULL;
    }
    delete d;
    d = NULL;
}

//! Assigns other to this plane and returns a reference to this plane.
/*!
 *
 */
axlPlane& axlPlane::operator=(const axlPlane& other)
{
    *(d->point) = *(other.d->point);
    *(d->normal) = *(other.d->normal);

    return (*this);
}

//! Returns the point of the plane.
/*!
 *
 */
axlPoint *axlPlane::point(void) const
{
    return d->point;
}

//! Returns the normal of the plane.
/*!
 *
 */
axlPoint *axlPlane::normal(void) const
{
    return d->normal;
}


//! Change first point and second point of this plane.
/*!
 *
 */
void axlPlane::setValues(axlPoint *point, axlPoint *normal)
{
    *(d->point) = *point;
    *(d->normal) = *normal;
    //this->touchGeometry();
}

//! Change first point of this plane.
/*!
 *
 */
void axlPlane::setPoint(axlPoint *point)
{
    *(d->point) = *point;
    //this->touchGeometry();
}

void axlPlane::setPoint(double *p)
{
    d->point->coordinates()[0] = p[0];
    d->point->coordinates()[1] = p[1];
    d->point->coordinates()[2] = p[2];
    //this->touchGeometry();
}

//! Change second point of this plane.
/*!
 *
 */
void axlPlane::setNormal(axlPoint *normal)
{
    *(d->normal) = *normal;
    //this->touchGeometry();
}

void axlPlane::setNormal(double *normal)
{
    d->normal->coordinates()[0] = normal[0];
    d->normal->coordinates()[1] = normal[1];
    d->normal->coordinates()[2] = normal[2];
//    this->touchGeometry();
}

void axlPlane::touchPoint(axlPoint point)
{
    d->point->setCoordinates(point.x(),point.y(),point.z());
    this->touchGeometry();
}

void axlPlane::touchNormal(axlPoint normal)
{
    d->normal->setCoordinates(normal.x(),normal.y(),normal.z());
    this->touchGeometry();
}

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlPlane plane)
{
    dbg.nospace() << plane.description();

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlPlane& plane)
{
    dbg.nospace() << plane.description();

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlPlane *plane)
{
    dbg.nospace() << plane->description();

    return dbg.space();
}

QString axlPlane::description(void) const
{
    QString result = "axlPlane";
    result.append("\nPoint : "+d->point->description() + "\nNormal : "+d->normal->description());
    return result;
}

QString axlPlane::identifier(void) const
{
    return "axlPlane";
}

////SLOT
//void axlPlane::onPointChanged(axlPoint *point)
//{
//    *(d->point) = *point;
////    this->touchGeometry();
//}

//void axlPlane::onNormalChanged(axlPoint *normal)
//{
//    *(d->normal) = *normal;
////    this->touchGeometry();
//}


QVariantList axlPlane::convertDataToQVariant(void) const{
    QVariantList list;
    QVariant id = QVariant::fromValue(identifier());
    QVariantList point = d->point->convertDataToQVariant();
    QVariantList normal = d->normal->convertDataToQVariant();
    list.append(id);
    list.append(point);
    list.append(normal);
    QVariant name = QVariant::fromValue(objectName());
    list.append(name);
    return list;

}

int axlPlane::convertQVariantToData(const QVariantList &data){
    QVariantList point;
    point.append(data.at(1));
    point.append(data.at(2));
    point.append(data.at(3));
    point.append(data.at(4));
    point.append(data.at(5));
    d->point->convertQVariantToData(point);
    QVariantList normal;
    normal.append(data.at(6));
    normal.append(data.at(7));
    normal.append(data.at(8));
    normal.append(data.at(9));
    normal.append(data.at(10));
    d->normal->convertQVariantToData(normal);
    setObjectName(data.last().toString());
    return 1;
}

//to be registered to the data factory.
dtkAbstractData *createaxlPlane(void)
{
    return new axlPlane;
}

// /////////////////////////////////////////////////////////////////
// axlPlane documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlPlane
 *
 *  \brief Class axlPlane defines 3D planes.
 *
 *  This class enables to represent and manipulate 3D planes.
 *
 *  Example:
 *  \code
 *  axlPoint *point = new axlPoint(0.0, 0.0, 0.0)
 *  axlPoint *normal = new axlPoint(1.0, 0.0, 0.0)
 *  axlPlane *A = new axlPlane(point, normal);
 *  \endcode
 */
