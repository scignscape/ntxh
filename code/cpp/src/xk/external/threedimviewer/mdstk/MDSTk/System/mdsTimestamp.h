//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/11/14                          \n
 *
 * $Id: mdsTimestamp.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Timestamp definition.
 */

#ifndef MDS_TIMESTAMP_H
#define MDS_TIMESTAMP_H

#include <MDSTk/Base/mdsSetup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif // _WIN32

// Linux version
#ifdef _LINUX
#    include <unistd.h>
#    include <pthread.h>
#    include <sys/types.h>
#    include <time.h>
#    include <errno.h>
#endif // _LINUX

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsSharedPtr.h>

#include "mdsSystem.h"
#include "mdsSystemExport.h"

// STL
#include <string>
#include <iostream>


namespace mds
{
namespace sys
{

//==============================================================================
/*!
 * Timestamp class representing an event time and description.
 */
class MDS_SYSTEM_EXPORT CTimestamp
{
public:
    //! Timestamp constructor.
    CTimestamp(const std::string& sDescription);

    //! Copy constructor.
    CTimestamp(const CTimestamp &Timestamp);

    //! Destructor.
    virtual ~CTimestamp() {}

    //! Returns the description.
    const std::string& getDescription() { return m_sDescription; }

    //! Writes the time into the output stream in human readable form.
    friend std::ostream& operator <<(std::ostream& Stream, const CTimestamp& Time);

protected:
#ifdef _WIN32
    //! Current time.
    SYSTEMTIME m_Time;
#endif // _WIN32

#ifdef _LINUX
    //! Current time.
    time_t m_Time;
#endif // _LINUX

    //! Timestamp description.
    std::string m_sDescription;
};


//==============================================================================
/*!
 * Macro that creates a timestamp object.
 */
#define MDS_TIMESTAMP(Desc)     mds::sys::CTimestamp(Desc)


} // namespace sys
} // namespace mds

#endif // MDS_TIMESTAMP_H

