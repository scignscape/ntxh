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
 * Date:    2003/10/16                       
 *
 * Description:
 * - I/O interface by means of virtual channels.
 * - E.g. stdin/stdout, files and named pipes.
 */

#include <VPL/Module/Channel.h>

#include <VPL/Base/Error.h>
#include <VPL/System/Memory.h>
#include <VPL/Math/Base.h>

// STL
#include <cstdlib>


namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Methods of the class vpl::mod::CChannel.
 */
bool CChannel::skip(tSize iLength)
{
    static const int BUFFER_SIZE = 64;

    tLock Lock(*this);

    if( checkType(CH_BIDIRECTIONAL) )
    {
        return false;
    }

    char pcBuffer[BUFFER_SIZE];
    if( m_Type & CH_IN )
    {
        while( iLength > 0 )
        {
            tSize iCount = vpl::math::getMin<tSize>(iLength, BUFFER_SIZE);
            if( this->read(pcBuffer, iCount) != iCount )
            {
                return false;
            }
            iLength -= iCount;
        }
    }
    else if( m_Type & CH_OUT )
    {
        vpl::sys::memSet<char>(pcBuffer, 0, BUFFER_SIZE);
        while( iLength > 0 )
        {
            tSize iCount = vpl::math::getMin<tSize>(iLength, BUFFER_SIZE);
            if( !this->write(pcBuffer, iCount) )
            {
                return false;
            }
            iLength -= iCount;
        }
    }
    else
    {
        return false;
    }

    // O.K.
    return true;
}


CChannel *CChannel::create(EChannelType eType, const std::string& sDesc)
{
    // Read a channel medium
    std::string::size_type Colon = sDesc.find(':');
    std::string sMedium = sDesc.substr(0, Colon);

    // Create a CStdChannel
    if( sMedium == CH_STDIO_TEXT )
    {
        if( sMedium.length() == sDesc.length() )
        {
            return new CStdChannel(eType);
        }
    }

    // CFileChannel
    else if( sMedium == CH_FILE_TEXT )
    {
        // Read a filename
        std::string sFilename = sDesc;
        sFilename.erase(0, sFilename.find(':') + 1);

        // Creation of a channel
        if( sFilename.length() > 0 && sFilename.find(':') == std::string::npos )
        {
            return new CFileChannel(eType, sFilename);
        }
    }

    // CPipeChannel
    else if( sMedium == CH_PIPE_TEXT )
    {
        // Read a pipe name
        std::string sPipename = sDesc;
        sPipename.erase(0, sPipename.find(':') + 1);

        // Creation of a channel
        if( sPipename.length() > 0 && sPipename.find(':') == std::string::npos )
        {
            return new CPipeChannel(eType, sPipename);
        }
    }

    // CSharedMem
    else if( sMedium == CH_SHM_TEXT )
    {
        // Read shared memory name
        std::string sMemname = sDesc;
        sMemname.erase(0, sMemname.find(':') + 1);

        // Creation of a channel
        if( sMemname.length() > 0 && sMemname.find(':') == std::string::npos )
        {
            return new CSharedMemChannel(eType, sMemname);
        }
    }

    // CNullChannel
    else if( sMedium == CH_NULL_TEXT )
    {
        if( sMedium.length() == sDesc.length() )
        {
            return new CNullChannel(eType);
        }
    }

    // Unknown channel specification
    else
    {
        throw CCannotCreate();
    }

    return 0;
}


void CChannel::separate(const std::string& sDescs, std::vector<std::string>& Descs)
{
    // Clear the vector of channel descriptions
    Descs.clear();

    // Find the first occurence of two successive colons
    std::string sTemp = sDescs;
    std::string::size_type Colons = sTemp.find("::");

    // Cut out the channel description
    std::string sTempDescs = sTemp.substr(0, Colons);

    // Parse the whole input string
    while( sTempDescs.length() > 0 )
    {
        // Insert the obtained description to the vector
        Descs.push_back(sTempDescs);

        // It was the last one channel description
        if( Colons == std::string::npos )
        {
            break;
        }

        // Erase it from the string
        sTemp.erase(0, Colons + 2);

        // Find the next occurence of colons
        Colons = sTemp.find("::");

        // Cut out the channel description
        sTempDescs = sTemp.substr(0, Colons);
    }
}


