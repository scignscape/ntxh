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
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/04/19                       
 * 
 * Description:
 * - Convolution kernel definition.
 */

#include <VPL/Image/Kernel.h>

#include <VPL/System/Memory.h>
#include <VPL/Math/Base.h>

#include <cstring>


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Implementation of the class vpl::img::CKernel1D.
 */
CKernel1D::CKernel1D(tSize Size) : data(Size)
{
    VPL_ASSERT((Size % 2) == 1);
}


CKernel1D::CKernel1D(CKernel1D::tConstDataPtr pData, tSize Size) : data(Size)
{
    VPL_ASSERT((Size % 2) == 1);

    // Copy the kernel data
    vpl::sys::memCopy(m_pData, pData, m_Size);
}


CKernel1D::CKernel1D(const CKernel1D& k) : data(k)
{
}


void CKernel1D::resize(tSize Size)
{
    VPL_ASSERT((Size % 2) == 1);

    // Reallocate the memory
    data::resize(Size);
}


CKernel1D& CKernel1D::operator =(const CKernel1D& k)
{
    if( &k == this )
    {
        return *this;
    }

    tSize Count = vpl::math::getMin(m_Size, k.m_Size);
    vpl::sys::memCopy(m_pData, k.m_pData, Count);

    return *this;
}


//!\brief   Normalizes this object.
void CKernel1D::normalize()
{
    tConvKernelData sum(0.0);
    for(tSize s = 0; s < m_Size; ++s)
        sum += (*this)(s);

    for(tSize s = 0; s < m_Size; ++s)
        (*this)(s) /= sum;
}


//==============================================================================
/*
 * Implementation of the class vpl::img::CKernel2D.
 */
CKernel2D::CKernel2D(tSize Size)
    : data(Size * Size)
    , m_YOffset(Size)
{
    VPL_ASSERT((Size % 2) == 1);
}


CKernel2D::CKernel2D(CKernel2D::tConstDataPtr pData, tSize Size)
    : data(Size * Size)
    , m_YOffset(Size)
{
    VPL_ASSERT((Size % 2) == 1);

    // Copy the kernel data
    vpl::sys::memCopy(m_pData, pData, m_Size);
}


CKernel2D::CKernel2D(const CKernel2D& k)
    : data(k)
    , m_YOffset(k.m_YOffset)
{
}


void CKernel2D::resize(tSize Size)
{
    VPL_ASSERT((Size % 2) == 1);

    // Reallocate the memory
    data::resize(Size * Size);
    m_YOffset = Size;
}


CKernel2D& CKernel2D::operator =(const CKernel2D& k)
{
    if( &k == this )
    {
        return *this;
    }

    tSize Count = vpl::math::getMin(m_YOffset, k.m_YOffset);
    for( tSize j = 0; j < Count; ++j )
    {
        vpl::sys::memCopy(m_pData + j * m_YOffset, k.m_pData + j * k.m_YOffset, Count);
    }

    return *this;
}


//==============================================================================
/*
 * Implementation of the class vpl::img::CKernel3D.
 */
CKernel3D::CKernel3D(tSize Size)
    : data(Size * Size * Size)
    , m_YOffset(Size)
    , m_ZOffset(Size * Size)
{
    VPL_ASSERT((Size % 2) == 1);
}


CKernel3D::CKernel3D(CKernel3D::tConstDataPtr pData, tSize Size)
    : data(Size * Size * Size)
    , m_YOffset(Size)
    , m_ZOffset(Size * Size)
{
    VPL_ASSERT((Size % 2) == 1);

    // Copy the kernel data
    vpl::sys::memCopy(m_pData, pData, m_Size);
}


CKernel3D::CKernel3D(const CKernel3D& k)
    : data(k)
    , m_YOffset(k.m_YOffset)
    , m_ZOffset(k.m_ZOffset)
{
}


void CKernel3D::resize(tSize Size)
{
    VPL_ASSERT((Size % 2) == 1);

    // Reallocate the memory
    data::resize(Size * Size * Size);
    m_YOffset = Size;
    m_ZOffset = Size * Size;
}


CKernel3D& CKernel3D::operator =(const CKernel3D& k)
{
    if( &k == this )
    {
        return *this;
    }

    tSize Count = vpl::math::getMin(m_YOffset, k.m_YOffset);

    for( tSize i = 0; i < Count; ++i )
    {
        for( tSize j = 0; j < Count; ++j )
        {
            vpl::sys::memCopy(m_pData + i * m_ZOffset + j * m_YOffset,
                               k.m_pData + i * k.m_ZOffset + j * k.m_YOffset,
                               Count
                               );
        }
    }
    return *this;
}


} // namespace img
} // namespace vpl

