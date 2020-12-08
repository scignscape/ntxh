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
 * Date:    2007/04/17                       
 *
 * Description:
 * - Histogram equalization.
 */

#include "SliceHistEqualization.h"

#include <VPL/Image/Slice.h>
#include <VPL/Image/ImageFunctions.h>

#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>

// STL
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module equalizes histogram of input slice";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "";

//! Additional arguments

//! Default arguments values


//==============================================================================
/*
 * Implementation of the class CSliceHistEqualization.
 */
CSliceHistEqualization::CSliceHistEqualization(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceHistEqualization::~CSliceHistEqualization()
{
}


bool CSliceHistEqualization::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line parameters

    // O.K.
    return true;
}


bool CSliceHistEqualization::main()
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
        // Read slice from the input channel
        if( readInput(pIChannel, spSlice.get()) )
        {
            // Histogram equalization
            if( !vpl::img::histogramEqualization(*spSlice) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Cannot equalize the histogram" << std::endl);
                return false;
            }

            // Write slice to the output channel
            if( !writeOutput(pOChannel, spSlice.get()) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output" << std::endl);
                return false;
            }
        }
        else
        {
            VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input slice" << std::endl);
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


void CSliceHistEqualization::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSliceHistEqualization::writeExtendedUsage(std::ostream& Stream)
{
    Stream << std::endl;
    Stream << "Input: MDSTk slice" << std::endl;
    Stream << "Output: MDSTk slice" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CSliceHistEqualizationPtr spModule(new CSliceHistEqualization(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

