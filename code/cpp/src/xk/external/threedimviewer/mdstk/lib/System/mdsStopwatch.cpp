//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/24                          \n
 *
 * $Id: mdsStopwatch.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Time difference measuring
 */

#include <MDSTk/System/mdsStopwatch.h>

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsError.h>
#include <MDSTk/Base/mdsWarning.h>
#include <MDSTk/Base/mdsGlobalLog.h>


namespace mds
{
namespace sys
{

//==============================================================================
/*
 * Implementation of the class mds::sys::CStopwatch.
 * - Windows version.
 */

#ifdef _WIN32

CStopwatch::CStopwatch()
{
    if( !QueryPerformanceFrequency(&liFrequency) )
    {
        MDS_THROW_ERROR("Constructor CStopwatch::CStopwatch() failed");
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
        MDS_LOG_WARNING("Method CStopwatch::start() failed");
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
 * Implementation of the class mds::sys::CStopwatch.
 * - Linux version.
 */

#ifdef _LINUX

CStopwatch::CStopwatch()
{
    struct timespec Time;
    if( clock_getres(CLOCK_REALTIME, &Time) != 0 )
    {
        MDS_THROW_ERROR("Constructor CStopwatch::CStopwatch() failed");
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
        MDS_LOG_WARNING("Method CStopwatch::getCurrentTime() failed");
    }

    return (unsigned long long)(Time.tv_sec * 1000) + (unsigned long long)(Time.tv_nsec / 1000000);
}

#endif // _LINUX


} // namespace sys
} // namespace mds

