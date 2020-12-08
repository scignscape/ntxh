//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/11/14                          \n
 *
 * $Id: mdsLog.h 2065 2012-02-02 23:29:38Z spanel $
 *
 * Description:
 * - Logging functions.
 */

#ifndef MDS_LOG_H
#define MDS_LOG_H

#include "mdsBaseExport.h"
#include "mdsAssert.h"
#include "mdsError.h"
#include "mdsWarning.h"
#include "mdsLock.h"
#include "mdsLogChannel.h"
#include "mdsScopedPtr.h"
#include "mdsSharedPtr.h"

// STL
#include <cstring>
#include <string>
#include <set>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <iomanip>


namespace mds
{
namespace base
{

//==============================================================================
/*!
 * Class implementing logging interface.
 */
class MDS_BASE_EXPORT CLog
    : public CObject
    , public CLibraryLockableClass<CLog>
    , public std::streambuf
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CLog);

    //! Size of the buffer.
    enum { SIZE = 512 };

    //! Lock type.
    typedef CLibraryLockableClass<CLog>::CLock tLock;

public:
    //! Default constructor.
    CLog(bool bEnable = true);

    //! Virtual destructor.
    virtual ~CLog();


    //! Returns the output stream.
    std::ostream& getStream() { return *m_pStream; }

    //! Registers a given output channel.
    void registerChannel(CLogChannel *pLogChannel);

    //! Unregisters a specified logging channel.
    void unregisterChannel(CLogChannel *pLogChannel);

    //! Removes all registered channels.
    void removeAllChannels();

    //! Enables/disables the logging.
    void enable(bool bEnable = true);

    //! Disables the logging.
    void disable();


    //! Implementation of virtual functions (std::streambuf).
    virtual int overflow(int c = EOF);
    virtual int underflow();
    virtual int sync();

protected:
    //! Set of all registered logging channels.
    typedef std::set<CLogChannelPtr> tChannels;

protected:
    //! Flag used to disable/enable logging.
    bool m_bEnabled;

    //! Output stream.
    CScopedPtr<std::ostream> m_pStream;

    //! Set of all registered logging channels.
    tChannels m_Channels;

    //! Log buffer.
    char m_pcBuffer[SIZE];

    //! Pointer to the buffer end.
    char *m_pcBufferEnd;
};


//==============================================================================
/*!
 * Smart pointer to the log.
 */
typedef CLog::tSmartPtr     CLogPtr;


} // namespace base
} // namespace mds

#endif // MDS_LOG_H

