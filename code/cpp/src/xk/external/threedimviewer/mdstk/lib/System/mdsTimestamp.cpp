//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/11/14                          \n
 *
 * $Id: mdsTimestamp.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Timestamp definition.
 */

#include <MDSTk/System/mdsTimestamp.h>


namespace mds
{
namespace sys
{

//==============================================================================
/*
 * Methods of the class mds::sys::CTimestamp.
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
 * Methods of the class mds::sys::CTimestamp.
 * - Linux version.
 */

#ifdef _LINUX

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

#endif // _LINUX


} // namespace sys
} // namespace mds

