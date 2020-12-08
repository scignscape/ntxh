//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/09/28                          \n
 *
 * $Id: mdsStreamChannel.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Buffered channel providing STL-like stream functionality.
 */

#ifndef MDS_StreamChannel_H
#define MDS_StreamChannel_H

#include <MDSTk/Base/mdsScopedPtr.h>

#include "mdsChannel.h"

// STL
#include <streambuf>
#include <iomanip>
#include <istream>
#include <ostream>


namespace mds
{
namespace mod
{

//==============================================================================
/*!
 * Buffered channel providing STL-like stream functionality.
 */
class MDS_MODULE_EXPORT COStreamChannel : public mds::base::CObject, public std::streambuf
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(COStreamChannel);

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
    virtual int overflow(int c = EOF);
    virtual int underflow();
    virtual int sync();

protected:
    //! Output stream.
    mds::base::CScopedPtr<std::ostream> m_pStream;

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
class MDS_MODULE_EXPORT CIStreamChannel : public mds::base::CObject, public std::streambuf
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CIStreamChannel);

    //! Size of the internal buffer.
    enum { SIZE = 512 };

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
    virtual int overflow(int c = EOF);
    virtual int underflow();
    virtual int sync();

protected:
    //! Input stream.
    mds::base::CScopedPtr<std::istream> m_pStream;

    //! Internal buffer.
    char m_pcBuffer[SIZE + 1];

    //! Pointer to the buffer end.
    char *m_pcBufferEnd;

    //! Input channel.
    CChannelPtr m_spChannel;
};


//==============================================================================
/*!
 * Smart pointer to channel CIStreamChannel.
 */
typedef CIStreamChannel::tSmartPtr  CIStreamChannelPtr;


} // namespace mod
} // namespace mds

#endif // MDS_StreamChannel_H

