//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/11/05                          \n
 *
 * $Id: mdsSaveJPEGDir.cpp 2098 2012-02-16 23:50:36Z spanel $
 *
 * File description:
 * - Saves all input slices as JPEG images to a given directory.
 */

#include "mdsSaveJPEGDir.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/ImageIO/mdsJPEG.h>
#include <MDSTk/System/mdsSystem.h>

// STL
#include <iostream>
#include <sstream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module saves all input images as JPEG images to a directory";

// Additional command line arguments
const std::string MODULE_ARGUMENTS      = "format:dir";

//! Additional arguments
const std::string MODULE_ARG_FORMAT     = "format";
const std::string MODULE_ARG_DIR        = "dir";

//! Allowed output image formats
const std::string IMAGE8                = "image8";
const std::string RGB                   = "rgb";
const std::string SLICE                 = "slice";

//! Default argument values
const std::string DEFAULT_FORMAT        = SLICE;

//! Output file extension
const std::string DEFAULT_FILEEXT       = ".jpg";


//==============================================================================
/*
 * Implementation of the class CSaveJPEGDir.
 */
CSaveJPEGDir::CSaveJPEGDir(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSaveJPEGDir::~CSaveJPEGDir()
{
}


bool CSaveJPEGDir::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input channel
    if( getNumOfInputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input channels" << std::endl);
        return false;
    }

    // Image format
    m_ssFormat = DEFAULT_FORMAT;
    m_Arguments.value(MODULE_ARG_FORMAT, m_ssFormat);
    if( m_ssFormat != IMAGE8 && m_ssFormat != SLICE && m_ssFormat != RGB )
    {
        MDS_CERR('<' << getFilename() << "> Wrong '" << MODULE_ARG_FORMAT << "' parameter value: type -h for help" << std::endl);
        return false;
    }

    // Input directory
    if( !m_Arguments.exists(MODULE_ARG_DIR) )
    {
        MDS_CERR('<' << getFilename() << "> Input directory was not specified: type -h for help" << std::endl);
        return false;
    }
    m_Arguments.value(MODULE_ARG_DIR, m_ssDir);

    // Truncate the trailing slash
    if( m_ssDir[m_ssDir.length() - 1] == '\\' || m_ssDir[m_ssDir.length() - 1] == '/' )
    {
        m_ssDir.resize(m_ssDir.length() - 1);
    }

    // O.K.
    return true;
}


template <class ImageType>
bool CSaveJPEGDir::saveImageToDir(ImageType& Image)
{
    // Image label
    static int iCount = 0;

    // Prepare the filename
    std::stringstream Stream;
    Stream.fill('0');
    Stream.setf(std::ios::right | std::ios::fixed);
    Stream << this->m_ssDir << SLASHC << std::setw(4) << iCount << DEFAULT_FILEEXT;

    // Increase the counter...
    ++iCount;

    // Create the input file channel
    mds::mod::CFileChannel FileChannel(mds::mod::CH_OUT, Stream.str());

    // Open the input file
    if( !FileChannel.connect() )
    {
        MDS_CERR('<' << this->getFilename() << "> Cannot create output file: " << Stream.str() << std::endl);
        return false;
    }

    // Save JPEG image
    bool bSaved = mds::img::saveJPEG(Image, FileChannel);

    // Close the channel
    FileChannel.disconnect();

    // Check for an error...
    if( !bSaved )
    {
        MDS_CERR('<' << this->getFilename() << "> Failed to write the output JPEG image: " << Stream.str() << std::endl);
        return false;
    }

    MDS_LOG_NOTE("Saved " << Stream.str());
    return true;
}


bool CSaveJPEGDir::main()
{
    // Note
    MDS_LOG_NOTE("Module main function");

    // I/O channels
    mds::mod::CChannel *pIChannel = getInput(0);

    // Is any input?
    if( !pIChannel->isConnected() )
    {
        return false;
    }

    // Wait for data
    if( !pIChannel->wait(1000) )
    {
        return true;
    }

    // Read input image of specified format
    if( m_ssFormat == IMAGE8 )
    {
        // Create a new image
        mds::img::CImage8Ptr spImage(new mds::img::CImage8);

        // Read image from the input channel
        if( !readInput(pIChannel, spImage.get()) )
        {
            MDS_CERR('<' << getFilename() << "> Failed to read input image" << std::endl);
            return false;
        }

        // Save the image
        saveImageToDir(*spImage);
    }
    else if( m_ssFormat == RGB )
    {
        // Create a new image
        mds::img::CRGBImagePtr spImage(new mds::img::CRGBImage);

        // Read image from the input channel
        if( !readInput(pIChannel, spImage.get()) )
        {
            MDS_CERR('<' << getFilename() << "> Failed to read input image" << std::endl);
            return false;
        }

        // Save the image
        saveImageToDir(*spImage);
    }
    else if( m_ssFormat == SLICE )
    {
        // Create a new image
        mds::img::CSlicePtr spSlice(new mds::img::CSlice);

        // Read image from the input channel
        if( !readInput(pIChannel, spSlice.get()) )
        {
            MDS_CERR('<' << getFilename() << "> Failed to read input image" << std::endl);
            return false;
        }

        // Save the image
        saveImageToDir(*spSlice);
    }

    // Returning 'true' means to continue processing the input channel
    return true;
}


void CSaveJPEGDir::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSaveJPEGDir::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-format ssType]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -format  Specifies input image format." << std::endl);
    MDS_CERR("           One of the following values can be given:" << std::endl);
    MDS_CERR("             " << IMAGE8 << std::endl);
    MDS_CERR("             " << RGB << std::endl);
    MDS_CERR("             " << SLICE << std::endl);
    MDS_CERR("           Default value is " << DEFAULT_FORMAT << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -dir  Input directory that will by searched for input images." << std::endl);
    MDS_CERR("        E.g. ../data/myimages" << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("Input: sequence of MDSTk images" << std::endl);
    MDS_CERR("Output: see the options" << std::endl);
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CSaveJPEGDirPtr spModule(new CSaveJPEGDir(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Module application finished
    return 0;
}

