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
 * Date:    2005/02/12                       
 *
 * Description:
 * - Shows histogram of an input slice.
 */

#include "SliceHistogram.h"

#include <VPL/Image/Slice.h>
#include <VPL/Image/ImageHistogram.h>

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
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceHistogram::~CSliceHistogram()
{
}


bool CSliceHistogram::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line parameters
    m_iBins = DEFAULT_BINS;
    m_Arguments.value(MODULE_ARGUMENT_BINS, m_iBins);
    if( m_iBins <= 0 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'bins' parameter value: type -h for help" << std::endl);
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
            // Quantized image histogram
            typedef vpl::img::CHistogram<vpl::img::CDImage> tMyHistogram;

            // Compute histogram
            tMyHistogram Histogram((vpl::tSize)m_iBins,
                                    vpl::img::CPixelTraits<vpl::img::CDImage::tPixel>::getPixelMin(),
                                    vpl::img::CPixelTraits<vpl::img::CDImage::tPixel>::getPixelMax()
                                    );
            if( !Histogram(*spSlice) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Cannot compute the input slice histogram" << std::endl);
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
            for( vpl::tSize i = 0; i < Histogram.getSize(); ++i )
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
                vpl::img::CDImage::tPixel min = vpl::img::CPixelTraits<vpl::img::CDImage::tPixel>::getPixelMin();
                vpl::img::CDImage::tPixel max = vpl::img::CPixelTraits<vpl::img::CDImage::tPixel>::getPixelMax();
                tMyHistogram Histogram((vpl::tSize) max - min, min, max);

                if( !Histogram(*spSlice) )
                {
                    VPL_LOG_ERROR('<' << m_sFilename << "> Cannot compute the input slice histogram" << std::endl);
                    return false;
                }

                float Entropy = 0;
                float InvTotalCount = 1.0f / Histogram.getTotalCount();
                float LogConst = 1.0f / std::log(2.0f);
                for( vpl::tSize i = 0; i < Histogram.getSize(); ++i )
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
            if( !pOChannel->write(ss.str().c_str(), vpl::tSize(ss.str().length())) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output" << std::endl);
                return false;
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


void CSliceHistogram::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSliceHistogram::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-bins uValue] [-entropy]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -bins  Sets the number of histogram bins. Default value" << std::endl;
    Stream << "         is " << DEFAULT_BINS << "." << std::endl;
    Stream << "  -entropy  Computes also data entropy." << std::endl;
    Stream << std::endl;
    Stream << "Input: MDSTk slice" << std::endl;
    Stream << "Output: text" << std::endl;
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

