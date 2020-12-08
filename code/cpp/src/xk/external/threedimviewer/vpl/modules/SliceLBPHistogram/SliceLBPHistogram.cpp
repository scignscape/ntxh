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
 * Copyright (c) 2003-2009 by Michal Spanel        
 *
 * Authors: Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz     
 * Date:    2008/01/27                             
 *
 * File description:
 * - Extracts and displays normalized LBP histogram.
 */

#include "SliceLBPHistogram.h"

// MDSTk
#include <VPL/Image/Slice.h>
#include <VPL/Image/LBP/Extractor.h>

// STL
#include <iostream>
#include <sstream>


//==============================================================================
/*
 * Global constants.
 */

//! Module description.
const std::string MODULE_DESCRIPTION    = "Extracts normalized histogram of LBP codes";

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
 * Writes feature vector to the text stream.
 */
template <typename T, int N>
void printFeatures(std::stringstream& Stream, const vpl::img::CFeatureVector<T,N>& Data)
{
    for( int i = 0; i < (N - 1); ++i )
    {
        Stream << Data(i) << " ";
    }
    Stream << Data(N - 1) << std::endl;
}


//==============================================================================
/*!
 * Estimates and prints histogram of LBP codes.
 */
template <vpl::lbp::ECodeType Type, template <vpl::lbp::ECodeType> class Mapping>
void extractAndPrintFeatures(std::stringstream& Stream, vpl::img::CDImage& Image)
{
    typedef vpl::lbp::CLBPExtractor<vpl::img::CDImage, Type, Mapping> tExtractor;
    typedef typename tExtractor::tVector tFeatures;

    // Create LBP histogram extractor
    tExtractor Extractor;
    Extractor.accumulate(&Image);

    // Evaluate feature vector (= normalized histogram)
    tFeatures Features;
    Extractor.evaluate(Features);

    // Print the histogram
    printFeatures(Stream, Features);
}


//==============================================================================
/*
 * Implementation of the class CSliceLBPHistogram.
 */
CSliceLBPHistogram::CSliceLBPHistogram(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    // Allow additional command line arguments
    allowArguments(MODULE_ARGUMENTS);
}


CSliceLBPHistogram::~CSliceLBPHistogram()
{
}


bool CSliceLBPHistogram::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    m_ssMapping = DEFAULT_M;
    m_Arguments.value(MODULE_ARG_M, m_ssMapping);

    m_NumOfSamples = DEFAULT_S;
    m_Arguments.value(MODULE_ARG_S, m_NumOfSamples);
    if( m_NumOfSamples != 8 && m_NumOfSamples != 12 && m_NumOfSamples != 16 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_S << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_X = m_Y = 0;
    m_Arguments.value(MODULE_ARG_X, m_X);
    m_Arguments.value(MODULE_ARG_Y, m_Y);

    m_Width = m_Height = -1;
    m_Arguments.value(MODULE_ARG_W, m_Width);
    m_Arguments.value(MODULE_ARG_H, m_Height);

//    m_bNormalize = m_Arguments.exists(MODULE_ARG_N);

    return true;
}


