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
 * Date:    2004/11/22                          \n
 *
 * Description:
 * - Class template managing references to 1D data array.
 * - Provides own data reference counting mechanism.
 */

#ifndef VPL_RefData_H
#define VPL_RefData_H

#include "Data.h"


namespace vpl
{

//==============================================================================
/*
 * Global constants.
 */

//! Enumeration constant used for making reference to data. It is usually
//! the last parameter of a constructor. Finally, there are two constructor
//! types. First one is used to make a new copy of an object,
//! second one to make a new reference.
enum EMakeRef
{
    REFERENCE
};


namespace base
{

//==============================================================================
/*!
 * Class template to allocate memory blocks and manage references memory blocks.
 * - Functions vpl::sys::memAlloc() and vpl::sys::memFree() are used internally
 *   to allocate a continuous block of memory.
 * - If the macro VPL_USE_ALIGNED_MEMORY_ALLOCATIONS is defined
 *   (see CMake options), the biginning of the block is aligned 
 *   to vpl::sys::DEFAULT_MEMORY_ALIGNMENT bytes.
 */
template <typename T>
class CRefData : public CDataAllocator<T>
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
    inline CRefData();

    //! This constructor does no allocation of the data.
    //! - Be sure that one of the methods resize(), copy() or makeRef()
    //!   are called somewhere later.
    //! - Use with care!
    inline explicit CRefData(EEmptyConst);

    //! Constructor that allocates a given size of data.
    //! - Data of the zero size can be allocated.
    inline explicit CRefData(tSize Size);

    //! Constructor that copies specified data.
    inline CRefData(tConstDataPtr pData, tSize Size);

    //! Constructor copies given data.
    inline CRefData(const CRefData& Data);

    //! Constructor which makes reference to existing data.
    //! - Usage: CRefData(Data, REFERENCE).
    inline CRefData(const CRefData& Data, EMakeRef);

    //! Destructor deallocates the data if the number of references
    //! decreases to zero.
    inline ~CRefData();

    //! Assignment operator.
    //! - Resizes the memory block and makes copy of the data.
    inline CRefData& operator=(const CRefData& Data);

    //! Allocates data of a given size.
    //! - If Size is smaller than the current size,
    //!   the content is reduced by removing elements beyond (no destructor called).
    //! - If Size is greater than the current size, the content is expanded
    //!   by allocating more memory (no initialiazation of the new elements
    //!   is performed).
    //! - If several references exist to the currente data, the reference
    //!   counter is decremented and new data block is allocated.
    //! - Returns reference to this.
    inline CRefData& resize(tSize Size);

    //! Allocates memory and copies the specified data to it.
    //! - Returns reference to this.
    inline CRefData& copy(tConstDataPtr pData, tSize Size);

    //! Allocates memory and copies the specified data.
    //! - Returns reference to this.
    inline CRefData& copy(const CRefData& Data);

    //! Makes a new reference to the existing data.
    //! - Eventually deallocates the current data block if no more
    //!   references exist.
    //! - Returns reference to this.
    inline CRefData& makeRef(const CRefData& Data);

    //! Initializes the data.
    inline CRefData& fill(const tData& Value);


    //! Returns data size.
    tSize getSize() const
    {
        return (m_pRef) ? m_pRef->m_Size : 0;
    }

    //! Returns the number of references to the data.
    int getNumOfReferences() const
    {
        return (m_pRef) ? m_pRef->m_iReferences : 0;
    }

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
        return m_pRef->m_pData[m_pRef->m_Sampling.adjustIdx(i)];
    }
    const tData& at(tSize i) const
    {
        return m_pRef->m_pData[m_pRef->m_Sampling.adjustIdx(i)];
    }

    //! Returns pointer to the given element.
    tDataPtr getPtr(tSize i)
    {
        return (m_pRef->m_pData + m_pRef->m_Sampling.adjustIdx(i));
    }
    tConstDataPtr getPtr(tSize i) const
    {
        return (m_pRef->m_pData + m_pRef->m_Sampling.adjustIdx(i));
    }

    //! Sets the element of matrix at the position [i].
    CRefData& set(tSize i, const T& Value)
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


    //! Calls function object for every element.
    template <class Function>
    inline Function forRange(tSize i, tSize j, Function Func);

    //! Calls function object for every element.
    template <class Function>
    inline Function forRange(tSize i, tSize j, Function Func) const;


    //! Returns reference to the data sampling strategy.
    CDataSampling& getSampling()
    {
        VPL_ASSERT(m_pRef);

        return m_pRef->m_Sampling;
    }
    const CDataSampling& getSampling() const
    {
        VPL_ASSERT(m_pRef);

        return m_pRef->m_Sampling;
    }

protected:
    //! Structure containing information on allocated data
    //! and the number of references to this data.
    struct SRefInfo
    {
        //! Size of the allocated data.
        tSize m_Size;

        //! Pointer to the allocated data.
        tDataPtr m_pData;

        //! Helper data sampling structure.
        CDataSampling m_Sampling;

        //! The number of references to the data.
        //! - Zero if there is no reference.
        volatile int m_iReferences;

        //! Constructor that allocates a given size of data.
        //! - Allocation of the zero size data is allowed.
        inline SRefInfo(tSize Size);

        //! Destructor.
        //! - Deallocates the data.
        inline ~SRefInfo();
        
        //! Resizes the data.
        //! - Function doesn't check the number of references.
        inline void resize(tSize Size);
    };

    //! Pointer to the structure containing the referenced data.
    SRefInfo *m_pRef;
};


//==============================================================================
/*
 * Method templates
 */

// Include file containing method templates
#include "RefData.hxx"


} // namespace base
} // namespace vpl

#endif // VPL_RefData_H

