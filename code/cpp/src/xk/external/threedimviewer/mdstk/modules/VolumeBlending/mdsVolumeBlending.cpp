//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/06/14                          \n
 *
 * $Id: mdsVolumeBlending.cpp 2102 2012-02-17 09:12:21Z spanel $
 *
 * File description:
 * - Blending of two volumes into one.
 */

#include "mdsVolumeBlending.h"

// MDSTk
#include <MDSTk/Image/mdsDensityVolume.h>

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description.
const std::string MODULE_DESCRIPTION    = "Module for blending of two volumes";

//! Additional command line arguments.
const std::string MODULE_ARGUMENTS      = "alpha";

//! Additional arguments.
const std::string MODULE_ARGUMENT_ALPHA = "alpha";

//! Default values.
const double DEFAULT_ALPHA              = 0.5;

//! Minimal and maximal values.
const double ALPHA_MIN                  = 0.0;
const double ALPHA_MAX                  = 1.0;


//==============================================================================
/*
 * Implementation of the class CVolumeBlending.
 */
CVolumeBlending::CVolumeBlending(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeBlending::~CVolumeBlending()
{
}


bool CVolumeBlending::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 2 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Parameters
    m_dAlpha = DEFAULT_ALPHA;
    m_Arguments.value(MODULE_ARGUMENT_ALPHA, m_dAlpha);
    if( m_dAlpha > ALPHA_MAX || m_dAlpha < ALPHA_MIN )
    {
        MDS_CERR('<' << m_sFilename << "> Bad " << MODULE_ARGUMENT_ALPHA << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CVolumeBlending::main()
{
    // Note
    MDS_LOG_NOTE("Module main function");

    // I/O channels
    mds::mod::CChannel *pIChannel = getInput(0);
    mds::mod::CChannel *pOChannel = getOutput(0);

    // Create a new volume
    mds::img::CDensityVolume Volume1;

    // Is any input?
    if( !pIChannel->isConnected() )
    {
        return false;
    }

    // Wait for data
    if( !pIChannel->wait(1000) )
    {
        MDS_LOG_NOTE("Wait timeout");
        return true;
    }

    // Read volume from the input channel
    if( !readInput(pIChannel, &Volume1) )
    {
        MDS_CERR('<' << m_sFilename << "> Failed to read input volume" << std::endl);
        return false;
    }

    // I/O channels
    pIChannel = getInput(1);

    // Create a new volume
    mds::img::CDensityVolume Volume2;

    // Is any input?
    if( !pIChannel->isConnected() )
    {
        return false;
    }

    // Wait for data
    if( !pIChannel->wait(1000) )
    {
        MDS_LOG_NOTE("Wait timeout");
        return true;
    }

    // Read second volume from the input channel
    if( !readInput(pIChannel, &Volume2) )
    {
        MDS_CERR('<' << m_sFilename << "> Failed to read input volume" << std::endl);
        return false;
    }

    // Estimate overlapping part of both volumes
    mds::tSize XCount = mds::math::getMin(Volume1.getXSize(), Volume2.getXSize());
    mds::tSize YCount = mds::math::getMin(Volume1.getYSize(), Volume2.getYSize());
    mds::tSize ZCount = mds::math::getMin(Volume1.getZSize(), Volume2.getZSize());

    // Blending
    double dInvAlpha = 1.0 - m_dAlpha;
    for( mds::tSize k = 0; k < ZCount; ++k )
    {
        for( mds::tSize j = 0; j < YCount; ++j )
        {
            for( mds::tSize i = 0; i < XCount; ++i )
            {
                double dResult = m_dAlpha * Volume1(i,j,k) + dInvAlpha * Volume2(i,j,k);
                Volume1(i,j,k) = mds::img::tDensityPixel(dResult);
            }
        }
    }

    // Write the result to the output channel
    if( !writeOutput(pOChannel, &Volume1) )
    {
        MDS_CERR('<' << m_sFilename << "> Failed to write the output volume" << std::endl);
        return false;
    }

    // Terminate the processing
    return false;
}


void CVolumeBlending::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CVolumeBlending::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-alpha dValue]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -alpha  Blending ratio. Values in the range <" << ALPHA_MIN << ", " << ALPHA_MAX << "> are allowed." << std::endl);
    MDS_CERR("          Default value is " << DEFAULT_ALPHA << '.' << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("Input: two MDSTk volumes in separate channels" << std::endl);
    MDS_CERR("Output: MDSTk volume" << std::endl);
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CVolumeBlendingPtr spModule(new CVolumeBlending(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

