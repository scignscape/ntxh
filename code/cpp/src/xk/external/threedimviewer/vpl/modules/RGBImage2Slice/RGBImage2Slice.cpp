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
 * Copyright (c) 2003-2007 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/14                       
 *
 * File description:
 * - Converts input RGB image to medical slice.
 */

#include "RGBImage2Slice.h"

// MDSTk
#include <VPL/Image/Slice.h>
#include <VPL/Image/ImageFunctions.h>

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module converts input RGB image to medical slice";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "";

//! Additional arguments


//==============================================================================
/*
 * Implementation of the class CRGBImage2Slice.
 */
CRGBImage2Slice::CRGBImage2Slice(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CRGBImage2Slice::~CRGBImage2Slice()
{
}


bool CRGBImage2Slice::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // O.K.
    return true;
}


bool CRGBImage2Slice::main()
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

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Create a new RGB image
        vpl::img::CRGBImagePtr spRGBImage;

        // Read image from the input channel
        if( readInput(pIChannel, spRGBImage.get()) )
        {
            // Convert RGB image to slice
            vpl::img::CSlicePtr spSlice;
            spSlice->convert(*spRGBImage);

            // Write it to the output channel
            if( !writeOutput(pOChannel, spSlice.get()) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
                return false;
            }
        }
        else
        {
            VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input RGB image" << std::endl);
            return false;
        }
    }
    else
    {
        VPL_LOG_INFO("Wait timeout");
    }

    // Returning 'true' means to continue processing the input channel
    return true;
}


void CRGBImage2Slice::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CRGBImage2Slice::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Input: MDSTk RGB image" << std::endl;
    Stream << "Output: MDSTk slice" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CRGBImage2SlicePtr spModule(new CRGBImage2Slice(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

