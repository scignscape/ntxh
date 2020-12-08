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

#ifdef _WIN32 // Windows specific
#include <Windows.h>
#include <Wbemcli.h>
#include <comdef.h>
#pragma comment(lib, "wbemuuid.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "rpcrt4.lib")  // UuidCreate - Minimum supported OS Win 2000
#endif

#include <VPL/ImageIO/DicomSliceLoaderGDCM.h>

//VPL must be build with GDCM to access this class
#if defined( VPL_USE_GDCM )

#include <VPL/ImageIO/DicomSlice.h>

//STL
#include <cstdlib>
#include <cstdio>
#include <sys/stat.h>

namespace vpl
{
namespace img
{
CDicomSliceLoaderGDCM::CDicomSliceLoaderGDCM()
    : m_gdcmReader()
    , m_intercept(0.0)
    , m_slope(1.0)
    , m_dimX(0)
    , m_dimY(0)
    , m_dimZ(0)
    , m_fileLoaded(false)
    , m_filePreloaded(false)
    , m_sFileName("")
    , m_iNumOfFrames(0)
    , m_iNumOfDimensions(-1)
{
    m_buffer.resize(0);
    m_ImagePositions.clear();
}

CDicomSliceLoaderGDCM::~CDicomSliceLoaderGDCM()
{
}

bool CDicomSliceLoaderGDCM::loadDicom(std::string fileName, CDicomSlice &dicomSlice, bool load_image_data)
{
    //if no filename was specified, return
    if (fileName.empty())
        return false;

    // check if the file has not been already read
    if (!m_fileLoaded)
    {
        if (!readFile(fileName)) 
            return false;        
    }            
            
    if (load_image_data)
    {
        if (!loadImage(dicomSlice))
            return false;
    }
            
    resetInfo(dicomSlice);

    return loadInfo(dicomSlice);
}

bool CDicomSliceLoaderGDCM::loadDicom(CDicomSlice &dicomSlice, bool load_image_data)
{
    return loadDicom(m_sFileName, dicomSlice, load_image_data);
}

bool CDicomSliceLoaderGDCM::loadDicomImageOnly(std::string fileName, CDicomSlice &dicomSlice)
{
    // if file was not loaded, then load it
    if (!m_fileLoaded)
    {
        if (!readFile(fileName)) 
            return false;
    }                

    if (!loadImage(dicomSlice))  
        return false;
            
    return true;
}

bool CDicomSliceLoaderGDCM::loadMultiframeDicom(std::string fileName, tSlices& slices, bool load_image_data)
{
    if (!m_fileLoaded)
    {
        if (!readFile(fileName))
            return false;
    }

    return loadMultiframeDicom(slices, load_image_data);

}

bool CDicomSliceLoaderGDCM::loadMultiframeDicom(tSlices &slices, bool load_image_data)
{    
    //check if the DICOM file has been already read
    if (!m_fileLoaded)
    {   
        if(!readFile())
            return false;
    }

    // reference slice used for copying slice tags
    vpl::img::CDicomSlicePtr referenceSlice = new vpl::img::CDicomSlice;

    //loads tag infromation into reference slice
    if (!loadDicom(*referenceSlice, false))        
        return false;

    gdcm::Image &img = m_gdcmReader.GetImage();    
    if(img.IsEmpty())
        return false;

    //if the buffer wasn't filled
    if (m_buffer.getSize() == 0)
    {        
        m_buffer.resize(img.GetBufferLength());
        //copies the raw image data into buffer
        img.GetBuffer(m_buffer.getPtr());
    }

    //helper variables for thickess / z-axis position calculation
    vpl::img::CPoint3D zero_point(0, 0, 0);
    vpl::img::CVector3D normal_image;
    gdcm::PhotometricInterpretation phtIntercept = img.GetPhotometricInterpretation();
    gdcm::PixelFormat pixelFormat = img.GetPixelFormat().GetScalarType();
    
   for (unsigned int z = 0; z < m_dimZ; ++z)
   {
       vpl::img::CDicomSlicePtr spSlice = new vpl::img::CDicomSlice(*referenceSlice);
       spSlice->resize(m_dimX, m_dimY);

       if (m_ImagePositions.size() > z)
       {
           //set image position from vector of positions
           spSlice->m_ImagePosition.setX(m_ImagePositions.at(z)[0]);
           spSlice->m_ImagePosition.setY(m_ImagePositions.at(z)[1]);
           spSlice->m_ImagePosition.setZ(m_ImagePositions.at(z)[2]);

           // slice position calculation
           //Z-axis
           normal_image.vectorProduct(spSlice->m_ImageOrientationX, spSlice->m_ImageOrientationY);
           normal_image.normalize();

           vpl::img::CVector3D position_vector(zero_point, spSlice->m_ImagePosition);
           spSlice->setPosition(normal_image.dotProduct(normal_image, position_vector));
       }       

       //load image data at given position to spSlice
       if (load_image_data)
        readImage(*spSlice, m_buffer.getPtr(), z); 
        slices.push_back(spSlice);       
   }
    return true;
}

bool CDicomSliceLoaderGDCM::loadMultiframeDicom(std::string fileName, CDicomSlice& dicomSlice, unsigned index, bool load_image_data)
{
    if (!m_fileLoaded)
    {
        if (!readFile(fileName))
            return false;
    }

    return loadMultiframeDicom(dicomSlice, index, load_image_data);

}

bool CDicomSliceLoaderGDCM::loadMultiframeDicom(CDicomSlice &dicomSlice, unsigned index, bool load_image_data)
{
    //check if the DICOM file has been already read
    if (!m_fileLoaded)
    {
        if (!readFile())
            return false;
    }

    //loads tag infromation into  slice
    if (!loadDicom(dicomSlice, false))
        return false;

    //check if index is valid
    if (index > getNumberOfFrames() || index > m_ImagePositions.size())
        return false;

    gdcm::Image &img = m_gdcmReader.GetImage();
    if (img.IsEmpty())
        return false;

    //helper variables for thickess / z-axis position calculation
    vpl::img::CPoint3D zero_point(0, 0, 0);
    vpl::img::CVector3D normal_image;
    gdcm::PhotometricInterpretation phtIntercept = img.GetPhotometricInterpretation();
    gdcm::PixelFormat pixelFormat = img.GetPixelFormat().GetScalarType();

    //set image position from vector of positions
    dicomSlice.m_ImagePosition.setX(m_ImagePositions.at(index)[0]);
    dicomSlice.m_ImagePosition.setY(m_ImagePositions.at(index)[1]);
    dicomSlice.m_ImagePosition.setZ(m_ImagePositions.at(index)[2]);

    //slice position calculation
    //Z-axis
    normal_image.vectorProduct(dicomSlice.m_ImageOrientationX, dicomSlice.m_ImageOrientationY);
    normal_image.normalize();

    vpl::img::CVector3D position_vector(zero_point, dicomSlice.m_ImagePosition);
    dicomSlice.setPosition(normal_image.dotProduct(normal_image, position_vector));

    // if image data are requested
    if (load_image_data)
    {
        //if the buffer wasn't filled
        if (m_buffer.getSize() == 0)
        {
            m_buffer.resize(img.GetBufferLength());
            //copies the raw image data into buffer
            img.GetBuffer(m_buffer.getPtr());
        }
        //load image data at given position to spSlice
        readImage(dicomSlice, m_buffer.getPtr(), index);
    }
    return true;
}


bool CDicomSliceLoaderGDCM::loadInfo(CDicomSlice &dicomSlice)
{
    if (!m_fileLoaded)
        return false;

    // Helper variables
    std::string tmpString;
    CPoint3D zero_point(0, 0, 0);
    CVector3D normal_image;
 
    /*--------------------------- CDicomSlice attributes ---------------------------*/    
    dicomSlice.m_sPatientId = readTag(gdcm::Tag(VPL_GDCM_PatientID));
    dicomSlice.m_sPatientBirthday = readTag(gdcm::Tag(VPL_GDCM_PatientBirthDate));
    dicomSlice.m_sPatientSex = readTag(gdcm::Tag(VPL_GDCM_PatientSex));
    dicomSlice.m_sStudyUid = readTag(gdcm::Tag(VPL_GDCM_StudyInstanceUID));
    dicomSlice.m_sStudyId = readTag(gdcm::Tag(VPL_GDCM_StudyID));
    dicomSlice.m_sStudyDate = readTag(gdcm::Tag(VPL_GDCM_StudyDate));
    dicomSlice.m_sSeriesUid = readTag(gdcm::Tag(VPL_GDCM_SeriesInstanceUID));
    dicomSlice.m_sModality = readTag(gdcm::Tag(VPL_GDCM_Modality));
    dicomSlice.m_sSeriesDate = readTag(gdcm::Tag(VPL_GDCM_InstanceCreationDate));
    dicomSlice.m_sSeriesTime = readTag(gdcm::Tag(VPL_GDCM_InstanceCreationTime));
    dicomSlice.m_sPatientPosition = readTag(gdcm::Tag(VPL_GDCM_PatientPosition));
    dicomSlice.m_sScanOptions = readTag(gdcm::Tag(VPL_GDCM_ScanOptions));

    //This values could contain "special" characters
    dicomSlice.m_sPatientName = getAttributeValue<VPL_GDCM_PatientName>();
    dicomSlice.m_sPatientDescription = getAttributeValue<VPL_GDCM_PatientComments>();
    dicomSlice.m_sStudyDescription = getAttributeValue<VPL_GDCM_StudyDescription>();
    dicomSlice.m_sManufacturer = getAttributeValue<VPL_GDCM_Manufacturer>();
    dicomSlice.m_sModelName = getAttributeValue<VPL_GDCM_ManufacturerModelName>();
    dicomSlice.m_sSeriesDescription = getAttributeValue<VPL_GDCM_SeriesDescription>();

    const gdcm::MediaStorage &ms = m_gdcmReader.GetFile().GetHeader().GetMediaStorage();
    if (!ms.IsUndefined())
        dicomSlice.m_sMediaStorage = std::string(m_gdcmReader.GetFile().GetHeader().GetMediaStorage().GetString());
    else
    {
        //probably will not work, and m_sMediaStorage will remain empty
        dicomSlice.m_sMediaStorage = readTag(gdcm::Tag(0x0002,0x0002));
    }

    parseImageType(dicomSlice);

    dicomSlice.m_sSliceFileName = m_sFileName;

    dicomSlice.m_iSliceNumber = getAttributeValue<VPL_GDCM_InstanceNumber>();
    dicomSlice.m_iWindowCenter = getAttributeValue<VPL_GDCM_WindowCenter>();
    dicomSlice.m_iWindowWidth = getAttributeValue<VPL_GDCM_WindowWidth>();
    dicomSlice.m_iSeriesNumber = getAttributeValue<VPL_GDCM_SeriesNumber>();

    gdcm::Image &img = m_gdcmReader.GetImage();
    if (img.IsEmpty())
        return false;

    dicomSlice.m_bExplicitTransfer = img.GetTransferSyntax().IsExplicit();
    dicomSlice.m_uPixelRepresentation = img.GetPixelFormat().GetPixelRepresentation();
    // Image orientation / directional cosines
    //Returns a 6 - tuples specifying the direction cosines 
    //A default value of(1, 0, 0, 0, 1, 0) will be returned
    //when the direction cosines was not specified.
    const double *cosines = img.GetDirectionCosines();

    dicomSlice.m_ImageOrientationX.setX(cosines[0]);
    dicomSlice.m_ImageOrientationX.setY(cosines[1]);
    dicomSlice.m_ImageOrientationX.setZ(cosines[2]);

    dicomSlice.m_ImageOrientationY.setX(cosines[3]);
    dicomSlice.m_ImageOrientationY.setY(cosines[4]);
    dicomSlice.m_ImageOrientationY.setZ(cosines[5]);

    //normalization
    dicomSlice.m_ImageOrientationX.normalize();
    dicomSlice.m_ImageOrientationY.normalize();

    /*--------------------------- CSlice attributes ---------------------------*/
    //Spacing: m_dDX, m_dDY
    const double* spacings = img.GetSpacing();
    if (spacings[0] != NULL && spacings[1] != NULL)
        dicomSlice.setPixel(spacings[0], spacings[1]);

    //! fix spacing incompatibility
    if (1==dicomSlice.getDX() && 1==dicomSlice.getDY()) // 1 is default value for GetSpacing when tag was not found
    {
        gdcm::DataSet& ds = m_gdcmReader.GetFile().GetDataSet();
        if( ds.FindDataElement( gdcm::Tag(VPL_GDCM_PixelSpacing) ) ) // explicitly access Pixel spacing tag
        {
            const gdcm::DataElement& de = ds.GetDataElement( gdcm::Tag(VPL_GDCM_PixelSpacing) );
            gdcm::Attribute<VPL_GDCM_PixelSpacing> at;
            at.SetFromDataElement( de );
            double x = at.GetValue(0);
            double y = at.GetValue(1);
            if (x>0 && y>0)
                dicomSlice.setPixel(x,y);
        }
    }
    //Thickness
    dicomSlice.setThickness(getAttributeValue<VPL_GDCM_SliceThickness>());

    //m_Index / Slice index
    dicomSlice.setIndex(dicomSlice.m_iSliceNumber);
        
    // slice position calculation
    //Z-axis
    normal_image.vectorProduct(dicomSlice.m_ImageOrientationX, dicomSlice.m_ImageOrientationY);
    normal_image.normalize();

    vpl::img::CVector3D position_vector(zero_point, dicomSlice.m_ImagePosition);
    dicomSlice.setPosition(normal_image.dotProduct(normal_image, position_vector));

    return true;
}

void CDicomSliceLoaderGDCM::resetInfo(CDicomSlice &dicomSlice)
{      
    /*--------------------------- CDicomSlice attributes ---------------------------*/
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

    dicomSlice.m_iSeriesNumber = 0;
    dicomSlice.m_iSeriesNumber = 0;
    dicomSlice.m_iSliceNumber = 0;
    dicomSlice.m_iWindowCenter = 1000;
    dicomSlice.m_iWindowWidth = 1000;
    dicomSlice.m_uPixelRepresentation = 0;
    /*--------------------------- CSlice attributes ---------------------------*/
    dicomSlice.setPosition(0.0);
    dicomSlice.setPixel(1.0,1.0);            
    dicomSlice.setThickness(1.0);               
}

bool CDicomSliceLoaderGDCM::parseNestedPosition()
{
    //Example of nested structure
    /*
    (5200,9230) SQ (Sequence with undefined length)         # u/l,1 Per-frame Functional Groups Sequence
        (fffe,e000) na (Item with undefined length)
            (0020,9113) SQ (Sequence with undefined length) # u/l,1 Plane Position Sequence
                (fffe,e000) na (Item with undefined length)
                    (0020,0032) DS [0\0\80.16 ]             # 10,3 Image Position (Patient)
                (fffe,e00d)
            (fffe,e0dd)
        (fffe,e00d)
        ...
    (fffe,e00d)
    */

    gdcm::DataSet& ds = m_gdcmReader.GetFile().GetDataSet();

    // Tag (5200,9230) SQ (Sequence with undefined length) = Per-frame Functional Groups Sequence
    gdcm::Tag perFrameFunctionalGroupTag(VPL_GDCM_PerFrameFunctionalGroupsSequence);
    //Tag (0020,9113) SQ (Sequence with undefined length) = Plane Position Sequence
    gdcm::Tag planePositionSequenceTag(VPL_GDCM_PlanePositionSequence);
    //Tag (0020,0032) DS =  Image Position (Patient)
    gdcm::Tag imagePositionPatientTag(VPL_GDCM_ImagePositionPatient);

    gdcm::DataElement perFrameFunctionalGroup;

    // find the main nested sequence
    if (ds.FindDataElement(perFrameFunctionalGroupTag))
        perFrameFunctionalGroup = ds.GetDataElement(perFrameFunctionalGroupTag);
    else
        return false;

    if (perFrameFunctionalGroup.IsEmpty())
        return false;

    gdcm::SmartPointer<gdcm::SequenceOfItems> planePositionSequencePointer;
    planePositionSequencePointer = perFrameFunctionalGroup.GetValueAsSQ();

    //this should be equal to number of frames
    size_t size = planePositionSequencePointer->Items.size();

    for (int i = 1; i <= size; ++i)
    {
        const gdcm::Item &item = planePositionSequencePointer->GetItem(i);
        //this dataset should contain only one tag - Plane Position Sequence
        const gdcm::DataSet &planePositionSequenceDs = item.GetNestedDataSet();

        if (planePositionSequenceDs.FindDataElement(planePositionSequenceTag))
        {
            gdcm::DataElement imagePositionEl = planePositionSequenceDs.GetDataElement(planePositionSequenceTag);
            gdcm::SmartPointer<gdcm::SequenceOfItems> imagePositionPointer;
            imagePositionPointer = imagePositionEl.GetValueAsSQ();

            if (imagePositionPointer->Items.empty())
                continue;

            //this dataset should contain only one tag - Image Position (Patient)
            gdcm::Item imagePositionItem = imagePositionPointer->Items.at(0);
            const gdcm::DataSet &imagePositionDs = imagePositionItem.GetNestedDataSet();
            if (imagePositionDs.FindDataElement(imagePositionPatientTag))
            {
                gdcm::DataElement pos = imagePositionDs.GetDataElement(imagePositionPatientTag);
                trimSlashesAndPush(pos);
            }
        }
    }
    return true;
}

void CDicomSliceLoaderGDCM::parseImageType(CDicomSlice &dicomSlice)
{
    std::string imageType = readTag(gdcm::Tag(VPL_GDCM_ImageType));

   if (imageType.empty())
       return;

   std::vector<std::string> tokens;
   
   splitStringToTokens(tokens, imageType, "\\");

   if (tokens.size() > 0)
       dicomSlice.m_sImageType = tokens.at(0);
   if (tokens.size() > 1)
       dicomSlice.m_sImageType_PatientExaminationCharacteristics = tokens.at(1);
   if (tokens.size() > 2)
       dicomSlice.m_sImageType_ModalitySpecificCharacteristics = tokens.at(2);
   if (tokens.size() > 3)
       dicomSlice.m_sImageType_ImplementationSpecificIdentifiers = tokens.at(3);  
}

void CDicomSliceLoaderGDCM::splitStringToTokens(std::vector<std::string> &tokens, std::string strToSplit, std::string delimiter)
{
    //copy the string
    std::string s = strToSplit;
    //helper variables
    size_t pos = 0;
    std::string token;

    while ((pos = s.find(delimiter)) != std::string::npos)
    {        
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());        
    }
    //push also the what's left of the string
    tokens.push_back(s);
}

bool CDicomSliceLoaderGDCM::tryToLoadBuggyFile(std::string fileName)
{
    gdcm::Reader r;
    r.SetFileName(fileName.c_str());
    //check if the file is parseable, if so, then the ImageReader has already done the same,
    //so we can use it for reading tags
    if (r.Read())
    {
        //check if it's a media storage problem
        gdcm::MediaStorage ms;
        ms.SetFromFile(m_gdcmReader.GetFile());
        if (ms.IsUndefined())
            VPL_LOG_ERROR('<' << "DicomSliceLoaderGDCM.cpp" << "> Private media storage" << std::endl);

        if (!ms.IsUndefined())
            VPL_LOG_ERROR('<' << "DicomSliceLoaderGDCM.cpp" << "> File should not containt an image, according to Media Storage" << std::endl);

        //got to set this to true, so the method readTag is useable,
        //it's safe to do it, becuase the dataset is already accessible (previous condition)
        m_fileLoaded = true;
        gdcm::DataSet &ds = m_gdcmReader.GetFile().GetDataSet();
        //check if the dicom file contains image element
        if (ds.FindDataElement(gdcm::Tag(VPL_GDCM_PixelData)))
        {
            //get the raw image data element
            gdcm::DataElement el = ds.GetDataElement(gdcm::Tag(VPL_GDCM_PixelData));
            
            if (!el.IsEmpty())
            {
                //helper variables
                std::string tmp;

                //fill the image manually
                gdcm::Image &image = m_gdcmReader.GetImage();
                image.SetDataElement(el);
                
                //get transfer syntax
                image.SetTransferSyntax(m_gdcmReader.GetFile().GetHeader().GetDataSetTransferSyntax());
                
                m_iNumOfFrames = getAttributeValue<VPL_GDCM_NumberOfFrames>();
                //it's multiframe dicom file
                if (m_iNumOfFrames > 1)
                    image.SetNumberOfDimensions(3);
                //it's regular dicom file
                else
                    image.SetNumberOfDimensions(2);                

                //fill dimensions
                unsigned int dims[3] = {};
                //m_dx
                dims[0] = getAttributeValue<VPL_GDCM_Rows>();
                //m_dy
                dims[1] = getAttributeValue<VPL_GDCM_Columns>();
                //m_dz
                dims[2] = m_iNumOfFrames;
                image.SetDimensions(dims);

                //pixel format
                gdcm::PixelFormat pf;               

                pf.SetBitsAllocated(getAttributeValue<VPL_GDCM_BitsAllocated>());
                pf.SetBitsStored(getAttributeValue<VPL_GDCM_BitsStored>());
                pf.SetHighBit(getAttributeValue<VPL_GDCM_HighBit>());
                pf.SetPixelRepresentation(getAttributeValue<VPL_GDCM_PixelRepresentation>());

                image.SetPixelFormat(pf);

                //Photometric Interpretation
                //image.SetPhotometricInterpretation(gdcm::PhotometricInterpretation::MONOCHROME2);
                gdcm::PhotometricInterpretation pi = gdcm::PhotometricInterpretation::UNKNOWN;
                std::string photometricinterpretation_str = getAttributeValue<VPL_GDCM_PhotometricInterpretation>();
                pi = gdcm::PhotometricInterpretation::GetPIType(photometricinterpretation_str.c_str());
                image.SetPhotometricInterpretation(pi);
               
                //Rescale Intercept
                image.SetIntercept(getAttributeValue<VPL_GDCM_RescaleIntercept>());
               
                //Rescale Slope
                gdcm::Attribute<0x0028, 0x1053>::ArrayType v = getAttributeValue<VPL_GDCM_RescaleSlope>();
                //check if Slope was defined, if not assigned default value 1.0
                if (v)
                    image.SetSlope(v);
                else
                    image.SetSlope(1.0);

                //fill private attributes
                m_fileLoaded = fillPrivateInfo(fileName);
                return m_fileLoaded;
            }
        }        
    }
    return false;
}

std::string CDicomSliceLoaderGDCM::readTag(unsigned groupNum, unsigned elemNum)
{
    return readTag(gdcm::Tag(groupNum, elemNum));
}

bool CDicomSliceLoaderGDCM::loadImagePositions()
{
    if (!m_fileLoaded && !m_filePreloaded) 
    {        
        return false;    
    }
   
    // get image position tag
    double origin[3] = {0,0,0};
    gdcm::DataSet& ds = m_gdcmReader.GetFile().GetDataSet();

    if (ds.FindDataElement(gdcm::Tag(VPL_GDCM_ImagePositionPatient)))
    {
        //defualt value returned by this method should be array with length 3
        //possibly dangerous
        const double *tmp = getAttribute<VPL_GDCM_ImagePositionPatient>().GetValues();
        origin[0] = tmp[0];
        origin[1] = tmp[1];
        origin[2] = tmp[2];

        //if origin was not derived from tag VPL_GDCM_ImagePositionPatient
        if (origin[0] == 0 && origin[1] == 0 && origin[2] == 0)
        {
            //try to get it from image
            gdcm::Image img = m_gdcmReader.GetImage();
            if (!img.IsEmpty())
            {
                origin[0] = img.GetOrigin(0);
                origin[1] = img.GetOrigin(1);
                origin[2] = img.GetOrigin(2);
            }
                
        }
    }
      
    // if it's simple dicom file, then return this values
    if (!isMultiframe())        
    {
        std::vector<double> tmp;
        tmp.push_back(origin[0]);
        tmp.push_back(origin[1]);
        tmp.push_back(origin[2]);
        m_ImagePositions.push_back(tmp);
        return true;
    }
    //if it's multiframe file
    else
    {
        //let's see if the image position was defined as nested for every slice
        if (parseNestedPosition())
            //if so, then this function has already filled the vector and we're good
            return true;
        //we have to compute position for every frame/slice
        else
        {
            //we will need spacing
            //const double *spacings = img.GetSpacing();
            double spacings = getAttributeValue<VPL_GDCM_SpacingBetweenSlices>();
            double f1, f2, f3;
            f1 = f2 = f3 = 0;
            for (unsigned int i = 0; i < m_iNumOfFrames; ++i)
            {
                f3 += spacings;
                std::vector<double> tmp;
                tmp.push_back(f1);
                tmp.push_back(f2);
                tmp.push_back(f3);

                m_ImagePositions.push_back(tmp);
            }
            return true;
        }
    }    
    return false;
}

bool CDicomSliceLoaderGDCM::preLoadFile(std::string fileName)
{   
    if (fileName.empty())
        return false;

    m_gdcmReader.SetFileName(fileName.c_str());    

    //read up to pixel data
    if (!m_gdcmReader.ReadUpToTag(gdcm::Tag(VPL_GDCM_PixelData)))
        return false;

    //number of frames is needed for isMultiframe() function
    m_iNumOfFrames = getAttributeValue<VPL_GDCM_NumberOfFrames>();

    //enable access to dataset
    m_filePreloaded = true;
    
    //load image positions
    m_filePreloaded = loadImagePositions();

    return m_filePreloaded;
}

bool CDicomSliceLoaderGDCM::trimSlashesAndPush(gdcm::DataElement& el)
{
    std::ostringstream stream;
    stream << el.GetValue();
    std::string s = stream.str();
    std::vector<double> arr;
    
    std::vector<std::string> tokens;

    splitStringToTokens(tokens, s, "\\");

    if (tokens.size() < 3)
        return false;

    //fill the helper array with positions coverted from strings to doubles
    for (std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); ++it)
    {
        double val = std::atof((*it).c_str());
        arr.push_back(val);

    }

