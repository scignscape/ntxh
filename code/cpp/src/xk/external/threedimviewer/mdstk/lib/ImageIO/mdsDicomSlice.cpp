//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 *          Premysl Krsek, krsek@fit.vutbr.cz   \n
 * Date:    2003/12/15                          \n
 *
 * $Id: mdsDicomSlice.cpp 2094 2012-02-16 01:54:45Z spanel $
 *
 * Description:
 * - Manipulation with DICOM files.
 */

#include <MDSTk/ImageIO/mdsDicomSlice.h>
#include <MDSTk/Math/mdsBase.h>
#include <MDSTk/System/mdsSystemTypes.h>

// STL
#include <cstring>
#include <cmath>


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Implementation of the class mds::img::CDicomSlice.
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

//==============================================================================

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

//==============================================================================

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

//==============================================================================

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

//==============================================================================

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

//==============================================================================

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

//==============================================================================

CDicomSlice::CDicomSlice(const CDicomSlice& Slice)
    : CSlice(Slice)
    , m_sPatientName(Slice.m_sPatientName)
    , m_sPatientId(Slice.m_sPatientId)
    , m_sPatientBirthday(Slice.m_sPatientBirthday)
    , m_sPatientSex(Slice.m_sPatientSex)
    , m_sPatientDescription(Slice.m_sPatientDescription)    
    , m_sStudyUid(Slice.m_sStudyUid)
    , m_sStudyId(Slice.m_sStudyId)        
    , m_sStudyDate(Slice.m_sStudyDate)
    , m_sStudyDescription(Slice.m_sStudyDescription)  
    , m_sSeriesUid(Slice.m_sSeriesUid)
    , m_iSeriesNumber(Slice.m_iSeriesNumber)
    , m_sModality(Slice.m_sModality)
    , m_sSeriesDate(Slice.m_sSeriesDate)
    , m_sSeriesTime(Slice.m_sSeriesTime)
    , m_sSeriesDescription(Slice.m_sSeriesDescription)
    , m_iSliceNumber(Slice.m_iSliceNumber)
    , m_iWindowCenter(Slice.m_iWindowCenter)
    , m_iWindowWidth(Slice.m_iWindowWidth)
    , m_sPatientPosition(Slice.m_sPatientPosition)
    , m_bExplicitTransfer(Slice.m_bExplicitTransfer)
    , m_uPixelRepresentation(Slice.m_uPixelRepresentation)
    , m_ImagePosition(Slice.m_ImagePosition)
    , m_ImageOrientationX(Slice.m_ImageOrientationX)
    , m_ImageOrientationY(Slice.m_ImageOrientationY)
    , m_sSliceFileName(Slice.m_sSliceFileName)
    , m_sImageType(Slice.m_sImageType)
    , m_sScanOptions(Slice.m_sScanOptions)
{
}

//==============================================================================

CDicomSlice::CDicomSlice(const CDicomSlice& Slice, EMakeRef)
    : CSlice(Slice, REFERENCE)
    , m_sPatientName(Slice.m_sPatientName)
    , m_sPatientId(Slice.m_sPatientId)
    , m_sPatientBirthday(Slice.m_sPatientBirthday)
    , m_sPatientSex(Slice.m_sPatientSex)
    , m_sPatientDescription(Slice.m_sPatientDescription)        
    , m_sStudyUid(Slice.m_sStudyUid)
    , m_sStudyId(Slice.m_sStudyId)    
    , m_sStudyDate(Slice.m_sStudyDate)
    , m_sStudyDescription(Slice.m_sStudyDescription) 
    , m_sSeriesUid(Slice.m_sSeriesUid)
    , m_iSeriesNumber(Slice.m_iSeriesNumber)
    , m_sModality(Slice.m_sModality) 
    , m_sSeriesDate(Slice.m_sSeriesDate)
    , m_sSeriesTime(Slice.m_sSeriesTime)
    , m_sSeriesDescription(Slice.m_sSeriesDescription)
    , m_iSliceNumber(Slice.m_iSliceNumber)
    , m_iWindowCenter(Slice.m_iWindowCenter)
    , m_iWindowWidth(Slice.m_iWindowWidth)
    , m_sPatientPosition(Slice.m_sPatientPosition)
    , m_bExplicitTransfer(Slice.m_bExplicitTransfer)
    , m_uPixelRepresentation(Slice.m_uPixelRepresentation)
    , m_ImagePosition(Slice.m_ImagePosition)
    , m_ImageOrientationX(Slice.m_ImageOrientationX)
    , m_ImageOrientationY(Slice.m_ImageOrientationY)
    , m_sSliceFileName(Slice.m_sSliceFileName)
    , m_sImageType(Slice.m_sImageType)
    , m_sScanOptions(Slice.m_sScanOptions)
{
}

