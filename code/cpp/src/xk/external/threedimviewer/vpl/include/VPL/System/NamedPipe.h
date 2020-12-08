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
 * Date:    2004/04/06                       
 *
 * Description:
 * - IPC using named pipes.
 */

#ifndef VPL_NAMEDPIPE_H
#define VPL_NAMEDPIPE_H

#include <VPL/Base/Setup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif

// Linux and Mac version
#if defined(_LINUX) || defined(_MACOSX)
#    include <unistd.h>
#    include <fcntl.h>
#    include <limits.h>
#    include <errno.h>
#    include <sys/types.h>
#    include <sys/stat.h>
#endif

#include <VPL/Base/SharedPtr.h>
#include <VPL/Base/Types.h>

#include "System.h"
#include "SystemExport.h"

// STL
#include <string>


namespace vpl
{
namespace sys
{

//==============================================================================
/*
 * Global constants.
 */

//! Type of the named pipe.
enum EPipeType
{
    //! Input pipe.
    P_IN            = 1 << 0,

    //! Output pipe.
    P_OUT           = 1 << 1
};

//! Named pipe state.
enum EPipeState
{
    //! Disconnected pipe.
    P_DISCONNECTED  = 1 << 0,

    //! Successfully connected pipe.
    P_CONNECTED     = 1 << 1,

    //! Broken pipe.
    P_BROKEN        = (1 << 2) | P_DISCONNECTED,

    //! End of pipe reached.
    P_END           = (1 << 3) | P_DISCONNECTED
};

//! Wait function resolution.
const unsigned P_RESOLUTION     = 100;


//==============================================================================
/*
 * Global constants.
 * - Windows version.
 */

#ifdef _WIN32

//! Default prefix of any pipe name.
const std::string P_NAME_PREFIX     = "\\\\.\\pipe\\vpl::CNamedPipe::";

//! Default buffer size.
const int P_BUFFER_SIZE             = 4096;

#endif


//==============================================================================
/*
 * Global constants.
 * - Linux and Mac version.
 */

#if defined(_LINUX) || defined(_MACOSX)

//! Default prefix of any pipe name.
const std::string P_NAME_PREFIX     = "/tmp/::CNamedPipe::";

//! Default buffer size.
const int P_BUFFER_SIZE             = (int)PIPE_BUF;

#endif


//==============================================================================
/*!
 * Named pipe.
 */
class VPL_SYSTEM_EXPORT CNamedPipe : public vpl::base::CObject
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CNamedPipe);

public:
    //! Constructor.
    CNamedPipe(const std::string& sName, int Type);

    //! Destuctor.
    virtual ~CNamedPipe();

    //! Returns type of the named pipe.
    int type() const { return m_Type; }

    //! Returns actual state of the pipe.
    int state() const { return m_State; }


    //! Connects to a specified named pipe.
    //! - Returns false on failure or if a given timeout elapses.
    bool connect(unsigned uTimeout);

    //! Listens to a specified named pipe.
    //! - Returns false on failure or if a given timeout elapses.
    bool listen(unsigned uTimeout);

    //! Returns true if the pipe is successfully connected.
    bool isConnected();

    //! Disconnects the named pipe.
    void disconnect();


    //! Waits for data.
    //! - Until the data received event is signalled.
    //! - Returns false if a timeout elapses or the channel is not input.
    bool wait(unsigned uTimeout);

    //! Reads 'iLength' bytes from the named pipe.
    //! - In case of error the number of successfully read bytes is returned.
    tSize read(char *pData, tSize iLength);

    //! Writes data to the named pipe.
    bool write(const char *pData, tSize iLength);

protected:
#ifdef _WIN32
    //! Windows named pipe handle.
    HANDLE m_hNamedPipe;

    //! Windows event used to wait for a connection.
    HANDLE m_hEvent;
#endif

#if defined(_LINUX) || defined(_MACOSX)
    //! File descriptor of a linux named pipe.
    int m_PipeFd;
#endif

    //! Name of the pipe.
    std::string m_sName;

    //! Type of the named pipe.
    int m_Type;

    //! State of the pipe.
    int m_State;

private:
    //! Private copy constructor.
    CNamedPipe(const CNamedPipe&);

    //! Private assignment operator.
    void operator=(const CNamedPipe&);
};


//==============================================================================
/*!
 * Smart pointer to a named pipe.
 */
typedef CNamedPipe::tSmartPtr   CNamedPipePtr;


} // namespace sys
} // namespace vpl

#endif // VPL_NAMEDPIPE_H

