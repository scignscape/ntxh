/* axlFieldParametricCurveTangentVector.cpp ---
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

#include "axlFieldParametricCurveTangentVector.h"
#include "axlAbstractProcess.h"

#include "axlPoint.h"
#include "axlMesh.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

#include "axlAbstractCurveParametric.h"

class axlFieldParametricCurveTangentVectorPrivate
{
public:
    axlFieldParametricCurveTangentVector::Kind kind;
    axlFieldParametricCurveTangentVector::Type type;
    axlFieldParametricCurveTangentVector::Support support;

    axlAbstractCurveParametric *input;
};

// /////////////////////////////////////////////////////////////////
// axlFieldParametricCurveTangentVector implementation
// /////////////////////////////////////////////////////////////////

//!
/*!
 *
 */
axlFieldParametricCurveTangentVector::axlFieldParametricCurveTangentVector() : axlAbstractFieldParametricCurve(),  d(new axlFieldParametricCurveTangentVectorPrivate)
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
axlFieldParametricCurveTangentVector::~axlFieldParametricCurveTangentVector(void)
{
    delete d;

    d = NULL;
}


//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double *axlFieldParametricCurveTangentVector::vector(double u, double v, double w)
{
    if(!(this->kind() == Vector)) {
        qDebug() << "Getting vector value on non vector field.";
        return NULL;
    }
    axlMesh mesh = d->input->eval(u,1);
    axlPoint *deriv1u = new axlPoint() ;
    mesh.vertex(1, deriv1u);
    double *tangent = deriv1u->coordinates();

    return tangent;

}



//! Returns the identifier of the field "axlFieldParametricCurveTangentVector".
/*!
 *
 */
QString axlFieldParametricCurveTangentVector::identifier(void) const
{
    return "axlFieldParametricCurveTangentVector";
}


//! Returns the description of the field.
/*!
 *
 */
QString axlFieldParametricCurveTangentVector::description(void) const
{
    QString qstr;

    qstr.append("axlFieldParametricCurveTangentVector : \n");
    qstr.append("Type : Double ");
    qstr.append(";Kind : Vector ");
    qstr.append(";Support : Point");


    return qstr;

}


//! Sets the BSpline on which the BSpline field is applied
/*!
 *
 */
void axlFieldParametricCurveTangentVector::setCurve(axlAbstractData *data){
    if(dynamic_cast<axlAbstractCurveParametric*>(data))
        d->input = dynamic_cast<axlAbstractCurveParametric*>(data);
}


//! Returns the first parameter value of the field.
/*!
 *
 */
double axlFieldParametricCurveTangentVector::start_u(void){

    return d->input->startParam();

}



//! Returns the last parameter value of the field.
/*!
 *
 */
double axlFieldParametricCurveTangentVector::end_u(void){

    return d->input->endParam();
}



//! Returns the number of parameters.
/*!
 *
 */
double axlFieldParametricCurveTangentVector::numbersample_u(void){

    return d->input->numSamples();
}



//! Returns the number of values evaluated for this BSpline field on each samples of the input BSpline.
/*!
 *
 */
int axlFieldParametricCurveTangentVector::size(void){
    return d->input->numSamples();
}



//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlFieldParametricCurveTangentVector::update(void)
{
    emit updated();
}

// /////////////////////////////////////////////////////////////////
// axlFieldParametricCurveTangentVector documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlFieldParametricCurveTangentVector
 *
 *  \brief Class axlFieldParametricCurveTangentVector defines an API for field which owns a BSpline Surface as a function and a parametric surface on which the field is applied.
 *
 */

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlFieldParametricCurveTangentVector(void)
{
    return new axlFieldParametricCurveTangentVector;
}



