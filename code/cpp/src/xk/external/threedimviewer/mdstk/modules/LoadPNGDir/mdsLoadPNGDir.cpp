//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/11/01                          \n
 *
 * $Id: mdsLoadPNGDir.cpp 2098 2012-02-16 23:50:36Z spanel $
 *
 * File description:
 * - Loads all PNG images from a given directory.
 * - Converts them to the slice format.
 */

#include "mdsLoadPNGDir.h"

#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/ImageIO/mdsPNG.h>
#include <MDSTk/System/mdsFileBrowser.h>
#include <MDSTk/Base/mdsStaticAssert.h>

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
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CLoadPNGDir::~CLoadPNGDir()
{
}


bool CLoadPNGDir::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of output channels: type -h for help" << std::endl);
        return false;
    }

    // Image format
    m_ssFormat = DEFAULT_FORMAT;
    m_Arguments.value(MODULE_ARG_FORMAT, m_ssFormat);
    if( m_ssFormat != IMAGE8 && m_ssFormat != SLICE && m_ssFormat != RGB )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong '" << MODULE_ARG_FORMAT << "' parameter value: type -h for help" << std::endl);
        return false;
    }

    // File mask
    m_ssFileMask = DEFAULT_FILEMASK;
    m_Arguments.value(MODULE_ARG_FILEMASK, m_ssFileMask);
    if( m_ssFileMask.empty() )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong '" << MODULE_ARG_FILEMASK << "' parameter value: type -h for help" << std::endl);
        return false;
    }

    // Input directory
    if( !m_Arguments.exists(MODULE_ARG_DIR) )
    {
        MDS_CERR('<' << m_sFilename << "> Input directory was not specified: type -h for help" << std::endl);
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
    mds::mod::CChannel *pOChannel = this->getOutput(0);

    // Initialize the file browser
    mds::sys::CFileBrowserPtr spFileBrowser;

    // Get the current directory
    std::string CWD = spFileBrowser->getDirectory();

    // Change the current directory
    if( !spFileBrowser->setDirectory(this->m_ssDir) )
    {
        MDS_CERR('<' << this->m_sFilename << "> Wrong input directory: type -h for help" << std::endl);
        return -1;
    }

    // Load all PNG files in the directory
    int iCount = 0;
    mds::sys::CFileBrowser::SFileAttr File;
    bool bResult = spFileBrowser->findFirst(this->m_ssFileMask, File);

    // Load all PNG files in the directory
    for( ; bResult; bResult = spFileBrowser->findNext(File) )
    {
        // Create the input file channel
        mds::mod::CFileChannel FileChannel(mds::mod::CH_IN, File.m_sName);

        // Open the input file
        if( !FileChannel.connect() )
        {
            MDS_CERR('<' << this->m_sFilename << "> Cannot open input file: " << File.m_sName << std::endl);
            continue;
        }

        // Read PNG image
        bool bLoaded = mds::img::loadPNG(AuxImage, FileChannel);

        // Close the channel
        FileChannel.disconnect();

        // Check for an error...
        if( !bLoaded )
        {
            MDS_CERR('<' << this->m_sFilename << "> Failed to read input PNG image: " << File.m_sName << std::endl);
            continue;
        }

        MDS_LOG_NOTE("Loaded " << File.m_sName);

        // Write image to the output channel
        if( !this->writeOutput(pOChannel, &AuxImage) )
        {
            MDS_CERR('<' << this->m_sFilename << "> Failed to write the output image" << std::endl);
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
    MDS_LOG_NOTE("Module main function");

    int iCount = 0;
    if( m_ssFormat == IMAGE8 )
    {
        // Create a new image
        mds::img::CImage8Ptr spImage(new mds::img::CImage8);

        // Load all images
        iCount = loadImagesFromDir(*spImage);
    }
    else if( m_ssFormat == RGB )
    {
        // Create a new image
        mds::img::CRGBImagePtr spImage(new mds::img::CRGBImage);

        // Load all images
        iCount = loadImagesFromDir(*spImage);
    }
    else if( m_ssFormat == SLICE )
    {
        // Create a new image
        mds::img::CSlicePtr spSlice(new mds::img::CSlice);

        // Load all images
        iCount = loadImagesFromDir(*spSlice);
    }

    // Log the number of loaded images
    MDS_LOG_NOTE("Num. of images: " << iCount);

    // Was any file found?
    if( iCount == 0 )
    {
        MDS_CERR('<' << m_sFilename << "> No image found" << std::endl);
    }

    // Returning 'true' means to continue processing the input channel
    return false;
}


void CLoadPNGDir::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CLoadPNGDir::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-format ssType] [-dir ssPath] [-filemask ssMask]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -format  Specifies output image format." << std::endl);
    MDS_CERR("           One of the following values can be given:" << std::endl);
    MDS_CERR("             " << IMAGE8 << std::endl);
    MDS_CERR("             " << RGB << std::endl);
    MDS_CERR("             " << SLICE << std::endl);
    MDS_CERR("           Default value is " << DEFAULT_FORMAT << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -dir  Input directory that will by searched for input images." << std::endl);
    MDS_CERR("        E.g. ../data/myimages" << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -filemask  Mask to select specific files in the directory." << std::endl);
    MDS_CERR("             Default value is " << DEFAULT_FILEMASK << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("Input: see the options" << std::endl);
    MDS_CERR("Output: sequence of MDSTk images" << std::endl);
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

