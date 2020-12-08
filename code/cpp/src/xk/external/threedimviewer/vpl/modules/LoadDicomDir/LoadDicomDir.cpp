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
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2010 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/11/01                       
 *
 * File description:
 * - Loads all DICOM images from a given directory.
 */

#include "LoadDicomDir.h"

#include <VPL/ImageIO/DicomSlice.h>
#include <VPL/System/FileBrowser.h>
#include <VPL/Base/Logging.h>
// STL
#include <iostream>
#include <string>

#   if defined( VPL_USE_GDCM )
//GDCM loader
#include <VPL/ImageIO/DicomSliceLoaderGDCM.h>
#   else
//Original loader
#include <VPL/ImageIO/DicomSliceLoaderVPL.h>
#   endif
//==============================================================================
/*
 * Global module constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module loads DICOM images from a given directory";

// Additional command line arguments
const std::string MODULE_ARGUMENTS      = "dir:filemask";

//! Additional arguments
const std::string MODULE_ARG_DIR        = "dir";
const std::string MODULE_ARG_FILEMASK   = "filemask";

//! Default argument values
const std::string DEFAULT_FILEMASK      = "*.dcm";


//==============================================================================
/*
 * Implementation of the class CLoadDicomDir.
 */
CLoadDicomDir::CLoadDicomDir(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CLoadDicomDir::~CLoadDicomDir()
{
}


bool CLoadDicomDir::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of output channels: type -h for help" << std::endl);
        return false;
    }

    // File mask
    m_ssFileMask = DEFAULT_FILEMASK;
    m_Arguments.value(MODULE_ARG_FILEMASK, m_ssFileMask);
    if( m_ssFileMask.empty() )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong '" << MODULE_ARG_FILEMASK << "' parameter value: type -h for help" << std::endl);
        return false;
    }

    // Input directory
    if( !m_Arguments.exists(MODULE_ARG_DIR) )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Input directory was not specified: type -h for help" << std::endl);
        return false;
    }
    m_Arguments.value(MODULE_ARG_DIR, m_ssDir);

    // O.K.
    return true;
}


bool CLoadDicomDir::main()
{
    // Note
    VPL_LOG_INFO("Module main function");

    // I/O channels
    vpl::mod::CChannel *pOChannel = getOutput(0);

    // Smart pointer to DICOM slice
    vpl::img::CDicomSlicePtr spSlice(new vpl::img::CDicomSlice);

    // Initialize the file browser
    vpl::sys::CFileBrowserPtr spFileBrowser;

    // Get the current directory
    std::string CWD = spFileBrowser->getDirectory();

    // Change the current directory
    if( !spFileBrowser->setDirectory(m_ssDir) )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong input directory: type -h for help" << std::endl);
        return false;
    }

    // Load all JPEG files in the directory
    int iCount = 0;
    vpl::sys::CFileBrowser::SFileAttr File;
    bool bResult = spFileBrowser->findFirst(m_ssFileMask, File);

    // Load all JPEG files in the directory
    for( ; bResult; bResult = spFileBrowser->findNext(File) )
    {
        
        // Read JPEG image
        bool bOK = false;

#   if defined( VPL_USE_GDCM )
        vpl::img::CDicomSliceLoaderGDCM m_Loader;
        bOK = m_Loader.loadDicom(File.m_sName, *spSlice, true);

#   else
        vpl::img::CDicomSliceLoaderVPL m_Loader;
        bOK = m_Loader.loadDicom(File.m_sName, *spSlice, true);

#   endif
        // Check for an error...
        if (!bOK)
        {
            VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input DICOM image: " << File.m_sName << std::endl);
            continue;
        }

        VPL_LOG_INFO("Loaded " << File.m_sName);

        // Write image to the output channel
        if( !this->writeOutput(pOChannel, spSlice.get()) )
        {
            VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output image" << std::endl);
            continue;
        }

        // Another image loaded...
        ++iCount;
    }

    // Restore the current working directory
    spFileBrowser->setDirectory(CWD);

    // Log the number of loaded images
    VPL_LOG_INFO("Num. of images: " << iCount);

    // Was any file found?
    if( iCount == 0 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> No image found" << std::endl);
    }

    // Returning 'true' means to continue processing the input channel
    return false;
}


void CLoadDicomDir::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CLoadDicomDir::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-dir ssPath] [-filemask ssMask]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -dir  Input directory that will by searched for input images." << std::endl;
    Stream << "        E.g. ../data/dicomdir" << std::endl;
    Stream << std::endl;
    Stream << "  -filemask  Mask to select specific files in the directory." << std::endl;
    Stream << "             Default value is " << DEFAULT_FILEMASK << "." << std::endl;
    Stream << std::endl;
    Stream << "Input: see the options" << std::endl;
    Stream << "Output: sequence of VPL images/slices" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CLoadDicomDirPtr spModule(new CLoadDicomDir(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

