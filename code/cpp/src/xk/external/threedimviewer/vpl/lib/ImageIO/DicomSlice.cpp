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
 *          Premysl Krsek, krsek@fit.vutbr.cz   \n
 * Date:    2003/12/15                          \n
 *
 * Description:
 * - Manipulation with DICOM files.
 */

#include <VPL/ImageIO/DicomSlice.h>

#include <VPL/Math/Base.h>
#include <VPL/System/SystemTypes.h>

// STL
#include <cstring>
#include <cmath>


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Implementation of the class vpl::img::CDicomSlice.
 */
CDicomSlice::CDicomSlice()
    : m_iSeriesNumber(0)
    , m_iSliceNumber(0)
    , m_iWindowCenter(1000)
    , m_iWindowWidth(1000)
    , m_bExplicitTransfer(false)
    , m_uPixelRepresentation(0)
    , m_ImagePosition(0, 0, 0)
    , m_ImageOrientationX(1, 0, 0)
    , m_ImageOrientationY(0, 1, 0)

{
}


CDicomSlice::CDicomSlice(tSize XSize,
                         tSize YSize,
                         tSize Margin
                         )
    : CSlice(XSize, YSize, Margin)
    , m_iSeriesNumber(0)
    , m_iSliceNumber(0)
    , m_iWindowCenter(1000)
    , m_iWindowWidth(1000)
    , m_bExplicitTransfer(false)
    , m_uPixelRepresentation(0)
    , m_ImagePosition(0, 0, 0)
    , m_ImageOrientationX(1, 0, 0)
    , m_ImageOrientationY(0, 1, 0)

{
}


CDicomSlice::CDicomSlice(const CDImage& Image)
    : CSlice(Image)
    , m_iSeriesNumber(0)
    , m_iSliceNumber(0)
    , m_iWindowCenter(1000)
    , m_iWindowWidth(1000)
    , m_bExplicitTransfer(false)
    , m_uPixelRepresentation(0)
    , m_ImagePosition(0, 0, 0)
    , m_ImageOrientationX(1, 0, 0)
    , m_ImageOrientationY(0, 1, 0)

{
}


CDicomSlice::CDicomSlice(const CDImage& Image, EMakeRef)
    : CSlice(Image, REFERENCE)
    , m_iSeriesNumber(0)
    , m_iSliceNumber(0)
    , m_iWindowCenter(1000)
    , m_iWindowWidth(1000)
    , m_bExplicitTransfer(false)
    , m_uPixelRepresentation(0)
    , m_ImagePosition(0, 0, 0)
    , m_ImageOrientationX(1, 0, 0)
    , m_ImageOrientationY(0, 1, 0)

{
}


CDicomSlice::CDicomSlice(const CSlice& Slice)
    : CSlice(Slice)
    , m_iSeriesNumber(0)
    , m_iSliceNumber(0)
    , m_iWindowCenter(1000)
    , m_iWindowWidth(1000)
    , m_bExplicitTransfer(false)
    , m_uPixelRepresentation(0)
    , m_ImagePosition(0, 0, 0)
    , m_ImageOrientationX(1, 0, 0)
    , m_ImageOrientationY(0, 1, 0)

{
}


CDicomSlice::CDicomSlice(const CSlice& Slice, EMakeRef)
    : CSlice(Slice, REFERENCE)
    , m_iSeriesNumber(0)
    , m_iSliceNumber(0)
    , m_iWindowCenter(1000)
    , m_iWindowWidth(1000)
    , m_bExplicitTransfer(false)
    , m_uPixelRepresentation(0)
    , m_ImagePosition(0, 0, 0)
    , m_ImageOrientationX(1, 0, 0)
    , m_ImageOrientationY(0, 1, 0)

{
}


CDicomSlice::CDicomSlice(const CDicomSlice& Slice)
    : CSlice(Slice)
{
    copyProps(Slice);
}


CDicomSlice::CDicomSlice(const CDicomSlice& Slice, EMakeRef)
    : CSlice(Slice, REFERENCE)
{
    copyProps(Slice);
}


CDicomSlice::~CDicomSlice()
{
}


CDicomSlice& CDicomSlice::operator =(const CDImage& Image)
{
    *(dynamic_cast<CDImage *>(this)) = Image;

    return *this;
}


CDicomSlice& CDicomSlice::operator =(const CSlice& Slice)
{
    *(dynamic_cast<CSlice *>(this)) = Slice;

    return *this;
}


CDicomSlice& CDicomSlice::operator =(const CDicomSlice& Slice)
{
    *(dynamic_cast<CSlice *>(this)) = dynamic_cast<const CSlice&>(Slice);

    copyProps(Slice);

    return *this;
}


CDicomSlice& CDicomSlice::copyProps(const CDicomSlice& Slice)
{
    CSlice::copyProps(Slice);

    m_sPatientName = Slice.m_sPatientName;
    m_sPatientId = Slice.m_sPatientId;
    m_sPatientBirthday = Slice.m_sPatientBirthday;
    m_sPatientSex = Slice.m_sPatientSex;
    m_sPatientDescription = Slice.m_sPatientDescription;    
    m_sStudyUid = Slice.m_sStudyUid;
    m_sStudyId = Slice.m_sStudyId;    
    m_sStudyDate = Slice.m_sStudyDate;
    m_sStudyDescription = Slice.m_sStudyDescription;
    m_sModality = Slice.m_sModality;
    m_iSeriesNumber = Slice.m_iSeriesNumber;
    m_sSeriesUid = Slice.m_sSeriesUid;
    m_sSeriesDate = Slice.m_sSeriesDate;
    m_sSeriesTime = Slice.m_sSeriesTime;
    m_sSeriesDescription = Slice.m_sSeriesDescription;
    m_iSliceNumber = Slice.m_iSliceNumber;
    m_iWindowCenter = Slice.m_iWindowCenter;
    m_iWindowWidth = Slice.m_iWindowWidth;
    m_sPatientPosition = Slice.m_sPatientPosition;
    m_bExplicitTransfer = Slice.m_bExplicitTransfer;
    m_uPixelRepresentation = Slice.m_uPixelRepresentation;
    m_ImagePosition = Slice.m_ImagePosition;
    m_ImageOrientationX = Slice.m_ImageOrientationX;
    m_ImageOrientationY = Slice.m_ImageOrientationY;
    m_sSliceFileName = Slice.m_sSliceFileName;
    m_sImageType = Slice.m_sImageType;
    m_sScanOptions = Slice.m_sScanOptions;
    m_sManufacturer = Slice.m_sManufacturer;
    m_sModelName = Slice.m_sModelName;
    m_sMediaStorage = Slice.m_sMediaStorage;

    return *this;
}


} // namespace img
} // namespace vpl
