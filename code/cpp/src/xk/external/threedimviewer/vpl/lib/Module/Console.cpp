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
 * Date:    2006/04/07                       
 *
 * Description:
 * - Definition of a simple console application.
 */

#include <VPL/Module/Console.h>

#include <VPL/Base/Assert.h>
#include <VPL/Base/Version.h>
#include <VPL/Base/BuildDate.h>
#include <VPL/Base/Warning.h>
#include <VPL/System/Sleep.h>

// STL
#include <stdexcept>
#include <iostream>

// Windows version
#ifdef _WIN32
#    include <fcntl.h>
#    include <io.h>
#    include <stdio.h>
#endif // _WIN32


namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Implementation of the class vpl::mod::CConsole.
 */
CConsole::CConsole(const std::string& sDescription)
    : m_sDescription(sDescription)
    , m_sFilename("?")
    , m_sAllowedArguments("h:log:logname")
    , m_Thread(threadRoutine, NULL, false)
{
// Windows version
#ifdef _WIN32
    _setmode(_fileno(stdin), O_BINARY);
    _setmode(_fileno(stdout), O_BINARY);
#endif // _WIN32

    // Set user thread data
    m_Thread.setData(static_cast<void *>(this));

// Linux version
#ifdef _LINUX
    m_stdin = stdin;
    FILE *fstdin = fdopen(fileno(stdin), "rb");
    VPL_ASSERT(fstdin);
    stdin = fstdin;

    m_stdout = stdout;
    FILE *fstdout = fdopen(fileno(stdout), "wb");
    VPL_ASSERT(fstdout);
    stdout = fstdout;
#endif // _LINUX
}


CConsole::~CConsole()
{
// Linux version
#ifdef _LINUX
    fclose(stdin);
    stdin = m_stdin;

    fclose(stdout);
    stdout = m_stdout;
#endif // _LINUX
}


bool CConsole::init(int argc, char *argv[])
{
    // Application filename
    m_sFilename = argv[0];
    if( m_sFilename.rfind(SLASHC) != std::string::npos )
    {
        m_sFilename.erase(0, m_sFilename.rfind(SLASHC) + 1);
    }

#ifdef _WIN32
    if( m_sFilename.rfind(".exe") != std::string::npos )
    {
        m_sFilename.erase(m_sFilename.rfind(".exe"), std::string::npos);
    }
#endif // _WIN32

    // Parsing command line arguments
    if( !m_Arguments.parse(argc, argv) )
    {
        std::cerr << '<' << m_sFilename << "> Bad command line arguments: invalid format" << std::endl;
        printUsage();
        return false;
    }

    // Control allowed arguments
    if( !m_Arguments.check(m_sAllowedArguments) )
    {
        std::cerr << '<' << m_sFilename << "> Bad command line arguments: argument that is not allowed" << std::endl;
        printUsage();
        return false;
    }

    // Just show a full module usage
    if( m_Arguments.exists(console::ARGUMENT_HELP) )
    {
        printFullUsage();
        return false;
    }

    // Log filename
    std::string sLogFilename = m_sFilename;
    m_Arguments.value(console::ARGUMENT_LOGNAME, sLogFilename);
    sLogFilename += vpl::base::LOG_DEFAULT_EXT;

    // Creation of a global module log
    std::string ssLogType = console::DEFAULT_LOG;
    m_Arguments.value(console::ARGUMENT_LOG, ssLogType);
    if( ssLogType == console::LOG_FILE )
    {
        VPL_LOG_ADD_FILE_APPENDER(sLogFilename);
    }
    else if ( ssLogType == console::LOG_BOTH )
    {
        VPL_LOG_ADD_CERR_APPENDER;
        VPL_LOG_ADD_FILE_APPENDER(sLogFilename);
    }
    else if( ssLogType == console::LOG_STDERR )
    {
        VPL_LOG_ADD_CERR_APPENDER;
    }
    else if( ssLogType != console::LOG_NULL )
    {
        std::cerr << '<' << m_sFilename << "> Bad " << console::ARGUMENT_LOG << " argument: type -h for help" << std::endl;
        printUsage();
        return false;
    }

    // Initialize OpenMP
    int iNumOfThreads = ompDefaultSettings();
    if( iNumOfThreads < 0 )
    {
        VPL_LOG_INFO('<' << m_sFilename << "> OpenMP has been disabled!");
    }
    else
    {
        VPL_LOG_INFO('<' << m_sFilename << "> OpenMP is enabled: " << iNumOfThreads << " threads");
    }
    
    // OK, let's start...
    return true;
}


