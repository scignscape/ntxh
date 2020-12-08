//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by PGMed@FIT         \n
 *
 * Authors: Miroslav Svub, svub@fit.vutbr.cz    \n
 *          Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/04/01                          \n
 *
 * $Id:$
 *
 * Description:
 * - Sparse matrix iterator definition.
 */

#ifndef MDS_SparseMatrixAltIterator_H
#define MDS_SparseMatrixAltIterator_H

#include <MDSTk/Base/mdsTypes.h>
#include <MDSTk/Base/mdsIteratorBase.h>
#include <MDSTk/Base/mdsTypeTraits.h>
#include <MDSTk/Base/mdsTemplates.h>


namespace mds
{

// Declare iterator traits first...
MDS_ITERATOR_TEMPLATE_TRAITS(math, CSparseMatrixAltIterator)

namespace math
{

//==============================================================================
/*!
 * Sparse matrix iterator.
 * - Warning semantics of it's methods differ from that of standard 
 *   matrix iterator becasue it iterates over non-zero elements only!
 * - Template parameter M is the matrix type.
 * - Parameter T is the matrix element type.
 */
template <class M, typename T>
class CSparseMatrixAltIterator : public mds::base::CIteratorBase<CSparseMatrixAltIterator<M, T> >
{
public:
    //! Check that M is a matrix. You will see name of this enum somewhere
    //! in compiler error message if the type M is not matrix.
    enum { TEMPLATE_PARAMETER_IS_NOT_SPARSE_MATRIX = M::CLASS_SPARSEMATRIX };

    //! Matrix type.
    typedef M tMatrix;

    //! Element type.
    typedef T tElement;

    //! Column iterator.
    typedef typename mds::SSelect<mds::CTypeTraits<M>::isConst, typename tMatrix::tColConstIterator, typename tMatrix::tColIterator>::RESULT tColumnIterator;

public:
    //! Constructor.
    CSparseMatrixAltIterator(tMatrix& Matrix)
        : m_Matrix(Matrix)
        , m_Row(0)
        , m_Col(0)
    {
        m_ColIt = m_Matrix.getColBegin(m_Col);
        while( m_ColIt == m_Matrix.getColEnd(m_Col) )
        {
            if( ++m_Col >= m_Matrix.getNumOfCols() )
            {
                return;
            }
            m_ColIt = m_Matrix.getColBegin(m_Col);
        }
        m_Row =  m_ColIt->first;
    }

    //! Destructor.
    ~CSparseMatrixAltIterator() {}

    //! Returns the current iterator position.
    tSize row() const { return m_Row; }
    tSize col() const { return m_Col; }

    //! Moves iterator to the next element.
    void advance()
    {
        ++m_ColIt;
        while( m_ColIt == m_Matrix.getColEnd(m_Col) )
        {
            if( ++m_Col >= m_Matrix.getNumOfCols() )
            {
                return;
            }
            m_ColIt = m_Matrix.getColBegin(m_Col);
        }
        m_Row =  m_ColIt->first;
    }

    //! Returns true if the iterator points after the end.
    bool atEnd() const
    {
        return (m_Col >= m_Matrix.getNumOfCols());
    }

    //! Returns the current item.
    const tElement& value() const
    {
        return m_ColIt->second;
    }

    //! Returns reference to the current item.
    tElement& valueRef() const
    {
        return m_ColIt->second;
    }

    //! Returns pointer to the current item.
    tElement *valuePtr() const
    {
        return &(m_ColIt->second);
    }

    //! Returns size of the volume in voxels.
    tSize getSize() const
    {
        return m_Matrix.getNumOfNonDominant();
    }

protected:
    //! Reference to the matrix;
    tMatrix& m_Matrix;

    //! Iterator position.
    tSize m_Row, m_Col;

    //! Iterator true position in sparse column.
    tColumnIterator m_ColIt;

private:
    //! Private assignment operator.
    CSparseMatrixAltIterator& operator =(const CSparseMatrixAltIterator&) { return *this; }
};


} // namespace math
} // namespace mds

#endif // MDS_SparseMatrixAltIterator_H
