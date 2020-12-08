//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2004 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/19                          \n
 *
 * $Id: mdsSliceSubsampling.cpp 2101 2012-02-17 08:20:21Z spanel $
 *
 * File description:
 * - Image subsampling using Gaussian pyramid.
 */

#include "mdsSliceSubsampling.h"

#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsPyramid.h>

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
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceSubsampling::~CSliceSubsampling()
{
}


bool CSliceSubsampling::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
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
        MDS_CERR('<' << m_sFilename << "> Bad " << MODULE_ARGUMENT_RATE << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_uLevels = DEFAULT_LEVEL;
    m_Arguments.value(MODULE_ARGUMENT_LEVEL, m_uLevels);
    if( m_uLevels < 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad " << MODULE_ARGUMENT_LEVEL << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CSliceSubsampling::main()
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
    mds::img::CSlicePtr spNewSlice;

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
                    MDS_LOG_NOTE("Gaussian algorithm choosen.");

                    // Create image pyramid using a specified subsampling rate
                    mds::img::CDImagePyramid Pyramid((mds::tSize)m_uRate,
                                                     (mds::tSize)m_uLevels,
                                                     *spSlice
                                                     );

                    // Create a new slice
                    spNewSlice = new mds::img::CSlice(Pyramid.getImage(m_uLevels - 1));
                }
                break;
                case ALG_NEAREST:
                {
                    MDS_LOG_NOTE("Nearest pixel algorithm choosen.");

                    // Compute dimentions of subsampled image.
                    mds::tSize Width = spSlice->getXSize();
                    mds::tSize Height = spSlice->getYSize();
                    mds::tSize NewWidth = Width >> (m_uLevels - 1);
                    mds::tSize NewHeight = Height >> (m_uLevels - 1);
                    mds::tSize Step = 0x01 << (m_uLevels - 1);

                    // Create new image.
                    spNewSlice = new mds::img::CSlice(NewWidth, NewHeight);

                    // Fill it with nearest values from original image.
                    for( mds::tSize Y = 0; Y < NewHeight; ++Y )
                    {
                        for( mds::tSize X = 0; X < NewWidth; ++X )
                        {
                            const mds::img::tDensityPixel & pixel = spSlice->at(X * Step, Y * Step);
                            spNewSlice->set(X, Y, pixel);
                        }
                    }
                }
                break;
                case ALG_AVERAGE:
                {
                    MDS_LOG_NOTE("Average algorithm choosen.");

                    // Compute dimentions of subsampled image.
                    mds::tSize Width = spSlice->getXSize();
                    mds::tSize Height = spSlice->getYSize();
                    mds::tSize NewWidth = Width >> (m_uLevels - 1);
                    mds::tSize NewHeight = Height >> (m_uLevels - 1);
                    mds::tSize Step = 0x01 << (m_uLevels - 1);

                    // Create new image.
                    spNewSlice = new mds::img::CSlice(NewWidth, NewHeight);

                    // Fill it with average values from original image.
                    for( mds::tSize Y = 0; Y < NewHeight; ++Y )
                    {
                        for( mds::tSize X = 0; X < NewWidth; ++X )
                        {
                            long long int pixel = 0;
                            for( mds::tSize avg_Y = 0; avg_Y < Step; avg_Y++)
                            {
                                for( mds::tSize avg_X = 0; avg_X < Step; avg_X++)
                                {
                                    pixel += spSlice->at((X * Step) + avg_X, (Y * Step) + avg_Y);
                                }
                            }
                            spNewSlice->set(X, Y, mds::img::tDensityPixel(pixel / (Step * Step)));
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
                MDS_CERR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
                return false;
            }
        }
        else
        {
            MDS_CERR('<' << m_sFilename << "> Failed to read input slice" << std::endl);
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


void CSliceSubsampling::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceSubsampling::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-rate uValue] [-levels uValue]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -rate  Used subsampling rate." << std::endl);
    MDS_CERR("  -levels  The number of levels of the Gaussian pyramid." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("Input: MDSTk slice" << std::endl);
    MDS_CERR("Output: MDSTk slice" << std::endl);
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

