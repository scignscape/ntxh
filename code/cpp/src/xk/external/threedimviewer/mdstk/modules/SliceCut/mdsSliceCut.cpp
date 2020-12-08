//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/19                          \n
 *
 * $Id: mdsSliceCut.cpp 2098 2012-02-16 23:50:36Z spanel $
 *
 * File description:
 * - Cuts a specified interval of pixels.
 */

#include "mdsSliceCut.h"

#include <MDSTk/Image/mdsSlice.h>

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module cuts a specified interval of pixels.";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "min:max";

//! Additional arguments
const std::string MODULE_ARGUMENT_MIN   = "min";
const std::string MODULE_ARGUMENT_MAX   = "max";

//! Default min and max values
const int DEFAULT_MIN          = mds::img::CPixelTraits<mds::img::CSlice::tPixel>::getPixelMin();
const int DEFAULT_MAX          = mds::img::CPixelTraits<mds::img::CSlice::tPixel>::getPixelMax();


//==============================================================================
/*
 * Implementation of the class CSliceCut.
 */
CSliceCut::CSliceCut(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceCut::~CSliceCut()
{
}


bool CSliceCut::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line parameters 'min' and 'max'
    m_iMin = DEFAULT_MIN;
    m_Arguments.value(MODULE_ARGUMENT_MIN, m_iMin);
    if( m_iMin > DEFAULT_MAX || m_iMin < DEFAULT_MIN )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'min' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'max'
    m_iMax = DEFAULT_MAX;
    m_Arguments.value(MODULE_ARGUMENT_MAX, m_iMax);
    if( m_iMax < m_iMin || m_iMax > DEFAULT_MAX )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'max' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CSliceCut::main()
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
        // Otherwise, read slice from the input channel
        if( readInput(pIChannel, spSlice.get()) )
        {
            // Cut the interval
            spSlice->cut((mds::img::CSlice::tPixel)m_iMin, (mds::img::CSlice::tPixel)m_iMax);

            // Write it to the output channel
            if( !writeOutput(pOChannel, spSlice.get()) )
            {
                MDS_CERR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
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


void CSliceCut::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceCut::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-min iValue] [-max iValue]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -min  Lower boundary of the interval." << std::endl);
    MDS_CERR("  -max  Higher interval boundary." << std::endl);
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
    CSliceCutPtr spModule(new CSliceCut(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

