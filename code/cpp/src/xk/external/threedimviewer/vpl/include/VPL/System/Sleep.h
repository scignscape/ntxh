//==============================================================================
/* This file comes from MDSTk software and was modified for
 * 
 * VPL - Voxel Processing Library
 * Changes are Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 * 
 * The original MDSTk legal notice can be found below.
 * 
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/11/01                       
 *
 * Description:
 * - Pause execution for a time specified time.
 */

#ifndef VPL_SLEEP_H
#define VPL_SLEEP_H

#include <VPL/Base/Setup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif

// Linux and Mac version
#if defined(_LINUX) || defined(_MACOSX)
#    include <unistd.h>
#    include <pthread.h>
#    include <time.h>
#    include <errno.h>
#endif

#include "System.h"
#include "SystemExport.h"


namespace vpl
{
namespace sys
{

//==============================================================================
/*!
 * Sleep for a time specified in miliseconds.
 */
VPL_SYSTEM_EXPORT void sleep(unsigned uTime);


} // namespace sys
} // namespace vpl

#endif // VPL_SLEEP_H

