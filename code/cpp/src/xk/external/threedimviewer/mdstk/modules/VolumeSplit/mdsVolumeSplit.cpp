//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/07/30                          \n
 *
 * $Id: mdsVolumeSplit.cpp 2102 2012-02-17 09:12:21Z spanel $
 *
 * File description:
 * - Splits an input volume into several slices.
 */

#include "mdsVolumeSplit.h"

#include <MDSTk/Image/mdsDensityVolume.h>

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
const mds::img::EPlane DEFAULT_PLANE    = mds::img::PLANE_XY;


//==============================================================================
/*
 * Implementation of the class CVolumeSplit.
 */
CVolumeSplit::CVolumeSplit(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeSplit::~CVolumeSplit()
{
}


bool CVolumeSplit::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
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
            m_ePlane = mds::img::PLANE_XY;
        }
        else if( sPlaneName == PLANE_XZ_NAME )
        {
            m_ePlane = mds::img::PLANE_XZ;
        }
        else if( sPlaneName == PLANE_YZ_NAME )
        {
            m_ePlane = mds::img::PLANE_YZ;
        }
        else
        {
            MDS_CERR('<' << m_sFilename << "> Bad parameter value: type -h for help" << std::endl);
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
            // Get the number of slices and the size
            mds::tSize sx = 0, sy = 0, Count = 0;
            double dx = 1.0, dy = 1.0, Thickness = 1.0;
            switch( m_ePlane )
            {
                case mds::img::PLANE_XZ:
                    sx = spVolume->getXSize();
                    sy = spVolume->getZSize();
                    Count = spVolume->getYSize();
                    dx = spVolume->getDX();
                    dy = spVolume->getDZ();
                    Thickness = spVolume->getDY();
                    break;

                case mds::img::PLANE_YZ:
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
            mds::img::CSlicePtr spSlice(new mds::img::CSlice(sx, sy));
            spSlice->setPixel(dx, dy);
            spSlice->setThickness(Thickness);
            spSlice->setOrientation(m_ePlane);

            // Split the volume into slices
            for( mds::tSize i = 0; i < Count; ++i )
            {
                // Get the slice data
                switch( m_ePlane )
                {
                    case mds::img::PLANE_XZ:
                        spVolume->getPlaneXZ(i, *spSlice);
                        break;

                    case mds::img::PLANE_YZ:
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
                    MDS_CERR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
                }
            }
        }
        else
        {
            MDS_CERR('<' << m_sFilename << "> Failed to read input slice" << std::endl);
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


void CVolumeSplit::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CVolumeSplit::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-plane Orientation]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -plane  Parameter switches the plane used to cut the input" << std::endl);
    MDS_CERR("          volume. Allowed values are:" << std::endl);
    MDS_CERR("            " << PLANE_XY_NAME << std::endl);
    MDS_CERR("            " << PLANE_XZ_NAME << std::endl);
    MDS_CERR("            " << PLANE_YZ_NAME << std::endl);
    MDS_CERR("          at present." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("Input: MDSTk volume" << std::endl);
    MDS_CERR("Output: sequence of MDSTk slices" << std::endl);
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

