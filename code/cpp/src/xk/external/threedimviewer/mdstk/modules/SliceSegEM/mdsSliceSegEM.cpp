//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/11/02                          \n
 *
 * $Id: mdsSliceSegEM.cpp 2101 2012-02-17 08:20:21Z spanel $
 *
 * Description:
 * - Image segmentation based on EM algorithm.
 */

#include "mdsSliceSegEM.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
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
const std::string MODULE_DESCRIPTION    = "Module provides image segmentation based on the GMM+EM algorithm.";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "clusters:minsigma:mac";

//! Additional arguments names
const std::string MODULE_ARGUMENT_C     = "clusters";
const std::string MODULE_ARGUMENT_MS    = "minsigma";
const std::string MODULE_ARGUMENT_MAC   = "mac";

//! Default arguments values
const int DEFAULT_C                     = 0;
const double DEFAULT_MS                 = mds::math::GaussianFunc::DEFAULT_MIN_COVARIANCE;
const double DEFAULT_MAC                = mds::math::MaxLikelihoodByEM::MIN_ADD_CHANGE;

//! Allowed arguments values
const int MIN_C                         = 0;
const int MAX_C                         = 32;


//==============================================================================
/*
 * Implementation of the class CSliceSegEM.
 */
CSliceSegEM::CSliceSegEM(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceSegEM::~CSliceSegEM()
{
}


bool CSliceSegEM::startup()
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

    m_dMinSigma = DEFAULT_MS;
    m_Arguments.value(MODULE_ARGUMENT_MS, m_dMinSigma);
    if( m_dMinSigma < 0.0 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad " << MODULE_ARGUMENT_MS << " parameter value: type -h for help" << std::endl);
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


bool CSliceSegEM::main()
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
    mds::img::CSlicePtr spSlice;

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read slice from the input channel
        if( readInput(pIChannel, spSlice.get()) )
        {
            // Minimum and maximum density
            mds::img::CSlice::tPixel Min = mds::img::CPixelTraits<mds::img::CSlice::tPixel>::getPixelMin();
            mds::img::CSlice::tPixel Max = mds::img::CPixelTraits<mds::img::CSlice::tPixel>::getPixelMax();

            // Full histogram
            typedef mds::img::CFullHistogram<mds::img::CSlice> tHistogram;
            tHistogram Histogram(Min, Max);
            if( !Histogram(*spSlice) )
            {
                MDS_CERR('<' << m_sFilename << "> Cannot compute histogram of the input slice" << std::endl);
                return false;
            }

            // Create an array of feature vectors
            typedef mds::img::CFeatureVector<double, 1> tFeature;
            typedef mds::img::CArray<tFeature> tFeatures;

            // Initialize all feature vectors
            tFeatures Features;
            Features.create(Histogram.getSize());
            for( mds::img::CSlice::tPixel value = Min; value <= Max; ++value )
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
                MDS_CERR('<' << m_sFilename << "> Cannot process slice segmentation" << std::endl);
                return false;
            }

            // Create a new slice
            // - copy of the input one
            mds::img::CSlicePtr spSegmented(new mds::img::CSlice(*spSlice));

            // Classify all pixels
            for( mds::img::CSlice::tIterator it(*spSegmented); it; ++it )
            {
                // Find cluster whose membership function is maximal
                mds::tSize Max = Method.getMembership(Histogram.getIndex(*it));
                *it = mds::img::CSlice::tPixel(Max);
            }

            // Write the result to the output channel
            if( !writeOutput(pOChannel, spSegmented.get()) )
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


void CSliceSegEM::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceSegEM::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-clusters iValue] [-minsigma dValue] [-mac dValue]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -clusters  Number of segments in the input image. Zero value can" << std::endl);
    MDS_CERR("             be also given. In this case the number of segments is" << std::endl);
    MDS_CERR("             estimated automatically by the algorithm." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -minsigma  Minimal allowed value of the sigma parameter of gaussian" << std::endl);
    MDS_CERR("             function. Default value is " << DEFAULT_MS << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -mac  Minimal change of the log-likelihood function which results" << std::endl);
    MDS_CERR("        in addition of a new gaussian component to the mixture. Default" << std::endl);
    MDS_CERR("        value is " << DEFAULT_MAC << "." << std::endl);
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
    CSliceSegEMPtr spModule(new CSliceSegEM(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

