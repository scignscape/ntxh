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
 * - Cuts a specified interval of voxels.
 */

#include "VolumeCut.h"

#include <VPL/Image/Slice.h>
#include <VPL/Image/DensityVolume.h>
#include <VPL/Math/Base.h>

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
const int DEFAULT_MIN       = vpl::img::CPixelTraits<vpl::img::CDensityVolume::tVoxel>::getPixelMin();
const int DEFAULT_MAX       = vpl::img::CPixelTraits<vpl::img::CDensityVolume::tVoxel>::getPixelMax();

const int DEFAULT_BORDER    = 0;

//! Allowed arguments values
const int MIN_BORDER        = 0;
const int MAX_BORDER        = 64;


//==============================================================================
/*
 * Implementation of the class CVolumeCut.
 */
CVolumeCut::CVolumeCut(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeCut::~CVolumeCut()
{
}


bool CVolumeCut::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Parameters 'min' and 'max'
    m_iMin = DEFAULT_MIN;
    m_Arguments.value(MODULE_ARG_MIN, m_iMin);
    if( m_iMin > DEFAULT_MAX || m_iMin < DEFAULT_MIN )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'min' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_iMax = DEFAULT_MAX;
    m_Arguments.value(MODULE_ARG_MAX, m_iMax);
    if( m_iMax < m_iMin || m_iMax > DEFAULT_MAX )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'max' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_iBorder = DEFAULT_BORDER;
    m_Arguments.value(MODULE_ARG_BORDER, m_iBorder);
    if( m_iBorder < MIN_BORDER || m_iBorder > MAX_BORDER )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad " << MODULE_ARG_BORDER << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CVolumeCut::main()
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
        // Read and process data from the input channel
        if( readInput(pIChannel, spVolume.get()) )
        {
            // Auxiliary volume
            vpl::img::CDensityVolume AuxVolume;

            if( m_iBorder > 0 )
            {
                // Enlarge the volume
                AuxVolume.vpl::img::CDVolume::resize(spVolume->getXSize() + 2 * m_iBorder,
                                                     spVolume->getYSize() + 2 * m_iBorder,
                                                     spVolume->getZSize() + 2 * m_iBorder
                                                     );
                AuxVolume.fillEntire(spVolume->at(0, 0, 0));
                vpl::img::CDVolume AuxVolume2(AuxVolume,
                                              m_iBorder,
                                              m_iBorder,
                                              m_iBorder,
                                              spVolume->getXSize(),
                                              spVolume->getYSize(),
                                              spVolume->getZSize(),
                                              vpl::REFERENCE
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
				vpl::math::limit<vpl::tSize>(m_iMinX, 0, spVolume->getXSize() - 1);
				vpl::math::limit<vpl::tSize>(m_iMaxX, m_iMinX, spVolume->getXSize() - 1);
				vpl::math::limit<vpl::tSize>(m_iMinY, 0, spVolume->getYSize() - 1);
				vpl::math::limit<vpl::tSize>(m_iMaxY, m_iMinY, spVolume->getYSize() - 1);
				vpl::math::limit<vpl::tSize>(m_iMinZ, 0, spVolume->getZSize() - 1);
				vpl::math::limit<vpl::tSize>(m_iMaxZ, m_iMinZ, spVolume->getZSize() - 1);

                // Create subvolume of the existing one
                AuxVolume.vpl::img::CDVolume::makeRef(*spVolume,
                                                      m_iMinX,
                                                      m_iMinY,
                                                      m_iMinZ,
                                                      m_iMaxX - m_iMinX + 1,
                                                      m_iMaxY - m_iMinY + 1,
                                                      m_iMaxZ - m_iMinZ + 1
                                                      );
            }

            // Set voxel properties
            AuxVolume.setDX(spVolume->getDX());
            AuxVolume.setDY(spVolume->getDY());
            AuxVolume.setDZ(spVolume->getDZ());

            // Cut the volume voxels
            AuxVolume.cut((vpl::img::CDensityVolume::tVoxel)m_iMin,
                          (vpl::img::CDensityVolume::tVoxel)m_iMax
                          );

            // Write it to the output channel
            if( !writeOutput(pOChannel, &AuxVolume) )
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

    // "Return true" means continue
    return true;
}


void CVolumeCut::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CVolumeCut::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-min iValue] [-max iValue]" << std::endl;
    Stream << "                [-minx iValue] [-maxx iValue]" << std::endl;
    Stream << "                [-miny iValue] [-maxy iValue]" << std::endl;
    Stream << "                [-minz iValue] [-maxz iValue]" << std::endl;
    Stream << "                [-border iValue]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -min  Lower boundary of the voxel value interval." << std::endl;
    Stream << "  -max  Higher interval boundary." << std::endl;
    Stream << std::endl;
    Stream << "  -minx, -maxx  Allows to create smaller sub-volume of the input" << std::endl;
    Stream << "  -miny, -maxy  volume. Minimal and maximal coordinates of voxels" << std::endl;
    Stream << "  -minz, -maxz  must be given." << std::endl;
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
    CVolumeCutPtr spModule(new CVolumeCut(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

