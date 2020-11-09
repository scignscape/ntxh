/* axlFieldParametricVolumeTangentVector.cpp ---
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

#include "axlFieldParametricVolumeTangentVector.h"
#include "axlAbstractProcess.h"

#include "axlPoint.h"
#include "axlMesh.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

#include "axlAbstractVolumeParametric.h"

class axlFieldParametricVolumeTangentVectorPrivate
{
public:
    axlFieldParametricVolumeTangentVector::Kind kind;
    axlFieldParametricVolumeTangentVector::Type type;
    axlFieldParametricVolumeTangentVector::Support support;

    axlAbstractVolumeParametric *input;

    //some direction parameters
    double a;
    double b;
    double c;
};

// /////////////////////////////////////////////////////////////////
// axlFieldParametricVolumeTangentVector implementation
// /////////////////////////////////////////////////////////////////

//!
/*!
 *
 */
axlFieldParametricVolumeTangentVector::axlFieldParametricVolumeTangentVector() : axlAbstractFieldParametricVolume(),  d(new axlFieldParametricVolumeTangentVectorPrivate)
{
    d->input = NULL;
    this->setObjectName(this->identifier());
    this->setType(axlAbstractField::Double);
    this->setKind(axlAbstractField::Vector);
    this->setSupport(axlAbstractField::Point);
    d->a = 0;
    d->b = 0;
    d->c = 0;


}



//! Destroys a Bspline field.
/*!
 *
 */
axlFieldParametricVolumeTangentVector::~axlFieldParametricVolumeTangentVector(void)
{
    delete d;

    d = NULL;
}


//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double *axlFieldParametricVolumeTangentVector::vector(double u, double v, double w)
{
    // qDebug() << Q_FUNC_INFO << 1;
    //    if(!(this->kind() == Vector)) {
    //        qDebug() << "Getting vector value on non vector field.";
    //        return NULL;
    //    }
    axlMesh mesh = d->input->eval(u,v,w,1);
    //qDebug() << Q_FUNC_INFO << 2 << " "<< mesh.size();
    axlPoint *deriv1u = new axlPoint() ;
    mesh.vertex(1, deriv1u);
    axlPoint *deriv1v = new axlPoint();
    mesh.vertex(2, deriv1v);
    axlPoint *deriv1w = new axlPoint();
    mesh.vertex(3, deriv1w);


    double x = d->a*deriv1u->x() + d->b*deriv1v->x() + d->c*deriv1w->x();
    double y = d->a*deriv1u->y() + d->b*deriv1v->y()+ d->c*deriv1w->y();
    double z = d->a*deriv1u->z() + d->b*deriv1v->z()+ d->c*deriv1w->z();
    double *tangentTab = new double[3];
    tangentTab[0] = x;
    tangentTab[1] = y;
    tangentTab[2] = z;

    //qDebug() << Q_FUNC_INFO << tangentTab[0] << " " << tangentTab[1] << " "<< tangentTab[2];
    return tangentTab;

}



//! Returns the identifier of the field "axlFieldParametricVolumeTangentVector".
/*!
 *
 */
QString axlFieldParametricVolumeTangentVector::identifier(void) const
{
    return "axlFieldParametricVolumeTangentVector";
}


//! Returns the description of the field.
/*!
 *
 */
QString axlFieldParametricVolumeTangentVector::description(void) const
{
    QString qstr;

    qstr.append("axlFieldParametricVolumeTangentVector : \n");
    qstr.append("Type : Double ");
    qstr.append(";Kind : Vector ");
    qstr.append(";Support : Point");


    return qstr;

}


//! Sets the BSpline on which the BSpline field is applied
/*!
 *
 */
void axlFieldParametricVolumeTangentVector::setVolume(axlAbstractData *data){
    if(dynamic_cast<axlAbstractVolumeParametric*>(data))
        d->input = dynamic_cast<axlAbstractVolumeParametric*>(data);
}


//! Sets the direction parameter for the tangentVector
/*!
 *
 */
void axlFieldParametricVolumeTangentVector::setParameter(double parameter, int channel){
    if(channel == 0)
        d->a = parameter;
    else if(channel == 1)
        d->b = parameter;
    else if(channel ==2)
        d->c = parameter;
    else
        qDebug() << "only three possible channel values : 0 to 2";
}

//! Returns the direction parameter for the tangentVector, the channel-th one.
/*!
 *
 */
double axlFieldParametricVolumeTangentVector::parameter(int channel){
    if(channel == 0)
        return d->a;
    else if(channel == 1)
        return d->b;
    else if(channel ==2)
        return d->c;
    else {
        qDebug() << "only three possible channel values : 0 to 2";
        return -1;
    }
}


//! Returns the first parameter value of the field.
/*!
 *
 */
double axlFieldParametricVolumeTangentVector::start_u(void){

    return d->input->startParam_u();

}


//! Returns the first parameter value of the field.
/*!
 *
 */
double axlFieldParametricVolumeTangentVector::start_v(void){
    return d->input->startParam_v();
}

//! Returns the first parameter value of the field.
/*!
 *
 */
double axlFieldParametricVolumeTangentVector::start_w(void){
    return d->input->startParam_w();
}



//! Returns the last parameter value of the field.
/*!
 *
 */
double axlFieldParametricVolumeTangentVector::end_u(void){

    return d->input->endParam_u();
}


//! Returns the last parameter value of the field.
/*!
 *
 */
double axlFieldParametricVolumeTangentVector::end_v(void){

    return d->input->endParam_v();
}



//! Returns the last parameter value of the field.
/*!
 *
 */
double axlFieldParametricVolumeTangentVector::end_w(void){

    return d->input->endParam_w();
}



//! Returns the number of parameters.
/*!
 *
 */
double axlFieldParametricVolumeTangentVector::numbersample_u(void){

    return d->input->numSamples_u();
}

//! Returns the number of parameters.
/*!
 *
 */
double axlFieldParametricVolumeTangentVector::numbersample_v(void){
    return d->input->numSamples_v();
}


//! Returns the number of parameters.
/*!
 *
 */
double axlFieldParametricVolumeTangentVector::numbersample_w(void){
    return d->input->numSamples_w();
}


//! Returns the number of values evaluated for this BSpline field on each samples of the input BSpline.
/*!
 *
 */
int axlFieldParametricVolumeTangentVector::size(void){
    return d->input->numSamples_u()*d->input->numSamples_v()*d->input->numSamples_w();
}



//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlFieldParametricVolumeTangentVector::update(void)
{
    emit updated();
}

// /////////////////////////////////////////////////////////////////
// axlFieldParametricVolumeTangentVector documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlFieldParametricVolumeTangentVector
 *
 *  \brief Class axlFieldParametricVolumeTangentVector defines an API for field which owns a BSpline Surface as a function and a parametric surface on which the field is applied.
 *
 */

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlFieldParametricVolumeTangentVector(void)
{
    return new axlFieldParametricVolumeTangentVector;
}
