/* axlAbstractFieldSpatial.cpp ---
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

#include "axlAbstractFieldSpatial.h"
#include "axlAbstractProcess.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

class axlAbstractFieldSpatialPrivate
{
public:
};

// /////////////////////////////////////////////////////////////////
// axlAbstractFieldSpatial implementation
// /////////////////////////////////////////////////////////////////

//!
/*!
 *
 */
axlAbstractFieldSpatial::axlAbstractFieldSpatial() : axlAbstractField(),  d(new axlAbstractFieldSpatialPrivate)
{
}



//! Destroys a spatial field.
/*!
 *
 */
axlAbstractFieldSpatial::~axlAbstractFieldSpatial(void)
{
    delete d;

    d = NULL;
}



////! Sets the type of the field which can be either int, float or double.
///*!
// *
// */
//void axlAbstractFieldSpatial::setType(axlAbstractFieldSpatial::Type type)
//{

//    d->type = type;
//}

////! Sets the kind of the field which can be either scalar, vector or tensor.
///*!
// *
// */
//void axlAbstractFieldSpatial::setKind(axlAbstractFieldSpatial::Kind kind)
//{

//    d->kind = kind;
//}

////!
///*!
// *
// */
//void axlAbstractFieldSpatial::setSupport(axlAbstractFieldSpatial::Support support)
//{
//    d->support = support;
//}


//axlAbstractFieldSpatial::Type axlAbstractFieldSpatial::type(void)
//{
//    return d->type;
//}

//axlAbstractFieldSpatial::Kind axlAbstractFieldSpatial::kind(void)
//{
//    return d->kind;
//}

//axlAbstractFieldSpatial::Support axlAbstractFieldSpatial::support(void)
//{
//    return d->support;
//}



//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double axlAbstractFieldSpatial::scalar(double x, double y, double z)
{
    if(!(this->kind() == Scalar)) {
        qDebug() << "Getting scalar value on non scalar field.";
        return 0;
    }
    return 0;
}

//! Returns the value of the spatial field at the coordinates point entered
/*!
 *
 */
double *axlAbstractFieldSpatial::vector(double x, double y, double z)
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
double *axlAbstractFieldSpatial::tensor(double x, double y, double z)
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
//QString axlAbstractFieldSpatial::name(void)
//{
//    return this->objectName() ;
//}

////! Sets the name of the field.
///*!
// *
// */
//void axlAbstractFieldSpatial::setName(QString name)
//{
//    this->setObjectName(name);

//}

//! Returns the description of the field.
/*!
 *
 */
QString axlAbstractFieldSpatial::description(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return "";

}


//! Returns the description of the field.
/*!
 *
 */
QString axlAbstractFieldSpatial::identifier(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return "";

}


//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlAbstractFieldSpatial::update(void)
{
    emit updated();
}

// /////////////////////////////////////////////////////////////////
// axlField documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlAbstractFieldSpatial
 *
 *  \brief Class axlAbstractFieldSpatial defines an API for spatial field.
 *
 */

// /////////////////////////////////////////////////////////////////
// Type instanciation
// /////////////////////////////////////////////////////////////////

dtkAbstractData *createaxlAbstractFieldSpatial(void)
{
    return new axlAbstractFieldSpatial();
}
