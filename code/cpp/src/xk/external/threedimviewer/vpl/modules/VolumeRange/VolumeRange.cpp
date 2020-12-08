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
 * Date:    2004/08/10                       
 *
 * File description:
 * - Extends a given voxel value interval to the range 0..MAX.
 */

#include "VolumeRange.h"

// MDSTk
#include <VPL/Image/Slice.h>
#include <VPL/Image/DensityVolume.h>
#include <VPL/Image/VolumeFunctions.h>
#include <VPL/Image/PixelTraits.h>

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
const int DEFAULT_MIN   = vpl::img::CPixelTraits<vpl::img::CDensityVolume::tVoxel>::getPixelMin();
const int DEFAULT_MAX   = vpl::img::CPixelTraits<vpl::img::CDensityVolume::tVoxel>::getPixelMax();
const int ALLOWED_MIN   = -10000;
const int ALLOWED_MAX   = 10000;

//! Default final interval maximum
const int DEFAULT_FMIN  = vpl::img::CPixelTraits<vpl::img::tPixel8>::getPixelMin();
const int DEFAULT_FMAX  = vpl::img::CPixelTraits<vpl::img::tPixel8>::getPixelMax();


//==============================================================================
/*
 * Implementation of the class CVolumeRange.
 */
CVolumeRange::CVolumeRange(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
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
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Parameters 'min', 'max' and 'MAX'
    m_iMin = DEFAULT_MIN;
    m_Arguments.value(MODULE_ARGUMENT_MIN, m_iMin);
    if( m_iMin > ALLOWED_MAX || m_iMin < ALLOWED_MIN )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'min' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'max'
    m_iMax = DEFAULT_MAX;
    m_Arguments.value(MODULE_ARGUMENT_MAX, m_iMax);
    if( m_iMax < m_iMin || m_iMax > ALLOWED_MAX )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'max' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'MAX'
    m_iMAX = DEFAULT_FMAX;
    m_Arguments.value(MODULE_ARGUMENT_FMAX, m_iMAX);
    if( m_iMAX > ALLOWED_MAX )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'MAX' parameter value: type -h for help" << std::endl);
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
    vpl::img::CDensityVolumePtr spVolume;

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read volume from the input channel
        if( readInput(pIChannel, spVolume.get()) )
        {
            if( !m_bCopy )
            {
                // Input minimal and maximal voxel value
                vpl::img::CDensityVolume::tVoxel RMin, RMax;
                if( !m_bAuto )
                {
                    RMin = (vpl::img::CDensityVolume::tVoxel)m_iMin;
                    RMax = (vpl::img::CDensityVolume::tVoxel)m_iMax;
                }
                else
                {
                    RMin = vpl::img::getMin<vpl::img::CDensityVolume::tVoxel>(*spVolume);
                    RMax = vpl::img::getMax<vpl::img::CDensityVolume::tVoxel>(*spVolume);
                }

                // Output minimal and maximal voxel value
                vpl::img::CDensityVolume::tVoxel VMin = (vpl::img::CDensityVolume::tVoxel)DEFAULT_FMIN;
                vpl::img::CDensityVolume::tVoxel VMax = (vpl::img::CDensityVolume::tVoxel)m_iMAX;

                // Scaling factor
                double dScale = double(VMax - VMin) / double(RMax - RMin);

                // Convert all voxels
                for( vpl::img::CDensityVolume::tIterator it(*spVolume); it; ++it )
                {
                    vpl::img::CDensityVolume::tVoxel Value = *it;
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
                        *it = vpl::img::CDensityVolume::tVoxel(double(Value - RMin) * dScale + VMin);
                    }
                }
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


void CVolumeRange::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CVolumeRange::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-min iValue] [-max iValue] [-MAX iValue]" << std::endl;
    Stream << "                [-auto] [-copy]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -min  Lower boundary of interpolated interval." << std::endl;
    Stream << std::endl;
    Stream << "  -max  Higher interval boundary. The given interval is lineary" << std::endl;
    Stream << "        interpolated to the range 0..MAX. Default <min, max>" << std::endl;
    Stream << "        interval is <" << DEFAULT_MIN << ", " << DEFAULT_MAX << ">." << std::endl;
    Stream << std::endl;
    Stream << "  -MAX  Higher boundary of the final interval. Default value" << std::endl;
    Stream << "        is " << DEFAULT_FMAX << "." << std::endl;
    Stream << std::endl;
    Stream << "  -auto  Interval boundaries are estimated automatically." << std::endl;
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
    CVolumeRangePtr spModule(new CVolumeRange(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

