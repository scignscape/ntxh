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
 * Copyright (c) 2003-2006 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/06/14                       
 *
 * File description:
 * - Blending of two volumes into one.
 */

#include "VolumeBlending.h"

// MDSTk
#include <VPL/Image/DensityVolume.h>

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
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeBlending::~CVolumeBlending()
{
}


bool CVolumeBlending::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 2 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Parameters
    m_dAlpha = DEFAULT_ALPHA;
    m_Arguments.value(MODULE_ARGUMENT_ALPHA, m_dAlpha);
    if( m_dAlpha > ALPHA_MAX || m_dAlpha < ALPHA_MIN )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad " << MODULE_ARGUMENT_ALPHA << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CVolumeBlending::main()
{
    // Note
    VPL_LOG_INFO("Module main function");

    // I/O channels
    vpl::mod::CChannel *pIChannel = getInput(0);
    vpl::mod::CChannel *pOChannel = getOutput(0);

    // Create a new volume
    vpl::img::CDensityVolume Volume1;

    // Is any input?
    if( !pIChannel->isConnected() )
    {
        return false;
    }

    // Wait for data
    if( !pIChannel->wait(1000) )
    {
        VPL_LOG_INFO("Wait timeout");
        return true;
    }

    // Read volume from the input channel
    if( !readInput(pIChannel, &Volume1) )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input volume" << std::endl);
        return false;
    }

    // I/O channels
    pIChannel = getInput(1);

    // Create a new volume
    vpl::img::CDensityVolume Volume2;

    // Is any input?
    if( !pIChannel->isConnected() )
    {
        return false;
    }

    // Wait for data
    if( !pIChannel->wait(1000) )
    {
        VPL_LOG_INFO("Wait timeout");
        return true;
    }

    // Read second volume from the input channel
    if( !readInput(pIChannel, &Volume2) )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input volume" << std::endl);
        return false;
    }

    // Estimate overlapping part of both volumes
    vpl::tSize XCount = vpl::math::getMin(Volume1.getXSize(), Volume2.getXSize());
    vpl::tSize YCount = vpl::math::getMin(Volume1.getYSize(), Volume2.getYSize());
    vpl::tSize ZCount = vpl::math::getMin(Volume1.getZSize(), Volume2.getZSize());

    // Blending
    double dInvAlpha = 1.0 - m_dAlpha;
    for( vpl::tSize k = 0; k < ZCount; ++k )
    {
        for( vpl::tSize j = 0; j < YCount; ++j )
        {
            for( vpl::tSize i = 0; i < XCount; ++i )
            {
                double dResult = m_dAlpha * Volume1(i,j,k) + dInvAlpha * Volume2(i,j,k);
                Volume1(i,j,k) = vpl::img::tDensityPixel(dResult);
            }
        }
    }

    // Write the result to the output channel
    if( !writeOutput(pOChannel, &Volume1) )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output volume" << std::endl);
        return false;
    }

    // Terminate the processing
    return false;
}


void CVolumeBlending::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CVolumeBlending::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-alpha dValue]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -alpha  Blending ratio. Values in the range <" << ALPHA_MIN << ", " << ALPHA_MAX << "> are allowed." << std::endl;
    Stream << "          Default value is " << DEFAULT_ALPHA << '.' << std::endl;
    Stream << std::endl;
    Stream << "Input: two MDSTk volumes in separate channels" << std::endl;
    Stream << "Output: MDSTk volume" << std::endl;
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

