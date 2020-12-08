//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)            \n
 * Copyright (c) 2003-2009 by Michal Spanel             \n
 *
 * Authors: Jiri Zahradka, xzahra14@stud.fit.vutbr.cz   \n
 *          Michal Spanel, spanel@fit.vutbr.cz          \n
 * Date:    2008/01/06                                  \n
 *
 * $Id: mdsSliceSegWatersheds.cpp 2101 2012-02-17 08:20:21Z spanel $
 *
 * File description:
 * - Image segmentation using the watershed transform and subsequent
 *   region merging.
 */

#include "mdsSliceSegWatersheds.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/Watersheds/mdsWatershedTransform.h>
#include <MDSTk/Image/Watersheds/mdsRegionMerging.h>
#include <MDSTk/Image/mdsImageFunctions.h>
#include <MDSTk/Image/mdsImageFiltering.h>

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
    : mds::mod::CModule(sDescription)
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
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line arguments
    m_dSimThreshold = mds::img::RegionMerging::DEFAULT_SIMILARITY_THRESHOLD;
    m_Arguments.value(MODULE_ARG_SIMTHR, m_dSimThreshold);
    if( m_dSimThreshold < 0 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIMTHR << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dSimRatio = mds::img::RegionMerging::DEFAULT_SIMILARITY_RATIO;
    m_Arguments.value(MODULE_ARG_SIMRATIO, m_dSimRatio);
    if( m_dSimRatio < 0 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIMTHR << "' parameter value: type -h for help" << std::endl);
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
    MDS_LOG_NOTE("Module main function");

    // I/O channels
    mds::mod::CChannel *pIChannel = getInput(0);
    mds::mod::CChannel *pOChannel = getOutput(0);

    // Is any input?
    if( !pIChannel->isConnected() )
    {
        return false;
    }

    // Create a new slice
    mds::img::CSlice Slice;

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read slice from the input channel
        if( readInput(pIChannel, &Slice) )
        {
            // Fill image margin to prevent artifacts
            Slice.mirrorMargin();

            // Image size
            mds::tSize XSize = Slice.getXSize();
            mds::tSize YSize = Slice.getYSize();
            mds::tSize Margin = Slice.getMargin();

            // Edge images
            mds::img::CDImage EdgeImage(XSize, YSize, Margin);
            mds::img::CDImage AuxImage(XSize, YSize, Margin);
            EdgeImage.fillEntire(0);
            AuxImage.fillEntire(0);

            // Edge detection
            mds::img::CSobelX<mds::img::CDImage, mds::img::CMakeAbs> SobelX;
            SobelX(Slice, EdgeImage);

            mds::img::CSobelY<mds::img::CDImage, mds::img::CMakeAbs> SobelY;
            SobelY(Slice, AuxImage);

            static const mds::img::tDensityPixel THRESHOLD = 50;

            // Combine derivatives in X and Y axes
            for( mds::tSize j = 0; j < YSize; ++j )
            {
                for( mds::tSize i = 0; i < XSize; ++i )
                {
//                    mds::img::tDensityPixel Value = mds::math::getMax(EdgeImage(i, j), AuxImage(i, j));
                    mds::img::tDensityPixel Value = EdgeImage(i, j) + AuxImage(i, j);
                    EdgeImage(i, j) = (Value > THRESHOLD) ? Value : 0;
                }
            }

            // Create an output image
            mds::img::CImage32 Segmented(XSize, YSize, Margin);
            Segmented.fillEntire(0);

            // Image segmentation method
            mds::img::CWatershedTransform<mds::img::CDImage> Transform;
            if( m_bWatershedsOnly && !m_bMerge )
            {
               Transform.setOptions(mds::img::WatershedTransform::WATERSHEDS);
            }

            // Watershed transform
            if( !Transform(EdgeImage, Segmented) )
            {
                MDS_CERR('<' << m_sFilename << "> Watershed transform has failed" << std::endl);
                return false;
            }

            // Region merging
            if( m_bMerge )
            {
                mds::img::CRegionMerging<mds::img::CDImage, mds::img::CMeanValueSimilarity> Merging;
//                mds::img::CRegionMerging<mds::img::CDImage, mds::img::CVarianceSimilarity> Merging;
                Merging.setSimilarityThreshold(m_dSimThreshold);
                Merging.setSimilarityRatio(m_dSimRatio);
                if( !Merging(Slice, Segmented) )
                {
                    MDS_CERR('<' << m_sFilename << "> Region merging has failed" << std::endl);
                    return false;
                }
            }

//            static const mds::img::tPixel32 Min = 0;
            static const mds::img::tPixel32 Max = mds::img::tPixel32(mds::CTypeTraits<mds::img::tDensityPixel>::getMax());

            // Check the number of output regions
            mds::img::tPixel32 MaxValue = mds::img::getMax<mds::img::tPixel32>(Segmented);
            MDS_LOG_NOTE("Number of regions = " << MaxValue);
            if( MaxValue > Max )
            {
                MDS_CERR('<' << m_sFilename << "> Region label exceeds the maximum allowed pixel value" << std::endl);
            }

            // Create an output slice
            for( mds::tSize j = 0; j < YSize; ++j )
            {
                for( mds::tSize i = 0; i < XSize; ++i )
                {
                    Slice(i, j) = mds::img::tDensityPixel(mds::math::getMin(Max, Segmented(i, j)));
                }
            }

            // Write the result to the output channel
            if( !writeOutput(pOChannel, &Slice) )
            {
                MDS_CERR('<' << m_sFilename << "> Failed to write the segmented slice" << std::endl);
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


void CSliceSegWatersheds::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceSegWatersheds::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-wsheds] [-merge]" << std::endl);
    MDS_CERR("                [-simthr dValue] [-simratio dValue]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -wsheds  The module calculates watershed transform only. The output image" << std::endl);
    MDS_CERR("           will contain ones in place of boundaries between two adjacent" << std::endl);
    MDS_CERR("           catchment basins (= watersheds) and zeros elsewhere." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -merge  Enables region merging phase based on a similarity of two regions." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -simthr  Minimum required similarity of two regions going to be merged." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -simratio  Maximum allowed ratio of the maximal similarity in the current" << std::endl);
    MDS_CERR("             step and the minimal similarity observed during previous" << std::endl);
    MDS_CERR("             merging steps." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("Input: MDSTk slice" << std::endl);
    MDS_CERR("Output: MDSTk slice" << std::endl);
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

