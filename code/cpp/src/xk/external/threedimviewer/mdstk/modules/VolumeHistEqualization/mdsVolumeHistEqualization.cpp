//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/04/17                          \n
 *
 * $Id: mdsVolumeHistEqualization.cpp 2102 2012-02-17 09:12:21Z spanel $
 *
 * Description:
 * - Histogram equalization.
 */

#include "mdsVolumeHistEqualization.h"

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
#include <sstream>
#include <iomanip>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module equalizes histogram of input volume";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "";

//! Additional arguments

//! Default arguments values


//==============================================================================
/*
 * Implementation of the class CVolumeHistEqualization.
 */
CVolumeHistEqualization::CVolumeHistEqualization(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeHistEqualization::~CVolumeHistEqualization()
{
}


bool CVolumeHistEqualization::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line parameters

    // O.K.
    return true;
}


bool CVolumeHistEqualization::main()
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
            // Histogram equalization
            if( !mds::img::histogramEqualization(*spVolume) )
            {
                MDS_CERR('<' << m_sFilename << "> Cannot equalize the histogram" << std::endl);
                return false;
            }

            // Write volume to the output channel
            if( !writeOutput(pOChannel, spVolume.get()) )
            {
                MDS_CERR('<' << m_sFilename << "> Failed to write the output volume" << std::endl);
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


void CVolumeHistEqualization::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CVolumeHistEqualization::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Input: MDSTk volume" << std::endl);
    MDS_CERR("Output: MDSTk volume" << std::endl);
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CVolumeHistEqualizationPtr spModule(new CVolumeHistEqualization(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

