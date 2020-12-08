//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 *          Premysl Krsek, krsek@fit.vutbr.cz   \n
 * Date:    2003/12/15                          \n
 *
 * $Id: mdsDicomSlice.h 1964 2011-01-23 21:38:39Z spanel $
 *
 * Description:
 * - Manipulation with DICOM files.
 */

#ifndef MDS_DICOMSLICE_H
#define MDS_DICOMSLICE_H

#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsVector3.h>
#include <MDSTk/Module/mdsChannel.h>

#include "mdsImageIOExport.h"

// STL
#include <string>


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Class encapsulating DICOM file operations.
 * - Only CT and MR modalities are supported.
 */
class MDS_IMAGEIO_EXPORT CDicomSlice : public CSlice
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CDicomSlice);

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

    //! Image type.
    std::string m_sImageType;

    //! Scan options (AXIAL, etc.).
    std::string m_sScanOptions;

public:
    //! Default constructor.
    CDicomSlice();

    //! Constructor.
    CDicomSlice(tSize XSize, tSize YSize, tSize Margin = CSlice::DEFAULT_MARGIN);

    //! Copy constructor.
    //! - Makes a new copy of the image data.
    CDicomSlice(const CDImage& Image);

    //! Copy constructor.
    //! - Makes a reference only.
    CDicomSlice(const CDImage& Image, EMakeRef);

    //! Copy constructor.
    //! - Makes a new copy of the image data.
    CDicomSlice(const CSlice& Slice);

    //! Copy constructor.
    //! - Makes a reference only.
    CDicomSlice(const CSlice& Slice, EMakeRef);

    //! Copy constructor.
    //! - Makes a new copy of the image data.
    CDicomSlice(const CDicomSlice& Slice);

    //! Copy constructor.
    //! - Makes a reference only.
    CDicomSlice(const CDicomSlice& Slice, EMakeRef);

    //! Destructor.
    virtual ~CDicomSlice();

    //! Image assignment operator.
    virtual CDicomSlice& operator =(const CDImage& Image);

    //! Slice assignment operator.
    virtual CDicomSlice& operator =(const CSlice& Slice);

    //! Slice assignment operator.
    virtual CDicomSlice& operator =(const CDicomSlice& Slice);


    //! Loads DICOM slice from a given channel.
    //! - Returns false on failure.
    bool loadDicom(mds::mod::CChannel *pChannel, bool load_image_data = true);

private:
    //! Reads and checks DICOM header.
    //! - Based on P. Krsek's code.
    bool readDicomHeader(mds::mod::CChannel *pChannel);

    //! Reads DICOM slice data.
    bool readDicom(mds::mod::CChannel *pChannel, bool load_image_data);

    //! Reads DICOM data element with VR = SQ, jump across, do not take data
    bool readSQDataElement(mds::mod::CChannel *pChannel);

    //! Gets element tag group and element.
    bool readElementTag(mds::mod::CChannel *pChannel,
                        unsigned short *pusGroup,
                        unsigned short *pusElem
                        );

    //! Reads the element tag value length.
    bool readValueLength(mds::mod::CChannel *pChannel,
                         char *pcType,
                         bool bExplicit,
                         unsigned long *pulLength,
                         unsigned long *pulOffset
                         );

    //! Reads the element data.
    char *readValueData(mds::mod::CChannel *pChannel, unsigned long ulLength);
};


//==============================================================================
/*
 * Smart pointer to DICOM slice.
 */
typedef CDicomSlice::tSmartPtr  CDicomSlicePtr;


} // namespace img
} // namespace mds

#endif // MDS_DICOMSLICE_H

