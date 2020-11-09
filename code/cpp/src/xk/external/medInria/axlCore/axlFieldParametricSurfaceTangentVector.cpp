/* axlFieldParametricSurfaceTangentVector.cpp ---
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

#include "axlFieldParametricSurfaceTangentVector.h"
#include "axlAbstractProcess.h"

#include "axlPoint.h"
#include "axlMesh.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

#include "axlAbstractSurfaceBSpline.h"
#include "axlAbstractSurfaceParametric.h"

class axlFieldParametricSurfaceTangentVectorPrivate
{
public:
    axlFieldParametricSurfaceTangentVector::Kind kind;
    axlFieldParametricSurfaceTangentVector::Type type;
    axlFieldParametricSurfaceTangentVector::Support support;

    axlAbstractSurfaceParametric *input;

    //some direction parameters
    double a;
    double b;
};

// /////////////////////////////////////////////////////////////////
// axlFieldParametricSurfaceTangentVector implementation
// /////////////////////////////////////////////////////////////////

//!
/*!
 *
 */
axlFieldParametricSurfaceTangentVector::axlFieldParametricSurfaceTangentVector() : axlAbstractFieldParametricSurface(),  d(new axlFieldParametricSurfaceTangentVectorPrivate)
{
    d->input = NULL;
    this->setObjectName(this->identifier());
    this->setType(axlAbstractField::Double);
    this->setKind(axlAbstractField::Vector);
    this->setSupport(axlAbstractField::Point);
    d->a = 0;
    d->b = 0;


}



//! Destroys a Bspline field.
/*!
 *
 */
axlFieldParametricSurfaceTangentVector::~axlFieldParametricSurfaceTangentVector(void)
{
    delete d;

    d = NULL;
}


//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double *axlFieldParametricSurfaceTangentVector::vector(double u, double v, double w)
{
    if(!(this->kind() == Vector)) {
        qDebug() << "Getting vector value on non vector field.";
        return NULL;
    }
    axlMesh mesh = d->input->eval(u,v,1);
    axlPoint *deriv1u = new axlPoint() ;
    mesh.vertex(1, deriv1u);
    axlPoint *deriv1v = new axlPoint();
    mesh.vertex(2, deriv1v);

    axlPoint tangent = new axlPoint();
    double x = d->a*deriv1u->x() + d->b*deriv1v->x();
    double y = d->a*deriv1u->y() + d->b*deriv1v->y();
    double z = d->a*deriv1u->z() + d->b*deriv1v->z();
    tangent.setCoordinates(x,y,z);


    return tangent.coordinates();

}



//! Returns the identifier of the field "axlFieldParametricSurfaceTangentVector".
/*!
 *
 */
QString axlFieldParametricSurfaceTangentVector::identifier(void) const
{
    return "axlFieldParametricSurfaceTangentVector";
}


//! Returns the description of the field.
/*!
 *
 */
QString axlFieldParametricSurfaceTangentVector::description(void) const
{
    QString qstr;

    qstr.append("axlFieldParametricSurfaceTangentVector : \n");
    qstr.append("Type : Double ");
    qstr.append(";Kind : Vector ");
    qstr.append(";Support : Point");


    return qstr;

}


//! Sets the BSpline on which the BSpline field is applied
/*!
 *
 */
void axlFieldParametricSurfaceTangentVector::setSurface(axlAbstractData *data){
    if(dynamic_cast<axlAbstractSurfaceBSpline*>(data))
        d->input = dynamic_cast<axlAbstractSurfaceBSpline*>(data);
}


//! Sets the direction parameter for the tangentVector
/*!
 *
 */
void axlFieldParametricSurfaceTangentVector::setParameter(double parameter, int channel){
    if(channel == 0)
        d->a = parameter;
    else if(channel == 1)
        d->b = parameter;
    else
        qDebug() << "only two possible channel values : 0 and 1";
}

//! Returns the direction parameter for the tangentVector, for the channel-th.
/*!
 *
 */
double axlFieldParametricSurfaceTangentVector::parameter(int channel){
    if(channel == 0)
        return d->a;
    else if(channel == 1)
        return d->b;
    else {
        qDebug() << "channel has only two values : 0 and 1.";
        return -1;
    }

}


//! Returns the first parameter value of the field.
/*!
 *
 */
double axlFieldParametricSurfaceTangentVector::start_u(void){

    return d->input->startParam_u();

}


//! Returns the first parameter value of the field.
/*!
 *
 */
double axlFieldParametricSurfaceTangentVector::start_v(void){
    return d->input->startParam_v();
}


//! Returns the last parameter value of the field.
/*!
 *
 */
double axlFieldParametricSurfaceTangentVector::end_u(void){

    return d->input->endParam_u();
}


//! Returns the last parameter value of the field.
/*!
 *
 */
double axlFieldParametricSurfaceTangentVector::end_v(void){

    return d->input->endParam_v();
}



//! Returns the number of parameters.
/*!
 *
 */
double axlFieldParametricSurfaceTangentVector::numbersample_u(void){

    return d->input->numSamples_u();
}

//! Returns the number of parameters.
/*!
 *
 */
double axlFieldParametricSurfaceTangentVector::numbersample_v(void){
    return d->input->numSamples_v();
}



//! Returns the number of values evaluated for this BSpline field on each samples of the input BSpline.
/*!
 *
 */
int axlFieldParametricSurfaceTangentVector::size(void){
    return d->input->numSamples_u()*d->input->numSamples_v();
}



//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlFieldParametricSurfaceTangentVector::update(void)
{
    emit updated();
}

// /////////////////////////////////////////////////////////////////
// axlFieldParametricSurfaceTangentVector documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlFieldParametricSurfaceTangentVector
 *
 *  \brief Class axlFieldParametricSurfaceTangentVector defines an API for field which owns a BSpline Surface as a function and a parametric surface on which the field is applied.
 *
 */

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlFieldParametricSurfaceTangentVector(void)
{
    return new axlFieldParametricSurfaceTangentVector;
}
