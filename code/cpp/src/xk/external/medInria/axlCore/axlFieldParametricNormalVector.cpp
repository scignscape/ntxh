/* axlFieldParametricNormalVector.cpp ---
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

#include "axlFieldParametricNormalVector.h"
#include "axlAbstractProcess.h"

#include "axlPoint.h"
#include "axlMesh.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

#include "axlAbstractSurfaceBSpline.h"
#include "axlAbstractSurfaceParametric.h"

class axlFieldParametricNormalVectorPrivate
{
public:
    axlFieldParametricNormalVector::Kind kind;
    axlFieldParametricNormalVector::Type type;
    axlFieldParametricNormalVector::Support support;

    axlAbstractSurfaceParametric *input;
};

// /////////////////////////////////////////////////////////////////
// axlFieldParametricNormalVector implementation
// /////////////////////////////////////////////////////////////////

//!
/*!
 *
 */
axlFieldParametricNormalVector::axlFieldParametricNormalVector() : axlAbstractFieldParametricSurface(),  d(new axlFieldParametricNormalVectorPrivate)
{
    d->input = NULL;
    this->setObjectName(this->identifier());
    this->setType(axlAbstractField::Double);
    this->setKind(axlAbstractField::Vector);
    this->setSupport(axlAbstractField::Point);
}



//! Destroys a Bspline field.
/*!
 *
 */
axlFieldParametricNormalVector::~axlFieldParametricNormalVector(void)
{
    delete d;

    d = NULL;
}


//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double *axlFieldParametricNormalVector::vector(double u, double v, double w)
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
    axlPoint *normalPoint = axlPoint::crossProduct(deriv1u, deriv1v);
    double *normal = normalPoint->coordinates();
    //qDebug() << Q_FUNC_INFO << u <<  " " <<v << " " << normal[0] << " " << normal[1]<<" " << normal[2] ;

    return normal;

}



//! Returns the identifier of the field "axlFieldParametricNormalVector".
/*!
 *
 */
QString axlFieldParametricNormalVector::identifier(void) const
{
    return "axlFieldParametricNormalVector";
}


//! Returns the description of the field.
/*!
 *
 */
QString axlFieldParametricNormalVector::description(void) const
{
    QString qstr;

    qstr.append("axlFieldParametricNormalVector : \n");
    qstr.append("Type : Double ");
    qstr.append(";Kind : Vector ");
    qstr.append(";Support : Point");


    return qstr;

}


//! Sets the BSpline on which the BSpline field is applied
/*!
 *
 */
void axlFieldParametricNormalVector::setSurface(axlAbstractData *data){
    if(dynamic_cast<axlAbstractSurfaceBSpline*>(data))
        d->input = dynamic_cast<axlAbstractSurfaceBSpline*>(data);
}


//! Returns the first parameter value of the field.
/*!
 *
 */
double axlFieldParametricNormalVector::start_u(void){

    return d->input->startParam_u();

}


//! Returns the first parameter value of the field.
/*!
 *
 */
double axlFieldParametricNormalVector::start_v(void){
    return d->input->startParam_v();
}


//! Returns the last parameter value of the field.
/*!
 *
 */
double axlFieldParametricNormalVector::end_u(void){

    return d->input->endParam_u();
}


//! Returns the last parameter value of the field.
/*!
 *
 */
double axlFieldParametricNormalVector::end_v(void){

    return d->input->endParam_v();
}



//! Returns the number of parameters.
/*!
 *
 */
double axlFieldParametricNormalVector::numbersample_u(void){

    return d->input->numSamples_u();
}

//! Returns the number of parameters.
/*!
 *
 */
double axlFieldParametricNormalVector::numbersample_v(void){
    return d->input->numSamples_v();
}



//! Returns the number of values evaluated for this BSpline field on each samples of the input BSpline.
/*!
 *
 */
int axlFieldParametricNormalVector::size(void){
    return d->input->numSamples_u()*d->input->numSamples_v();
}



//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlFieldParametricNormalVector::update(void)
{
    emit updated();
}

// /////////////////////////////////////////////////////////////////
// axlFieldParametricNormalVector documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlFieldParametricNormalVector
 *
 *  \brief Class axlFieldParametricNormalVector defines an API for field which owns a BSpline Surface as a function and a parametric surface on which the field is applied.
 *
 */

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlFieldParametricNormalVector(void)
{
    return new axlFieldParametricNormalVector;
}


