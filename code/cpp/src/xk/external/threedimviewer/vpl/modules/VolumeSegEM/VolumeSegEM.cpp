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
 * Copyright (c) 2003-2010 by Michal Spanel   
 *
 * Author:   Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:     2010/06/25                       
 *
 * File description:
 * - Sample volume segmentation module.
 */

#include "VolumeSegEM.h"

#include <VPL/Image/Slice.h>
#include <VPL/Image/DensityVolume.h>
#include <VPL/Image/Histogram.h>
#include <VPL/Image/FeatureExtraction/FeatureVector.h>
#include <VPL/Image/Algorithm/WeightedEM.h>
#include <VPL/Base/Array.h>

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
const double DEFAULT_MAC                = vpl::math::MaxLikelihoodByEM::MIN_ADD_CHANGE;

//! Allowed arguments values
const int MIN_C                         = 0;
const int MAX_C                         = 32;


//==============================================================================
/*
 * Implementation of the class CVolumeSegEM.
 */
CVolumeSegEM::CVolumeSegEM(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeSegEM::~CVolumeSegEM()
{
}


bool CVolumeSegEM::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line argument 'clusters'
    m_iClusters = DEFAULT_C;
    m_Arguments.value(MODULE_ARGUMENT_C, m_iClusters);
    if( m_iClusters < MIN_C || m_iClusters > MAX_C )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad " << MODULE_ARGUMENT_C << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dMinAddChange = DEFAULT_MAC;
    m_Arguments.value(MODULE_ARGUMENT_MAC, m_dMinAddChange);
    if( m_dMinAddChange < 0.0 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad " << MODULE_ARGUMENT_MAC << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CVolumeSegEM::main()
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
        // Read slice from the input channel
        if( readInput(pIChannel, spVolume.get()) )
        {
            // Minimum and maximum density
            vpl::img::CDensityVolume::tVoxel Min = vpl::img::CPixelTraits<vpl::img::CDensityVolume::tVoxel>::getPixelMin();
            vpl::img::CDensityVolume::tVoxel Max = vpl::img::CPixelTraits<vpl::img::CDensityVolume::tVoxel>::getPixelMax();

            // Full histogram
            typedef vpl::img::CFullHistogram<vpl::img::CDensityVolume> tHistogram;
            tHistogram Histogram(Min, Max);
            if( !Histogram(*spVolume) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Cannot compute histogram of the input volume" << std::endl);
                return false;
            }

            // Create an array of feature vectors
            typedef vpl::img::CFeatureVector<double, 1> tFeature;
            typedef vpl::base::CArray<tFeature> tFeatures;

            // Initialize all feature vectors
            tFeatures Features;
            Features.resize(Histogram.getSize());
            for( vpl::img::CDensityVolume::tVoxel value = Min; value <= Max; ++value )
            {
                vpl::tSize j = Histogram.getIndex(value);
                Features(j).setFeature(0, double(value));
                Features(j).setNumOfSamples(Histogram.getCount(j));
                Features(j).setState(vpl::img::FeatureVector::VALID);
            }

            // Image segmentation method
            vpl::img::CWeightedEM<tFeatures, 1> Method;
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
                VPL_LOG_ERROR('<' << m_sFilename << "> Cannot process volume segmentation" << std::endl);
                return false;
            }

            // Create a new volume
            // - copy of the input one
            vpl::img::CDensityVolumePtr spSegmented(new vpl::img::CDensityVolume(*spVolume));

            // Classify voxels
            vpl::img::CDensityVolume::tIterator it(*spSegmented);
            for( ; it; ++it )
            {
                // Find cluster whose membership function is maximal
                vpl::tSize Max = Method.getMembership(Histogram.getIndex(*it));
                *it = vpl::img::CDensityVolume::tVoxel(Max);
            }

            // Write the result to the output channel
            if( !writeOutput(pOChannel, spSegmented.get()) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the segmented volume" << std::endl);
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


void CVolumeSegEM::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CVolumeSegEM::writeExtendedUsage(std::ostream& Stream)
{
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
    CVolumeSegEMPtr spModule(new CVolumeSegEM(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

