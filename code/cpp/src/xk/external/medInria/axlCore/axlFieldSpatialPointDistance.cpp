/* axlFieldSpatialPointDistance.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */
#include <sstream>

#include "axlFieldSpatialPointDistance.h"
#include "axlPoint.h"
#include "axlAbstractProcess.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

class axlFieldSpatialPointDistancePrivate
{
public:

    axlPoint *point;



};

// /////////////////////////////////////////////////////////////////
// axlFieldSpatialPointDistance implementation
// /////////////////////////////////////////////////////////////////

//!
/*!
 *
 */
axlFieldSpatialPointDistance::axlFieldSpatialPointDistance() : axlAbstractFieldSpatial(),  d(new axlFieldSpatialPointDistancePrivate)
{

    this->setType(axlAbstractField::Float);
    this->setKind(axlAbstractField::Scalar);
    this->setSupport(axlAbstractField::Point);
    this->setObjectName(this->identifier());
    d->point = new axlPoint(0,0,0);
}



//! Destroys a spatial field.
/*!
 *
 */
axlFieldSpatialPointDistance::~axlFieldSpatialPointDistance(void)
{

    if(d->point){
        delete d->point;
        d->point = NULL;
    }

    delete d;

    d = NULL;
}


//! Sets the reference point.
/*!
 *
 */
void axlFieldSpatialPointDistance::setParameter(double data, int channel){
    if(channel ==0){
    d->point->x() = data; //onXChanged(data);
    }else if(channel == 1){
        d->point->y() = data; //onYChanged(data);
    }else if(channel==2){
        d->point->z() = data; //onZChanged(data);
    }

}


//! Returns the reference point.
/*!
 *
 */
axlPoint *axlFieldSpatialPointDistance::getPoint(void){
    return d->point;
}


//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double axlFieldSpatialPointDistance::scalar(double x, double y, double z)
{
        return std::abs((x-d->point->x()) * (x-d->point->x()) + (y-d->point->y()) * (y-d->point->y()) + (z-d->point->z()) * (z-d->point->z()));
}


//! Returns the description of the field.
/*!
 *
 */
QString axlFieldSpatialPointDistance::description(void) const
{
    QString qstr;

    qstr.append("axlFieldSpatialPointDistance");
    qstr.append("Type : Float");
    qstr.append(";Kind : Scalar");
    qstr.append(";Support : Point");

    return qstr;

}


//! Returns the identifier of the field "axlFieldSpatialPointDistance".
/*!
 *
 */
QString axlFieldSpatialPointDistance::identifier(void) const
{
    return "axlFieldSpatialPointDistance";
}


//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlFieldSpatialPointDistance::update(void)
{
    emit updated();
}

// /////////////////////////////////////////////////////////////////
// axlFieldSpatialPointDistance documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlFieldSpatialPointDistance
 *
 *  \brief Class axlFieldSpatialPointDistance defines an API for spatial field.
 *
 */

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createAxlFieldSpatialPointDistance(void)
{
    return new axlFieldSpatialPointDistance;
}

