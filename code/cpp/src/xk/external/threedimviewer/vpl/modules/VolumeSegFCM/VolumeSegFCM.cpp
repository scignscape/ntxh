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

#include "VolumeSegFCM.h"

#include <VPL/Image/Slice.h>
#include <VPL/Image/DensityVolume.h>
#include <VPL/Image/Histogram.h>
#include <VPL/Image/FeatureExtraction/FeatureVector.h>
#include <VPL/Image/Algorithm/WeightedFCM.h>
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
const std::string MODULE_DESCRIPTION    = "Module provides fuzzy C-means segmentation algorithm";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "clusters:weight";

//! Additional arguments names
const std::string MODULE_ARGUMENT_C     = "clusters";
const std::string MODULE_ARGUMENT_W     = "weight";

//! Default arguments values
const int DEFAULT_C                     = 0;
const double DEFAULT_W                  = 1.5;

//! Allowed arguments values
const int MIN_C                         = 0;
const int MAX_C                         = 32;

const double MIN_W                      = 1.0;
const double MAX_W                      = 10.0;


//==============================================================================
/*
 * Implementation of the class CVolumeSegFCM.
 */
CVolumeSegFCM::CVolumeSegFCM(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeSegFCM::~CVolumeSegFCM()
{
}


bool CVolumeSegFCM::startup()
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

    // Command line argument 'weight'
    m_dWeight = DEFAULT_W;
    m_Arguments.value(MODULE_ARGUMENT_W, m_dWeight);
    if( m_dWeight < MIN_W || m_dWeight > MAX_W )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad " << MODULE_ARGUMENT_W << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CVolumeSegFCM::main()
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
                 VPL_LOG_ERROR('<' << m_sFilename << "> Cannot compute the input volume histogram" << std::endl);
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
             vpl::img::CWeightedFCM<tFeatures, 1> Method;
             Method.setWeight(m_dWeight);

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


void CVolumeSegFCM::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CVolumeSegFCM::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-clusters iValue] [-weight dValue]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -clusters  Number of segments in the input image. Zero value can" << std::endl;
    Stream << "             be also given. In this case the number of segments is" << std::endl;
    Stream << "             estimated automatically by the algorithm." << std::endl;
    Stream << std::endl;
    Stream << "  -weight  Parameter of the fuzzy C-means clustering algorithm." << std::endl;
    Stream << "           See its documentation. Value in the range " << MIN_W << ".." << MAX_W << " can be" << std::endl;
    Stream << "           given. Default value is " << DEFAULT_W << "." << std::endl;
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
    CVolumeSegFCMPtr spModule(new CVolumeSegFCM(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

