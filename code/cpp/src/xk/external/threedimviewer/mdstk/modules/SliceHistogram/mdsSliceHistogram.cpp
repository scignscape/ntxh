//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/02/12                          \n
 *
 * $Id: mdsSliceHistogram.cpp 2100 2012-02-17 07:36:55Z spanel $
 *
 * Description:
 * - Shows histogram of an input slice.
 */

#include "mdsSliceHistogram.h"

#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsImageHistogram.h>

#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>

// STL
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module shows input slice histogram";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "bins:entropy";

//! Additional arguments
const std::string MODULE_ARGUMENT_BINS     = "bins";
const std::string MODULE_ARGUMENT_ENTROPY  = "entropy";

//! Default arguments values
const unsigned int DEFAULT_BINS         = 64;
const bool DEFAULT_ENTROPY              = false;

//! Maximal length of visualized histogram bin
const int MAX_BIN_LENGTH                = 60;


//==============================================================================
/*
 * Implementation of the class CSliceHistogram.
 */
CSliceHistogram::CSliceHistogram(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceHistogram::~CSliceHistogram()
{
}


bool CSliceHistogram::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line parameters
    m_iBins = DEFAULT_BINS;
    m_Arguments.value(MODULE_ARGUMENT_BINS, m_iBins);
    if( m_iBins <= 0 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'bins' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_bEntropy = DEFAULT_ENTROPY;
    if (m_Arguments.exists(MODULE_ARGUMENT_ENTROPY))
    {
        m_bEntropy = true;
    }

    // O.K.
    return true;
}


bool CSliceHistogram::main()
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
            // Quantized image histogram
            typedef mds::img::CHistogram<mds::img::CDImage> tMyHistogram;

            // Compute histogram
            tMyHistogram Histogram((mds::tSize)m_iBins,
                                    mds::img::CPixelTraits<mds::img::CDImage::tPixel>::getPixelMin(),
                                    mds::img::CPixelTraits<mds::img::CDImage::tPixel>::getPixelMax()
                                    );
            if( !Histogram(*spSlice) )
            {
                MDS_CERR('<' << m_sFilename << "> Cannot compute the input slice histogram" << std::endl);
                return false;
            }

            // Create the output string stream
            std::stringstream ss;
            ss.fill(' ');
            ss.setf(std::ios::right | std::ios::fixed);

            // Print header
            ss << "-- Image histogram --" << std::endl;

            // Prepare bin visualization string
            char *pcBin = new char[MAX_BIN_LENGTH + 1];
            memset(pcBin, '-', MAX_BIN_LENGTH);
            pcBin[MAX_BIN_LENGTH] = '\0';

            // Maximal histogram value
            tMyHistogram::tBin Max = Histogram.getMax();

            // Print the histogram
            tMyHistogram::tBin Count, Length;
            for( mds::tSize i = 0; i < Histogram.getSize(); ++i )
            {
                Count = Histogram.getCount(i);
                ss << std::setw(6) << Histogram.getLowerBound(i) << ">";
                Length = Count * MAX_BIN_LENGTH / Max;
                pcBin[Length] = '\0';
                ss << pcBin;
                pcBin[Length] = '-';
                ss << "| " << Count << std::endl;
            }

            // Delete the helper string
            delete[] pcBin;

            // Compute also entropy?
            if (m_bEntropy)
            {
                // FIXME: We must create and compute new full valued histogram.
                mds::img::CDImage::tPixel min = mds::img::CPixelTraits<mds::img::CDImage::tPixel>::getPixelMin();
                mds::img::CDImage::tPixel max = mds::img::CPixelTraits<mds::img::CDImage::tPixel>::getPixelMax();
                tMyHistogram Histogram((mds::tSize) max - min, min, max);

                if( !Histogram(*spSlice) )
                {
                    MDS_CERR('<' << m_sFilename << "> Cannot compute the input slice histogram" << std::endl);
                    return false;
                }

                float Entropy = 0;
                float InvTotalCount = 1.0f / Histogram.getTotalCount();
                float LogConst = 1.0f / std::log(2.0f);
                for( mds::tSize i = 0; i < Histogram.getSize(); ++i )
                {
                    tMyHistogram::tBin Count = Histogram.getCount(i);
                    float Probability = Count * InvTotalCount;
                    if (Count != 0)
                    {
                        Entropy += Probability * log(Probability) * LogConst;
                    }
                }
                Entropy = -Entropy;

                ss << "-- Entropy: " << Entropy << " --" << std::endl;
            }

            // Write it to the output channel
            if( !pOChannel->write(ss.str().c_str(), mds::tSize(ss.str().length())) )
            {
                MDS_CERR('<' << m_sFilename << "> Failed to write the output" << std::endl);
                return false;
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


void CSliceHistogram::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceHistogram::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-bins uValue] [-entropy]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -bins  Sets the number of histogram bins. Default value" << std::endl);
    MDS_CERR("         is " << DEFAULT_BINS << "." << std::endl);
    MDS_CERR("  -entropy  Computes also data entropy." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("Input: MDSTk slice" << std::endl);
    MDS_CERR("Output: text" << std::endl);
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CSliceHistogramPtr spModule(new CSliceHistogram(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

