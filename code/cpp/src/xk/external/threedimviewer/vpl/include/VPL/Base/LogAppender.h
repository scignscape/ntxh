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

#ifndef VPL_LogAppender_H
#define VPL_LogAppender_H

#include "LogFilters.h"
#include "Lock.h"
#include "LogLayout.h"

#include <fstream>
#include <iostream>

namespace vpl
{
namespace base
{

/**
 * Log appender.
 *
 * Appender takes log record and converts it to the string format (using by layout class). Output string is appended to 
 * the log file (or something similar, see CLogIDEAppender). Every appender uses only one layout. Appender can be enabled
 * or disabled. Disabled appenders are not called by system to process records. Records can be filtered, because
 * one of the appender's base classes is filter pool (see LogFilters.h).
**/
class CLogAppender 
	: public CLogFilterPool
	, public CLockableClass<CLogAppender>
{
public:
	VPL_SHAREDPTR(CLogAppender);

	//! Lock type.
	typedef CLibraryLockableClass<CLogAppender>::CLock tLock;

public:
	//! Constructor
	CLogAppender(const std::string &name = "", bool bEnabled = true) 
        : m_bEnabled(bEnabled), m_name(name) 
        {m_layout = new CLogLayoutSimple(true, false, true);}

	//! Enable/disable appender
	void enable(bool bEnabled) {tLock lock; m_bEnabled = bEnabled;}

	//! Log record
	void log(const CLogRecord &record);

	//! Set recorded information layout
	void setLayout(CLogLayoutBase *layout);

    //! Get currently used layout
    CLogLayoutBase *getLayout() {return m_layout;}

    //! Get appender name
    const std::string &getName() {return m_name;}

protected:
	//! Internal logging function
	virtual void logInternal(const CLogRecord &record) = 0;

protected:
	//! Is appender enabled
	bool m_bEnabled;

	//! Layout
	CLogLayoutBasePtr m_layout;

    //! Appender name
    std::string m_name;

}; // class CLogAppender

typedef CLogAppender::tSmartPtr CLogAppenderPtr;

/**
 * Channel appender. 
 *
 * Converted string is written to the output stream.
**/
class COStreamAppender
	: public CLogAppender
{
public:
	VPL_SHAREDPTR(COStreamAppender);

public:
    //! Constructor
    COStreamAppender(std::ostream &stream = std::cerr, const std::string &appender_name = "") : CLogAppender(appender_name), m_stream(stream) {}

protected:
	//! Internal logging function
	virtual void logInternal(const CLogRecord &record);

protected:
	//! Output STL stream.
	std::ostream& m_stream;

	//! Protected copy constructor.
	COStreamAppender(const COStreamAppender&);

	//! Protected assignment operator.
	void operator=(const COStreamAppender&);

}; // class CChannelAppender

typedef COStreamAppender::tSmartPtr COStreamAppenderPtr;

/**
 *  File output stream appender writes output string to the file stream.
**/
class CFStreamAppender
	: public CLogAppender
{
public:
	VPL_SHAREDPTR(CFStreamAppender);

public:
	//! Constructor
	CFStreamAppender(const char *pcFileName, const std::string &appender_name = "");

	//! Constructor.
	CFStreamAppender(const std::string& ssFileName, const std::string &appender_name = "");

	//! Virtual destructor.
	virtual ~CFStreamAppender();

protected:
	//! Internal logging function
	virtual void logInternal(const CLogRecord &record);

protected:
	//! Output file stream.
	std::ofstream m_stream;

	//! Protected copy constructor.
	CFStreamAppender(const CFStreamAppender&);

	//! Protected assignment operator.
	void operator=(const CFStreamAppender&);

}; // class CFStreamAppender

typedef CFStreamAppender::tSmartPtr CFStreamAppenderPtr;

} // namespace base
} // namespace vpl

#endif // VPL_LogAppender_H
