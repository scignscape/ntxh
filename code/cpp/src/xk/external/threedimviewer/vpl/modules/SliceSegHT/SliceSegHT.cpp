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
 * Copyright (c) 2003-2005 by Michal Spanel         
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz      
 *          Miroslav Svub, xsvubm00@stud.fit.vutbr.cz  \n
 * Date:    2004/10/24                              
 *
 * File description:
 * - Simple segmentation method based on histogram thresholding.
 */

#include <VPL/Image/Slice.h>

#include "SliceSegHT.h"
#include "HistogramThresholding.h"

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
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceSegHT::~CSliceSegHT()
{
}


bool CSliceSegHT::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line arguments
    m_iThresholds = DEFAULT_T;
    m_Arguments.value(MODULE_ARGUMENT_T, m_iThresholds);
    if( m_iThresholds < 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'tresholds' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_iColumns = DEFAULT_C;
    m_Arguments.value(MODULE_ARGUMENT_C, m_iColumns);
    if( m_iColumns < 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'columns' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CSliceSegHT::main()
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

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read slice from the input channel
        if( readInput(pIChannel, spSlice.get()) )
        {
            // Create a new slice
            // - copy of the input one
            vpl::img::CSlice Segmented(*spSlice);

            // Image segmentation method
            vpl::imseg::CHistogramThresholding Method(m_iThresholds, m_iColumns);

            // Segmentation
            if( !Method(*spSlice, Segmented) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Cannot process image segmentation" << std::endl);
            }

            // Write the result to the output channel
            if( !writeOutput(pOChannel, &Segmented) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the segmented slice" << std::endl);
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


void CSliceSegHT::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSliceSegHT::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-thresholds iValue] [-columns iValue]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -thresholds  The number of thresholds used for segmentation." << std::endl;
    Stream << std::endl;
    Stream << "  -columns  Histogram resolution. In other words, the number" << std::endl;
    Stream << "            of columns of the created histogram." << std::endl;
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
    CSliceSegHTPtr spModule(new CSliceSegHT(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

