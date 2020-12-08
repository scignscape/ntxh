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
 * Author:   Michal Spanel, spanel@fit.vutbr.cz        
 *           Martin Skotnica, xskotn01@stud.fit.vutbr.cz  \n
 * Date:     2005/01/25                                
 *
 * File description:
 * - Simple region growing slice segmentation
 */

#include "VolumeSegRG.h"
#include "RegionGrowing.h"

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
const std::string MODULE_DESCRIPTION    = "Module providing a simple region growing segmentation";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "wdiff:wedge:t:merge";

//! Additional arguments
const std::string MODULE_ARGUMENT_WD    = "wdiff";
const std::string MODULE_ARGUMENT_WE    = "wedge";
const std::string MODULE_ARGUMENT_T     = "t";
const std::string MODULE_ARGUMENT_M     = "merge";

//! Default argument values
const double DEFAULT_WD                 = 1.0;
const double DEFAULT_WE                 = 0.0;
const int DEFAULT_T                     = 300;


//==============================================================================
/*
 * Implementation of the class CVolumeSegRG.
 */
CVolumeSegRG::CVolumeSegRG(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeSegRG::~CVolumeSegRG()
{
}


bool CVolumeSegRG::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line arguments
    m_iThreshold = DEFAULT_T;
    m_Arguments.value(MODULE_ARGUMENT_T, m_iThreshold);
    if( m_iThreshold < 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARGUMENT_T << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dWeightDiff = DEFAULT_WD;
    m_Arguments.value(MODULE_ARGUMENT_WD, m_dWeightDiff);
    if( m_dWeightDiff < 0.0 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dWeightEdge = DEFAULT_WE;
    m_Arguments.value(MODULE_ARGUMENT_WE, m_dWeightEdge);
    if( m_dWeightEdge < 0.0 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_bMerge = m_Arguments.exists(MODULE_ARGUMENT_M);

    // O.K.
    return true;
}


bool CVolumeSegRG::main()
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
    vpl::img::CDensityVolumePtr spVolume(new vpl::img::CDensityVolume());

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read volume from the input channel
        if( readInput(pIChannel, spVolume.get()) )
        {
            // Create a new volume
            // - copy of the input one
            vpl::img::CDensityVolumePtr spSegmented(new vpl::img::CDensityVolume(*spVolume));

            // Volume segmentation method
            vpl::volseg::CVolumeRegionGrowing Method(m_dWeightDiff,
                                                     m_dWeightEdge,
                                                     m_iThreshold,
                                                     m_bMerge
                                                     );

            // Segmentation
            if( !Method(*spVolume, *spSegmented) )
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


void CVolumeSegRG::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CVolumeSegRG::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-t uValue] [-wdiff dValue] [-wedge dValue] [-merge]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -t  Threshold used for adding voxels to a region." << std::endl;
    Stream << std::endl;
    Stream << "  -wdiff  Weight of the distance component of a voxel similarity measure." << std::endl;
    Stream << std::endl;
    Stream << "  -wedge  Weight of the image edge component of the measure." << std::endl;
    Stream << std::endl;
    Stream << "  -merge  Enables merging of produced regions." << std::endl;
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
    CVolumeSegRGPtr spModule(new CVolumeSegRG(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

