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

#include <VPL/System/Timestamp.h>


namespace vpl
{
namespace sys
{

//==============================================================================
/*
 * Methods of the class vpl::sys::CTimestamp.
 * - Windows version.
 */

#ifdef _WIN32

CTimestamp::CTimestamp(const std::string& sDescription)
    : m_sDescription(sDescription)
{
    GetLocalTime(&m_Time);
}


CTimestamp::CTimestamp(const CTimestamp &Timestamp)
{
    m_sDescription = Timestamp.m_sDescription;
    m_Time = Timestamp.m_Time;
}


std::ostream& operator <<(std::ostream& Stream, const CTimestamp& Time)
{
    // Windows version
    Stream << '<' << Time.m_Time.wHour << 'h'
    << ':' << Time.m_Time.wMinute << 'm'
    << ':' << Time.m_Time.wSecond << 's'
    << ':' << Time.m_Time.wMilliseconds << "ms>";

    Stream << " Time: " << Time.m_sDescription << std::endl;

    return Stream;
}

#endif // _WIN32


//==============================================================================
/*
 * Methods of the class vpl::sys::CTimestamp.
 * - Linux and Mac version.
 */

#if defined(_LINUX) || defined(_MACOSX)

CTimestamp::CTimestamp(const std::string& sDescription)
    : m_sDescription(sDescription)
{
    time(&m_Time);
}


CTimestamp::CTimestamp(const CTimestamp &Timestamp)
{
    m_sDescription = Timestamp.m_sDescription;
    m_Time = Timestamp.m_Time;
}


std::ostream& operator <<(std::ostream& Stream, const CTimestamp& Time)
{
    tm ttime;
    gmtime_r(&Time.m_Time, &ttime);

    Stream << '<' << ttime.tm_hour << 'h'
    << ':' << ttime.tm_min << 'm'
    << ':' << ttime.tm_sec << "s>";

    Stream << " Time: " << Time.m_sDescription << std::endl;

    return Stream;
}

#endif // _LINUX || _MACOSX


} // namespace sys
} // namespace vpl

