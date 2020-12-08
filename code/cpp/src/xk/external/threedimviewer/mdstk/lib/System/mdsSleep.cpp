//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/11/01                          \n
 *
 * $Id: mdsSleep.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Pause execution for a time specified time.
 */

#include <MDSTk/System/mdsSleep.h>

#include <MDSTk/Base/mdsAssert.h>


namespace mds
{
namespace sys
{

//==============================================================================
/*
 * Implementation of the function mds::sys::sleep().
 * - Windows version.
 */

#ifdef _WIN32

void sleep(unsigned uTime)
{
    ::Sleep(uTime);
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the function mds::sys::sleep().
 * - Linux version.
 */

#ifdef _LINUX

void sleep(unsigned uTime)
{
    // nanosleep()
    timespec Req, Rem;
    Req.tv_sec = uTime / 1000;
    Req.tv_nsec = (uTime % 1000) * 1000000;
    int iResult = nanosleep(&Req, &Rem);
    while( iResult == -1 && errno == EINTR )
    {
        Req.tv_sec = Rem.tv_sec;
        Req.tv_nsec = Rem.tv_nsec;
        nanosleep(&Req, &Rem);
    }
}

#endif // _LINUX


} // namespace sys
} // namespace mds