//==============================================================================
/*
 * Methods of the class vpl::mod::CStdChannel.
 */
CStdChannel::CStdChannel(int Type) : CChannel(CH_STDIO, Type)
{
    if( checkType(CH_BIDIRECTIONAL) )
    {
        throw CCannotCreate();
    }
}


CStdChannel::~CStdChannel()
{
    CStdChannel::disconnect();
}


void CStdChannel::disconnect()
{
    CStdChannel::flush();
}


bool CStdChannel::connect(unsigned VPL_UNUSED(uTimeout))
{
    tLock Lock(*this);

    if( m_Type & CH_IN )
    {
        return (!feof(stdin) && !ferror(stdin));
    }
    else if( m_Type & CH_OUT )
    {
        return (!feof(stdout) && !ferror(stdout));
    }
    else
    {
        return false;
    }

}


bool CStdChannel::listen(unsigned uTimeout)
{
    return CStdChannel::connect(uTimeout);
}


bool CStdChannel::wait(unsigned VPL_UNUSED(uTimeout))
{
    tLock Lock(*this);

    if( (m_Type & CH_IN) == 0 )
    {
        return false;
    }
    return (!feof(stdin) && !ferror(stdin));
}


tSize CStdChannel::read(char *pcData, tSize iLength)
{
    VPL_CHECK(pcData && iLength > 0, return 0);

    tLock Lock(*this);

    if( (m_Type & CH_IN) == 0 || feof(stdin) || ferror(stdin) )
    {
        return 0;
    }

    return (tSize)fread(pcData, sizeof(char), (size_t)iLength, stdin);
}


bool CStdChannel::write(const char *pcData, tSize iLength)
{
    VPL_CHECK(pcData && iLength >= 0, return false);

    tLock Lock(*this);

    if( (m_Type & CH_OUT) == 0 || ferror(stdout) )
    {
        return false;
    }

    return (iLength == (tSize)fwrite(pcData, sizeof(char), (size_t)iLength, stdout));
}


bool CStdChannel::isConnected()
{
    tLock Lock(*this);

    if( m_Type & CH_IN )
    {
        int c = getc(stdin);
        if( ferror(stdin) || feof(stdin) )
        {
            return false;
        }
        else
        {
            return (ungetc(c, stdin) != EOF);
        }
    }
    else if ( m_Type & CH_OUT )
    {
        return (ferror(stdout) == 0);
    }
    else
    {
        return false;
    }
}


bool CStdChannel::flush()
{
    tLock Lock(*this);

    if( ferror(stdout) )
    {
        return false;
    }

    return (fflush(stdout) == 0);
}


//==============================================================================
/*
 * Methods of the class vpl::mod::CFileChannel.
 */
CFileChannel::CFileChannel(int Type)
    : CChannel(CH_FILE, Type)
    , m_File(NULL)
{
    if( checkType(CH_BIDIRECTIONAL) )
    {
        throw CCannotCreate();
    }
}


CFileChannel::CFileChannel(int Type, const std::string& sFileName)
    : CChannel(CH_FILE, Type)
    , m_File(NULL)
{
    if( checkType(CH_BIDIRECTIONAL) )
    {
        throw CCannotCreate();
    }

    // Open input file
    if( m_Type & CH_IN )
    {
        m_File = fopen(sFileName.c_str(), "rb");
    }

    // Open output file
    else if( m_Type & CH_OUT )
    {
        m_File = fopen(sFileName.c_str(), "wb");

    }
    m_FileName = sFileName;
}


CFileChannel::~CFileChannel()
{
    CFileChannel::disconnect();
}


void CFileChannel::disconnect()
{
    // Is any file opened
    if( m_File == NULL )
    {
        return;
    }

    // Flush buffers, and close the file
    fflush(m_File);
    fclose(m_File);

    // Clear the file handle
    m_File = NULL;
}


bool CFileChannel::connect(unsigned VPL_UNUSED(uTimeout))
{
    tLock Lock(*this);

    // Check if the file is opened
    if( m_File != NULL )
    {
        return (!feof(m_File) && !ferror(m_File));
    }
    else
    {
        return false;
    }
}


bool CFileChannel::listen(unsigned uTimeout)
{
    return CFileChannel::connect(uTimeout);
}


