//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/10                          \n
 *
 * $Id: mdsVolumeRange.cpp 2102 2012-02-17 09:12:21Z spanel $
 *
 * File description:
 * - Extends a given voxel value interval to the range 0..MAX.
 */

#include "mdsVolumeRange.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsDensityVolume.h>
#include <MDSTk/Image/mdsVolumeFunctions.h>
#include <MDSTk/Image/mdsPixelTraits.h>

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module extends a given interval of voxel values to the range 0..MAX";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "min:max:MAX:auto:copy";

//! Additional arguments
const std::string MODULE_ARGUMENT_MIN   = "min";
const std::string MODULE_ARGUMENT_MAX   = "max";
const std::string MODULE_ARGUMENT_FMAX  = "MAX";
const std::string MODULE_ARGUMENT_AUTO  = "auto";
const std::string MODULE_ARGUMENT_COPY  = "copy";

//! Default 'min' and 'max' values
const int DEFAULT_MIN   = mds::img::CPixelTraits<mds::img::CDensityVolume::tVoxel>::getPixelMin();
const int DEFAULT_MAX   = mds::img::CPixelTraits<mds::img::CDensityVolume::tVoxel>::getPixelMax();
const int ALLOWED_MIN   = -10000;
const int ALLOWED_MAX   = 10000;

//! Default final interval maximum
const int DEFAULT_FMIN  = mds::img::CPixelTraits<mds::img::tPixel8>::getPixelMin();
const int DEFAULT_FMAX  = mds::img::CPixelTraits<mds::img::tPixel8>::getPixelMax();


//==============================================================================
/*
 * Implementation of the class CVolumeRange.
 */
CVolumeRange::CVolumeRange(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
    , m_bAuto(false)
    , m_bCopy(false)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeRange::~CVolumeRange()
{
}


bool CVolumeRange::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Parameters 'min', 'max' and 'MAX'
    m_iMin = DEFAULT_MIN;
    m_Arguments.value(MODULE_ARGUMENT_MIN, m_iMin);
    if( m_iMin > ALLOWED_MAX || m_iMin < ALLOWED_MIN )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'min' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'max'
    m_iMax = DEFAULT_MAX;
    m_Arguments.value(MODULE_ARGUMENT_MAX, m_iMax);
    if( m_iMax < m_iMin || m_iMax > ALLOWED_MAX )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'max' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'MAX'
    m_iMAX = DEFAULT_FMAX;
    m_Arguments.value(MODULE_ARGUMENT_FMAX, m_iMAX);
    if( m_iMAX > ALLOWED_MAX )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'MAX' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_bAuto = m_Arguments.exists(MODULE_ARGUMENT_AUTO);
    m_bCopy = m_Arguments.exists(MODULE_ARGUMENT_COPY);

    // O.K.
    return true;
}


bool CVolumeRange::main()
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
            if( !m_bCopy )
            {
                // Input minimal and maximal voxel value
                mds::img::CDensityVolume::tVoxel RMin, RMax;
                if( !m_bAuto )
                {
                    RMin = (mds::img::CDensityVolume::tVoxel)m_iMin;
                    RMax = (mds::img::CDensityVolume::tVoxel)m_iMax;
                }
                else
                {
                    RMin = mds::img::getMin<mds::img::CDensityVolume::tVoxel>(*spVolume);
                    RMax = mds::img::getMax<mds::img::CDensityVolume::tVoxel>(*spVolume);
                }

                // Output minimal and maximal voxel value
                mds::img::CDensityVolume::tVoxel VMin = (mds::img::CDensityVolume::tVoxel)DEFAULT_FMIN;
                mds::img::CDensityVolume::tVoxel VMax = (mds::img::CDensityVolume::tVoxel)m_iMAX;

                // Scaling factor
                double dScale = double(VMax - VMin) / double(RMax - RMin);

                // Convert all voxels
                for( mds::img::CDensityVolume::tIterator it(*spVolume); it; ++it )
                {
                    mds::img::CDensityVolume::tVoxel Value = *it;
                    if( Value > RMax )
                    {
                        *it = VMax;
                    }
                    else if( Value < RMin )
                    {
                        *it = VMin;
                    }
                    else
                    {
                        *it = mds::img::CDensityVolume::tVoxel(double(Value - RMin) * dScale + VMin);
                    }
                }
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


void CVolumeRange::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CVolumeRange::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-min iValue] [-max iValue] [-MAX iValue]" << std::endl);
    MDS_CERR("                [-auto] [-copy]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -min  Lower boundary of interpolated interval." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -max  Higher interval boundary. The given interval is lineary" << std::endl);
    MDS_CERR("        interpolated to the range 0..MAX. Default <min, max>" << std::endl);
    MDS_CERR("        interval is <" << DEFAULT_MIN << ", " << DEFAULT_MAX << ">." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -MAX  Higher boundary of the final interval. Default value" << std::endl);
    MDS_CERR("        is " << DEFAULT_FMAX << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -auto  Interval boundaries are estimated automatically." << std::endl);
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
    CVolumeRangePtr spModule(new CVolumeRange(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

