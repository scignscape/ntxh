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
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/03/31                       
 *
 * File description:
 * - Converts an input slice to JPEG image format.
 */

#include "SaveJPEG.h"

// MDSTk
#include <VPL/Image/Slice.h>
#include <VPL/ImageIO/JPEG.h>

// STL
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

// Module description
const std::string MODULE_DESCRIPTION    = "Module converts input slice to JPEG image";

// Additional command line arguments
const std::string MODULE_ARGUMENTS      = "format:quality";

//! Additional arguments
const std::string MODULE_ARG_FORMAT     = "format";
const std::string MODULE_ARG_QUALITY    = "quality";

//! Allowed output image formats
const std::string IMAGE8                = "image8";
const std::string RGB                   = "rgb";
const std::string SLICE                 = "slice";

//! Default argument values
const std::string DEFAULT_FORMAT        = SLICE;
const int DEFAULT_ARG_QUALITY           = 128;

//! Allowed argument values
const int MIN_QUALITY                   = 0;
const int MAX_QUALITY                   = 255;


//==============================================================================
/*
 * Implementation of the class CSaveJPEG.
 */
CSaveJPEG::CSaveJPEG(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSaveJPEG::~CSaveJPEG()
{
}


bool CSaveJPEG::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Image format
    m_ssFormat = DEFAULT_FORMAT;
    m_Arguments.value(MODULE_ARG_FORMAT, m_ssFormat);

    // Parameter
    m_iQuality = DEFAULT_ARG_QUALITY;
    m_Arguments.value(MODULE_ARG_QUALITY, m_iQuality);
    if( m_iQuality < MIN_QUALITY || m_iQuality > MAX_QUALITY )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad " << MODULE_ARG_QUALITY << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CSaveJPEG::main()
{
    // Note
    VPL_LOG_INFO("Module main function");

    // I/O channels
    vpl::mod::CChannel *pIChannel = getInput(0);
    vpl::mod::CChannel *pOChannel = getOutput(0);

    // Is any input?
    if( !pIChannel->isConnected() )
    {
        return false;
    }

    // Create a new slice
    vpl::img::CSlicePtr spSlice;

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read input image of specified format
        if( m_ssFormat == IMAGE8 )
        {
            // Create a new image
            vpl::img::CImage8Ptr spImage;

            // Read image from the input channel
            if( readInput(pIChannel, spImage.get()) )
            {
                // Write it to the output channel
                if( !vpl::img::saveJPEG(*spImage, *pOChannel, m_iQuality) )
                {
                    VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output JPEG image" << std::endl);
                }
            }
            else
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input image" << std::endl);
            }
        }
        else if( m_ssFormat == RGB )
        {
            vpl::img::CRGBImagePtr spImage;
            if( readInput(pIChannel, spImage.get()) )
            {
                if( !vpl::img::saveJPEG(*spImage, *pOChannel, m_iQuality) )
                {
                    VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output JPEG image" << std::endl);
                }
            }
            else
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input image" << std::endl);
            }
        }
        else if( m_ssFormat == SLICE )
        {
            vpl::img::CSlicePtr spSlice;
            if( readInput(pIChannel, spSlice.get()) )
            {
                if( !vpl::img::saveJPEG(*spSlice, *pOChannel, m_iQuality) )
                {
                    VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output JPEG image" << std::endl);
                }
            }
            else
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input slice" << std::endl);
            }
        }
        else
        {
            VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_FORMAT << "' parameter value: type -h for help" << std::endl);
            printUsage();
            return false;
        }
        return false;
    }
    else
    {
        VPL_LOG_INFO("Wait timeout");
    }

    // Returning 'true' means to continue processing the input channel
    return true;
}


void CSaveJPEG::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSaveJPEG::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-format ssType] [-quality iValue]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -format  Specifies input image format." << std::endl;
    Stream << "           One of the following values can be given:" << std::endl;
    Stream << "             " << IMAGE8 << std::endl;
    Stream << "             " << RGB << std::endl;
    Stream << "             " << SLICE << std::endl;
    Stream << "           Default value is " << DEFAULT_FORMAT << "." << std::endl;
    Stream << std::endl;
    Stream << "  -quality  Quality of the JPEG image. Values in the range <0..255>" << std::endl;
    Stream << "            are allowed. Default value is " << DEFAULT_ARG_QUALITY << "." << std::endl;
    Stream << std::endl;
    Stream << "Input: MDSTk image" << std::endl;
    Stream << "Output: JPEG image" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CSaveJPEGPtr spModule(new CSaveJPEG(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

