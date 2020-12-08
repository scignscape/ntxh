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
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/24                          \n
 *
 * Description:
 * - Base class template for all iterators.
 */

#ifndef VPL_IteratorBase_H
#define VPL_IteratorBase_H

#include "Templates.h"
#include "IteratorTraits.h"


namespace vpl
{
namespace base
{

//==============================================================================
/*!
 * Base class for all iterators.
 * - Parameter I is the iterator type.
 */
template <typename I>
class CIteratorBase
{
public:
    //! Iterator type.
    typedef I tDerived;

    //! Value (or item) type.
    typedef typename CIteratorTraits<I>::tItem tItem;

public:
    //! Returns reference to the iterator implementation.
    tDerived& getImpl()
    {
        return *static_cast<tDerived *>(this);
    }
    const tDerived& getImpl() const
    {
        return *static_cast<const tDerived *>(this);
    }

public:
    //! Returns pointer to the current item.
    tItem *operator->() const { return getImpl().valuePtr(); }

    //! Returns reference to the current item.
    tItem& operator*() const { return getImpl().valueRef(); }

    // Operator moves the iterator to the next item.
    // - Prefix notation.
    CIteratorBase& operator++()
    {
        getImpl().advance();
        return *this;
    }

    // Operator moves the iterator to the next item.
    // - Postfix notation.
    CIteratorBase operator++(int)
    {
        tDerived Temp(getImpl());
        getImpl().advance();
        return Temp;
    }

    //! Returns true if the iterator is valid, i.e. not pointing after the end.
    operator bool() const { return !(getImpl().atEnd()); }

    //! Returns the current item.
    const tItem& value() const { return getImpl().value(); }

    //! Returns reference to the current item.
    tItem& valueRef() const { return getImpl().valueRef(); }
    
    //! Returns pointer to the current item.
    tItem& valuePtr() const { return getImpl().valuePtr(); }

    //! Returns number of all items in the container.
    tSize getSize() const { return getImpl().getSize(); }
    
protected:
    //! Default constructor.
    CIteratorBase() {}

    //! Copy constructor.
    CIteratorBase(const CIteratorBase&) {}

    //! Assignment operator.
    CIteratorBase& operator =(const CIteratorBase&) { return &this; }
};


//==============================================================================
/*
 * Helper macros.
 */

//! Macro declares class members tIterator and tConstIterator
//! within a container class.
#define VPL_ITERATOR(ContainerType, ItemType, IteratorClass) \
    enum { ITERATOR_DECLARED }; \
    typedef IteratorClass<ContainerType, ItemType> tIterator; \
    typedef IteratorClass<const ContainerType, const ItemType> tConstIterator;


} // namespace base
} // namespace vpl

#endif // VPL_IteratorBase_H

