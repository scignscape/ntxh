//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)           \n
 * Copyright (c) 2003-2005 by Michal Spanel            \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz         \n
 *          Miroslav Svub, xsvubm00@stud.fit.vutbr.cz  \n
 * Date:    2005/01/25                                 \n
 *
 * $Id: mdsVolumeSegHT.cpp 2102 2012-02-17 09:12:21Z spanel $
 *
 * File description:
 * - Simple segmentation method based on histogram thresholding.
 */

#include "mdsVolumeSegHT.h"
#include "mdsHistogramThresholding.h"

#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsDensityVolume.h>

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
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeSegHT::~CVolumeSegHT()
{
}


bool CVolumeSegHT::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line arguments
    m_iThresholds = DEFAULT_T;
    m_Arguments.value(MODULE_ARGUMENT_T, m_iThresholds);
    if( m_iThresholds < 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'tresholds' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_iColumns = DEFAULT_C;
    m_Arguments.value(MODULE_ARGUMENT_C, m_iColumns);
    if( m_iColumns < 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'columns' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CVolumeSegHT::main()
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
            // Create a new volume
            // - copy of the input one
            mds::img::CDensityVolume Segmented(*spVolume);

            // Volume segmentation method
            mds::volseg::CVolumeHistogramThresholding Method(m_iThresholds, m_iColumns);

            // Segmentation
            if( !Method(*spVolume, Segmented) )
            {
                MDS_CERR('<' << m_sFilename << "> Cannot process volume segmentation" << std::endl);
            }

            // Write the result to the output channel
            if( !writeOutput(pOChannel, &Segmented) )
            {
                MDS_CERR('<' << m_sFilename << "> Failed to write the segmented volume" << std::endl);
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


void CVolumeSegHT::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CVolumeSegHT::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-thresholds Value] [-hres Value]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -thresholds  The number of thresholds used for segmentation." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -bins  Histogram resolution. In other words, the number" << std::endl);
    MDS_CERR("         of columns/bins of the computed histogram." << std::endl);
    MDS_CERR(std::endl);
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
    CVolumeSegHTPtr spModule(new CVolumeSegHT(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

