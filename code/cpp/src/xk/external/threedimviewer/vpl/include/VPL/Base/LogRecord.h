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

#ifndef VPL_LogRecord_H
#define VPL_LogRecord_H

#include <string>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif

// Linux and Mac version
#if defined(_LINUX) || defined(_MACOSX)
#    include <unistd.h>
#    include <pthread.h>
#    include <sys/types.h>
#    include <time.h>
#    include <errno.h>
#endif

#define LL_TRACE 0
#define LL_DEBUG 1
#define LL_INFO	 2
#define LL_WARN  4
#define LL_ERROR 8
#define LL_FATAL 16

namespace vpl
{
namespace base
{

/**
 * Log record structure. 
**/
struct CLogRecord
{
public:
	//! Simple constructor
	CLogRecord();

	//! Constructor 
	CLogRecord(int level, const std::string &file, size_t line, unsigned threadId, const std::string &message, long tag = 0, bool raw = false);

	//! Constructor 
	CLogRecord(int level, std::string category, const std::string &file, size_t line, unsigned threadId, const std::string &message, long tag = 0, bool raw = false);

	//! Copy constructor
	CLogRecord(const CLogRecord &rec);

	//! Set all needed data
	void set(int level, const std::string &file, size_t line, unsigned threadId, const std::string &message, long tag = 0, bool raw = false);

	//! Set all needed data
	void set(int level, std::string category, const std::string &file, size_t line, unsigned threadId, const std::string &message, long tag = 0, bool raw = false);

	//! Get id
	unsigned long getId() const {return m_id;}

	//! Get level
	size_t getLevel() const {return m_level;}

	//! Get logged thread ID.
	unsigned getThreadId() const { return m_threadId; }

	//! Get record message
	std::string getMessage() const {return m_message;}

    //! Get record category
    std::string getCategory() const { return m_category; }

	//! Get record time
	void getTime(unsigned int &year, unsigned int &month, unsigned int &dayOfWeek, unsigned int &day, unsigned int &hour, unsigned int &minute ,unsigned int &second, unsigned int &milliseconds) const;

	//! Get tag
	long getTag() const {return m_tag;}

	//! Get file name
	const std::string &getFileName() const {return m_file;}

	//! Get line number
	size_t getLineNumber() const {return m_line;}

    //! Is it "raw" record
    bool isRaw() const {return m_bRaw;}

protected:
	//! Identification number
	unsigned long m_id; 

	//! Record level
	size_t m_level;

	//! Log record creation time
#ifdef _WIN32
	//! Current time.
	SYSTEMTIME m_time;
#endif

#if defined(_LINUX) || defined(_MACOSX)
	//! Current time.
	time_t m_time;
#endif

	//! Thread ID.
	unsigned m_threadId;

	//! Log record message
	std::string m_message;

    //! Log record directory
    std::string m_category;

	//! File name
	std::string m_file;

	//! Line number
	size_t m_line;

	//! Tag
	long m_tag;

    //! Is it "raw" log record?
    bool m_bRaw;

	// Set logger as friend class for easier access
	friend class CLoggerBase;

};

	
}
}

#endif // VPL_LogRecord_H

