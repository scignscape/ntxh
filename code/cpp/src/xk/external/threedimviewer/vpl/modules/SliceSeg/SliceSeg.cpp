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
 * Date:    2004/03/01                       
 *
 * File description:
 * - Sample slice segmentation module.
 */

#include "SliceSeg.h"
#include "SegMethod.h"

// MDSTk
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
const std::string MODULE_DESCRIPTION    = "Sample module providing image segmentation.";

//! Additional command line arguments
//! - Colon separated list!
//! - Sample code!
const std::string MODULE_ARGUMENTS      = "a:b";

//! Additional arguments names
//! - Sample code!
const std::string MODULE_ARGUMENT_A     = "a";
const std::string MODULE_ARGUMENT_B     = "b";

//! Default arguments values
//! - Sample code!
const unsigned int DEFAULT_A            = 1;


//==============================================================================
/*
 * Implementation of the class CSliceSeg.
 */
CSliceSeg::CSliceSeg(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    // Allow additional command line arguments
    allowArguments(MODULE_ARGUMENTS);
}


CSliceSeg::~CSliceSeg()
{
}


bool CSliceSeg::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line argument - a
    //! - Sample code!
    m_iA = DEFAULT_A;
    m_Arguments.value(MODULE_ARGUMENT_A, m_iA);
    if( m_iA > 100 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'a' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Command line argument - b
    //! - Sample code!
    m_bB = m_Arguments.exists(MODULE_ARGUMENT_B);

    // O.K.
    return true;
}


bool CSliceSeg::main()
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
            // Create a new slice
            // - Copy of the input one
            vpl::img::CSlicePtr spSegmented(new vpl::img::CSlice(*spSlice));

            // Image segmentation method
            vpl::imseg::CSegMethod Method;

            // Method initialization
            // - sample code
            if( !Method.init() )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Cannot initialize image segmentation method" << std::endl);
            }
            else if( !Method(*spSlice, *spSegmented) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Cannot process image segmentation" << std::endl);
            }

            // Write the result to the output channel
            if( !writeOutput(pOChannel, spSegmented.get()) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the segmented slice" << std::endl);
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


void CSliceSeg::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSliceSeg::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-a iValue] [-b]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -a  ..." << std::endl;
    Stream << "  -b  ..." << std::endl;
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
    CSliceSegPtr spModule(new CSliceSeg(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

