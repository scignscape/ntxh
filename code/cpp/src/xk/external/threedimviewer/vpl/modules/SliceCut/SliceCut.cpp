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
 * Date:    2004/08/19                       
 *
 * File description:
 * - Cuts a specified interval of pixels.
 */

#include "SliceCut.h"

#include <VPL/Image/Slice.h>

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module cuts a specified interval of pixels.";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "min:max";

//! Additional arguments
const std::string MODULE_ARGUMENT_MIN   = "min";
const std::string MODULE_ARGUMENT_MAX   = "max";

//! Default min and max values
const int DEFAULT_MIN          = vpl::img::CPixelTraits<vpl::img::CSlice::tPixel>::getPixelMin();
const int DEFAULT_MAX          = vpl::img::CPixelTraits<vpl::img::CSlice::tPixel>::getPixelMax();


//==============================================================================
/*
 * Implementation of the class CSliceCut.
 */
CSliceCut::CSliceCut(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceCut::~CSliceCut()
{
}


bool CSliceCut::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line parameters 'min' and 'max'
    m_iMin = DEFAULT_MIN;
    m_Arguments.value(MODULE_ARGUMENT_MIN, m_iMin);
    if( m_iMin > DEFAULT_MAX || m_iMin < DEFAULT_MIN )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'min' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'max'
    m_iMax = DEFAULT_MAX;
    m_Arguments.value(MODULE_ARGUMENT_MAX, m_iMax);
    if( m_iMax < m_iMin || m_iMax > DEFAULT_MAX )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'max' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CSliceCut::main()
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
        // Otherwise, read slice from the input channel
        if( readInput(pIChannel, spSlice.get()) )
        {
            // Cut the interval
            spSlice->cut((vpl::img::CSlice::tPixel)m_iMin, (vpl::img::CSlice::tPixel)m_iMax);

            // Write it to the output channel
            if( !writeOutput(pOChannel, spSlice.get()) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
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


void CSliceCut::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSliceCut::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-min iValue] [-max iValue]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -min  Lower boundary of the interval." << std::endl;
    Stream << "  -max  Higher interval boundary." << std::endl;
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
    CSliceCutPtr spModule(new CSliceCut(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

