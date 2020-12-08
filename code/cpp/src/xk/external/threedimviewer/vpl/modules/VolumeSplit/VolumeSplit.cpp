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
 * Date:    2004/07/30                       
 *
 * File description:
 * - Splits an input volume into several slices.
 */

#include "VolumeSplit.h"

#include <VPL/Image/DensityVolume.h>

// STL
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module splits input volume into slices.";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "plane";

//! Additional arguments
const std::string MODULE_ARGUMENT_PLANE = "plane";

//! Allowed plane argument values
const std::string PLANE_XY_NAME         = "xy";
const std::string PLANE_XZ_NAME         = "xz";
const std::string PLANE_YZ_NAME         = "yz";

//! Default plane
const vpl::img::EPlane DEFAULT_PLANE    = vpl::img::PLANE_XY;


//==============================================================================
/*
 * Implementation of the class CVolumeSplit.
 */
CVolumeSplit::CVolumeSplit(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeSplit::~CVolumeSplit()
{
}


bool CVolumeSplit::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Get the plane parameter value
    m_ePlane = DEFAULT_PLANE;
    if( m_Arguments.exists(MODULE_ARGUMENT_PLANE) )
    {
        std::string sPlaneName;
        m_Arguments.value(MODULE_ARGUMENT_PLANE, sPlaneName);
        if( sPlaneName == PLANE_XY_NAME )
        {
            m_ePlane = vpl::img::PLANE_XY;
        }
        else if( sPlaneName == PLANE_XZ_NAME )
        {
            m_ePlane = vpl::img::PLANE_XZ;
        }
        else if( sPlaneName == PLANE_YZ_NAME )
        {
            m_ePlane = vpl::img::PLANE_YZ;
        }
        else
        {
            VPL_LOG_ERROR('<' << m_sFilename << "> Bad parameter value: type -h for help" << std::endl);
            printUsage();
            return false;
        }
    }

    // O.K.
    return true;
}


bool CVolumeSplit::main()
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
            // Get the number of slices and the size
            vpl::tSize sx = 0, sy = 0, Count = 0;
            double dx = 1.0, dy = 1.0, Thickness = 1.0;
            switch( m_ePlane )
            {
                case vpl::img::PLANE_XZ:
                    sx = spVolume->getXSize();
                    sy = spVolume->getZSize();
                    Count = spVolume->getYSize();
                    dx = spVolume->getDX();
                    dy = spVolume->getDZ();
                    Thickness = spVolume->getDY();
                    break;

                case vpl::img::PLANE_YZ:
                    sx = spVolume->getYSize();
                    sy = spVolume->getZSize();
                    Count = spVolume->getXSize();
                    dx = spVolume->getDY();
                    dy = spVolume->getDZ();
                    Thickness = spVolume->getDX();
                    break;

                default:
                    sx = spVolume->getXSize();
                    sy = spVolume->getYSize();
                    Count = spVolume->getZSize();
                    dx = spVolume->getDX();
                    dy = spVolume->getDY();
                    Thickness = spVolume->getDZ();
                    break;
            }

            // Slice of the volume
            vpl::img::CSlicePtr spSlice(new vpl::img::CSlice(sx, sy));
            spSlice->setPixel(dx, dy);
            spSlice->setThickness(Thickness);
            spSlice->setOrientation(m_ePlane);

            // Split the volume into slices
            for( vpl::tSize i = 0; i < Count; ++i )
            {
                // Get the slice data
                switch( m_ePlane )
                {
                    case vpl::img::PLANE_XZ:
                        spVolume->getPlaneXZ(i, *spSlice);
                        break;

                    case vpl::img::PLANE_YZ:
                        spVolume->getPlaneYZ(i, *spSlice);
                        break;

                    default:
                        spVolume->getPlaneXY(i, *spSlice);
                        break;
                }

                // Set the slice properties
                spSlice->setIndex(i);
                spSlice->setPosition(i * Thickness);

                // Write it to the output channel
                if( !writeOutput(pOChannel, spSlice.get()) )
                {
                    VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
                }
            }
        }
        else
        {
            VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input slice" << std::endl);
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


void CVolumeSplit::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CVolumeSplit::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-plane Orientation]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -plane  Parameter switches the plane used to cut the input" << std::endl;
    Stream << "          volume. Allowed values are:" << std::endl;
    Stream << "            " << PLANE_XY_NAME << std::endl;
    Stream << "            " << PLANE_XZ_NAME << std::endl;
    Stream << "            " << PLANE_YZ_NAME << std::endl;
    Stream << "          at present." << std::endl;
    Stream << std::endl;
    Stream << "Input: MDSTk volume" << std::endl;
    Stream << "Output: sequence of MDSTk slices" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CVolumeSplitPtr spModule(new CVolumeSplit(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

