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
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.c
 * Date:    2009/03/30                          \n
 *
 * Description:
 * - Thread control.
 */

#include <VPL/System/UserThread.h>


namespace vpl
{
namespace sys
{

//==============================================================================
/*
 * Implementation of the class vpl::sys::CUserThread.
 */

CUserThread::CUserThread(void *pData, bool bRun) : CThread(CUserThread::threadRoutine, pData, bRun)
{
}


CUserThread::~CUserThread()
{
}


VPL_THREAD_ROUTINE(CUserThread::threadRoutine)
{
    CUserThread *pUserThread = dynamic_cast<CUserThread *>(pThread);
    if( !pUserThread )
    {
        return -1;
    }

    return pUserThread->entry();
}


} // namespace sys
} // namespace vpl

