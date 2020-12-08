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
 * Copyright (c) 2003-2004 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/19                       
 *
 * File description:
 * - Image subsampling using Gaussian pyramid.
 */

#include "SliceSubsampling.h"

#include <VPL/Image/Slice.h>
#include <VPL/Image/Pyramid.h>

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION = "Module creates a subsampled image using Gaussian pyramid.";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS = "algorithm:rate:levels";

// Additional arguments
const std::string MODULE_ARGUMENT_ALGORITHM = "algorithm";
const std::string MODULE_ARGUMENT_RATE      = "rate";
const std::string MODULE_ARGUMENT_LEVEL     = "levels";

//! Type of the slice coloring method
enum ESubsamplingAlogorithm
{
    ALG_GAUSSIAN = 1,
    ALG_NEAREST,
    ALG_AVERAGE
};

//! Allowed 'algorithm' argument values
const std::string ALG_GAUSSIAN_NAME = "gaussian";
const std::string ALG_NEAREST_NAME  = "nearest";
const std::string ALG_AVERAGE_NAME  = "average";

// Default arguments values
const ESubsamplingAlogorithm DEFAULT_ALGORITHM = ALG_GAUSSIAN;
const unsigned int DEFAULT_RATE                = 2;
const unsigned int DEFAULT_LEVEL               = 2;

//==============================================================================
/*
 * Global variables.
 */

//! Subsampling algorithm
ESubsamplingAlogorithm eAlgorithm;

//==============================================================================
/*
 * Implementation of the class CSliceSubsampling.
 */
CSliceSubsampling::CSliceSubsampling(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceSubsampling::~CSliceSubsampling()
{
}


bool CSliceSubsampling::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Parameters
    m_Arguments.value(MODULE_ARGUMENT_ALGORITHM, m_sAlgorithm);
    if( m_sAlgorithm == ALG_GAUSSIAN_NAME )
    {
        eAlgorithm = ALG_GAUSSIAN;
    }
    else if( m_sAlgorithm == ALG_NEAREST_NAME )
    {
        eAlgorithm = ALG_NEAREST;
    }
    else if( m_sAlgorithm == ALG_AVERAGE_NAME )
    {
        eAlgorithm = ALG_AVERAGE;
    }
    else
    {
        eAlgorithm = DEFAULT_ALGORITHM;
    }

    m_uRate = DEFAULT_RATE;
    m_Arguments.value(MODULE_ARGUMENT_RATE, m_uRate);
    if( m_uRate < 2 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad " << MODULE_ARGUMENT_RATE << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_uLevels = DEFAULT_LEVEL;
    m_Arguments.value(MODULE_ARGUMENT_LEVEL, m_uLevels);
    if( m_uLevels < 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad " << MODULE_ARGUMENT_LEVEL << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CSliceSubsampling::main()
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
    vpl::img::CSlicePtr spSlice;
    vpl::img::CSlicePtr spNewSlice;

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read slice from the input channel
        if( readInput(pIChannel, spSlice.get()) )
        {
            switch (eAlgorithm)
            {
                case ALG_GAUSSIAN:
                {
                    VPL_LOG_INFO("Gaussian algorithm choosen.");

                    // Create image pyramid using a specified subsampling rate
                    vpl::img::CDImagePyramid Pyramid((vpl::tSize)m_uRate,
                                                     (vpl::tSize)m_uLevels,
                                                     *spSlice
                                                     );

                    // Create a new slice
                    spNewSlice = new vpl::img::CSlice(Pyramid.getImage(m_uLevels - 1));
                }
                break;
                case ALG_NEAREST:
                {
                    VPL_LOG_INFO("Nearest pixel algorithm choosen.");

                    // Compute dimentions of subsampled image.
                    vpl::tSize Width = spSlice->getXSize();
                    vpl::tSize Height = spSlice->getYSize();
                    vpl::tSize NewWidth = Width >> (m_uLevels - 1);
                    vpl::tSize NewHeight = Height >> (m_uLevels - 1);
                    vpl::tSize Step = 0x01 << (m_uLevels - 1);

                    // Create new image.
                    spNewSlice = new vpl::img::CSlice(NewWidth, NewHeight);

                    // Fill it with nearest values from original image.
                    for( vpl::tSize Y = 0; Y < NewHeight; ++Y )
                    {
                        for( vpl::tSize X = 0; X < NewWidth; ++X )
                        {
                            const vpl::img::tDensityPixel & pixel = spSlice->at(X * Step, Y * Step);
                            spNewSlice->set(X, Y, pixel);
                        }
                    }
                }
                break;
                case ALG_AVERAGE:
                {
                    VPL_LOG_INFO("Average algorithm choosen.");

                    // Compute dimentions of subsampled image.
                    vpl::tSize Width = spSlice->getXSize();
                    vpl::tSize Height = spSlice->getYSize();
                    vpl::tSize NewWidth = Width >> (m_uLevels - 1);
                    vpl::tSize NewHeight = Height >> (m_uLevels - 1);
                    vpl::tSize Step = 0x01 << (m_uLevels - 1);

                    // Create new image.
                    spNewSlice = new vpl::img::CSlice(NewWidth, NewHeight);

                    // Fill it with average values from original image.
                    for( vpl::tSize Y = 0; Y < NewHeight; ++Y )
                    {
                        for( vpl::tSize X = 0; X < NewWidth; ++X )
                        {
                            long long int pixel = 0;
                            for( vpl::tSize avg_Y = 0; avg_Y < Step; avg_Y++)
                            {
                                for( vpl::tSize avg_X = 0; avg_X < Step; avg_X++)
                                {
                                    pixel += spSlice->at((X * Step) + avg_X, (Y * Step) + avg_Y);
                                }
                            }
                            spNewSlice->set(X, Y, vpl::img::tDensityPixel(pixel / (Step * Step)));
                        }
                    }
                }
                break;
                default:
                {
                    // Nothing.
                }
            }

            // Copy metadata.
            spNewSlice->setPixel(spSlice->getDX(), spSlice->getDY());
            spNewSlice->setThickness(spSlice->getThickness());
            spNewSlice->setPosition(spSlice->getPosition());
            spNewSlice->setOrientation(spSlice->getOrientation());
            spNewSlice->setIndex(spSlice->getIndex());

            // Write it to the output channel
            if( !writeOutput(pOChannel, spNewSlice.get()) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
                return false;
            }
        }
        else
        {
            VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input slice" << std::endl);
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


void CSliceSubsampling::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSliceSubsampling::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-rate uValue] [-levels uValue]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -rate  Used subsampling rate." << std::endl;
    Stream << "  -levels  The number of levels of the Gaussian pyramid." << std::endl;
    Stream << std::endl;
    Stream << "Input: MDSTk slice" << std::endl;
    Stream << "Output: MDSTk slice" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CSliceSubsamplingPtr spModule(new CSliceSubsampling(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

