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

#ifndef VPL_CONSOLE_H
#define VPL_CONSOLE_H

#include <VPL/Base/Logging.h>
#include <VPL/Base/SharedPtr.h>
#include <VPL/System/Thread.h>
#include <VPL/System/ExitHandler.h>

#include "ModuleExport.h"
#include "Argv.h"

// STL
#include <string>
#include <cstdio>


namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Global definitions and constants.
 */

//! Namespace containing constants used by the CConsole class.
namespace console
{

//! Command line arguments.
const std::string ARGUMENT_HELP     = "h";
const std::string ARGUMENT_LOG      = "log";
const std::string ARGUMENT_LOGNAME  = "logname";

//! Allowed log argument values.
const std::string LOG_NULL          = "null";
const std::string LOG_STDERR        = "stderr";
const std::string LOG_FILE          = "file";
const std::string LOG_BOTH          = "both";

//! Default argument values.
const std::string DEFAULT_LOG       = LOG_FILE;

} // namespace console


//==============================================================================
/*!
 * Class encapsulating a simple console application.
 * - Supports log files and logging.
 * - Provides command line argument parsing.
 */
class VPL_MODULE_EXPORT CConsole : public vpl::base::CObject
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CConsole);

public:
    //! Default constructor.
    CConsole(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CConsole();

    //! Returns the application description.
    const std::string& getDescription() const { return m_sDescription; }

    //! Returns real name of the executed binary application.
    const std::string& getFilename() const { return m_sFilename; }


    //! Initializes console application and parses a given command line.
    //! - Returns false on failure.
    virtual bool init(int argc, char *argv[]);

    //! Executes processing thread and console I/O.
    //! - Returns false if the module cannot start.
    bool run();

    //! Exits the application.
    void exit();

    //! Returns true whenever the processing thread is running.
    bool isActive() { return m_Thread.isActive(); }

    //! Returns pointer to the parsed command line arguments.
    CArgv *getArguments() { return &m_Arguments; }

    //! Additinal command line arguments should be specified.
    //! - Individual arguments are separated by colon.
    void allowArguments(const std::string& sArgs);

    //! Writes simple usage to the cerr stream.
    virtual void printUsage();

    //! Writes full help to the cerr stream.
    virtual void printFullUsage();


    //! Virtual method called on console startup.
    //! - Expected to be overriden in concrete module!
    //! - Returns false on failure.
    virtual bool startup() = 0;

    //! Virtual method repeatedly called by the processing thread.
    //! - Expected to be overriden in concrete module!
    //! - When you need to stop the execution just return false.
    virtual bool main() = 0;

    //! Called on console shutdown.
    //! - Expected to be overriden in concrete module!
    virtual void shutdown() = 0;

    //! Called on writing a full usage statement.
    //! - Expected to be overriden in concrete module!
    virtual void writeExtendedUsage(std::ostream& Stream) = 0;

protected:
    //! Application description.
    std::string m_sDescription;

    //! Application filename.
    std::string m_sFilename;

    //! Allowed command line arguments.
    std::string m_sAllowedArguments;

    //! Parsed command line arguments.
    CArgv m_Arguments;

    //! Processing thread.
    vpl::sys::CThread m_Thread;

    //! The main thread routine.
    static VPL_THREAD_ROUTINE(threadRoutine);

    //! Exit handler.
    vpl::sys::CExitHandler m_ExitHandler;

// Linux version
#ifdef _LINUX
    //! Original stdin and stdout.
    FILE *m_stdin, *m_stdout;
#endif // _LINUX
};


//==============================================================================
/*!
 * Smart pointer to console.
 */
typedef CConsole::tSmartPtr     CConsolePtr;


} // namespace mod
} // namespace vpl

#endif // VPL_CONSOLE_H
