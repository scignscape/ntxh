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

#include <VPL/Base/LogIDEAppender.h>

#ifdef _MSC_VER

#include <windows.h>

//! Trace macro used to output debug information to the visual studio output window.
#define IDE_OUT_STR( s )            \
	{                             \
	OutputDebugString( s.c_str() );  \
	}
#endif

#ifdef _MACOSX

#include <asl.h>

#define IDE_OUT_STR( s ) \
{ \
    std::cerr << s; \
}
#endif

#ifdef _LINUX
#include <cstdio>

#define IDE_OUT_STR( s ) \
{ \
	std::cerr << s; \
}
#endif

#ifndef IDE_OUT_STR
#define  IDE_OUT_STR(s)
{ \
    std::cerr << s; \
}
#endif 



//! Constructor
vpl::base::CIDEAppender::CIDEAppender(const std::string & name, bool bEnabled)
    : CLogAppender(name, bEnabled)
{}

/**
 * Logs an internal.
 *
 * \param	record	The record.
**/
void vpl::base::CIDEAppender::logInternal( const CLogRecord &record )
{
	m_ss.str(std::string());
	m_ss.clear();

	m_layout->writeRecord(record, m_ss);

	IDE_OUT_STR(m_ss.str()); 
}
