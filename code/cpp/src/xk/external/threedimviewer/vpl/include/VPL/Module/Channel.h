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
 * Date:    2003/10/23                       
 *
 * Description:
 * - I/O interface by means of virtual channels.
 * - E.g. stdin/stdout, files and named pipes.
 * - Some trick have to be used to switch stdin and stdout to the binary mode!
 */

#ifndef VPL_CHANNEL_H
#define VPL_CHANNEL_H

#include <VPL/Base/Types.h>
#include <VPL/Base/Assert.h>
#include <VPL/Base/Exception.h>
#include <VPL/Base/SharedPtr.h>
#include <VPL/Base/Lock.h>
#include <VPL/System/NamedPipe.h>
#include <VPL/System/SharedMem.h>
#include <VPL/System/NamedSemaphore.h>
#include <VPL/System/String.h>

#include "ModuleExport.h"

// STL
#include <cstdio>
#include <string>
#include <vector>


namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Global definitions and constants.
 */

//! Channel types. Usually, the listed types cannot be combined together,
//! channel can be either input or output. However, there are some bidirectional
//! channels which can be opened in both directions. See the comments.
enum EChannelType
{
    //! Unknown channel.
    CH_UNKNOWN          = 0,

    //! Input channel.
    CH_IN               = 1 << 0,

    //! Output channel.
    CH_OUT              = 1 << 1,

    //! Bidirectional channel.
    CH_BIDIRECTIONAL    = CH_IN | CH_OUT,

    //! Channel compressor.
    CH_COMPRESSOR       = 1 << 2,

    //! Channel data predictor.
    CH_PREDICTOR        = 1 << 3
};


//! Channel transmission medium.
enum EChannelMedium
{
    //! Null channel.
    CH_NULL     = 0,

    //! Channel via stdin and stdout.
    CH_STDIO    = 1,

    //! Channel implemented over files.
    CH_FILE,

    //! Channel using named pipes.
    CH_PIPE,

    //! Channel over a shared memory.
    CH_SHM,

    //! Communication over network (not yet implemented).
    CH_TCP,

    //! Channel over a memory buffer.
    CH_MEM
};

//! Channel medium (textual form)
const std::string CH_NULL_TEXT = "null";
const std::string CH_STDIO_TEXT = "stdio";
const std::string CH_FILE_TEXT = "file";
const std::string CH_PIPE_TEXT = "pipe";
const std::string CH_SHM_TEXT = "shm";

//! Channel medium (textual form) for geting by id.
const std::string CH_MEDIUM_TYPE[5] = { CH_NULL_TEXT ,CH_STDIO_TEXT,CH_FILE_TEXT,CH_PIPE_TEXT,CH_SHM_TEXT };


//! Timeout used for connection establishing.
const unsigned CH_CONNECTION_TIMEOUT    = 15000;

//! Timeout used for waiting for data.
const unsigned CH_WAIT_TIMEOUT          = 1000;


//==============================================================================
/*!
 * Base abstract class for all classes implementing channels.
 */
class VPL_MODULE_EXPORT CChannel
    : public vpl::base::CObject
    , public vpl::base::CLibraryLockableObject<CChannel>
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CChannel);

    //! Lock that have to be used to provide mutual access to write(), read()
    //! and etc. functions.
    typedef vpl::base::CLibraryLockableObject<CChannel>::CLock tLock;

    //! Exception thrown from constructor, or the create() method, in case of some error.
    VPL_DECLARE_EXCEPTION(CCannotCreate, "Failed to create a new channel")

