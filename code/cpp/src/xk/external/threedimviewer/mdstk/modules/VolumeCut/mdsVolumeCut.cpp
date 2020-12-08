//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/19                          \n
 *
 * $Id: mdsVolumeCut.cpp 2102 2012-02-17 09:12:21Z spanel $
 *
 * File description:
 * - Cuts a specified interval of voxels.
 */

#include "mdsVolumeCut.h"

#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsDensityVolume.h>
#include <MDSTk/Math/mdsBase.h>

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module cuts a given interval of voxels";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "min:max:minx:maxx:miny:maxy:minz:maxz:border";

//! Additional arguments
const std::string MODULE_ARG_MIN        = "min";
const std::string MODULE_ARG_MAX        = "max";
const std::string MODULE_ARG_MINX       = "minx";
const std::string MODULE_ARG_MAXX       = "maxx";
const std::string MODULE_ARG_MINY       = "miny";
const std::string MODULE_ARG_MAXY       = "maxy";
const std::string MODULE_ARG_MINZ       = "minz";
const std::string MODULE_ARG_MAXZ       = "maxz";
const std::string MODULE_ARG_BORDER     = "border";

//! Default arguments values
const int DEFAULT_MIN       = mds::img::CPixelTraits<mds::img::CDensityVolume::tVoxel>::getPixelMin();
const int DEFAULT_MAX       = mds::img::CPixelTraits<mds::img::CDensityVolume::tVoxel>::getPixelMax();

const int DEFAULT_BORDER    = 0;

//! Allowed arguments values
const int MIN_BORDER        = 0;
const int MAX_BORDER        = 64;


//==============================================================================
/*
 * Implementation of the class CVolumeCut.
 */
CVolumeCut::CVolumeCut(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeCut::~CVolumeCut()
{
}


bool CVolumeCut::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Parameters 'min' and 'max'
    m_iMin = DEFAULT_MIN;
    m_Arguments.value(MODULE_ARG_MIN, m_iMin);
    if( m_iMin > DEFAULT_MAX || m_iMin < DEFAULT_MIN )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'min' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_iMax = DEFAULT_MAX;
    m_Arguments.value(MODULE_ARG_MAX, m_iMax);
    if( m_iMax < m_iMin || m_iMax > DEFAULT_MAX )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'max' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_iBorder = DEFAULT_BORDER;
    m_Arguments.value(MODULE_ARG_BORDER, m_iBorder);
    if( m_iBorder < MIN_BORDER || m_iBorder > MAX_BORDER )
    {
        MDS_CERR('<' << m_sFilename << "> Bad " << MODULE_ARG_BORDER << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CVolumeCut::main()
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
        // Read and process data from the input channel
        if( readInput(pIChannel, spVolume.get()) )
        {
            // Auxiliary volume
            mds::img::CDensityVolume AuxVolume;

            if( m_iBorder > 0 )
            {
                // Enlarge the volume
                AuxVolume.mds::img::CDVolume::create(spVolume->getXSize() + 2 * m_iBorder,
                                                     spVolume->getYSize() + 2 * m_iBorder,
                                                     spVolume->getZSize() + 2 * m_iBorder
                                                     );
                AuxVolume.fillEntire(spVolume->at(0, 0, 0));
                mds::img::CDVolume AuxVolume2(AuxVolume,
                                              m_iBorder,
                                              m_iBorder,
                                              m_iBorder,
                                              spVolume->getXSize(),
                                              spVolume->getYSize(),
                                              spVolume->getZSize(),
                                              mds::REFERENCE
                                              );
                AuxVolume2 = *spVolume;
            }
            else
            {
                // Read additional parameters
                m_iMinX = 0;
                m_Arguments.value(MODULE_ARG_MINX, m_iMinX);
                m_iMaxX = spVolume->getXSize() - 1;
                m_Arguments.value(MODULE_ARG_MAXX, m_iMaxX);
                m_iMinY = 0;
                m_Arguments.value(MODULE_ARG_MINY, m_iMinY);
                m_iMaxY = spVolume->getYSize() - 1;
                m_Arguments.value(MODULE_ARG_MAXY, m_iMaxY);
                m_iMinZ = 0;
                m_Arguments.value(MODULE_ARG_MINZ, m_iMinZ);
                m_iMaxZ = spVolume->getZSize() - 1;
                m_Arguments.value(MODULE_ARG_MAXZ, m_iMaxZ);

                // Limit parameters
                mds::math::limit(m_iMinX, 0, spVolume->getXSize() - 1);
                mds::math::limit(m_iMaxX, m_iMinX, spVolume->getXSize() - 1);
                mds::math::limit(m_iMinY, 0, spVolume->getYSize() - 1);
                mds::math::limit(m_iMaxY, m_iMinY, spVolume->getYSize() - 1);
                mds::math::limit(m_iMinZ, 0, spVolume->getZSize() - 1);
                mds::math::limit(m_iMaxZ, m_iMinZ, spVolume->getZSize() - 1);

                // Create subvolume of the existing one
                AuxVolume.mds::img::CDVolume::create(*spVolume,
                                                     m_iMinX,
                                                     m_iMinY,
                                                     m_iMinZ,
                                                     m_iMaxX - m_iMinX + 1,
                                                     m_iMaxY - m_iMinY + 1,
                                                     m_iMaxZ - m_iMinZ + 1,
                                                     mds::REFERENCE
                                                     );
            }

            // Set voxel properties
            AuxVolume.setDX(spVolume->getDX());
            AuxVolume.setDY(spVolume->getDY());
            AuxVolume.setDZ(spVolume->getDZ());

            // Cut the volume voxels
            AuxVolume.cut((mds::img::CDensityVolume::tVoxel)m_iMin,
                          (mds::img::CDensityVolume::tVoxel)m_iMax
                          );

            // Write it to the output channel
            if( !writeOutput(pOChannel, &AuxVolume) )
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

    // "Return true" means continue
    return true;
}


void CVolumeCut::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CVolumeCut::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-min iValue] [-max iValue]" << std::endl);
    MDS_CERR("                [-minx iValue] [-maxx iValue]" << std::endl);
    MDS_CERR("                [-miny iValue] [-maxy iValue]" << std::endl);
    MDS_CERR("                [-minz iValue] [-maxz iValue]" << std::endl);
    MDS_CERR("                [-border iValue]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -min  Lower boundary of the voxel value interval." << std::endl);
    MDS_CERR("  -max  Higher interval boundary." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -minx, -maxx  Allows to create smaller sub-volume of the input" << std::endl);
    MDS_CERR("  -miny, -maxy  volume. Minimal and maximal coordinates of voxels" << std::endl);
    MDS_CERR("  -minz, -maxz  must be given." << std::endl);
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
    CVolumeCutPtr spModule(new CVolumeCut(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