//==============================================================================

CDicomSlice::~CDicomSlice()
{
}

//==============================================================================

CDicomSlice& CDicomSlice::operator =(const CDImage& Image)
{
    *((CDImage *)this) = Image;

    return *this;
}

//==============================================================================

CDicomSlice& CDicomSlice::operator =(const CSlice& Slice)
{
    *((CSlice *)this) = Slice;

    return *this;
}

//==============================================================================

CDicomSlice& CDicomSlice::operator =(const CDicomSlice& Slice)
{
    *((CSlice *)this) = (const CSlice&)Slice;

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

    return *this;
}

//==============================================================================
/*
 * IMplementation of the class mds::CDicomSlice
 * - loading DICOM slices
 */
bool CDicomSlice::loadDicom(mds::mod::CChannel *pChannel, bool load_image_data)
{
    MDS_CHECK(pChannel, return false);

    // Read and check DICOM header
    if ( ! readDicomHeader(pChannel) )
        return false;

    // Read DICOM data
    return ( readDicom(pChannel, load_image_data) );
}


//==============================================================================
/*
 * DICOM data manipulation functions
 */
bool CDicomSlice::readDicom(mds::mod::CChannel *pChannel, bool load_image_data)
{
    // Helper variables
    char pcType[5], *pcTemp, *pcTemp1, *pcElemData;
    mds::sys::tUInt16 usGroup, usElem, usWord16;
    unsigned long ulOffset, ulLength;
    double dValue;
    mds::sys::tUInt32 uXSize = 0, uYSize = 0;

    CPoint3D zero_point(0, 0, 0);
    CVector3D normal_image, position_vector;

    // slice parameters initialization 
    m_dPosition = 0.0;
    m_dDX = 1.0;
    m_dDY = 1.0;
    m_dThickness = 1.0;

    m_iSeriesNumber    = 0;
    m_iSliceNumber = 0;
    m_iWindowCenter = 1000;
    m_iWindowWidth = 1000;
    m_uPixelRepresentation = 0;

    m_sPatientName.erase();
    m_sPatientId.erase();
    m_sPatientBirthday.erase();
    m_sPatientSex.erase();
    m_sPatientDescription.erase();
    m_sStudyUid.erase();
    m_sStudyId.erase();    
    m_sStudyDate.erase();
    m_sStudyDescription.erase();
    m_sModality.erase();
    m_sSeriesUid.erase();
    m_sSeriesDate.erase();
    m_sSeriesTime.erase();
    m_sPatientPosition.erase();
    m_sSliceFileName.erase();
    m_sImageType.erase();
    m_sScanOptions.erase();

    m_ImageOrientationX.setXYZ(1, 0, 0);
    m_ImageOrientationY.setXYZ(0, 1, 0);

    //! @todo Erase image data ?!
    
    // Pixel value normalization
    double dSlope = 1.0, dIntercept = 0.0;
    
    // Pixel padding value
    mds::sys::tUInt16 usPaddingValue = 0;
    
    // DICOM elements reading cycle 
    do {
        // tag reading
        if( !readElementTag(pChannel, &usGroup, &usElem) )
            return false;

        // value byte data length reading 
        if( !readValueLength(pChannel, pcType, m_bExplicitTransfer, &ulLength, &ulOffset) )
            return false;

        // tag zero length test 
        if( ulLength == 0UL )
            continue;

        // tag non defined length, reading by SQ value representation
        if( ulLength == 0xFFFFFFFF )
        {
            // reading by SQ value representation 
            if( !readSQDataElement(pChannel) )
                return false;
            continue;
        }

        // element data reading 
        pcElemData = readValueData(pChannel, ulLength);
        if( !pcElemData )
            return false;

        // element data processing 
        switch( usGroup )
        {
        case 0x8:
            switch( usElem )
            {
            case 0x12:                    // create date
                // text save
                m_sSeriesDate = pcElemData;
                break;
            case 0x13:                    // create time
                // text save
                m_sSeriesTime = pcElemData;
                break;
            case 0x20:                    // study datum 
                // text save
                m_sStudyDate = pcElemData;
                break;
            case 0x21:                    // series datum
                // text save
                m_sSeriesDate = pcElemData;
                break;
            case 0x31:                    // series time
                // text save
                m_sSeriesTime = pcElemData;
                break;
            case 0x60:                    // slice modality
                // text save
                m_sModality = pcElemData;
                break;
            case 0x1030:                  // study note
                // text save
                m_sStudyDescription = pcElemData;
                break;
            case 0x103E:                  // series note
                // text save
                m_sSeriesDescription = pcElemData;
                break;
            }
            break;

        case 0x10:
            switch( usElem )
            {
            case 0x10:                    // patient name
                // text save
                m_sPatientName = pcElemData;
                break;
            case 0x20:                    // patient ID
                // text save
                m_sPatientId = pcElemData;
                break;
            case 0x30:                    // patient birthday
                // text save
                m_sPatientBirthday = pcElemData;
                break;
            case 0x40:                    // patient sex
                // text save
                m_sPatientSex = pcElemData;
                break;
            case 0x4000:                  // patient note
                // text save
                m_sPatientDescription = pcElemData;
                break;
            }
            break;

        case 0x18:
            switch( usElem )
            {
            case 0x50:                      // slice thickness
                // take number from text
                sscanf(pcElemData, "%lf", &m_dThickness);
                break;
            case 0x5100:                    // patient position
                // text save
                m_sPatientPosition = pcElemData;
                break;
            }
            break;

        case 0x20:
            switch( usElem )
            {
            case 0xD:                     // study UID
                // text save
                m_sStudyUid = pcElemData;
                break;
            case 0xE:                     // series UID
                // text save
                m_sSeriesUid = pcElemData;
                break;
            case 0x10:                    // study ID
                // take number form text 
                m_sStudyId = pcElemData;
                break;
            case 0x11:                    // series number
                // take number form text 
                sscanf(pcElemData, "%d", &m_iSeriesNumber);
                break;
            case 0x13:                    // slice number
                // take number form text 
                sscanf(pcElemData, "%d", &m_iSliceNumber);
                m_iIndex = m_iSliceNumber;
                break;
            case 0x32:                    // patient slice position 
                // take coordinate Z form text 
                dValue = 0;
                pcTemp = strrchr(pcElemData, '\\');
                sscanf((pcTemp+1), "%lf", &dValue);
                m_ImagePosition.setZ((tCoordinate)dValue);
                // remove last slash
                *pcTemp = 0;
                pcTemp1 = pcTemp;
                // take coordinate Y form text
                dValue = 0;
                pcTemp = strrchr(pcElemData, '\\');
                *pcTemp1 = '\\';
                sscanf((pcTemp+1), "%lf", &dValue);
                m_ImagePosition.setY((tCoordinate)dValue);
                // remove last slash
                *pcTemp = 0;
                // take coordinate X form text
                dValue = 0;
                sscanf(pcElemData, "%lf", &dValue);
                *pcTemp = '\\';
                m_ImagePosition.setX((tCoordinate)dValue);
                break;
            case 0x37:                    // patient image orientation 
                // take coordinate Z of slice Y orientation form text 
                dValue = 0;
                pcTemp = strrchr(pcElemData, '\\');
                sscanf((pcTemp+1), "%lf", &dValue);
                m_ImageOrientationY.setZ((tCoordinate)dValue);
                // remove last slash
                *pcTemp = 0;
                pcTemp1 = pcTemp;
                // take coordinate Y of slice Y orientation form text 
                dValue = 0;
                pcTemp = strrchr(pcElemData, '\\');
                *pcTemp1 = '\\';
                sscanf((pcTemp+1), "%lf", &dValue);
                m_ImageOrientationY.setY((tCoordinate)dValue);
                // remove last slash
                *pcTemp = 0;
                pcTemp1 = pcTemp;
                // take coordinate X of slice Y orientation form text 
                dValue = 0;
                pcTemp = strrchr(pcElemData, '\\');
                *pcTemp1 = '\\';
                sscanf((pcTemp+1), "%lf", &dValue);
                m_ImageOrientationY.setX((tCoordinate)dValue);
                // remove last slash
                *pcTemp = 0;
                pcTemp1 = pcTemp;
                // take coordinate Z of slice X orientation form text 
                dValue = 0;
                pcTemp = strrchr(pcElemData, '\\');
                *pcTemp1 = '\\';
                sscanf((pcTemp+1), "%lf", &dValue);
                m_ImageOrientationX.setZ((tCoordinate)dValue);
                // remove last slash
                *pcTemp = 0;
                pcTemp1 = pcTemp;
                // take coordinate Y of slice X orientation form text 
                dValue = 0;
                pcTemp = strrchr(pcElemData, '\\');
                *pcTemp1 = '\\';
                sscanf((pcTemp+1), "%lf", &dValue);
                m_ImageOrientationX.setY((tCoordinate)dValue);
                // remove last slash
                *pcTemp = 0;
                pcTemp1 = pcTemp;
                // take coordinate X of slice X orientation form text 
                dValue = 0;
                sscanf(pcElemData, "%lf", &dValue);
                *pcTemp1 = '\\';
                m_ImageOrientationX.setX((tCoordinate)dValue);

                // slice plane normal calculation and normalization 
                normal_image.vectorProduct(m_ImageOrientationX, m_ImageOrientationY);
                normal_image.normalize();
                // slice position vector calculation. length and normalization
                position_vector. create(zero_point, m_ImagePosition);
                m_dPosition = position_vector.getLength();
                position_vector.normalize();

                // test modality MR
                if ( (strncmp(m_sModality.c_str(), "MR", 2) == 0) || (strncmp(m_sModality.c_str(), "mr", 2) == 0) )
                {
                    // tilt deleting for MR data
                    m_ImageOrientationX.setXYZ(1, 0, 0);
                    m_ImageOrientationY.setXYZ(0, 1, 0);
                    // slice position calculation, form 3D position of slice plane
                    m_dPosition = normal_image.dotProduct(normal_image, position_vector) * m_dPosition;
                }
                else
                    m_dPosition = m_ImagePosition.getZ();
                break;
/*            case 0x1041:                    // slice position 
                // take number form text 
                sscanf(pcElemData, "%lf", &m_dPosition);
               break;*/
            }
            break;

        case 0x28:
            switch( usElem )
            {
            case 0x02:                    // samples per pixel
                memcpy(&usWord16, pcElemData, 2);
                if( usWord16 != 1 )
                {
                    delete pcElemData;
                    return false;
                }
                break;
            case 0x10:                    // slice matrix size, in axis Y
                // take number
                memcpy(&usWord16, pcElemData, 2);
                // save value
                uYSize = usWord16;
                break;
            case 0x11:                    // slice matrix size, in axis X
                // take number
                memcpy(&usWord16, pcElemData, 2);
                // save value
                uXSize = usWord16;
                break;
            case 0x30:                    // slice pixel size
                // take number
                pcTemp = strchr(pcElemData, '\\');
                // remove slash between values 
                *pcTemp = 0;
                sscanf(pcElemData, "%lf", &m_dDX);
                // take number
                sscanf((pcTemp+1), "%lf", &m_dDY);
                // put slash between values 
                *pcTemp = '\\';
                break;
            case 0x103:
                m_uPixelRepresentation = 0;
                memcpy(&usWord16, pcElemData, 2);
                // save value
                m_uPixelRepresentation = usWord16;
                break;
            case 0x1050:                    // density window centr
                dValue = 0;
                // take number form text
                sscanf(pcElemData, "%lf", &dValue);
                // save value
                m_iWindowCenter = (int)floor(dValue);
                break;
            case 0x1051:                    // density window width
                dValue = 0;
                // take number form text
                sscanf(pcElemData, "%lf", &dValue);
                // save value
                m_iWindowWidth = (int)floor(dValue);
                break;
            case 0x1052:                    // rescale intercept
                dIntercept = 0.0;
                sscanf(pcElemData, "%lf", &dIntercept);
                break;
            case 0x1053:                    // rescale slope
                dSlope = 1.0;
                sscanf(pcElemData, "%lf", &dSlope);
                break;
            case 0x120:                     // pixel padding value
                memcpy(&usWord16, pcElemData, 2);
                usPaddingValue = usWord16;
                break;
            }
            break;

        case 0x7fe0:
            if( usElem == 0x10 )                // slice pixel data 
            {
                // slice image size test
                MDS_ASSERT((uXSize * uYSize * sizeof(unsigned short)) == ulLength);

                // slice image data memory allocation
                CDImage::create(tSize(uXSize), tSize(uYSize), m_Margin);

                // load slice image data test
                if (load_image_data)
                {
                    // Minimal and maximal allowed density pixel value
                    CDImage::tPixel Min = mds::img::CPixelTraits<CDImage::tPixel>::getPixelMin();
                    double dMax = mds::img::CPixelTraits<CDImage::tPixel>::getPixelMax();
                    double dMin = Min;

                    CDImage::fillEntire(Min);

                    // slice image data copy
                    for( tSize j = 0; j < m_Size.y(); ++j )
                    {
                        if( m_uPixelRepresentation == 1 )
                        {
                            mds::sys::tInt16 *pData = ((mds::sys::tInt16 *)pcElemData) + j * m_Size.x();
                            for( tSize i = 0; i < m_Size.x(); ++i )
                            {
                                dValue = dSlope * double(*(pData + i)) + dIntercept;
                                mds::math::limit(dValue, dMin, dMax);
                                set(i, j, CDImage::tPixel(dValue));
                            }
                        }
                        else
                        {
                            mds::sys::tUInt16 *pData = ((mds::sys::tUInt16 *)pcElemData) + j * m_Size.x();
                            for( tSize i = 0; i < m_Size.x(); ++i )
                            {
                                dValue = dSlope * double(*(pData + i)) + dIntercept;
                                mds::math::limit(dValue, dMin, dMax);
                                set(i, j, CDImage::tPixel(dValue));
                            }
                        }
                    }
                }

                // deletion of loaded data memory
                delete pcElemData;

                // end of the function
                return true;
            }
            break;

        } // switch( usGroup )

        // deletion of loaded data memory
        delete pcElemData;

    } while( true );
}

