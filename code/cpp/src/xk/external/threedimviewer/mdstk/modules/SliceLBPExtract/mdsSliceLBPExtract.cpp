//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)          \n
 * Copyright (c) 2003-2009 by Michal Spanel           \n
 *
 * Authors: Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz        \n
 * Date:    2008/01/27                                \n
 *
 * $Id: mdsSliceLBPExtract.cpp 2100 2012-02-17 07:36:55Z spanel $
 *
 * File description:
 * - Extracts LBP codes from an image.
 */

#include "mdsSliceLBPExtract.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/LBP/mdsFunctional.h>

// STL
#include <string>
#include <iostream>
#include <sstream>


//==============================================================================
/*
 * Global constants.
 */

//! Module description.
const std::string MODULE_DESCRIPTION    = "Extracts LBP codes from input slice";

//! Additional command line arguments.
//! - Colon separated list!
const std::string MODULE_ARGUMENTS      = "m:s:x:y:width:height";
const std::string MODULE_ARG_M          = "m";
const std::string MODULE_ARG_S          = "s";
const std::string MODULE_ARG_X          = "x";
const std::string MODULE_ARG_Y          = "y";
const std::string MODULE_ARG_W          = "width";
const std::string MODULE_ARG_H          = "height";

//! Default arguments values.
const std::string DEFAULT_M             = "urm";
const int DEFAULT_S                     = 8;

//==============================================================================
/*!
 * Functor writes all LBP codes to the output stream.
 */
class CPrintLBPCode
{
public:
    //! Constructor.
    CPrintLBPCode(std::stringstream& Stream) : m_Stream(Stream) {}

    //! Functor body.
    void operator() (mds::tSize MDS_UNUSED(x), mds::tSize MDS_UNUSED(y), unsigned int Code)
    {
        m_Stream << Code << std::endl;
    }

protected:
    //! Reference to the string stream.
    std::stringstream& m_Stream;
};


//==============================================================================
/*
 * Implementation of the class CSliceLBPExtract.
 */
CSliceLBPExtract::CSliceLBPExtract(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    // Allow additional command line arguments
    allowArguments(MODULE_ARGUMENTS);
}


CSliceLBPExtract::~CSliceLBPExtract()
{
}


bool CSliceLBPExtract::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    m_ssMapping = DEFAULT_M;
    m_Arguments.value(MODULE_ARG_M, m_ssMapping);

    m_NumOfSamples = DEFAULT_S;
    m_Arguments.value(MODULE_ARG_S, m_NumOfSamples);
    if( m_NumOfSamples != 8 && m_NumOfSamples != 12 && m_NumOfSamples != 16 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_S << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_X = m_Y = 0;
    m_Arguments.value(MODULE_ARG_X, m_X);
    m_Arguments.value(MODULE_ARG_Y, m_Y);

    m_Width = m_Height = -1;
    m_Arguments.value(MODULE_ARG_W, m_Width);
    m_Arguments.value(MODULE_ARG_H, m_Height);

    return true;
}


bool CSliceLBPExtract::main()
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

    // Helper code...
/*    MDS_LOG_NOTE("Number of ones:");
    for( unsigned i = 0; i <= 255; ++i )
    {
        MDS_LOG(mds::lbp::CBitOps<unsigned char>::getNumOfOnes((unsigned char)i) << ", ");
    }
    MDS_LOG(std::endl);

    MDS_LOG_NOTE("Number of trans:");
    for( unsigned i = 0; i <= 255; ++i )
    {
        MDS_LOG(mds::lbp::CBitOps<unsigned char>::getNumOfTransitions((unsigned char)i) << ", ");
    }
    MDS_LOG(std::endl);

    MDS_LOG_NOTE("Rotate to min:");
    for( unsigned i = 0; i <= 255; ++i )
    {
        MDS_LOG((unsigned int)mds::lbp::CBitOps<unsigned char>::rotate2Min((unsigned char)i) << ", ");
    }
    MDS_LOG(std::endl);

    MDS_LOG_NOTE("Names:");
    for( unsigned i = 0; i <= 255; ++i )
    {
        MDS_LOG("\"" << mds::lbp::CBitOps<unsigned char>::conv2String((unsigned char)i) << "\", ");
    }
    MDS_LOG(std::endl);*/

/*    MDS_LOG_NOTE("RotMin mapping size:");
    mds::lbp::CRotMin<mds::lbp::LBP8> Map8;
    MDS_LOG_NOTE("  LBP8 -> " << Map8.getSize());
    mds::lbp::CRotMin<mds::lbp::LBP12> Map12;
    MDS_LOG_NOTE("  LBP12 -> " << Map12.getSize());
    mds::lbp::CRotMin<mds::lbp::LBP16> Map16;
    MDS_LOG_NOTE("  LBP16 -> " << Map16.getSize());*/

