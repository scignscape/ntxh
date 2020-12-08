//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/04/27                          \n
 *
 * $Id: mdsVolumeEdgeDetector.cpp 2102 2012-02-17 09:12:21Z spanel $
 *
 * Description:
 * - Advanced volume edge detection algorithms.
 */

#include "mdsVolumeEdgeDetector.h"

#include <MDSTk/Image/mdsDensityVolume.h>
#include <MDSTk/Image/mdsVolumeEdgeDetection.h>

// STl
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module provides advanced volume edge detection algorithms";

//! Additional command line arguments
//const std::string MODULE_ARGUMENTS      = "detector:t1:t2:t:detectborder";
const std::string MODULE_ARGUMENTS      = "detector:t1:t2:detectborder";

//! Additional arguments
const std::string MODULE_ARG_DETECTOR   = "detector";
const std::string MODULE_ARG_SIGMA      = "sigma";
const std::string MODULE_ARG_T1         = "t1";
const std::string MODULE_ARG_T2         = "t2";
const std::string MODULE_ARG_T          = "t";
const std::string MODULE_ARG_DB         = "detectborder";

//! Default argument values
const double DEFAULT_SIGMA              = 0.75;
const double DEFAULT_T1                 = 0.05;
const double DEFAULT_T2                 = 0.02;
//const double DEFAULT_T1                 = 0.02;
//const double DEFAULT_T2                 = 0.01;
const double DEFAULT_T                  = 0.05;

//! Allowed argument values
const double MIN_SIGMA                  = 0.5;
const double MAX_SIGMA                  = 3.0;

const double MIN_T                      = 0.0;
const double MAX_T                      = 1.0;


//==============================================================================
/*
 * Implementation of the class CSliceFilter.
 */
