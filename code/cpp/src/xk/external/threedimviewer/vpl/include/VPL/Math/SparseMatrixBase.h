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
 * Copyright (c) 2010 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/02                          \n
 *
 * Description:
 * - Base class for all two-dimensional sparse matrixes.
 */

#ifndef VPL_SparseMatrixBase_H
#define VPL_SparseMatrixBase_H

#include <VPL/Base/TypeTraits.h>
#include <VPL/Base/Scalar.h>


namespace vpl
{
namespace math
{

//==============================================================================
/*!
 * Traits used to implement curiously recurring template pattern for sparse
 * matrices.
 */
template <typename M>
struct CSparseMatrixTraits
{
    //! Matrix coefficient type.
    typedef tNull tElement;   
};


//! Helper macro used to declare matrix traits before a matrix class template.
#define VPL_SPARSE_MATRIX_TRAITS(SparseMatrixClass) \
    template <typename T> class SparseMatrixClass; \
    template <typename T> \
    struct CSparseMatrixTraits<SparseMatrixClass<T> > \
    { \
        typedef T tElement; \
    };


//==============================================================================
/*!
 * Base class for all two-dimensional sparse matrixes.
 * - Base class takes a template parameter M. This parameter is the type
 *   of the class which derives from it (so called curiously recurring template
 *   pattern).
 */
template <class M>
class CSparseMatrixBase
{
public:
    //! Matrix type.
    typedef M tMatrix;

    //! Element type.
    typedef typename CSparseMatrixTraits<M>::tElement tElement;
    
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
    //! Returns the matrix dominant value.
    tElement getDominant() const { return getImpl().getDominant(); }

    //! Returns the matrix size (dimensions).
    tSize getNumOfRows() const { return getImpl().getNumOfRows(); }
    tSize getNumOfCols() const { return getImpl().getNumOfCols(); }

    //! Returns the matrix size (dimensions).
    tSize rows() const { return getImpl().rows(); }
    tSize cols() const { return getImpl().cols(); }


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


    //! Calls a function object for every non-dominant matrix element.
    template <class Function>
    inline Function forEachRef(Function Func)
    {
        return getImpl().pforEachRef(Func);
    }

    //! Calls a function object for every matrix element.
    template <class Function>
    inline Function forEach(Function Func) const
    {
        return getImpl().forEach(Func);
    }

    //! Calls a function object for every non-dominant matrix element.
    //! - Parallel version.
    template <class Function>
    inline Function pforEachRef(Function Func)
    {
        return getImpl().pforEachRef(Func);
    }

    //! Calls a function object for every matrix element.
    //! - Parallel version.
    template <class Function>
    inline Function pforEach(Function Func) const
    {
        return getImpl().pforEach(Func);
    }

protected:
    //! Default constructor.
    CSparseMatrixBase() {}

    //! Copy constructor.
    CSparseMatrixBase(const CSparseMatrixBase&) {}

    //! Assignment operator.
    CSparseMatrixBase& operator =(const CSparseMatrixBase&) {}
};


} // namespace math
} // namespace vpl

#endif // VPL_SparseMatrixBase_H

