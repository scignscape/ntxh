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


//==============================================================================
/*
 * Implementation of the class CAffineMatrix.
 */

template <typename U>
inline CAffineMatrix::CAffineMatrix(const vpl::math::CStaticMatrix<U,3,3>& Matrix) : tMatrix(Matrix)
{
}


inline CAffineMatrix::CAffineMatrix(const CAffineMatrix& Matrix) : tMatrix(Matrix)
{
}


inline CAffineMatrix& CAffineMatrix::makeIdentity()
{
    at(0,0) = at(1,1) = at(2,2) = 1.0;
    at(0,1) = at(0,2) = at(1,0) = 0.0;
    at(1,2) = at(2,0) = at(2,1) = 0.0;

    return *this;
}


inline CAffineMatrix& CAffineMatrix::makeScale(tCoordinate sx, tCoordinate sy)
{
    at(0,0) = sx;
    at(1,1) = sy;
    at(2,2) = 1.0;

    at(0,1) = at(0,2) = at(1,0) = 0.0;
    at(1,2) = at(2,0) = at(2,1) = 0.0;

    return *this;
}


inline CAffineMatrix& CAffineMatrix::makeScale(const tCoords3& v)
{
    at(0,0) = v.x();
    at(1,1) = v.y();
    at(2,2) = 1.0;

    at(0,1) = at(0,2) = at(1,0) = 0.0;
    at(1,2) = at(2,0) = at(2,1) = 0.0;

    return *this;
}


inline CAffineMatrix& CAffineMatrix::makeRotate(tCoordinate Angle)
{
    tCoordinate cosa = std::cos(Angle);
    tCoordinate sina = std::sin(Angle);

    at(0,0) = cosa;
    at(0,1) = sina;
    at(1,0) = -sina;
    at(1,1) = cosa;

    at(2,2) = 1.0;
    at(0,2) = at(1,2) = at(2,0) = at(2,1) = 0.0;

    return *this;
}


inline CAffineMatrix& CAffineMatrix::makeTranslate(tCoordinate dx, tCoordinate dy)
{
    at(2,0) = dx;
    at(2,1) = dy;

    at(0,0) = at(1,1) = at(2,2) = 1.0;
    at(0,1) = at(0,2) = at(1,0) = at(1,2) = 0.0;

    return *this;
}


inline CAffineMatrix& CAffineMatrix::makeTranslate(const tCoords3& v)
{
    at(2,0) = v.x();
    at(2,1) = v.y();

    at(0,0) = at(1,1) = at(2,2) = 1.0;
    at(0,1) = at(0,2) = at(1,0) = at(1,2) = 0.0;

    return *this;
}


inline CAffineMatrix& CAffineMatrix::setScale(tCoordinate sx, tCoordinate sy)
{
    at(0,0) = sx;
    at(1,1) = sy;
    at(2,2) = 1.0;

    return *this;
}


inline CAffineMatrix& CAffineMatrix::setScale(const tCoords3& v)
{
    at(0,0) = v.x();
    at(1,1) = v.y();
    at(2,2) = 1.0;

    return *this;
}


inline CAffineMatrix& CAffineMatrix::setRotate(tCoordinate Angle)
{
    tCoordinate cosa = std::cos(Angle);
    tCoordinate sina = std::sin(Angle);

    at(0,0) = cosa;
    at(0,1) = sina;
    at(1,0) = -sina;
    at(1,1) = cosa;

    return *this;
}


inline CAffineMatrix& CAffineMatrix::setTranslate(tCoordinate dx, tCoordinate dy)
{
    at(2,0) = dx;
    at(2,1) = dy;
    at(2,2) = 1.0;

    return *this;
}


inline CAffineMatrix& CAffineMatrix::setTranslate(const tCoords3& v)
{
    at(2,0) = v.x();
    at(2,1) = v.y();
    at(2,2) = 1.0;

    return *this;
}


inline CAffineMatrix::tCoords3 CAffineMatrix::getScaling() const
{
    return tCoords3(at(0,0), at(1,1), 1.0);
}


inline CAffineMatrix::tCoords3 CAffineMatrix::getTranslation() const
{
    return tCoords3(at(2,0), at(2,1), 1.0);
}


inline CAffineMatrix& CAffineMatrix::addScale(tCoordinate sx, tCoordinate sy)
{
    postMult(CAffineMatrix().makeScale(sx, sy));

    return *this;
}


inline CAffineMatrix& CAffineMatrix::addScale(const tCoords3& v)
{
    postMult(CAffineMatrix().makeScale(v));

    return *this;
}


inline CAffineMatrix& CAffineMatrix::addRotate(tCoordinate Angle)
{
    postMult(CAffineMatrix().makeRotate(Angle));

    return *this;
}


inline CAffineMatrix& CAffineMatrix::addTranslate(tCoordinate dx, tCoordinate dy)
{
    postMult(CAffineMatrix().makeTranslate(dx, dy));

    return *this;
}


inline CAffineMatrix& CAffineMatrix::addTranslate(const tCoords3& v)
{
    postMult(CAffineMatrix().makeTranslate(v));

    return *this;
}


inline void CAffineMatrix::invert()
{
    vpl::math::inverse(*this);
}


inline CAffineMatrix::tCoords3 CAffineMatrix::preMult(const tCoords3& v) const
{
    tCoordinate x = v.x() * at(0,0) + v.y() * at(1,0) + v.z() * at(2,0);
    tCoordinate y = v.x() * at(0,1) + v.y() * at(1,1) + v.z() * at(2,1);
    tCoordinate z = v.x() * at(0,2) + v.y() * at(1,2) + v.z() * at(2,2);

    return tCoords3(x, y, z);
}


inline void CAffineMatrix::preMult2(tCoords3& v) const
{
    tCoordinate x = v.x() * at(0,0) + v.y() * at(1,0) + v.z() * at(2,0);
    tCoordinate y = v.x() * at(0,1) + v.y() * at(1,1) + v.z() * at(2,1);
    tCoordinate z = v.x() * at(0,2) + v.y() * at(1,2) + v.z() * at(2,2);

    v.x() = x;
    v.y() = y;
    v.z() = z;
}


inline void CAffineMatrix::preMult(const tCoords3& v, tCoords3& r) const
{
    r.x() = v.x() * at(0,0) + v.y() * at(1,0) + v.z() * at(2,0);
    r.y() = v.x() * at(0,1) + v.y() * at(1,1) + v.z() * at(2,1);
    r.z() = v.x() * at(0,2) + v.y() * at(1,2) + v.z() * at(2,2);
}


inline void CAffineMatrix::postMult(const CAffineMatrix& m)
{
    tMatrix Temp = *this;

    for( tSize i = 0; i < 3; ++i )
    {
        for( tSize j = 0; j < 3; ++j )
        {
            at(i,j) = Temp(i,0) * m(0,j)
                + Temp(i,1) * m(1,j)
                + Temp(i,2) * m(2,j);
        }
    }
}

