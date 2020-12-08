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
 * Date:    2004/05/08                       
 *
 * Description:
 * - Optical flow estimation and visualization module.
 */

#include "SliceOpticalFlow.h"

// MDSTk
#include <VPL/Image/Slice.h>
#include <VPL/Image/ImageFiltering.h>
#include <VPL/Image/OpticalFlow/LucasKanade.h>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION        = "Optical flow estimation and visualization module";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS          = "grid:levels";

//! Additional arguments
const std::string MODULE_ARGUMENT_GRID      = "grid";
const std::string MODULE_ARGUMENT_LEVELS    = "levels";

//! Default argument values
const int DEFAULT_GRID      = 10;
const int DEFAULT_LEVELS    = 1;

//! Maximal grid size
const int MAX_GRID          = 50;

//! Maximal image pyramid levels
const int MAX_LEVELS        = 4;


//==============================================================================
/*
 * Global variables.
 */

//! Temporary image pyramids
vpl::img::CDImagePyramidPtr spPyramid0, spPyramid1;

//! Pointer to the previously loaded slice
vpl::img::CDImagePyramidPtr spPrevious(spPyramid0);

//! Pointer to the current slice
vpl::img::CDImagePyramidPtr spCurrent(spPyramid1);


//==============================================================================
/*
 * Implementation of the class CSliceOpticalFlow.
 */
CSliceOpticalFlow::CSliceOpticalFlow(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceOpticalFlow::~CSliceOpticalFlow()
{
}


bool CSliceOpticalFlow::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Grid size parameter
    m_iGrid = DEFAULT_GRID;
    m_Arguments.value(MODULE_ARGUMENT_GRID, m_iGrid);
    if( m_iGrid <= 0 || m_iGrid > MAX_GRID )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad grid parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Pyramid levels parameter
    m_iLevels = DEFAULT_LEVELS;
    m_Arguments.value(MODULE_ARGUMENT_LEVELS, m_iLevels);
    if( m_iLevels <= 0 || m_iLevels > MAX_LEVELS )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad levels parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CSliceOpticalFlow::main()
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

    // Create a new slice
    vpl::img::CSlicePtr spSlice(new vpl::img::CSlice());
    vpl::img::CSlicePtr spFiltered(new vpl::img::CSlice());

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read slice from the input channel
        if( readInput(pIChannel, spSlice.get()) )
        {
            // Filter used for image preprocessing
//            vpl::img::CAvg5Filter<vpl::img::CDImage> Filter;
//            vpl::img::CGaussFilter<vpl::img::CDImage> Filter(7);

            vpl::img::CSobelX<vpl::img::CDImage, vpl::img::CMakeAbs> FilterX;
            vpl::img::CSobelY<vpl::img::CDImage, vpl::img::CMakeAbs> FilterY;

            // Preprocess the image
            spFiltered->resize(spSlice->getXSize(), spSlice->getYSize());
//            Filter(*spSlice, *spFiltered);
            FilterX(*spSlice, *spFiltered);

            vpl::img::CDImage Filtered2;
            Filtered2.resize(spSlice->getXSize(), spSlice->getYSize());
            FilterY(*spSlice, Filtered2);
            *spFiltered += Filtered2;

            // First slice of the sequence?
            if( spPrevious->getLevels() > 0 )
            {
                // Create image pyramids
                spCurrent->create(2, m_iLevels, *spFiltered);

                // Motion image size
                vpl::tSize XSize = vpl::math::getMin(spPrevious->getXSize(0), spCurrent->getXSize(0));
                vpl::tSize YSize = vpl::math::getMin(spPrevious->getYSize(0), spCurrent->getYSize(0));

                // Create an output slice
                vpl::img::CSlicePtr spMotion(new vpl::img::CSlice(XSize, YSize));
                spMotion->fillEntire(vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMin());

                // Point optical flow
//                vpl::img::COpticalFlow OptFlow(11);
//                vpl::img::COpticalFlow<vpl::img::CDImage> OptFlow(13);
//                vpl::img::COpticalFlow<vpl::img::CDImage> OptFlow(21);
                vpl::img::COpticalFlow<vpl::img::CDImage> OptFlow(13);

                // Compute optical flow between two consecutive slices
                vpl::tSize MaxX = XSize - m_iGrid;
                vpl::tSize MaxY = YSize - m_iGrid;
                for( vpl::tSize y = m_iGrid; y < MaxY; y += m_iGrid )
                {
                    OptFlow.getPosition().y() = vpl::img::tCoordinate(y);
                    for( vpl::tSize x = m_iGrid; x < MaxX; x += m_iGrid )
                    {
                        OptFlow.getPosition().x() = vpl::img::tCoordinate(x);
                        if( OptFlow.compute(*spPrevious, *spCurrent) )
                        {
                            OptFlow.visualize(*spMotion);
                        }
                    }
                }

                // Exchange the image pyramids
                vpl::img::CDImagePyramidPtr spPyramid(spPrevious);
                spPrevious = spCurrent;
                spCurrent = spPyramid;

                // Write it to the output channel
                if( !writeOutput(pOChannel, spMotion.get()) )
                {
                    VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
                }
            }
            else
            {
                // Create the image pyramid
                spPrevious->create(2, m_iLevels, *spFiltered);
            }
        }
    }
    else
    {
        VPL_LOG_INFO("Wait timeout");
    }

    // Returning 'true' means to continue processing the input channel
    return true;
}


void CSliceOpticalFlow::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSliceOpticalFlow::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage:" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -grid  Optical flow is estimated in points regular distributed over" << std::endl;
    Stream << "         a 2D mesh. The parameter specifies the range between" << std::endl;
    Stream << "         two neighbouring points in the mesh." << std::endl;
    Stream << std::endl;
    Stream << "  -levels  The number of levels of the used image pyramid. The" << std::endl;
    Stream << "           default value is " << DEFAULT_LEVELS << "." << std::endl;
    Stream << std::endl;
    Stream << "Input: MDSTk slice" << std::endl;
    Stream << "Output: MDSTk slice" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CSliceOpticalFlowPtr spModule(new CSliceOpticalFlow(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

