//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)     \n
 * Copyright (c) 2003-2005 by Michal Spanel      \n
 *
 * Author:   Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:     2005/01/25                          \n
 *
 * File description:
 * - Sample volume segmentation module.
 */

#include "mdsVolumeSeg.h"
#include "mdsSegMethod.h"

// MDSTk
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
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeSeg::~CVolumeSeg()
{
}


bool CVolumeSeg::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line argument - a
    // - sample code
    m_iA = DEFAULT_A;
    m_Arguments.value(MODULE_ARGUMENT_A, m_iA);
    if( m_iA > 100 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'a' parameter value: type -h for help" << std::endl);
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
        // Read slice from the input channel
        if( readInput(pIChannel, spVolume.get()) )
        {
            // Create a new volume
            // - copy of the input one
            mds::img::CDensityVolumePtr spSegmented(new mds::img::CDensityVolume(*spVolume));

            // Volume segmentation method
            mds::volseg::CSegMethod Method;

            // Method initialization
            // - sample code
            if( !Method.init() )
            {
                MDS_CERR('<' << m_sFilename << "> Cannot initialize volume segmentation method" << std::endl);
            }
            else if( !Method(*spVolume, *spSegmented) )
            {
                MDS_CERR('<' << m_sFilename << "> Cannot process volume segmentation" << std::endl);
            }

            // Write the result to the output channel
            if( !writeOutput(pOChannel, spSegmented.get()) )
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


void CVolumeSeg::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CVolumeSeg::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-a iValue] [-b]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -a  ..." << std::endl);
    MDS_CERR("  -b  ..." << std::endl);
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
    CVolumeSegPtr spModule(new CVolumeSeg(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