public:
    //! Default constructor.
    //! - It doesn't initialize the channel type and medium!
    //! - Use with care!
    CChannel() : m_Type(CH_UNKNOWN), m_Medium(CH_NULL) {}

    //! Constructor.
    //! - Initializes the channel type and medium.
    CChannel(int Medium, int Type) : m_Type(Type), m_Medium(Medium) {}

    //! Virtual destructor.
    virtual ~CChannel() {}

    //! Method returns the channel type.
    int getType() const { return m_Type; }

    //! Checks if channel type corresponds to a given value.
    bool checkType(int Type) const { return ((m_Type & Type) == Type); }

    //! Returns the channel medium.
    int getMedium() const { return m_Medium; }

    //! Checks if channel medium is equal to a given value.
    bool checkMedium(int Medium) const { return (m_Medium == Medium); }


    //! Connects to the opposite channel side.
    //! - If the channel is connection oriented, this function must be called
    //!   on the client side before any communication!
    //! - Returns false on failure or timeout elapsed.
    virtual bool connect(unsigned uTimeout = CH_CONNECTION_TIMEOUT) = 0;

    //! Listens for and accepts an incoming connection.
    //! - If the channel is connection oriented, this function must be called
    //!   on the server side before any communication!
    //! - Returns false on failure or timeout elapsed.
    virtual bool listen(unsigned uTimeout = CH_CONNECTION_TIMEOUT) = 0;

    //! Disconnects from the opossite channel side.
    //! - The function can be called on the server or client side.
    virtual void disconnect() = 0;

    //! Method for testing channel errors such as: disconnected or broken
    //! channel, reading after end of input, etc.
    //! - The function can be called on the server or client side.
    virtual bool isConnected() = 0;


    //! Waits for data.
    //! - Returns false if timeout elapses or the channel is not input.
    virtual bool wait(unsigned uTimeout = CH_WAIT_TIMEOUT) = 0;

    //! Reads bytes from the input channel.
    //! - In case of error or reading after end of input
    //!   the number of successfully readed bytes is returned.
    virtual tSize read(char *pcData, tSize iLength) = 0;

    //! Writes data to the output channel.
    virtual bool write(const char *pcData, tSize iLength) = 0;

    //! Finalizes all writing/reading operations (flushes internal buffers, etc.).
    virtual bool flush() = 0;

    //! Skips a given number of bytes.
    //! - If the channel is open for readinpg, the data are discarded.
    //!   Otherwise, zeros are written to the output channel.
    //! - This method cannot be used if the channel is opened for reading
    //!   and writting simultaneously!
    virtual bool skip(tSize iLength);


    //! Creation of a channel which is described by a textual string.
    //! - String has the form: "chmedium[:chattrib1[:chattrib2[:...]]]".
    //! - Actually, the channel medium can be "stdio", "file", "pipe"
    //!   and "shm".
    //! - Channel attributes depend on the medium.
    //! - "stdio" has empty attributes, "file" (:filename), "pipe" (:pipename)
    //!   and "shm" (:shmname).
    //! - Throws CCannotCreate exception on failure!
    static CChannel *create(EChannelType eType, const std::string& sDesc);

    //! Parses a given string and separates descriptions of several channels.
    //! - Channels are separated by two successive colons "::" in the string.
    //! - Example: "chmedium1[:chattribs1][::chmedium2[:chattribs2][::...]]".
    static void separate(const std::string& sDescs,
                         std::vector<std::string>& Descs
                         );

    //! Returns input and/or output file name
    std::string getFileName() {return m_FileName;}

protected:
    //! Channel type.
    int m_Type;

    //! Channel medium.
    int m_Medium;

    //! Input and/or output file name
    std::string m_FileName;
};


//==============================================================================
/*!
 * Smart pointer to channel.
 */
typedef CChannel::tSmartPtr     CChannelPtr;


//==============================================================================
/*!
 * Null channel that doesn't write or read any data. It just counts the number
 * of written and read bytes of data.
 * - This channel is bidirectional. It can be opened for reading
 *   and writing simultaneously.
 */
class VPL_MODULE_EXPORT CNullChannel : public CChannel
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CNullChannel);

public:
    //! Constructor.
    //! - Channel type.
    CNullChannel(int Type)
        : CChannel(CH_NULL, Type)
        , m_iReadCount(0)
        , m_iWrittenCount(0)
    {}

    //! Destructor.
    virtual ~CNullChannel() {}

    //! Returns the number of bytes read from the channel.
    tSize getNumOfReadBytes()
    {
        tLock Lock(*this);

        return m_iReadCount;
    }

    //! Returns the number of bytes written to the channel.
    tSize getNumOfWrittenBytes()
    {
        tLock Lock(*this);

        return m_iWrittenCount;
    }

    //! Clears the number of read an written bytes.
    void clearNumOfBytes()
    {
        tLock Lock(*this);

        m_iReadCount = 0;
        m_iWrittenCount = 0;
    }

    // Virtual methods
    virtual bool connect(unsigned VPL_UNUSED(uTimeout)) override { return true; }
	virtual bool listen(unsigned VPL_UNUSED(uTimeout)) override { return true; }
	virtual void disconnect() override {}
	virtual bool isConnected() override { return true; }
	virtual bool wait(unsigned VPL_UNUSED(uTimeout)) override { return true; }
	virtual bool flush() override { return true; }

    //! Increases an internal counter of read bytes.
    //! - The function always returns the required number of bytes.
	virtual tSize read(char * VPL_UNUSED(pcData), tSize iLength) override
    {
        tLock Lock(*this);

        m_iReadCount += iLength;
        return iLength;
    }

    //! Increases an internal counter of written bytes.
    //! - The function always returns true.
	virtual bool write(const char * VPL_UNUSED(pcData), tSize iLength) override
    {
        tLock Lock(*this);

        m_iWrittenCount += iLength;
        return true;
    }

