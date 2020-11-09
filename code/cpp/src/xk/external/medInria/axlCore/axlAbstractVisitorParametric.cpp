/* axlAbstractVisitorParametricParametric.cpp ---
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

#include "axlAbstractVisitorParametric.h"
#include <dtkCoreSupport/dtkGlobal.h>
#include<axlCore/axlPoint.h>
//#include <axlGui/axlInspectorObjectFactory.h>

class axlAbstractVisitorParametricPrivate
{
public:
};

axlAbstractVisitorParametric::axlAbstractVisitorParametric(QObject *parent) : axlAbstractVisitor(parent), d(new axlAbstractVisitorParametricPrivate)
{
    this->setParent(parent);
}

axlAbstractVisitorParametric::~axlAbstractVisitorParametric(void)
{
    delete d;

    d = NULL;
}


//! Return a dialog.
/*!
 *
 */
//axlInspectorObjectInterface *axlAbstractVisitorParametric::form(void){
//    DTK_DEFAULT_IMPLEMENTATION;
//    return NULL;
//}

//! Return an axlPoint which contains the evaluation value for parameter u.
/*!
 *
 */
axlPoint axlAbstractVisitorParametric::eval(double u){
    DTK_DEFAULT_IMPLEMENTATION;
    Q_UNUSED(u);
    return axlPoint();

}

//! Return an axlPoint which contains the evaluation value for parameters (u,v).
/*!
 *
 */
axlPoint axlAbstractVisitorParametric::eval(double u, double v){
    DTK_DEFAULT_IMPLEMENTATION;
    Q_UNUSED(u);
    Q_UNUSED(v);
    return axlPoint();
}

//! Return an axlPoint which contains the evaluation value for parameters (u,v, w).
/*!
 *
 */
axlPoint axlAbstractVisitorParametric::eval(double u, double v, double w){
    DTK_DEFAULT_IMPLEMENTATION;
    Q_UNUSED(u);
    Q_UNUSED(v);
    Q_UNUSED(w);
    return axlPoint();
}

// /////////////////////////////////////////////////////////////////
// axlAbstractVisitorParametric documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlAbstractVisitorParametric
 *
 *  \brief Class axlAbstractVisitorParametric defines an API for Visitor (design pattern) for axel parametric object.
 *
 *  Every axel Visitor for parametric object must inherite from this abstract class.
 */

