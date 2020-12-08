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
 * Date:    2003/11/01                          \n
 *
 * Description:
 * - Pause execution for a time specified time.
 */

#include <VPL/System/Sleep.h>

#include <VPL/Base/Assert.h>


namespace vpl
{
namespace sys
{

//==============================================================================
/*
 * Implementation of the function vpl::sys::sleep().
 * - Windows version.
 */

#ifdef _WIN32

void sleep(unsigned uTime)
{
    ::Sleep(uTime);
}

#endif


//==============================================================================
/*
 * Implementation of the function vpl::sys::sleep().
 * - Linux and Mac version.
 */

#if defined(_LINUX) || defined(_MACOSX)

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

#endif


} // namespace sys
} // namespace vpl

