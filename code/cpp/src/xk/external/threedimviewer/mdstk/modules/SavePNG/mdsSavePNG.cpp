//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/03/30                          \n
 *
 * $Id: mdsSavePNG.cpp 2098 2012-02-16 23:50:36Z spanel $
 *
 * File description:
 * - Converts an input slice to PNG image format.
 */

#include "mdsSavePNG.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/ImageIO/mdsPNG.h>

// STL
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module converts an input slice to the PNG image";

// Additional command line arguments
const std::string MODULE_ARGUMENTS      = "format";

//! Additional arguments
const std::string MODULE_ARG_FORMAT     = "format";

//! Allowed output image formats
const std::string IMAGE8                = "image8";
const std::string RGB                   = "rgb";
const std::string SLICE                 = "slice";

//! Default argument values
const std::string DEFAULT_FORMAT        = SLICE;


//==============================================================================
/*
 * Implementation of the class CSavePNG.
 */
CSavePNG::CSavePNG(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSavePNG::~CSavePNG()
{
}


bool CSavePNG::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Image format
    m_ssFormat = DEFAULT_FORMAT;
    m_Arguments.value(MODULE_ARG_FORMAT, m_ssFormat);

    // O.K.
    return true;
}


bool CSavePNG::main()
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
        // Read input image of specified format
        if( m_ssFormat == IMAGE8 )
        {
            // Create a new image
            mds::img::CImage8Ptr spImage;

            // Read image from the input channel
            if( readInput(pIChannel, spImage.get()) )
            {
                // Write it to the output channel
                if( !mds::img::savePNG(*spImage, *pOChannel) )
                {
                    MDS_CERR('<' << m_sFilename << "> Failed to write the output PNG image" << std::endl);
                }
            }
            else
            {
                MDS_CERR('<' << m_sFilename << "> Failed to read input image" << std::endl);
            }
        }
        else if( m_ssFormat == RGB )
        {
            mds::img::CRGBImagePtr spImage;
            if( readInput(pIChannel, spImage.get()) )
            {
                if( !mds::img::savePNG(*spImage, *pOChannel) )
                {
                    MDS_CERR('<' << m_sFilename << "> Failed to write the output PNG image" << std::endl);
                }
            }
            else
            {
                MDS_CERR('<' << m_sFilename << "> Failed to read input image" << std::endl);
            }
        }
        else if( m_ssFormat == SLICE )
        {
            mds::img::CSlicePtr spSlice;
            if( readInput(pIChannel, spSlice.get()) )
            {
                if( !mds::img::savePNG(*spSlice, *pOChannel) )
                {
                    MDS_CERR('<' << m_sFilename << "> Failed to write the output PNG image" << std::endl);
                }
            }
            else
            {
                MDS_CERR('<' << m_sFilename << "> Failed to read input slice" << std::endl);
            }
        }
        else
        {
            MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_FORMAT << "' parameter value: type -h for help" << std::endl);
            printUsage();
            return false;
        }
        return false;
    }
    else
    {
        MDS_LOG_NOTE("Wait timeout");
    }

    // Returning 'true' means to continue processing the input channel
    return true;
}


void CSavePNG::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSavePNG::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-format ssType]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -format  Specifies input image format." << std::endl);
    MDS_CERR("           One of the following values can be given:" << std::endl);
    MDS_CERR("             " << IMAGE8 << std::endl);
    MDS_CERR("             " << RGB << std::endl);
    MDS_CERR("             " << SLICE << std::endl);
    MDS_CERR("           Default value is " << DEFAULT_FORMAT << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("Input: MDSTk image" << std::endl);
    MDS_CERR("Output: JPEG image" << std::endl);
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CSavePNGPtr spModule(new CSavePNG(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Module application finished
    return 0;
}

