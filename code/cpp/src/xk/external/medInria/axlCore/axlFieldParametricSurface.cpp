/* axlFieldParametricSurface.cpp ---
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

#include "axlFieldParametricSurface.h"
#include "axlAbstractProcess.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

#include "axlAbstractSurfaceBSpline.h"
#include "axlAbstractSurfaceParametric.h"

class axlFieldParametricSurfacePrivate
{
public:
    axlFieldParametricSurface::Kind kind;
    axlFieldParametricSurface::Type type;
    axlFieldParametricSurface::Support support;

    axlAbstractSurfaceParametric *input;
    axlAbstractSurfaceParametric *function;
};

// /////////////////////////////////////////////////////////////////
// axlFieldParametricSurface implementation
// /////////////////////////////////////////////////////////////////

//!
/*!
 *
 */
axlFieldParametricSurface::axlFieldParametricSurface() : axlAbstractFieldParametricSurface(),  d(new axlFieldParametricSurfacePrivate)
{
    d->input = NULL;
    d->function = NULL;
    this->setObjectName(this->identifier());
}



//! Destroys a Bspline field.
/*!
 *
 */
axlFieldParametricSurface::~axlFieldParametricSurface(void)
{
    delete d;

    d = NULL;
}



////! Sets the type of the field which can be either int, float or double.
///*!
// *
// */
//void axlFieldParametricSurface::setType(axlFieldParametricSurface::Type type)
//{

//    d->type = type;
//}

////! Sets the kind of the field which can be either scalar, vector or tensor.
///*!
// *
// */
//void axlFieldParametricSurface::setKind(axlFieldParametricSurface::Kind kind)
//{

//    d->kind = kind;
//}

////!
///*!
// *
// */
//void axlFieldParametricSurface::setSupport(axlFieldParametricSurface::Support support)
//{
//    d->support = support;
//}


//axlFieldParametricSurface::Type axlFieldParametricSurface::type(void)
//{
//    return d->type;
//}

//axlFieldParametricSurface::Kind axlFieldParametricSurface::kind(void)
//{
//    return d->kind;
//}

//axlFieldParametricSurface::Support axlFieldParametricSurface::support(void)
//{
//    return d->support;
//}

//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double axlFieldParametricSurface::scalar(double u, double v, double w)
{
    if(!(this->kind() == Scalar)) {
        qDebug() << "Getting scalar value on non scalar field.";
        return 0;
    }
    if(d->function){
        return d->function->eval(u,v).x();
    } else
        return 0;
}

//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double *axlFieldParametricSurface::vector(double u, double v, double w)
{
    if(!(this->kind() == Vector)) {
        qDebug() << "Getting vector value on non vector field.";
        return NULL;
    }
    return d->function->eval(u,v).coordinates();

}

//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double *axlFieldParametricSurface::tensor(double u, double v, double w)
{
    if(!(this->kind() == Tensor)) {
        qDebug() << "Getting tensor value on non tensor field.";
        return NULL;
    }
    // TO DO
    return NULL;
}

////! Returns the name the field.
///*!
// *
// */
//QString axlFieldParametricSurface::name(void)
//{
//    return this->objectName() ;
//}

////! Sets the name of the field.
///*!
// *
// */
//void axlFieldParametricSurface::setName(QString name)
//{
//    this->setObjectName(name);

//}


//! Returns the identifier of the field "axlFieldParametricSurface".
/*!
 *
 */
QString axlFieldParametricSurface::identifier(void) const
{
    return "axlFieldParametricSurface";
}

//! Returns the description of the field.
/*!
 *
 */
QString axlFieldParametricSurface::description(void) const
{
    QString qstr;

    qstr.append("axlFieldParametricSurface : \n");

    switch(d->type){
    case axlFieldParametricSurface::Int:
        qstr.append("Type : integer");
        break;
    case axlFieldParametricSurface::Float:
        qstr.append("Type : Float");
        break;
    case axlFieldParametricSurface::Double:
        qstr.append("Type : Double");
        break;
    default:
        qDebug() << "Unsupported field type";
    }


    switch(d->kind) {
    case axlFieldParametricSurface::Scalar:
        qstr.append(";Kind : Scalar");
        break;
    case axlFieldParametricSurface::Vector:
        qstr.append(";Kind : Vector");
        break;
    case axlFieldParametricSurface::Tensor:
        qstr.append(";Kind : Tensor");
        break;
    default:
        qDebug() << ";Unsupported field kind";
    }

    switch(d->support) {
    case axlFieldParametricSurface::Point:
        qstr.append(";Support : Point");
        break;
    case axlFieldParametricSurface::Cell:
        qstr.append(";Support : Cell");
        break;
    case axlFieldParametricSurface::Custom:
        qstr.append(";Support : Custom");
        break;
    default:
        qDebug() << ";No support";
    }

    return qstr;

}

//! Sets the Bspline function which determines the values of the parametric field.
/*!
 *
 */
void axlFieldParametricSurface::setFunction(axlAbstractData *data){
    qDebug() << Q_FUNC_INFO << 1;
    if(dynamic_cast<axlAbstractSurfaceParametric*>(data)){
        qDebug() << Q_FUNC_INFO << 2;
        d->function = dynamic_cast<axlAbstractSurfaceParametric*>(data);
    }
}


//! Returns the Bspline function which determines the values of the parametric field.
/*!
 *
 */
axlAbstractData *axlFieldParametricSurface::getFunction(void){
    return d->function;
}

//! Sets the BSpline on which the BSpline field is applied
/*!
 *
 */
void axlFieldParametricSurface::setSurface(axlAbstractData *data){
    if(dynamic_cast<axlAbstractSurfaceBSpline*>(data))
        d->input = dynamic_cast<axlAbstractSurfaceBSpline*>(data);
}


//! Returns the first parameter value of the field.
/*!
 *
 */
double axlFieldParametricSurface::start_u(void){

    return d->input->startParam_u();

}


//! Returns the first parameter value of the field.
/*!
 *
 */
double axlFieldParametricSurface::start_v(void){
    return d->input->startParam_v();
}


//! Returns the last parameter value of the field.
/*!
 *
 */
double axlFieldParametricSurface::end_u(void){

    return d->input->endParam_u();
}


//! Returns the last parameter value of the field.
/*!
 *
 */
double axlFieldParametricSurface::end_v(void){

    return d->input->endParam_v();
}



//! Returns the number of parameters.
/*!
 *
 */
double axlFieldParametricSurface::numbersample_u(void){

    return d->input->numSamples_u();
}

//! Returns the number of parameters.
/*!
 *
 */
double axlFieldParametricSurface::numbersample_v(void){
    return d->input->numSamples_v();
}



//! Returns the number of values evaluated for this BSpline field on each samples of the input BSpline.
/*!
 *
 */
int axlFieldParametricSurface::size(void){
    return d->input->numSamples_u()*d->input->numSamples_v();
}



//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlFieldParametricSurface::update(void)
{
    emit updated();
}

// /////////////////////////////////////////////////////////////////
// axlFieldParametricSurface documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlFieldParametricSurface
 *
 *  \brief Class axlFieldParametricSurface defines an API for field which owns a BSpline Surface as a function and a parametric surface on which the field is applied.
 *
 */

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlFieldParametricSurface(void)
{
    return new axlFieldParametricSurface;
}


