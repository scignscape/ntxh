/* axlFieldParametricVolume.cpp ---
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

#include "axlFieldParametricVolume.h"
#include "axlAbstractProcess.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

#include "axlAbstractVolumeBSpline.h"
#include "axlAbstractVolumeParametric.h"

class axlFieldParametricVolumePrivate
{
public:
        axlFieldParametricVolume::Kind kind;
        axlFieldParametricVolume::Type type;
        axlFieldParametricVolume::Support support;

    axlAbstractVolumeParametric *input;
    axlAbstractVolumeParametric *function;
};

// /////////////////////////////////////////////////////////////////
// axlFieldParametricVolume implementation
// /////////////////////////////////////////////////////////////////

//!
/*!
 *
 */
axlFieldParametricVolume::axlFieldParametricVolume() : axlAbstractFieldParametricVolume(),  d(new axlFieldParametricVolumePrivate)
{
    d->input = NULL;
    d->function = NULL;
    this->setObjectName(this->identifier());
}



//! Destroys a Bspline field.
/*!
 *
 */
axlFieldParametricVolume::~axlFieldParametricVolume(void)
{
    delete d;

    d = NULL;
}



////! Sets the type of the field which can be either int, float or double.
///*!
// *
// */
//void axlFieldParametricVolume::setType(axlFieldParametricVolume::Type type)
//{

//    d->type = type;
//}

////! Sets the kind of the field which can be either scalar, vector or tensor.
///*!
// *
// */
//void axlFieldParametricVolume::setKind(axlFieldParametricVolume::Kind kind)
//{

//    d->kind = kind;
//}

////!
///*!
// *
// */
//void axlFieldParametricVolume::setSupport(axlFieldParametricVolume::Support support)
//{
//    d->support = support;
//}


//axlFieldParametricVolume::Type axlFieldParametricVolume::type(void)
//{
//    return d->type;
//}

//axlFieldParametricVolume::Kind axlFieldParametricVolume::kind(void)
//{
//    return d->kind;
//}

//axlFieldParametricVolume::Support axlFieldParametricVolume::support(void)
//{
//    return d->support;
//}

//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double axlFieldParametricVolume::scalar(double u, double v , double w)
{
//    if(!(this->kind() == Scalar)) {
//        qDebug() << "Getting scalar value on non scalar field.";
//        return 0;
//    }
    return d->function->eval(u,v,w).x();



}

//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double *axlFieldParametricVolume::vector(double u, double v, double w)
{
//    if(!(this->kind() == Vector)) {
//        qDebug() << "Getting vector value on non vector field.";
//        return NULL;
//    }
    return d->function->eval(u,v,w).coordinates();

}

//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double *axlFieldParametricVolume::tensor(double u, double v, double w)
{
//    if(!(this->kind() == Tensor)) {
//        qDebug() << "Getting tensor value on non tensor field.";
//        return NULL;
//    }

    //TO DO
    return NULL;
}

////! Returns the name the field.
///*!
// *
// */
//QString axlFieldParametricVolume::name(void)
//{
//    return this->objectName() ;
//}

////! Sets the name of the field.
///*!
// *
// */
//void axlFieldParametricVolume::setName(QString name)
//{
//    this->setObjectName(name);

//}

//! Returns the description of the field.
/*!
 *
 */
QString axlFieldParametricVolume::description(void) const
{
    QString qstr;

    qstr.append("axlFieldParametricVolume : \n");


    switch(d->type){
    case axlFieldParametricVolume::Int:
        qstr.append("Type : integer");
        break;
    case axlFieldParametricVolume::Float:
        qstr.append("Type : Float");
        break;
    case axlFieldParametricVolume::Double:
        qstr.append("Type : Double");
        break;
    default:
        qDebug() << "Unsupported field type";
    }


    switch(d->kind) {
    case axlFieldParametricVolume::Scalar:
        qstr.append(";Kind : Scalar");
        break;
    case axlFieldParametricVolume::Vector:
        qstr.append(";Kind : Vector");
        break;
    case axlFieldParametricVolume::Tensor:
        qstr.append(";Kind : Tensor");
        break;
    default:
        qDebug() << ";Unsupported field kind";
    }

    switch(d->support) {
    case axlFieldParametricVolume::Point:
        qstr.append(";Support : Point");
        break;
    case axlFieldParametricVolume::Cell:
        qstr.append(";Support : Cell");
        break;
    case axlFieldParametricVolume::Custom:
        qstr.append(";Support : Custom");
        break;
    default:
        qDebug() << ";No support";
    }

    return qstr;

}


//! Returns the identifier of the field "axlFieldParametricVolume".
/*!
 *
 */
QString axlFieldParametricVolume::identifier(void) const
{

    return "axlFieldParametricVolume";
}

//! Sets the Bspline function which determines the values of the parametric field.
/*!
 *
 */
void axlFieldParametricVolume::setFunction(axlAbstractData *data){
    if(dynamic_cast<axlAbstractVolumeParametric*>(data))
        d->function = dynamic_cast<axlAbstractVolumeParametric*>(data);
}

//! Returns the Bspline function which determines the values of the parametric field.
/*!
 *
 */
axlAbstractData *axlFieldParametricVolume::getFunction(void){
    return d->function;
}

//! Sets the BSpline on which the BSpline field is applied
/*!
 *
 */
void axlFieldParametricVolume::setVolume(axlAbstractData *data){
    if(dynamic_cast<axlAbstractVolumeParametric *>(data))
        d->input = dynamic_cast<axlAbstractVolumeParametric *>(data);
}


//! Returns the first parameter value of the field.
/*!
 *
 */
double axlFieldParametricVolume::start_u(void){

    return d->input->startParam_u();

}


//! Returns the first parameter value of the field.
/*!
 *
 */
double axlFieldParametricVolume::start_v(void){
    return d->input->startParam_v();
}


//! Returns the first parameter value of the field.
/*!
 *
 */
double axlFieldParametricVolume::start_w(void){
    return d->input->startParam_w();
}


//! Returns the last parameter value of the field.
/*!
 *
 */
double axlFieldParametricVolume::end_u(void){

    return d->input->endParam_u();
}


//! Returns the last parameter value of the field.
/*!
 *
 */
double axlFieldParametricVolume::end_v(void){

    return d->input->endParam_v();
}


//! Returns the last parameter value of the field.
/*!
 *
 */
double axlFieldParametricVolume::end_w(void){

    return d->input->endParam_w();
}


//! Returns the number of parameters.
/*!
 *
 */
double axlFieldParametricVolume::numbersample_u(void){

    return d->input->numSamples_u();
}

//! Returns the number of parameters.
/*!
 *
 */
double axlFieldParametricVolume::numbersample_v(void){
    return d->input->numSamples_v();
}


//! Returns the number of parameters.
/*!
 *
 */
double axlFieldParametricVolume::numbersample_w(void){
    return d->input->numSamples_w();
}


//! Returns the number of values evaluated for this BSpline field on each samples of the input BSpline.
/*!
 *
 */
int axlFieldParametricVolume::size(void){
    return d->input->numSamples_u() *d->input->numSamples_v() *d->input->numSamples_w();
}



//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlFieldParametricVolume::update(void)
{
    emit updated();
}

// /////////////////////////////////////////////////////////////////
// axlFieldBSpline documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlFieldParametricVolume
 *
 *  \brief Class axlFieldParametricVolume defines an API for field which owns a BSpline Volume.
 *
 */

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlFieldParametricVolume(void)
{
    return new axlFieldParametricVolume();
}


