//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/14                          \n
 *
 * $Id: mdsSlice.cpp 2091 2012-02-14 11:26:36Z spanel $
 *
 * Description:
 * - Density slice.
 */

#include <MDSTk/Image/mdsSlice.h>


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Implementation of the class mds::img::CSlice.
 */
CSlice::CSlice()
    : CDImage(0, 0, DEFAULT_MARGIN)
    , m_dDX(1.0)
    , m_dDY(1.0)
    , m_dThickness(1.0)
    , m_dPosition(0.0)
    , m_iIndex(0)
    , m_eOrientation(PLANE_XY)
{
}


CSlice::CSlice(tSize XSize, tSize YSize, tSize Margin)
    : CDImage(XSize, YSize, Margin)
    , m_dDX(1.0)
    , m_dDY(1.0)
    , m_dThickness(1.0)
    , m_dPosition(0.0)
    , m_iIndex(0)
    , m_eOrientation(PLANE_XY)
{
}


CSlice::CSlice(const CSlice& Slice)
    : CDImage(Slice)
    , m_dDX(Slice.m_dDX)
    , m_dDY(Slice.m_dDY)
    , m_dThickness(Slice.m_dThickness)
    , m_dPosition(Slice.m_dPosition)
    , m_iIndex(Slice.m_iIndex)
    , m_eOrientation(Slice.m_eOrientation)
{
}


CSlice::CSlice(const CSlice& Slice, EMakeRef)
    : CDImage(Slice, REFERENCE)
    , m_dDX(Slice.m_dDX)
    , m_dDY(Slice.m_dDY)
    , m_dThickness(Slice.m_dThickness)
    , m_dPosition(Slice.m_dPosition)
    , m_iIndex(Slice.m_iIndex)
    , m_eOrientation(Slice.m_eOrientation)
{
}


CSlice::CSlice(const CDImage& Image)
    : CDImage(Image)
    , m_dDX(1.0)
    , m_dDY(1.0)
    , m_dThickness(1.0)
    , m_dPosition(0.0)
    , m_iIndex(0)
    , m_eOrientation(PLANE_XY)
{
}


CSlice::CSlice(const CDImage& Image, EMakeRef)
    : CDImage(Image, REFERENCE)
    , m_dDX(1.0)
    , m_dDY(1.0)
    , m_dThickness(1.0)
    , m_dPosition(0.0)
    , m_iIndex(0)
    , m_eOrientation(PLANE_XY)
{
}


CSlice::~CSlice()
{
}


CSlice& CSlice::create(tSize XSize, tSize YSize, tSize Margin)
{
    // Create image
    CDImage::create(XSize, YSize, Margin);

    // Initialize the slice parameters
    m_dThickness = 1.0;
    m_dPosition = 0.0;
    m_iIndex = 0;
    m_eOrientation = PLANE_XY;

    return *this;
}


CSlice& CSlice::create(const CSlice& Slice)
{
    // Copy the image data
    CDImage::create(Slice);

    // Slice properties
    m_dDX = Slice.m_dDX;
    m_dDY = Slice.m_dDY;
    m_dThickness = Slice.m_dThickness;
    m_dPosition = Slice.m_dPosition;
    m_iIndex = Slice.m_iIndex;
    m_eOrientation = Slice.m_eOrientation;

    return *this;
}


CSlice& CSlice::create(const CSlice& Slice, EMakeRef)
{
    // Make reference to the image data
    CDImage::create(Slice, REFERENCE);

    // Slice properties
    m_dDX = Slice.m_dDX;
    m_dDY = Slice.m_dDY;
    m_dThickness = Slice.m_dThickness;
    m_dPosition = Slice.m_dPosition;
    m_iIndex = Slice.m_iIndex;
    m_eOrientation = Slice.m_eOrientation;

    return *this;
}


CSlice& CSlice::operator =(const CSlice& Slice)
{
    *((CDImage *)this) = (const CDImage&)Slice;

    m_dDX = Slice.m_dDX;
    m_dDY = Slice.m_dDY;
    m_dThickness = Slice.m_dThickness;
    m_dPosition = Slice.m_dPosition;
    m_iIndex = Slice.m_iIndex;
    m_eOrientation = Slice.m_eOrientation;

    return *this;
}


} // namespace img
} // namespace mds

