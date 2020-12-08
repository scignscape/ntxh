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
 * Copyright (c) 2003-2006 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/04/27                       
 *
 * Description:
 * - Advanced volume edge detection algorithms.
 */

#include "VolumeEdgeDetector.h"

#include <VPL/Image/DensityVolume.h>
#include <VPL/Image/VolumeEdgeDetection.h>

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
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeEdgeDetector::~CVolumeEdgeDetector()
{
}


bool CVolumeEdgeDetector::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    m_bDetectBorder = m_Arguments.exists(MODULE_ARG_DB);

    // Is a filter parameter given?
    if( !m_Arguments.exists(MODULE_ARG_DETECTOR) )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Detector was not specified: type -h for help" << std::endl);
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
            VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIGMA << "' parameter value: type -h for help" << std::endl);
            printUsage();
            return false;
        }*/

    // Parameter 't1'
    m_dT1 = DEFAULT_T1;
    m_Arguments.value(MODULE_ARG_T1, m_dT1);
    if( m_dT1 > MAX_T || m_dT1 < MIN_T )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_T1 << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 't2'
    m_dT2 = DEFAULT_T2;
    m_Arguments.value(MODULE_ARG_T2, m_dT2);
    if( m_dT2 > m_dT1 || m_dT2 < MIN_T )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_T2 << "' parameter value: type -h for help" << std::endl);
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

    // O.K.
    return true;
}


bool CVolumeEdgeDetector::main()
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

    // Create a new density volume
    vpl::img::CDensityVolumePtr spVolume;

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
            vpl::tSize XSize = spVolume->getXSize();
            vpl::tSize YSize = spVolume->getYSize();
            vpl::tSize ZSize = spVolume->getZSize();

            // Create an output slice
            vpl::img::CDensityVolume Filtered(XSize, YSize, ZSize);
            Filtered.fillEntire(vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMin());

            // Set properties of the output volume
            Filtered.setVoxel(spVolume->getDX(), spVolume->getDY(), spVolume->getDZ());

            // Edge detection
            if( m_ssDetectorName == std::string("canny") )
            {
                // Canny Edge Detector
                vpl::img::CVolumeCanny<vpl::img::CDVolume> Detector(m_dT1, m_dT2);
                Detector(*spVolume, Filtered);
            }
            else if( m_ssDetectorName == std::string("nms") )
            {
                vpl::img::CVolumeSobelX<vpl::img::CDVolume> SobelX;
                vpl::img::CVolumeSobelY<vpl::img::CDVolume> SobelY;
                vpl::img::CVolumeSobelZ<vpl::img::CDVolume> SobelZ;

                // For each voxel
                for( vpl::tSize k = 0; k < spVolume->getZSize(); ++k )
                {
                    for( vpl::tSize j = 0; j < spVolume->getYSize(); ++j )
                    {
                        for( vpl::tSize i = 0; i < spVolume->getXSize(); ++i )
                        {
                            // Get the voxel value
                            vpl::img::CDVolume::tVoxel Value = spVolume->at(i, j, k);
                            if( Value > 0 )
                            {
                                // Derivatives in x, y and z direction
                                double dX = SobelX.getResponse(*spVolume, i, j, k);
                                double dY = SobelY.getResponse(*spVolume, i, j, k);
                                double dZ = SobelZ.getResponse(*spVolume, i, j, k);
                                if( vpl::math::getAbs(dX) < 10
                                    && vpl::math::getAbs(dY) < 10
                                    && vpl::math::getAbs(dZ) < 10 )
                                {
                                    Filtered(i, j, k) = Value;
                                    continue;
                                }

                                // Estimate orientation of the edge
                                vpl::img::CVector3D Orient(dX, dY, dZ);
                                Orient.normalize();
                                Orient *= 0.5;

                                // Voxel neighbours
                                vpl::img::CPoint3D Left(i + Orient.x(), j + Orient.y(), k + Orient.z());
                                vpl::img::CPoint3D Right(i - Orient.x(), j - Orient.y(), k - Orient.z());

                                // Interpolate voxel value in place of neighbours
                                vpl::img::CDVolume::tVoxel LeftValue = spVolume->interpolate(Left);
                                vpl::img::CDVolume::tVoxel RightValue = spVolume->interpolate(Right);

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
                VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_DETECTOR << "' parameter value: type -h for help" << std::endl);
                printUsage();
                return false;
            }

            if( m_bDetectBorder )
            {
                vpl::img::tDensityPixel Value = vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMax() / 2;
                for( vpl::tSize x = 0; x < XSize; ++x )
                {
                    for( vpl::tSize y = 0; y < YSize; ++y )
                    {
                        Filtered(x, y, 0) = Filtered(x, y, ZSize - 1) = Value;
                    }
                    for( vpl::tSize z = 0; z < ZSize; ++z )
                    {
                        Filtered(x, 0, z) = Filtered(x, YSize - 1, z) = Value;
                    }
                }
                for( vpl::tSize y = 0; y < YSize; ++y )
                {
                    for( vpl::tSize z = 0; z < ZSize; ++z )
                    {
                        Filtered(0, y, z) = Filtered(XSize - 1, y, z) = Value;
                    }
                }
            }

            // Write it to the output channel
            if( !writeOutput(pOChannel, &Filtered) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output volume" << std::endl);
                return false;
            }
        }
        else
        {
            VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input volume" << std::endl);
            return false;
        }
    }
    else
    {
        VPL_LOG_INFO("Wait timeout");
    }

    // Returning 'true' means to continue processing the input channel
    return true;
}


void CVolumeEdgeDetector::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CVolumeEdgeDetector::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-detector strType] [-t1 dValue] [-t2 dValue]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -detector  Specifies an edge detector that will be used for volume" << std::endl;
    Stream << "             filtering. Supported types are:" << std::endl;
    Stream << "               canny" << std::endl;
    Stream << "             at present." << std::endl;
/*    Stream << std::endl;
    Stream << "  -sigma  Standard deviation (\"sigma\" parameter) of the Canny" << std::endl;
    Stream << "          edge detector. Allowed values are within the range" << std::endl;
    Stream << "          " << MIN_SIGMA << ".." << MAX_SIGMA << " and default value" << std::endl;
    Stream << "          is " << DEFAULT_SIGMA << "." << std::endl;*/
    Stream << std::endl;
    Stream << "  -t1 and -t2  Thresholds affecting the hysteresis provided by Canny" << std::endl;
    Stream << "               edge detector. Values in the range " << MIN_T << ".." << MAX_T << std::endl;
    Stream << "               can be given. Be sure of t1 value is greater than t2!" << std::endl;
    Stream << "               Default values are t1 = " << DEFAULT_T1 << " and" << std::endl;
    Stream << "               t2 = " << DEFAULT_T2 << "." << std::endl;
/*    Stream << std::endl;
    Stream << "  -t  Threshold of the magnitude of derivatives computed by zero" << std::endl;
    Stream << "      crossing edge detector. Values in the range " << MIN_T << ".." << MAX_T << " can be given." << std::endl;
    Stream << "      Default value is t = " << DEFAULT_T << "." << std::endl;*/
    Stream << std::endl;
    Stream << "Input: MDSTk volume" << std::endl;
    Stream << "Output: MDSTk volume" << std::endl;
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

