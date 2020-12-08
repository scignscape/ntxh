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
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/11/01                          \n
 *
 * File description:
 * - Loads all PNG images from a given directory.
 * - Converts them to the slice format.
 */

#include "LoadPNGDir.h"

#include <VPL/Image/Slice.h>
#include <VPL/ImageIO/PNG.h>
#include <VPL/System/FileBrowser.h>
#include <VPL/Base/StaticAssert.h>

// STL
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global module constants.
 */

// Module description
const std::string MODULE_DESCRIPTION    = "Module loads PNG images from a directory";

// Additional command line arguments
const std::string MODULE_ARGUMENTS      = "format:dir:filemask";

//! Additional arguments
const std::string MODULE_ARG_FORMAT     = "format";
const std::string MODULE_ARG_DIR        = "dir";
const std::string MODULE_ARG_FILEMASK   = "filemask";

//! Allowed output image formats
const std::string IMAGE8                = "image8";
const std::string RGB                   = "rgb";
const std::string SLICE                 = "slice";

//! Default argument values
const std::string DEFAULT_FORMAT        = SLICE;
const std::string DEFAULT_FILEMASK      = "*.png";


//==============================================================================
/*
 * Implementation of the class CLoadPNGDir.
 */
CLoadPNGDir::CLoadPNGDir(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CLoadPNGDir::~CLoadPNGDir()
{
}


bool CLoadPNGDir::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of output channels: type -h for help" << std::endl);
        return false;
    }

    // Image format
    m_ssFormat = DEFAULT_FORMAT;
    m_Arguments.value(MODULE_ARG_FORMAT, m_ssFormat);
    if( m_ssFormat != IMAGE8 && m_ssFormat != SLICE && m_ssFormat != RGB )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong '" << MODULE_ARG_FORMAT << "' parameter value: type -h for help" << std::endl);
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


template <class ImageType>
int CLoadPNGDir::loadImagesFromDir(ImageType& AuxImage)
{
    // Output channel
    vpl::mod::CChannel *pOChannel = this->getOutput(0);

    // Initialize the file browser
    vpl::sys::CFileBrowserPtr spFileBrowser;

    // Get the current directory
    std::string CWD = spFileBrowser->getDirectory();

    // Change the current directory
    if( !spFileBrowser->setDirectory(this->m_ssDir) )
    {
        VPL_LOG_ERROR('<' << this->m_sFilename << "> Wrong input directory: type -h for help" << std::endl);
        return -1;
    }

    // Load all PNG files in the directory
    int iCount = 0;
    vpl::sys::CFileBrowser::SFileAttr File;
    bool bResult = spFileBrowser->findFirst(this->m_ssFileMask, File);

    // Load all PNG files in the directory
    for( ; bResult; bResult = spFileBrowser->findNext(File) )
    {
        // Create the input file channel
        vpl::mod::CFileChannel FileChannel(vpl::mod::CH_IN, File.m_sName);

        // Open the input file
        if( !FileChannel.connect() )
        {
            VPL_LOG_ERROR('<' << this->m_sFilename << "> Cannot open input file: " << File.m_sName << std::endl);
            continue;
        }

        // Read PNG image
        bool bLoaded = vpl::img::loadPNG(AuxImage, FileChannel);

        // Close the channel
        FileChannel.disconnect();

        // Check for an error...
        if( !bLoaded )
        {
            VPL_LOG_ERROR('<' << this->m_sFilename << "> Failed to read input PNG image: " << File.m_sName << std::endl);
            continue;
        }

        VPL_LOG_INFO("Loaded " << File.m_sName);

        // Write image to the output channel
        if( !this->writeOutput(pOChannel, &AuxImage) )
        {
            VPL_LOG_ERROR('<' << this->m_sFilename << "> Failed to write the output image" << std::endl);
            continue;
        }

        // Another image loaded...
        ++iCount;
    }

    // Restore the current working directory
    spFileBrowser->setDirectory(CWD);

    return iCount;
}


bool CLoadPNGDir::main()
{
    // Note
    VPL_LOG_INFO("Module main function");

    int iCount = 0;
    if( m_ssFormat == IMAGE8 )
    {
        // Create a new image
        vpl::img::CImage8Ptr spImage(new vpl::img::CImage8);

        // Load all images
        iCount = loadImagesFromDir(*spImage);
    }
    else if( m_ssFormat == RGB )
    {
        // Create a new image
        vpl::img::CRGBImagePtr spImage(new vpl::img::CRGBImage);

        // Load all images
        iCount = loadImagesFromDir(*spImage);
    }
    else if( m_ssFormat == SLICE )
    {
        // Create a new image
        vpl::img::CSlicePtr spSlice(new vpl::img::CSlice);

        // Load all images
        iCount = loadImagesFromDir(*spSlice);
    }

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


void CLoadPNGDir::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CLoadPNGDir::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-format ssType] [-dir ssPath] [-filemask ssMask]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -format  Specifies output image format." << std::endl;
    Stream << "           One of the following values can be given:" << std::endl;
    Stream << "             " << IMAGE8 << std::endl;
    Stream << "             " << RGB << std::endl;
    Stream << "             " << SLICE << std::endl;
    Stream << "           Default value is " << DEFAULT_FORMAT << "." << std::endl;
    Stream << std::endl;
    Stream << "  -dir  Input directory that will by searched for input images." << std::endl;
    Stream << "        E.g. ../data/myimages" << std::endl;
    Stream << std::endl;
    Stream << "  -filemask  Mask to select specific files in the directory." << std::endl;
    Stream << "             Default value is " << DEFAULT_FILEMASK << "." << std::endl;
    Stream << std::endl;
    Stream << "Input: see the options" << std::endl;
    Stream << "Output: sequence of MDSTk images" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CLoadPNGDirPtr spModule(new CLoadPNGDir(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

