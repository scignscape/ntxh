//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/24                          \n
 *
 * $Id: mdsStopwatch.h 1864 2010-09-01 09:07:40Z spanel $
 *
 * Description:
 * - Time difference measuring.
 */

#ifndef MDS_STOPWATCH_H
#define MDS_STOPWATCH_H

#include <MDSTk/Base/mdsSetup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif // _WIN32

// Linux version
#ifdef _LINUX
#endif // _LINUX

#include <MDSTk/Base/mdsSharedPtr.h>

#include "mdsSystem.h"
#include "mdsSystemExport.h"


namespace mds
{
namespace sys
{

//==============================================================================
/*!
 * Class for time difference measuring.
 */
class MDS_SYSTEM_EXPORT CStopwatch : public mds::base::CObject
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CStopwatch);

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
#endif // _WIN32

#ifdef _LINUX
    //! Time of the last CStopwatch::start() call.
    unsigned long long ulStart;

    //! Frequency of the performance timer.
    unsigned long long ulFrequency;

    //! Returns current system time in milliseconds.
    unsigned long long getCurrentTime();
#endif // _LINUX

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
} // namespace mds

#endif // MDS_STOPWATCH_H

