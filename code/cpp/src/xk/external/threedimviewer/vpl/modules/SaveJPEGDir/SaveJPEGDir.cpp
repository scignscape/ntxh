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
 * Date:    2010/11/05                       
 *
 * File description:
 * - Saves all input slices as JPEG images to a given directory.
 */

#include "SaveJPEGDir.h"

// MDSTk
#include <VPL/Image/Slice.h>
#include <VPL/ImageIO/JPEG.h>
#include <VPL/System/System.h>

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
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSaveJPEGDir::~CSaveJPEGDir()
{
}


bool CSaveJPEGDir::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input channel
    if( getNumOfInputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input channels" << std::endl);
        return false;
    }

    // Image format
    m_ssFormat = DEFAULT_FORMAT;
    m_Arguments.value(MODULE_ARG_FORMAT, m_ssFormat);
    if( m_ssFormat != IMAGE8 && m_ssFormat != SLICE && m_ssFormat != RGB )
    {
        VPL_LOG_ERROR('<' << getFilename() << "> Wrong '" << MODULE_ARG_FORMAT << "' parameter value: type -h for help" << std::endl);
        return false;
    }

    // Input directory
    if( !m_Arguments.exists(MODULE_ARG_DIR) )
    {
        VPL_LOG_ERROR('<' << getFilename() << "> Input directory was not specified: type -h for help" << std::endl);
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
    vpl::mod::CFileChannel FileChannel(vpl::mod::CH_OUT, Stream.str());

    // Open the input file
    if( !FileChannel.connect() )
    {
        VPL_LOG_ERROR('<' << this->getFilename() << "> Cannot create output file: " << Stream.str() << std::endl);
        return false;
    }

    // Save JPEG image
    bool bSaved = vpl::img::saveJPEG(Image, FileChannel);

    // Close the channel
    FileChannel.disconnect();

    // Check for an error...
    if( !bSaved )
    {
        VPL_LOG_ERROR('<' << this->getFilename() << "> Failed to write the output JPEG image: " << Stream.str() << std::endl);
        return false;
    }

    VPL_LOG_INFO("Saved " << Stream.str());
    return true;
}


bool CSaveJPEGDir::main()
{
    // Note
    VPL_LOG_INFO("Module main function");

    // I/O channels
    vpl::mod::CChannel *pIChannel = getInput(0);

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
        vpl::img::CImage8Ptr spImage(new vpl::img::CImage8);

        // Read image from the input channel
        if( !readInput(pIChannel, spImage.get()) )
        {
            VPL_LOG_ERROR('<' << getFilename() << "> Failed to read input image" << std::endl);
            return false;
        }

        // Save the image
        saveImageToDir(*spImage);
    }
    else if( m_ssFormat == RGB )
    {
        // Create a new image
        vpl::img::CRGBImagePtr spImage(new vpl::img::CRGBImage);

        // Read image from the input channel
        if( !readInput(pIChannel, spImage.get()) )
        {
            VPL_LOG_ERROR('<' << getFilename() << "> Failed to read input image" << std::endl);
            return false;
        }

        // Save the image
        saveImageToDir(*spImage);
    }
    else if( m_ssFormat == SLICE )
    {
        // Create a new image
        vpl::img::CSlicePtr spSlice(new vpl::img::CSlice);

        // Read image from the input channel
        if( !readInput(pIChannel, spSlice.get()) )
        {
            VPL_LOG_ERROR('<' << getFilename() << "> Failed to read input image" << std::endl);
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
    VPL_LOG_INFO("Module shutdown");
}


void CSaveJPEGDir::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-format ssType]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -format  Specifies input image format." << std::endl;
    Stream << "           One of the following values can be given:" << std::endl;
    Stream << "             " << IMAGE8 << std::endl;
    Stream << "             " << RGB << std::endl;
    Stream << "             " << SLICE << std::endl;
    Stream << "           Default value is " << DEFAULT_FORMAT << "." << std::endl;
    Stream << std::endl;
    Stream << "  -dir  Input directory that will by searched for input images." << std::endl;
    Stream << "        E.g. ../data/myimages" << std::endl;
    Stream << std::endl;
    Stream << "Input: sequence of MDSTk images" << std::endl;
    Stream << "Output: see the options" << std::endl;
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

