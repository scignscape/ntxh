/* axlAbstractFieldParametricVolume.cpp ---
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

#include "axlAbstractFieldParametricVolume.h"
#include "axlAbstractProcess.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

class axlAbstractFieldParametricVolumePrivate
{
public:
};

// /////////////////////////////////////////////////////////////////
// axlAbstractFieldParametricVolume implementation
// /////////////////////////////////////////////////////////////////

//!
/*!
 *
 */
axlAbstractFieldParametricVolume::axlAbstractFieldParametricVolume() : axlAbstractFieldParametric(),  d(new axlAbstractFieldParametricVolumePrivate)
{
}



//! Destroys a parametric field.
/*!
 *
 */
axlAbstractFieldParametricVolume::~axlAbstractFieldParametricVolume(void)
{
    delete d;

    d = NULL;
}


//! Sets the support Volume of the field
/*!
 *
 */
void axlAbstractFieldParametricVolume::setVolume(axlAbstractData *Volume){

    DTK_DEFAULT_IMPLEMENTATION;
}

//! Returns number of parameters on which the field is evaluated.
/*!
 *
 */
int axlAbstractFieldParametricVolume::size(void){
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

//! Returns the value of the parametric field at the parameters values in input
/*!
 *
 */
double axlAbstractFieldParametricVolume::scalar(double u, double v, double w)
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
double *axlAbstractFieldParametricVolume::vector(double u, double v, double w)
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
double *axlAbstractFieldParametricVolume::tensor(double u, double v, double w)
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
double axlAbstractFieldParametricVolume::start_u(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


//! Returns the first v-value parameter.
/*!
 *
 */
double axlAbstractFieldParametricVolume::start_v(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


//! Returns the first w-value parameter.
/*!
 *
 */
double axlAbstractFieldParametricVolume::start_w(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


//! Returns the last u-value parameter.
/*!
 *
 */
double axlAbstractFieldParametricVolume::end_u(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


//! Returns the last v-value parameter.
/*!
 *
 */
double axlAbstractFieldParametricVolume::end_v(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


//! Returns the last w-value parameter.
/*!
 *
 */
double axlAbstractFieldParametricVolume::end_w(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


//! Returns the number of u-parameters.
/*!
 *
 */
double axlAbstractFieldParametricVolume::numbersample_u(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


//! Returns the number of v-parameters.
/*!
 *
 */
double axlAbstractFieldParametricVolume::numbersample_v(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


//! Returns the number of w-parameters.
/*!
 *
 */
double axlAbstractFieldParametricVolume::numbersample_w(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}



//! Returns the description of the field.
/*!
 *
 */
void axlAbstractFieldParametricVolume::setFunction(axlAbstractData *data){

    DTK_DEFAULT_IMPLEMENTATION;
}


//! Returns the description of the field.
/*!
 *
 */
axlAbstractData *axlAbstractFieldParametricVolume::getFunction(void){
    return NULL;
}

//! Returns the description of the field.
/*!
 *
 */

QString axlAbstractFieldParametricVolume::description(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return QString();

}


//! Returns the description of the field.
/*!
 *
 */

QString axlAbstractFieldParametricVolume::identifier(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return QString();

}

//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlAbstractFieldParametricVolume::update(void)
{
    emit updated();
}

// /////////////////////////////////////////////////////////////////
// axlField documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlAbstractFieldParametricVolume
 *
 *  \brief Class axlAbstractFieldParametricVolume defines an API for parametric field.
 *
 */

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlAbstractFieldParametricVolume(void)
{
    return new axlAbstractFieldParametricVolume;
}


