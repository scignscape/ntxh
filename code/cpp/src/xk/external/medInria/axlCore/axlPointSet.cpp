/* axlPointSet.h ---
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

#include "axlPointSet.h"

#include <dtkCoreSupport/dtkGlobal.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>



class axlPointSetPrivate
{
public:
    QList<axlPoint *> points;
    bool planar;
    bool uniqueColor;

};

// /////////////////////////////////////////////////////////////////
// axlPointSet
// /////////////////////////////////////////////////////////////////

axlPointSet::axlPointSet(void) : axlAbstractData(), d(new axlPointSetPrivate)
{
    this->setObjectName(this->identifier());
    d->planar = false;
    d->uniqueColor = true;
}

axlPointSet::~axlPointSet(void)
{
    delete d;

    d = NULL;
}


void *axlPointSet::points(void) const
{
        return &(d->points); // (d->Points est QList<axlPointSet *> )
}

void *axlPointSet::points(void)
{
        return &(d->points); // (d->Points est QList<axlPointSet *> )
}

bool axlPointSet::isPlanar(void) const
{
    return d->planar;
}

void axlPointSet::setPlanar(const bool isPlanar)
{
    d->planar=isPlanar;
}

bool axlPointSet::isUniqueColor(void) const
{
    return d->uniqueColor;
}

void axlPointSet::setUniqueColor(const bool uniqueColor)
{
    d->uniqueColor = uniqueColor;
}

int axlPointSet::numberOfPoints(void) const
{
    return d->points.size();
    //return static_cast<QList<axlPoint *> *>(this->points())->size();
}

void axlPointSet::push_front(axlPoint* p)
{
    d->points.push_front(p);

//    static_cast<QList<axlPoint *> *>(this->points())->push_front(p);
}

void axlPointSet::push_back(axlPoint* p)
{
    d->points.append( p);
  //  static_cast<QList<axlPoint *> *>(this->points())->push_back(p);
}

axlPoint *axlPointSet::value(int n) const
{
    return d->points.at(n);
   //return static_cast<QList<axlPoint *> *>(this->points())->value(n);
}

axlPoint *axlPointSet::value(int n)
{
    return d->points.at(n);

   //return static_cast<QList<axlPoint *> *>(this->points())->value(n);
}

QDebug axlPointSet::printAxlAbstractPoints(QDebug dbg)
{
    QList<axlPoint *> *listPoint = static_cast<QList<axlPoint *> *>(this->points());
    QList<axlPoint *>::iterator itPoints;
    for(itPoints=listPoint->begin();itPoints!=listPoint->end();itPoints++)
    {
      //dbg.nospace() <<itPoints;
    }

    return dbg.space();
}

void axlPointSet::printAxlPointSet(void)
{
        qDebug()<<d->points;
}

bool axlPointSet::registered(void)
{

    return dtkAbstractDataFactory::instance()->registerDataType("axlPointSet", createaxlPointSet);
}

QString axlPointSet::description(void) const
{
    QString result = "axlPointSet";
    result.append("\nNumber of points : "+QString::number(d->points.size()));
    return result;
}

QString axlPointSet::identifier(void) const
{
    return "axlPointSet";
}

QString axlPointSet::objectType(void) const
{
    return "Point set";
}



// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlPointSet(void)
{
    return new axlPointSet;
}