//==============================================================================

bool CDicomSlice::readDicomHeader(mds::mod::CChannel *pChannel)
{
    // Helper variables
    char pcPrefix[5], pcType[5], *pcElemData;
    unsigned short usGroup, usElem;
    unsigned long ulOffset, ulHeaderLimit, ulLength;

    // jump over preamble
    char pcDump[128];
    if( pChannel->read(pcDump, 128) != 128 )
        return false;

    // take prefix value 
    if( pChannel->read(pcPrefix, 4)!= 4 )
        return false;

    // pcPrefix test
    if( strncmp(pcPrefix, "DICM", 4) )
        return false;

    // take first tag value
    if( !readElementTag(pChannel, &usGroup, &usElem) )
        return false;

    // test code of first element
    if( usGroup != 2 || usElem != 0 )
        return false;

    // take value length of first element
    if( ! readValueLength(pChannel, pcType, true, &ulLength, &ulOffset) )
        return false;

    // element value length test
    if( ulLength != 4UL )
        return false;

    // take header byte number
    if( pChannel->read((char *)&ulHeaderLimit, 4) != 4 )
        return false;

    // index to header end initialization
    ulOffset = 0UL;

    // header data elements loading cycle
    do {
        // take tag value
        if( !readElementTag(pChannel, &usGroup, &usElem) )
            return false;
        ulOffset += 4UL;

        // header tag group test
        if( usGroup != 2 )
            return false;

        // take element value length
        if( !readValueLength(pChannel, pcType, true, &ulLength, &ulOffset) )
            return false;

        // element value length zero test 
        if( ulLength == 0UL )
            continue;

        // take element data value
        pcElemData = readValueData(pChannel, ulLength);
        if( !pcElemData )
            return false;
        ulOffset += ulLength;

        // element data value processing
        switch( usElem )
        {
            case 0x10:                        // Transfer syntax UID
                // transfer syntax evaluation
                if( !strncmp(pcElemData, "1.2.840.10008.1.2", ulLength) )
                    m_bExplicitTransfer = false;    // implicit transfer syntax
                else if( !strncmp(pcElemData, "1.2.840.10008.1.2.1", ulLength) )
                    m_bExplicitTransfer = true;    // explicit transfer syntax
                else if( !strncmp(pcElemData, "9.8.260.90002.9.8.9", ulLength) )
                    m_bExplicitTransfer = true;    // segmented data (proprietary, P. Krsek)
                else                               // unknown transfer syntax
                    return false;
    
                break;
        }

        // loaded data deleting
        delete pcElemData;

    } while( ulOffset < ulHeaderLimit );

    // DICOM header loaded successfully
    return true;
}

