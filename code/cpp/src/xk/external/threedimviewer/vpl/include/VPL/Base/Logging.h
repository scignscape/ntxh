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

#ifndef VPL_Logging_H
#define VPL_Logging_H

#include <VPL/Base/Logger.h>
#include <VPL/System/Thread.h>
#include <sstream>

//==============================================================================
/*
 * Global constants
 */

namespace vpl
{
namespace base
{
    //! Default log file extension.
	const std::string LOG_DEFAULT_EXT   = ".log";
}
}

//==============================================================================
/*
 * Logging level
 */

// Default logging level used if LOG_LEVEL is not defined
#ifdef _DEBUG
#   define DEFAULT_LL_LEVEL LL_TRACE
#else
#   define DEFAULT_LL_LEVEL LL_DEBUG
#endif

// Redefine your log level before this header file is included,
// if you want to change what log level records are
// discarded at compilation time
#ifndef VPL_LOG_LEVEL
#   define VPL_LOG_LEVEL DEFAULT_LL_LEVEL 
#endif

//==============================================================================
/*
 * Logging macros
 */

#define VPL_LOG_NEW_FULL(level, file, line, message, tag, raw) \
{ \
    std::stringstream ss; \
	ss << message; \
	VPL_GLOBAL_LOGGER.log((level), (file), (line), vpl::sys::CThread::currentId(), ss.str(), (tag), (raw)); \
}

#define VPL_LOG_NEW(level, message, tag, raw) VPL_LOG_NEW_FULL(level, __FILE__, __LINE__, message, (tag), (raw))
#define VPL_LOG_NEW_IF(condition, level, message, tag, raw) {if(condition) VPL_LOG_NEW(level, message, tag, (raw));}
#define VPL_LOG_NEW_IF_NOT(condition, level, message, tag, raw) {VPL_LOG_NEW_IF(!(condition), level, message, tag, (raw));}

#if VPL_LOG_LEVEL > LL_TRACE
#   define VPL_LOG_TRACE(message)
#   define VPL_LOG_TRACE_IF(condition, message) 
#   define VPL_LOG_TRACE_IF_NOT(condition, message)
#   define VPL_LOG_TRACE_TAG(message, tag) 
#else
#   define VPL_LOG_TRACE(message) VPL_LOG_NEW(LL_TRACE, message, 0, false);
#   define VPL_LOG_TRACE_IF(condition, message) {if(condition) VPL_LOG_TRACE(message);}
#   define VPL_LOG_TRACE_IF_NOT(condition, message) {if(!(condition)) VPL_LOG_TRACE(message);}
#   define VPL_LOG_TRACE_TAG(message, tag) VPL_LOG_NEW(LL_TRACE, message, (tag));
#endif

#if VPL_LOG_LEVEL > LL_DEBUG
#   define VPL_LOG_DEBUG(message) 
#   define VPL_LOG_DEBUG_IF(condition, message)    
#   define VPL_LOG_DEBUG_IF_NOT(condition, message)
#   define VPL_LOG_DEBUG_TAG(message, tag) 
#else
#   define VPL_LOG_DEBUG(message) VPL_LOG_NEW(LL_DEBUG, message, 0, false);
#   define VPL_LOG_DEBUG_IF(condition, message)     {if(condition)     VPL_LOG_DEBUG(message);}
#   define VPL_LOG_DEBUG_IF_NOT(condition, message) {if(!(condition))  VPL_LOG_DEBUG(message);}
#   define VPL_LOG_DEBUG_TAG(message, tag) VPL_LOG_NEW(LL_DEBUG, message, (tag));
#endif

#if VPL_LOG_LEVEL > LL_INFO
#   define VPL_LOG_INFO(message)
#   define VPL_LOG_INFO_IF(condition, message)    
#   define VPL_LOG_INFO_IF_NOT(condition, message)
#   define VPL_LOG_INFO_TAG(message, tag) 

#   define VPL_LOG_INFO_RAW(message)
#   define VPL_LOG_INFO_IF_RAW(condition, message)    
#   define VPL_LOG_INFO_IF_NOT_RAW(condition, message)
#   define VPL_LOG_INFO_TAG_RAW(message, tag) 
#else
#   define VPL_LOG_INFO(message) VPL_LOG_NEW(LL_INFO, message, 0, false);
#   define VPL_LOG_INFO_IF(condition, message)     {if(condition)     VPL_LOG_INFO(message);}
#   define VPL_LOG_INFO_IF_NOT(condition, message) {if(!(condition))  VPL_LOG_INFO(message);}
#   define VPL_LOG_INFO_TAG(message, tag) VPL_LOG_NEW(LL_INFO, message, (tag));

#   define VPL_LOG_INFO_RAW(message) VPL_LOG_NEW(LL_INFO, message, 0, true);
#   define VPL_LOG_INFO_IF_RAW(condition, message)     {if(condition)     VPL_LOG_INFO(message);}
#   define VPL_LOG_INFO_IF_NOT_RAW(condition, message) {if(!(condition))  VPL_LOG_INFO(message);}
#   define VPL_LOG_INFO_TAG_RAW(message, tag) VPL_LOG_NEW(LL_INFO, message, (tag));
#endif