protected:
    //! The number of read/written bytes.
    tSize m_iReadCount, m_iWrittenCount;
};


//==============================================================================
/*!
 * Smart pointer to null channel.
 */
typedef CNullChannel::tSmartPtr     CNullChannelPtr;


//==============================================================================
/*!
 * Channel implemented via reading stdin and writing stdout.
 */
class VPL_MODULE_EXPORT CStdChannel : public CChannel
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CStdChannel);

public:
    //! Constructor.
    //! - Channel type.
    CStdChannel(int Type);

    //! Destructor.
    virtual ~CStdChannel();

    // Virtual methods
	virtual bool connect(unsigned uTimeout = CH_CONNECTION_TIMEOUT) override;
	virtual bool listen(unsigned uTimeout = CH_CONNECTION_TIMEOUT) override;
	virtual void disconnect() override;
	virtual bool isConnected() override;
	virtual bool wait(unsigned uTimeout = CH_WAIT_TIMEOUT) override;
	virtual tSize read(char *pcData, tSize iLength) override;
	virtual bool write(const char *pcData, tSize iLength) override;
	virtual bool flush() override;
};


//==============================================================================
/*!
 * Smart pointer to stdin/stdout channel.
 */
typedef CStdChannel::tSmartPtr      CStdChannelPtr;


//==============================================================================
/*!
 * I/O by means of reading and writing files.
 */
class VPL_MODULE_EXPORT CFileChannel : public CChannel
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CFileChannel);

public:
    //! Constructor.
    //! - Allowed channel types are CH_IN and CH_OUT.
    //! - Input/output file.
    CFileChannel(int Type, const std::string& sFileName);

    //! Constructor.
    //! - Allowed channel types are CH_IN and CH_OUT.
    CFileChannel(int Type);

    //! Destructor.
    virtual ~CFileChannel();

    //! Changes the input filename (and closes the previously opened one).
    void setFilename(const std::string& sFileName);

    // Virtual methods
	virtual bool connect(unsigned uTimeout = CH_CONNECTION_TIMEOUT) override;
	virtual bool listen(unsigned uTimeout = CH_CONNECTION_TIMEOUT) override;
	virtual void disconnect() override;
	virtual bool isConnected() override;
	virtual bool wait(unsigned uTimeout = CH_WAIT_TIMEOUT) override;
	virtual tSize read(char *pcData, tSize iLength) override;
	virtual bool write(const char *pcData, tSize iLength) override;
	virtual bool flush() override;

protected:
    //! Input and/or output binary file
    FILE *m_File;
};


//==============================================================================
/*!
 * Smart pointer to file channel.
 */
typedef CFileChannel::tSmartPtr     CFileChannelPtr;


//==============================================================================
/*!
 * I/O by means of reading and writing files with Unicode names.
 */
class VPL_MODULE_EXPORT CFileChannelU : public CChannel
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CFileChannelU);

public:
    //! Constructor.
    //! - Allowed channel types are CH_IN and CH_OUT.
    //! - Input/output file.
    CFileChannelU(int Type, const vpl::sys::tString& sFileName);

    //! Constructor.
    //! - Allowed channel types are CH_IN and CH_OUT.
    CFileChannelU(int Type);

    //! Destructor.
    virtual ~CFileChannelU();

    //! Changes the input filename (and closes the previously opened one).
    void setFilename(const vpl::sys::tString& sFileName);

    // Virtual methods
	virtual bool connect(unsigned uTimeout = CH_CONNECTION_TIMEOUT) override;
	virtual bool listen(unsigned uTimeout = CH_CONNECTION_TIMEOUT) override;
	virtual void disconnect() override;
	virtual bool isConnected() override;
	virtual bool wait(unsigned uTimeout = CH_WAIT_TIMEOUT) override;
	virtual tSize read(char *pcData, tSize iLength) override;
	virtual bool write(const char *pcData, tSize iLength) override;
	virtual bool flush() override;

