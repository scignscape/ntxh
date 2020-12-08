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
 
#ifndef VPL_DICOMSLICELOADER_H
#define VPL_DICOMSLICELOADER_H

//VPL
#include <VPL/Base/Setup.h>
#include <VPL/ImageIO/ImageIOExport.h>
#include <VPL/Base/SharedPtr.h>
#include <VPL/Base/Exception.h>

#include <VPL/ImageIO/DicomSlice.h>

namespace vpl
{
namespace img
{
//==============================================================================
/*!
* Base class for all DICOM loaders.
*/
class VPL_IMAGEIO_EXPORT CDicomSliceLoader : public vpl::base::CObject
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CDicomSliceLoader);

    //! Exception generated whend GDCM loader fails to load DICOM file,  
    //! after catching this exeption it is possible to use CDicomSliceLoaderGDCM::tryToLoadBuggyFile
    //! wicht tries to load file but does not ensure data consistency
    VPL_DECLARE_EXCEPTION(CDicomSliceLoaderGDCMExeption, "GDCM Image Loader failed to read file.");

    //! Exception thrown when method is not implemented
    VPL_DECLARE_EXCEPTION(CDicomSliceLoaderNotImplemeted, "Not implemented.");

    //! Vector of CDicomSlices 
    typedef std::vector<CDicomSlice::tSmartPtr> tSlices;

    //! Vector of image positions, one image position is a 3-tuple
    typedef std::vector<std::vector<double> > tImagePositions;

public:
    //! Default constructor.
    CDicomSliceLoader() {}

    //! Default destructor.
    virtual ~CDicomSliceLoader() {}

    //! Loads data from DICOM file, including image data, patient information, etc.
    virtual bool loadDicom(std::string fileName, CDicomSlice &dicomSlice, bool load_image_data = true) = 0;

    //! Reads specified tag from DICOM file
    //! -Returns value as string
    virtual std::string readTag(unsigned int groupNum, unsigned int elemNum) = 0;

    //! Loads multiframe dicom file, into vector of slices
    virtual bool loadMultiframeDicom(std::string fileName, tSlices &slices, bool load_image_data = true) = 0;

    //! Loads only one frame from multiframe dicom file into given slice
    virtual bool loadMultiframeDicom(std::string fileName, CDicomSlice &dicomSlice, unsigned int index, bool load_image_data = true) = 0;
};

//==============================================================================
/*
* Smart pointer to DICOM slice.
*/
typedef CDicomSliceLoader::tSmartPtr  CDicomSliceLoaderPtr;


} // namespace img
} // namespace vpl

#endif // VPL_DICOMSLICELOADER_H
