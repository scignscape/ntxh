//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/08                          \n
 *
 * $Id: mdsLogChannel.h 2039 2011-12-28 14:00:13Z spanel $
 *
 * Description:
 * - Output logging channels.
 */

#ifndef MDS_LOGCHANNEL_H
#define MDS_LOGCHANNEL_H

#include "mdsBaseExport.h"
#include "mdsSharedPtr.h"

// STL
#include <string>
#include <iostream>
#include <fstream>


namespace mds
{
namespace base
{

//==============================================================================
/*!
 * Abstract class encapsulating log channel.
 */
class MDS_BASE_EXPORT CLogChannel : public CObject
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CLogChannel);

public:
    //! Virtual destructor.
    virtual ~CLogChannel() {}

    //! Writes a given log entry to the channel.
    virtual void entry(const char *pcData) = 0;
};


//==============================================================================
/*!
 * Smart pointer to the log channel.
 */
typedef CLogChannel::tSmartPtr  CLogChannelPtr;


//==============================================================================
/*!
 * Channel for logging to the output STL stream.
 */
class MDS_BASE_EXPORT CLogChannelOStream : public CLogChannel
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CLogChannelOStream);

public:
    //! Constructor.
    CLogChannelOStream(std::ostream& Stream) : m_Stream(Stream) {}

    //! Virtual destructor
    virtual ~CLogChannelOStream() {}

    //! Writes a given log entry to the channel.
    virtual void entry(const char *pcData)
    {
        m_Stream << pcData << std::flush;
    }

protected:
    //! Output STL stream.
    std::ostream& m_Stream;

    //! Protected copy constructor.
    CLogChannelOStream(const CLogChannelOStream&);

    //! Protected assignment operator.
    void operator=(const CLogChannelOStream&);
};


//==============================================================================
/*!
 * Smart pointer to the log channel.
 */
typedef CLogChannelOStream::tSmartPtr   CLogChannelOStreamPtr;


//==============================================================================
/*!
 * Channel for logging to the file stream.
 */
class MDS_BASE_EXPORT CLogChannelFStream : public CLogChannelOStream
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CLogChannelFStream);

public:
    //! Constructor.
    CLogChannelFStream(const char *pcFileName);

    //! Constructor.
    CLogChannelFStream(const std::string& ssFileName);

    //! Virtual destructor.
    virtual ~CLogChannelFStream();

protected:
    //! Output file stream.
    std::ofstream m_FileStream;

    //! Protected copy constructor.
    CLogChannelFStream(const CLogChannelFStream&);

    //! Protected assignment operator.
    void operator=(const CLogChannelFStream&);
};


//==============================================================================
/*!
 * Smart pointer to the log channel.
 */
typedef CLogChannelFStream::tSmartPtr   CLogChannelFStreamPtr;


} // namespace base
} // namespace mds

#endif // MDS_LOGCHANNEL_H

