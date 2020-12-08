//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/10/30                          \n
 *
 * $Id: mdsMatrixIterator.h 2094 2012-02-16 01:54:45Z spanel $
 * 
 * Description:
 * - Matrix iterator definition.
 */

#ifndef MDS_MATRIXITERATOR_H
#define MDS_MATRIXITERATOR_H

#include <MDSTk/Base/mdsIteratorBase.h>


namespace mds
{

// Declare iterator traits first...
MDS_ITERATOR_TEMPLATE_TRAITS(math, CMatrixIterator)

namespace math
{

//==============================================================================
/*!
 * Iterator used to traverse matrix elements by rows.
 * - Template parameter M is the matrix type.
 * - Parameter T is the matrix element type.
 */
template <class M, typename T>
class CMatrixIterator : public mds::base::CIteratorBase<CMatrixIterator<M, T> >
{
public:
    //! Check that M is a matrix. You will see name of this enum somewhere
    //! in compiler error message if the type M is not matrix.
    enum { TEMPLATE_PARAMETER_IS_NOT_MATRIX = M::CLASS_MATRIX };

    //! Matrix type.
    typedef M tMatrix;

    //! Element type.
    typedef T tElement;

public:
    //! Constructor.
    CMatrixIterator(tMatrix& Matrix)
        : m_Matrix(Matrix)
        , m_Row(0)
        , m_Col(0)
    {}

    //! Destructor.
    ~CMatrixIterator() {}

    //! Returns current iterator position.
    tSize row() const { return m_Row; }
    tSize col() const { return m_Col; }
    
    //! Moves iterator to the next element.
    void advance()
    {
        if( ++m_Col >= m_Matrix.getNumOfCols() )
        {
            m_Col = 0;
            ++m_Row;
        }
    }

    //! Returns true if the iterator points after the end.
    bool atEnd() const
    {
        return (m_Row >= m_Matrix.getNumOfRows());
    }

    //! Returns the current item.
    const tElement& value() const
    {
        return m_Matrix.at(m_Row, m_Col);
    }

    //! Returns reference to the current item.
    tElement& valueRef() const
    {
        return m_Matrix.at(m_Row, m_Col);
    }

    //! Returns pointer to the current item.
    tElement *valuePtr() const
    {
        return m_Matrix.getPtr(m_Row, m_Col);
    }

    //! Returns size of the volume in voxels.
    tSize getSize() const
    {
        return m_Matrix.getNumOfRows() * m_Matrix.getNumOfCols();
    }

protected:
    //! Reference to the matrix.
    tMatrix& m_Matrix;

    //! Iterator position.
    tSize m_Row, m_Col;

private:
    //! Private assignment operator.
    CMatrixIterator& operator =(const CMatrixIterator&) { return *this; }
};


} // namespace math
} // namespace mds

#endif // MDS_MATRIXITERATOR_H

