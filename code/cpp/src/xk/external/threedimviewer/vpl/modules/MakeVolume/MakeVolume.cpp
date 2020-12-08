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
 * 
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.c
 * Date:    2004/07/26                          \n
 *
 * File description:
 * - Module makes a volume from several input slices.
 */

#include "MakeVolume.h"

// VPL
#include <VPL/Image/Slice.h>
#include <VPL/Image/DensityVolume.h>

// STL
#include <vector>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module makes volume from several input slices.";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "border:bvalue";

//! Additional arguments names
const std::string MODULE_ARG_BORDER     = "border";
const std::string MODULE_ARG_BVALUE     = "bvalue";

//! Default arguments values
const int DEFAULT_BORDER                = 0;
const int DEFAULT_BVALUE                = vpl::img::CPixelTraits<vpl::img::CDVolume::tVoxel>::getPixelMin();

//! Allowed arguments values
const int MIN_BORDER                    = 0;
const int MAX_BORDER                    = 64;
const int MIN_BVALUE                    = vpl::img::CPixelTraits<vpl::img::CDVolume::tVoxel>::getPixelMin();
const int MAX_BVALUE                    = vpl::img::CPixelTraits<vpl::img::CDVolume::tVoxel>::getPixelMax();


//==============================================================================
/*
 * Type definitions.
 */

//! Vector of all input slices
typedef std::vector<vpl::img::CSlicePtr> tSlices;


//==============================================================================
/*
 * Global variables.
 */

//! Vector of all input slices
tSlices InputSlices;


//==============================================================================
/*
 * Implementation of the class CMakeVolume.
 */
CMakeVolume::CMakeVolume(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CMakeVolume::~CMakeVolume()
{
}


bool CMakeVolume::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    m_iBorder = DEFAULT_BORDER;
    m_Arguments.value(MODULE_ARG_BORDER, m_iBorder);
    if( m_iBorder < MIN_BORDER || m_iBorder > MAX_BORDER )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad " << MODULE_ARG_BORDER << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_iBorderValue = DEFAULT_BVALUE;
    m_Arguments.value(MODULE_ARG_BVALUE, m_iBorderValue);
    if( m_iBorderValue < MIN_BVALUE || m_iBorderValue > MAX_BVALUE )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad " << MODULE_ARG_BVALUE << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CMakeVolume::main()
{
    // Note
    VPL_LOG_INFO("Module main function");

    // I/O channels
    vpl::mod::CChannel *pIChannel = getInput(0);
    vpl::mod::CChannel *pOChannel = getOutput(0);

    // Is any input?
    if( !pIChannel->isConnected() )
    {
        // Smart pointer to a new volume
        vpl::img::CDensityVolumePtr spVolume;

        // Make volume and write it to the output channel
        if((spVolume->makeVolume(InputSlices) ))
        {
            if( !writeOutput(pOChannel, spVolume.get()) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output volume" << std::endl);
            }
        }
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
            // Push slice to the vector
            InputSlices.push_back(spSlice);
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


void CMakeVolume::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");

    // Clear input slices
    InputSlices.clear();
}


void CMakeVolume::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-border uValue] [-bvalue iValue]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -border  Size of the volume margin in voxels." << std::endl;
    Stream << "           Values in the range <" << MIN_BORDER << ", " << MAX_BORDER << "> can be given." << std::endl;
    Stream << std::endl;
    Stream << "  -bvalue  Voxel value used to fill the margin." << std::endl;
    Stream << "           Allowed voxel range is <" << MIN_BVALUE << ", " << MAX_BVALUE << ">." << std::endl;
    Stream << std::endl;
    Stream << "Input: sequence of MDSTk slices" << std::endl;
    Stream << "Output: MDSTk volume" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CMakeVolumePtr spModule(new CMakeVolume(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

