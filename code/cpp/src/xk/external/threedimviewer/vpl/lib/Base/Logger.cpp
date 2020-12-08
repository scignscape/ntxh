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

#include <VPL/Base/Logger.h>


unsigned long vpl::base::CLoggerBase::m_id_counter = 0;

/*!
 * \fn  vpl::base::CLoggerBase::CLoggerBase(bool bEnableTimeStamp )
 *
 * \brief   Constructor.
 *
 * \param   bEnableTimeStamp    true to enable, false to disable the time stamp.
 */

vpl::base::CLoggerBase::CLoggerBase(bool bEnableTimeStamp /*= true*/)
    : m_levelThresholdFilter(LL_TRACE)
    , m_bTimeStampEnabled(bEnableTimeStamp)
    , m_pathLength(1)
{}

/**
 * Logs.
 *
 * \param	level  	The level.
 * \param	file   	The file.
 * \param	line   	The line.
 * \param	message	The message.
 * \param	tag	   	The tag.
**/
void vpl::base::CLoggerBase::log( int level, std::string category, const std::string &file, size_t line, unsigned threadId, const std::string &message, long tag /*= 0*/, bool raw /*= false*/ )
{
	// Lock object
	tLock Lock;

	// Use level filter
	if(m_levelThresholdFilter(level) == CLogFilter::rejected)
		return;	// Level too low - do nothing

    std::string shortened_path(shortenPath(file, m_pathLength));

	// Fill record structure
	m_recordBuffer.set(level, category, shortened_path, line, threadId, message, tag, raw);
	m_recordBuffer.m_id = getId(!raw);

	// Store time stamp if should be done
	if(m_bTimeStampEnabled)
	{
#ifdef _WIN32
		GetLocalTime(&(m_recordBuffer.m_time)); 
#endif
#if defined(_LINUX) || defined(_MACOSX)
		time(&m_recordBuffer.m_time);	
#endif
	}

	// Use remaining filters
	if(filter(m_recordBuffer) == CLogFilter::rejected)
		return;
	
	// Apply appenders
	tAppenderPtrVec::iterator it(m_appenders.begin()), itEnd(m_appenders.end());
	for(; it != itEnd; ++it)
		(*it)->log(m_recordBuffer);
}

/**
 * Adds an appender. 
 *
 * \param [in,out]	appender	If non-null, the appender.
**/
vpl::base::CLogAppender *vpl::base::CLoggerBase::addAppender( CLogAppender *appender )
{
	// Lock logger
	tLock lock;

	if(appender == 0)
		return 0;

	m_appenders.push_back(appender);

    return appender;
}

/**
 * @brief   Gets an appender.
 *
 * @param   name    The name.
 *
 * @return  null if it fails, else the appender.
 */

vpl::base::CLogAppender * vpl::base::CLoggerBase::getAppender(const std::string &name)
{
    tAppenderPtrVec::iterator it(m_appenders.begin()), itEnd(m_appenders.end());
    for(; it != itEnd; ++it)
        if(name == (*it)->getName())
            return *it;

    return 0;
}


void vpl::base::CLoggerBase::setLevelThreshold(int level)
{
    m_levelThresholdFilter.setLevel(level);
}

/*!
 * \fn  std::string vpl::base::CLoggerBase::shortenPath(const std::string &path, int num_segments )
 *
 * \brief   Shortens path.
 *
 * \param   path            Full pathname of the file.
 * \param   num_segments    Number of segments - number of (back)slashes left. Negative value means do nothing.
 *
 * \return  .
 */

std::string vpl::base::CLoggerBase::shortenPath(const std::string &path, int num_segments /*= 0*/)
{
    if(num_segments < 0)
        return path;

    bool not_end(true);
    int i(0);
    size_t last_pos(path.length());
    while(not_end && i <= num_segments)
    {
        size_t pos(path.find_last_of("/\\", last_pos-1));
        if(pos == std::string::npos)
            not_end = false;

        last_pos = pos;
        ++i;
    }

    if(last_pos == std::string::npos)
        return path;

    return path.substr(last_pos+1, std::string::npos);
}


