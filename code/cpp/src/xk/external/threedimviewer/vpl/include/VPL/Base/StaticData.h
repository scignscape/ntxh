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
 * Date:    2006/02/15                          \n
 *
 * Description:
 * - Class template providing data allocation functions.
 * - Implemented via static array.
 */

#ifndef VPL_StaticData_H
#define VPL_StaticData_H

#include <VPL/System/Memory.h>

#include "Assert.h"
#include "Types.h"
#include "Exception.h"
#include "Meta.h"
#include "DataAllocator.h"


namespace vpl
{
namespace base
{

//==============================================================================
/*
 * Global definitions.
 */

//! Exception thrown when you are trying increase size of a static memory block.
VPL_DECLARE_EXCEPTION(CBadStaticAlloc, "Cannot increase size of a static memory block")


//==============================================================================
/*!
 * Class template providing data allocation implemented via a static array
 * of elements
 */
template <typename T, tSize M>
class CStaticData : public CDataAllocator<T>
{
public:
    // Base types
    typedef CDataAllocator<T> base;
    typedef typename base::tData tData;
    typedef typename base::tDataPtr tDataPtr;
    typedef typename base::tConstData tConstData;
    typedef typename base::tConstDataPtr tConstDataPtr;

    //! Maximal allowed size of the memory block.
    enum { MAX_SIZE = M };

public:
    //! Default constructor initializes length of the data to MAX_SIZE.
    inline CStaticData();

    //! This constructor does noething.
    //! - Be sure that one of the methods resize() or copy() are called
    //!   somewhere later.
    //! - Use with care!
    inline explicit CStaticData(EEmptyConst);

    //! Constructor initializes size of data.
    //! - Data of zero size can be also created.
    //! - Throws vpl::base::CBadStaticAlloc() if the specified size
    //!   is greater then the allowed MAX_SIZE!
    inline explicit CStaticData(tSize Size);

    //! Constructor that copies a specified data.
    inline CStaticData(tConstDataPtr pData, tSize Size);

    //! Constructor copies given data.
    inline CStaticData(const CStaticData& Data);

    //! Destructor.
    inline ~CStaticData();

    //! Assignment operator.
    //! - Resizes he current vector and copies all the elements.
    inline CStaticData& operator =(const CStaticData& Data);

    //! Resizes the memory block.
    //! - Throws vpl::base::CBadStaticAlloc() if the specified size
    //!   is greater then the allowed MAX_SIZE!
    inline CStaticData& resize(tSize Size);

    //! Copies the specified data.
    inline CStaticData& copy(tConstDataPtr pData, tSize Size);

    //! Allocates memory and copies the specified data.
    inline CStaticData& copy(const CStaticData& Data);

    //! Initializes the data.
    inline CStaticData& fill(const tData& Value);


    //! Returns current data size.
    tSize getSize() const { return m_Size; }

    //! Returns reference to the subscripted element [i].
    T& operator ()(tSize i)
    {
        return m_pData[i];
    }
    const T& operator ()(tSize i) const
    {
        return m_pData[i];
    }

    //! Returns reference to the element [i].
    T& at(tSize i)
    {
        return m_pData[i];
    }
    const T& at(tSize i) const
    {
        return m_pData[i];
    }

    //! Returns pointer to the element [i].
    T *getPtr(tSize i)
    {
        return (m_pData + i);
    }
    const T *getPtr(tSize i) const
    {
        return (m_pData + i);
    }

    //! Sets the element of matrix at the position [i].
    CStaticData& set(tSize i, const T& Value)
    {
        m_pData[i] = Value;
        return *this;
    }

    //! Returns pointer to the data.
    T *getPtr()
    {
        return m_pData;
    }
    const T *getPtr() const
    {
        return m_pData;
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

protected:
    //! Current size.
    tSize m_Size;

    //! Statically allocated data.
    tData m_pData[M];
};


//==============================================================================
/*
 * Method templates
 */

// Include file containing method templates
#include "StaticData.hxx"


} // namespace base
} // namespace vpl

#endif // VPL_StaticData_H

