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
 * Date:    2004/08/10                       
 *
 * File description:
 * - Shows information on input volume.
 */

#include "VolumeInfo.h"

// MDSTk
#include <VPL/Image/Slice.h>
#include <VPL/Image/DensityVolume.h>
#include <VPL/Image/VolumeFunctions.h>

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

//! Module description
const std::string MODULE_DESCRIPTION    = "Module shows information on input volume data";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "";


//==============================================================================
/*
 * Implementation of the class CVolumeInfo.
 */
CVolumeInfo::CVolumeInfo(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeInfo::~CVolumeInfo()
{
}


bool CVolumeInfo::startup()
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


bool CVolumeInfo::main()
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
            // Create the output string
            char pcOut[1024];
            sprintf(pcOut,
                    "-- Information on volume data --\n"
                    " SizeX:      %d\n"
                    " SizeY:      %d\n"
                    " SizeZ:      %d\n"
                    " Voxel:      %.2f, %.2f, %.2f\n"
                    "-- Voxel values statistic --\n"
                    " Minimum:    %d\n"
                    " Maximum:    %d\n"
                    " Mean value: %.2f\n"
                    " Variance:   %.2f\n",
                    spVolume->getXSize(),
                    spVolume->getYSize(),
                    spVolume->getZSize(),
                    spVolume->getDX(),
                    spVolume->getDY(),
                    spVolume->getDZ(),
                    vpl::img::getMin<int>(*spVolume),
                    vpl::img::getMax<int>(*spVolume),
                    vpl::img::getMean<double>(*spVolume),
                    sqrt(vpl::img::getVariance<double>(*spVolume))
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


void CVolumeInfo::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CVolumeInfo::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Input: MDSTk volume" << std::endl;
    Stream << "Output: text" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CVolumeInfoPtr spModule(new CVolumeInfo(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

