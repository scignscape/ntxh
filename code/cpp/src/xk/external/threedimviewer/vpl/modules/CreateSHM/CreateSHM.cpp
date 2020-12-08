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
 * Copyright (c) 2003-2006 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/04/07                       
 *
 * File description:
 * - Console utility allocates a new shared memory block.
 * - Only for testing!
 */

#include "CreateSHM.h"

#include <VPL/System/Sleep.h>
#include <VPL/Base/Logging.h>

// STL
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description.
const std::string MODULE_DESCRIPTION    = "Allocates a new shared memory block.";

//! Additional command line arguments.
const std::string MODULE_ARGUMENTS      = "name:size";

//! Additional arguments.
const std::string MODULE_ARGUMENT_NAME  = "name";
const std::string MODULE_ARGUMENT_SIZE  = "size";


//==============================================================================
/*
 * Implementation of the class CCreateSHM.
 */
CCreateSHM::CCreateSHM(const std::string& sDescription)
    : vpl::mod::CConsole(sDescription)
    , m_pSemaphore(NULL)
    , m_pSharedMem(NULL)
{
    allowArguments(MODULE_ARGUMENTS);
}


CCreateSHM::~CCreateSHM()
{
}


bool CCreateSHM::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Command line arguments
    if( !m_Arguments.exists(MODULE_ARGUMENT_NAME) )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Parameter " << MODULE_ARGUMENT_NAME << " is not given: type -h for help" << std::endl);
        printUsage();
        return false;
    }
    m_ssName = "";
    m_Arguments.value(MODULE_ARGUMENT_NAME, m_ssName);
    if( m_ssName.length() == 0 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad " << MODULE_ARGUMENT_NAME << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'size'
    if( !m_Arguments.exists(MODULE_ARGUMENT_SIZE) )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Parameter " << MODULE_ARGUMENT_SIZE << " is not given: type -h for help" << std::endl);
        printUsage();
        return false;
    }
    m_iSize = 0;
    m_Arguments.value(MODULE_ARGUMENT_SIZE, m_iSize);
    if( m_iSize <= 0 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad " << MODULE_ARGUMENT_SIZE << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CCreateSHM::main()
{
    // Note
//    VPL_LOG_INFO("Module main function");

    // Create locked named semaphore
    if( !m_pSemaphore )
    {
        bool bAlreadyExists = false;
        try {
            m_pSemaphore = new vpl::sys::CNamedSemaphore(0, &m_ssName, &bAlreadyExists);
        }
        catch( ... )
        {
            VPL_LOG_ERROR("Error: Cannot create semaphore named " << m_ssName << "!" << std::endl);
            return false;
        }

        // Check if the semaphore already exists
        if( bAlreadyExists )
        {
            VPL_LOG_ERROR("Warning: Semaphore named " << m_ssName << " already exists!" << std::endl);
        }
    }

    // Create the shared memory
    if( m_pSemaphore && !m_pSharedMem )
    {
        bool bAlreadyExists = false;
        try {
            m_pSharedMem = new vpl::sys::CSharedMem(m_ssName, m_iSize * 1024, true, &bAlreadyExists);
        }
        catch( ... )
        {
            VPL_LOG_ERROR("Error: Cannot create shared memory named " << m_ssName << "!" << std::endl);
            return false;
        }

        // Check if the memory already exists
        if( bAlreadyExists )
        {
            VPL_LOG_ERROR("Warning: Shared memory named " << m_ssName << " already exists!" << std::endl);
        }

        // Unlock the sempahore
        m_pSemaphore->unlock();
    }

    // Sleep for a short time
    vpl::sys::sleep(500);

    // Continue running the module
    return true;
}


void CCreateSHM::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");

    // Destroy the shared memory
    if( m_pSharedMem )
    {
        // Lock the shared memory
        m_pSemaphore->lock();

        // Destroy it
        delete m_pSharedMem;
    }

    // Destroy the semaphore
    if( m_pSemaphore )
    {
        delete m_pSemaphore;
    }
}


void CCreateSHM::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-name sValue] [-size iValue]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -name  Name of the shared memory block." << std::endl;
    Stream << std::endl;
    Stream << "  -size  Size of the block in kilobytes (kB). A value greater than" << std::endl;
    Stream << "         zero must be given." << std::endl;
    Stream << std::endl;
    Stream << "Input: none" << std::endl;
    Stream << "Output: none" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a console using smart pointer
    CCreateSHMPtr spConsole(new CCreateSHM(MODULE_DESCRIPTION));

    // Initialize and execute the console
    if( spConsole->init(argc, argv) )
    {
        spConsole->run();
    }

    // Console application finished
    return 0;
}

