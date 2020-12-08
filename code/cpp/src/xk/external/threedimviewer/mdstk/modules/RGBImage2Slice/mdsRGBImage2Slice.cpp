//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/14                          \n
 *
 * $Id: mdsRGBImage2Slice.cpp 2098 2012-02-16 23:50:36Z spanel $
 *
 * File description:
 * - Converts input RGB image to medical slice.
 */

#include "mdsRGBImage2Slice.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsImageFunctions.h>

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module converts input RGB image to medical slice";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "";

//! Additional arguments


//==============================================================================
/*
 * Implementation of the class CRGBImage2Slice.
 */
CRGBImage2Slice::CRGBImage2Slice(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CRGBImage2Slice::~CRGBImage2Slice()
{
}


bool CRGBImage2Slice::startup()
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


bool CRGBImage2Slice::main()
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

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Create a new RGB image
        mds::img::CRGBImagePtr spRGBImage;

        // Read image from the input channel
        if( readInput(pIChannel, spRGBImage.get()) )
        {
            // Convert RGB image to slice
            mds::img::CSlicePtr spSlice;
            spSlice->convert(*spRGBImage);

            // Write it to the output channel
            if( !writeOutput(pOChannel, spSlice.get()) )
            {
                MDS_CERR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
                return false;
            }
        }
        else
        {
            MDS_CERR('<' << m_sFilename << "> Failed to read input RGB image" << std::endl);
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


void CRGBImage2Slice::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CRGBImage2Slice::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Input: MDSTk RGB image" << std::endl);
    MDS_CERR("Output: MDSTk slice" << std::endl);
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CRGBImage2SlicePtr spModule(new CRGBImage2Slice(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

