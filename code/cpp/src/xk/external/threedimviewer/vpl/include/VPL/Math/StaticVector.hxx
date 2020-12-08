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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/06/05                          \n
 *
 * Description:
 * - Static vector operations.
 */


//==============================================================================
/*
 * Method templates.
 */

// Constructor
template <typename T, tSize M>
inline CStaticVector<T,M>::CStaticVector()
    : m_Vector()
{
    zeros();
}


template <typename T, tSize M>
template <typename U>
inline CStaticVector<T,M>::CStaticVector(const CStaticVector<U,M>& Vector)
    : m_Vector()
{
    m_Vector = Vector.asEigen().template cast<T>();
}


template <typename T, tSize M>
template <typename Derived>
inline CStaticVector<T,M>::CStaticVector(const Eigen::MatrixBase<Derived>& Vector)
    : m_Vector()
{
    m_Vector = Vector.template cast<T>();
}


template <typename T, tSize M>
vpl::math::CStaticVector<T, M>::CStaticVector(tElement e)
{
    fill(e);
}


template <typename T, tSize M>
vpl::math::CStaticVector<T, M>::CStaticVector(tElement x, tElement y)
{
    VPL_ASSERT(SIZE == 2);
    m_Vector(0) = x;
    m_Vector(1) = y;
}

template <typename T, tSize M>
inline CStaticVector<T, M>::CStaticVector(tElement x, tElement y, tElement z)
{
    VPL_ASSERT(SIZE == 3);
    m_Vector(0) = x;
    m_Vector(1) = y;
    m_Vector(2) = z;
}


template <typename T, tSize M>
vpl::math::CStaticVector<T, M>::CStaticVector(tElement x, tElement y, tElement z, tElement w)
{
    VPL_ASSERT(SIZE == 4);
    m_Vector(0) = x;
    m_Vector(1) = y;
    m_Vector(2) = z;
    m_Vector(3) = w;
}


template <typename T, tSize M>
vpl::math::CStaticVector<T, M>::CStaticVector(const CStaticVector<T, SIZE - 1> &v, tElement e)
{
    VPL_ASSERT(SIZE > 2);
    for (int i = 0; i < SIZE - 1; ++i)
    {
        m_Vector(i) = v(i);
    }
    m_Vector(SIZE - 1) = e;
}


// Copy constructor
template <typename T, tSize M>
inline CStaticVector<T,M>::CStaticVector(const CStaticVector<T,M>& Vector)
    : tBase()
    , m_Vector(Vector.asEigen())
{
}


//! Initialize by elements
template <typename T, tSize M>
inline void CStaticVector<T, M>::set(tElement x, tElement y)
{
    VPL_ASSERT(SIZE == 2);
    m_Vector(0) = x; m_Vector(1) = y;
}


template <typename T, tSize M>
inline void CStaticVector<T, M>::set(tElement x, tElement y, tElement z)
{
    VPL_ASSERT(SIZE == 3);
    m_Vector(0) = x; m_Vector(1) = y; m_Vector(2) = z;
}


template <typename T, tSize M>
inline void CStaticVector<T, M>::set(tElement x, tElement y, tElement z, tElement w)
{
    VPL_ASSERT(SIZE == 4);
    m_Vector(0) = x; m_Vector(1) = y; m_Vector(2) = z;  m_Vector(3) = w;
}

//! Get x value reference
template <typename T, tSize M>
inline T & CStaticVector<T, M>::x()
{
    VPL_ASSERT(SIZE >= 1);
    return m_Vector(0);
}


template <typename T, tSize M>
inline T & CStaticVector<T, M>::y()
{
    VPL_ASSERT(SIZE >= 2);
    return m_Vector(1);
}


template <typename T, tSize M>
inline T & CStaticVector<T, M>::z()
{
    VPL_ASSERT(SIZE >= 3);
    return m_Vector(2);
}


template <typename T, tSize M>
inline T & CStaticVector<T, M>::w()
{
    VPL_ASSERT(SIZE >= 4);
    return m_Vector(3);
}

//! Get x value copy
template <typename T, tSize M>
inline T CStaticVector<T, M>::x() const
{
    VPL_ASSERT(SIZE >= 1);
    return m_Vector(0);
}


template <typename T, tSize M>
inline T CStaticVector<T, M>::y() const
{
    VPL_ASSERT(SIZE >= 2);
    return m_Vector(1);
}


template <typename T, tSize M>
inline T CStaticVector<T, M>::z() const
{
    VPL_ASSERT(SIZE >= 3);
    return m_Vector(2);
}


template <typename T, tSize M>
inline T CStaticVector<T, M>::w() const
{
    VPL_ASSERT(SIZE >= 4);
    return m_Vector(3);
}

// Assignment operator
template <typename T, tSize M>
template <typename U>
inline CStaticVector<T,M>& CStaticVector<T,M>::operator =(const CStaticVector<U,M>& Vector)
{
    m_Vector = Vector.asEigen().template cast<T>();

    return *this;
}


