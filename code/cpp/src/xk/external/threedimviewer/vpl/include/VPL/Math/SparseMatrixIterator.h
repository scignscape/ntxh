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
 * Copyright (c) 2003-2011 by PGMed@FIT         \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2011/05/30                          \n
 * 
 * Description:
 * - Sparse matrix iterator definition.
 */

#ifndef VPL_SPARSEMATRIXITERATOR_H
#define VPL_SPARSEMATRIXITERATOR_H

#include <VPL/Base/Types.h>
#include <VPL/Base/IteratorBase.h>
#include <VPL/Base/TypeTraits.h>
#include <VPL/Base/Templates.h>


namespace vpl
{

// Declare iterator traits first...
VPL_ITERATOR_TEMPLATE_TRAITS(math, CSparseMatrixIterator)

namespace math
{

//==============================================================================
/*!
 * Sparse matrix iterator.
 * - Semantics of the iterator differ from that of standard matrix iterator
 *   because it iterates over non-zero elements only!
 * - Template parameter M is the matrix type.
 * - Parameter T is the matrix element type.
 */
template <class M, typename T>
class CSparseMatrixIterator : public vpl::base::CIteratorBase<CSparseMatrixIterator<M, T> >
{
public:
    //! Check that M is a matrix. You will see name of this enum somewhere
    //! in compiler error message if the type M is not matrix.
    enum { TEMPLATE_PARAMETER_IS_NOT_SPARSE_MATRIX = M::CLASS_SPARSEMATRIX };

    //! Matrix type.
    typedef M tMatrix;

    //! Element type.
    typedef T tElement;

public:
    //! Constructor.
    CSparseMatrixIterator(tMatrix& Matrix)
        : m_Matrix(Matrix)
        , m_OutIndex(0)
        , m_InnerIt(Matrix.asEigen(), 0)
    {}

    //! Destructor.
    ~CSparseMatrixIterator() {}

    //! Returns the current iterator position.
    tSize row() const { return m_InnerIt.row(); }
    tSize col() const { return m_InnerIt.col(); }

    //! Moves iterator to the next element.
    void advance()
    {
        ++m_InnerIt;
        if( !m_InnerIt )
        {
            ++m_OutIndex;
            if( m_OutIndex < m_Matrix.asEigen().outerSize() )
            {
                m_InnerIt = tInnerIterator(m_Matrix->asEigen(), m_OutIndex);
            }
        }
    }

    //! Returns true if the iterator points after the end.
    bool atEnd() const
    {
        return !m_InnerIt;
    }

    //! Returns the current item.
    const tElement& value() const
    {
        return m_InnerIt.value();
    }

    //! Returns reference to the current item.
    tElement& valueRef() const
    {
        return m_InnerIt.valueRef();
    }

    //! Returns pointer to the current item.
    tElement *valuePtr() const
    {
        return &m_InnerIt.valueRef();
    }

    //! Returns number of non-dominant values in the matrix.
    tSize getSize() const
    {
        return m_Matrix.getNumOfNonDominant();
    }

protected:
    //! Reference to the matrix.
    tMatrix& m_Matrix;

    //! Column iterator.
    typedef typename tMatrix::InnerIterator tInnerIterator;

    //! Iterator position.
    tSize m_OutIndex;

    //! Column iterator.
    tInnerIterator m_InnerIt;

private:
    //! Private assignment operator.
    CSparseMatrixIterator& operator =(const CSparseMatrixIterator&) { return *this; }
};


} // namespace math
} // namespace vpl

#endif // VPL_SPARSEMATRIXITERATOR_H
