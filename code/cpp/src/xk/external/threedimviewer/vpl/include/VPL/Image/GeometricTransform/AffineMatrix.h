//==============================================================================
/* This file comes from MDSTk software and was modified for
 * 
 * VPL - Voxel Processing Library
 * Changes are Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 * 
 * The original MDSTk legal notice can be found below.
 * 
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2009 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/12/16                       
 *
 * Description:
 * - 2D affine transformation matrix.
 */

#ifndef VPL_AffineMatrix_H
#define VPL_AffineMatrix_H

#include <VPL/Math/Base.h>
#include <VPL/Math/StaticMatrix.h>
#include <VPL/Math/MatrixFunctions/Inverse.h>

#include "../ImageTypes.h"
#include "../Point3.h"

#include <cmath>


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Class encapsulates affine tranformation matrix.
 */
class CAffineMatrix : public vpl::math::CStaticMatrix<tCoordinate,3,3>
{
public:
    //! Size of the matrix.
    enum { DIMENSION = 3 };

    //! Base class.
    typedef vpl::math::CStaticMatrix<tCoordinate,3,3> tMatrix;

    //! Vector of coordinates.
    typedef CCoordinates3<tCoordinate> tCoords3;

public:
    //! Default constructor.
    //! - The matrix remains uninitialized.
    CAffineMatrix() {}

    //! Copy constructor.
    template <typename U>
    inline CAffineMatrix(const vpl::math::CStaticMatrix<U,3,3>& Matrix);

    //! Copy constructor specialization.
    inline CAffineMatrix(const CAffineMatrix& Matrix);

    //! Destructor.
    ~CAffineMatrix() {}

    //! Makes the matrix unit.
    inline CAffineMatrix& makeIdentity();

    //! Makes the scaling matrix.
    inline CAffineMatrix& makeScale(tCoordinate sx, tCoordinate sy);
    inline CAffineMatrix& makeScale(const tCoords3& v);

    //! Makes the rotation matrix.
    inline CAffineMatrix& makeRotate(tCoordinate Angle);

    //! Makes the translation matrix.
    inline CAffineMatrix& makeTranslate(tCoordinate dx, tCoordinate dy);
    inline CAffineMatrix& makeTranslate(const tCoords3& v);


    //! Sets the scaling.
    inline CAffineMatrix& setScale(tCoordinate sx, tCoordinate sy);
    inline CAffineMatrix& setScale(const tCoords3& v);

    //! Sets the rotation.
    inline CAffineMatrix& setRotate(tCoordinate Angle);

    //! Sets the translation.
    inline CAffineMatrix& setTranslate(tCoordinate dx, tCoordinate dy);
    inline CAffineMatrix& setTranslate(const tCoords3& v);


    //! Returns the current scaling ratio.
    inline tCoords3 getScaling() const;

    //! Returns the current translation.
    inline tCoords3 getTranslation() const;


    //! Adds a scaling matrix to the current one using multiplication.
    //! - x = x * m
    inline CAffineMatrix& addScale(tCoordinate sx, tCoordinate sy);
    inline CAffineMatrix& addScale(const tCoords3& v);

    //! Adds a rotation matrix to the current one.
    //! - x = x * m
    inline CAffineMatrix& addRotate(tCoordinate Angle);

    //! Adds a the translation matrix to the current one.
    //! - x = x * m
    inline CAffineMatrix& addTranslate(tCoordinate dx, tCoordinate dy);
    inline CAffineMatrix& addTranslate(const tCoords3& v);


    //! Inverts the transformation matrix inplace.
    //! - Throws an exception on failure!
    inline void invert();

    //! Multiplies the matrix and a given vector.
    //! - Returns v * x
    inline tCoords3 preMult(const tCoords3& v) const;

    //! Inplace multiplication of the matrix and a given vector.
    //! - v = v * x
    inline void preMult2(tCoords3& v) const;

    //! Multiplication of the matrix and a given vector.
    //! - r = v * x
    inline void preMult(const tCoords3& v, tCoords3& r) const;

    //! Inplace matrix multiplication.
    //! - x = x * m
    inline void postMult(const CAffineMatrix& m);
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "AffineMatrix.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_AffineMatrix_H