void CFileChannel::setFilename(const std::string& sFileName)
{
    tLock Lock(*this);

    // Close previously opened file
    CFileChannel::disconnect();

    // Open file
    if( m_Type & CH_IN )
    {
        m_File = fopen(sFileName.c_str(), "rb");
    }
    else if( m_Type & CH_OUT )
    {
        m_File = fopen(sFileName.c_str(), "wb");
    }
    m_FileName = sFileName;
}


bool CFileChannel::wait(unsigned VPL_UNUSED(uTimeout))
{
    tLock Lock(*this);

    if( (m_Type & CH_IN) == 0 || m_File == NULL )
    {
        return false;
    }
    return (!feof(m_File) && !ferror(m_File));
}


tSize CFileChannel::read(char *pcData, tSize iLength)
{
    VPL_CHECK(pcData && iLength > 0, return 0);

    tLock Lock(*this);

    if( (m_Type & CH_IN) == 0 || m_File == NULL )
    {
        return 0;
    }


    return (tSize)fread(pcData, sizeof(char), iLength, m_File);
}


bool CFileChannel::write(const char *pcData, tSize iLength)
{
    VPL_CHECK(pcData && iLength >= 0, return false);

    tLock Lock(*this);

    if( (m_Type & CH_OUT) == 0 || m_File == NULL )
    {
        return false;
    }

    return (iLength == (tSize)fwrite(pcData, sizeof(char), iLength, m_File));
}


bool CFileChannel::isConnected()
{
    tLock Lock(*this);

    if( m_File == NULL )
    {
        return false;
    }

    if( m_Type & CH_IN )
    {
        int c = getc(m_File);
        if( ferror(m_File) || feof(m_File) )
        {
            return false;
        }
        else
        {
            return (ungetc(c, m_File) != EOF);
        }
    }
    else if( m_Type & CH_OUT )
    {
        return (ferror(m_File) == 0);
    }
    else
    {
        return false;
    }
}


bool CFileChannel::flush()
{
    tLock Lock(*this);

    if( m_File == NULL )
    {
        return false;
    }

    return (fflush(m_File) == 0);
}

//==============================================================================
/*
 * Methods of the class vpl::mod::CFileChannelU.
 */
CFileChannelU::CFileChannelU(int Type)
    : CChannel(CH_FILE, Type)
    , m_File(NULL)
{
    if( checkType(CH_BIDIRECTIONAL) )
    {
        throw CCannotCreate();
    }
}


CFileChannelU::CFileChannelU(int Type, const vpl::sys::tString& sFileName)
    : CChannel(CH_FILE, Type)
    , m_File(NULL)
{
    if( checkType(CH_BIDIRECTIONAL) )
    {
        throw CCannotCreate();
    }

    // Open file
	if( m_Type & CH_IN )
    {
        m_File = vpl::sys::fopenU(sFileName, vpl::sys::tString(vplT("rb")));
    }

    // Open output file
    else if( m_Type & CH_OUT )
    {
        m_File = vpl::sys::fopenU(sFileName, vpl::sys::tString(vplT("wb")));
    }
}


CFileChannelU::~CFileChannelU()
{
    CFileChannelU::disconnect();
}


void CFileChannelU::disconnect()
{
    // Is any file opened
    if( m_File == NULL )
    {
        return;
    }

    // Flush buffers, and close the file
    fflush(m_File);
    fclose(m_File);

    // Clear the file handle
    m_File = NULL;
}


bool CFileChannelU::connect(unsigned VPL_UNUSED(uTimeout))
{
    tLock Lock(*this);

    // Check if the file is opened
    if( m_File != NULL )
    {
        return (!feof(m_File) && !ferror(m_File));
    }
    else
    {
        return false;
    }
}


bool CFileChannelU::listen(unsigned uTimeout)
{
    return CFileChannelU::connect(uTimeout);
}


void CFileChannelU::setFilename(const vpl::sys::tString& sFileName)
{
    tLock Lock(*this);

    // Close previously opened file
    CFileChannelU::disconnect();

    // Open file
	if( m_Type & CH_IN )
    {
        m_File = vpl::sys::fopenU(sFileName, vpl::sys::tString(vplT("rb")));
    }

    // Open output file
    else if( m_Type & CH_OUT )
    {
        m_File = vpl::sys::fopenU(sFileName, vpl::sys::tString(vplT("wb")));
    }
}


