/* axlLine.cpp ---
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

#include "axlLine.h"

#include "axlPoint.h"

#include <dtkCoreSupport/dtkGlobal.h>

// /////////////////////////////////////////////////////////////////
// axlLinePrivate
// /////////////////////////////////////////////////////////////////

class axlLinePrivate
{
public:
    axlPoint *p1;
    axlPoint *p2;
};

// /////////////////////////////////////////////////////////////////
// axlLine implementation
// /////////////////////////////////////////////////////////////////

//! Constructs a axel line of with firstPoint and second point are NULL with parent \a parent of QObject type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel line with no parent.
 */
axlLine::axlLine(QObject *parent) : axlAbstractCurveParametric(), d(new axlLinePrivate)
{
    this->setObjectName(this->identifier());

    d->p1 = new axlPoint();
    d->p2 = new axlPoint(1.0, 0.0, 0.0);
}
//! Constructs a axel line of two axlPoint \a p1 \a p2 with parent \a parent of QObject type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel point with no parent.
 */
axlLine::axlLine(axlPoint *p1, axlPoint *p2, QObject *parent) : axlAbstractCurveParametric(), d(new axlLinePrivate)
{
    this->setObjectName(this->identifier());

    d->p1 = new axlPoint(p1);
    d->p2 = new axlPoint(p2);
}

//! Constructs an axel line from two axl points \a p1 \a p2 and a \a parent
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a axel point with no parent.
 */
axlLine::axlLine(const axlPoint& p1, const axlPoint& p2, QObject* parent) : axlAbstractCurveParametric(), d(new axlLinePrivate)
{
    this->setObjectName(this->identifier());

    d->p1 = new axlPoint(p1);
    d->p2 = new axlPoint(p2);
}

//! Constructs a copy of \a other with same axlPoints.
/*!
 *
 */
axlLine::axlLine(const axlLine& other) : axlAbstractCurveParametric(), d(new axlLinePrivate)
{
    this->setObjectName(this->identifier());
    this->setParent(other.parent());
    d->p1 = new axlPoint(other.d->p1);
    d->p2 = new axlPoint(other.d->p2);
}

//! Destroys the axel line.
/*!
 *
 */
axlLine::~axlLine(void)
{
    if (d->p1) {
        delete(d->p1);
        d->p1 = NULL;
    }
    if (d->p2) {
        delete(d->p2);
        d->p2 = NULL;
    }
    delete d;
    d = NULL;
}

//! Assigns other to this line and returns a reference to this line.
/*!
 *
 */
axlLine& axlLine::operator=(const axlLine& other)
{
    *(d->p1) = *(other.d->p1);
    *(d->p2) = *(other.d->p2);

    return (*this);
}

//! Returns first point of the line.
/*!
 *
 */
axlPoint *axlLine::firstPoint(void) const
{
    return d->p1;
}

//! Returns second point of the line.
/*!
 *
 */
axlPoint *axlLine::secondPoint(void) const
{
    return d->p2;
}

//! Returns a barycenter point of the line.
/*!
 *
 */
axlPoint *axlLine::getBarycenterPoint(double coeff)
{
    double x = (firstPoint()->x() + coeff*(secondPoint()->x() - firstPoint()->x()));
    double y = (firstPoint()->y() + coeff*(secondPoint()->y() - firstPoint()->y()));
    double z = (firstPoint()->z() + coeff*(secondPoint()->z() - firstPoint()->z()));
    return new axlPoint(x,y,z);
}

//! Returns the center point of the line.
/*!
 *
 */
axlPoint *axlLine::getMiddlePoint(void)
{
    double x = (firstPoint()->x() + 0.5*(secondPoint()->x() - firstPoint()->x()));
    double y = (firstPoint()->y() + 0.5*(secondPoint()->y() - firstPoint()->y()));
    double z = (firstPoint()->z() + 0.5*(secondPoint()->z() - firstPoint()->z()));
    return new axlPoint(x,y,z);
}

//! Change first point and second point of this line.
/*!
 *
 */
void axlLine::setValues(axlPoint *p1, axlPoint *p2)
{
    *(d->p1) = *p1;
    *(d->p2) = *p2;
    //this->touchGeometry();

}

//! Change first point of this line.
/*!
 *
 */
void axlLine::setFirstPoint(axlPoint *p1)
{
    *(d->p1) = *p1;
    //this->touchGeometry();
}

//! Change second point of this line.
/*!
 *
 */
