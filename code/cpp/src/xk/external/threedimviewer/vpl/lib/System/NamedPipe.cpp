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
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.c
 * Date:    2004/04/06                          \n
 *
 * Description:
 * - IPC using named pipes.
 */

#include <VPL/System/NamedPipe.h>

#include <VPL/Base/Assert.h>
#include <VPL/Base/Error.h>
#include <VPL/Base/Warning.h>
#include <VPL/Base/Logging.h>


namespace vpl
{
namespace sys
{

//==============================================================================
/*
 * Implementation of the class vpl::sys::CNamedPipe.
 * - Windows version.
 */

#ifdef _WIN32

CNamedPipe::CNamedPipe(const std::string& sName, int Type)
    : m_hNamedPipe(0)
    , m_Type(Type)
    , m_State(P_DISCONNECTED)
{
    // Initialize member variables of a newly created pipe
    m_hEvent = CreateEvent(NULL, TRUE, TRUE, NULL);
    if( !m_hEvent )
    {
        VPL_THROW_ERROR("Constructor CNamedPipe::CNamedPipe() failed");
    }

    // Create a pipe name
    m_sName = P_NAME_PREFIX + sName;
}


CNamedPipe::~CNamedPipe()
{
    // Disconnect the named pipe
    CNamedPipe::disconnect();

    // Close the pipe handle
    if( m_hNamedPipe )
    {
        if( !CloseHandle(m_hNamedPipe) )
        {
            VPL_LOG_WARN("Destructor CNamedPipe::~CNamedPipe() failed");
        }
    }

    // Close the event handle
    if( m_hEvent )
    {
        CloseHandle(m_hEvent);
    }
}


bool CNamedPipe::connect(unsigned uTimeout)
{
    // Is the pipe already connected?
    if( m_State & P_CONNECTED )
    {
        return true;
    }

    for( unsigned uTime = 0; uTime <= uTimeout; uTime += P_RESOLUTION )
    {
        // Connect to the named pipe
        m_hNamedPipe = CreateFile(m_sName.c_str(),
                                  GENERIC_READ | GENERIC_WRITE,
                                  0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL
                                  );

        // Break if the pipe handle is valid
        if( m_hNamedPipe != INVALID_HANDLE_VALUE )
        {
            break;
        }

        // Is the pipe busy?
        if( GetLastError() == ERROR_PIPE_BUSY )
        {
            // Wait for a specified named pipe
            if( !WaitNamedPipe(m_sName.c_str(), uTimeout - uTime + P_RESOLUTION) )
            {
                break;
            }
        }
        else
        {
            // Sleep for a short period of time...
            Sleep(P_RESOLUTION);
        }
    }

    // Error...
    if( m_hNamedPipe == INVALID_HANDLE_VALUE )
    {
        m_hNamedPipe = 0;
        return false;
    }

    // The pipe connected; change the read mode.
    DWORD dwMode = PIPE_READMODE_BYTE | PIPE_WAIT;
    if( !SetNamedPipeHandleState(m_hNamedPipe, &dwMode, NULL, NULL) )
    {
        return false;
    }

    // Connected
    m_State = P_CONNECTED;

    // O.K.
    return true;
}


bool CNamedPipe::listen(unsigned uTimeout)
{
    // Is the pipe already connected?
    if( m_State & P_CONNECTED )
    {
        return true;
    }

    // Create a new windows named pipe in overlapped mode (server-end).
    if( !m_hNamedPipe )
    {
        m_hNamedPipe = CreateNamedPipe(
                           m_sName.c_str(),
                           PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED,
                           PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
                           1,
                           (DWORD)P_BUFFER_SIZE,
                           (DWORD)P_BUFFER_SIZE,
                           1000, NULL
                           );
        if( m_hNamedPipe == INVALID_HANDLE_VALUE )
        {
            m_hNamedPipe = 0;
            return false;
        }
    }

    // Connect a pipe client
    OVERLAPPED so;
    so.Offset = so.OffsetHigh = 0;
    so.hEvent = m_hEvent;
    BOOL bResult = ConnectNamedPipe(m_hNamedPipe, &so);
    if( !bResult && GetLastError() == ERROR_PIPE_CONNECTED )
    {
//        SetEvent(m_hEvent);
        m_State = P_CONNECTED;
        return true;
    }

    // Wait for client
    if( WaitForSingleObject(m_hEvent, uTimeout) != WAIT_OBJECT_0 )
    {
        return false;
    }

    // Test the result of ConnectNamedPipe() function
    DWORD dwBytesRead;
    bResult = GetOverlappedResult(m_hNamedPipe, &so, &dwBytesRead, FALSE);
    if( !bResult )
    {
        return false;
    }

    // Connected
    m_State = P_CONNECTED;

    // O.K.
    return true;
}


void CNamedPipe::disconnect()
{
    // Is pipe connected?
    if( (m_State & P_CONNECTED) == 0 )
    {
        return;
    }

    if( m_Type & P_OUT )
    {
        FlushFileBuffers(m_hNamedPipe);
    }

    // Is this a client or server?
    DWORD dwFlags = 0;
    if( !GetNamedPipeInfo(m_hNamedPipe, &dwFlags, NULL, NULL, NULL) )
    {
        VPL_LOG_WARN("Method CNamedPipe::disconnect() failed");
    }
    if( (dwFlags & PIPE_SERVER_END) == PIPE_SERVER_END )
    {
        // Disconnect from the client, and leave the pipe handle valid
        if( !DisconnectNamedPipe(m_hNamedPipe) )
        {
            VPL_LOG_WARN("Method CNamedPipe::disconnect() failed");
        }
    }
    else
    {
        // Close the client handle
        if( !CloseHandle(m_hNamedPipe) )
        {
            VPL_LOG_WARN("Method CNamedPipe::disconnect() failed");
        }
        m_hNamedPipe = 0;
    }

    // Named pipe disconnected
    m_State = P_DISCONNECTED;
}


bool CNamedPipe::isConnected()
{
    return ((m_State & P_CONNECTED) != 0);
}


bool CNamedPipe::wait(unsigned uTimeout)
{
    // Test the pipe state and the allowed pipe type
    if( (m_State & P_CONNECTED) == 0 || (m_Type & P_IN) == 0 )
    {
        return false;
    }

    // Wait for data
    DWORD dwBytesAvail = 0;
    BOOL bResult = false;
    for( unsigned uTime = 0; uTime <= uTimeout; uTime += P_RESOLUTION )
    {
        bResult = PeekNamedPipe(m_hNamedPipe, NULL, 0, NULL, &dwBytesAvail, NULL);
        if( bResult && dwBytesAvail > 0 )
        {
            break;
        }
        Sleep(P_RESOLUTION);
    }
    if( !bResult )
    {
        switch( GetLastError() )
        {
            case ERROR_HANDLE_EOF:
                // End of pipe readed
                CNamedPipe::disconnect();
                m_State = P_END;
                break;

            default:
                // Broken pipe
                CNamedPipe::disconnect();
                m_State = P_BROKEN;
                break;
        }
    }

    // Return result
    return (bResult && dwBytesAvail > 0);
}


tSize CNamedPipe::read(char *pData, tSize iLength)
{
    VPL_CHECK(pData, return 0);

    // Test the pipe state and the allowed pipe type
    if( (m_State & P_CONNECTED) == 0 || (m_Type & P_IN) == 0 )
    {
        return 0;
    }

    // Create overlapped structure
    OVERLAPPED so;
    so.Offset = so.OffsetHigh = 0;
    so.hEvent = m_hEvent;

    // Read the data
    DWORD dwBytesRead = 0, dwLength = (DWORD)iLength;
    BOOL bResult = ReadFile(m_hNamedPipe, pData, dwLength, &dwBytesRead, &so);
    if( !bResult )
    {
        switch( GetLastError() )
        {
            case ERROR_HANDLE_EOF:
                // End of pipe readed
                CNamedPipe::disconnect();
                m_State = P_END;
                break;

            case ERROR_IO_PENDING:
                // Wait for I/O
                if( WaitForSingleObject(m_hEvent, INFINITE) != WAIT_OBJECT_0 )
                {
                    return 0;
                }

                // Get the result
                bResult = GetOverlappedResult(m_hNamedPipe, &so, &dwBytesRead, FALSE);
                if( !bResult )
                {
                    switch( GetLastError() )
                    {
                    case ERROR_HANDLE_EOF:
                        // End of pipe readed
                        CNamedPipe::disconnect();
                        m_State = P_END;
                        break;
                    default:
                        // Broken pipe
                        CNamedPipe::disconnect();
                        m_State = P_BROKEN;
                        break;
                    }
                }
                break;

            default:
                // Broken pipe
                CNamedPipe::disconnect();
                m_State = P_BROKEN;
                break;
        }
    }

    // There are no data in the pipe
    return (tSize)dwBytesRead;
}


bool CNamedPipe::write(const char *pData, tSize iLength)
{
    VPL_CHECK(pData, return false);

    // Test the pipe state and the allowed pipe type
    if( (m_State & P_CONNECTED) == 0 || (m_Type & P_OUT) == 0 )
    {
        return false;
    }

    // Create overlapped structure
    OVERLAPPED so;
    so.Offset = so.OffsetHigh = 0;
    so.hEvent = m_hEvent;

    // Write the data
    DWORD dwBytesWritten = 0, dwLength = (DWORD)iLength;
    BOOL bResult = WriteFile(m_hNamedPipe, pData, dwLength, &dwBytesWritten, &so);
    if( !bResult )
    {
        switch( GetLastError() )
        {
            case ERROR_IO_PENDING:
                // Wait for I/O
                if( WaitForSingleObject(m_hEvent, INFINITE) != WAIT_OBJECT_0 )
                {
                    return false;
                }

                // Get the result
                bResult = GetOverlappedResult(m_hNamedPipe, &so, &dwBytesWritten, FALSE);
                if( !bResult )
                {
                    // Broken pipe
                    CNamedPipe::disconnect();
                    m_State = P_BROKEN;
                }
                break;

            default:
                // Broken pipe
                CNamedPipe::disconnect();
                m_State = P_BROKEN;
                break;
        }
    }

    // Return the result
    return (dwBytesWritten == dwLength);
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class vpl::sys::CNamedPipe.
s * - Linux and Mac version.
 */

#if defined(_LINUX) || defined(_MACOSX)

CNamedPipe::CNamedPipe(const std::string& sName, int Type)
    : m_Type(Type)
    , m_State(P_DISCONNECTED)
{
    // No named pipe is created
    m_PipeFd = -1;

    // Create a pipe name
    m_sName = P_NAME_PREFIX + sName;

    // Create the named pipe
    if( access(m_sName.c_str(), F_OK) == -1 )
    {
        if( mkfifo(m_sName.c_str(), 0700) != 0 )
        {
            VPL_LOG_WARN("Constructor CNamedPipe::CNamedPipe() failed");
        }
    }
}


CNamedPipe::~CNamedPipe()
{
    // Disconnect the named pipe
    CNamedPipe::disconnect();

    // Unlink the named pipe
    if( access(m_sName.c_str(), F_OK) != -1 )
    {
        unlink(m_sName.c_str());
    }
}


bool CNamedPipe::connect(unsigned VPL_UNUSED(uTimeout))
{
    // Disconnect the named pipe
    CNamedPipe::disconnect();

    // Connect to the existing named pipe
    if ( m_Type & P_OUT )
    {
        // Open the name pipe
        m_PipeFd = open(m_sName.c_str(), O_WRONLY);
        if( m_PipeFd == -1 )
        {
            return false;
        }
    }
    else if ( m_Type & P_IN )
    {
        // Open the name pipe
        m_PipeFd = open(m_sName.c_str(), O_RDONLY);
        if( m_PipeFd == -1 )
        {
            return false;
        }
    }
    else
    {
        // Unknown pipe type
        return false;
    }

    // Connected
    m_State = P_CONNECTED;

    // O.K.
    return true;
}


bool CNamedPipe::listen(unsigned uTimeout)
{
    return connect(uTimeout);
}


void CNamedPipe::disconnect()
{
    // Is pipe connected?
    if( (m_State & P_CONNECTED) == 0 )
    {
        return;
    }

    // Close the handle
    if( m_PipeFd != -1 )
    {
        close(m_PipeFd);
        m_PipeFd = -1;
    }

    // Named pipe disconnected
    m_State = P_DISCONNECTED;
}


bool CNamedPipe::isConnected()
{
    return ((m_State & P_CONNECTED) != 0);
}


bool CNamedPipe::wait(unsigned VPL_UNUSED(uTimeout))
{
    // Test the pipe state and the allowed pipe type
    if( (m_State & P_CONNECTED) == 0 || (m_Type & P_IN) == 0 )
    {
        return false;
    }

    // Cannot wait for data, so return true
    return true;
}


//! Function that reads n bytes using a given descriptor
int readn(const int fd, char *ptr, const int n, bool *eof)
{
    int nleft = n;
    while( nleft > 0 )
    {
        int nread = read(fd, ptr, nleft);
        if( nread < 0 )
        {
            if( errno == EINTR )
            {
                nread = 0;
            }
            else
            {
                return -1;
            }
        }
        else if( nread == 0 )
        {
            *eof = true;
            break;
        }
        nleft -= nread;
        ptr += nread;
    }
    return (n - nleft);
}


//! Function that writes n bytes using a given descriptor
int writen(const int fd, char *ptr, const int n)
{
    int nleft = n;
    while( nleft > 0 )
    {
        int nwritten = write(fd, ptr, nleft);
        if( nwritten < 0 )
        {
            if( errno == EINTR )
            {
                nwritten = 0;
            }
            else
            {
                return -1;
            }
        }
        else if( nwritten == 0 )
        {
            return -1;
        }
        nleft -= nwritten;
        ptr += nwritten;
    }
    return (n - nleft);
}


tSize CNamedPipe::read(char *pData, tSize iLength)
{
    VPL_ASSERT(pData);

    // Test the pipe state and the allowed pipe type
    if( (m_State & P_CONNECTED) == 0 || (m_Type & P_IN) == 0 )
    {
        return 0;
    }

    // Read data from the pipe
    bool bEof = false;
    tSize iResult = readn(m_PipeFd, pData, (int)iLength, &bEof);

    // Pipe error
    if( iResult < 0 )
    {
        // Broken pipe
        CNamedPipe::disconnect();
        m_State = P_BROKEN;
        return 0;
    }

    // End of pipe readed
    else if( bEof )
    {
        // End of pipe readed
        CNamedPipe::disconnect();
        m_State = P_END;
    }

    // Return the number of bytes readed
    return iResult;
}


bool CNamedPipe::write(const char *pData, tSize iLength)
{
    VPL_ASSERT(pData);

    // Test the pipe state and the allowed pipe type
    if( (m_State & P_CONNECTED) == 0 || (m_Type & P_OUT) == 0 )
    {
        return false;
    }

    // Write the data
    tSize iResult, iLeft = iLength;
    char *pTemp = (char *)pData;
    while( iLeft >= P_BUFFER_SIZE )
    {
        iResult = writen(m_PipeFd, pTemp, P_BUFFER_SIZE);
        if( iResult == -1 )
        {
            // Broken pipe
            CNamedPipe::disconnect();
            m_State = P_BROKEN;
            return false;
        }
        iLeft -= P_BUFFER_SIZE;
        pTemp += P_BUFFER_SIZE;
    }

    // Write the data remainder
    if( iLeft > 0 )
    {
        iResult = writen(m_PipeFd, pTemp, (int)iLeft);
        if( iResult == -1 )
        {
            // Broken pipe
            CNamedPipe::disconnect();
            m_State = P_BROKEN;
            return false;
        }
    }

    // Result
    return true;
}

#endif // _LINUX || _MACOSX


} // namespace sys
} // namespace vpl