//==============================================================================

bool CDicomSlice::readValueLength(mds::mod::CChannel *pChannel, char *pcType, bool bExplicit, unsigned long *ulLength, unsigned long *ulOffset)
{
    MDS_ASSERT(pcType);
    MDS_ASSERT(pcType);
    MDS_ASSERT(ulLength);
    MDS_ASSERT(ulOffset);

    *ulLength = 0UL;                // loaded element data length value

    // implicit transfer syntax test
    if( !bExplicit )
    {
        // take data length value 
        if( pChannel->read((char *)ulLength, 4) != 4 )
            return false;
        *ulOffset += 4UL;
    }
    else
    {
        // take value representation
        if( pChannel->read(pcType, 2) != 2 )
            return false;
        *ulOffset += 2UL;

        // take additional 2 byte or data length value loading
        if( pChannel->read((char *)ulLength, 2) != 2 )
            return false;
        *ulOffset += 2UL;

        // value representation text lower case conversion
        pcType[0] = (char)tolower(pcType[0]);
        pcType[1] = (char)tolower(pcType[1]);

        // value representation evaluation
        if( !strncmp(pcType,"ob",2) || !strncmp(pcType,"ow",2) || !strncmp(pcType,"sq",2) || !strncmp(pcType,"un",2) )
        {
            // take data length value
            if( pChannel->read((char *)ulLength, 4) != 4 )
                return false;
            *ulOffset += 4UL;
        }
    }

    // the function end, OK
    return true;
}

