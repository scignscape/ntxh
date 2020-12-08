//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/03/01                          \n
 *
 * $Id: mdsSliceSeg.cpp 2100 2012-02-17 07:36:55Z spanel $
 *
 * File description:
 * - Sample slice segmentation module.
 */

#include "mdsSliceSeg.h"
#include "mdsSegMethod.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Sample module providing image segmentation.";

//! Additional command line arguments
//! - Colon separated list!
//! - Sample code!
const std::string MODULE_ARGUMENTS      = "a:b";

//! Additional arguments names
//! - Sample code!
const std::string MODULE_ARGUMENT_A     = "a";
const std::string MODULE_ARGUMENT_B     = "b";

//! Default arguments values
//! - Sample code!
const unsigned int DEFAULT_A            = 1;


//==============================================================================
/*
 * Implementation of the class CSliceSeg.
 */
CSliceSeg::CSliceSeg(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    // Allow additional command line arguments
    allowArguments(MODULE_ARGUMENTS);
}


CSliceSeg::~CSliceSeg()
{
}


bool CSliceSeg::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line argument - a
    //! - Sample code!
    m_iA = DEFAULT_A;
    m_Arguments.value(MODULE_ARGUMENT_A, m_iA);
    if( m_iA > 100 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'a' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Command line argument - b
    //! - Sample code!
    m_bB = m_Arguments.exists(MODULE_ARGUMENT_B);

    // O.K.
    return true;
}


bool CSliceSeg::main()
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
            // - Copy of the input one
            mds::img::CSlicePtr spSegmented(new mds::img::CSlice(*spSlice));

            // Image segmentation method
            mds::imseg::CSegMethod Method;

            // Method initialization
            // - sample code
            if( !Method.init() )
            {
                MDS_CERR('<' << m_sFilename << "> Cannot initialize image segmentation method" << std::endl);
            }
            else if( !Method(*spSlice, *spSegmented) )
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


void CSliceSeg::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceSeg::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-a iValue] [-b]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -a  ..." << std::endl);
    MDS_CERR("  -b  ..." << std::endl);
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
    CSliceSegPtr spModule(new CSliceSeg(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

