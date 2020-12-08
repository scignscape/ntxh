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
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/14                          \n
 *
 * Description:
 * - Density slice.
 */

#include <VPL/Image/Slice.h>


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Implementation of the class vpl::img::CSlice.
 */
CSlice::CSlice()
    : tBase(0, 0, DEFAULT_MARGIN)
    , m_dDX(1.0)
    , m_dDY(1.0)
    , m_dThickness(1.0)
    , m_dPosition(0.0)
    , m_Index(0)
    , m_eOrientation(PLANE_XY)
{
}


CSlice::CSlice(tSize XSize, tSize YSize, tSize Margin)
    : tBase(XSize, YSize, Margin)
    , m_dDX(1.0)
    , m_dDY(1.0)
    , m_dThickness(1.0)
    , m_dPosition(0.0)
    , m_Index(0)
    , m_eOrientation(PLANE_XY)
{
}


CSlice::CSlice(const CSlice& Slice)
    : tBase(Slice)
{
    copyProps(Slice);
}


CSlice::CSlice(const CSlice& Slice, EMakeRef)
    : tBase(Slice, REFERENCE)
{
    copyProps(Slice);
}


CSlice::CSlice(const CDImage& Image)
    : tBase(Image)
    , m_dDX(1.0)
    , m_dDY(1.0)
    , m_dThickness(1.0)
    , m_dPosition(0.0)
    , m_Index(0)
    , m_eOrientation(PLANE_XY)
{
}


CSlice::CSlice(const CDImage& Image, EMakeRef)
    : tBase(Image, REFERENCE)
    , m_dDX(1.0)
    , m_dDY(1.0)
    , m_dThickness(1.0)
    , m_dPosition(0.0)
    , m_Index(0)
    , m_eOrientation(PLANE_XY)
{
}


CSlice::~CSlice()
{
}


CSlice& CSlice::resize(tSize XSize, tSize YSize, tSize Margin)
{
    // Create image
    tBase::resize(XSize, YSize, Margin);

    // Initialize the slice parameters
    m_dThickness = 1.0;
    m_dPosition = 0.0;
    m_Index = 0;
    m_eOrientation = PLANE_XY;

    return *this;
}


CSlice& CSlice::resize(const CSize2i& Size, tSize Margin)
{
    // Create image
    tBase::resize(Size, Margin);

    // Initialize the slice parameters
    m_dThickness = 1.0;
    m_dPosition = 0.0;
    m_Index = 0;
    m_eOrientation = PLANE_XY;

    return *this;
}


CSlice& CSlice::copy(const CSlice& Slice, tSize Margin)
{
    // Copy the image data
    tBase::copy(Slice, Margin);

    // Slice properties
    copyProps(Slice);

    return *this;
}


CSlice& CSlice::copy(const tBase& Image, tSize Margin)
{
    // Copy the image data
    tBase::copy(Image, Margin);

    return *this;
}


CSlice& CSlice::makeRef(const CSlice& Slice)
{
    // Make reference to the image data
    tBase::makeRef(Slice);

    // Slice properties
    copyProps(Slice);

    return *this;
}


CSlice& CSlice::makeRef(const tBase& Image)
{
    // Make reference to the image data
    tBase::makeRef(Image);

    return *this;
}


CSlice& CSlice::operator =(const CSlice& Slice)
{
    *(dynamic_cast<tBase *>(this)) = dynamic_cast<const tBase&>(Slice);

    copyProps(Slice);

    return *this;
}


CSlice& CSlice::copyProps(const CSlice& Slice)
{
    m_dDX = Slice.m_dDX;
    m_dDY = Slice.m_dDY;
    m_dThickness = Slice.m_dThickness;
    m_dPosition = Slice.m_dPosition;
    m_Index = Slice.m_Index;
    m_eOrientation = Slice.m_eOrientation;

    return *this;
}


} // namespace img
} // namespace vpl

