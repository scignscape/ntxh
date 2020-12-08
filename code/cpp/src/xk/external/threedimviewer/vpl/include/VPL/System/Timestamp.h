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
 * Date:    2003/11/14                          \n
 *
 * Description:
 * - Timestamp definition.
 */

#ifndef VPL_TIMESTAMP_H
#define VPL_TIMESTAMP_H

#include <VPL/Base/Setup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif

// Linux and Mac version
#if defined(_LINUX) || defined(_MACOSX)
#    include <unistd.h>
#    include <pthread.h>
#    include <sys/types.h>
#    include <time.h>
#    include <errno.h>
#endif

#include <VPL/Base/Assert.h>
#include <VPL/Base/SharedPtr.h>

#include "System.h"
#include "SystemExport.h"

// STL
#include <string>
#include <iostream>


namespace vpl
{
namespace sys
{

//==============================================================================
/*!
 * Timestamp class representing an event time and description.
 */
class VPL_SYSTEM_EXPORT CTimestamp
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
#endif

#if defined(_LINUX) || defined(_MACOSX)
    //! Current time.
    time_t m_Time;
#endif

    //! Timestamp description.
    std::string m_sDescription;
};


//==============================================================================
/*!
 * Macro that creates a timestamp object.
 */
#define VPL_TIMESTAMP(Desc)     vpl::sys::CTimestamp(Desc)


} // namespace sys
} // namespace vpl

#endif // VPL_TIMESTAMP_H