    m_ImagePositions.push_back(arr);

    return true;
}

bool CDicomSliceLoaderGDCM::fillPrivateInfo(std::string fileName)
{  
    gdcm::Image &img = m_gdcmReader.GetImage();
    if (img.IsEmpty())
        return false;

    m_sFileName = fileName;
    m_iNumOfDimensions = img.GetNumberOfDimensions();
    
    m_iNumOfFrames = getAttributeValue<VPL_GDCM_NumberOfFrames>();    

    //dimensions
    const unsigned int* dimension = img.GetDimensions();

    m_dimX = dimension[0];
    m_dimY = dimension[1];
    m_dimZ = dimension[2];

    //get Slope and Intercept values
    m_intercept = img.GetIntercept();
    m_slope = img.GetSlope();

    // Loads image positions
     return loadImagePositions();
}

std::string CDicomSliceLoaderGDCM::readTag(gdcm::Tag tag) const
{
    //If file was not loaded we can not acces dataset
    if (!m_fileLoaded && !m_filePreloaded)
        return "";

    const gdcm::File &file = m_gdcmReader.GetFile();
    const gdcm::DataSet &ds = file.GetDataSet();

    if (ds.FindDataElement(tag))
    {
        gdcm::DataElement el = ds.GetDataElement(tag);

        if (!el.IsEmpty())
        {
            std::ostringstream stringStream;
            stringStream << el.GetValue();

            return stringStream.str();
        }                
    }
    return "";
            
}