protected:
    //! Input and/or output binary file
    FILE *m_File;
};


//==============================================================================
/*!
 * Smart pointer to file channel.
 */
typedef CFileChannelU::tSmartPtr     CFileChannelUPtr;


//==============================================================================
/*!
 * Channel via named pipes.
 */
class VPL_MODULE_EXPORT CPipeChannel : public CChannel
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CPipeChannel);

public:
    //! Constructor.
    //! - Allowed channel types are CH_IN and CH_OUT.
    //! - Name of the pipe.
    //! - Pipe channel cannot be opened for input and output simultaneously!
    //!   Constructor throws exception in this case!
    CPipeChannel(int Type, const std::string& ssName);

    //! Destructor.
    virtual ~CPipeChannel();

    // Virtual methods
	virtual bool connect(unsigned uTimeout = CH_CONNECTION_TIMEOUT) override;
	virtual bool listen(unsigned uTimeout = CH_CONNECTION_TIMEOUT) override;
	virtual void disconnect() override;
	virtual bool isConnected() override;
	virtual bool wait(unsigned uTimeout = CH_WAIT_TIMEOUT) override;
	virtual tSize read(char *pcData, tSize iLength) override;
	virtual bool write(const char *pcData, tSize iLength) override;
	virtual bool flush() override;

protected:
    //! Input and/or output named pipe
    vpl::sys::CNamedPipe m_Pipe;
};


//==============================================================================
/*!
 * Smart pointer to pipe channel.
 */
typedef CPipeChannel::tSmartPtr     CPipeChannelPtr;


//==============================================================================
/*!
 * Channel over shared memory.
 * - Only for testing!
 */
class VPL_MODULE_EXPORT CSharedMemChannel : public CChannel
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CSharedMemChannel);

public:
    //! Constructor.
    //! - Opens an existing shared memory.
    //! - Allowed channel types are CH_IN and CH_OUT.
    //! - Name of the shared memory.
    //! - This channel cannot be opened for input and output simultaneously!
    //!   Constructor throws exception in this case!
    CSharedMemChannel(int Type, const std::string& ssName);

    //! Destructor.
    virtual ~CSharedMemChannel();

    //! Returns pointer to the shared memory.
    vpl::sys::CSharedMem *getSharedMemPtr() { return m_spSharedMem; }

    //! Returns current pointer to the remaining (unread) data.
    char *getDataPtr() { return m_pcData; }

    // Virtual methods
	virtual bool connect(unsigned uTimeout = CH_CONNECTION_TIMEOUT) override;
	virtual bool listen(unsigned uTimeout = CH_CONNECTION_TIMEOUT) override;
	virtual void disconnect() override;
	virtual bool isConnected() override;
	virtual bool wait(unsigned uTimeout = CH_WAIT_TIMEOUT) override;
	virtual tSize read(char *pcData, tSize iLength) override;
	virtual bool write(const char *pcData, tSize iLength) override;
	virtual bool flush() override;

    //! Skips a given number of bytes.
	virtual bool skip(tSize iLength) override;

protected:
    //! Named semaphore used to lock the shared memory.
    vpl::sys::CNamedSemaphorePtr m_spSemaphore;

    //! Shared memory.
    vpl::sys::CSharedMemPtr m_spSharedMem;

    //! The number of bytes remaining in the shared memory.
    tSize m_iNumOfBytes;

    //! Pointer to the data byte in the shared memory.
    char *m_pcData;

    //! Pointer to the number of bytes written to the shared memory.
    vpl::sys::tInt64 *m_piNumOfWrittenBytes;
};


//==============================================================================
/*!
 * Smart pointer to shared memory channel.
 */
typedef CSharedMemChannel::tSmartPtr    CSharedMemChannelPtr;


} // namespace mod
} // namespace vpl

#endif // VPL_CHANNEL_H

