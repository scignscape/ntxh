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

#ifndef VPL_DICOMDIRLOADER_H
#define VPL_DICOMDIRLOADER_H

#include <VPL/ImageIO/ImageIOExport.h>
#include <VPL/ImageIO/DicomSliceLoaderVPL.h>
#include <VPL/ImageIO/DicomSliceLoaderGDCM.h>
#include <VPL/System/FileBrowser.h>
#include <VPL/Image/DensityVolume.h>


namespace vpl
{
namespace img
{
//==============================================================================
/*!
* Loads all DICOM images from directory, and make volume.
*/
class VPL_IMAGEIO_EXPORT CDicomDirLoader
{
public:

    CDicomDirLoader()
    {
        m_imageCount = 0;
    }
    //! Get number of success loaded DICOM files.
    int getNumOfImages() 
    {
        return m_imageCount;
    }
    //! Loads data from DICOM files in direcotry, including image data, patient information, etc.
    bool loadDicomDir(const std::string& directory, const std::string& filemask = "*.dcm");

    //! Create density volume from loaded dicom files.
    bool makeDensityVolume(vpl::img::CDensityVolume& dstVolume, int borderValue = vpl::img::CPixelTraits<vpl::img::CDVolume::tVoxel>::getPixelMin()) const;

    bool getSlice(vpl::img::CDicomSlice& slice, int index) const;


private:
	vpl::img::CDicomSlicePtr m_dicomSlice;
    std::vector<vpl::img::CSlicePtr> m_slices;
    int m_imageCount;
};
}
}

#endif