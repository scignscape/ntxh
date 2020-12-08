//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/10                          \n
 *
 * $Id: mdsSTLIterator.h 2101 2012-02-17 08:20:21Z spanel $
 *
 * Description:
 * - Container encapsulating any STL container.
 */

#ifndef MDS_STLIterator_H
#define MDS_STLIterator_H

#include "mdsIteratorBase.h"

#include <iterator>


namespace mds
{

//==============================================================================
/*
 * Declare iterator traits first.
 */

// Forward declaration
namespace base { template <typename I> class CSTLIterator; }

// Define iterator traits for the CSTLIterator
template <typename I>
struct CIteratorTraits<base::CSTLIterator<I> >
{
    typedef typename CTypeTraits<typename I::pointer>::tPointee tItem;
};


namespace base
{

//==============================================================================
/*!
 * STL iterator wrapper.
 * - Parameter I is any STL iterator (vector::iterator, map::const_iterator, etc.).
 */
template <typename I>
class CSTLIterator : public CIteratorBase<CSTLIterator<I> >
{
public:
    //! Iterator base.
    typedef CIteratorBase<CSTLIterator<I> > base;

    //! Item type.
    typedef typename base::tItem tItem;

    //! STL iterator.
    typedef I tSTLIterator;

public:
    //! Constructor.
    CSTLIterator(const tSTLIterator& Begin,
                 const tSTLIterator& End
                 )
        : m_Begin(Begin)
        , m_End(End)
    {}

    //! Copy constructor.
    CSTLIterator(const CSTLIterator& It)
        : m_Begin(It.m_Begin) 
        , m_End(It.m_End)
    {}

    //! Destructor.
    ~CSTLIterator() {}

    //! Assignment operator.
    CSTLIterator& operator=(const CSTLIterator& It)
    {
        if( *this != It )
        {
            m_Begin = It.m_Begin;
            m_End = It.m_End;
        }
        return *this;
    }

    //! Moves iterator to the next position.
    void advance() { ++m_Begin; }

    //! Returns true if the iterator position is valid.
    bool atEnd() const
    {
        return (m_Begin == m_End);
    }

    //! Returns the current item.
    const tItem& value() const
    {
        return *m_Begin;
    }

    //! Returns reference to the current item.
    tItem& valueRef() const
    {
        return *m_Begin;
    }

    //! Returns pointer to the current item.
    tItem *valuePtr() const
    {
        return &(*m_Begin);
    }

    //! Returns size of the sequence.
    tSize getSize() const
    {
        return std::distance(m_Begin, m_End);
    }

protected:
    //! Wrapped STL iterators.
    tSTLIterator m_Begin, m_End;
};


} // namespace base
} // namespace mds

#endif // MDS_STLIterator_H
