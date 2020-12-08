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
 * Copyright (c) 2003-2009 by Michal Spanel          
 *
 * Authors: Jiri Zahradka, xzahra14@stud.fit.vutbr.cz
 *          Michal Spanel, spanel@fit.vutbr.cz       
 * Date:    2008/01/06                               
 *
 * File description:
 * - Image segmentation using the watershed transform and subsequent
 *   region merging.
 */

#include "SliceSegWatersheds.h"

// MDSTk
#include <VPL/Image/Slice.h>
#include <VPL/Image/Watersheds/WatershedTransform.h>
#include <VPL/Image/Watersheds/RegionMerging.h>
#include <VPL/Image/ImageFunctions.h>
#include <VPL/Image/ImageFiltering.h>

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Image segmentation based on watershed transform.";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "wsheds:merge:simthr:simratio";

//! Additional arguments names
const std::string MODULE_ARG_WSHED      = "wsheds";
const std::string MODULE_ARG_MERGE      = "merge";
const std::string MODULE_ARG_SIMTHR     = "simthr";
const std::string MODULE_ARG_SIMRATIO   = "simratio";


//==============================================================================
/*
 * Implementation of the class CSliceSegWatersheds.
 */
CSliceSegWatersheds::CSliceSegWatersheds(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
    , m_bWatershedsOnly(false)
{
    // Allow additional command line arguments
    allowArguments(MODULE_ARGUMENTS);
}


CSliceSegWatersheds::~CSliceSegWatersheds()
{
}


bool CSliceSegWatersheds::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line arguments
    m_dSimThreshold = vpl::img::RegionMerging::DEFAULT_SIMILARITY_THRESHOLD;
    m_Arguments.value(MODULE_ARG_SIMTHR, m_dSimThreshold);
    if( m_dSimThreshold < 0 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIMTHR << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dSimRatio = vpl::img::RegionMerging::DEFAULT_SIMILARITY_RATIO;
    m_Arguments.value(MODULE_ARG_SIMRATIO, m_dSimRatio);
    if( m_dSimRatio < 0 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIMTHR << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_bWatershedsOnly = m_Arguments.exists(MODULE_ARG_WSHED);
    m_bMerge = m_Arguments.exists(MODULE_ARG_MERGE);

    // O.K.
    return true;
}


bool CSliceSegWatersheds::main()
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
    vpl::img::CSlice Slice;

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read slice from the input channel
        if( readInput(pIChannel, &Slice) )
        {
            // Fill image margin to prevent artifacts
            Slice.mirrorMargin();

            // Image size
            vpl::tSize XSize = Slice.getXSize();
            vpl::tSize YSize = Slice.getYSize();
            vpl::tSize Margin = Slice.getMargin();

            // Edge images
            vpl::img::CDImage EdgeImage(XSize, YSize, Margin);
            vpl::img::CDImage AuxImage(XSize, YSize, Margin);
            EdgeImage.fillEntire(0);
            AuxImage.fillEntire(0);

            // Edge detection
            vpl::img::CSobelX<vpl::img::CDImage, vpl::img::CMakeAbs> SobelX;
            SobelX(Slice, EdgeImage);

            vpl::img::CSobelY<vpl::img::CDImage, vpl::img::CMakeAbs> SobelY;
            SobelY(Slice, AuxImage);

            static const vpl::img::tDensityPixel THRESHOLD = 50;

            // Combine derivatives in X and Y axes
            for( vpl::tSize j = 0; j < YSize; ++j )
            {
                for( vpl::tSize i = 0; i < XSize; ++i )
                {
//                    vpl::img::tDensityPixel Value = vpl::math::getMax(EdgeImage(i, j), AuxImage(i, j));
                    vpl::img::tDensityPixel Value = EdgeImage(i, j) + AuxImage(i, j);
                    EdgeImage(i, j) = (Value > THRESHOLD) ? Value : 0;
                }
            }

            // Create an output image
            vpl::img::CImage32 Segmented(XSize, YSize, Margin);
            Segmented.fillEntire(0);

            // Image segmentation method
            vpl::img::CWatershedTransform<vpl::img::CDImage> Transform;
            if( m_bWatershedsOnly && !m_bMerge )
            {
               Transform.setOptions(vpl::img::WatershedTransform::WATERSHEDS);
            }

            // Watershed transform
            if( !Transform(EdgeImage, Segmented) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Watershed transform has failed" << std::endl);
                return false;
            }

            // Region merging
            if( m_bMerge )
            {
                vpl::img::CRegionMerging<vpl::img::CDImage, vpl::img::CMeanValueSimilarity> Merging;
//                vpl::img::CRegionMerging<vpl::img::CDImage, vpl::img::CVarianceSimilarity> Merging;
                Merging.setSimilarityThreshold(m_dSimThreshold);
                Merging.setSimilarityRatio(m_dSimRatio);
                if( !Merging(Slice, Segmented) )
                {
                    VPL_LOG_ERROR('<' << m_sFilename << "> Region merging has failed" << std::endl);
                    return false;
                }
            }

//            static const vpl::img::tPixel32 Min = 0;
            static const vpl::img::tPixel32 Max = vpl::img::tPixel32(vpl::CTypeTraits<vpl::img::tDensityPixel>::getMax());

            // Check the number of output regions
            vpl::img::tPixel32 MaxValue = vpl::img::getMax<vpl::img::tPixel32>(Segmented);
            VPL_LOG_INFO("Number of regions = " << MaxValue);
            if( MaxValue > Max )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Region label exceeds the maximum allowed pixel value" << std::endl);
            }

            // Create an output slice
            for( vpl::tSize j = 0; j < YSize; ++j )
            {
                for( vpl::tSize i = 0; i < XSize; ++i )
                {
                    Slice(i, j) = vpl::img::tDensityPixel(vpl::math::getMin(Max, Segmented(i, j)));
                }
            }

            // Write the result to the output channel
            if( !writeOutput(pOChannel, &Slice) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the segmented slice" << std::endl);
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


void CSliceSegWatersheds::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSliceSegWatersheds::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-wsheds] [-merge]" << std::endl;
    Stream << "                [-simthr dValue] [-simratio dValue]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -wsheds  The module calculates watershed transform only. The output image" << std::endl;
    Stream << "           will contain ones in place of boundaries between two adjacent" << std::endl;
    Stream << "           catchment basins (= watersheds) and zeros elsewhere." << std::endl;
    Stream << std::endl;
    Stream << "  -merge  Enables region merging phase based on a similarity of two regions." << std::endl;
    Stream << std::endl;
    Stream << "  -simthr  Minimum required similarity of two regions going to be merged." << std::endl;
    Stream << std::endl;
    Stream << "  -simratio  Maximum allowed ratio of the maximal similarity in the current" << std::endl;
    Stream << "             step and the minimal similarity observed during previous" << std::endl;
    Stream << "             merging steps." << std::endl;
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
    CSliceSegWatershedsPtr spModule(new CSliceSegWatersheds(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

