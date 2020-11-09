/* axlFieldSpatialCoordinates.cpp ---
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

#include "axlFieldSpatialCoordinates.h"
#include "axlAbstractProcess.h"
#include <axlCore/axlPoint.h>

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

class axlFieldSpatialCoordinatesPrivate
{
public:

//    axlFieldSpatialCoordinates::Kind kind;
//    axlFieldSpatialCoordinates::Type type;
//    axlFieldSpatialCoordinates::Support support;
    double a;
    double b;
    double c;

};

// /////////////////////////////////////////////////////////////////
// axlFieldSpatialCoordinates implementation
// /////////////////////////////////////////////////////////////////

//!
/*!
 *
 */
axlFieldSpatialCoordinates::axlFieldSpatialCoordinates() : axlAbstractFieldSpatial(),  d(new axlFieldSpatialCoordinatesPrivate)
{
    this->setType(axlAbstractField::Float);
    this->setKind(axlAbstractField::Scalar);
    this->setSupport(axlAbstractField::Point);
    this->setObjectName(this->identifier());

    d->a = 0;
    d->b = 0;
    d->c = 1;

}



//! Destroys a spatial field.
/*!
 *
 */
axlFieldSpatialCoordinates::~axlFieldSpatialCoordinates(void)
{
    delete d;

    d = NULL;
}


//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double axlFieldSpatialCoordinates::scalar(double x, double y, double z)
{
    return (d->a*x +d->b*y +d->c*z);
}


//! Sets the coordinates direction.
/*!
 *
 */
void axlFieldSpatialCoordinates::setParameter(double parameter, int channel){

    if(channel == 0)
        d->a = parameter;
    else if(channel ==1)
        d->b = parameter;
    else if(channel ==2)
        d->c = parameter;
    else
        qDebug()<< "3 channels possible : 0 to 2";

}

//! Returns the channel-th parameter value.
/*!
 *
 */
double axlFieldSpatialCoordinates::parameter(int channel){
    if(channel ==0)
        return d->a;
    else if(channel ==1)
        return d->b;
    else if (channel == 2)
        return d->c;
    else {
        qDebug() << "channel has only three possible values : 0 to 2.";
        return -1;
    }

}


//! Returns the description of the field.
/*!
 *
 */
QString axlFieldSpatialCoordinates::description(void) const
{
    QString qstr;

    qstr.append("axlFieldSpatialCoordinates : ");
    qstr.append("Type : Float");
    qstr.append(";Kind : Scalar");
    qstr.append(";Support : Point");

    return qstr;

}

//! Returns the identifier of the field which is "axlFieldSpatialCoordinates".
/*!
 *
 */
QString axlFieldSpatialCoordinates::identifier(void) const
{
    return "axlFieldSpatialCoordinates";

}


//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlFieldSpatialCoordinates::update(void)
{
    emit updated();
}

// /////////////////////////////////////////////////////////////////
// axlFieldSpatialCoordinates documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlFieldSpatialCoordinates
 *
 *  \brief Class axlFieldSpatialCoordinates defines an API for spatial field. The value are computed as follow :
 *   this->scalar(x,y,z) returns a*x+b*y+c*z value with (a,b,c) the direction chosen. By default this direction is equal to (0,0,1).
 */

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlFieldSpatialCoordinates(void)
{
    return new axlFieldSpatialCoordinates;
}
