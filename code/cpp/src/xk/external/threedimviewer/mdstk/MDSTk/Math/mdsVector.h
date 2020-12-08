//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/05                          \n
 *
 * $Id: mdsVector.h 2097 2012-02-16 20:19:05Z spanel $
 *
 * Description:
 * - Common vector operations.
 */

#ifndef MDS_Vector_H
#define MDS_Vector_H

#include "mdsMatrix.h"
#include "mdsStaticVector.h"


namespace mds
{
namespace math
{

// Declare vector traits first...
MDS_VECTOR_TRAITS(CVector)

//==============================================================================
/*!
 * Class template providing basic dense vector operations.
 * - T is vector element type (only int, usigned, float, double, std::complex<>,
 *   and mds::math::CComplex<> types are supported).
 */
template <typename T>
class CVector : public mds::base::CObject, public CVectorBase<CVector<T> >
{
public:
    //! Base class.
    typedef CVectorBase<CVector<T> > tBase;

    //! Templates that require members of the CVector class can use
    //! this enum to check the existence.
    enum { CLASS_VECTOR };

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CVector);

    //! Vector element type.
    typedef T tElement;

    //! Underlying data (see the Eigen math library).
    typedef Eigen::Matrix<tElement, Eigen::Dynamic, 1, Eigen::ColMajor | Eigen::AutoAlign> tStorage;

    //! Declare iterator types tIterator and tConstIterator.
    MDS_ITERATOR(CVector, tElement, CVectorIterator)

public:
    //! Default constructor.
    inline CVector();

    //! Constructor.
    //! - Creates a new vector of a given size.
    inline explicit CVector(tSize Size);

    //! Constructor.
    //! - Creates subvector of a given vector.
    //! - Makes a new copy of the data.
    inline CVector(const CVector& Vector, tSize First, tSize Size);

    //! Copy constructor.
    //! - Makes a new copy of the data.
    inline CVector(const CVector& Vector);

    //! Conversion constructor.
    //! - Makes a new copy of the data.
    template <typename Derived>
    inline CVector(const Eigen::MatrixBase<Derived>& Vector);

    //! Destructor.
    ~CVector();

    //! Re-creates the vector of a given length.
    inline CVector& create(tSize Size);

    //! Creates a subvector of a given vector.
    //! - Makes a new copy of the data.
    inline CVector& create(const CVector& Vector, tSize First, tSize Size);

    //! Re-creates the vector.
    //! - Makes a new copy of the data.
    template <typename Derived>
    inline CVector& create(const CVectorBase<Derived>& Vector);

    //! Re-creates the vector.
    //! - Makes a new copy of the data.
    template <typename Derived>
    inline CVector& create(const Eigen::MatrixBase<Derived>& Vector);

    //! Assignment operator.
    inline CVector& operator =(const CVector& Vector);

    //! Assignment operator.
    template <typename Derived>
    inline CVector& operator =(const Eigen::MatrixBase<Derived>& Vector);


    //! Returns reference to the underlying data (see the Eigen math library).
    tStorage& asEigen() { return m_Vector; }
    const tStorage& asEigen() const { return m_Vector; }

    //! Returns the vector size.
    tSize getSize() const { return m_Vector.size(); }

    //! Returns the vector size.
    tSize size() const { return m_Vector.size(); }

    //! Returns stride between two neigbouring vector elements.
    tSize getStride() const { return 1; }

    //! Returns reference to the element [i].
    T& at(tSize i)
    {
        return m_Vector.coeffRef(i);
    }
    const T& at(tSize i) const
    {
        return m_Vector.coeff(i);
    }

    //! Returns reference to the subscripted element [i].
    T& operator ()(tSize i)
    {
        return m_Vector.coeffRef(i);
    }
    const T& operator ()(tSize i) const
    {
        return m_Vector.coeff(i);
    }

    //! Sets the vector element at the position [i].
    CVector& set(tSize i, const T& Value)
    {
        m_Vector.coeffRef(i) = Value;
        return *this;
    }

    //! Returns pointer to the vector data.
    T *getPtr() { return m_Vector.data(); }
    const T *getPtr() const { return m_Vector.data(); }

    //! Returns pointer to a given element.
    T *getPtr(tSize i) { return (getPtr() + i); }
    const T *getPtr(tSize i) const { return (getPtr() + i); }


    //! Calls a function object for every vector element.
    template <class Function>
    inline Function forEach(Function Func);

    //! Calls a function object for every vector element.
    template <class Function>
    inline Function forEach(Function Func) const;


    //! Element wise addition.
    inline CVector& operator +=(const CVector& Vector);

    //! Element wise subtraction.
    inline CVector& operator -=(const CVector& Vector);

    //! Element wise product.
    inline CVector& operator *=(const CVector& Vector);

    //! Element wise addition.
    inline CVector& operator /=(const CVector& Vector);


    //! Adds scalar to all elements.
    template <typename U>
    inline CVector& operator +=(const CScalar<U>& c);

    //! Subtracts scalar from all elements.
    template <typename U>
    inline CVector& operator -=(const CScalar<U>& c);

    //! Multiplies all elements by scalar.
    template <typename U>
    inline CVector& operator *=(const CScalar<U>& c);

    //! Divides all elements by scalar.
    template <typename U>
    inline CVector& operator /=(const CScalar<U>& c);


    //! The vector initialization method.
    //! - Returns reference to this.
    inline CVector& zeros();

    //! The vector initialization method.
    //! - Returns reference to this.
    inline CVector& ones();

    //! Absolute value of all elements.
    //! - Returns reference to this.
    inline CVector& abs();

    //! Sets vector elements to a given value.
    //! - Returns reference to this.
    inline CVector& fill(const T& Value);

    //! Limit range of elements.
    //! - Returns reference to this.
    inline CVector& limit(const T& Lower, const T& Upper);

    //! Initializes this subsampling a given vector.
    //! - Returns reference to this.
    inline CVector& subSample(const CVector& Vector, tSize k = 2);

    //! Concatenates two vectors.
    //! - Returns reference to this.
    inline CVector& concat(const CVector& Vector1,
                           const CVector& Vector2
                           );

    //! Provides operation this += Vector * Scalar.
    //! - Throws CMultFailed() exception on failure.
    //! - Returns reference to this.
    inline CVector& multAdd(const CVector& Vector, const T& Scalar);

    //! Matrix vs. column vector multiplication.
    //! - Throws CMultFailed() exception on failure.
    //! - Returns reference to this.
    inline CVector& mult(const CMatrix<T>& Matrix,
                         const CVector& Vector
                         );

    //! Row vector vs. matrix multiplication.
    //! - Throws CMultFailed() exception on failure.
    //! - Returns reference to this.
    inline CVector& mult(const CVector& Vector,
                         const CMatrix<T>& Matrix
                         );

protected:
    //! Vector data.
    tStorage m_Vector;
};


//=============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsVector.hxx"


//=============================================================================
/*
 * Basic type definitions.
 */

//! Dynamic vector of int numbers.
typedef CVector<int>            CIVector;

//! Dynamic vector of float numbers.
typedef CVector<float>          CFVector;

//! Dynamic vector of doubles.
typedef CVector<double>         CDVector;

//! Pointer to a dynamic vector of int numbers
typedef CIVector::tSmartPtr     CIVectorPtr;

//! Pointer to a dynamic vector of float numbers
typedef CFVector::tSmartPtr     CFVectorPtr;

//! Pointer to a dynamic vector of doubles
typedef CDVector::tSmartPtr     CDVectorPtr;


} // namespace math
} // namespace mds

#endif // MDS_Vector_H

