//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/06/05                          \n
 *
 * $Id: mdsStaticVector.hxx 2093 2012-02-16 00:32:09Z spanel $
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


// Copy constructor
template <typename T, tSize M>
inline CStaticVector<T,M>::CStaticVector(const CStaticVector<T,M>& Vector)
    : tBase()
    , m_Vector(Vector.asEigen())
{
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
    mds::base::memVectMult(getPtr(), Vector.getPtr(), SIZE);

    return *this;
}


template <typename T, tSize M>
inline CStaticVector<T,M>& CStaticVector<T,M>::operator /=(const CStaticVector<T,M>& Vector)
{
    mds::base::memVectDiv(getPtr(), Vector.getPtr(), SIZE);

    return *this;
}


template <typename T, tSize M>
template <typename U>
inline CStaticVector<T,M>& CStaticVector<T,M>::operator +=(const CScalar<U>& c)
{
    forEach(mds::base::CAdd<tElement>(tElement(c.value())));

    return *this;
}


template <typename T, tSize M>
template <typename U>
inline CStaticVector<T,M>& CStaticVector<T,M>::operator -=(const CScalar<U>& c)
{
    forEach(mds::base::CSub<tElement>(tElement(c.value())));

    return *this;
}


template <typename T, tSize M>
template <typename U>
inline CStaticVector<T,M>& CStaticVector<T,M>::operator *=(const CScalar<U>& c)
{
    forEach(mds::base::CMult<tElement,U>(c.value()));

    return *this;
}


template <typename T, tSize M>
template <typename U>
inline CStaticVector<T,M>& CStaticVector<T,M>::operator /=(const CScalar<U>& c)
{
    forEach(mds::base::CDiv<tElement,U>(c.value()));

    return *this;
}


template <typename T, tSize M>
template <class Function>
inline Function CStaticVector<T,M>::forEach(Function Func)
{
    return mds::base::metaForEach<SIZE,T,Function>(getPtr(), Func);
}


template <typename T, tSize M>
template <class Function>
inline Function CStaticVector<T,M>::forEach(Function Func) const
{
    return mds::base::metaForEach<SIZE,const T,Function>(getPtr(), Func);
}


template <typename T, tSize M>
inline CStaticVector<T,M>& CStaticVector<T,M>::zeros()
{
    forEach(mds::base::CFill<tElement>(tElement()));

    return *this;
}


template <typename T, tSize M>
inline CStaticVector<T,M>& CStaticVector<T,M>::ones()
{
    forEach(mds::base::CFill<tElement>(tElement(1)));

    return *this;
}


template <typename T, tSize M>
inline CStaticVector<T,M>& CStaticVector<T,M>::fill(const T& Value)
{
    forEach(mds::base::CFill<tElement>(Value));

    return *this;
}


template <typename T, tSize M>
inline CStaticVector<T,M>& CStaticVector<T,M>::abs()
{
    forEach(mds::base::CAbs<tElement>());

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