//    return false;

    // Create a new slice
    mds::img::CSlice Slice;

    // Wait for data
    if( !pIChannel->wait(1000) )
    {
        MDS_LOG_NOTE("Wait timeout");
        return true;
    }

    // Read slice from the input channel
    if( !readInput(pIChannel, &Slice) )
    {
        MDS_CERR('<' << m_sFilename << "> Failed to read input slice" << std::endl);
        return false;
    }

    // Check parameters
    mds::math::limit<int>(m_X, 0, Slice.getXSize() - 1);
    mds::math::limit<int>(m_Y, 0, Slice.getYSize() - 1);
    m_Width = (m_Width == -1) ? Slice.getXSize() : m_Width;
    m_Height = (m_Height == -1) ? Slice.getYSize() : m_Width;
    mds::math::limit<int>(m_Width, 0, Slice.getXSize() - m_X - 1);
    mds::math::limit<int>(m_Height, 0, Slice.getYSize() - m_Y - 1);

    // Log modified parameters
    MDS_LOG_NOTE("Window position (" << m_X << ", " << m_Y << ")");
    MDS_LOG_NOTE("Window size (" << m_Width << ", " << m_Height << ")");

    // Prepare image window
    mds::img::CDImage Region;
    Region.create(Slice, m_X, m_Y, m_Width, m_Height, mds::REFERENCE);

    // Extract LBP codes from the window
    std::stringstream Stream;
    CPrintLBPCode PrintLBP(Stream);
    if( m_ssMapping == std::string("plain") )
    {
        if( m_NumOfSamples == 12 )
        {
            mds::lbp::forEach<mds::img::CDImage, mds::lbp::LBP12, mds::lbp::CPlain>(Region, PrintLBP);
        }
        else
        {
            mds::lbp::forEach<mds::img::CDImage, mds::lbp::LBP8, mds::lbp::CPlain>(Region, PrintLBP);
        }
    }
    else if( m_ssMapping == std::string("rotmin") )
    {
        if( m_NumOfSamples == 16 )
        {
            mds::lbp::forEach<mds::img::CDImage, mds::lbp::LBP16, mds::lbp::CRotMin>(Region, PrintLBP);
        }
        else if( m_NumOfSamples == 12 )
        {
            mds::lbp::forEach<mds::img::CDImage, mds::lbp::LBP12, mds::lbp::CRotMin>(Region, PrintLBP);
        }
        else
        {
            mds::lbp::forEach<mds::img::CDImage, mds::lbp::LBP8, mds::lbp::CRotMin>(Region, PrintLBP);
        }
    }
    else if( m_ssMapping == std::string("uniform") )
    {
        if( m_NumOfSamples == 16 )
        {
            mds::lbp::forEach<mds::img::CDImage, mds::lbp::LBP16, mds::lbp::CUniform>(Region, PrintLBP);
        }
        else if( m_NumOfSamples == 12 )
        {
            mds::lbp::forEach<mds::img::CDImage, mds::lbp::LBP12, mds::lbp::CUniform>(Region, PrintLBP);
        }
        else
        {
            mds::lbp::forEach<mds::img::CDImage, mds::lbp::LBP8, mds::lbp::CUniform>(Region, PrintLBP);
        }
    }
    else if( m_ssMapping == std::string("urm") )
    {
        if( m_NumOfSamples == 16 )
        {
            mds::lbp::forEach<mds::img::CDImage, mds::lbp::LBP16, mds::lbp::CUniformRotMin>(Region, PrintLBP);
        }
        else if( m_NumOfSamples == 12 )
        {
            mds::lbp::forEach<mds::img::CDImage, mds::lbp::LBP12, mds::lbp::CUniformRotMin>(Region, PrintLBP);
        }
        else
        {
            mds::lbp::forEach<mds::img::CDImage, mds::lbp::LBP8, mds::lbp::CUniformRotMin>(Region, PrintLBP);
        }
    }
    else
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_M << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Write the result to the output channel
    if( !pOChannel->write(Stream.str().c_str(), (int)Stream.str().length()) )
    {
        MDS_CERR('<' << m_sFilename << "> Failed to write the output" << std::endl);
        return false;
    }

    // Returning true means to continue processing the input channel
    return false;
}


void CSliceLBPExtract::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceLBPExtract::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-x iValue] [-y iValue] [-width iValue] [-height iValue]" << std::endl);
    MDS_CERR("                [-m sValue] [-s iValue]" << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -x, y  Position of top left corner of an image window" << std::endl);
    MDS_CERR("         from where LBPs will be extracted (zeros by default)." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -width  Width of the image window (whole image by default)." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -height  Height of the window." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -m  Type of the LBP mapping. Please, specify one of the following values" << std::endl);
    MDS_CERR("        plain (no mapping at all)," << std::endl);
    MDS_CERR("        rotmin (rotation invariant LBP)," << std::endl);
    MDS_CERR("        uniform (uniform LBPs only)," << std::endl);
    MDS_CERR("        urm (uniform rotation invariant LBP)" << std::endl);
    MDS_CERR("      The last option is the default one." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -s  Number of samples (8 by default). Moreover," << std::endl);
    MDS_CERR("        12," << std::endl);
    MDS_CERR("        and 16" << std::endl);
    MDS_CERR("      can be given." << std::endl << std::endl);
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
    CSliceLBPExtractPtr spModule(new CSliceLBPExtract(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

