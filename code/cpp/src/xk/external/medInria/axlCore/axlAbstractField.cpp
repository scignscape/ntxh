/* axlAbstractField.cpp ---
 *
 * Author: Thibaud Kloczko
 * Copyright (C) 2008 - Thibaud Kloczko, Inria.
 * Created: Wed Jul 28 11:22:28 2010 (+0200)
 * Version: $Id$
 * Last-Updated: Tue Oct 25 09:55:32 2011 (+0200)
 *           By: Thibaud Kloczko
 *     Update #: 355
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractField.h"

#include <dtkCoreSupport/dtkGlobal.h>

class axlAbstractFieldPrivate
{
public:
    axlAbstractField::Kind kind;
    axlAbstractField::Type type;
    axlAbstractField::Support support;

    double min;
    double max;
};
// /////////////////////////////////////////////////////////////////
// axlAbstractField implementation
// /////////////////////////////////////////////////////////////////

//!

/*!
 *
 */
axlAbstractField::axlAbstractField(): d(new axlAbstractFieldPrivate)
{
    //    d->kind = axlAbstractField::Scalar;
    //    d->type = axlAbstractField::Float;
    //    d->support = axlAbstractField::Point;
    d->max = 0;
    d->min = 0;

}

/*!
 *
 */
axlAbstractField::axlAbstractField(QString name, Type type, Kind kind, Support support)
{
    d->kind = kind;
    d->type = type;
    d->support = support;
    this->setObjectName(name);
    d->max = 0;
    d->min = 0;
}


//! Destroys the field.
/*!
 *
 */
axlAbstractField::~axlAbstractField(void)
{
}

//! Sets the type of the field which can be either int, float or double.
/*!
 *
 */
void axlAbstractField::setType(axlAbstractField::Type type)
{
    d->type = type;
}

//! Sets the kind of the field which can be either scalar, vector or tensor.
/*!
 *
 */
void axlAbstractField::setKind(axlAbstractField::Kind kind)
{
    d->kind = kind;
}

//!
/*!
 *
 */
void axlAbstractField::setSupport(axlAbstractField::Support support)
{
    d->support = support;
}

////!
///*!
// *  Set a scalar element \a v1 at \a index location in the scalar data array.
// */
//void axlAbstractField::setScalar(int index, double v1)
//{
//    Q_UNUSED(index);
//    Q_UNUSED(v1);
//}

////!
///*!
// *  Set a vector element (\a v1, \a v2, \a v3) at \a index location in the vector data array.
// */
//void axlAbstractField::setVector(int index, double v1, double v2, double v3)
//{
//    Q_UNUSED(index);
//    Q_UNUSED(v1);
//    Q_UNUSED(v2);
//    Q_UNUSED(v3);
//}

////!
///*!
// *  Set a tensor element (\a v1, \a v2, \a v3, \a v4, \a v5, \a v6, \a v7, \a v8, \a v9)
// *  at \a index location in the tensor data array.
// */
//void axlAbstractField::setTensor(int index, double v1, double v2, double v3, double v4, double v5, double v6, double v7, double v8, double v9)
//{
//    Q_UNUSED(index);
//    Q_UNUSED(v1);
//    Q_UNUSED(v2);
//    Q_UNUSED(v3);
//    Q_UNUSED(v4);
//    Q_UNUSED(v5);
//    Q_UNUSED(v6);
//    Q_UNUSED(v7);
//    Q_UNUSED(v8);
//    Q_UNUSED(v9);
//}

axlAbstractField::Type axlAbstractField::type(void)
{
    return d->type;
}

axlAbstractField::Kind axlAbstractField::kind(void)
{
    return d->kind;
}

axlAbstractField::Support axlAbstractField::support(void)
{
    return d->support;
}

//int axlAbstractField::size(void)
//{
//     DTK_DEFAULT_IMPLEMENTATION;

//	 return -1;
//}

//void axlAbstractField::setSize(int size)
//{
//    Q_UNUSED(size);

//}

//! Returns the minimum value of the field.
/*!
 *
 */
double axlAbstractField::minValue(void)
{
    return d->min;
}

//! Sets the minimum value of the field.
/*!
 *
 */
void axlAbstractField::setMin(double mini)
{
    d->min = mini;
}


//! Returns the maximum value of the field.
/*!
 *
 */
double axlAbstractField::maxValue(void)
{
    return d->max;
}

//! Sets the maximum value of the field..
/*!
 *
 */
void axlAbstractField::setMax(double maxi)
{
    d->max = maxi;
}

////! Returns the value at \a index location of the scalar array.
///*!
// *
// */
//double axlAbstractField::scalar(int index)
//{
//    DTK_DEFAULT_IMPLEMENTATION;

//    return 0;
//}

////! Returns the value at \a index location of the vector array.
///*!
// *
// */
//double *axlAbstractField::vector(int index)
//{
//    DTK_DEFAULT_IMPLEMENTATION;

//    return NULL;
//}

////! Returns the value at \a index location of the tensor array.
///*!
// *
// */
//double *axlAbstractField::tensor(int index)
//{
//    DTK_DEFAULT_IMPLEMENTATION;

//    return NULL;
//}

////! Returns the name the field.
///*!
// *
// */
//QString axlAbstractField::name(void)
//{

//    return this->objectName();
//}

//void axlAbstractField::setName(QString name)
//{
//    this->setObjectName(name);
//}


//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlAbstractField::update(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

//! Return the identifier of an axlAbstractField which is empty.
//!
/*!
 *
 */
QString axlAbstractField::identifier(void) const{
    return "";
}


////! Returns a void pointer to the underlying vtkDataArray object.
///*!
// *
// */
//void *axlAbstractField::array(void)
//{
//    DTK_DEFAULT_IMPLEMENTATION;

//    return NULL;
//}

// /////////////////////////////////////////////////////////////////
// axlAbstractField documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlAbstractField
 *
 *  \brief Class axlAbstractField defines an API for arrays of numeric data.
 *
 *  This class, based on a wrapping of vtkDataArray class, enables
 *  to deal with different type (int, float or double) and different
 *  kind (scalar, vector, tensor) of data.
 */
