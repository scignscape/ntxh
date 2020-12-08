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
 * - Statistical comparison of two images using histogram of LBP codes.
 */

#include "SliceLBPCompare.h"

// MDSTk
#include <VPL/Image/Slice.h>
#include <VPL/Image/LBP/Extractor.h>
#include <VPL/Image/FeatureExtraction/DistanceMeasure.h>

// STL
#include <iostream>
#include <sstream>


//==============================================================================
/*
 * Global constants.
 */

//! Module description.
const std::string MODULE_DESCRIPTION    = "Compares LBP histograms of two images.";

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
 * Compares two LBP histograms and writes the result.
 */
template <vpl::lbp::ECodeType Type, template <vpl::lbp::ECodeType> class Mapping>
void extractAndCompareFeatures(std::stringstream& Stream,
                               vpl::img::CDImage& Image1,
                               vpl::img::CDImage& Image2
                               )
{
    typedef vpl::lbp::CLBPExtractor<vpl::img::CDImage, Type, Mapping> tExtractor;
    typedef typename tExtractor::tVector tFeatures;

    // Extract LBP histogram from the first image
    tExtractor Extractor;
    tFeatures v1, v2;
    Extractor.accumulate(&Image1);
    Extractor.evaluate(v1);

    // Process the second image
    Extractor.clear();
    Extractor.accumulate(&Image2);
    Extractor.evaluate(v2);

    // Compare histograms
    double dResult = vpl::img::CChiSquare<tFeatures>::calculate(v1, v2);

    // Print the result
    Stream << dResult << std::endl;
}


//==============================================================================
/*
 * Implementation of the class CSliceLBPCompare.
 */
CSliceLBPCompare::CSliceLBPCompare(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    // Allow additional command line arguments
    allowArguments(MODULE_ARGUMENTS);
}


CSliceLBPCompare::~CSliceLBPCompare()
{
}


bool CSliceLBPCompare::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 2 || getNumOfOutputs() != 1 )
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

    return true;
}


bool CSliceLBPCompare::main()
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
    vpl::img::CSlice Slice, Slice2;

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

    // Second input image
    pIChannel = getInput(1);

    // Is any input?
    if( !pIChannel->isConnected() )
    {
        return false;
    }

    // Wait for data
    if( !pIChannel->wait(1000) )
    {
        VPL_LOG_INFO("Wait timeout");
        return true;
    }

    // Read slice from the input channel
    if( !readInput(pIChannel, &Slice2) )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input slice" << std::endl);
        return false;
    }

    // Image size
    vpl::tSize XSize = vpl::math::getMin(Slice.getXSize(), Slice2.getXSize());
    vpl::tSize YSize = vpl::math::getMin(Slice.getYSize(), Slice2.getYSize());

    // Check parameters
    vpl::math::limit<int>(m_X, 0, XSize - 1);
    vpl::math::limit<int>(m_Y, 0, YSize - 1);
    m_Width = (m_Width == -1) ? XSize : m_Width;
    m_Height = (m_Height == -1) ? YSize : m_Width;
    vpl::math::limit<int>(m_Width, 0, XSize - m_X - 1);
    vpl::math::limit<int>(m_Height, 0, YSize - m_Y - 1);

    // Log modified parameters
    VPL_LOG_INFO("Window position (" << m_X << ", " << m_Y << ")");
    VPL_LOG_INFO("Window size (" << m_Width << ", " << m_Height << ")");

    // Prepare image window
    vpl::img::CDImage Region, Region2;
    Region.makeRef(Slice, m_X, m_Y, m_Width, m_Height);
    Region2.makeRef(Slice2, m_X, m_Y, m_Width, m_Height);

    // Extract LBP codes from the window
    std::stringstream Stream;
    if( m_ssMapping == std::string("plain") )
    {
        if( m_NumOfSamples == 12 )
        {
            extractAndCompareFeatures<vpl::lbp::LBP12, vpl::lbp::CPlain>(Stream, Region, Region2);
        }
        else
        {
            extractAndCompareFeatures<vpl::lbp::LBP8, vpl::lbp::CPlain>(Stream, Region, Region2);
        }
    }
    else if( m_ssMapping == std::string("rotmin") )
    {
        if( m_NumOfSamples == 16 )
        {
            extractAndCompareFeatures<vpl::lbp::LBP16, vpl::lbp::CRotMin>(Stream, Region, Region2);
        }
        else if( m_NumOfSamples == 12 )
        {
            extractAndCompareFeatures<vpl::lbp::LBP12, vpl::lbp::CRotMin>(Stream, Region, Region2);
        }
        else
        {
            extractAndCompareFeatures<vpl::lbp::LBP8, vpl::lbp::CRotMin>(Stream, Region, Region2);
        }
    }
    else if( m_ssMapping == std::string("uniform") )
    {
        if( m_NumOfSamples == 16 )
        {
            extractAndCompareFeatures<vpl::lbp::LBP16, vpl::lbp::CUniform>(Stream, Region, Region2);
        }
        else if( m_NumOfSamples == 12 )
        {
            extractAndCompareFeatures<vpl::lbp::LBP12, vpl::lbp::CUniform>(Stream, Region, Region2);
        }
        else
        {
            extractAndCompareFeatures<vpl::lbp::LBP8, vpl::lbp::CUniform>(Stream, Region, Region2);
        }
    }
    else if( m_ssMapping == std::string("urm") )
    {
        if( m_NumOfSamples == 16 )
        {
            extractAndCompareFeatures<vpl::lbp::LBP16, vpl::lbp::CUniformRotMin>(Stream, Region, Region2);
        }
        else if( m_NumOfSamples == 12 )
        {
            extractAndCompareFeatures<vpl::lbp::LBP12, vpl::lbp::CUniformRotMin>(Stream, Region, Region2);
        }
        else
        {
            extractAndCompareFeatures<vpl::lbp::LBP8, vpl::lbp::CUniformRotMin>(Stream, Region, Region2);
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


void CSliceLBPCompare::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSliceLBPCompare::writeExtendedUsage(std::ostream& Stream)
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
    Stream << "Input: two MDSTk slices in separate channels" << std::endl;
    Stream << "Output: text" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CSliceLBPComparePtr spModule(new CSliceLBPCompare(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

