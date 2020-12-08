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

#ifndef VPL_MinimalLogger_H
#define VPL_MinimalLogger_H

#include "BaseExport.h"
#include <string>


namespace vpl
{
namespace base
{

//==============================================================================
/*!
 * Class implementing pure and simple logging interface without including anything unneccessary.
 * This is a base class to vpl::base::CLoggerBase
 */
class VPL_BASE_EXPORT MinimalLogger
{
protected:
	//! Constructor
    MinimalLogger()
    {}

    //! Destructor
    ~MinimalLogger()
    {}

public:
	//! Log
    virtual void log(int level, std::string category, const std::string & file, size_t line, unsigned threadId, const std::string & message, long tag = 0, bool raw = false) = 0;

};


} // namespace base
} // namespace vpl

#endif  // VPL_MinimalLogger_H
