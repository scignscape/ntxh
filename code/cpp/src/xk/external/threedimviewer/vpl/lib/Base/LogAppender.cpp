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

#include <VPL/Base/LogAppender.h>

/**
 * Logs.
 *
 * \param [in,out]	record	The record.
**/
void vpl::base::CLogAppender::log( const CLogRecord &record )
{
	if(!m_bEnabled) 
		return; 

	tLock lock; 

	if(filter(record) != CLogFilter::rejected) 
		logInternal(record);
}

/**
 * Sets a layout.
 *
 * \param [in,out]	layout	If non-null, the layout.
**/
void vpl::base::CLogAppender::setLayout( CLogLayoutBase *layout )
{
	assert(layout != 0);

	m_layout = layout;
}

/**
 * Logs an internal.
 *
 * \param [in,out]	record	The record.
**/
void vpl::base::COStreamAppender::logInternal( const CLogRecord &record )
{
	m_layout->writeRecord(record, m_stream);
}


/**
 * Constructor.
 *
 * \param	pcFileName	Filename of the file.
**/
vpl::base::CFStreamAppender::CFStreamAppender( const char *pcFileName, const std::string &appender_name /*= ""*/ )
    : CLogAppender(appender_name)
{
	m_stream.open(pcFileName);
}

/**
 * Constructor.
 *
 * \param	ssFileName	Filename of the file.
**/
vpl::base::CFStreamAppender::CFStreamAppender( const std::string& ssFileName, const std::string &appender_name /*= ""*/ )
    : CLogAppender(appender_name)
{
	m_stream.open(ssFileName.c_str(), std::ios_base::out);
}

/**
 * Destructor.
**/
vpl::base::CFStreamAppender::~CFStreamAppender()
{
	m_stream.close();
}

/**
 * Logs an internal.
 *
 * \param [in,out]	record	The record.
**/
void vpl::base::CFStreamAppender::logInternal( const CLogRecord &record )
{
	m_layout->writeRecord(record, m_stream);
}

