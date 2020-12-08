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
 * Author:   Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:     2005/01/25                       
 *
 * File description:
 * - Sample volume segmentation module.
 */

#include "VolumeSeg.h"
#include "SegMethod.h"

// MDSTk
#include <VPL/Image/Slice.h>
#include <VPL/Image/DensityVolume.h>

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Sample module providing volume segmentation functions.";

//! Additional command line arguments
//! - sample code
const std::string MODULE_ARGUMENTS      = "a:b";

//! Additional arguments names
//! - sample code
const std::string MODULE_ARGUMENT_A     = "a";
const std::string MODULE_ARGUMENT_B     = "b";

//! Default arguments values
//! - sample code
const unsigned int DEFAULT_A            = 1;


//==============================================================================
/*
 * Implementation of the class CVolumeSeg.
 */
CVolumeSeg::CVolumeSeg(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeSeg::~CVolumeSeg()
{
}


bool CVolumeSeg::startup()
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
    // - sample code
    m_iA = DEFAULT_A;
    m_Arguments.value(MODULE_ARGUMENT_A, m_iA);
    if( m_iA > 100 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'a' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Command line argument - b
    // - sample code
    m_bB = m_Arguments.exists(MODULE_ARGUMENT_B);

    // O.K.
    return true;
}


bool CVolumeSeg::main()
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

    // Create a new volume
    vpl::img::CDensityVolumePtr spVolume;

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read slice from the input channel
        if( readInput(pIChannel, spVolume.get()) )
        {
            // Create a new volume
            // - copy of the input one
            vpl::img::CDensityVolumePtr spSegmented(new vpl::img::CDensityVolume(*spVolume));

            // Volume segmentation method
            vpl::volseg::CSegMethod Method;

            // Method initialization
            // - sample code
            if( !Method.init() )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Cannot initialize volume segmentation method" << std::endl);
            }
            else if( !Method(*spVolume, *spSegmented) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Cannot process volume segmentation" << std::endl);
            }

            // Write the result to the output channel
            if( !writeOutput(pOChannel, spSegmented.get()) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the segmented volume" << std::endl);
            }
        }
        else
        {
            VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input volume" << std::endl);
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


void CVolumeSeg::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CVolumeSeg::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-a iValue] [-b]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -a  ..." << std::endl;
    Stream << "  -b  ..." << std::endl;
    Stream << std::endl;
    Stream << "Input: MDSTk volume" << std::endl;
    Stream << "Output: MDSTk volume" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CVolumeSegPtr spModule(new CVolumeSeg(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

