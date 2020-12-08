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
 * Date:    2004/08/19                       
 *
 * File description:
 * - Simple voxel value thresholding.
 */

#include "VolumeThresholding.h"

#include <VPL/Image/Slice.h>
#include <VPL/Image/DensityVolume.h>
#include <VPL/Image/VolumeFunctions.h>

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module provides a simple voxel value thresholding.";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "method:min:max:n";

// Additional arguments
const std::string MODULE_ARG_METHOD     = "method";
const std::string MODULE_ARG_MIN        = "min";
const std::string MODULE_ARG_MAX        = "max";
const std::string MODULE_ARG_N          = "n";

//! Default min and max values
const int DEFAULT_MIN   = vpl::img::CPixelTraits<vpl::img::CDensityVolume::tVoxel>::getPixelMin();
const int DEFAULT_MAX   = vpl::img::CPixelTraits<vpl::img::CDensityVolume::tVoxel>::getPixelMax();
const int DEFAULT_N     = 1;


//==============================================================================
/*
 * Implementation of the class CVolumeThresholding.
 */
CVolumeThresholding::CVolumeThresholding(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeThresholding::~CVolumeThresholding()
{
}


bool CVolumeThresholding::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Is the 'method' parameter given?
    if( !m_Arguments.exists(MODULE_ARG_METHOD) )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Method was not specified: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Type of thresholding
    m_Arguments.value(MODULE_ARG_METHOD, m_ssMethodName);

    // Parameter 'min'
    m_iMin = DEFAULT_MIN;
    m_Arguments.value(MODULE_ARG_MIN, m_iMin);
    if( m_iMin > DEFAULT_MAX || m_iMin < DEFAULT_MIN )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_MIN << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'max'
    m_iMax = DEFAULT_MAX;
    m_Arguments.value(MODULE_ARG_MAX, m_iMax);
    if( m_iMax < m_iMin || m_iMax > DEFAULT_MAX )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_MAX << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'n'
    m_iN = DEFAULT_N;
    m_Arguments.value(MODULE_ARG_N, m_iN);
    if( m_iN < 1 || m_iN > 100 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_N << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CVolumeThresholding::main()
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
            // Thresholding
            if( m_ssMethodName == std::string("minmax") )
            {
                vpl::img::tDensityPixel TMin = vpl::img::tDensityPixel(m_iMin);
                vpl::img::tDensityPixel TMax = vpl::img::tDensityPixel(m_iMax);

                spVolume->forEach(vpl::img::CMinMaxThresholding<vpl::img::tDensityPixel>(TMin, TMax));
            }
            else if( m_ssMethodName == std::string("maxpeakness") )
            {
                vpl::img::singleThresholding(*spVolume);
            }
            else if( m_ssMethodName == std::string("iterative") )
            {
                vpl::img::multiIterativeThresholding(*spVolume, m_iN);
            }
            else if( m_ssMethodName == std::string("otsu") )
            {
                vpl::img::singleOtsuThresholding(*spVolume);
            }
            else
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_METHOD << "' parameter value: type -h for help" << std::endl);
                printUsage();
                return false;
            }

            // Write it to the output channel
            if( !writeOutput(pOChannel, spVolume.get()) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output volume" << std::endl);
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


void CVolumeThresholding::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CVolumeThresholding::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-method sName] [-min iValue] [-max iValue] [-n uValue]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -method  Specifies a thresholding method. Allowed values are" << std::endl;
    Stream << "             minmax" << std::endl;
    Stream << "             maxpeakness" << std::endl;
    Stream << "             iterative" << std::endl;
    Stream << "             otsu" << std::endl;
    Stream << "           at present. See other documentation for details." << std::endl;
    Stream << std::endl;
    Stream << "  -min  Lower boundary of the tresholded interval." << std::endl;
    Stream << std::endl;
    Stream << "  -max  Higher interval boundary." << std::endl;
    Stream << std::endl;
    Stream << "  -n  Number of thresholds used by the iterative method." << std::endl;
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
    CVolumeThresholdingPtr spModule(new CVolumeThresholding(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

