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
 * Copyright (c) 2003-2008 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/09/28                       
 *
 * Description:
 * - Buffered channel providing STL-like stream functionality.
 */

#ifndef VPL_StreamChannel_H
#define VPL_StreamChannel_H

#include <VPL/Base/ScopedPtr.h>
#include <VPL/Module/Channel.h>

// STL
#include <streambuf>
#include <iomanip>
#include <istream>
#include <ostream>

namespace vpl
{
namespace mod
{

//==============================================================================
/*!
 * Buffered channel providing STL-like stream functionality.
 */
class VPL_MODULE_EXPORT COStreamChannel : public vpl::base::CObject, public std::streambuf
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(COStreamChannel);

    //! Size of the internal buffer.
    enum { SIZE = 512 };

public:
    //! Default constructor.
    //! - Pointer to an output channel.
    COStreamChannel(CChannel *pChannel);

    //! Virtual destructor
    virtual ~COStreamChannel();

    //! Returns the output stream.
    std::ostream& getStream() { return *m_pStream; }

    //! Returns pointer to the output channel.
    CChannel *getChannel() { return m_spChannel.get(); }

    //! Sets the output channel.
    void setChannel(CChannel *pChannel) { m_spChannel = pChannel; }

    //! Implementation of virtual functions (std::streambuf).
	virtual int overflow(int c = EOF) override;
	virtual int underflow() override;
	virtual int sync() override;

protected:
    //! Output stream.
    vpl::base::CScopedPtr<std::ostream> m_pStream;

    //! Internal buffer.
    char m_pcBuffer[SIZE + 1];

    //! Pointer to the buffer end.
    char *m_pcBufferEnd;

    //! Output channel.
    CChannelPtr m_spChannel;
};


//==============================================================================
/*!
 * Smart pointer to channel COStreamChannel.
 */
typedef COStreamChannel::tSmartPtr  COStreamChannelPtr;


//==============================================================================
/*!
 * Buffered channel providing STL-like stream functionality.
 */
class VPL_MODULE_EXPORT CIStreamChannel : public vpl::base::CObject, public std::streambuf
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CIStreamChannel);

    //! Size of the internal buffer.
    enum { SIZE = 512 };

    //! Size of an area on the beginning of the buffer, wich is used to store some data from previous load.
    enum { MEM = 16 };
    
    //! Excwptions thrown when invalid seek is used
    VPL_DECLARE_EXCEPTION(CSeekBeyond, "Seek error: cannot seek beyond buffer")
    VPL_DECLARE_EXCEPTION(CSeekBeginning, "Seek error: cannot seek to beginning")
    VPL_DECLARE_EXCEPTION(CSeekEnd, "Seek error: cannot seek to end")

public:
    //! Default constructor.
    //! - Pointer to an input channel.
    CIStreamChannel(CChannel *pChannel);

    //! Virtual destructor
    virtual ~CIStreamChannel();

    //! Returns the output stream.
    std::istream& getStream() { return *m_pStream; }

    //! Returns pointer to the input channel.
    CChannel *getChannel() { return m_spChannel.get(); }

    //! Sets the input channel.
    void setChannel(CChannel *pChannel) { m_spChannel = pChannel; }

    //! Implementation of virtual functions (std::streambuf).
	virtual int overflow(int c = EOF) override;
	virtual int underflow() override;
	virtual int sync() override;

    //! Seeks are supported only within internal buffer with size SIZE
    virtual std::streampos seekoff(std::streamoff off, std::ios_base::seekdir way,
                                   std::ios_base::openmode which = std::ios_base::in | std::ios_base::out) override;
    virtual std::streampos seekpos(std::streampos sp, std::ios_base::openmode which = std::ios_base::in | std::ios_base::out) override;

protected:
    //! Input stream.
    vpl::base::CScopedPtr<std::istream> m_pStream;

    //! Internal buffer.
    char m_pcBuffer[SIZE + 1];

    //! Pointer to the buffer end.
    char *m_pcBufferEnd;

    //! Input channel.
    CChannelPtr m_spChannel;

    //! Number of loaded blocks
    unsigned int m_numberOfBlocks;
};


//==============================================================================
/*!
 * Smart pointer to channel CIStreamChannel.
 */
typedef CIStreamChannel::tSmartPtr  CIStreamChannelPtr;


} // namespace mod
} // namespace vpl

#endif // VPL_StreamChannel_H

