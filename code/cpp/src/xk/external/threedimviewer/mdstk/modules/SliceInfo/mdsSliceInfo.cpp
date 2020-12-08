//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/22                          \n
 *
 * $Id: mdsSliceInfo.cpp 2100 2012-02-17 07:36:55Z spanel $
 *
 * File description:
 * - Shows information on input slice.
 */

#include "mdsSliceInfo.h"

#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsImageFunctions.h>

#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>

// STL
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

// Module description
const std::string MODULE_DESCRIPTION    = "Module shows information on input slice.";

// Additional command line arguments
const std::string MODULE_ARGUMENTS      = "";


//==============================================================================
/*
 * Implementation of the class CSliceInfo.
 */
CSliceInfo::CSliceInfo(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceInfo::~CSliceInfo()
{
}


bool CSliceInfo::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // O.K.
    return true;
}


bool CSliceInfo::main()
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
            // Create the output string
            char pcOut[1024];
            sprintf(pcOut,
                    "-- Information on slice image data --\n"
                    " Width:      %d\n"
                    " Height:     %d\n"
                    " Index:      %d\n"
                    " Position:   %.2f\n"
                    " Pixel:      %.2f, %.2f\n"
                    " Thickness:  %.2f\n"
                    "-- Pixel values statistic --\n"
                    " Minimum:    %d\n"
                    " Maximum:    %d\n"
                    " Mean value: %.2f\n"
                    " Variance:   %.2f\n",
                    spSlice->getXSize(),
                    spSlice->getYSize(),
                    spSlice->getIndex(),
                    spSlice->getPosition(),
                    spSlice->getDX(),
                    spSlice->getDY(),
                    spSlice->getThickness(),
                    mds::img::getMin<int>(*spSlice),
                    mds::img::getMax<int>(*spSlice),
                    mds::img::getMean<double>(*spSlice),
                    sqrt(mds::img::getVariance<double>(*spSlice))
                   );

            // Write it to the output channel
            if( !pOChannel->write(pcOut, mds::tSize(strlen(pcOut))) )
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


void CSliceInfo::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceInfo::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
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
    CSliceInfoPtr spModule(new CSliceInfo(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