int CDicomSliceLoaderGDCM::getNumberOfDimensions() const
{    
    return m_iNumOfDimensions;
}

unsigned int CDicomSliceLoaderGDCM::getNumberOfFrames() const
{
    return m_iNumOfFrames;
}

bool CDicomSliceLoaderGDCM::isMultiframe()
{
    if (m_iNumOfFrames > 1)
        return true;
    if (m_iNumOfDimensions == 3)
        return true;

    return false;
}

bool CDicomSliceLoaderGDCM::loadImage(CDicomSlice &dicomSlice)
{
    if (!m_fileLoaded)
        return false;

    gdcm::Image &img = m_gdcmReader.GetImage();
    if (img.IsEmpty())
        return false;

    //if the buffer wasn't filled
    if(m_buffer.getSize() == 0)
    {
        m_buffer.resize(img.GetBufferLength());
        //copies the raw image data into buffer
        img.GetBuffer(m_buffer.getPtr());
    }
  
    // copy raw image data to buffer
    if (!img.GetBuffer(m_buffer.getPtr()))
    {
        VPL_LOG_ERROR('<' << "DicomSliceLoaderGDCM.cpp" << "> Failed to load raw image data" << std::endl);
        return false;
    }

    //set image position
    if (!m_ImagePositions.empty())
    {
        //helper variables for thickess / z-axis position calculation
        vpl::img::CPoint3D zero_point(0, 0, 0);
        vpl::img::CVector3D normal_image;
        ////set image position from vector of positions
        dicomSlice.m_ImagePosition.setX(m_ImagePositions.at(0)[0]);
        dicomSlice.m_ImagePosition.setY(m_ImagePositions.at(0)[1]);
        dicomSlice.m_ImagePosition.setZ(m_ImagePositions.at(0)[2]);

        // slice position calculation
        //Z-axis
        normal_image.vectorProduct(dicomSlice.m_ImageOrientationX, dicomSlice.m_ImageOrientationY);
        normal_image.normalize();

        vpl::img::CVector3D position_vector(zero_point, dicomSlice.m_ImagePosition);
        dicomSlice.setPosition(normal_image.dotProduct(normal_image, position_vector));
    }    
    //loads first (and only) frame into dicomSlice
    return readImage(dicomSlice, m_buffer.getPtr(), 0);            
}

