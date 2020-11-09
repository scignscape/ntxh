/* axlAbstractFieldParametricCurve.cpp ---
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

#include "axlAbstractFieldParametricCurve.h"
#include "axlAbstractProcess.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

class axlAbstractFieldParametricCurvePrivate
{
public:
};

// /////////////////////////////////////////////////////////////////
// axlAbstractFieldParametricCurve implementation
// /////////////////////////////////////////////////////////////////

//!
/*!
 *
 */
axlAbstractFieldParametricCurve::axlAbstractFieldParametricCurve() : axlAbstractFieldParametric(),  d(new axlAbstractFieldParametricCurvePrivate)
{
}



//! Destroys a parametric field.
/*!
 *
 */
axlAbstractFieldParametricCurve::~axlAbstractFieldParametricCurve(void)
{
    delete d;

    d = NULL;
}


//! Sets the support Curve of the field
/*!
 *
 */
void axlAbstractFieldParametricCurve::setCurve(axlAbstractData *Curve){

    DTK_DEFAULT_IMPLEMENTATION;
}

//! Returns number of parameters on which the field is evaluated.
/*!
 *
 */
int axlAbstractFieldParametricCurve::size(void){
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

//! Returns the value of the parametric field at the parameters values in input
/*!
 *
 */
double axlAbstractFieldParametricCurve::scalar(double u, double v, double w)
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
double *axlAbstractFieldParametricCurve::vector(double u, double v, double w)
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
double *axlAbstractFieldParametricCurve::tensor(double u, double v, double w)
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
double axlAbstractFieldParametricCurve::start_u(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


//! Returns the last v-value parameter.
/*!
 *
 */
double axlAbstractFieldParametricCurve::end_u(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}



//! Returns the number of u-parameters.
/*!
 *
 */
double axlAbstractFieldParametricCurve::numbersample_u(void){

    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}


//! Returns the description of the field.
/*!
 *
 */
void axlAbstractFieldParametricCurve::setFunction(axlAbstractData *data){

    DTK_DEFAULT_IMPLEMENTATION;
}


//! Returns the description of the field.
/*!
 *
 */
axlAbstractData *axlAbstractFieldParametricCurve::getFunction(void){
    return NULL;
}

//! Returns the description of the field.
/*!
 *
 */

QString axlAbstractFieldParametricCurve::description(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return QString();

}


//! Returns the description of the field.
/*!
 *
 */

QString axlAbstractFieldParametricCurve::identifier(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return QString();

}

//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlAbstractFieldParametricCurve::update(void)
{
    emit updated();
}

// /////////////////////////////////////////////////////////////////
// axlField documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlAbstractFieldParametricCurve
 *
 *  \brief Class axlAbstractFieldParametricCurve defines an API for parametric field.
 *
 */

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlAbstractFieldParametricCurve(void)
{
    return new axlAbstractFieldParametricCurve;
}


