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
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/18                       
 *
 * File description:
 * - Reads DICOM data from an input channel.
 * - Converts it to the image slice.
 */

#include "LoadDicom.h"

#include <VPL/ImageIO/DicomSlice.h>
#include <VPL/Base/Logging.h>

// STL
#include <iostream>
#include <string>

//VPL
//for exception
#include <VPL/ImageIO/DicomSliceLoader.h>

#   if defined( VPL_USE_GDCM )
//GDCM loader
#include <VPL/ImageIO/DicomSliceLoaderGDCM.h>
#   else
//Original loader
#include <VPL/ImageIO/DicomSliceLoaderVPL.h>
#   endif

//==============================================================================
/*
 * Global module constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module loads medical data in DICOM format";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "file";

//==============================================================================
/*
 * Implementation of the class CLoadDicom.
 */
CLoadDicom::CLoadDicom(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CLoadDicom::~CLoadDicom()
{
}


bool CLoadDicom::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // O.K.
    return true;
}


bool CLoadDicom::main()
{
    // Note
    VPL_LOG_INFO("Module main function");

    // I/O channels
    vpl::mod::CChannel *pIChannel = getInput(0);
    vpl::mod::CChannel *pOChannel = getOutput(0);



    // no input file specified
    if (!m_Arguments.exists(MODULE_ARGUMENTS))
    {
        printFullUsage();
        VPL_LOG_ERROR('<' << m_sFilename << "> Cannot open input file." << std::endl);
        return false;
    }

    std::string fn;
    m_Arguments.value(MODULE_ARGUMENTS, fn);
        
    // Smart pointer to DICOM slice
    vpl::img::CDicomSlicePtr spSlice(new vpl::img::CDicomSlice);

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        try
        {           
            bool bOK = false;

            //Load DICOM data from input channel
#if defined( VPL_USE_GDCM )

            vpl::img::CDicomSliceLoaderGDCM m_Loader;
            bOK = m_Loader.loadDicom(fn, *spSlice, true);
                 
#else
            vpl::img::CDicomSliceLoaderVPL m_Loader;
            bOK = m_Loader.loadDicom(fn, *spSlice, true);
            
#endif
            if (bOK)
            {
                // Write it to the output channel as slice
                if (!writeOutput(pOChannel, spSlice.get()))
                {
                    VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
                }
            }
            else
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input DICOM data" << std::endl);
                return false;
            }
        }
        catch (vpl::img::CDicomSliceLoader::CDicomSliceLoaderGDCMExeption &e)
        {
            VPL_LOG_ERROR('<' << m_sFilename << "> " << e.what() << std::endl);
            return false;
        }
         
    }
    else
    {
        VPL_LOG_INFO("Wait timeout");
    }

    // Returning 'true' means to continue processing the input channel
    return false;
}


void CLoadDicom::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CLoadDicom::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Input: DICOM image" << std::endl;
    Stream << "Output: MDSTk image/slice" << std::endl;
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

