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

#include <VPL/Base/LogRecord.h>

/**
 * Default constructor.
**/
vpl::base::CLogRecord::CLogRecord()
	: m_id(0)
	, m_level(0)
	, m_time()
	, m_threadId(0)
	, m_message("")
    , m_category("")
	, m_file("")
	, m_line(0)
	, m_tag(-1)
    , m_bRaw(false)
{

}

/**
 * Constructor.
 *
 * \param	level  	The level.
 * \param	file   	The file.
 * \param	line   	The line.
 * \param	message	The message.
 * \param	tag	   	The tag.
**/
vpl::base::CLogRecord::CLogRecord(int level, const std::string & file, size_t line, unsigned threadId, const std::string & message, long tag /*= 0*/, bool raw /*= false*/)
    : m_id(0l)
    , m_level(level)
    , m_time()
    , m_threadId(threadId)
    , m_message(message)
    , m_category("")
	, m_file(file)
	, m_line(line)
	, m_tag(tag)
    , m_bRaw(raw)
{

}

/**
 * Constructor.
 *
 * \param	level  	The level.
 * \param	file   	The file.
 * \param	line   	The line.
 * \param	message	The message.
 * \param	tag	   	The tag.
**/
vpl::base::CLogRecord::CLogRecord(int level, std::string category, const std::string &file, size_t line, unsigned threadId, const std::string &message, long tag /*= 0*/, bool raw /*= false*/)
	: m_id(0l)
	, m_level(level)
	, m_time()
	, m_threadId(threadId)
	, m_message(message)
    , m_category(category)
	, m_file(file)
	, m_line(line)
	, m_tag(tag)
    , m_bRaw(raw)
{

}

vpl::base::CLogRecord::CLogRecord( const CLogRecord &rec )
	: m_id(rec.m_id)
	, m_level(rec.m_level)
	, m_time(rec.m_time)
	, m_message(rec.m_message)
    , m_category(rec.m_category)
	, m_file(rec.m_file)
	, m_line(rec.m_line)
	, m_tag(rec.m_tag)
    , m_bRaw(rec.m_bRaw)
{
	
}

void vpl::base::CLogRecord::set( int level, const std::string &file, size_t line, unsigned threadId, const std::string &message, long tag /*= 0*/, bool raw /*= false*/ )
{
	m_level = level;
	m_file = file;
	m_line = line;
	m_threadId = threadId;
	m_message = message;
	m_tag = tag;
    m_bRaw = raw;
}

void vpl::base::CLogRecord::set( int level, std::string category, const std::string &file, size_t line, unsigned threadId, const std::string &message, long tag /*= 0*/, bool raw /*= false*/ )
{
	m_level = level;
	m_file = file;
	m_line = line;
	m_threadId = threadId;
	m_message = message;
    m_category = category;
	m_tag = tag;
    m_bRaw = raw;
}

/**
 * Gets a time.
 *
 * \param [in,out]	year	The year.
 * \param	month			The month.
 * \param	dayOfWeek   	The day of week.
 * \param	day				The day.
 * \param	hour			The hour.
 * \param	minute			The minute.
 * \param	second			The second.
 * \param	milliseconds	The milliseconds.
**/
void vpl::base::CLogRecord::getTime( unsigned int &year, unsigned int &month, unsigned int &dayOfWeek, unsigned int &day, unsigned int &hour, unsigned int &minute ,unsigned int &second, unsigned int &milliseconds ) const
{
#ifdef _WIN32
	year = m_time.wYear;
	month = m_time.wMonth;
	dayOfWeek = m_time.wDayOfWeek;
	day = m_time.wDay;
	hour = m_time.wHour;
	minute = m_time.wMinute;
	second = m_time.wSecond;
	milliseconds = m_time.wMilliseconds;
#endif
#if defined(_LINUX) || defined(_MACOSX)
    tm *ttime;
    ttime = localtime(&m_time);
	second = ttime->tm_sec;         /* seconds */
	minute = ttime->tm_min;         /* minutes */
	hour = ttime->tm_hour;        /* hours */
	day = ttime->tm_mday;        /* day of the month */
	month = 1+ttime->tm_mon;         /* month is in format 0-11 so add 1 */
	year = 1900+ttime->tm_year;        /* year is years past from 1900*/
	dayOfWeek = ttime->tm_wday;        /* day of the week */
	milliseconds = 0;	// Not in the tm structure
#endif
}

