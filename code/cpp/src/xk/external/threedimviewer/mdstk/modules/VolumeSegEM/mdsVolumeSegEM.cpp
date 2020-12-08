//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)     \n
 * Copyright (c) 2003-2010 by Michal Spanel      \n
 *
 * Author:   Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:     2010/06/25                          \n
 *
 * File description:
 * - Sample volume segmentation module.
 */

#include "mdsVolumeSegEM.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsDensityVolume.h>
#include <MDSTk/Image/mdsHistogram.h>
#include <MDSTk/Image/FeatureExtraction/mdsFeatureVector.h>
#include <MDSTk/Image/Algorithm/mdsWeightedEM.h>
#include <MDSTk/Image/mdsArray.h>

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module provides segmentation algorithm based on the GMM+EM algorithm";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "clusters:mac";

//! Additional arguments names
const std::string MODULE_ARGUMENT_C     = "clusters";
const std::string MODULE_ARGUMENT_MAC   = "mac";

//! Default arguments values
const int DEFAULT_C                     = 0;
const double DEFAULT_MAC                = mds::math::MaxLikelihoodByEM::MIN_ADD_CHANGE;

//! Allowed arguments values
const int MIN_C                         = 0;
const int MAX_C                         = 32;


//==============================================================================
/*
 * Implementation of the class CVolumeSegEM.
 */
CVolumeSegEM::CVolumeSegEM(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeSegEM::~CVolumeSegEM()
{
}


bool CVolumeSegEM::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line argument 'clusters'
    m_iClusters = DEFAULT_C;
    m_Arguments.value(MODULE_ARGUMENT_C, m_iClusters);
    if( m_iClusters < MIN_C || m_iClusters > MAX_C )
    {
        MDS_CERR('<' << m_sFilename << "> Bad " << MODULE_ARGUMENT_C << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dMinAddChange = DEFAULT_MAC;
    m_Arguments.value(MODULE_ARGUMENT_MAC, m_dMinAddChange);
    if( m_dMinAddChange < 0.0 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad " << MODULE_ARGUMENT_MAC << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CVolumeSegEM::main()
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
        // Read slice from the input channel
        if( readInput(pIChannel, spVolume.get()) )
        {
            // Minimum and maximum density
            mds::img::CDensityVolume::tVoxel Min = mds::img::CPixelTraits<mds::img::CDensityVolume::tVoxel>::getPixelMin();
            mds::img::CDensityVolume::tVoxel Max = mds::img::CPixelTraits<mds::img::CDensityVolume::tVoxel>::getPixelMax();

            // Full histogram
            typedef mds::img::CFullHistogram<mds::img::CDensityVolume> tHistogram;
            tHistogram Histogram(Min, Max);
            if( !Histogram(*spVolume) )
            {
                MDS_CERR('<' << m_sFilename << "> Cannot compute histogram of the input volume" << std::endl);
                return false;
            }

            // Create an array of feature vectors
            typedef mds::img::CFeatureVector<double, 1> tFeature;
            typedef mds::img::CArray<tFeature> tFeatures;

            // Initialize all feature vectors
            tFeatures Features;
            Features.create(Histogram.getSize());
            for( mds::img::CDensityVolume::tVoxel value = Min; value <= Max; ++value )
            {
                mds::tSize j = Histogram.getIndex(value);
                Features(j).setFeature(0, double(value));
                Features(j).setNumOfSamples(Histogram.getCount(j));
                Features(j).setState(mds::img::FeatureVector::VALID);
            }

            // Image segmentation method
            mds::img::CWeightedEM<tFeatures, 1> Method;
            Method.setMinAddChange(m_dMinAddChange);

            // Clusterig...
            bool bDone = false;
            if( m_iClusters < 1 )
            {
                bDone = Method.execute(Features);
            }
            else
            {
                bDone = Method.execute(Features, m_iClusters);
            }
            if( !bDone )
            {
                MDS_CERR('<' << m_sFilename << "> Cannot process volume segmentation" << std::endl);
                return false;
            }

            // Create a new volume
            // - copy of the input one
            mds::img::CDensityVolumePtr spSegmented(new mds::img::CDensityVolume(*spVolume));

            // Classify voxels
            mds::img::CDensityVolume::tIterator it(*spSegmented);
            for( ; it; ++it )
            {
                // Find cluster whose membership function is maximal
                mds::tSize Max = Method.getMembership(Histogram.getIndex(*it));
                *it = mds::img::CDensityVolume::tVoxel(Max);
            }

            // Write the result to the output channel
            if( !writeOutput(pOChannel, spSegmented.get()) )
            {
                MDS_CERR('<' << m_sFilename << "> Failed to write the segmented volume" << std::endl);
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


void CVolumeSegEM::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CVolumeSegEM::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
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
    CVolumeSegEMPtr spModule(new CVolumeSegEM(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

