//==============================================================================
/* This file is part of
 *
 * VPL - Voxel Processing Library
 * Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef VPL_Logger_H
#define VPL_Logger_H

#include "MinimalLogger.h"

#include "Assert.h"
#include "Error.h"
#include "Warning.h"
#include "Lock.h"
#include "LogChannel.h"
#include "ScopedPtr.h"
#include "SharedPtr.h"
#include "Singleton.h"
#include "Exception.h"

#include "LogRecord.h"
#include "LogFilters.h"
#include "LogAppender.h"
#include "LogIDEAppender.h"


namespace vpl
{
namespace base
{

//==============================================================================
/*!
 * Class implementing logging interface.
 */
class VPL_BASE_EXPORT CLoggerBase
    : public MinimalLogger
    , public CLibraryLockableClass<CLoggerBase>
	, public CLogFilterPool
{
public:
	//! Smart pointer type.
	//! - Declares type tSmartPtr.
	VPL_SHAREDPTR(CLoggerBase);

	//! Lock type.
	typedef CLibraryLockableClass<CLoggerBase>::CLock tLock;

public:
	//! Constructor
	CLoggerBase(bool bEnableTimeStamp = true);

	//! Log
	virtual void log(int level, const std::string &file, size_t line, unsigned threadId, const std::string &message, long tag = 0, bool raw = false)
    {
        log(level, "", file, line, threadId, message, tag, raw);
    }

	//! Log (with category)
    virtual void log(int level, std::string category, const std::string & file, size_t line, unsigned threadId, const std::string & message, long tag = 0, bool raw = false);
	
	//! Log exception
	virtual void log(int level, const std::string &file, size_t line, unsigned threadId, const vpl::base::CFullException& Exception, long tag = 0, bool raw = false)
	{
		log(level, "", file, line, threadId, Exception.what(), tag, raw);
	}
	
	//! Log exception (with category)
	virtual void log(int level, std::string category, const std::string &file, size_t line, unsigned threadId, const vpl::base::CFullException& Exception, long tag = 0, bool raw = false)
	{
		log(level, category, file, line, threadId, Exception.what(), tag, raw);
	}

	//! Log error
	virtual void log(int level, const std::string &file, size_t line, unsigned threadId, const vpl::base::CError& error, long tag = 0, bool raw = false)
	{
		log(level, "", file, line, threadId, error.what(), tag, raw);
	}

	//! Log error (with category)
	virtual void log(int level, std::string category, const std::string &file, size_t line, unsigned threadId, const vpl::base::CError& error, long tag = 0, bool raw = false)
	{
		log(level, category, file, line, threadId, error.what(), tag, raw);
	}

	//! Add appender
	virtual CLogAppender *addAppender(CLogAppender *appender);

    //! Try to find appender with given name
    virtual CLogAppender *getAppender(const std::string &name);

    //! Set used path length
    void setPathLength(int length) { m_pathLength = length; }

    /**
     * Sets level threshold dynamically
     *
     * \param   level   The level - see LL_TRACE to LL_FATAL macros.
     */
    void setLevelThreshold(int level);

protected:
	//! Get next log id
	unsigned long getId(bool increase_counter) {if(increase_counter) return m_id_counter++; else return m_id_counter;}

    //! Shorten path 
    std::string shortenPath(const std::string &path, int num_segments = 0);

protected:
	//! There is one special filter - global level threshold
	CLogFilterByLevel m_levelThresholdFilter;

	//! Log record buffer
	CLogRecord m_recordBuffer;

	//! Should be time stamp added to the log record?
	bool m_bTimeStampEnabled;

	//! Id counter 
	static unsigned long m_id_counter;

    //! Appenders vector type
    typedef std::vector<CLogAppenderPtr> tAppenderPtrVec;

    //! Appenders
	tAppenderPtrVec m_appenders;

    //! Default path length - -1 is whole path, 0 - only file name, 1 - file name + subdirectory (one)
    int m_pathLength;   
};

//! Smart pointer to the logger.
typedef CLoggerBase::tSmartPtr CLoggerPtr;


//==============================================================================
/*!
 * Global logging singleton.
 */
class CLoggerSingleton : public CLoggerBase, public CSingleton<SL_LOGGER>
{
private:
	//! Private constructor.
	CLoggerSingleton() : CLoggerBase(true) {}

	//! Allow main log instantiation using the singleton holder.
	VPL_PRIVATE_SINGLETON(CLoggerSingleton);
};


//==============================================================================
/*
 * Certain logging macros.
 */

//! Returns reference to the global application log.
#define VPL_GLOBAL_LOGGER      VPL_SINGLETON(vpl::base::CLoggerSingleton)

//! Add std cout appender
#define VPL_LOG_ADD_CERR_APPENDER VPL_GLOBAL_LOGGER.addAppender(new vpl::base::COStreamAppender());
#define VPL_LOG_ADD_CERR_APPENDER_NAMED(name) VPL_GLOBAL_LOGGER.addAppender(new vpl::base::COStreamAppender(std::cerr, std::string(name)));

//! Add file output appender
#define VPL_LOG_ADD_FILE_APPENDER(file_name) VPL_GLOBAL_LOGGER.addAppender(new vpl::base::CFStreamAppender(std::string(file_name)));
#define VPL_LOG_ADD_FILE_APPENDER_NAMED(file_name, appender_name) VPL_GLOBAL_LOGGER.addAppender(new vpl::base::CFStreamAppender(std::string(file_name), std::string(appender_name)));

//! Add IDE output appender
#define VPL_LOG_ADD_IDE_APPENDER VPL_GLOBAL_LOGGER.addAppender(new vpl::base::CIDEAppender);
#define VPL_LOG_ADD_IDE_APPENDER_NAMED(name) VPL_GLOBAL_LOGGER.addAppender(new vpl::base::CIDEAppender(std::string(name));


} // namespace base
} // namespace vpl

#endif  // VPL_Logger_H
