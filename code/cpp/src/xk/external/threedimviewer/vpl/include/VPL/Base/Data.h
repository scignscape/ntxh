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
 * Date:    2004/11/23                          \n
 *
 * Description:
 * - Template providing data allocation functions.
 * - Functions malloc() and free() are used internally.
 */

#ifndef VPL_Data_H
#define VPL_Data_H

#include <VPL/System/Memory.h>

#include "Assert.h"
#include "Types.h"
#include "Exception.h"
#include "DataAllocator.h"


namespace vpl
{
namespace base
{

//==============================================================================
/*!
 * Class template providing basic data allocation functions.
 * - Functions vpl::sys::memAlloc() and vpl::sys::memFree() are used internally
 *   to allocate a continuous block of memory.
 * - If the macro VPL_USE_ALIGNED_MEMORY_ALLOCATIONS is defined
 *   (see CMake options), the biginning of the block is aligned 
 *   to vpl::sys::DEFAULT_MEMORY_ALIGNMENT bytes.
 */
template <typename T>
class CData : public CDataAllocator<T>
{
public:
    // Base types
    typedef CDataAllocator<T> base;
    typedef typename base::tData tData;
    typedef typename base::tDataPtr tDataPtr;
    typedef typename base::tConstData tConstData;
    typedef typename base::tConstDataPtr tConstDataPtr;

    //! This allocator provides an advanced data sampling.
    //! Templates that require this functionality may check existence of this enum.
    enum { DATA_SAMPLING_ALLOWED };

public:
    //! Default constructor allocates data of zero length.
    inline CData();

    //! This constructor does no allocation of the data.
    //! - Be sure that one of the methods resize() or copy() are called
    //!   somewhere later.
    //! - Use with care!
    inline explicit CData(EEmptyConst);

    //! Constructor that allocates a given size of data.
    //! - Data of the zero size can be also allocated.
    inline explicit CData(tSize Size);

    //! Constructor that copies a specified data.
    inline CData(tConstDataPtr pData, tSize Size);

    //! Constructor copies a given data.
    inline CData(const CData& Data);

    //! Destructor deallocates the data.
    inline ~CData();

    //! Assignment operator.
    //! - Resizes the current block and copies all the elements.
    CData& operator =(const CData& Data);

    //! Allocates memory for data of a given size.
    //! - If Size is smaller than the current size,
    //!   the content is reduced by removing elements beyond (no destructor called).
    //! - If Size is greater than the current size, the content is expanded
    //!   by allocating more memory (no initialiazation of the new elements
    //!   is performed).
    //! - Returns reference to this.
    inline CData& resize(tSize Size);

    //! Allocates memory and copies the specified data.
    //! - Returns reference to this.
    inline CData& copy(tConstDataPtr pData, tSize Size);

    //! Allocates memory and copies the specified data.
    //! - Returns reference to this.
    inline CData& copy(const CData& Data);

    //! Fills the entire data.
    inline CData& fill(const tData& Value);


    //! Returns size of the data.
    tSize getSize() const { return m_Size; }

    //! Returns reference to the subscripted element [i].
    tData& operator ()(tSize i)
    {
		return at(i);
    }
    const tData& operator ()(tSize i) const
    {
		return at(i);
    }

    //! Returns reference to the element [i].
    tData& at(tSize i)
    {
        return m_pData[m_Sampling.adjustIdx(i)];
    }
    const tData& at(tSize i) const
    {
        return m_pData[m_Sampling.adjustIdx(i)];
    }

    //! Returns pointer to the element [i].
    tDataPtr getPtr(tSize i)
    {
        return (m_pData + m_Sampling.adjustIdx(i));
    }
    tConstDataPtr getPtr(tSize i) const
    {
        return (m_pData + m_Sampling.adjustIdx(i));
    }

    //! Sets the element of matrix at the position [i].
    CData& set(tSize i, const T& Value)
    {
		at(i) = Value;
        return *this;
    }

    //! Returns pointer to the data.
    tDataPtr getPtr()
    {
		return getPtr(0);
    }
    tConstDataPtr getPtr() const
    {
		return getPtr(0);
    }

    //! Returns true if the specified range of elements lie within
    //! a single continuous block of memory.
    bool isWithinBlock(tSize VPL_UNUSED(i), tSize VPL_UNUSED(j)) const { return true; }


    //! Calls function object for every element.
    template <class Function>
    inline Function forEach(Function Func);

    //! Calls function object for every element.
    template <class Function>
    inline Function forEach(Function Func) const;


    //! Calls function object for all elements in the range <i, j>.
    template <class Function>
    inline Function forRange(tSize i, tSize j, Function Func);

    //! Calls function object for all elements in the range <i, j>.
    template <class Function>
    inline Function forRange(tSize i, tSize j, Function Func) const;


    //! Returns reference to the data sampling strategy.
    CDataSampling& getSampling()
    {
        return m_Sampling;
    }
    const CDataSampling& getSampling() const
    {
        return m_Sampling;
    }

protected:
    //! Size of the allocated data.
    tSize m_Size;

    //! Pointer to the allocated data.
    tDataPtr m_pData;

    //! Helper data sampling structure.
    CDataSampling m_Sampling;
};


//==============================================================================
/*
 * Method templates
 */

// Include file containing method templates
#include "Data.hxx"


} // namespace base
} // namespace vpl

#endif // VPL_Data_H

