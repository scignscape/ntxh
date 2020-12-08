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

#ifndef VPL_LogIDEAppender_H
#define VPL_LogIDEAppender_H

#include "LogAppender.h"
#include <sstream>

namespace vpl
{
namespace base
{

//==============================================================================
/*!
 * CIDEAppender is specialized appender for writing information to the IDE.
 * On visual studio debug output window is used. Default cerr stream is used elsewhere.
 */
class CIDEAppender : public CLogAppender
{
public:
	VPL_SHAREDPTR(CIDEAppender);

public:
	//! Constructor
    CIDEAppender(const std::string & name = "", bool bEnabled = true);

protected:
	//! Internal logging function
	virtual void logInternal(const CLogRecord &record);

protected:
	//! Protected copy constructor.
	CIDEAppender(const CIDEAppender&);

	//! Protected assignment operator.
	void operator=(const CIDEAppender&);

protected:
	//! Internal stream
	std::stringstream m_ss;
};


} // namespace base
} // namespace vpl

#endif // VPL_LogIDEAppender_H
