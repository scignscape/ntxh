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

#ifndef VPL_DICOMSLICELOADERGDCM_H
#define VPL_DICOMSLICELOADERGDCM_H

//VPL
#include <VPL/Base/Setup.h>
#include <VPL/ImageIO/DicomSliceLoader.h>
#include <VPL/ImageIO/ImageIOExport.h>
#include <VPL/Base/Data.h>

//VPL must be build with GDCM to access this class
#if defined( VPL_USE_GDCM )

//GDCM
#include <gdcmImageReader.h>
#include <gdcmAttribute.h>

#include <VPL/ImageIO/DefTagGDCM.h>

namespace vpl
{
namespace img
{
//==============================================================================
/*!
 * Loads DICOM image using GDCM toolkit.
 */
class VPL_IMAGEIO_EXPORT CDicomSliceLoaderGDCM : public CDicomSliceLoader
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CDicomSliceLoaderGDCM);
    
    //! Default constructor.
    CDicomSliceLoaderGDCM();

    //! Default destructor.
    ~CDicomSliceLoaderGDCM();

    //! Loads data from DICOM file, including image data, patient information, etc. into previously specified slice 
    //! Calls readFile() if it wasn't called before.
    virtual bool loadDicom(std::string fileName, CDicomSlice &dicomSlice, bool load_image_data = true) override;

    //! Reads Dicom File and tags. This function must be called before any other actions
    bool readFile(std::string fileName);

    //! Overloaded function. Filename must be specified using setFileName(), before using this function
    bool readFile();  

    //! Loads multiframe dicom file, into vector of slices
    virtual bool loadMultiframeDicom(std::string fileName, tSlices &slices, bool load_image_data = true) override;

    //! Loads only one frame from multiframe dicom file into given slice
    virtual bool loadMultiframeDicom(std::string fileName, CDicomSlice &dicomSlice, unsigned int index, bool load_image_data = true) override;

    //! Loads only image data, ignores information from tags
    bool loadDicomImageOnly(std::string fileName, CDicomSlice &dicomSlice);

    //! This method is called when gdcm Image Reader fails to load the file
    //! There are 2 reasons it might fail:
    //!  1. it's not a Dicom file
    //!  2. the file does not contain an image
    //! Sometimes gdcm Image Reader fails even if the file contains image data, for example if the Media Storage SOP Class UID is private
    //! This method check whether there are som image data or not, and tries to load them
    bool tryToLoadBuggyFile(std::string fileName);

    //! Reads specified tag from DICOM file
    //! -Returns value as string
    virtual std::string readTag(unsigned int groupNum, unsigned int elemNum) override;
    std::string readTag(gdcm::Tag tag) const;

    //! Returns pointer to gdcm Image Reader
    const gdcm::ImageReader& getGDCMReader() const { return m_gdcmReader; }

    //! Returns number of dimensions. Multiframe Dicom Files have 3 dimensions. On failure returns 0.
    int getNumberOfDimensions() const;

    //! Returns number of frames. On failure returns 0.
    unsigned int getNumberOfFrames() const;

    //! Checks if file contains multiple frames
    bool isMultiframe();

    //! Fils the vector vec with image positions of every slice
    tImagePositions & getImagePositions(){ return m_ImagePositions; }

    //! Sets file name
    void setFileName(std::string fileName){ m_sFileName = fileName; }

    //! Reads binary attribute and returns it as gdcm ArrayType 
    template<uint16_t Group, uint16_t Element>
    typename gdcm::Attribute<Group, Element>::ArrayType getAttributeValue();

    //! Reads binary attribute
    template<uint16_t Group, uint16_t Element>
    gdcm::Attribute<Group, Element> getAttribute(); 

    //! Pre-loads given file, ignores image data and loads only neccessary tags
    bool preLoadFile(std::string fileName);

private:    
    //! Instance of GDCM Image Reader
    gdcm::ImageReader m_gdcmReader;

    //! Image dimensions
    unsigned int m_dimX;
    unsigned int m_dimY;
    unsigned int m_dimZ;

    //! Intercept value
    double m_intercept;

    //! Slope value
    double m_slope;

    //! Indicates, that the file has been already loaded using gdcm gdcmReader::Read()
    bool m_fileLoaded;

    //! Indicates, that the file has been already preloaded using gdcm gdcmReader::ReadUpToTag()
    bool m_filePreloaded;

    std::string m_sFileName;

    //! Number of dimensions
    int m_iNumOfDimensions;
    
    //! Number of frames, applies for multiframe files
    unsigned int m_iNumOfFrames;

    //! Vector of all image positions
    tImagePositions m_ImagePositions;

    //! buffer with raw image data
    vpl::base::CData<char> m_buffer;

private:
    //! Reads and converts raw image values and writes them into given slice
    //! Returns pointer to raw char buffer, where reading ended
    template<typename T>
    char* readRawImageDataIntoSlice(T buffer, CDicomSlice &dicomSlice);
    