#if VPL_LOG_LEVEL > LL_WARN
#   define VPL_LOG_WARN(message) 
#   define VPL_LOG_WARN_IF(condition, message)    
#   define VPL_LOG_WARN_IF_NOT(condition, message)
#   define VPL_LOG_WARN_TAG(message, tag) 

#   define VPL_LOG_WARN_RAW(message) 
#   define VPL_LOG_WARN_IF_RAW(condition, message)    
#   define VPL_LOG_WARN_IF_NOT_RAW(condition, message)
#   define VPL_LOG_WARN_TAG_RAW(message, tag) 
#else
#   define VPL_LOG_WARN(message) VPL_LOG_NEW(LL_WARN, message, 0, false);
#   define VPL_LOG_WARN_IF(condition, message)     {if(condition)     VPL_LOG_WARN(message);}
#   define VPL_LOG_WARN_IF_NOT(condition, message) {if(!(condition))  VPL_LOG_WARN(message);}
#   define VPL_LOG_WARN_TAG(message, tag) VPL_LOG_NEW(LL_WARN, message, (tag), false);

#   define VPL_LOG_WARN_RAW(message) VPL_LOG_NEW(LL_WARN, message, 0, true);
#   define VPL_LOG_WARN_IF_RAW(condition, message)     {if(condition)     VPL_LOG_WARN(message);}
#   define VPL_LOG_WARN_IF_NOT_RAW(condition, message) {if(!(condition))  VPL_LOG_WARN(message);}
#   define VPL_LOG_WARN_TAG_RAW(message, tag) VPL_LOG_NEW(LL_WARN, message, (tag), true);
#endif

#if VPL_LOG_LEVEL > LL_ERROR
#   define VPL_LOG_ERROR(message) 
#   define VPL_LOG_ERROR_IF(condition, message)    
#   define VPL_LOG_ERROR_IF_NOT(condition, message)
#   define VPL_LOG_ERROR_TAG(message, tag) 

#   define VPL_LOG_ERROR_RAW(message) 
#   define VPL_LOG_ERROR_IF_RAW(condition, message)    
#   define VPL_LOG_ERROR_IF_NOT_RAW(condition, message)
#   define VPL_LOG_ERROR_TAG_RAW(message, tag) 
#else
#   define VPL_LOG_ERROR(message) VPL_LOG_NEW(LL_ERROR, message, 0, false);
#   define VPL_LOG_ERROR_IF(condition, message)     {if(condition)     VPL_LOG_ERROR(message);}
#   define VPL_LOG_ERROR_IF_NOT(condition, message) {if(!(condition))  VPL_LOG_ERROR(message);}
#   define VPL_LOG_ERROR_TAG(message, tag) VPL_LOG_NEW(LL_ERROR, message, (tag), false);

#   define VPL_LOG_ERROR_RAW(message) VPL_LOG_NEW(LL_ERROR, message, 0, true);
#   define VPL_LOG_ERROR_IF_RAW(condition, message)     {if(condition)     VPL_LOG_ERROR(message);}
#   define VPL_LOG_ERROR_IF_NOT_RAW(condition, message) {if(!(condition))  VPL_LOG_ERROR(message);}
#   define VPL_LOG_ERROR_TAG_RAW(message, tag) VPL_LOG_NEW(LL_ERROR, message, (tag), true);
#endif

#if VPL_LOG_LEVEL > LL_FATAL
#   define VPL_LOG_FATAL(message) 
#   define VPL_LOG_FATAL_IF(condition, message)    
#   define VPL_LOG_FATAL_IF_NOT(condition, message)
#   define VPL_LOG_FATAL_TAG(message, tag) 

#   define VPL_LOG_FATAL_RAW(message) 
#   define VPL_LOG_FATAL_IF_RAW(condition, message)    
#   define VPL_LOG_FATAL_IF_NOT_RAW(condition, message)
#   define VPL_LOG_FATAL_TAG_RAW(message, tag) 
#else
#   define VPL_LOG_FATAL(message) VPL_LOG_NEW(LL_FATAL, message, 0, false);
#   define VPL_LOG_FATAL_IF(condition, message)     {if(condition)     VPL_LOG_FATAL(message);}
#   define VPL_LOG_FATAL_IF_NOT(condition, message) {if(!(condition))  VPL_LOG_FATAL(message);}
#   define VPL_LOG_FATAL_TAG(message, tag) VPL_LOG_NEW(LL_FATAL, message, (tag), false);

#   define VPL_LOG_FATAL_RAW(message) VPL_LOG_NEW(LL_FATAL, message, 0, true);
#   define VPL_LOG_FATAL_IF_RAW(condition, message)     {if(condition)     VPL_LOG_FATAL(message);}
#   define VPL_LOG_FATAL_IF_NOT_RAW(condition, message) {if(!(condition))  VPL_LOG_FATAL(message);}
#   define VPL_LOG_FATAL_TAG_RAW(message, tag) VPL_LOG_NEW(LL_FATAL, message, (tag), true);
#endif


#endif // VPL_Logging_H
