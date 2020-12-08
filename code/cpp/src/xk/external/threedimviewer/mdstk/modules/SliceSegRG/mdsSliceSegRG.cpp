//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)             \n
 * Copyright (c) 2003-2005 by Michal Spanel              \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz           \n
 *          Martin Skotnica, xskotn01@stud.fit.vutbr.cz  \n
 * Date:    2004/03/01                                   \n
 *
 * $Id: mdsSliceSegRG.cpp 2101 2012-02-17 08:20:21Z spanel $
 *
 * Description:
 * - Simple region growing slice segmentation.
 */

#include <MDSTk/Image/mdsSlice.h>

#include "mdsSliceSegRG.h"
#include "mdsRegionGrowing.h"

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module providing a simple region growing segmentation";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "wdiff:wedge:t:merge";

//! Additional arguments
const std::string MODULE_ARGUMENT_WD    = "wdiff";
const std::string MODULE_ARGUMENT_WE    = "wedge";
const std::string MODULE_ARGUMENT_T     = "t";
const std::string MODULE_ARGUMENT_M     = "merge";

//! Default argument values
const double DEFAULT_WD                 = 1.0;
const double DEFAULT_WE                 = 0.0;
const int DEFAULT_T                     = 300;


//==============================================================================
/*
 * Implementation of the class CSliceSegRG.
 */
CSliceSegRG::CSliceSegRG(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceSegRG::~CSliceSegRG()
{
}


bool CSliceSegRG::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line arguments
    m_iThreshold = DEFAULT_T;
    m_Arguments.value(MODULE_ARGUMENT_T, m_iThreshold);
    if( m_iThreshold < 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARGUMENT_T << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dWeightDiff = DEFAULT_WD;
    m_Arguments.value(MODULE_ARGUMENT_WD, m_dWeightDiff);
    if( m_dWeightDiff < 0.0 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dWeightEdge = DEFAULT_WE;
    m_Arguments.value(MODULE_ARGUMENT_WE, m_dWeightEdge);
    if( m_dWeightEdge < 0.0 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_bMerge = m_Arguments.exists(MODULE_ARGUMENT_M);

    // O.K.
    return true;
}


bool CSliceSegRG::main()
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

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read slice from the input channel
        if( readInput(pIChannel, spSlice.get()) )
        {
            // Create a new slice
            // - copy of the input one
            mds::img::CSlicePtr spSegmented(new mds::img::CSlice(*spSlice));

            // Image segmentation method
            mds::imseg::CRegionGrowing Method(m_dWeightDiff,
                                              m_dWeightEdge,
                                              m_iThreshold,
                                              m_bMerge
                                              );

            // Segmentation
            if( !Method(*spSlice, *spSegmented) )
            {
                MDS_CERR('<' << m_sFilename << "> Cannot process image segmentation" << std::endl);
            }

            // Write the result to the output channel
            if( !writeOutput(pOChannel, spSegmented.get()) )
            {
                MDS_CERR('<' << m_sFilename << "> Failed to write the segmented slice" << std::endl);
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


void CSliceSegRG::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceSegRG::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-t uValue] [-wdiff dValue] [-wedge dValue] [-merge]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -t  Threshold used for adding pixels to a region." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -wdiff  Weight of the distance component of a pixel similarity measure." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -wedge  Weight of the image edge component of the measure." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -merge  Enables merging of produced regions." << std::endl);
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
    CSliceSegRGPtr spModule(new CSliceSegRG(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

