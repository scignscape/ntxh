//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/04/06                          \n
 *
 * $Id: mdsNamedPipe.h 2091 2012-02-14 11:26:36Z spanel $
 *
 * Description:
 * - IPC using named pipes.
 */

#ifndef MDS_NAMEDPIPE_H
#define MDS_NAMEDPIPE_H

#include <MDSTk/Base/mdsSetup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif

// Linux version
#ifdef _LINUX
#    include <unistd.h>
#    include <fcntl.h>
#    include <limits.h>
#    include <errno.h>
#    include <sys/types.h>
#    include <sys/stat.h>
#endif

#include <MDSTk/Base/mdsSharedPtr.h>

#include "mdsSystem.h"
#include "mdsSystemExport.h"

// STL
#include <string>


namespace mds
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
const std::string P_NAME_PREFIX     = "\\\\.\\pipe\\mds::CNamedPipe::";

//! Default buffer size.
const int P_BUFFER_SIZE             = 4096;

#endif // _WIN32


//==============================================================================
/*
 * Global constants.
 * - Linux version.
 */

#ifdef _LINUX

//! Default prefix of any pipe name.
const std::string P_NAME_PREFIX     = "/tmp/mds::CNamedPipe::";

//! Default buffer size.
const int P_BUFFER_SIZE             = (int)PIPE_BUF;

#endif // _LINUX


//==============================================================================
/*!
 * Named pipe.
 */
class MDS_SYSTEM_EXPORT CNamedPipe : public mds::base::CObject
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CNamedPipe);

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
    int read(char *pData, int iLength);

    //! Writes data to the named pipe.
    bool write(const char *pData, int iLength);

protected:
#ifdef _WIN32
    //! Windows named pipe handle.
    HANDLE m_hNamedPipe;

    //! Windows event used to wait for a connection.
    HANDLE m_hEvent;
#endif // _WIN32

#ifdef _LINUX
    //! File descriptor of a linux named pipe.
    int m_PipeFd;
#endif // _LINUX

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
} // namespace mds

#endif // MDS_NAMEDPIPE_H