bool CFileChannelU::wait(unsigned VPL_UNUSED(uTimeout))
{
    tLock Lock(*this);

    if( (m_Type & CH_IN) == 0 || m_File == NULL )
    {
        return false;
    }
    return (!feof(m_File) && !ferror(m_File));
}


tSize CFileChannelU::read(char *pcData, tSize iLength)
{
    VPL_CHECK(pcData && iLength > 0, return 0);

    tLock Lock(*this);

    if( (m_Type & CH_IN) == 0 || m_File == NULL )
    {
        return 0;
    }

    return (tSize)fread(pcData, sizeof(char), iLength, m_File);
}


bool CFileChannelU::write(const char *pcData, tSize iLength)
{
    VPL_CHECK(pcData && iLength >= 0, return false);

    tLock Lock(*this);

    if( (m_Type & CH_OUT) == 0 || m_File == NULL )
    {
        return false;
    }

    return (iLength == (tSize)fwrite(pcData, sizeof(char), iLength, m_File));
}


bool CFileChannelU::isConnected()
{
    tLock Lock(*this);

    if( m_File == NULL )
    {
        return false;
    }

    if( m_Type & CH_IN )
    {
        int c = getc(m_File);
        if( ferror(m_File) || feof(m_File) )
        {
            return false;
        }
        else
        {
            return (ungetc(c, m_File) != EOF);
        }
    }
    else if( m_Type & CH_OUT )
    {
        return (ferror(m_File) == 0);
    }
    else
    {
        return false;
    }
}


bool CFileChannelU::flush()
{
    tLock Lock(*this);

    if( m_File == NULL )
    {
        return false;
    }

    return (fflush(m_File) == 0);
}


//==============================================================================
/*
 * Implementation of the class vpl::mod::CPipeChannel.
 */
CPipeChannel::CPipeChannel(int Type, const std::string& ssName)
    : CChannel(CH_PIPE, Type)
    , m_Pipe(ssName, (Type & CH_IN) ? vpl::sys::P_IN : vpl::sys::P_OUT)
{
    // Pipe can't be opened for input and output simultaneously!
    if( checkType(CH_BIDIRECTIONAL) )
    {
        throw CCannotCreate();
    }
}


CPipeChannel::~CPipeChannel()
{
//    CPipeChannel::disconnect();
}


void CPipeChannel::disconnect()
{
    tLock Lock(*this);

    m_Pipe.disconnect();
}


bool CPipeChannel::connect(unsigned uTimeout)
{
    tLock Lock(*this);

    return m_Pipe.connect(uTimeout);
}


bool CPipeChannel::listen(unsigned uTimeout)
{
    tLock Lock(*this);

    return m_Pipe.listen(uTimeout);
}


bool CPipeChannel::wait(unsigned uTimeout)
{
    tLock Lock(*this);

    return m_Pipe.wait(uTimeout);
}


tSize CPipeChannel::read(char *pcData, tSize iLength)
{
    tLock Lock(*this);

    return m_Pipe.read(pcData, iLength);
}


bool CPipeChannel::write(const char *pcData, tSize iLength)
{
    tLock Lock(*this);

    return m_Pipe.write(pcData, iLength);
}


bool CPipeChannel::isConnected()
{
    tLock Lock(*this);

    return m_Pipe.isConnected();
}


bool CPipeChannel::flush()
{
    return true;
}


//==============================================================================
/*
 * Implementation of the class vpl::mod::CSharedMemChannel.
 */