bool CSliceLBPHistogram::main()
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
     vpl::img::CSlice Slice;

     // Wait for data
     if( !pIChannel->wait(1000) )
     {
         VPL_LOG_INFO("Wait timeout");
         return true;
     }

     // Read slice from the input channel
     if( !readInput(pIChannel, &Slice) )
     {
         VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input slice" << std::endl);
         return false;
     }

     // Check parameters
     vpl::math::limit<int>(m_X, 0, Slice.getXSize() - 1);
     vpl::math::limit<int>(m_Y, 0, Slice.getYSize() - 1);
     m_Width = (m_Width == -1) ? Slice.getXSize() : m_Width;
     m_Height = (m_Height == -1) ? Slice.getYSize() : m_Width;
     vpl::math::limit<int>(m_Width, 0, Slice.getXSize() - m_X - 1);
     vpl::math::limit<int>(m_Height, 0, Slice.getYSize() - m_Y - 1);

     // Log modified parameters
     VPL_LOG_INFO("Window position (" << m_X << ", " << m_Y << ")");
     VPL_LOG_INFO("Window size (" << m_Width << ", " << m_Height << ")");

     // Prepare image window
     vpl::img::CDImage Region;
     Region.makeRef(Slice, m_X, m_Y, m_Width, m_Height);

     // Extract LBP codes from the window
     std::stringstream Stream;
     if( m_ssMapping == std::string("plain") )
     {
        if( m_NumOfSamples == 12 )
         {
             extractAndPrintFeatures<vpl::lbp::LBP12, vpl::lbp::CPlain>(Stream, Region);
         }
         else
         {
             extractAndPrintFeatures<vpl::lbp::LBP8, vpl::lbp::CPlain>(Stream, Region);
         }
     }
     else if( m_ssMapping == std::string("rotmin") )
     {
         if( m_NumOfSamples == 16 )
         {
             extractAndPrintFeatures<vpl::lbp::LBP16, vpl::lbp::CRotMin>(Stream, Region);
         }
         else if( m_NumOfSamples == 12 )
         {
             extractAndPrintFeatures<vpl::lbp::LBP12, vpl::lbp::CRotMin>(Stream, Region);
         }
         else
         {
             extractAndPrintFeatures<vpl::lbp::LBP8, vpl::lbp::CRotMin>(Stream, Region);
         }
     }
     else if( m_ssMapping == std::string("uniform") )
     {
         if( m_NumOfSamples == 16 )
         {
             extractAndPrintFeatures<vpl::lbp::LBP16, vpl::lbp::CUniform>(Stream, Region);
         }
         else if( m_NumOfSamples == 12 )
         {
             extractAndPrintFeatures<vpl::lbp::LBP12, vpl::lbp::CUniform>(Stream, Region);
         }
         else
         {
             extractAndPrintFeatures<vpl::lbp::LBP8, vpl::lbp::CUniform>(Stream, Region);
         }
     }
     else if( m_ssMapping == std::string("urm") )
     {
         if( m_NumOfSamples == 16 )
         {
             extractAndPrintFeatures<vpl::lbp::LBP16, vpl::lbp::CUniformRotMin>(Stream, Region);
         }
         else if( m_NumOfSamples == 12 )
         {
             extractAndPrintFeatures<vpl::lbp::LBP12, vpl::lbp::CUniformRotMin>(Stream, Region);
         }
         else
         {
             extractAndPrintFeatures<vpl::lbp::LBP8, vpl::lbp::CUniformRotMin>(Stream, Region);
         }
     }
     else
     {
         VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_M << "' parameter value: type -h for help" << std::endl);
         printUsage();
         return false;
     }

     // Write the result to the output channel
	 if (!pOChannel->write(Stream.str().c_str(), vpl::tSize(Stream.str().length())))
     {
         VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output" << std::endl);
         return false;
     }

     // Returning true means to continue processing the input channel
     return false;
}


void CSliceLBPHistogram::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSliceLBPHistogram::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-x iValue] [-y iValue] [-width iValue] [-height iValue]" << std::endl;
    Stream << "                [-m sValue] [-s iValue]" << std::endl;
    Stream << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -x, y  Position of top left corner of an image window" << std::endl;
    Stream << "         from where LBPs will be extracted (zeros by default)." << std::endl;
    Stream << std::endl;
    Stream << "  -width  Width of the image window (whole image by default)." << std::endl;
    Stream << std::endl;
    Stream << "  -height  Height of the window." << std::endl;
    Stream << std::endl;
    Stream << "  -m  Type of the LBP mapping. Please, specify one of the following values" << std::endl;
    Stream << "        plain (no mapping at all)," << std::endl;
    Stream << "        rotmin (rotation invariant LBP)," << std::endl;
    Stream << "        uniform (uniform LBPs only)," << std::endl;
    Stream << "        urm (uniform rotation invariant LBP)" << std::endl;
    Stream << "      The last option is the default one." << std::endl;
    Stream << std::endl;
    Stream << "  -s  Number of samples (8 by default). Moreover," << std::endl;
    Stream << "        12," << std::endl;
    Stream << "        and 16" << std::endl;
    Stream << "      can be given." << std::endl << std::endl;
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
    CSliceLBPHistogramPtr spModule(new CSliceLBPHistogram(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

