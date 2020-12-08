//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/11/01                          \n
 *
 * $Id: mdsSleep.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Pause execution for a time specified time.
 */

#ifndef MDS_SLEEP_H
#define MDS_SLEEP_H

#include <MDSTk/Base/mdsSetup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif

// Linux version
#ifdef _LINUX
#    include <unistd.h>
#    include <pthread.h>
#    include <time.h>
#    include <errno.h>
#endif

#include "mdsSystem.h"
#include "mdsSystemExport.h"


namespace mds
{
namespace sys
{

//==============================================================================
/*!
 * Sleep for a time specified in miliseconds.
 */
MDS_SYSTEM_EXPORT void sleep(unsigned uTime);


} // namespace sys
} // namespace mds

#endif // MDS_SLEEP_H

