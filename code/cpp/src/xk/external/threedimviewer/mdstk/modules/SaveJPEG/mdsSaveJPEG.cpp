//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/03/31                          \n
 *
 * $Id: mdsSaveJPEG.cpp 2098 2012-02-16 23:50:36Z spanel $
 *
 * File description:
 * - Converts an input slice to JPEG image format.
 */

#include "mdsSaveJPEG.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/ImageIO/mdsJPEG.h>

// STL
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

// Module description
const std::string MODULE_DESCRIPTION    = "Module converts input slice to JPEG image";

// Additional command line arguments
const std::string MODULE_ARGUMENTS      = "format:quality";

//! Additional arguments
const std::string MODULE_ARG_FORMAT     = "format";
const std::string MODULE_ARG_QUALITY    = "quality";

//! Allowed output image formats
const std::string IMAGE8                = "image8";
const std::string RGB                   = "rgb";
const std::string SLICE                 = "slice";

//! Default argument values
const std::string DEFAULT_FORMAT        = SLICE;
const int DEFAULT_ARG_QUALITY           = 128;

//! Allowed argument values
const int MIN_QUALITY                   = 0;
const int MAX_QUALITY                   = 255;


//==============================================================================
/*
 * Implementation of the class CSaveJPEG.
 */
CSaveJPEG::CSaveJPEG(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSaveJPEG::~CSaveJPEG()
{
}


bool CSaveJPEG::startup()
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

    // Parameter
    m_iQuality = DEFAULT_ARG_QUALITY;
    m_Arguments.value(MODULE_ARG_QUALITY, m_iQuality);
    if( m_iQuality < MIN_QUALITY || m_iQuality > MAX_QUALITY )
    {
        MDS_CERR('<' << m_sFilename << "> Bad " << MODULE_ARG_QUALITY << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CSaveJPEG::main()
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
                if( !mds::img::saveJPEG(*spImage, *pOChannel, m_iQuality) )
                {
                    MDS_CERR('<' << m_sFilename << "> Failed to write the output JPEG image" << std::endl);
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
                if( !mds::img::saveJPEG(*spImage, *pOChannel, m_iQuality) )
                {
                    MDS_CERR('<' << m_sFilename << "> Failed to write the output JPEG image" << std::endl);
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
                if( !mds::img::saveJPEG(*spSlice, *pOChannel, m_iQuality) )
                {
                    MDS_CERR('<' << m_sFilename << "> Failed to write the output JPEG image" << std::endl);
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


void CSaveJPEG::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSaveJPEG::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-format ssType] [-quality iValue]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -format  Specifies input image format." << std::endl);
    MDS_CERR("           One of the following values can be given:" << std::endl);
    MDS_CERR("             " << IMAGE8 << std::endl);
    MDS_CERR("             " << RGB << std::endl);
    MDS_CERR("             " << SLICE << std::endl);
    MDS_CERR("           Default value is " << DEFAULT_FORMAT << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -quality  Quality of the JPEG image. Values in the range <0..255>" << std::endl);
    MDS_CERR("            are allowed. Default value is " << DEFAULT_ARG_QUALITY << "." << std::endl);
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
    CSaveJPEGPtr spModule(new CSaveJPEG(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

