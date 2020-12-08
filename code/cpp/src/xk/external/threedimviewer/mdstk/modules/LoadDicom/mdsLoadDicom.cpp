//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/18                          \n
 *
 * $Id: mdsLoadDicom.cpp 2098 2012-02-16 23:50:36Z spanel $
 *
 * File description:
 * - Reads DICOM data from an input channel.
 * - Converts it to the image slice.
 */

#include "mdsLoadDicom.h"

#include <MDSTk/ImageIO/mdsDicomSlice.h>

// STL
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global module constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module loads medical data in DICOM format";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "";


//==============================================================================
/*
 * Implementation of the class CLoadDicom.
 */
CLoadDicom::CLoadDicom(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CLoadDicom::~CLoadDicom()
{
}


bool CLoadDicom::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // O.K.
    return true;
}


bool CLoadDicom::main()
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

    // Smart pointer to DICOM slice
    mds::img::CDicomSlicePtr spSlice(new mds::img::CDicomSlice);

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read and process data from the input channel
        // Load DICOM data from input channel
        if( spSlice->loadDicom(pIChannel) )
        {
            // Write it to the output channel as slice
            if( !writeOutput(pOChannel, spSlice.get()) )
            {
                MDS_CERR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
            }
        }
        else
        {
            MDS_CERR('<' << m_sFilename << "> Failed to read input DICOM data" << std::endl);
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


void CLoadDicom::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CLoadDicom::writeExtendedUsage(std::ostream&)
{
    MDS_CERR("Input: DICOM image" << std::endl);
    MDS_CERR("Output: MDSTk image/slice" << std::endl);
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CLoadDicomPtr spModule(new CLoadDicom(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

