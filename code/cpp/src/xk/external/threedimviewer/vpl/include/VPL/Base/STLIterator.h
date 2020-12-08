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
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2010 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/10                       
 *
 * Description:
 * - Container encapsulating any STL container.
 */

#ifndef VPL_STLIterator_H
#define VPL_STLIterator_H

#include "IteratorBase.h"

#include <iterator>


namespace vpl
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
} // namespace vpl

#endif // VPL_STLIterator_H
