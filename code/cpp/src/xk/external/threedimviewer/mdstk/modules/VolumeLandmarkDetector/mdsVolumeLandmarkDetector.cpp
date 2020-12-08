//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)       \n
 * Copyright (c) 2003-2007 by Michal Spanel        \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz     \n
 * Date:    2007/07/03                             \n
 *
 * $Id: mdsVolumeLandmarkDetector.cpp 2102 2012-02-17 09:12:21Z spanel $
 *
 * Description:
 * - Volume landmark ("3D corner") detection algorithms.
 */

#include "mdsVolumeLandmarkDetector.h"

// MDSTk
#include <MDSTk/Image/mdsDensityVolume.h>
#include <MDSTk/Image/mdsLandmarkDetection.h>
#include <MDSTk/Math/mdsBase.h>

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
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeLandmarkDetector::~CVolumeLandmarkDetector()
{
}


bool CVolumeLandmarkDetector::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Draws found corner points to the second input volume
    m_bDraw = m_Arguments.exists(MODULE_ARG_DRAW);

    // Test of existence of input and output channel
    if( getNumOfInputs() != ((m_bDraw) ? 2 : 1) || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Is a filter parameter given?
    if( !m_Arguments.exists(MODULE_ARG_DETECTOR) )
    {
        MDS_CERR('<' << m_sFilename << "> Detector was not specified: type -h for help" << std::endl);
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
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIZE << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 't'
    m_dT = DEFAULT_T;
    m_Arguments.value(MODULE_ARG_T, m_dT);
    if( m_dT > MAX_T || m_dT < MIN_T )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_T << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'edge'
    m_dEdge = DEFAULT_EDGE;
    m_Arguments.value(MODULE_ARG_EDGE, m_dEdge);
    if( m_dEdge > MAX_EDGE || m_dEdge < MIN_EDGE )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_EDGE << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dW = DEFAULT_W;
    m_Arguments.value(MODULE_ARG_W, m_dW);
    if( m_dW <= 0.0 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_W << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CVolumeLandmarkDetector::main()
{
    // Note
    MDS_LOG_NOTE("Module main function");

    // I/O channels
    mds::mod::CChannel *pIChannel = getInput(0);
    mds::mod::CChannel *pOChannel = getOutput(0);

    // Create a new volume
    mds::img::CDensityVolumePtr spVolume(new mds::img::CDensityVolume());
    mds::img::CDensityVolumePtr spCornerVolume(new mds::img::CDensityVolume());

    // Is any input?
    if( !pIChannel->isConnected() )
    {
        return false;
    }

    // Wait for data
    if( !pIChannel->wait(1000) )
    {
        MDS_LOG_NOTE("Wait timeout");
        return true;
    }

    // Read volume data from the input channel
    if( !readInput(pIChannel, spVolume.get()) )
    {
        MDS_CERR('<' << m_sFilename << "> Failed to read input volume" << std::endl);
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
            MDS_LOG_NOTE("Wait timeout");
            return true;
        }

        // Read volume from the input channel
        if( !readInput(pIChannel, spCornerVolume.get()) )
        {
            MDS_CERR('<' << m_sFilename << "> Failed to read input corner volume" << std::endl);
            return false;
        }
    }

    // Initialize the output volume
    if( m_bCornerness )
    {
        // Resize the volume
        spCornerVolume->create(spVolume->getXSize(),
                               spVolume->getYSize(),
                               spVolume->getZSize()
                               );
        spCornerVolume->fillEntire(mds::img::CPixelTraits<mds::img::tDensityPixel>::getPixelMin());

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
    typedef std::vector<mds::img::CPoint3D> tLandmarks;
    tLandmarks Landmarks;

    // Corner detection
    if( m_ssDetectorName == std::string("rohr") )
    {
        // Harris corner detector
        mds::img::CRohrLandmarks<mds::img::CDVolume> Detector(m_iSize, m_dT, m_dEdge);
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
        mds::img::CSusanLandmarks<mds::img::CDVolume> Detector(m_dT, m_dW);
        Detector(*spVolume, Landmarks);
    }
    else
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_DETECTOR << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Visualize all found corners
    if( m_bDraw )
    {
        tLandmarks::iterator itEnd = Landmarks.end();
        for( tLandmarks::iterator it = Landmarks.begin(); it != itEnd; ++it )
        {
            mds::tSize i = mds::math::round2Int(it->getX());
            mds::tSize j = mds::math::round2Int(it->getY());
            mds::tSize k = mds::math::round2Int(it->getZ());

//            mds::img::CDensityVolume::tVoxel Value = spCornerVolume->get(i, j, k);

            spCornerVolume->set(i, j, k,
//                                Value + mds::img::CPixelTraits<mds::img::tDensityPixel>::getPixelMax()
                                mds::img::CPixelTraits<mds::img::tDensityPixel>::getPixelMax()
                                );
        }
    }

    // Visualize all found corners
    if( m_bDraw || m_bCornerness )
    {
        // Write modified volume to the output channel
        if( !writeOutput(pOChannel, spCornerVolume.get()) )
        {
            MDS_CERR('<' << m_sFilename << "> Failed to write the output volume" << std::endl);
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
            Stream << '(' << mds::math::round2Int(it->getX()) << ", "
                << mds::math::round2Int(it->getY()) << ", "
                << mds::math::round2Int(it->getZ()) << ')'
                << std::endl;
        }

        // Write it to the output channel
        if( !pOChannel->write(Stream.str().c_str(), (int)Stream.str().length()) )
        {
            MDS_CERR('<' << m_sFilename << "> Failed to write the output" << std::endl);
            return false;
        }
    }

    // Returning 'true' means to continue processing the input channel
    return true;
}


void CVolumeLandmarkDetector::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CVolumeLandmarkDetector::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-detector strValue] [-size iValue] [-t dValue]" << std::endl);
    MDS_CERR("                [-edge dValue] [-draw]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -detector  Specifies landmark detector that will be used for detection." << std::endl);
    MDS_CERR("             Supported types are:" << std::endl);
    MDS_CERR("               rohr" << std::endl);
    MDS_CERR("               susan" << std::endl);
    MDS_CERR("             at present." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -size  Size of the sub-window used to estimate derivatives." << std::endl);
    MDS_CERR("         Values in the range " << MIN_SIZE << ".." << MAX_SIZE << std::endl);
    MDS_CERR("         are allowed. Default value is " << DEFAULT_SIZE <<  std::endl);
    MDS_CERR(std::endl);
	MDS_CERR("  -t  Threshold used to suppress improbable landmarks." << std::endl);
    MDS_CERR("      Values in the range " << MIN_T << ".." << MAX_T << std::endl);
    MDS_CERR("      can be given. Default value is " << DEFAULT_T <<  std::endl);
    MDS_CERR(std::endl);
	MDS_CERR("  -edge  Threshold used to eliminate landmarks lying directly on edges" << std::endl);
    MDS_CERR("         (Rohr's detector only). Values in the range " << MIN_EDGE << ".." << MAX_EDGE << std::endl);
    MDS_CERR("         can be given. Default value is " << DEFAULT_EDGE << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -w  Parameter specific for the 3D Susan corner detector." << std::endl);
    MDS_CERR("      Any value greater then zero may be given." << std::endl);
    MDS_CERR("      Default value is " << DEFAULT_W << "." << std::endl);
    MDS_CERR(std::endl);
	MDS_CERR("  -draw  Draws all found landmarks to the second input volume." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("Input: one (or two) MDSTk volumes" << std::endl);
    MDS_CERR("Output: text or MDSTk volume" << std::endl);
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

