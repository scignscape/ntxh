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
 * Date:    2005/10/14                       
 *
 * Description:
 * - Fuzzy C-means image segmentation.
 */

#include "SliceSegFCM.h"

#include <VPL/Image/Slice.h>
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
const std::string MODULE_DESCRIPTION    = "Module provides fuzzy C-means segmentation algorithm.";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "clusters:weight";

//! Additional arguments names
const std::string MODULE_ARGUMENT_C     = "clusters";
const std::string MODULE_ARGUMENT_W     = "weight";

//! Default arguments values
const int DEFAULT_C                     = 0;
const double DEFAULT_W                  = vpl::math::FuzzyCMeans::DEFAULT_WEIGHT;

//! Allowed arguments values
const int MIN_C                         = 0;
const int MAX_C                         = 32;

const double MIN_W                      = 1.0;
const double MAX_W                      = 10.0;


//==============================================================================
/*
 * Implementation of the class CSliceSegFCM.
 */
CSliceSegFCM::CSliceSegFCM(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceSegFCM::~CSliceSegFCM()
{
}


bool CSliceSegFCM::startup()
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


bool CSliceSegFCM::main()
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
    vpl::img::CSlicePtr spSlice;

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read slice from the input channel
        if( readInput(pIChannel, spSlice.get()) )
        {
            // Minimum and maximum density
            vpl::img::CSlice::tPixel Min = vpl::img::CPixelTraits<vpl::img::CSlice::tPixel>::getPixelMin();
            vpl::img::CSlice::tPixel Max = vpl::img::CPixelTraits<vpl::img::CSlice::tPixel>::getPixelMax();

            // Full histogram
            typedef vpl::img::CFullHistogram<vpl::img::CSlice> tHistogram;
            tHistogram Histogram(Min, Max);
            if( !Histogram(*spSlice) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Cannot compute histogram of the input slice" << std::endl);
                return false;
            }

            // Create an array of feature vectors
            typedef vpl::img::CFeatureVector<double, 1> tFeature;
            typedef vpl::base::CArray<tFeature> tFeatures;

            // Initialize all feature vectors
            tFeatures Features;
            Features.resize(Histogram.getSize());
            for( vpl::img::CSlice::tPixel value = Min; value <= Max; ++value )
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
                VPL_LOG_ERROR('<' << m_sFilename << "> Cannot process slice segmentation" << std::endl);
                return false;
            }

            // Create a new slice
            // - copy of the input one
            vpl::img::CSlicePtr spSegmented(new vpl::img::CSlice(*spSlice));

            // Classify all pixels
            for( vpl::img::CSlice::tIterator it(*spSegmented); it; ++it )
            {
                // Find cluster whose membership function is maximal
                vpl::tSize Max = Method.getMembership(Histogram.getIndex(*it));
                *it = vpl::img::CSlice::tPixel(Max);
            }

            // Write the result to the output channel
            if( !writeOutput(pOChannel, spSegmented.get()) )
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


void CSliceSegFCM::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSliceSegFCM::writeExtendedUsage(std::ostream& Stream)
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
    CSliceSegFCMPtr spModule(new CSliceSegFCM(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

