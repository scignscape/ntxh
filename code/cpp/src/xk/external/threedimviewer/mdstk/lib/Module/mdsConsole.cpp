//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/04/07                          \n
 *
 * $Id: mdsConsole.cpp 2106 2012-02-18 21:55:47Z spanel $
 *
 * Description:
 * - Definition of a simple console application.
 */

#include <MDSTk/Module/mdsConsole.h>

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsVersion.h>
#include <MDSTk/Base/mdsBuildDate.h>
#include <MDSTk/System/mdsSleep.h>

// STL
#include <stdexcept>
#include <iostream>

// Windows version
#ifdef _WIN32
#    include <fcntl.h>
#    include <io.h>
#    include <stdio.h>
#endif // _WIN32


namespace mds
{
namespace mod
{

//==============================================================================
/*
 * Implementation of the class mds::mod::CConsole.
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
    m_Thread.setData((void *)this);

// Linux version
#ifdef _LINUX
    m_stdin = stdin;
    FILE *fstdin = fdopen(fileno(stdin), "rb");
    MDS_ASSERT(fstdin);
    stdin = fstdin;

    m_stdout = stdout;
    FILE *fstdout = fdopen(fileno(stdout), "wb");
    MDS_ASSERT(fstdout);
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
        MDS_CERR('<' << m_sFilename << "> Bad command line arguments: invalid format" << std::endl);
        printUsage();
        return false;
    }

    // Control allowed arguments
    if( !m_Arguments.check(m_sAllowedArguments) )
    {
        MDS_CERR('<' << m_sFilename << "> Bad command line arguments: argument that is not allowed" << std::endl);
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
    sLogFilename += mds::base::LOG_DEFAULT_EXT;

    // Creation of a global module log
    std::string ssLogType = console::DEFAULT_LOG;
    m_Arguments.value(console::ARGUMENT_LOG, ssLogType);
    if( ssLogType == console::LOG_FILE )
    {
        MDS_LOG_INIT_FILE(sLogFilename.c_str());
    }
    else if ( ssLogType == console::LOG_BOTH )
    {
        MDS_LOG_INIT_STDERR;
        MDS_LOG_INIT_FILE(sLogFilename.c_str());
    }
    else if( ssLogType == console::LOG_STDERR )
    {
        MDS_LOG_INIT_STDERR;
    }
    else if( ssLogType != console::LOG_NULL )
    {
        MDS_CERR('<' << m_sFilename << "> Bad " << console::ARGUMENT_LOG << " argument: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Initialize OpenMP
    int iNumOfThreads = ompDefaultSettings();
    if( iNumOfThreads < 0 )
    {
        MDS_LOG_NOTE("OpenMP has been disabled!");
    }
    else
    {
        MDS_LOG_NOTE("OpenMP is enabled: " << iNumOfThreads << " threads.");
    }
    
    // O.K.
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
    MDS_LOG_TIME("Console startup");

    // Console startup
    if( !startup() )
    {
        MDS_CERR('<' << m_sFilename << "> Console startup failed" << std::endl);
//      printUsage();
        return false;
    }

    // Start the separate thread which calls the main method
    m_Thread.resume();

    // Waiting for termination or the ^C sequence
    while( !m_ExitHandler.wait(100) && m_Thread.isActive() );

    // Has the exit sequence been pressed
/*    if( m_ExitHandler.isCanceled() && m_Thread.isActive() )
    {
        MDS_LOG_NOTE("Module cancelled");
    }*/

    // Terminate the thread
    m_Thread.terminate();

    // Console shutdown
    shutdown();

    // Log a shutdown time
    MDS_LOG_TIME("Console shutdown");

    return true;
}


void CConsole::exit()
{
    MDS_CERR('<' << m_sFilename << "> Terminating ..." << std::endl);
    m_ExitHandler.exit();
}


void CConsole::printUsage()
{
    MDS_CERR(LABEL << '-' << VERSION << ": " << m_sDescription << std::endl);
    MDS_CERR("Usage: " << m_sFilename << " [-h] [-log sLog] [-logname sFilename]" << std::endl);
}


void CConsole::printFullUsage()
{
    printUsage();

    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -h Shows this help." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -log  Option selects a log type. Allowed values are:" << std::endl);
    MDS_CERR("          " << console::LOG_NULL << " for no logging," << std::endl);
    MDS_CERR("          " << console::LOG_STDERR << ',' << std::endl);
    MDS_CERR("          " << console::LOG_FILE << " and" << std::endl);
    MDS_CERR("          " << console::LOG_BOTH << '.' << std::endl);
    MDS_CERR("        Default value is " << console::DEFAULT_LOG << '.' << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -logname  Changes filename of the output log." << std::endl);

    MDS_CERR(std::endl);
    this->writeExtendedUsage(std::cerr);
}


//==============================================================================
/*
 * Console thread routine.
 */
MDS_THREAD_ROUTINE(CConsole::threadRoutine)
{
    // Console object
    CConsole *pConsole = static_cast<CConsole *>(pThread->getData());
    MDS_ASSERT(pConsole);

    try {
        // The thread has been started
        MDS_LOG_NOTE("The module thread has been started");

        // Main thread loop
        MDS_THREAD_MAIN_LOOP
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
                mds::sys::sleep(0);
            }

            MDS_CATCH_WARNING(pConsole->m_sFilename)
        }

        // Log the termination of the thread
        MDS_LOG_NOTE("The module thread has been terminated");

        // Terminate immediately
        pConsole->m_ExitHandler.exit();
    }

    MDS_CATCH_WARNING(pConsole->m_sFilename)
    MDS_CATCH_ERROR(pConsole->m_sFilename)

    catch( const mds::base::CFullException& Exception )
    {
        MDS_LOG(Exception);
        MDS_CERR('<' << pConsole->m_sFilename << "> Exception: see log for details, termintating ..." << std::endl);
        abort();
    }
    catch( const mds::base::CException& Exception )
    {
        MDS_LOG('<' << pConsole->m_sFilename << "> Exception: " << Exception.what() << std::endl);
        MDS_CERR('<' << pConsole->m_sFilename << "> Exception: see log for details, termintating ..." << std::endl);
        abort();
    }
    catch( const std::exception& Exception )
    {
        MDS_LOG('<' << pConsole->m_sFilename << "> Std exception: " << Exception.what() << std::endl);
        MDS_CERR('<' << pConsole->m_sFilename << "> Std exception: see log for details, termintating ..." << std::endl);
        abort();
    }
    catch( ... )
    {
        MDS_CERR('<' << pConsole->m_sFilename << "> Unknown exception: termintating ..." << std::endl);
        abort();
    }

    return 0;
}


} // namespace mod
} // namespace mds

