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
 * Date:    2003/12/22                       
 *
 * File description:
 * - Shows information on input slice.
 */

#include "SliceInfo.h"

#include <VPL/Image/Slice.h>
#include <VPL/Image/ImageFunctions.h>

#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>

// STL
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

// Module description
const std::string MODULE_DESCRIPTION    = "Module shows information on input slice.";

// Additional command line arguments
const std::string MODULE_ARGUMENTS      = "";


//==============================================================================
/*
 * Implementation of the class CSliceInfo.
 */
CSliceInfo::CSliceInfo(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceInfo::~CSliceInfo()
{
}


bool CSliceInfo::startup()
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


bool CSliceInfo::main()
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
            // Create the output string
            char pcOut[1024];
            sprintf(pcOut,
                    "-- Information on slice image data --\n"
                    " Width:      %d\n"
                    " Height:     %d\n"
                    " Index:      %d\n"
                    " Position:   %.2f\n"
                    " Pixel:      %.2f, %.2f\n"
                    " Thickness:  %.2f\n"
                    "-- Pixel values statistic --\n"
                    " Minimum:    %d\n"
                    " Maximum:    %d\n"
                    " Mean value: %.2f\n"
                    " Variance:   %.2f\n",
                    spSlice->getXSize(),
                    spSlice->getYSize(),
                    spSlice->getIndex(),
                    spSlice->getPosition(),
                    spSlice->getDX(),
                    spSlice->getDY(),
                    spSlice->getThickness(),
                    vpl::img::getMin<int>(*spSlice),
                    vpl::img::getMax<int>(*spSlice),
                    vpl::img::getMean<double>(*spSlice),
                    sqrt(vpl::img::getVariance<double>(*spSlice))
                   );

            // Write it to the output channel
            if( !pOChannel->write(pcOut, vpl::tSize(strlen(pcOut))) )
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


void CSliceInfo::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSliceInfo::writeExtendedUsage(std::ostream& Stream)
{
    Stream << std::endl;
    Stream << "Input: MDSTk slice" << std::endl;
    Stream << "Output: text" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CSliceInfoPtr spModule(new CSliceInfo(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

