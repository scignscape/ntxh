//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/08                          \n
 *
 * $Id: mdsGlobalLog.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Global application log.
 * - Logging of errors, exceptions and etc.
 * - Uses std::cerr and/or *.log file as output.
 */

#ifndef MDS_GLOBALLOG_H
#define MDS_GLOBALLOG_H

#include <MDSTk/System/mdsTimestamp.h>

#include "mdsLog.h"
#include "mdsSingleton.h"

// STL
#include <string>
#include <iostream>


namespace mds
{
namespace base
{

//==============================================================================
/*
 * Global constants.
 */

//! Default log file extension.
const std::string LOG_DEFAULT_EXT   = ".log";


//==============================================================================
/*!
 * Global application log.
 */
class CGlobalLog : public CLog, public CLibrarySingleton
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CGlobalLog);

public:
    //! Virtual destructor.
    virtual ~CGlobalLog() {}

private:
    //! Private constructor.
    CGlobalLog() {}

    //! Allow main log instantiation using the singleton holder.
    MDS_PRIVATE_SINGLETON(CGlobalLog);
};


//==============================================================================
/*
 * Certain logging macros.
 */

//! Returns reference to the global application log.
#define MDS_GLOBAL_LOG      MDS_SINGLETON(mds::base::CGlobalLog)

// Logging enabled
#ifndef MDS_LOGGING_DISABLED

//! Initializes global application log.
//! - Enables logging to the stderr
#   define MDS_LOG_INIT_STDERR \
        MDS_GLOBAL_LOG.registerChannel(new mds::base::CLogChannelOStream(std::cerr))

//! Initializes global application log.
//! - Enables logging to a file
#   define MDS_LOG_INIT_FILE(Filename) \
        MDS_GLOBAL_LOG.registerChannel(new mds::base::CLogChannelFStream(Filename))

//! Enters logging mutual section.
#   define MDS_LOG_ENTER \
        MDS_GLOBAL_LOG.lock()

//! Leaves logging mutual section.
#   define MDS_LOG_LEAVE \
        MDS_GLOBAL_LOG.unlock()

//! Writes a given expression to the log stream.
#   define MDS_LOG(Value) \
    { \
        MDS_LOG_ENTER; \
        MDS_GLOBAL_LOG.getStream() << Value; \
        MDS_LOG_LEAVE; \
    }

//! Macro that mutually writes to the std::cerr.
#   define MDS_CERR(Value) \
    { \
        MDS_LOG_ENTER; \
        std::cerr << Value; \
        MDS_LOG_LEAVE; \
    }

//! Enables logging.
#   define MDS_LOG_ENABLE \
        MDS_GLOBAL_LOG.enable()

//! Disables logging.
#   define MDS_LOG_DISABLE \
        MDS_GLOBAL_LOG.disable()

//! Logging disabled
#else

//! Does nothing.
#   define MDS_LOG_INIT_STDERR          ((void)0)
#   define MDS_LOG_INIT_FILE(Filename)  ((void)0)
#   define MDS_LOG_ENTER                ((void)0)
#   define MDS_LOG_LEAVE                ((void)0)
#   define MDS_LOG(Value)               ((void)0)
#   define MDS_CERR(Value)              ((void)0)
#   define MDS_LOG_ENABLE               ((void)0)
#   define MDS_LOG_DISABLE              ((void)0)

#endif // MDS_LOGGING_DISABLED


//! Logs current time.
#define MDS_LOG_TIME(Desc)          MDS_LOG(MDS_TIMESTAMP(Desc))

//! Creates and logs error.
#define MDS_LOG_ERROR(Reason)       MDS_LOG(MDS_ERROR(Reason))

//! Creates and logs warning.
#define MDS_LOG_WARNING(Reason)     MDS_LOG(MDS_WARNING(Reason))

//! Logs a simple note.
#define MDS_LOG_NOTE(Value)         MDS_LOG("<note> " << Value << std::endl)


} // namespace base
} // namespace mds

#endif // MDS_GLOBALLOG_H

