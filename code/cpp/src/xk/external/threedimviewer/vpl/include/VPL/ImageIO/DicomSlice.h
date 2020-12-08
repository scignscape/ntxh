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

#ifndef VPL_DICOMSLICE_H
#define VPL_DICOMSLICE_H

#include <VPL/Image/Slice.h>
#include <VPL/Image/Vector3.h>
#include <VPL/Module/Channel.h>

#include <VPL/ImageIO/ImageIOExport.h>

// STL
#include <string>

namespace vpl
{
namespace img
{
//==============================================================================
/*!
 * Class encapsulating DICOM file operations.
 * - Only CT and MR modalities are supported for now!
 * - Provides the ability to load non-compressed DICOM images.
 */
class VPL_IMAGEIO_EXPORT CDicomSlice : public CSlice
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CDicomSlice);

    VPL_DECLARE_EXCEPTION(CDicomSliceExeption, "Not implemented.");

public:
    //! Patient name.
    std::string m_sPatientName;

    //! Patient Id.
    std::string m_sPatientId;

    //! Patient birthday.
    std::string m_sPatientBirthday;

    //! Patient sex.
    std::string m_sPatientSex;

    //! Patient description.
    std::string m_sPatientDescription;

    //! Study uid.
    std::string m_sStudyUid;

    //! Study id.
    std::string m_sStudyId;

    //! Study date.
    std::string m_sStudyDate;

    //! Study description.
    std::string m_sStudyDescription;

    //! Series Uid.
    std::string m_sSeriesUid;

    //! Series number.
    int m_iSeriesNumber;

    //! Modality.
    std::string m_sModality;

    //! Series date.
    std::string m_sSeriesDate;

    //! Series time.
    std::string m_sSeriesTime;

    //! Series description.
    std::string m_sSeriesDescription;

    //! Slice number.
    int m_iSliceNumber;

    //! Density window center position.
    int m_iWindowCenter;

    //! Density window width.
    int m_iWindowWidth;

    //! Patient position.
    std::string m_sPatientPosition;

    //! Explicit transfer syntax.
    bool m_bExplicitTransfer;

    //! Pixel value representation.
    unsigned int m_uPixelRepresentation;

    //! Slice base point position.
    CPoint3D m_ImagePosition;

    //! Slice X axis (first row) direction.
    CVector3D m_ImageOrientationX;

    //! Slice Y axis (first column) direction.
    CVector3D m_ImageOrientationY;

    //! Slice file name
    std::string m_sSliceFileName;

    //! Image type. - Pixel Data Characteristics
    // see:
    // http://dicom.nema.org/MEDICAL/DICOM/2015a/output/chtml/part03/sect_C.7.6.html
    // C.7.6.1.1.2 Image Type 
    std::string m_sImageType; 

    std::string m_sImageType_PatientExaminationCharacteristics;
    std::string m_sImageType_ModalitySpecificCharacteristics;
    std::string m_sImageType_ImplementationSpecificIdentifiers;

    //! Scan options (AXIAL, etc.).
    std::string m_sScanOptions;

    //! Manufacturer.
    std::string m_sManufacturer;

    //! Manufacturer’s model name.
    std::string m_sModelName;

    //! Media Storage SOP Class UID.
    std::string m_sMediaStorage;
public:
    //! Default constructor.
    CDicomSlice();

    //! Constructor allocates underlying image data.
    CDicomSlice(tSize XSize, tSize YSize, tSize Margin = CSlice::DEFAULT_MARGIN);

    //! Constructor makes a copy of the image data.
    explicit CDicomSlice(const CDImage& Image);

    //! Constructor creates reference to a given image.
    //! - No image data are copied.
    explicit CDicomSlice(const CDImage& Image, EMakeRef);

    //! Constructor makes a copy of the slice data.
    explicit CDicomSlice(const CSlice& Slice);

    //! Constructor makes reference to a given slice.
    //! - All DICOM properties are copied.
    explicit CDicomSlice(const CSlice& Slice, EMakeRef);

    //! Copy constructor.
    //! - Makes a new copy of a given dicom slice.
    CDicomSlice(const CDicomSlice& Slice);

    //! Constructor makes reference to image data of a given slice.
    //! - All DICOM properties are copied.
    CDicomSlice(const CDicomSlice& Slice, EMakeRef);

    //! Destructor.
    virtual ~CDicomSlice();

    //! Image assignment operator.
    CDicomSlice& operator =(const CDImage& Image);

    //! Slice assignment operator.
    CDicomSlice& operator =(const CSlice& Slice);

    //! Dicom slice assignment operator.
    CDicomSlice& operator =(const CDicomSlice& Slice);

    //! Copies DICOM properties from one slice to another.
    CDicomSlice& copyProps(const CDicomSlice& Slice);

};


//==============================================================================
/*
 * Smart pointer to DICOM slice.
 */
typedef CDicomSlice::tSmartPtr  CDicomSlicePtr;


} // namespace img
} // namespace vpl

#endif // VPL_DICOMSLICE_H