void axlLine::setSecondPoint(axlPoint *p2)
{
    *(d->p2) = *p2;
    //this->touchGeometry();
}

//! modify first point of this line.
/*!
 *
 */
void axlLine::setFirstPoint(double *p1)
{
    d->p1->coordinates()[0] = p1[0];
    d->p1->coordinates()[1] = p1[1];
    d->p1->coordinates()[2] = p1[2];
    //this->touchGeometry();
}

//! modify second point of this line.
/*!
 *
 */
void axlLine::setSecondPoint(double *p2)
{
    d->p2->coordinates()[0] = p2[0];
    d->p2->coordinates()[1] = p2[1];
    d->p2->coordinates()[2] = p2[2];
    //this->touchGeometry();
}

//! Change first point of this line and emit using touchGeometry.
/*!
 *
 */
void axlLine::touchFirstPoint(const axlPoint &point) {
    setFirstPoint(point.coordinates());

    this->touchGeometry();
}

//! Change second point of this line and emit using touchGeometry.
/*!
 *
 */
void axlLine::touchSecondPoint(const axlPoint &point) {
    setSecondPoint(point.coordinates());

    this->touchGeometry();
}

void axlLine::applyMatrix(double* matrix) {
    d->p1->transformAsPoint(matrix);
    d->p2->transformAsPoint(matrix);
    this->touchGeometry();
}

//! compute the direction value of the line ie a in y =  ax + b.
/*!
 *
 */
double axlLine::planeDirection(void)
{
    double a = 0.5*((secondPoint()->y() - firstPoint()->y())/(secondPoint()->x() - firstPoint()->x()));
    return a;
}

//! compute the b value of the line y = ax + b.
/*!
 *
 */
double axlLine::planeOrigineOrdinate(void)
{
    double b = firstPoint()->y() - planeDirection()*firstPoint()->x();
    return b;
}

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////

QDebug operator<<(QDebug dbg, axlLine line)
{
    dbg.nospace() << line.description();

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlLine& line)
{
    dbg.nospace() << line.description();

    return dbg.space();
}

QDebug operator<<(QDebug dbg, axlLine *line)
{
    dbg.nospace() << line->description();

    return dbg.space();
}

QString axlLine::description(void) const
{
    QString result = "axlLine";
    result.append("\nfirstPoint : "+d->p1->description() + "\nsecondPoint : "+d->p2->description());
    return result;
}

QString axlLine::identifier(void) const
{
    return "axlLine";
}

//SLOT
void axlLine::onFirstPointChanged(axlPoint *p1)
{
    *(d->p1) = *p1;
    //this->touchGeometry();
}

void axlLine::onSecondPointChanged(axlPoint *p2)
{
    *(d->p2) = *p2;
    //this->touchGeometry();
}


QVariantList axlLine::convertDataToQVariant(void) const{
    QVariantList list;
    QVariant id = QVariant::fromValue(identifier());
    QVariantList point1 = d->p1->convertDataToQVariant();
    QVariantList point2 = d->p2->convertDataToQVariant();
    list.append(id);
    list.append(point1);
    list.append(point2);
    QVariant name = QVariant::fromValue(objectName());
    list.append(name);
    return list;

}

int axlLine::convertQVariantToData(const QVariantList &data){
    QVariantList point1;
    point1.append(data.at(1));
    point1.append(data.at(2));
    point1.append(data.at(3));
    point1.append(data.at(4));
    point1.append(data.at(5));
    d->p1->convertQVariantToData(point1);
    QVariantList point2;
    point2.append(data.at(6));
    point2.append(data.at(7));
    point2.append(data.at(8));
    point2.append(data.at(9));
    point2.append(data.at(10));
    d->p2->convertQVariantToData(point2);
    setObjectName(data.last().toString());
    return 1;
}

//to be registered to the data factory.
dtkAbstractData *createaxlLine(void)
{
    return new axlLine;
}


// /////////////////////////////////////////////////////////////////
// axlLine documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlLine
 *
 *  \brief Class axlLine defines 3D lines.
 *
 *  This class enables to represent and manipulate 3D lines.
 *
 *  Example:
 *  \code
 *  axlPoint *firstPoint = new axlPoint(0.0, 0.0, 0.0);
 *  axlPoint *secondPoint = new axlPoint(1.0, 0.0, 0.0);
 *  axlLine *A = new axlLine(firstPoint, secondPoint);
 *  \endcode
 */
