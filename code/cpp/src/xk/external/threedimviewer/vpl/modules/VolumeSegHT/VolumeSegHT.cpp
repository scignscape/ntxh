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
 * Author:  Michal Spanel, spanel@fit.vutbr.cz      
 *          Miroslav Svub, xsvubm00@stud.fit.vutbr.cz  \n
 * Date:    2005/01/25                              
 *
 * File description:
 * - Simple segmentation method based on histogram thresholding.
 */

#include "VolumeSegHT.h"
#include "HistogramThresholding.h"

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
const std::string MODULE_DESCRIPTION    = "Module providing a simple histogram thresholding segmentation";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "thresholds:bins";

//! Additional arguments
const std::string MODULE_ARGUMENT_T     = "thresholds";
const std::string MODULE_ARGUMENT_C     = "bins";

//! Default argument values
const int DEFAULT_T                     = 4;
const int DEFAULT_C                     = 64;


//==============================================================================
/*
 * Implementation of the class CVolumeSegHT.
 */
CVolumeSegHT::CVolumeSegHT(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeSegHT::~CVolumeSegHT()
{
}


bool CVolumeSegHT::startup()
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
    m_iThresholds = DEFAULT_T;
    m_Arguments.value(MODULE_ARGUMENT_T, m_iThresholds);
    if( m_iThresholds < 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'tresholds' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_iColumns = DEFAULT_C;
    m_Arguments.value(MODULE_ARGUMENT_C, m_iColumns);
    if( m_iColumns < 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'columns' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CVolumeSegHT::main()
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
        // Read volume from the input channel
        if( readInput(pIChannel, spVolume.get()) )
        {
            // Create a new volume
            // - copy of the input one
            vpl::img::CDensityVolume Segmented(*spVolume);

            // Volume segmentation method
            vpl::volseg::CVolumeHistogramThresholding Method(m_iThresholds, m_iColumns);

            // Segmentation
            if( !Method(*spVolume, Segmented) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Cannot process volume segmentation" << std::endl);
            }

            // Write the result to the output channel
            if( !writeOutput(pOChannel, &Segmented) )
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


void CVolumeSegHT::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CVolumeSegHT::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-thresholds Value] [-hres Value]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -thresholds  The number of thresholds used for segmentation." << std::endl;
    Stream << std::endl;
    Stream << "  -bins  Histogram resolution. In other words, the number" << std::endl;
    Stream << "         of columns/bins of the computed histogram." << std::endl;
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
    CVolumeSegHTPtr spModule(new CVolumeSegHT(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