CSharedMemChannel::CSharedMemChannel(int Type, const std::string& ssName)
    : CChannel(CH_SHM, Type)
    , m_spSemaphore(new vpl::sys::CNamedSemaphore(1, &ssName, NULL))
    , m_spSharedMem(new vpl::sys::CSharedMem(ssName, 0, true, NULL))
    , m_iNumOfBytes(0)
{
    VPL_ASSERT(m_spSemaphore != NULL);
    VPL_ASSERT(m_spSharedMem != NULL);

    // Channel can't be opened for input and output simultaneously!
    if( (Type & CH_BIDIRECTIONAL) == CH_BIDIRECTIONAL )
    {
        throw CCannotCreate();
    }

	m_iNumOfBytes = m_spSharedMem->getSize() - tSize(sizeof(vpl::sys::tUInt64));
    m_pcData = (char *)m_spSharedMem->getData();

    if( m_iNumOfBytes < 0 || !m_pcData )
    {
        m_iNumOfBytes = 0;
        return;
    }

    m_spSemaphore->lock();

    // The number of bytes written in the shared memory is stored at the beginning
	m_piNumOfWrittenBytes = (vpl::sys::tInt64 *)m_pcData;
	m_pcData += sizeof(vpl::sys::tInt64);

    if( Type & CH_OUT )
    {
        // Clear the number of written bytes
        *m_piNumOfWrittenBytes = 0;
    }
    else
    {
        // Check the number of written bytes
        if( m_iNumOfBytes > *m_piNumOfWrittenBytes && *m_piNumOfWrittenBytes > 0 )
        {
            m_iNumOfBytes = tSize(*m_piNumOfWrittenBytes);
        }
        else
        {
            m_iNumOfBytes = 0;
        }
    }

    m_spSemaphore->unlock();
}


CSharedMemChannel::~CSharedMemChannel()
{
    disconnect();
}


void CSharedMemChannel::disconnect()
{
}


bool CSharedMemChannel::connect(unsigned VPL_UNUSED(uTimeout))
{
    tLock Lock(*this);

    return (m_pcData && m_iNumOfBytes > 0);
}


bool CSharedMemChannel::listen(unsigned VPL_UNUSED(uTimeout))
{
    tLock Lock(*this);

    return (m_pcData && m_iNumOfBytes > 0);
}


bool CSharedMemChannel::wait(unsigned VPL_UNUSED(uTimeout))
{
    tLock Lock(*this);

    return (m_pcData && m_iNumOfBytes > 0);
}


tSize CSharedMemChannel::read(char *pcData, tSize iLength)
{
    VPL_CHECK(pcData && iLength > 0, return 0);

    tLock Lock(*this);

    if( (m_Type & CH_IN) == 0 || m_pcData == NULL )
    {
        return 0;
    }

    tSize iMin = vpl::math::getMin(iLength, m_iNumOfBytes);

    m_spSemaphore->lock();
    vpl::sys::memCopy(pcData, m_pcData, iMin);
    m_spSemaphore->unlock();

    m_iNumOfBytes -= iMin;
    m_pcData += iMin;

    return iMin;
}


bool CSharedMemChannel::write(const char *pcData, tSize iLength)
{
    VPL_CHECK(pcData && iLength >= 0, return false);

    tLock Lock(*this);

    if( (m_Type & CH_OUT) == 0 || m_pcData == NULL )
    {
        return false;
    }

    tSize iMin = vpl::math::getMin(iLength, m_iNumOfBytes);
    if( iMin != iLength )
    {
        return false;
    }

    m_spSemaphore->lock();
    vpl::sys::memCopy(m_pcData, pcData, iMin);
    *m_piNumOfWrittenBytes += iMin;
    m_spSemaphore->unlock();

    m_iNumOfBytes -= iMin;
    m_pcData += iMin;

    return true;
}


bool CSharedMemChannel::isConnected()
{
    tLock Lock(*this);

    return (m_pcData && m_iNumOfBytes > 0);
}


bool CSharedMemChannel::flush()
{
    return true;
}


bool CSharedMemChannel::skip(tSize iLength)
{
    tLock Lock(*this);

    if( m_Type & CH_IN )
    {
        tSize iMin = vpl::math::getMin(iLength, m_iNumOfBytes);
        if( iMin != iLength )
        {
            return false;
        }

        m_iNumOfBytes -= iMin;
        m_pcData += iMin;
    }
    else if( m_Type & CH_OUT )
    {
        tSize iMin = vpl::math::getMin(iLength, m_iNumOfBytes);
        if( iMin != iLength )
        {
            return false;
        }

        m_iNumOfBytes -= iMin;
        m_pcData += iMin;

        m_spSemaphore->lock();
        *m_piNumOfWrittenBytes += iMin;
        m_spSemaphore->unlock();
    }
    else
    {
        return false;
    }

    // O.K.
    return true;
}


} // namespace mod
} // namespace vpl