bool CDicomSliceLoaderGDCM::readImage(CDicomSlice &dicomSlice, char* buffer, unsigned index)
{
    dicomSlice.resize(tSize(m_dimX), tSize(m_dimY));

    gdcm::Image &img = m_gdcmReader.GetImage();
    if (img.IsEmpty())
        return false;

    if (img.GetPhotometricInterpretation() == gdcm::PhotometricInterpretation::MONOCHROME2)
    {
        //cast the bufer pointer according to pixel representation
        if (img.GetPixelFormat().GetScalarType() == gdcm::PixelFormat::UINT16)
        {
            vpl::sys::tUInt16* buffer16 = (vpl::sys::tUInt16 *)buffer;
            buffer16 = &buffer16[m_dimX*m_dimY*index];
            readRawImageDataIntoSlice(buffer16, dicomSlice);
            return true;
        }
        else if (img.GetPixelFormat().GetScalarType() == gdcm::PixelFormat::INT16)
        {
            vpl::sys::tInt16* buffer16 = (vpl::sys::tInt16 *)buffer;
            buffer16 = &buffer16[m_dimX*m_dimY*index];
            readRawImageDataIntoSlice(buffer16, dicomSlice);
            return true;
        }
        else if (img.GetPixelFormat().GetScalarType() == gdcm::PixelFormat::UINT8)
        {
            vpl::sys::tUInt8* buffer8 = (vpl::sys::tUInt8*)buffer;
            buffer8 = &buffer8[m_dimX*m_dimY*index];
            readRawImageDataIntoSlice(buffer8, dicomSlice);
            return true;
        }
        else if (img.GetPixelFormat().GetScalarType() == gdcm::PixelFormat::INT8)
        {
            vpl::sys::tInt8* buffer8 = (vpl::sys::tInt8*)buffer;
            buffer8 = &buffer8[m_dimX*m_dimY*index];
            readRawImageDataIntoSlice(buffer8, dicomSlice);
            return true;
        }
        VPL_LOG_ERROR('<' << "DicomSliceLoaderGDCM.cpp" << "> Unknown Pixel Representation" << std::endl);
        return false;
    }
    VPL_LOG_ERROR('<' << "DicomSliceLoaderGDCM.cpp" << "> Unknown Photometric Interpretation" << std::endl);
    return false;
}

