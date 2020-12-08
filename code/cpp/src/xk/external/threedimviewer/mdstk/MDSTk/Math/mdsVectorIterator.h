//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/09/15                          \n
 *
 * $Id: mdsVectorIterator.h 2094 2012-02-16 01:54:45Z spanel $
 * 
 * Description:
 * - Vector iterator definition.
 */

#ifndef MDS_VECTORITERATOR_H
#define MDS_VECTORITERATOR_H

#include <MDSTk/Base/mdsIteratorBase.h>


namespace mds
{

// Declare iterator traits first...
MDS_ITERATOR_TEMPLATE_TRAITS(math, CVectorIterator)

namespace math
{

//==============================================================================
/*!
 * Iterator used to traverse vector elements.
 * - Template parameter V is the vector type.
 * - Parameter T is the vector element type.
 */
template <class V, typename T>
class CVectorIterator : public mds::base::CIteratorBase<CVectorIterator<V, T> >
{
public:
    //! Check that V is a vector. You will see name of this enum somewhere
    //! in compiler error message if the type V is not vector.
    enum { TEMPLATE_PARAMETER_IS_NOT_VECTOR = V::CLASS_VECTOR };

    //! Vector type.
    typedef V tVector;

    //! Element type.
    typedef T tElement;

public:
    //! Constructor.
    CVectorIterator(tVector& Vector)
        : m_Vector(Vector)
        , m_i(0)
    {}

    //! Destructor.
    ~CVectorIterator() {}

    //! Returns the current iterator position.
    tSize index() const { return m_i; }

    //! Moves iterator to the next element.
    void advance() { ++m_i; }

    //! Returns true if the iterator points after the end.
    bool atEnd() const
    {
        return (m_i >= m_Vector.getSize());
    }

    //! Returns the current item.
    const tElement& value() const
    {
        return m_Vector.at(m_i);
    }

    //! Returns reference to the current item.
    tElement& valueRef() const
    {
        return m_Vector.at(m_i);
    }

    //! Returns pointer to the current item.
    tElement *valuePtr() const
    {
        return m_Vector.getPtr(m_i);
    }

    //! Returns size of the vector.
    tSize getSize() const
    {
        return m_Vector.getSize();
    }

protected:
    //! Reference to the vector.
    tVector& m_Vector;

    //! Iterator position.
    tSize m_i;

private:
    //! Private assignment operator.
    CVectorIterator& operator =(const CVectorIterator&) { return *this; }
};


} // namespace math
} // namespace mds

#endif // MDS_VECTORITERATOR_H

