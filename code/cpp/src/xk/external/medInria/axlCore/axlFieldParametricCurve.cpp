/* axlFieldParametricCurve.cpp ---
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

#include "axlFieldParametricCurve.h"
#include "axlAbstractProcess.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

#include "axlAbstractCurveBSpline.h"
#include "axlAbstractCurveParametric.h"

class axlFieldParametricCurvePrivate
{
public:
    axlFieldParametricCurve::Kind kind;
    axlFieldParametricCurve::Type type;
    axlFieldParametricCurve::Support support;

    axlAbstractCurveParametric *input;
    axlAbstractCurveParametric *function;
};

// /////////////////////////////////////////////////////////////////
// axlFieldParametricCurve implementation
// /////////////////////////////////////////////////////////////////

//!
/*!
 *
 */
axlFieldParametricCurve::axlFieldParametricCurve() : axlAbstractFieldParametricCurve(),  d(new axlFieldParametricCurvePrivate)
{
    d->input = NULL;
    d->function = NULL;
    this->setObjectName(this->identifier());
}



//! Destroys a Bspline field.
/*!
 *
 */
axlFieldParametricCurve::~axlFieldParametricCurve(void)
{
    delete d;

    d = NULL;
}



////! Sets the type of the field which can be either int, float or double.
///*!
// *
// */
//void axlFieldParametricCurve::setType(axlFieldParametricCurve::Type type)
//{

//    d->type = type;
//}

////! Sets the kind of the field which can be either scalar, vector or tensor.
///*!
// *
// */
//void axlFieldParametricCurve::setKind(axlFieldParametricCurve::Kind kind)
//{

//    d->kind = kind;
//}

////!
///*!
// *
// */
//void axlFieldParametricCurve::setSupport(axlFieldParametricCurve::Support support)
//{
//    d->support = support;
//}


//axlFieldParametricCurve::Type axlFieldParametricCurve::type(void)
//{
//    return d->type;
//}

//axlFieldParametricCurve::Kind axlFieldParametricCurve::kind(void)
//{
//    return d->kind;
//}

//axlFieldParametricCurve::Support axlFieldParametricCurve::support(void)
//{
//    return d->support;
//}

//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double axlFieldParametricCurve::scalar(double u, double v, double w)
{
    if(!(this->kind() == Scalar)) {
        qDebug() << "Getting scalar value on non scalar field.";
        return 0;
    }
    return d->function->eval(u).x();



}

//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double *axlFieldParametricCurve::vector(double u, double v, double w)
{
    if(!(this->kind() == Vector)) {
        qDebug() << "Getting vector value on non vector field.";
        return NULL;
    }
    return d->function->eval(u).coordinates();

}

//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double *axlFieldParametricCurve::tensor(double u, double v, double w)
{
    if(!(this->kind() == Tensor)) {
        qDebug() << "Getting tensor value on non tensor field.";
        return NULL;
    }
    return NULL;
}

////! Returns the name the field.
///*!
// *
// */
//QString axlFieldParametricCurve::name(void)
//{
//    return this->name() ;
//}

////! Sets the name of the field.
///*!
// *
// */
//void axlFieldParametricCurve::setName(QString name)
//{
//    this->setObjectName(name);

//}

//! Returns the description of the field.
/*!
 *
 */

QString axlFieldParametricCurve::description(void) const
{
    QString qstr;

    qstr.append("axlFieldParametricCurve : \n");

    switch(d->type){
    case axlFieldParametricCurve::Int:
        qstr.append("Type : integer");
        break;
    case axlFieldParametricCurve::Float:
        qstr.append("Type : Float");
        break;
    case axlFieldParametricCurve::Double:
        qstr.append("Type : Double");
        break;
    default:
        qDebug() << "Unsupported field type";
    }


    switch(d->kind) {
    case axlFieldParametricCurve::Scalar:
        qstr.append(";Kind : Scalar");
        break;
    case axlFieldParametricCurve::Vector:
        qstr.append(";Kind : Vector");
        break;
    case axlFieldParametricCurve::Tensor:
        qstr.append(";Kind : Tensor");
        break;
    default:
        qDebug() << ";Unsupported field kind";
    }

    switch(d->support) {
    case axlFieldParametricCurve::Point:
        qstr.append(";Support : Point");
        break;
    case axlFieldParametricCurve::Cell:
        qstr.append(";Support : Cell");
        break;
    case axlFieldParametricCurve::Custom:
        qstr.append(";Support : Custom");
        break;
    default:
        qDebug() << ";No support";
    }

    return qstr;

}


//! Returns the identifier of the field "axlFieldParametricCurve".
/*!
 *
 */

QString axlFieldParametricCurve::identifier(void) const
{
    return "axlFieldParametricCurve";
}

//! Sets the Bspline function which determines the values of the BSpline field.
/*!
 *
 */
void axlFieldParametricCurve::setFunction(axlAbstractData *data){
    if(dynamic_cast<axlAbstractCurveParametric*>(data))
        d->function = dynamic_cast<axlAbstractCurveParametric*>(data);
}

//! Returns the Bspline function which determines the values of the BSpline field.
/*!
 *
 */
axlAbstractData *axlFieldParametricCurve::getFunction(void){
    return d->function;

}

//! Sets the curve on which the parametric field is applied
/*!
 *
 */
void axlFieldParametricCurve::setCurve(axlAbstractData *data){
    if(dynamic_cast<axlAbstractCurveParametric *>(data))
        d->input = dynamic_cast<axlAbstractCurveParametric *>(data);
}


//! Returns the first parameter value of the field.
/*!
 *
 */
double axlFieldParametricCurve::start_u(void){
    return d->input->startParam();
}



//! Returns the last parameter value of the field.
/*!
 *
 */
double axlFieldParametricCurve::end_u(void){
    return d->input->endParam();
}



//! Returns the number of parameters.
/*!
 *
 */
double axlFieldParametricCurve::numbersample_u(void){
    return d->input->numSamples();
}


//! Returns the number of values evaluated for this parametric field on each samples of the input curve.
/*!
 *
 */
int axlFieldParametricCurve::size(void){
    return d->input->numSamples();
}



//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlFieldParametricCurve::update(void)
{
    emit updated();
}

// /////////////////////////////////////////////////////////////////
// axlFieldBSpline documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlFieldParametricCurve
 *
 *  \brief Class axlFieldParametricCurve defines an API for field which owns a BSpline curve.
 *
 */

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlFieldParametricCurve(void)
{
    return new axlFieldParametricCurve();
}


