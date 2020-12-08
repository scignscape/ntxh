//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/09/02                          \n
 *
 * $Id: mdsSliceBlending.cpp 2098 2012-02-16 23:50:36Z spanel $
 *
 * File description:
 * - Blending of two slices into one.
 */

#include "mdsSliceBlending.h"

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

//! Module description.
const std::string MODULE_DESCRIPTION    = "Module for blending of two slices.";

//! Additional command line arguments.
const std::string MODULE_ARGUMENTS      = "alpha";

//! Additional arguments.
const std::string MODULE_ARGUMENT_ALPHA = "alpha";

//! Default values.
const double DEFAULT_ALPHA              = 0.5;

//! Minimal and maximal values.
const double ALPHA_MIN                  = 0.0;
const double ALPHA_MAX                  = 1.0;


//==============================================================================
/*
 * Implementation of the class CSliceBlending.
 */
CSliceBlending::CSliceBlending(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceBlending::~CSliceBlending()
{
}


bool CSliceBlending::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 2 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Parameters
    m_dAlpha = DEFAULT_ALPHA;
    m_Arguments.value(MODULE_ARGUMENT_ALPHA, m_dAlpha);
    if( m_dAlpha > ALPHA_MAX || m_dAlpha < ALPHA_MIN )
    {
        MDS_CERR('<' << m_sFilename << "> Bad " << MODULE_ARGUMENT_ALPHA << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CSliceBlending::main()
{
    // Note
    MDS_LOG_NOTE("Module main function");

    // I/O channels
    mds::mod::CChannel *pIChannel = getInput(0);
    mds::mod::CChannel *pOChannel = getOutput(0);

    // Create a new Slice
    mds::img::CSlice Slice1;

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

    // Read Slice from the input channel
    if( !readInput(pIChannel, &Slice1) )
    {
        MDS_CERR('<' << m_sFilename << "> Failed to read input slice" << std::endl);
        return false;
    }

    // I/O channels
    pIChannel = getInput(1);

    // Create a new Slice
    mds::img::CSlice Slice2;

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

    // Read second Slice from the input channel
    if( !readInput(pIChannel, &Slice2) )
    {
        MDS_CERR('<' << m_sFilename << "> Failed to read input slice" << std::endl);
        return false;
    }

    // Estimate overlapping part of both Slices
    mds::tSize XCount = mds::math::getMin(Slice1.getXSize(), Slice2.getXSize());
    mds::tSize YCount = mds::math::getMin(Slice1.getYSize(), Slice2.getYSize());

    // Blending
    double dInvAlpha = 1.0 - m_dAlpha;
    for( mds::tSize j = 0; j < YCount; ++j )
    {
        for( mds::tSize i = 0; i < XCount; ++i )
        {
            double dResult = m_dAlpha * Slice1(i,j) + dInvAlpha * Slice2(i,j);
            Slice1(i,j) = mds::img::tDensityPixel(dResult);
        }
    }

    // Write the result to the output channel
    if( !writeOutput(pOChannel, &Slice1) )
    {
        MDS_CERR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
        return false;
    }

    // Terminate the processing
    return false;
}


void CSliceBlending::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceBlending::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-alpha dValue]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -alpha  Blending ratio. Values in the range <" << ALPHA_MIN << ", " << ALPHA_MAX << "> are allowed." << std::endl);
    MDS_CERR("          Default value is " << DEFAULT_ALPHA << '.' << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("Input: two MDSTk slices in separate channels" << std::endl);
    MDS_CERR("Output: MDSTk slice" << std::endl);
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CSliceBlendingPtr spModule(new CSliceBlending(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

