//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/19                          \n
 *
 * $Id: mdsVolumeThresholding.cpp 2102 2012-02-17 09:12:21Z spanel $
 *
 * File description:
 * - Simple voxel value thresholding.
 */

#include "mdsVolumeThresholding.h"

#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsDensityVolume.h>
#include <MDSTk/Image/mdsVolumeFunctions.h>

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
const int DEFAULT_MIN   = mds::img::CPixelTraits<mds::img::CDensityVolume::tVoxel>::getPixelMin();
const int DEFAULT_MAX   = mds::img::CPixelTraits<mds::img::CDensityVolume::tVoxel>::getPixelMax();
const int DEFAULT_N     = 1;


//==============================================================================
/*
 * Implementation of the class CVolumeThresholding.
 */
CVolumeThresholding::CVolumeThresholding(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeThresholding::~CVolumeThresholding()
{
}


bool CVolumeThresholding::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Is the 'method' parameter given?
    if( !m_Arguments.exists(MODULE_ARG_METHOD) )
    {
        MDS_CERR('<' << m_sFilename << "> Method was not specified: type -h for help" << std::endl);
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
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_MIN << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'max'
    m_iMax = DEFAULT_MAX;
    m_Arguments.value(MODULE_ARG_MAX, m_iMax);
    if( m_iMax < m_iMin || m_iMax > DEFAULT_MAX )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_MAX << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'n'
    m_iN = DEFAULT_N;
    m_Arguments.value(MODULE_ARG_N, m_iN);
    if( m_iN < 1 || m_iN > 100 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_N << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CVolumeThresholding::main()
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
    mds::img::CDensityVolumePtr spVolume(new mds::img::CDensityVolume());

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read volume from the input channel
        if( readInput(pIChannel, spVolume.get()) )
        {
            // Thresholding
            if( m_ssMethodName == std::string("minmax") )
            {
                mds::img::tDensityPixel TMin = mds::img::tDensityPixel(m_iMin);
                mds::img::tDensityPixel TMax = mds::img::tDensityPixel(m_iMax);

                spVolume->forEach(mds::img::CMinMaxThresholding<mds::img::tDensityPixel>(TMin, TMax));
            }
            else if( m_ssMethodName == std::string("maxpeakness") )
            {
                mds::img::singleThresholding(*spVolume);
            }
            else if( m_ssMethodName == std::string("iterative") )
            {
                mds::img::multiIterativeThresholding(*spVolume, m_iN);
            }
            else if( m_ssMethodName == std::string("otsu") )
            {
                mds::img::singleOtsuThresholding(*spVolume);
            }
            else
            {
                MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_METHOD << "' parameter value: type -h for help" << std::endl);
                printUsage();
                return false;
            }

            // Write it to the output channel
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


void CVolumeThresholding::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CVolumeThresholding::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-method sName] [-min iValue] [-max iValue] [-n uValue]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -method  Specifies a thresholding method. Allowed values are" << std::endl);
    MDS_CERR("             minmax" << std::endl);
    MDS_CERR("             maxpeakness" << std::endl);
    MDS_CERR("             iterative" << std::endl);
    MDS_CERR("             otsu" << std::endl);
    MDS_CERR("           at present. See other documentation for details." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -min  Lower boundary of the tresholded interval." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -max  Higher interval boundary." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -n  Number of thresholds used by the iterative method." << std::endl);
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
    CVolumeThresholdingPtr spModule(new CVolumeThresholding(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

