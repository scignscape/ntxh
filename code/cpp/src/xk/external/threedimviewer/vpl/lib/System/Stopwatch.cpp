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
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.c
 * Date:    2003/10/24                          \n
 *
 * Description:
 * - Time difference measuring
 */

#include <VPL/System/Stopwatch.h>

#include <VPL/Base/Assert.h>
#include <VPL/Base/Error.h>
#include <VPL/Base/Warning.h>
#include <VPL/Base/Logging.h>


namespace vpl
{
namespace sys
{

//==============================================================================
/*
 * Implementation of the class vpl::sys::CStopwatch.
 * - Windows version.
 */

#ifdef _WIN32

CStopwatch::CStopwatch()
{
    if( !QueryPerformanceFrequency(&liFrequency) )
    {
        VPL_THROW_ERROR("Constructor CStopwatch::CStopwatch() failed");
    }

    start();
}


CStopwatch::~CStopwatch()
{
}


void CStopwatch::start()
{
    if( !QueryPerformanceCounter(&liStart) )
    {
        VPL_LOG_WARN("Method CStopwatch::start() failed");
    }
}


unsigned long CStopwatch::getDuration()
{
    LARGE_INTEGER liStopTicks;
    QueryPerformanceCounter(&liStopTicks);

    return (unsigned long)((liStopTicks.QuadPart - liStart.QuadPart) * 1000 / liFrequency.QuadPart);
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class vpl::sys::CStopwatch.
 * - Linux version.
 */

#ifdef _LINUX

CStopwatch::CStopwatch()
{
    struct timespec Time;
    if( clock_getres(CLOCK_REALTIME, &Time) != 0 )
    {
        VPL_THROW_ERROR("Constructor CStopwatch::CStopwatch() failed");
    }

    // Compute the frequency
    ulFrequency = (unsigned long long)Time.tv_nsec;

    start();
}


CStopwatch::~CStopwatch()
{
}


void CStopwatch::start()
{
    ulStart = getCurrentTime();
}


unsigned long CStopwatch::getDuration()
{
    return (unsigned long)(getCurrentTime() - ulStart);
}


unsigned long long CStopwatch::getCurrentTime()
{
    struct timespec Time;
    if( clock_gettime(CLOCK_REALTIME, &Time) != 0 )
    {
        VPL_LOG_WARN("Method CStopwatch::getCurrentTime() failed");
    }

    return (unsigned long long)(Time.tv_sec * 1000) + (unsigned long long)(Time.tv_nsec / 1000000);
}

#endif // _LINUX


//==============================================================================
/*
 * Implementation of the class vpl::sys::CStopwatch.
 * - Mac version.
 */
    
#ifdef _MACOSX
    
CStopwatch::CStopwatch()
{
    mach_timebase_info_data_t info;
    kern_return_t err = mach_timebase_info( &info );
    if( err != 0  )
    {
        VPL_THROW_ERROR("Constructor CStopwatch::CStopwatch() failed");
    }
    
    // Conversion to msec
    dConversion = 1e-6 * (double) info.numer / (double) info.denom;
    
    start();
}


CStopwatch::~CStopwatch()
{
}


void CStopwatch::start()
{
    ulStart = getCurrentTime();
}


unsigned long CStopwatch::getDuration()
{
    return (unsigned long)(getCurrentTime() - ulStart);
}


unsigned long long CStopwatch::getCurrentTime()
{
    uint64_t ntime = mach_absolute_time();
    
    return (unsigned long long)((double) ntime * dConversion);
}

#endif // _MACOSX


} // namespace sys
} // namespace vpl

