//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/08                          \n
 *
 * $Id: mdsSliceOpticalFlow.cpp 2100 2012-02-17 07:36:55Z spanel $
 *
 * Description:
 * - Optical flow estimation and visualization module.
 */

#include "mdsSliceOpticalFlow.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsImageFiltering.h>
#include <MDSTk/Image/OpticalFlow/mdsLucasKanade.h>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION        = "Optical flow estimation and visualization module";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS          = "grid:levels";

//! Additional arguments
const std::string MODULE_ARGUMENT_GRID      = "grid";
const std::string MODULE_ARGUMENT_LEVELS    = "levels";

//! Default argument values
const int DEFAULT_GRID      = 10;
const int DEFAULT_LEVELS    = 1;

//! Maximal grid size
const int MAX_GRID          = 50;

//! Maximal image pyramid levels
const int MAX_LEVELS        = 4;


//==============================================================================
/*
 * Global variables.
 */

//! Temporary image pyramids
mds::img::CDImagePyramidPtr spPyramid0, spPyramid1;

//! Pointer to the previously loaded slice
mds::img::CDImagePyramidPtr spPrevious(spPyramid0);

//! Pointer to the current slice
mds::img::CDImagePyramidPtr spCurrent(spPyramid1);


//==============================================================================
/*
 * Implementation of the class CSliceOpticalFlow.
 */
CSliceOpticalFlow::CSliceOpticalFlow(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceOpticalFlow::~CSliceOpticalFlow()
{
}


bool CSliceOpticalFlow::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Grid size parameter
    m_iGrid = DEFAULT_GRID;
    m_Arguments.value(MODULE_ARGUMENT_GRID, m_iGrid);
    if( m_iGrid <= 0 || m_iGrid > MAX_GRID )
    {
        MDS_CERR('<' << m_sFilename << "> Bad grid parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Pyramid levels parameter
    m_iLevels = DEFAULT_LEVELS;
    m_Arguments.value(MODULE_ARGUMENT_LEVELS, m_iLevels);
    if( m_iLevels <= 0 || m_iLevels > MAX_LEVELS )
    {
        MDS_CERR('<' << m_sFilename << "> Bad levels parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CSliceOpticalFlow::main()
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
    mds::img::CSlicePtr spSlice(new mds::img::CSlice());
    mds::img::CSlicePtr spFiltered(new mds::img::CSlice());

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read slice from the input channel
        if( readInput(pIChannel, spSlice.get()) )
        {
            // Filter used for image preprocessing
//            mds::img::CAvg5Filter<mds::img::CDImage> Filter;
//            mds::img::CGaussFilter<mds::img::CDImage> Filter(7);

            mds::img::CSobelX<mds::img::CDImage, mds::img::CMakeAbs> FilterX;
            mds::img::CSobelY<mds::img::CDImage, mds::img::CMakeAbs> FilterY;

            // Preprocess the image
            spFiltered->create(spSlice->getXSize(), spSlice->getYSize());
//            Filter(*spSlice, *spFiltered);
            FilterX(*spSlice, *spFiltered);

            mds::img::CDImage Filtered2;
            Filtered2.create(spSlice->getXSize(), spSlice->getYSize());
            FilterY(*spSlice, Filtered2);
            *spFiltered += Filtered2;

            // First slice of the sequence?
            if( spPrevious->getLevels() > 0 )
            {
                // Create image pyramids
                spCurrent->create(2, m_iLevels, *spFiltered);

                // Motion image size
                mds::tSize XSize = mds::math::getMin(spPrevious->getXSize(0), spCurrent->getXSize(0));
                mds::tSize YSize = mds::math::getMin(spPrevious->getYSize(0), spCurrent->getYSize(0));

                // Create an output slice
                mds::img::CSlicePtr spMotion(new mds::img::CSlice(XSize, YSize));
                spMotion->fillEntire(mds::img::CPixelTraits<mds::img::tDensityPixel>::getPixelMin());

                // Point optical flow
//                mds::img::COpticalFlow OptFlow(11);
//                mds::img::COpticalFlow<mds::img::CDImage> OptFlow(13);
//                mds::img::COpticalFlow<mds::img::CDImage> OptFlow(21);
                mds::img::COpticalFlow<mds::img::CDImage> OptFlow(13);

                // Compute optical flow between two consecutive slices
                mds::tSize MaxX = XSize - m_iGrid;
                mds::tSize MaxY = YSize - m_iGrid;
                for( mds::tSize y = m_iGrid; y < MaxY; y += m_iGrid )
                {
                    OptFlow.getPosition().y() = mds::img::tCoordinate(y);
                    for( mds::tSize x = m_iGrid; x < MaxX; x += m_iGrid )
                    {
                        OptFlow.getPosition().x() = mds::img::tCoordinate(x);
                        if( OptFlow.compute(*spPrevious, *spCurrent) )
                        {
                            OptFlow.visualize(*spMotion);
                        }
                    }
                }

                // Exchange the image pyramids
                mds::img::CDImagePyramidPtr spPyramid(spPrevious);
                spPrevious = spCurrent;
                spCurrent = spPyramid;

                // Write it to the output channel
                if( !writeOutput(pOChannel, spMotion.get()) )
                {
                    MDS_CERR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
                }
            }
            else
            {
                // Create the image pyramid
                spPrevious->create(2, m_iLevels, *spFiltered);
            }
        }
    }
    else
    {
        MDS_LOG_NOTE("Wait timeout");
    }

    // Returning 'true' means to continue processing the input channel
    return true;
}


void CSliceOpticalFlow::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceOpticalFlow::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage:" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -grid  Optical flow is estimated in points regular distributed over" << std::endl);
    MDS_CERR("         a 2D mesh. The parameter specifies the range between" << std::endl);
    MDS_CERR("         two neighbouring points in the mesh." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -levels  The number of levels of the used image pyramid. The" << std::endl);
    MDS_CERR("           default value is " << DEFAULT_LEVELS << "." << std::endl);
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
    CSliceOpticalFlowPtr spModule(new CSliceOpticalFlow(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

