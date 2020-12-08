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
 * - Time difference measuring.
 */

#ifndef VPL_STOPWATCH_H
#define VPL_STOPWATCH_H

#include <VPL/Base/Setup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif

// Linux version
#ifdef _LINUX
#endif // _LINUX

// Mac version
#ifdef _MACOSX
#   include <mach/mach_time.h>
#endif

#include <VPL/Base/SharedPtr.h>

#include "System.h"
#include "SystemExport.h"


namespace vpl
{
namespace sys
{

//==============================================================================
/*!
 * Class for time difference measuring.
 */
class VPL_SYSTEM_EXPORT CStopwatch : public vpl::base::CObject
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CStopwatch);

public:
    //! Default constructor.
    CStopwatch();

    //! Destructor.
    virtual ~CStopwatch();

    //! Starts the time measuring.
    void start();

    //! Elapsed time in milliseconds.
    unsigned long getDuration();

protected:
#ifdef _WIN32
    //! Time of the last CStopwatch::start() call.
    LARGE_INTEGER liStart;

    //! Frequency of the performance timer.
    LARGE_INTEGER liFrequency;
#endif

#ifdef _LINUX
    //! Time of the last CStopwatch::start() call.
    unsigned long long ulStart;

    //! Frequency of the performance timer.
    unsigned long long ulFrequency;

    //! Returns current system time in milliseconds.
    unsigned long long getCurrentTime();
#endif

#ifdef _MACOSX
    //! Time of the last CStopwatch::start() call.
    unsigned long long ulStart;
    
    //! Conversion to micro seconds.
    double dConversion;
    
    //! Returns current system time in milliseconds.
    unsigned long long getCurrentTime();
#endif

private:
    //! Private copy constructor.
    CStopwatch(const CStopwatch&);

    //! Private assignment operator.
    void operator=(const CStopwatch&);
};


//==============================================================================
/*!
 * Smart pointer to the mutex.
 */
typedef CStopwatch::tSmartPtr   CStopwatchPtr;


} // namespace sys
} // namespace vpl

#endif // VPL_STOPWATCH_H

