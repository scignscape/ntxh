/* axlAbstractFieldParametricSurface.cpp ---
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

#include "axlAbstractFieldParametricSurface.h"
#include "axlAbstractProcess.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

class axlAbstractFieldParametricSurfacePrivate
{
public:
};

// /////////////////////////////////////////////////////////////////
// axlAbstractFieldParametricSurface implementation
// /////////////////////////////////////////////////////////////////

//!
/*!
 *
 */
axlAbstractFieldParametricSurface::axlAbstractFieldParametricSurface() : axlAbstractFieldParametric(),  d(new axlAbstractFieldParametricSurfacePrivate)
{
}



//! Destroys a parametric field.
/*!
 *
 */
axlAbstractFieldParametricSurface::~axlAbstractFieldParametricSurface(void)
{
    delete d;

    d = NULL;
}


//! Sets the support surface of the field
/*!
 *
 */
void axlAbstractFieldParametricSurface::setSurface(axlAbstractData *surface){

    DTK_DEFAULT_IMPLEMENTATION;
}

//! Returns number of parameters on which the field is evaluated.
/*!
 *
 */
int axlAbstractFieldParametricSurface::size(void){
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

//! Returns the value of the parametric field at the parameters values in input
/*!
 *
 */
double axlAbstractFieldParametricSurface::scalar(double u, double v, double w)
{
    if(!(this->kind() == Scalar)) {
        qDebug() << "Getting scalar value on non scalar field.";
        return 0;
    }
    return 0;
}

//! Returns the value of the parametric field evaluated at the parameters in input
/*!
 *
 */
double *axlAbstractFieldParametricSurface::vector(double u, double v, double w)
{
    if(!(this->kind() == Vector)) {
        qDebug() << "Getting vector value on non vector field.";
        return NULL;
    }
    return NULL;
}

//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double *axlAbstractFieldParametricSurface::tensor(double u, double v, double w)
{
    if(!(this->kind() == Tensor)) {
        qDebug() << "Getting tensor value on non tensor field.";
        return NULL;
    }

    return NULL;
}


//! Returns the first u-value parameter.
/*!
 *
 */
double axlAbstractFieldParametricSurface::start_u(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


//! Returns the first v-value parameter.
/*!
 *
 */
double axlAbstractFieldParametricSurface::start_v(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

//double axlAbstractFieldParametricSurface::start_w(void){

//    DTK_DEFAULT_IMPLEMENTATION;
//    return 0;
//}


//! Returns the last v-value parameter.
/*!
 *
 */
double axlAbstractFieldParametricSurface::end_u(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


//! Returns the last v-value parameter.
/*!
 *
 */
double axlAbstractFieldParametricSurface::end_v(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

//double axlAbstractFieldParametricSurface::end_w(void){

//    DTK_DEFAULT_IMPLEMENTATION;
//    return 0;
//}


//! Returns the number of u-parameters.
/*!
 *
 */
double axlAbstractFieldParametricSurface::numbersample_u(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


//! Returns the number of v-parameters.
/*!
 *
 */
double axlAbstractFieldParametricSurface::numbersample_v(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

//double axlAbstractFieldParametricSurface::numbersample_w(void){

//    DTK_DEFAULT_IMPLEMENTATION;
//    return 0;
//}



//! Returns the description of the field.
/*!
 *
 */
void axlAbstractFieldParametricSurface::setFunction(axlAbstractData *data){

    DTK_DEFAULT_IMPLEMENTATION;
}


//! Returns the description of the field.
/*!
 *
 */
axlAbstractData *axlAbstractFieldParametricSurface::getFunction(void){
    return NULL;
}

//! Returns the description of the field.
/*!
 *
 */

QString axlAbstractFieldParametricSurface::description(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return QString();

}


//! Returns the description of the field.
/*!
 *
 */

QString axlAbstractFieldParametricSurface::identifier(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return QString();

}

//double axlAbstractFieldParametricSurface::evalX(double u, double v  , double w ){
//    return d->value_point->eval3(u,v,w,0);

//}

//double axlAbstractFieldParametricSurface::evalY(double u, double v , double w ){
//    return d->value_point->eval3(u,v,w,1);
//}

//double axlAbstractFieldParametricSurface::evalZ(double u, double v , double w ){
//    return d->value_point->eval3(u,v,w,2);
//}

//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlAbstractFieldParametricSurface::update(void)
{
    emit updated();
}

// /////////////////////////////////////////////////////////////////
// axlField documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlAbstractFieldParametricSurface
 *
 *  \brief Class axlAbstractFieldParametricSurface defines an API for parametric field.
 *
 */

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlAbstractFieldParametricSurface(void)
{
    return new axlAbstractFieldParametricSurface;
}

