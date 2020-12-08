//==============================================================================
/* This file is part of
*
* VPL - Voxel Processing Library
* Copyright 2014 3Dim Laboratory s.r.o.
* All rights reserved.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

//VPL
#include <VPL/ImageIO/DicomSliceLoaderVPL.h>
#include <VPL/ImageIO/DicomSlice.h>

//STL
#include <cstdio>
#include <VPL/Image/Point3.h>
#include <VPL/Image/Vector3.h>


namespace vpl
{
namespace img
{
bool CDicomSliceLoaderVPL::loadDicom(std::string fileName, CDicomSlice& dicomSlice, bool load_image_data)
{
    bool ok = false;
    mod::CFileChannel pChannel(mod::CH_IN, fileName);
    // Create the input file channel
    // Open the input file
    if (!pChannel.connect())
    {
        VPL_LOG_ERROR('<' << "> Cannot open input file: " << fileName << std::endl);
        return false;
    }
   
    ok =  loadDicom(&pChannel, dicomSlice, load_image_data);

    // Close the channel
    pChannel.disconnect();

    return ok;
}

std::string CDicomSliceLoaderVPL::readTag(unsigned groupNum, unsigned elemNum)
{
    throw CDicomSliceLoaderNotImplemeted();
    return "";
}

bool CDicomSliceLoaderVPL::loadMultiframeDicom(std::string fileName, tSlices& slices, bool load_image_data)
{
    throw CDicomSliceLoaderNotImplemeted();
    return false;
}

bool CDicomSliceLoaderVPL::loadMultiframeDicom(std::string fileName, CDicomSlice& dicomSlice, unsigned index, bool load_image_data)
{
    throw CDicomSliceLoaderNotImplemeted();
    return false;
}

bool CDicomSliceLoaderVPL::loadDicom(vpl::mod::CChannel *pChannel, CDicomSlice &dicomSlice, bool load_image_data)
{
    VPL_CHECK(pChannel, return false);
    if (!readDicomHeader(pChannel, dicomSlice))
        return false;
    // Read DICOM data
    return readDicom(pChannel, dicomSlice, load_image_data);
}

    bool CDicomSliceLoaderVPL::readDicomHeader(vpl::mod::CChannel *pChannel,CDicomSlice &dicomSlice)
{
    // Helper variables
    char pcPrefix[5], pcType[5], *pcElemData;
    unsigned short usGroup, usElem;
    unsigned long ulOffset, ulHeaderLimit, ulLength;
    // jump over preamble
    char pcDump[128];
    if (pChannel->read(pcDump, 128) != 128)
        return false;

    // take prefix value 
    if (pChannel->read(pcPrefix, 4) != 4)
        return false;

    // pcPrefix test
    if (strncmp(pcPrefix, "DICM", 4))
        return false;

    // take first tag value
    if (!readElementTag(pChannel, &usGroup, &usElem))
        return false;

    // test code of first element
    if (usGroup != 2 || usElem != 0)
        return false;

    // take value length of first element
    if (!readValueLength(pChannel, pcType, true, &ulLength, &ulOffset))
        return false;

    // element value length test
    if (ulLength != 4UL)
        return false;

    // take header byte number
    if (pChannel->read((char *)&ulHeaderLimit, 4) != 4)
        return false;

    // index to header end initialization
    ulOffset = 0UL;

    // header data elements loading cycle
    do {
        // take tag value
        if (!readElementTag(pChannel, &usGroup, &usElem))
            return false;
        ulOffset += 4UL;

        // header tag group test
        if (usGroup != 2)
            return false;

        // take element value length
        if (!readValueLength(pChannel, pcType, true, &ulLength, &ulOffset))
            return false;

        // element value length zero test 
        if (ulLength == 0UL)
            continue;

        // take element data value
        pcElemData = readValueData(pChannel, ulLength);
        if (!pcElemData)
            return false;
        ulOffset += ulLength;

        // element data value processing
        switch (usElem)
        {
        case 0x10:                        // Transfer syntax UID
            // transfer syntax evaluation
            if (!strncmp(pcElemData, "1.2.840.10008.1.2", ulLength))
                dicomSlice.m_bExplicitTransfer = false;    // implicit transfer syntax
            else if (!strncmp(pcElemData, "1.2.840.10008.1.2.1", ulLength))
                dicomSlice.m_bExplicitTransfer = true;    // explicit transfer syntax
            else if (!strncmp(pcElemData, "9.8.260.90002.9.8.9", ulLength))
                dicomSlice.m_bExplicitTransfer = true;    // segmented data (proprietary, P. Krsek)
            else                               // unknown transfer syntax
                return false;

            break;
        }

        // loaded data deleting
        delete pcElemData;

    } while (ulOffset < ulHeaderLimit);

    // DICOM header loaded successfully
    return true;
}

bool CDicomSliceLoaderVPL::readDicom(vpl::mod::CChannel* pChannel, CDicomSlice &dicomSlice, bool load_image_data)
{
    // Helper variables
    char pcType[5], *pcTemp, *pcTemp1, *pcElemData;
    vpl::sys::tUInt16 usGroup, usElem, usWord16;
    unsigned long ulOffset, ulLength;
    double dValue;
    vpl::sys::tUInt32 uXSize = 0, uYSize = 0;

    CPoint3D zero_point(0, 0, 0);
    CVector3D normal_image, position_vector;

    std::string tmpStr;
    double dx = 0;
    double dy = 0;

    // slice parameters initialization 
    dicomSlice.setPosition(0.0);
    dicomSlice.setPixel(1.0, 1.0);
    dicomSlice.setThickness(1.0);

    dicomSlice.m_iSeriesNumber = 0;
    dicomSlice.m_iSliceNumber = 0;
    dicomSlice.m_iWindowCenter = 1000;
    dicomSlice.m_iWindowWidth = 1000;
    dicomSlice.m_uPixelRepresentation = 0;

    dicomSlice.m_sPatientName.erase();
    dicomSlice.m_sPatientId.erase();
    dicomSlice.m_sPatientBirthday.erase();
    dicomSlice.m_sPatientSex.erase();
    dicomSlice.m_sPatientDescription.erase();
    dicomSlice.m_sStudyUid.erase();
    dicomSlice.m_sStudyId.erase();
    dicomSlice.m_sStudyDate.erase();
    dicomSlice.m_sStudyDescription.erase();
    dicomSlice.m_sModality.erase();
    dicomSlice.m_sSeriesUid.erase();
    dicomSlice.m_sSeriesDate.erase();
    dicomSlice.m_sSeriesTime.erase();
    dicomSlice.m_sPatientPosition.erase();
    dicomSlice.m_sSliceFileName.erase();
    dicomSlice.m_sImageType.erase();
    dicomSlice.m_sScanOptions.erase();
    dicomSlice.m_sManufacturer.erase();
    dicomSlice.m_sModelName.erase();

    dicomSlice.m_ImageOrientationX.setXYZ(1, 0, 0);
    dicomSlice.m_ImageOrientationY.setXYZ(0, 1, 0);

    //! @todo Erase image data ?!

    // Pixel value normalization
    double dSlope = 1.0, dIntercept = 0.0;

    // Pixel padding value
    vpl::sys::tUInt16 usPaddingValue = 0;

    // DICOM elements reading cycle 
    do {
        // tag reading
        if (!readElementTag(pChannel, &usGroup, &usElem))
            return false;

        // value byte data length reading 
        if (!readValueLength(pChannel, pcType, dicomSlice.m_bExplicitTransfer, &ulLength, &ulOffset))
            return false;

        // tag zero length test 
        if (ulLength == 0UL)
            continue;

        // tag non defined length, reading by SQ value representation
        if (ulLength == 0xFFFFFFFF)
        {
            // reading by SQ value representation 
            if (!readSQDataElement(pChannel, dicomSlice))
                return false;
            continue;
        }

        // element data reading 
        pcElemData = readValueData(pChannel, ulLength);
        if (!pcElemData)
            return false;

        // element data processing 
        switch (usGroup)
        {
        case 0x8:
            switch (usElem)
            {
            case 0x12:                    // create date
                // text save
                dicomSlice.m_sSeriesDate = pcElemData;
                break;
            case 0x13:                    // create time
                // text save
                dicomSlice.m_sSeriesTime = pcElemData;
                break;
            case 0x20:                    // study datum 
                // text save
                dicomSlice.m_sStudyDate = pcElemData;
                break;
            case 0x21:                    // series datum
                // text save
                dicomSlice.m_sSeriesDate = pcElemData;
                break;
            case 0x31:                    // series time
                // text save
                dicomSlice.m_sSeriesTime = pcElemData;
                break;
            case 0x60:                    // slice modality
                // text save
                dicomSlice.m_sModality = pcElemData;
                break;
            case 0x70:                    // manufacturer
                // text save
                dicomSlice.m_sManufacturer = pcElemData;
                break;
            case 0x1090:                  // model name
                // text save
                dicomSlice.m_sModelName = pcElemData;
                break;
            case 0x1030:                  // study note
                // text save
                dicomSlice.m_sStudyDescription = pcElemData;
                break;
            case 0x103E:                  // series note
                // text save
                dicomSlice.m_sSeriesDescription = pcElemData;
                break;
            }
            break;

        case 0x10:
            switch (usElem)
            {
            case 0x10:                    // patient name
                // text save
                dicomSlice.m_sPatientName = pcElemData;
                break;
            case 0x20:                    // patient ID
                // text save
                dicomSlice.m_sPatientId = pcElemData;
                break;
            case 0x30:                    // patient birthday
                // text save
                dicomSlice.m_sPatientBirthday = pcElemData;
                break;
            case 0x40:                    // patient sex
                // text save
                dicomSlice.m_sPatientSex = pcElemData;
                break;
            case 0x4000:                  // patient note
                // text save
                dicomSlice.m_sPatientDescription = pcElemData;
                break;
            }
            break;

        case 0x18:
            switch (usElem)
            {
            case 0x50:                      // slice thickness
                // take number from text
                sscanf(pcElemData, "%lf", &dValue);
                dicomSlice.setThickness(dValue);
                break;
            case 0x5100:                    // patient position
                // text save
                dicomSlice.m_sPatientPosition = pcElemData;
                break;
            }
            break;

        case 0x20:
            switch (usElem)
            {
            case 0xD:                     // study UID
                // text save
                dicomSlice.m_sStudyUid = pcElemData;
                break;
            case 0xE:                     // series UID
                // text save
                dicomSlice.m_sSeriesUid = pcElemData;
                break;
            case 0x10:                    // study ID
                // take number form text 
                dicomSlice.m_sStudyId = pcElemData;
                break;
            case 0x11:                    // series number
                // take number form text 
                sscanf(pcElemData, "%d", &dicomSlice.m_iSeriesNumber);
                break;
            case 0x13:                    // slice number
                // take number form text 
                sscanf(pcElemData, "%d", &dicomSlice.m_iSliceNumber);
                dicomSlice.setIndex(dicomSlice.m_iSliceNumber);
                break;
            case 0x32:                    // patient slice position 
                // take coordinate Z form text 
                dValue = 0;
                pcTemp = strrchr(pcElemData, '\\');
                sscanf((pcTemp + 1), "%lf", &dValue);
                dicomSlice.m_ImagePosition.setZ((tCoordinate)dValue);
                // remove last slash
                *pcTemp = 0;
                pcTemp1 = pcTemp;
                // take coordinate Y form text
                dValue = 0;
                pcTemp = strrchr(pcElemData, '\\');
                *pcTemp1 = '\\';
                sscanf((pcTemp + 1), "%lf", &dValue);
                dicomSlice.m_ImagePosition.setY((tCoordinate)dValue);
                // remove last slash
                *pcTemp = 0;
                // take coordinate X form text
                dValue = 0;
                sscanf(pcElemData, "%lf", &dValue);
                *pcTemp = '\\';
                dicomSlice.m_ImagePosition.setX((tCoordinate)dValue);
                break;
            case 0x37:                    // patient image orientation 
                // take coordinate Z of slice Y orientation form text 
                dValue = 0;
                pcTemp = strrchr(pcElemData, '\\');
                sscanf((pcTemp + 1), "%lf", &dValue);
                dicomSlice.m_ImageOrientationY.setZ((tCoordinate)dValue);
                // remove last slash
                *pcTemp = 0;
                pcTemp1 = pcTemp;
                // take coordinate Y of slice Y orientation form text 
                dValue = 0;
                pcTemp = strrchr(pcElemData, '\\');
                *pcTemp1 = '\\';
                sscanf((pcTemp + 1), "%lf", &dValue);
                dicomSlice.m_ImageOrientationY.setY((tCoordinate)dValue);
                // remove last slash
                *pcTemp = 0;
                pcTemp1 = pcTemp;
                // take coordinate X of slice Y orientation form text 
                dValue = 0;
                pcTemp = strrchr(pcElemData, '\\');
                *pcTemp1 = '\\';
                sscanf((pcTemp + 1), "%lf", &dValue);
                dicomSlice.m_ImageOrientationY.setX((tCoordinate)dValue);
                // remove last slash
                *pcTemp = 0;
                pcTemp1 = pcTemp;
                // take coordinate Z of slice X orientation form text 
                dValue = 0;
                pcTemp = strrchr(pcElemData, '\\');
                *pcTemp1 = '\\';
                sscanf((pcTemp + 1), "%lf", &dValue);
                dicomSlice.m_ImageOrientationX.setZ((tCoordinate)dValue);
                // remove last slash
                *pcTemp = 0;
                pcTemp1 = pcTemp;
                // take coordinate Y of slice X orientation form text 
                dValue = 0;
                pcTemp = strrchr(pcElemData, '\\');
                *pcTemp1 = '\\';
                sscanf((pcTemp + 1), "%lf", &dValue);
                dicomSlice.m_ImageOrientationX.setY((tCoordinate)dValue);
                // remove last slash
                *pcTemp = 0;
                pcTemp1 = pcTemp;
                // take coordinate X of slice X orientation form text 
                dValue = 0;
                sscanf(pcElemData, "%lf", &dValue);
                *pcTemp1 = '\\';
                dicomSlice.m_ImageOrientationX.setX((tCoordinate)dValue);

                // slice plane normal calculation and normalization 
                normal_image.vectorProduct(dicomSlice.m_ImageOrientationX, dicomSlice.m_ImageOrientationY);
                normal_image.normalize();
                // slice position vector calculation. length and normalization
                position_vector.create(zero_point, dicomSlice.m_ImagePosition);
                dicomSlice.setPosition(position_vector.getLength());
                position_vector.normalize();

                // test modality MR
                if ((strncmp(dicomSlice.m_sModality.c_str(), "MR", 2) == 0) || (strncmp(dicomSlice.m_sModality.c_str(), "mr", 2) == 0))
                {
                    // tilt deleting for MR data
                    dicomSlice.m_ImageOrientationX.setXYZ(1, 0, 0);
                    dicomSlice.m_ImageOrientationY.setXYZ(0, 1, 0);
                    // slice position calculation, form 3D position of slice plane
                    dicomSlice.setPosition(normal_image.dotProduct(normal_image, position_vector) *  dicomSlice.getPosition());
                }
                else
                    dicomSlice.setPosition(dicomSlice.m_ImagePosition.getZ());
                break;
                /*            case 0x1041:                    // slice position
                // take number form text
                sscanf(pcElemData, "%lf", &m_dPosition);
                break;*/
            }
            break;

        case 0x28:
            switch (usElem)
            {
            case 0x02:                    // samples per pixel
                memcpy(&usWord16, pcElemData, 2);
                if (usWord16 != 1)
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

                sscanf(pcElemData, "%lf", &dx);
                // take number
                sscanf((pcTemp + 1), "%lf", &dy);
                dicomSlice.setPixel(dx, dy);
                // put slash between values 
                *pcTemp = '\\';
                break;
            case 0x103:
                dicomSlice.m_uPixelRepresentation = 0;
                memcpy(&usWord16, pcElemData, 2);
                // save value
                dicomSlice.m_uPixelRepresentation = usWord16;
                break;
            case 0x1050:                    // density window centr
                dValue = 0;
                // take number form text
                sscanf(pcElemData, "%lf", &dValue);
                // save value
                dicomSlice.m_iWindowCenter = (int)floor(dValue);
                break;
            case 0x1051:                    // density window width
                dValue = 0;
                // take number form text
                sscanf(pcElemData, "%lf", &dValue);
                // save value
                dicomSlice.m_iWindowWidth = (int)floor(dValue);
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
            if (usElem == 0x10)                // slice pixel data 
            {
                // slice image size test
                VPL_ASSERT((uXSize * uYSize * sizeof(unsigned short)) == ulLength);

                // slice image data memory allocation
                dicomSlice.CDImage::resize(tSize(uXSize), tSize(uYSize), dicomSlice.getMargin());

                // load slice image data test
                if (load_image_data)
                {
                    // Minimal and maximal allowed density pixel value
                    CDImage::tPixel Min = vpl::img::CPixelTraits<CDImage::tPixel>::getPixelMin();
                    double dMax = vpl::img::CPixelTraits<CDImage::tPixel>::getPixelMax();
                    double dMin = Min;

                    dicomSlice.CDImage::fillEntire(Min);

                    // slice image data copy
                    for (tSize j = 0; j < dicomSlice.getSize().y(); ++j)
                    {
                        if (dicomSlice.m_uPixelRepresentation == 1)
                        {
                            vpl::sys::tInt16 *pData = ((vpl::sys::tInt16 *)pcElemData) + j * dicomSlice.getSize().x();
                            for (tSize i = 0; i < dicomSlice.getSize().x(); ++i)
                            {
                                dValue = dSlope * double(*(pData + i)) + dIntercept;
                                vpl::math::limit(dValue, dMin, dMax);
                                dicomSlice.set(i, j, CDImage::tPixel(dValue));
                            }
                        }
                        else
                        {
                            vpl::sys::tUInt16 *pData = ((vpl::sys::tUInt16 *)pcElemData) + j * dicomSlice.getSize().x();
                            for (tSize i = 0; i < dicomSlice.getSize().x(); ++i)
                            {
                                dValue = dSlope * double(*(pData + i)) + dIntercept;
                                vpl::math::limit(dValue, dMin, dMax);
                                dicomSlice.set(i, j, CDImage::tPixel(dValue));
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

    } while (true);
}

bool CDicomSliceLoaderVPL::readSQDataElement(vpl::mod::CChannel* pChannel, CDicomSlice &dicomSlice)
{
    char              pcType[5], *pcElemData;
    unsigned short    usGroup, usElem;
    unsigned long     ulOffset, ulLength;

    // endless loading cycle
    while (true)
    {
        // tag loading
        if (!readElementTag(pChannel, &usGroup, &usElem))
            return false;

        // take element data value
        if (!readValueLength(pChannel, pcType, false, &ulLength, &ulOffset))
            return false;

        // tag group value test
        if (usGroup != 0xFFFE)
            return false;

        // tag element value test
        if (usElem == 0xE000)
        {
            // element data value length test
            if (ulLength != 0xFFFFFFFF)
            {
                // element data value zero length test 
                if (ulLength != 0)
                {
                    // element data loading
                    pcElemData = readValueData(pChannel, ulLength);
                    if (!pcElemData)
                        return false;
                    // element data memory deleting
                    delete pcElemData;
                }
            }
            else
            {
                // endless loading cycle for included elements
                while (true)
                {
                    // tag loading
                    if (!readElementTag(pChannel, &usGroup, &usElem))
                        return false;

                    // take element data value
                    if (!readValueLength(pChannel, pcType, dicomSlice.m_bExplicitTransfer, &ulLength, &ulOffset))
                        return false;

                    // sequence end tag test
                    if ((usGroup == 0xFFFE) && (usElem == 0xE00D))
                        break;

                    // element data value length test
                    if (ulLength != 0xFFFFFFFF)
                    {
                        // element data value zero length test
                        if (ulLength != 0)
                        {
                            // element data loading
                            pcElemData = readValueData(pChannel, ulLength);
                            if (!pcElemData)
                                return false;
                            // element data memory deleting
                            delete pcElemData;
                        }
                    }
                    else
                    {
                        // recursion of SQ sequence loading
                        if (!readSQDataElement(pChannel, dicomSlice))
                            return false;
                    }
                }
            }
        }
        else if (usElem == 0xE0DD)
            break;
        else
            return false;
    }

    return true;
}

bool CDicomSliceLoaderVPL::readElementTag(vpl::mod::CChannel* pChannel, unsigned short* usGroup, unsigned short* usElem)
{
    // Read an element tag
    if (pChannel->read((char *)usGroup, 2) != 2)
        return false;

    if (pChannel->read((char *)usElem, 2) != 2)
        return false;

    return true;
}

bool CDicomSliceLoaderVPL::readValueLength(vpl::mod::CChannel* pChannel, char* pcType, bool bExplicit, unsigned long* ulLength, unsigned long* ulOffset)
{
    VPL_ASSERT(pcType);
    VPL_ASSERT(pcType);
    VPL_ASSERT(ulLength);
    VPL_ASSERT(ulOffset);

    *ulLength = 0UL;                // loaded element data length value

    // implicit transfer syntax test
    if (!bExplicit)
    {
        // take data length value 
        if (pChannel->read((char *)ulLength, 4) != 4)
            return false;
        *ulOffset += 4UL;
    }
    else
    {
        // take value representation
        if (pChannel->read(pcType, 2) != 2)
            return false;
        *ulOffset += 2UL;

        // take additional 2 byte or data length value loading
        if (pChannel->read((char *)ulLength, 2) != 2)
            return false;
        *ulOffset += 2UL;

        // value representation text lower case conversion
        pcType[0] = (char)tolower(pcType[0]);
        pcType[1] = (char)tolower(pcType[1]);

        // value representation evaluation
        if (!strncmp(pcType, "ob", 2) || !strncmp(pcType, "ow", 2) || !strncmp(pcType, "sq", 2) || !strncmp(pcType, "un", 2))
        {
            // take data length value
            if (pChannel->read((char *)ulLength, 4) != 4)
                return false;
            *ulOffset += 4UL;
        }
    }

    // the function end, OK
    return true;
}

char* CDicomSliceLoaderVPL::readValueData(vpl::mod::CChannel* pChannel, unsigned long ulLength)
{
    // Allocate memory
    char *pcData = new char[ulLength + 1];
    VPL_ASSERT(pcData);

    // Read pcData
    if (pChannel->read(pcData, tSize(ulLength)) != tSize(ulLength))
    {
        delete[] pcData;
        return NULL;
    }

    pcData[ulLength] = '\0';
    return pcData;
}

} // namespace img
} // namespace vpl

