//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)           \n
 * Copyright (c) 2003-2005 by Michal Spanel            \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz         \n
 *          Miroslav Svub, xsvubm00@stud.fit.vutbr.cz  \n
 * Date:    2004/10/24                                 \n
 *
 * $Id: mdsSliceSegHT.cpp 2101 2012-02-17 08:20:21Z spanel $
 *
 * File description:
 * - Simple segmentation method based on histogram thresholding.
 */

#include <MDSTk/Image/mdsSlice.h>

#include "mdsSliceSegHT.h"
#include "mdsHistogramThresholding.h"

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module provides simple histogram thresholding segmentation";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "thresholds:columns";

//! Additional arguments
const std::string MODULE_ARGUMENT_T     = "thresholds";
const std::string MODULE_ARGUMENT_C     = "columns";

//! Default argument values
const int DEFAULT_T                     = 4;
const int DEFAULT_C                     = 64;


//==============================================================================
/*
 * Implementation of the class CSliceSegHT.
 */
CSliceSegHT::CSliceSegHT(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceSegHT::~CSliceSegHT()
{
}


bool CSliceSegHT::startup()
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
    m_iThresholds = DEFAULT_T;
    m_Arguments.value(MODULE_ARGUMENT_T, m_iThresholds);
    if( m_iThresholds < 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'tresholds' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_iColumns = DEFAULT_C;
    m_Arguments.value(MODULE_ARGUMENT_C, m_iColumns);
    if( m_iColumns < 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'columns' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CSliceSegHT::main()
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

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read slice from the input channel
        if( readInput(pIChannel, spSlice.get()) )
        {
            // Create a new slice
            // - copy of the input one
            mds::img::CSlice Segmented(*spSlice);

            // Image segmentation method
            mds::imseg::CHistogramThresholding Method(m_iThresholds, m_iColumns);

            // Segmentation
            if( !Method(*spSlice, Segmented) )
            {
                MDS_CERR('<' << m_sFilename << "> Cannot process image segmentation" << std::endl);
            }

            // Write the result to the output channel
            if( !writeOutput(pOChannel, &Segmented) )
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


void CSliceSegHT::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceSegHT::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-thresholds iValue] [-columns iValue]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -thresholds  The number of thresholds used for segmentation." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -columns  Histogram resolution. In other words, the number" << std::endl);
    MDS_CERR("            of columns of the created histogram." << std::endl);
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
    CSliceSegHTPtr spModule(new CSliceSegHT(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