CVolumeEdgeDetector::CVolumeEdgeDetector(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeEdgeDetector::~CVolumeEdgeDetector()
{
}


bool CVolumeEdgeDetector::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    m_bDetectBorder = m_Arguments.exists(MODULE_ARG_DB);

    // Is a filter parameter given?
    if( !m_Arguments.exists(MODULE_ARG_DETECTOR) )
    {
        MDS_CERR('<' << m_sFilename << "> Detector was not specified: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Type of image filtering
    m_Arguments.value(MODULE_ARG_DETECTOR, m_ssDetectorName);

    // Parameter 'sigma'
    /*    m_dSigma = DEFAULT_SIGMA;
        m_Arguments.value(MODULE_ARG_SIGMA, m_dSigma);
        if( m_dSigma > MAX_SIGMA || m_dSigma < MIN_SIGMA )
        {
            MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIGMA << "' parameter value: type -h for help" << std::endl);
            printUsage();
            return false;
        }*/

    // Parameter 't1'
    m_dT1 = DEFAULT_T1;
    m_Arguments.value(MODULE_ARG_T1, m_dT1);
    if( m_dT1 > MAX_T || m_dT1 < MIN_T )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_T1 << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 't2'
    m_dT2 = DEFAULT_T2;
    m_Arguments.value(MODULE_ARG_T2, m_dT2);
    if( m_dT2 > m_dT1 || m_dT2 < MIN_T )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_T2 << "' parameter value: type -h for help" << std::endl);
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

    // O.K.
    return true;
}


bool CVolumeEdgeDetector::main()
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

    // Create a new density volume
    mds::img::CDensityVolumePtr spVolume;

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read volume data from the input channel
        if( readInput(pIChannel, spVolume.get()) )
        {
            // Pad volume margin
            spVolume->mirrorMargin();
//            spVolume->fillMargin(0);

            // Volume size
            mds::tSize XSize = spVolume->getXSize();
            mds::tSize YSize = spVolume->getYSize();
            mds::tSize ZSize = spVolume->getZSize();

            // Create an output slice
            mds::img::CDensityVolume Filtered(XSize, YSize, ZSize);
            Filtered.fillEntire(mds::img::CPixelTraits<mds::img::tDensityPixel>::getPixelMin());

            // Set properties of the output volume
            Filtered.setVoxel(spVolume->getDX(), spVolume->getDY(), spVolume->getDZ());

            // Edge detection
            if( m_ssDetectorName == std::string("canny") )
            {
                // Canny Edge Detector
                mds::img::CVolumeCanny<mds::img::CDVolume> Detector(m_dT1, m_dT2);
                Detector(*spVolume, Filtered);
            }
            else if( m_ssDetectorName == std::string("nms") )
            {
                mds::img::CVolumeSobelX<mds::img::CDVolume> SobelX;
                mds::img::CVolumeSobelY<mds::img::CDVolume> SobelY;
                mds::img::CVolumeSobelZ<mds::img::CDVolume> SobelZ;

                // For each voxel
                for( mds::tSize k = 0; k < spVolume->getZSize(); ++k )
                {
                    for( mds::tSize j = 0; j < spVolume->getYSize(); ++j )
                    {
                        for( mds::tSize i = 0; i < spVolume->getXSize(); ++i )
                        {
                            // Get the voxel value
                            mds::img::CDVolume::tVoxel Value = spVolume->at(i, j, k);
                            if( Value > 0 )
                            {
                                // Derivatives in x, y and z direction
                                double dX = SobelX.getResponse(*spVolume, i, j, k);
                                double dY = SobelY.getResponse(*spVolume, i, j, k);
                                double dZ = SobelZ.getResponse(*spVolume, i, j, k);
                                if( mds::math::getAbs(dX) < 10
                                    && mds::math::getAbs(dY) < 10
                                    && mds::math::getAbs(dZ) < 10 )
                                {
                                    Filtered(i, j, k) = Value;
                                    continue;
                                }

                                // Estimate orientation of the edge
                                mds::img::CVector3D Orient(dX, dY, dZ);
                                Orient.normalize();
                                Orient *= 0.5;

                                // Voxel neighbours
                                mds::img::CPoint3D Left(i + Orient.x(), j + Orient.y(), k + Orient.z());
                                mds::img::CPoint3D Right(i - Orient.x(), j - Orient.y(), k - Orient.z());

                                // Interpolate voxel value in place of neighbours
                                mds::img::CDVolume::tVoxel LeftValue = spVolume->interpolate(Left);
                                mds::img::CDVolume::tVoxel RightValue = spVolume->interpolate(Right);

                                // Check if the voxel is local maximum
                                if( Value >= LeftValue && Value >= RightValue )
                                {
                                    Filtered(i, j, k) = Value;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_DETECTOR << "' parameter value: type -h for help" << std::endl);
                printUsage();
                return false;
            }

            if( m_bDetectBorder )
            {
                mds::img::tDensityPixel Value = mds::img::CPixelTraits<mds::img::tDensityPixel>::getPixelMax() / 2;
                for( mds::tSize x = 0; x < XSize; ++x )
                {
                    for( mds::tSize y = 0; y < YSize; ++y )
                    {
                        Filtered(x, y, 0) = Filtered(x, y, ZSize - 1) = Value;
                    }
                    for( mds::tSize z = 0; z < ZSize; ++z )
                    {
                        Filtered(x, 0, z) = Filtered(x, YSize - 1, z) = Value;
                    }
                }
                for( mds::tSize y = 0; y < YSize; ++y )
                {
                    for( mds::tSize z = 0; z < ZSize; ++z )
                    {
                        Filtered(0, y, z) = Filtered(XSize - 1, y, z) = Value;
                    }
                }
            }

            // Write it to the output channel
            if( !writeOutput(pOChannel, &Filtered) )
            {
                MDS_CERR('<' << m_sFilename << "> Failed to write the output volume" << std::endl);
                return false;
            }
        }
        else
        {
            MDS_CERR('<' << m_sFilename << "> Failed to read input volume" << std::endl);
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


void CVolumeEdgeDetector::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CVolumeEdgeDetector::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-detector strType] [-t1 dValue] [-t2 dValue]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -detector  Specifies an edge detector that will be used for volume" << std::endl);
    MDS_CERR("             filtering. Supported types are:" << std::endl);
    MDS_CERR("               canny" << std::endl);
    MDS_CERR("             at present." << std::endl);
/*    MDS_CERR(std::endl);
    MDS_CERR("  -sigma  Standard deviation (\"sigma\" parameter) of the Canny" << std::endl);
    MDS_CERR("          edge detector. Allowed values are within the range" << std::endl);
    MDS_CERR("          " << MIN_SIGMA << ".." << MAX_SIGMA << " and default value" << std::endl);
    MDS_CERR("          is " << DEFAULT_SIGMA << "." << std::endl);*/
    MDS_CERR(std::endl);
    MDS_CERR("  -t1 and -t2  Thresholds affecting the hysteresis provided by Canny" << std::endl);
    MDS_CERR("               edge detector. Values in the range " << MIN_T << ".." << MAX_T << std::endl);
    MDS_CERR("               can be given. Be sure of t1 value is greater than t2!" << std::endl);
    MDS_CERR("               Default values are t1 = " << DEFAULT_T1 << " and" << std::endl);
    MDS_CERR("               t2 = " << DEFAULT_T2 << "." << std::endl);
/*    MDS_CERR(std::endl);
    MDS_CERR("  -t  Threshold of the magnitude of derivatives computed by zero" << std::endl);
    MDS_CERR("      crossing edge detector. Values in the range " << MIN_T << ".." << MAX_T << " can be given." << std::endl);
    MDS_CERR("      Default value is t = " << DEFAULT_T << "." << std::endl);*/
    MDS_CERR(std::endl);
    MDS_CERR("Input: MDSTk volume" << std::endl);
    MDS_CERR("Output: MDSTk volume" << std::endl);
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CVolumeEdgeDetectorPtr spModule(new CVolumeEdgeDetector(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

