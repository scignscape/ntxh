/* axlAbstractFieldParametric.cpp ---
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

#include "axlAbstractFieldParametric.h"
#include "axlAbstractProcess.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

class axlAbstractFieldParametricPrivate
{
public:

};

// /////////////////////////////////////////////////////////////////
// axlAbstractFieldParametric implementation
// /////////////////////////////////////////////////////////////////

//!
/*!
 *
 */
axlAbstractFieldParametric::axlAbstractFieldParametric() : axlAbstractField(),  d(new axlAbstractFieldParametricPrivate)
{

}



//! Destroys a parametric field.
/*!
 *
 */
axlAbstractFieldParametric::~axlAbstractFieldParametric(void)
{
    delete d;

    d = NULL;
}


//!Returns number of parameters on which the field is evaluated.
/*!
 *
 */
int axlAbstractFieldParametric::size(void){
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

//! Returns the value of the parametric field at the parameters values in input
/*!
 *
 */
double axlAbstractFieldParametric::scalar(double u, double v, double w)
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
double *axlAbstractFieldParametric::vector(double u, double v, double w)
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
double *axlAbstractFieldParametric::tensor(double u, double v, double w)
{
    if(!(this->kind() == Tensor)) {
        qDebug() << "Getting tensor value on non tensor field.";
        return NULL;
    }

    return NULL;
}



//double axlAbstractFieldParametric::start_u(void){

//    DTK_DEFAULT_IMPLEMENTATION;
//    return 0;
//}

//double axlAbstractFieldParametric::start_v(void){

//    DTK_DEFAULT_IMPLEMENTATION;
//    return 0;
//}

//double axlAbstractFieldParametric::start_w(void){

//    DTK_DEFAULT_IMPLEMENTATION;
//    return 0;
//}

//double axlAbstractFieldParametric::end_u(void){

//    DTK_DEFAULT_IMPLEMENTATION;
//    return 0;
//}

//double axlAbstractFieldParametric::end_v(void){

//    DTK_DEFAULT_IMPLEMENTATION;
//    return 0;
//}

//double axlAbstractFieldParametric::end_w(void){

//    DTK_DEFAULT_IMPLEMENTATION;
//    return 0;
//}

//double axlAbstractFieldParametric::numbersample_u(void){

//    DTK_DEFAULT_IMPLEMENTATION;
//    return 0;
//}

//double axlAbstractFieldParametric::numbersample_v(void){

//    DTK_DEFAULT_IMPLEMENTATION;
//    return 0;
//}

//double axlAbstractFieldParametric::numbersample_w(void){

//    DTK_DEFAULT_IMPLEMENTATION;
//    return 0;
//}



//! Returns the description of the field.
/*!
 *
 */
void axlAbstractFieldParametric::setFunction(axlAbstractData *data){

    DTK_DEFAULT_IMPLEMENTATION;
}


//! Returns the description of the field.
/*!
 *
 */
axlAbstractData *axlAbstractFieldParametric::getFunction(void){
    return NULL;
}

//! Returns the description of the field.
/*!
 *
 */

QString axlAbstractFieldParametric::description(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return QString();

}


//! Returns the description of the field.
/*!
 *
 */

QString axlAbstractFieldParametric::identifier(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return QString();

}

//double axlAbstractFieldParametric::evalX(double u, double v  , double w ){
//    return d->value_point->eval3(u,v,w,0);

//}

//double axlAbstractFieldParametric::evalY(double u, double v , double w ){
//    return d->value_point->eval3(u,v,w,1);
//}

//double axlAbstractFieldParametric::evalZ(double u, double v , double w ){
//    return d->value_point->eval3(u,v,w,2);
//}

//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlAbstractFieldParametric::update(void)
{
    emit updated();
}

// /////////////////////////////////////////////////////////////////
// axlField documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlAbstractFieldParametric
 *
 *  \brief Class axlAbstractFieldParametric defines an API for parametric field.
 *
 */

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlAbstractFieldParametric(void)
{
    return new axlAbstractFieldParametric;
}
