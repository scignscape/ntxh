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
 * Date:    2007/06/21                          \n
 *
 * Description:
 * - Class template managing references to 1D data array.
 * - Functions malloc() and free() are used internally.
 * - Provides own data reference counting mechanism.
 * - Allows to share data over shared memory.
 */

#ifndef VPL_SHMData_H
#define VPL_SHMData_H

#include "RefData.h"

#include <VPL/System/SharedMem.h>


namespace vpl
{
namespace base
{

//==============================================================================
/*!
 * Class template managing references to a block of allocated memory.
 * - Functions malloc() and free() are used internally.
 * - Provides own data reference counting mechanism.
 * - Allows to share data over shared memory.
 */
template <typename T>
class CSHMData : public CDataAllocator<T>
{
public:
    // Base types
    typedef CDataAllocator<T> base;
    typedef typename base::tData tData;
    typedef typename base::tDataPtr tDataPtr;
    typedef typename base::tConstData tConstData;
    typedef typename base::tConstDataPtr tConstDataPtr;

public:
    //! Default constructor allocates data of zero length.
    inline CSHMData();

    //! This constructor does no allocation of the data.
    //! - Be sure that one of the methods create() is called somewhere.
    //! - Use with care!
    inline explicit CSHMData(EEmptyConst);

    //! Constructor that allocates a given size of data.
    //! - Data of the zero size can be allocated.
    inline explicit CSHMData(tSize Size);

    //! Constructor that copies a specified data.
    inline CSHMData(tConstDataPtr pData, tSize Size);

    //! Constructor copies a given data.
    inline CSHMData(const CSHMData& Data);

    //! Constructor which makes reference to an existing data.
    //! - Usage: CSHMData(Data, REFERENCE).
    inline CSHMData(const CSHMData& Data, EMakeRef);

    //! Destructor deallocates the data if the number of references
    //! decreases to zero.
    inline ~CSHMData();

    //! Allocates data of a given size.
    //! - In case of several references to the existing data, the reference
    //!   counter is decremented and new data are allocated.
    //! - Returns reference to this.
    inline CSHMData& resize(tSize Size);

    //! Allocates data and copies the specified data to it.
    //! - Returns reference to this.
    inline CSHMData& copy(tConstDataPtr pData, tSize Size);

    //! Allocates data and copies the specified data.
    //! - Returns reference to this.
    inline CSHMData& copy(const CSHMData& Data);

    //! Makes a new reference to existing data.
    //! - Eventually deallocates the associated data.
    //! - Returns reference to this.
    inline CSHMData& makeRef(const CSHMData& Data);

    //! Constructs data in a shared memory block.
    //! - Returns reference to this.
    inline CSHMData& create(vpl::sys::CSharedMem *pSharedMem, tDataPtr pBegin, tSize Size);

    //! Assignment operator.
    //! - Makes copy of the data.
    inline CSHMData& operator=(const CSHMData& Data);

    //! Initializes the data.
    //! - Returns reference to this.
    inline CSHMData& fill(const tData& Value);


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

    //! Returns pointer to the shared memory or NULL if data are not located
    //! in the shared memory.
    vpl::sys::CSharedMem *getSharedMemPtr()
    {
        return (m_pRef) ? m_pRef->m_spSharedMem.get() : 0;
    }

    //! Returns reference to the subscripted element [i].
    tData& operator ()(tSize i)
    {
        return m_pRef->m_pData[i];
    }
    const tData& operator ()(tSize i) const
    {
        return m_pRef->m_pData[i];
    }

    //! Returns reference to the element [i].
    tData& at(tSize i)
    {
        return m_pRef->m_pData[i];
    }
    const tData& at(tSize i) const
    {
        return m_pRef->m_pData[i];
    }

    //! Returns pointer to the given element.
    tData *getPtr(tSize i)
    {
        return (m_pRef->m_pData + i);
    }
    const tData *getPtr(tSize i) const
    {
        return (m_pRef->m_pData + i);
    }

    //! Sets the element of matrix at the position [i].
    CSHMData& set(tSize i, const T& Value)
    {
        m_pRef->m_pData[i] = Value;
        return *this;
    }

    //! Returns pointer to the data.
    tDataPtr getPtr()
    {
        return m_pRef->m_pData;
    }
    tConstDataPtr getPtr() const
    {
        return m_pRef->m_pData;
    }

    //! Returns true if the specified range of elements lie within
    //! a continuous block of memory.
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

protected:
    //! Structure containing information on allocated data
    //! and the number of references to this data.
    struct SRefInfo
    {
        //! Size of the allocated data.
        tSize m_Size;

        //! Pointer to the allocated data.
        tDataPtr m_pData;

        //! The number of references to the data.
        int m_iReferences;

        //! Shared memory.
        vpl::sys::CSharedMemPtr m_spSharedMem;

        //! Constructor that allocates a given size of data.
        //! - Allocation of the zero size data is allowed.
        inline SRefInfo(tSize Size);

        //! Constructor that allocates a given size of data.
        //! - Allocation of the zero size data is allowed.
        inline SRefInfo(vpl::sys::CSharedMem *pSharedMem, tDataPtr pBegin, tSize Size);

        //! Destructor.
        //! - Deallocates the data.
        inline ~SRefInfo();

        //! Resizes the data.
        //! - Function doesn't care about the number of references.
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
#include "SHMData.hxx"


} // namespace base
} // namespace vpl

#endif // VPL_SHMData_H

