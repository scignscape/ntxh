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
 * Copyright (c) 2003-2007 by Michal Spanel     
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  
 * Date:    2007/07/03                          
 *
 * Description:
 * - Volume landmark ("3D corner") detection algorithms.
 */

#include "VolumeLandmarkDetector.h"

// MDSTk
#include <VPL/Image/DensityVolume.h>
#include <VPL/Image/LandmarkDetection.h>
#include <VPL/Math/Base.h>

// STl
#include <iostream>
#include <string>
#include <sstream>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module provides 3D landmark detection algorithms";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "detector:size:t:edge:w:draw:cornerness";

//! Additional arguments
const std::string MODULE_ARG_DETECTOR   = "detector";
const std::string MODULE_ARG_SIZE       = "size";
const std::string MODULE_ARG_T          = "t";
const std::string MODULE_ARG_EDGE       = "edge";
const std::string MODULE_ARG_W          = "w";
const std::string MODULE_ARG_DRAW       = "draw";
const std::string MODULE_ARG_CORNERNESS = "cornerness";

//! Default argument values
const int DEFAULT_SIZE                  = 5;
//const double DEFAULT_T					= 0.01;
const double DEFAULT_T                  = 0.4;
const double DEFAULT_EDGE               = 0.25;
//const double DEFAULT_W                  = 20.0;
const double DEFAULT_W                  = 10.0;

//! Allowed argument values
const int MIN_SIZE                      = 1;
const int MAX_SIZE                      = 15;

const double MIN_T						= 0.0;
const double MAX_T						= 1.0;

const double MIN_EDGE                   = 0.0;
const double MAX_EDGE                   = 1.0;


//==============================================================================
/*
 * Implementation of the class CVolumeLandmarkDetector.
 */
