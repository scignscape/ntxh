//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/11/01                          \n
 *
 * $Id: mdsLoadDicomDir.cpp 2098 2012-02-16 23:50:36Z spanel $
 *
 * File description:
 * - Loads all DICOM images from a given directory.
 */

#include "mdsLoadDicomDir.h"

#include <MDSTk/ImageIO/mdsDicomSlice.h>
#include <MDSTk/System/mdsFileBrowser.h>

// STL
#include <iostream>
#include <string>


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
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CLoadDicomDir::~CLoadDicomDir()
{
}


bool CLoadDicomDir::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of output channels: type -h for help" << std::endl);
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


bool CLoadDicomDir::main()
{
    // Note
    MDS_LOG_NOTE("Module main function");

    // I/O channels
    mds::mod::CChannel *pOChannel = getOutput(0);

    // Smart pointer to DICOM slice
    mds::img::CDicomSlicePtr spSlice(new mds::img::CDicomSlice);

    // Initialize the file browser
    mds::sys::CFileBrowserPtr spFileBrowser;

    // Get the current directory
    std::string CWD = spFileBrowser->getDirectory();

    // Change the current directory
    if( !spFileBrowser->setDirectory(m_ssDir) )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong input directory: type -h for help" << std::endl);
        return false;
    }

    // Load all JPEG files in the directory
    int iCount = 0;
    mds::sys::CFileBrowser::SFileAttr File;
    bool bResult = spFileBrowser->findFirst(m_ssFileMask, File);

    // Load all JPEG files in the directory
    for( ; bResult; bResult = spFileBrowser->findNext(File) )
    {
        // Create the input file channel
        mds::mod::CFileChannel FileChannel(mds::mod::CH_IN, File.m_sName);

        // Open the input file
        if( !FileChannel.connect() )
        {
            MDS_CERR('<' << m_sFilename << "> Cannot open input file: " << File.m_sName << std::endl);
            continue;
        }

        // Read JPEG image
        bool bLoaded = spSlice->loadDicom(&FileChannel);

        // Close the channel
        FileChannel.disconnect();

        // Check for an error...
        if( !bLoaded )
        {
            MDS_CERR('<' << m_sFilename << "> Failed to read input JPEG image: " << File.m_sName << std::endl);
            continue;
        }

        MDS_LOG_NOTE("Loaded " << File.m_sName);

        // Write image to the output channel
        if( !this->writeOutput(pOChannel, spSlice.get()) )
        {
            MDS_CERR('<' << m_sFilename << "> Failed to write the output image" << std::endl);
            continue;
        }

        // Another image loaded...
        ++iCount;
    }

    // Restore the current working directory
    spFileBrowser->setDirectory(CWD);

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


void CLoadDicomDir::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CLoadDicomDir::writeExtendedUsage(std::ostream&)
{
    MDS_CERR("Extended usage: [-dir ssPath] [-filemask ssMask]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -dir  Input directory that will by searched for input images." << std::endl);
    MDS_CERR("        E.g. ../data/dicomdir" << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -filemask  Mask to select specific files in the directory." << std::endl);
    MDS_CERR("             Default value is " << DEFAULT_FILEMASK << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("Input: see the options" << std::endl);
    MDS_CERR("Output: sequence of MDSTk images/slices" << std::endl);
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