//==============================================================================

char * CDicomSlice::readValueData(mds::mod::CChannel *pChannel, unsigned long ulLength)
{
    // Allocate memory
    char *pcData = new char[ulLength + 1];
    MDS_ASSERT(pcData);

    // Read pcData
    if( pChannel->read(pcData, (int)ulLength) != (int)ulLength )
    {
        delete[] pcData;
        return NULL;
    }

    pcData[ulLength] = '\0';
    return pcData;
}

//==============================================================================

bool CDicomSlice::readElementTag(mds::mod::CChannel *pChannel, unsigned short *usGroup, unsigned short *usElem )
{
    // Read an element tag
    if( pChannel->read((char *)usGroup, 2) != 2 )
        return false;

    if( pChannel->read((char *)usElem, 2) != 2 )
        return false;

    return true;
}

//==============================================================================

bool CDicomSlice::readSQDataElement(mds::mod::CChannel *pChannel)
{
    char              pcType[5], *pcElemData;
    unsigned short    usGroup, usElem;
    unsigned long     ulOffset, ulLength;

    // endless loading cycle
    while( true )
    {
        // tag loading
        if( !readElementTag(pChannel, &usGroup, &usElem) )
            return false;

        // take element data value
        if( !readValueLength(pChannel, pcType, false, &ulLength, &ulOffset) )
            return false;

        // tag group value test
        if( usGroup != 0xFFFE )
            return false;

        // tag element value test
        if( usElem == 0xE000 )
        {
            // element data value length test
            if( ulLength != 0xFFFFFFFF )
            {
                // element data value zero length test 
                if( ulLength != 0 )
                {
                    // element data loading
                    pcElemData = readValueData(pChannel, ulLength);
                    if( !pcElemData )
                        return false;
                    // element data memory deleting
                    delete pcElemData;
                }
            }
            else
            {
                // endless loading cycle for included elements
                while( true )
                {
                    // tag loading
                    if( ! readElementTag(pChannel, &usGroup, &usElem))
                        return false;

                    // take element data value
                    if( ! readValueLength(pChannel, pcType, m_bExplicitTransfer, &ulLength, &ulOffset))
                        return false;

                    // sequence end tag test
                    if( (usGroup == 0xFFFE) && (usElem == 0xE00D) )
                        break;

                    // element data value length test
                    if( ulLength != 0xFFFFFFFF )
                    {
                        // element data value zero length test
                        if( ulLength != 0 )
                        {
                            // element data loading
                            pcElemData = readValueData(pChannel, ulLength);
                            if( !pcElemData )
                                return false;
                            // element data memory deleting
                            delete pcElemData;
                        }
                    }
                    else
                    {
                        // recursion of SQ sequence loading
                        if( !readSQDataElement(pChannel) )
                            return false;
                    }
                }
            }
        }
        else if( usElem == 0xE0DD )
            break;
        else
            return false;
    }

    return true;
}


} // namespace img
} // namespace mds