bool CDicomSliceLoaderGDCM::readFile(std::string fileName)
{
    // check if file exists
    struct stat buffer;
    if (!stat(fileName.c_str(), &buffer) == 0)
    {
        VPL_LOG_ERROR('<' << "DicomSliceLoaderGDCM.cpp" << "> Failed to open file" << std::endl);
        return false;
    }
    m_gdcmReader.SetFileName(fileName.c_str());

    if (!m_gdcmReader.CanRead())
    {        
        VPL_LOG_ERROR('<' << "DicomSliceLoaderGDCM.cpp" << "> Not readable DICOM file" << std::endl);
        return false;
    }

    if (!m_gdcmReader.Read())
    {       
            VPL_LOG_ERROR('<' << "DicomSliceLoaderGDCM.cpp" << "> Failed to read file" << std::endl);
            throw CDicomSliceLoaderGDCMExeption();        
    }

    // Loading was successful, this allows to use methods readTag(), loadImage() and others
    m_fileLoaded = true;

    //fill attributes
    m_fileLoaded = fillPrivateInfo(fileName);

    return m_fileLoaded;
}

bool CDicomSliceLoaderGDCM::readFile()
{
    if (m_sFileName.empty()) 
        return false;
    return readFile(m_sFileName);
}


} // namespace img
} // namespace vpl

#endif // VPL_USE_GDCM
