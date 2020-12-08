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
 * Copyright (c) 2011 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2011/05/29                          \n
 *
 * Description:
 * - Data allocator policy.
 */

#ifndef VPL_DataAllocator_H
#define VPL_DataAllocator_H

#include <VPL/System/Memory.h>

#include "Assert.h"
#include "Types.h"
#include "Exception.h"
#include "Meta.h"
#include "EmptyConst.h"


namespace vpl
{
namespace base
{

//==============================================================================
/*!
 * Base class for all classes providing data allocation functionality.
 * - Parameter T is an item type.
 */
template <typename T>
struct CDataAllocator
{
    //! Data type.
    typedef T tData;

    //! Pointer to the data.
    typedef T *tDataPtr;

    //! Const data type.
    typedef const T tConstData;

    //! Pointer to the constant data.
    typedef const T *tConstDataPtr;
};


//==============================================================================
/*!
 * Very simple class encapsulating modified sizing and indexing strategy
 * for data allocators.
 */
class CDataSampling
{
public:
    //! Default constructor.
    CDataSampling() : m_SizeMultiplier(1), m_SizeShift(0), m_IdxMultiplier(1), m_IdxShift(0) {}

    //! Copy constructor.
    CDataSampling(const CDataSampling& s)
        : m_SizeMultiplier(s.m_SizeMultiplier)
        , m_SizeShift(s.m_SizeShift)
        , m_IdxMultiplier(s.m_IdxMultiplier)
        , m_IdxShift(s.m_IdxShift)
    {}

    //! Assignment operator.
    CDataSampling& operator =(const CDataSampling& s)
    {
        m_SizeMultiplier = s.m_SizeMultiplier;
        m_SizeShift = s.m_SizeShift;
        m_IdxMultiplier = s.m_IdxMultiplier;
        m_IdxShift = s.m_IdxShift;
        return *this;
    }


    //! Changes modifiers which affect the data sizing before allocation.
    //! - allocated_size = size * multiplier + shift
    CDataSampling& setSizing(tSize Multiplier, tSize Shift)
    {
        m_SizeMultiplier = Multiplier;
        m_SizeShift = Shift;
        return *this;
    }

    //! Modifies a given size of the memory block before it is allocated.
    tSize adjustSize(tSize Size) const { return (Size * m_SizeMultiplier + m_SizeShift); }

    //! Changes sizing modifiers to the default values.
    CDataSampling& defaultSizing()
    {
        m_SizeMultiplier = 1;
        m_SizeShift = 0;
        return *this;
    }


    //! Changes modifiers which affect the data indexing.
    //! - real_index = index * multiplier + shift
    CDataSampling& setIndexing(tSize Multiplier, tSize Shift)
    {
        m_IdxMultiplier = Multiplier;
        m_IdxShift = Shift;
        return *this;
    }

    //! Modifies a given index before subscripting the element.
    tSize adjustIdx(tSize Index) const { return (Index * m_IdxMultiplier + m_IdxShift); }

    //! Changes indexing modifiers to default values.
    CDataSampling& defaultIndexing()
    {
        m_IdxMultiplier = 1;
        m_IdxShift = 0;
        return *this;
    }


    //! Returns true of the sizing strategy is the default one.
    bool isDefault() const { return (m_SizeMultiplier == 1 && m_SizeShift == 0 && m_IdxMultiplier == 1 && m_IdxShift == 0); }

public:
    //! Sizing and index modifiers.
    tSize m_SizeMultiplier, m_SizeShift;

    //! Indexing modifiers.
    tSize m_IdxMultiplier, m_IdxShift;
};


} // namespace base
} // namespace vpl

#endif // VPL_DataAllocator_H
