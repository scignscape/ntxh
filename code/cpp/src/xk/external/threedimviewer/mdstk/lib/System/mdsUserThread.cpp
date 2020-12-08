//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/30                          \n
 *
 * $Id: mdsUserThread.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Thread control.
 */

#include <MDSTk/System/mdsUserThread.h>


namespace mds
{
namespace sys
{

//==============================================================================
/*
 * Implementation of the class mds::sys::CUserThread.
 */

CUserThread::CUserThread(void *pData, bool bRun) : CThread(CUserThread::threadRoutine, pData, bRun)
{
}


CUserThread::~CUserThread()
{
}


MDS_THREAD_ROUTINE(CUserThread::threadRoutine)
{
    CUserThread *pUserThread = dynamic_cast<CUserThread *>(pThread);
    if( !pUserThread )
    {
        return -1;
    }

    return pUserThread->entry();
}


} // namespace sys
} // namespace mds

