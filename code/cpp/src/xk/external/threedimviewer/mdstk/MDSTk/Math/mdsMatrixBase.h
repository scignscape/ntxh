//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/12                          \n
 *
 * $Id: mdsMatrixBase.h 2094 2012-02-16 01:54:45Z spanel $
 *
 * Description:
 * - Base class for all two-dimensional matrixes.
 */

#ifndef MDS_MATRIXBASE_H
#define MDS_MATRIXBASE_H

#include <MDSTk/Base/mdsTypeTraits.h>
#include <MDSTk/Base/mdsScalar.h>


namespace mds
{
namespace math
{

//==============================================================================
/*!
 * Traits used to implement curiously recurring template pattern for matrices.
 */
template <typename M>
struct CMatrixTraits
{
    //! Matrix coefficient type.
    typedef tNull tElement;   
};


//! Helper macro used to declare matrix traits before a matrix class template.
#define MDS_MATRIX_TRAITS(MatrixClass) \
    template <typename T> class MatrixClass; \
    template <typename T> \
    struct CMatrixTraits<MatrixClass<T> > \
    { \
        typedef T tElement; \
    };


//! Helper macro used to declare matrix traits before a matrix class template.
#define MDS_STATIC_MATRIX_TRAITS(MatrixClass) \
    template <typename T, tSize U, tSize V> class MatrixClass; \
    template <typename T, tSize U, tSize V> \
    struct CMatrixTraits<MatrixClass<T,U,V> > \
    { \
        typedef T tElement; \
    };


//==============================================================================
/*!
 * Base class for all two-dimensional matrixes.
 * - Base class takes a template parameter M. This parameter is the type
 *   of the class which derives from it (so called curiously recurring template
 *   pattern).
 */
template <class M>
class CMatrixBase
{
public:
    //! Matrix type.
    typedef M tMatrix;

    //! Element type.
    typedef typename CMatrixTraits<M>::tElement tElement;

public:
    //! Returns reference to the matrix implementation.
    tMatrix& getImpl()
    {
        return *static_cast<tMatrix *>(this);
    }
    const tMatrix& getImpl() const
    {
        return *static_cast<const tMatrix *>(this);
    }

public:
    //! Returns the matrix size (dimensions).
    tSize getNumOfRows() const { return getImpl().getNumOfRows(); }
    tSize getNumOfCols() const { return getImpl().getNumOfCols(); }

    //! Returns the matrix size (dimensions).
    tSize rows() const { return getImpl().rows(); }
    tSize cols() const { return getImpl().cols(); }


    //! Returns row offset, i.e. the offset between two neighbouring
    //! elements in a matrix column.
    tSize getRowOffset() const { return getImpl().getRowOffset(); }

    //! Returns column offset, i.e. the offset between two neighbouring
    //! elements in a matrix row.
    tSize getColOffset() const { return getImpl().getColOffset(); }


    //! Method returns reference to the element at (row, col).
    tElement& operator ()(tSize row, tSize col)
    {
        return getImpl().at(row, col);
    }
    
    //! Method returns element (by value) at (row, col).
    const tElement operator ()(tSize row, tSize col) const
    {
        return getImpl().at(row, col);
    }

    //! Method returns reference to the element at (row, col).
    tElement& at(tSize row, tSize col)
    {
        return getImpl().at(row, col);
    }

    //! Method returns element (by value) at (row, col).
    const tElement at(tSize row, tSize col) const
    {
        return getImpl().at(row, col);
    }

    //! Method sets value of element at (row, col).
    tMatrix& set(tSize row, tSize col, const tElement& Value)
    {
        return getImpl().set(row, col, Value);
    }


    //! Calculates index of matrix coefficient.
    tSize getIdx(tSize row, tSize col) const
    {
        return getImpl().getIdx(row, col);
    }

    //! Returns the subscripted matrix coefficient.
    tElement& operator ()(tSize i)
    {
        return getImpl().at(i);
    }
    const tElement& operator ()(tSize i) const
    {
        return getImpl().at(i);
    }

    //! Returns the subscripted matrix coefficient.
    tElement& at(tSize i)
    {
        return getImpl().at(i);
    }
    const tElement& at(tSize i) const
    {
        return getImpl().at(i);
    }

    //! Sets the subscripted matrix coefficient.
    tMatrix& set(tSize i, const tElement& Value)
    {
        return getImpl().set(i, Value);
    }


    //! Calls a function object for every matrix coefficient.
    template <class Function>
    inline Function forEach(Function Func)
    {
        return getImpl().forEach(Func);
    }

    //! Calls a function object for every matrix coefficient.
    template <class Function>
    inline Function forEach(Function Func) const
    {
        return getImpl().forEach(Func);
    }

    //! Calls a function object for every matrix coefficient.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func)
    {
        return getImpl().pforEach(Func);
    }

    //! Calls a function object for every matrix coefficient.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func) const
    {
        return getImpl().pforEach(Func);
    }

protected:
    //! Default constructor.
    CMatrixBase() {}

    //! Copy constructor.
    CMatrixBase(const CMatrixBase&) {}

    //! Assignment operator.
    CMatrixBase& operator =(const CMatrixBase&) { return *this; }
};


} // namespace math
} // namespace mds

#endif // MDS_MATRIXBASE_H

