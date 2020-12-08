//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/04/19                          \n
 *
 * $Id: mdsKernel.cpp 2065 2012-02-02 23:29:38Z spanel $
 * 
 * Description:
 * - Convolution kernel definition.
 */

#include <MDSTk/Image/mdsKernel.h>

#include <MDSTk/Base/mdsMemory.h>
#include <MDSTk/Math/mdsBase.h>

#include <cstring>


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Implementation of the class mds::img::CKernel1D.
 */
CKernel1D::CKernel1D(tSize Size) : data(Size)
{
    MDS_ASSERT((Size % 2) == 1);
}


CKernel1D::CKernel1D(CKernel1D::tConstDataPtr pData, tSize Size) : data(Size)
{
    MDS_ASSERT((Size % 2) == 1);

    // Copy the kernel data
    mds::base::memCopy(m_pData, pData, m_Size);
}


CKernel1D::CKernel1D(const CKernel1D& k) : data(k)
{
}


void CKernel1D::create(tSize Size)
{
    MDS_ASSERT((Size % 2) == 1);

    // Reallocate the memory
    data::create(Size);
}


CKernel1D& CKernel1D::operator =(const CKernel1D& k)
{
    if( &k == this )
    {
        return *this;
    }

    tSize Count = mds::math::getMin(m_Size, k.m_Size);
    mds::base::memCopy(m_pData, k.m_pData, Count);

    return *this;
}


//==============================================================================
/*
 * Implementation of the class mds::img::CKernel2D.
 */
CKernel2D::CKernel2D(tSize Size)
    : data(Size * Size)
    , m_YOffset(Size)
{
    MDS_ASSERT((Size % 2) == 1);
}


CKernel2D::CKernel2D(CKernel2D::tConstDataPtr pData, tSize Size)
    : data(Size * Size)
    , m_YOffset(Size)
{
    MDS_ASSERT((Size % 2) == 1);

    // Copy the kernel data
    mds::base::memCopy(m_pData, pData, m_Size);
}


CKernel2D::CKernel2D(const CKernel2D& k)
    : data(k)
    , m_YOffset(k.m_YOffset)
{
}


void CKernel2D::create(tSize Size)
{
    MDS_ASSERT((Size % 2) == 1);

    // Reallocate the memory
    data::create(Size * Size);
    m_YOffset = Size;
}


CKernel2D& CKernel2D::operator =(const CKernel2D& k)
{
    if( &k == this )
    {
        return *this;
    }

    tSize Count = mds::math::getMin(m_YOffset, k.m_YOffset);
    for( tSize j = 0; j < Count; ++j )
    {
        mds::base::memCopy(m_pData + j * m_YOffset, k.m_pData + j * k.m_YOffset, Count);
    }

    return *this;
}


//==============================================================================
/*
 * Implementation of the class mds::img::CKernel3D.
 */
CKernel3D::CKernel3D(tSize Size)
    : data(Size * Size * Size)
    , m_YOffset(Size)
    , m_ZOffset(Size * Size)
{
    MDS_ASSERT((Size % 2) == 1);
}


CKernel3D::CKernel3D(CKernel3D::tConstDataPtr pData, tSize Size)
    : data(Size * Size * Size)
    , m_YOffset(Size)
    , m_ZOffset(Size * Size)
{
    MDS_ASSERT((Size % 2) == 1);

    // Copy the kernel data
    mds::base::memCopy(m_pData, pData, m_Size);
}


CKernel3D::CKernel3D(const CKernel3D& k)
    : data(k)
    , m_YOffset(k.m_YOffset)
    , m_ZOffset(k.m_ZOffset)
{
}


void CKernel3D::create(tSize Size)
{
    MDS_ASSERT((Size % 2) == 1);

    // Reallocate the memory
    data::create(Size * Size * Size);
    m_YOffset = Size;
    m_ZOffset = Size * Size;
}


CKernel3D& CKernel3D::operator =(const CKernel3D& k)
{
    if( &k == this )
    {
        return *this;
    }

    tSize Count = mds::math::getMin(m_YOffset, k.m_YOffset);

    for( tSize i = 0; i < Count; ++i )
    {
        for( tSize j = 0; j < Count; ++j )
        {
            mds::base::memCopy(m_pData + i * m_ZOffset + j * m_YOffset,
                               k.m_pData + i * k.m_ZOffset + j * k.m_YOffset,
                               Count
                               );
        }
    }
    return *this;
}


} // namespace img
} // namespace mds

