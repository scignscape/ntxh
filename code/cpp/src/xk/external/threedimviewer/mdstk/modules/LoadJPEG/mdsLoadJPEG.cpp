//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/03/31                          \n
 *
 * $Id: mdsLoadJPEG.cpp 2098 2012-02-16 23:50:36Z spanel $
 *
 * File description:
 * - Reads JPEG image from an input channel.
 * - Converts it to the slice format.
 */

#include "mdsLoadJPEG.h"

#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/ImageIO/mdsJPEG.h>

// STL
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global module constants.
 */

// Module description
const std::string MODULE_DESCRIPTION    = "Module loads JPEG image data";

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
 * Implementation of the class CLoadJPEG.
 */
CLoadJPEG::CLoadJPEG(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CLoadJPEG::~CLoadJPEG()
{
}


bool CLoadJPEG::startup()
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


bool CLoadJPEG::main()
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
        // Load JPEG image data from the input channel
        if( m_ssFormat == IMAGE8 )
        {
            // Create a new image
            mds::img::CImage8Ptr spImage(new mds::img::CImage8);

            // Read JPEG image
            if( mds::img::loadJPEG(*spImage, *pIChannel) )
            {
                // Write result to the output channel
                if( !writeOutput(pOChannel, spImage.get()) )
                {
                    MDS_CERR('<' << m_sFilename << "> Failed to write the output image" << std::endl);
                }
            }
            else
            {
                MDS_CERR('<' << m_sFilename << "> Failed to read input JPEG image data" << std::endl);
                return false;
            }
        }
        else if( m_ssFormat == RGB )
        {
            mds::img::CRGBImagePtr spImage(new mds::img::CRGBImage);

            if( mds::img::loadJPEG(*spImage, *pIChannel) )
            {
                if( !writeOutput(pOChannel, spImage.get()) )
                {
                    MDS_CERR('<' << m_sFilename << "> Failed to write the output image" << std::endl);
                }
            }
            else
            {
                MDS_CERR('<' << m_sFilename << "> Failed to read input JPEG image data" << std::endl);
                return false;
            }
        }
        else if( m_ssFormat == SLICE )
        {
            mds::img::CSlicePtr spSlice(new mds::img::CSlice);

            if( mds::img::loadJPEG(*spSlice, *pIChannel) )
            {
                if( !writeOutput(pOChannel, spSlice.get()) )
                {
                    MDS_CERR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
                }
            }
            else
            {
                MDS_CERR('<' << m_sFilename << "> Failed to read input JPEG image data" << std::endl);
                return false;
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


void CLoadJPEG::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CLoadJPEG::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-format ssType]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -format  Specifies output image format." << std::endl);
    MDS_CERR("           One of the following values can be given:" << std::endl);
    MDS_CERR("             " << IMAGE8 << std::endl);
    MDS_CERR("             " << RGB << std::endl);
    MDS_CERR("             " << SLICE << std::endl);
    MDS_CERR("           Default value is " << DEFAULT_FORMAT << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("Input: JPEG image" << std::endl);
    MDS_CERR("Output: MDSTk image" << std::endl);
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CLoadJPEGPtr spModule(new CLoadJPEG(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

