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
 * Date:    2005/09/08                       
 *
 * Description:
 * - Output logging channels.
 */

#ifndef VPL_LOGCHANNEL_H
#define VPL_LOGCHANNEL_H

#include "BaseExport.h"
#include "SharedPtr.h"

// STL
#include <string>
#include <iostream>
#include <fstream>


namespace vpl
{
namespace base
{

//==============================================================================
/*!
 * Abstract class encapsulating log channel.
 */
class VPL_BASE_EXPORT CLogChannel : public CObject
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CLogChannel);

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
class VPL_BASE_EXPORT CLogChannelOStream : public CLogChannel
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CLogChannelOStream);

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
class VPL_BASE_EXPORT CLogChannelFStream : public CLogChannelOStream
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CLogChannelFStream);

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
} // namespace vpl

#endif // VPL_LOGCHANNEL_H