void CConsole::allowArguments(const std::string& sArgs)
{
    if( sArgs.length() > 0 )
    {
        m_sAllowedArguments += std::string(":") + sArgs;
    }
}


bool CConsole::run()
{
    // Log a startup time
    VPL_LOG_INFO("Console startup");

    // Console startup
    if( !startup() )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Console startup failed");
        return false;
    }

    // Start the separate thread which calls the main method
    m_Thread.resume();

    // Waiting for termination or the ^C sequence
    while( !m_ExitHandler.wait(100) && m_Thread.isActive() );

    // Has the exit sequence been pressed
    if( m_ExitHandler.isCanceled() )
    {
        VPL_LOG_INFO('<' << m_sFilename << "> Module canceled");
    }

    // Terminate the thread
    m_Thread.terminate();

    // Console shutdown
    shutdown();

    // Log a shutdown time
    VPL_LOG_INFO('<' << m_sFilename << "> Console shutdown");

    return true;
}


void CConsole::exit()
{
    VPL_LOG_INFO('<' << m_sFilename << "> Terminating..." << std::endl);
    m_ExitHandler.exit();
}


void CConsole::printUsage()
{
    std::cerr << LABEL << '-' << VERSION << ": " << m_sDescription << std::endl;
    std::cerr << "Usage: " << m_sFilename << " [-h] [-log sLog] [-logname sFilename]" << std::endl;
}


void CConsole::printFullUsage()
{
    printUsage();

    std::cerr << "Options:" << std::endl;
    std::cerr << "  -h Shows this help." << std::endl;
    std::cerr << std::endl;
    std::cerr << "  -log  Option selects a log type. Allowed values are:" << std::endl;
    std::cerr << "          " << console::LOG_NULL << " for no logging," << std::endl;
    std::cerr << "          " << console::LOG_STDERR << ',' << std::endl;
    std::cerr << "          " << console::LOG_FILE << " and" << std::endl;
    std::cerr << "          " << console::LOG_BOTH << '.' << std::endl;
    std::cerr << "        Default value is " << console::DEFAULT_LOG << '.' << std::endl;
    std::cerr << std::endl;
    std::cerr << "  -logname  Changes filename of the output log." << std::endl;

    std::cerr << std::endl;
    this->writeExtendedUsage(std::cerr);
}


//==============================================================================
/*
 * Console thread routine.
 */
VPL_THREAD_ROUTINE(CConsole::threadRoutine)
{
    // Console object
    CConsole *pConsole = static_cast<CConsole *>(pThread->getData());
    VPL_ASSERT(pConsole);

    try {
        // The thread has been started
        VPL_LOG_INFO('<' << pConsole->m_sFilename << "> The module thread has been started");

        // Main thread loop
        VPL_THREAD_MAIN_LOOP
        {
            try {
                // Exit has been pressed
                if( pConsole->m_ExitHandler.isCanceled() )
                {
                    break;
                }

                // Call a main function
                if( !pConsole->main() )
                {
                    break;
                }

                // Sleep for a short period of time
                vpl::sys::sleep(0);
            }

            VPL_CATCH_WARNING(pConsole->m_sFilename)
        }

        // Log the termination of the thread
        VPL_LOG_INFO('<' << pConsole->m_sFilename << "> The module thread has been terminated");

        // Terminate immediately
        pConsole->m_ExitHandler.exit();
    }

    VPL_CATCH_WARNING(pConsole->m_sFilename)
    VPL_CATCH_ERROR(pConsole->m_sFilename)

    catch( const vpl::base::CFullException& Exception )
    {
        VPL_LOG_INFO(Exception);
        VPL_LOG_ERROR('<' << pConsole->m_sFilename << "> Exception: see log for details, termintating ..." << std::endl);
        abort();
    }
    catch( const vpl::base::CException& Exception )
    {
        VPL_LOG_INFO('<' << pConsole->m_sFilename << "> Exception: " << Exception.what() << std::endl);
        VPL_LOG_ERROR('<' << pConsole->m_sFilename << "> Exception: see log for details, termintating ..." << std::endl);
        abort();
    }
    catch( const std::exception& Exception )
    {
        VPL_LOG_INFO('<' << pConsole->m_sFilename << "> Std exception: " << Exception.what() << std::endl);
        VPL_LOG_ERROR('<' << pConsole->m_sFilename << "> Std exception: see log for details, termintating ..." << std::endl);
        abort();
    }
    catch( ... )
    {
        VPL_LOG_ERROR('<' << pConsole->m_sFilename << "> Unknown exception: termintating ..." << std::endl);
        abort();
    }

    return 0;
}


} // namespace mod
} // namespace vpl