CVolumeLandmarkDetector::CVolumeLandmarkDetector(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeLandmarkDetector::~CVolumeLandmarkDetector()
{
}


bool CVolumeLandmarkDetector::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Draws found corner points to the second input volume
    m_bDraw = m_Arguments.exists(MODULE_ARG_DRAW);

    // Test of existence of input and output channel
    if( getNumOfInputs() != ((m_bDraw) ? 2 : 1) || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Is a filter parameter given?
    if( !m_Arguments.exists(MODULE_ARG_DETECTOR) )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Detector was not specified: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Type of image filtering
    m_Arguments.value(MODULE_ARG_DETECTOR, m_ssDetectorName);

    // Parameter 'cornerness'
    m_bCornerness = m_Arguments.exists(MODULE_ARG_CORNERNESS) && (m_ssDetectorName == std::string("rohr"));

    // Parameter 'sigma'
    m_iSize = DEFAULT_SIZE;
    m_Arguments.value(MODULE_ARG_SIZE, m_iSize);
    if( m_iSize > MAX_SIZE || m_iSize < MIN_SIZE )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIZE << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 't'
    m_dT = DEFAULT_T;
    m_Arguments.value(MODULE_ARG_T, m_dT);
    if( m_dT > MAX_T || m_dT < MIN_T )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_T << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'edge'
    m_dEdge = DEFAULT_EDGE;
    m_Arguments.value(MODULE_ARG_EDGE, m_dEdge);
    if( m_dEdge > MAX_EDGE || m_dEdge < MIN_EDGE )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_EDGE << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dW = DEFAULT_W;
    m_Arguments.value(MODULE_ARG_W, m_dW);
    if( m_dW <= 0.0 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_W << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CVolumeLandmarkDetector::main()
{
    // Note
    VPL_LOG_INFO("Module main function");

    // I/O channels
    vpl::mod::CChannel *pIChannel = getInput(0);
    vpl::mod::CChannel *pOChannel = getOutput(0);

    // Create a new volume
    vpl::img::CDensityVolumePtr spVolume(new vpl::img::CDensityVolume());
    vpl::img::CDensityVolumePtr spCornerVolume(new vpl::img::CDensityVolume());

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

    // Read volume data from the input channel
    if( !readInput(pIChannel, spVolume.get()) )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input volume" << std::endl);
        return false;
    }

    // Second input volume used to visualize the model
    if( m_bDraw )
    {
        // I/O channels
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

        // Read volume from the input channel
        if( !readInput(pIChannel, spCornerVolume.get()) )
        {
            VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input corner volume" << std::endl);
            return false;
        }
    }

    // Initialize the output volume
    if( m_bCornerness )
    {
        // Resize the volume
        spCornerVolume->resize(spVolume->getXSize(),
                               spVolume->getYSize(),
                               spVolume->getZSize()
                               );
        spCornerVolume->fillEntire(vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMin());

        // Set properties of the output volume
        spCornerVolume->setVoxel(spVolume->getDX(),
                                 spVolume->getDY(),
                                 spVolume->getDZ()
                                 );
    }

    // Pad volume margin
//    spVolume->mirrorMargin();
    spVolume->fillMargin(0);

    // Output vector of landmarks
    typedef std::vector<vpl::img::CPoint3D> tLandmarks;
    tLandmarks Landmarks;

    // Corner detection
    if( m_ssDetectorName == std::string("rohr") )
    {
        // Harris corner detector
        vpl::img::CRohrLandmarks<vpl::img::CDVolume> Detector(m_iSize, m_dT, m_dEdge);
        if( m_bCornerness )
        {
            Detector(*spVolume, *spCornerVolume);
        }
        else
        {
            Detector(*spVolume, Landmarks);
        }
    }
    else if( m_ssDetectorName == std::string("susan") )
    {
        // Harris corner detector
        vpl::img::CSusanLandmarks<vpl::img::CDVolume> Detector(m_dT, m_dW);
        Detector(*spVolume, Landmarks);
    }
    else
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_DETECTOR << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Visualize all found corners
    if( m_bDraw )
    {
        tLandmarks::iterator itEnd = Landmarks.end();
        for( tLandmarks::iterator it = Landmarks.begin(); it != itEnd; ++it )
        {
            vpl::tSize i = vpl::math::round2Int(it->getX());
            vpl::tSize j = vpl::math::round2Int(it->getY());
            vpl::tSize k = vpl::math::round2Int(it->getZ());

//            vpl::img::CDensityVolume::tVoxel Value = spCornerVolume->get(i, j, k);

            spCornerVolume->set(i, j, k,
//                                Value + vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMax()
                                vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMax()
                                );
        }
    }

    // Visualize all found corners
    if( m_bDraw || m_bCornerness )
    {
        // Write modified volume to the output channel
        if( !writeOutput(pOChannel, spCornerVolume.get()) )
        {
            VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output volume" << std::endl);
            return false;
        }
    }
    else
    {
        // List all found landmarks
        std::stringstream Stream;
        Stream << "-- Found Landmarks --" << std::endl;
        tLandmarks::iterator itEnd = Landmarks.end();
        for( tLandmarks::iterator it = Landmarks.begin(); it != itEnd; ++it )
        {
            Stream << '(' << vpl::math::round2Int(it->getX()) << ", "
                << vpl::math::round2Int(it->getY()) << ", "
                << vpl::math::round2Int(it->getZ()) << ')'
                << std::endl;
        }

        // Write it to the output channel
		if (!pOChannel->write(Stream.str().c_str(), vpl::tSize(Stream.str().length())))
        {
            VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output" << std::endl);
            return false;
        }
    }

    // Returning 'true' means to continue processing the input channel
    return true;
}


void CVolumeLandmarkDetector::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CVolumeLandmarkDetector::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-detector strValue] [-size iValue] [-t dValue]" << std::endl;
    Stream << "                [-edge dValue] [-draw]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -detector  Specifies landmark detector that will be used for detection." << std::endl;
    Stream << "             Supported types are:" << std::endl;
    Stream << "               rohr" << std::endl;
    Stream << "               susan" << std::endl;
    Stream << "             at present." << std::endl;
    Stream << std::endl;
    Stream << "  -size  Size of the sub-window used to estimate derivatives." << std::endl;
    Stream << "         Values in the range " << MIN_SIZE << ".." << MAX_SIZE << std::endl;
    Stream << "         are allowed. Default value is " << DEFAULT_SIZE <<  std::endl;
    Stream << std::endl;
	Stream << "  -t  Threshold used to suppress improbable landmarks." << std::endl;
    Stream << "      Values in the range " << MIN_T << ".." << MAX_T << std::endl;
    Stream << "      can be given. Default value is " << DEFAULT_T <<  std::endl;
    Stream << std::endl;
	Stream << "  -edge  Threshold used to eliminate landmarks lying directly on edges" << std::endl;
    Stream << "         (Rohr's detector only). Values in the range " << MIN_EDGE << ".." << MAX_EDGE << std::endl;
    Stream << "         can be given. Default value is " << DEFAULT_EDGE << "." << std::endl;
    Stream << std::endl;
    Stream << "  -w  Parameter specific for the 3D Susan corner detector." << std::endl;
    Stream << "      Any value greater then zero may be given." << std::endl;
    Stream << "      Default value is " << DEFAULT_W << "." << std::endl;
    Stream << std::endl;
	Stream << "  -draw  Draws all found landmarks to the second input volume." << std::endl;
    Stream << std::endl;
    Stream << "Input: one (or two) MDSTk volumes" << std::endl;
    Stream << "Output: text or MDSTk volume" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CVolumeLandmarkDetectorPtr spModule(new CVolumeLandmarkDetector(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

