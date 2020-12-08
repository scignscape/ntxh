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

#include <VPL/ImageIO/DicomDirLoader.h>

namespace vpl
{
namespace img
{

bool CDicomDirLoader::loadDicomDir(const std::string& directory, const std::string& filemask)
{
    // Initialize the file browser
    vpl::sys::CFileBrowserPtr spFileBrowser;

    // Get the current directory
    const std::string cwd = spFileBrowser->getDirectory();

    // Change the current directory
    if (!spFileBrowser->setDirectory(directory))
    {
        return false;
    }
    // Load all JPEG files in the directory
    vpl::sys::CFileBrowser::SFileAttr file;
    bool bResult = spFileBrowser->findFirst(filemask, file);



    // Load all JPEG files in the directory
    for (; bResult; bResult = spFileBrowser->findNext(file))
    {
        // Smart pointer to DICOM slice
        vpl::img::CDicomSlicePtr spSlice(new vpl::img::CDicomSlice);

        // Read JPEG image
        bool bOk = false;

#if defined( VPL_USE_GDCM )
        CDicomSliceLoaderGDCM loader;
        bOk = loader.loadDicom(file.m_sName, *spSlice, true);
#else
        CDicomSliceLoaderVPL loader;
        bOk = loader.loadDicom(file.m_sName, *spSlice, true);
#endif
        // Check for an error...
        if (!bOk)
        {
            continue;
        }

        if (m_slices.empty())
        {
            m_dicomSlice->copyProps(*spSlice);
            m_dicomSlice->copy(*spSlice);
        }

        // Another image loaded...
        m_slices.push_back(CSlicePtr(spSlice));
        ++m_imageCount;
    }
    // Restore the current working directory
    spFileBrowser->setDirectory(cwd);

    // Was any file found?
    return m_imageCount != 0;
}

bool CDicomDirLoader::makeDensityVolume(vpl::img::CDensityVolume& dstVolume, int borderValue) const
{
    // Make volume
    return dstVolume.makeVolume(m_slices);
}

bool CDicomDirLoader::getSlice(vpl::img::CDicomSlice& slice, const int index) const
{
    if (!m_slices.empty())
    {
        slice.copyProps(*m_dicomSlice);
        slice.copy(*m_dicomSlice);
        return true;
    }
    return false;
}
} // namespace img
} // namespace vpl