    //! Loads image from DICOM file into CDicomSlice
    bool loadImage(CDicomSlice &dicomSlice);

    //! Processes raw image data at given position from DICOM file and writes it into CDicomSlice
    bool readImage(CDicomSlice &dicomSlice, char* buffer, unsigned int index);
    
    //! Loads information about patient, study, image properties, etc.
    bool loadInfo(CDicomSlice &dicomSlice);

    //! Resets all variables to default value
    void resetInfo(CDicomSlice &dicomSlice);
    
    //! Trims slashes from given element, wich contains Image Position, so it can be pushed to 
    //! vector of doubles
    bool trimSlashesAndPush(gdcm::DataElement& el);

    //! Loads information from tags, wich are neccessary for this class
    //! e.g. Rescale slope/intercept, number of frames, dimensions...
    bool fillPrivateInfo(std::string fileName);
  
    //! Method used to get image positions if they are in nested tag
    bool parseNestedPosition();

    //! Parse Image Type tag (0008,0008)
    //! This tag consistd of 4 values, 2 are compulsory and 2 are optional:
    //! 1) Pixel Data Characteristics (compulsory): ORIGINAL/DERIVED
    //! 2) Patient Examination Characteristics (compulsory): PRIMARY/SECONDARY 
    //! 3) Modality Specific Characteristics (optional)
    //! 4) Implementation specific identifiers (optional)
    //! see: dicom specification: C.7.6.1.1.2 (http://dicom.nema.org/MEDICAL/Dicom/2015c/output/chtml/part03/sect_C.7.6.html#sect_C.7.6.1.1.2)
    void parseImageType(CDicomSlice &dicomSlice);

    //! Splits string into tokens separated by delimiter
    void splitStringToTokens(std::vector<std::string> &tokens, std::string strToSplit, std::string delimiter);
    
    //! Loads image position(s) into vector m_ImagePositions
    bool loadImagePositions();

    //! Loads DICOM file into dicomSlice, filename specified to be defined before calling this function
    //! Calls readFile() if it wasn't called before.
    bool loadDicom(CDicomSlice &dimcomSlice, bool load_image_data = true);

    //! Internal load of multiframe dicom, loads all slices, filename needs to be specified before calling this function
    bool loadMultiframeDicom(tSlices &slices, bool load_image_data = true);

    //! Internal load, loads only one frame from multiframe dicom file into given slice, , filename needs to be specified before calling this function
    bool loadMultiframeDicom(CDicomSlice &dicomSlice, unsigned int index, bool load_image_data = true);
};

template <typename T>
char* CDicomSliceLoaderGDCM::readRawImageDataIntoSlice(T buffer, CDicomSlice & dicomSlice)
{
    double dMax = vpl::img::CPixelTraits<CDImage::tPixel>::getPixelMax();
    double dMin = vpl::img::CPixelTraits<CDImage::tPixel>::getPixelMin();


    for (unsigned int j = 0; j < m_dimY; ++j)
    {
        for (unsigned int i = 0; i < m_dimX; ++i)
        {
            double dVal = m_slope * (*buffer) + m_intercept;
            vpl::math::limit(dVal, dMin, dMax);
            dicomSlice.set(i, j, CDImage::tPixel(dVal));

            ++buffer;
        }
    }
    return (char*)buffer;
}

template <uint16_t Group, uint16_t Element>
typename gdcm::Attribute<Group, Element>::ArrayType CDicomSliceLoaderGDCM::getAttributeValue()
{
    gdcm::Attribute<Group, Element> at;
    gdcm::File file = m_gdcmReader.GetFile();
    gdcm::DataSet &ds = m_gdcmReader.GetFile().GetDataSet();

    if (ds.IsEmpty() || !ds.FindDataElement(gdcm::Tag(Group, Element)))
    {
        return typename gdcm::Attribute<Group, Element>::ArrayType();
    }
    else
    {
        at.Set(ds);
        return at.GetValue();
    }
}

#pragma optimize( "", off )
template <uint16_t Group, uint16_t Element>
gdcm::Attribute<Group, Element> CDicomSliceLoaderGDCM::getAttribute()
{
    gdcm::Attribute<Group, Element> at;
    const gdcm::File &file = m_gdcmReader.GetFile();
    const gdcm::DataSet &ds = file.GetDataSet();
    if (ds.IsEmpty() || !ds.FindDataElement(gdcm::Tag(Group, Element)))
        return gdcm::Attribute<Group, Element>();
    else
    {
        at.Set(ds);
        return at;
    }
    
}

//==============================================================================
/*
 * Smart pointer to DICOM slice.
 */
typedef CDicomSliceLoaderGDCM::tSmartPtr  CDicomSliceLoaderGDCMPtr;

} // namespace img
} // namespace vpl

#endif // VPL_USE_GDCM

#endif // VPL_DICOMSLICELOADERGDCM_H
