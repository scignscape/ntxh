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
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/03/30                          \n
 *
 * File description:
 * - Converts an input slice to PNG image format.
 */

#include "SavePNG.h"

// MDSTk
#include <VPL/Image/Slice.h>
#include <VPL/ImageIO/PNG.h>

// STL
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module converts an input slice to the PNG image";

// Additional command line arguments
const std::string MODULE_ARGUMENTS      = "format";

//! Additional arguments
const std::string MODULE_ARG_FORMAT     = "format";

//! Allowed output image formats
const std::string IMAGE8                = "image8";
const std::string IMAGE16               = "image16";
const std::string RGB                   = "rgb";
const std::string SLICE                 = "slice";

//! Default argument values
const std::string DEFAULT_FORMAT        = SLICE;


//==============================================================================
/*
 * Implementation of the class CSavePNG.
 */
CSavePNG::CSavePNG(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSavePNG::~CSavePNG()
{
}


bool CSavePNG::startup()
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

    // O.K.
    return true;
}


bool CSavePNG::main()
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
                if( !vpl::img::savePNG(*spImage, *pOChannel) )
                {
                    VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output PNG image" << std::endl);
                }
            }
            else
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input image" << std::endl);
            }
        }
        else if (m_ssFormat == IMAGE16)
        {
            // Create a new image
            vpl::img::CImage16Ptr spImage;

            // Read image from the input channel
            if (readInput(pIChannel, spImage.get()))
            {
                // Write it to the output channel
                if (!vpl::img::savePNG(*spImage, *pOChannel))
                {
                    VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output PNG image" << std::endl);
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
                if( !vpl::img::savePNG(*spImage, *pOChannel) )
                {
                    VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output PNG image" << std::endl);
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
                if( !vpl::img::savePNG(*spSlice, *pOChannel) )
                {
                    VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output PNG image" << std::endl);
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


void CSavePNG::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSavePNG::writeExtendedUsage(std::ostream& Stream)
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
    CSavePNGPtr spModule(new CSavePNG(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Module application finished
    return 0;
}
