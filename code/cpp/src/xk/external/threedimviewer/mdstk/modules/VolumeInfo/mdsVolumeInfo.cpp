//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/10                          \n
 *
 * $Id: mdsVolumeInfo.cpp 2102 2012-02-17 09:12:21Z spanel $
 *
 * File description:
 * - Shows information on input volume.
 */

#include "mdsVolumeInfo.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsDensityVolume.h>
#include <MDSTk/Image/mdsVolumeFunctions.h>

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
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeInfo::~CVolumeInfo()
{
}


bool CVolumeInfo::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // O.K.
    return true;
}


bool CVolumeInfo::main()
{
    // Note
    MDS_LOG_NOTE("Module main function");

    // I/O channels
    mds::mod::CChannel *pIChannel = getInput(0);
    mds::mod::CChannel *pOChannel = getOutput(0);

    // Is any input?
    if( !pIChannel->isConnected() )
    {
        return false;
    }

    // Create a new volume
    mds::img::CDensityVolumePtr spVolume;

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
                    mds::img::getMin<int>(*spVolume),
                    mds::img::getMax<int>(*spVolume),
                    mds::img::getMean<double>(*spVolume),
                    sqrt(mds::img::getVariance<double>(*spVolume))
                   );

            // Write it to the output channel
            if( !pOChannel->write(pcOut, mds::tSize(strlen(pcOut))) )
            {
                MDS_CERR('<' << m_sFilename << "> Failed to write the output" << std::endl);
                return false;
            }
        }
        else
        {
            MDS_CERR('<' << m_sFilename << "> Failed to read input volume" << std::endl);
            return false;
        }
    }
    else
    {
        MDS_LOG_NOTE("Wait timeout");
    }

    // Returning 'true' means to continue processing the input channel
    return true;
}


void CVolumeInfo::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CVolumeInfo::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Input: MDSTk volume" << std::endl);
    MDS_CERR("Output: text" << std::endl);
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