template <typename T, tSize M>
template <typename Derived>
inline CStaticVector<T,M>& CStaticVector<T,M>::operator =(const Eigen::MatrixBase<Derived>& Vector)
{
    m_Vector = Vector.template cast<T>();

    return *this;
}


template <typename T, tSize M>
inline CStaticVector<T,M>& CStaticVector<T,M>::operator =(const CStaticVector<T,M>& Vector)
{
    if( &Vector != this )
    {
        m_Vector = Vector.asEigen();
    }

    return *this;
}


template <typename T, tSize M>
inline CStaticVector<T,M>& CStaticVector<T,M>::operator +=(const CStaticVector<T,M>& Vector)
{
    m_Vector += Vector.asEigen();

    return *this;
}


template <typename T, tSize M>
inline CStaticVector<T,M>& CStaticVector<T,M>::operator -=(const CStaticVector<T,M>& Vector)
{
    m_Vector -= Vector.asEigen();

    return *this;
}


template <typename T, tSize M>
inline CStaticVector<T,M>& CStaticVector<T,M>::operator *=(const CStaticVector<T,M>& Vector)
{
    vpl::sys::memVectMult(getPtr(), Vector.getPtr(), SIZE);

    return *this;
}


template <typename T, tSize M>
inline CStaticVector<T,M>& CStaticVector<T,M>::operator /=(const CStaticVector<T,M>& Vector)
{
    vpl::sys::memVectDiv(getPtr(), Vector.getPtr(), SIZE);

    return *this;
}


template <typename T, tSize M>
template <typename U>
inline CStaticVector<T,M>& CStaticVector<T,M>::operator +=(const CScalar<U>& c)
{
    forEach(vpl::base::CAdd<tElement>(tElement(c.value())));

    return *this;
}


template <typename T, tSize M>
template <typename U>
inline CStaticVector<T,M>& CStaticVector<T,M>::operator -=(const CScalar<U>& c)
{
    forEach(vpl::base::CSub<tElement>(tElement(c.value())));

    return *this;
}


template <typename T, tSize M>
template <typename U>
inline CStaticVector<T,M>& CStaticVector<T,M>::operator *=(const CScalar<U>& c)
{
    forEach(vpl::base::CMult<tElement,U>(c.value()));

    return *this;
}


template <typename T, tSize M>
template <typename U>
inline CStaticVector<T,M>& CStaticVector<T,M>::operator /=(const CScalar<U>& c)
{
    forEach(vpl::base::CDiv<tElement,U>(c.value()));

    return *this;
}


template <typename T, tSize M>
bool vpl::math::CStaticVector<T, M>::operator<(const CStaticVector& v) const
{
    for (int i = 0; i < M; ++i)
    {
        if (m_Vector(i) < v(i))
        {
            return true;
        }
        else if (m_Vector(i) < v(i))
        {
            return false;
        }
    }
    return false;
}


template <typename T, tSize M>
template <class Function>
inline Function CStaticVector<T,M>::forEach(Function Func)
{
    return vpl::base::metaForEach<SIZE,T,Function>(getPtr(), Func);
}


template <typename T, tSize M>
template <class Function>
inline Function CStaticVector<T,M>::forEach(Function Func) const
{
    return vpl::base::metaForEach<SIZE,const T,Function>(getPtr(), Func);
}


template <typename T, tSize M>
inline CStaticVector<T,M>& CStaticVector<T,M>::zeros()
{
    forEach(vpl::base::CFill<tElement>(tElement()));

    return *this;
}


template <typename T, tSize M>
inline CStaticVector<T,M>& CStaticVector<T,M>::ones()
{
    forEach(vpl::base::CFill<tElement>(tElement(1)));

    return *this;
}


template <typename T, tSize M>
inline CStaticVector<T,M>& CStaticVector<T,M>::fill(const T& Value)
{
    forEach(vpl::base::CFill<tElement>(Value));

    return *this;
}


template <typename T, tSize M>
inline CStaticVector<T,M>& CStaticVector<T,M>::abs()
{
    forEach(vpl::base::CAbs<tElement>());

    return *this;
}


template <typename T, tSize M>
inline CStaticVector<T,M>& CStaticVector<T,M>::multAdd(const CStaticVector<T,M>& Vector,
                                                       const T& Scalar
                                                       )
{
    m_Vector += Scalar * Vector.asEigen();

    return *this;
}


// Matrix and vector multiplication
template <typename T, tSize M>
template <tSize K>
inline CStaticVector<T,M>& CStaticVector<T,M>::mult(const CStaticMatrix<T,M,K>& Matrix,
                                                    const CStaticVector<T,K>& Vector
                                                    )
{
    m_Vector = Matrix.asEigen() * Vector.asEigen();

    return *this;
}


// Vector and matrix multiplication
template <typename T, tSize M>
template <tSize K>
inline CStaticVector<T,M>& CStaticVector<T,M>::mult(const CStaticVector<T,K>& Vector,
                                                    const CStaticMatrix<T,K,M>& Matrix
                                                    )
{
    m_Vector = (Vector.asEigen().transpose() * Matrix.asEigen()).transpose();

    return *this;
}

