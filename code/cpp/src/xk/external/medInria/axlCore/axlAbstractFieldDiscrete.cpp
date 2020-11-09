/* axlAbstractFieldDiscrete.cpp ---
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

#include "axlAbstractFieldDiscrete.h"

#include <dtkCoreSupport/dtkGlobal.h>


// /////////////////////////////////////////////////////////////////
// axlAbstractFieldDiscrete implementation
// /////////////////////////////////////////////////////////////////

//!

/*!
 *
 */
axlAbstractFieldDiscrete::axlAbstractFieldDiscrete()
{

}

/*!
 *
 */
axlAbstractFieldDiscrete::axlAbstractFieldDiscrete(QString name, Type type, Kind kind, Support support, int size)
{

}

//! Constructs a discrete field from an \a array of underlying vtkDataArray type.
/*!
 *  The parent of an object may be viewed as the object's owner. The
 *  destructor of a parent object destroys all child objects. Setting
 *  parent to 0 constructs a discrete field with no parent.
 */
axlAbstractFieldDiscrete::axlAbstractFieldDiscrete(void *array)
{

}

//! Destroys the discrete field.
/*!
 *
 */
axlAbstractFieldDiscrete::~axlAbstractFieldDiscrete(void)
{
}

////! Sets the type of the field which can be either int, float or double.
///*!
// *
// */
//void axlAbstractFieldDiscrete::setType(axlAbstractFieldDiscrete::Type type)
//{
//    Q_UNUSED(type);
//}

////! Sets the kind of the field which can be either scalar, vector or tensor.
///*!
// *
// */
//void axlAbstractFieldDiscrete::setKind(axlAbstractFieldDiscrete::Kind kind)
//{
//     Q_UNUSED(kind);
//}

////!
///*!
// *
// */
//void axlAbstractFieldDiscrete::setSupport(axlAbstractFieldDiscrete::Support support)
//{
//    Q_UNUSED(support);
//}

//!
/*!
 *  Set a scalar element \a v1 at \a index location in the scalar data array.
 */
void axlAbstractFieldDiscrete::setScalar(int index, double v1)
{
    Q_UNUSED(index);
    Q_UNUSED(v1);
}

//!
/*!
 *  Set a vector element (\a v1, \a v2, \a v3) at \a index location in the vector data array.
 */
void axlAbstractFieldDiscrete::setVector(int index, double v1, double v2, double v3)
{
    Q_UNUSED(index);
    Q_UNUSED(v1);
    Q_UNUSED(v2);
    Q_UNUSED(v3);
}

//!
/*!
 *  Set a tensor element (\a v1, \a v2, \a v3, \a v4, \a v5, \a v6, \a v7, \a v8, \a v9)
 *  at \a index location in the tensor data array.
 */
void axlAbstractFieldDiscrete::setTensor(int index, double v1, double v2, double v3, double v4, double v5, double v6, double v7, double v8, double v9)
{
    Q_UNUSED(index);
    Q_UNUSED(v1);
    Q_UNUSED(v2);
    Q_UNUSED(v3);
    Q_UNUSED(v4);
    Q_UNUSED(v5);
    Q_UNUSED(v6);
    Q_UNUSED(v7);
    Q_UNUSED(v8);
    Q_UNUSED(v9);
}

//axlAbstractFieldDiscrete::Type axlAbstractFieldDiscrete::type(void)
//{
//    DTK_DEFAULT_IMPLEMENTATION;

//    return axlAbstractFieldDiscrete::Double;
//}

//axlAbstractFieldDiscrete::Kind axlAbstractFieldDiscrete::kind(void)
//{
//     DTK_DEFAULT_IMPLEMENTATION;

//     return axlAbstractFieldDiscrete::Scalar;
//}

//axlAbstractFieldDiscrete::Support axlAbstractFieldDiscrete::support(void)
//{
//     DTK_DEFAULT_IMPLEMENTATION;

//     return axlAbstractFieldDiscrete::Point;
//}

int axlAbstractFieldDiscrete::size(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return -1;
}

void axlAbstractFieldDiscrete::setSize(int size)
{
    Q_UNUSED(size);

}

//! Returns the value at \a index location of the scalar array.
/*!
 *
 */
double axlAbstractFieldDiscrete::scalar(int index)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

//! Returns the value at \a index location of the vector array.
/*!
 *
 */
double *axlAbstractFieldDiscrete::vector(int index)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return NULL;
}

//! Returns the value at \a index location of the tensor array.
/*!
 *
 */
double *axlAbstractFieldDiscrete::tensor(int index)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return NULL;
}

////! Returns the name the field.
///*!
// *
// */
//QString axlAbstractFieldDiscrete::name(void)
//{
//    DTK_DEFAULT_IMPLEMENTATION;

//    return "";
//}

//void axlAbstractFieldDiscrete::setName(QString name)
//{
//    Q_UNUSED(name);
//}


//! Mark the internal data structure as changed to notify underlying
//! pipeline execution.
/*!
 *
 */
void axlAbstractFieldDiscrete::update(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}


////! Returns a void pointer to the underlying vtkDataArray object.
///*!
// *
// */
//void *axlAbstractFieldDiscrete::array(void)
//{
//    DTK_DEFAULT_IMPLEMENTATION;

//    return NULL;
//}


//QString axlAbstractFieldDiscrete::objectType(void)
//{
//    return "Field";
//}

// /////////////////////////////////////////////////////////////////
// axlAbstractFieldDiscrete documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlAbstractFieldDiscrete
 *
 *  \brief Class axlAbstractFieldDiscrete defines an API for arrays of numeric data.
 *
 *  This class, based on a wrapping of vtkDataArray class, enables
 *  to deal with different type (int, float or double) and different
 *  kind (scalar, vector, tensor) of data.
 */

