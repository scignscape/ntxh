//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/14                          \n
 *
 * $Id: mdsSystemTypes.h 2049 2012-01-09 13:04:08Z spanel $
 *
 * Description:
 * - Basic types definition.
 */

#ifndef MDS_SYSTEMTYPES_H
#define MDS_SYSTEMTYPES_H

#include <MDSTk/Base/mdsSetup.h>

// Windows version
#ifdef _WIN32
#    include <stdio.h>
#endif // _WIN32

// Linux version
#ifdef _LINUX
#    include <sys/types.h>
#endif // _LINUX


namespace mds
{
namespace sys
{

//=============================================================================
/*
 * Global definitions.
 * - Windows version.
 */

#ifdef _WIN32

//! Basic system types.
typedef __int8              tInt8;
typedef unsigned __int8     tUInt8;
typedef __int16             tInt16;
typedef unsigned __int16    tUInt16;
typedef __int32             tInt32;
typedef unsigned __int32    tUInt32;
typedef __int64             tInt64;
typedef unsigned __int64    tUInt64;

#endif // _WIN32


//=============================================================================
/*
 * Global definitions.
 * - Linux version.
 */

#ifdef _LINUX

//! Basic system types.
typedef __int8_t            tInt8;
typedef __uint8_t           tUInt8;
typedef __int16_t           tInt16;
typedef __uint16_t          tUInt16;
typedef __int32_t           tInt32;
typedef __uint32_t          tUInt32;
typedef __int64_t           tInt64;
typedef __uint64_t          tUInt64;

#endif // _LINUX


} // namespace sys
} // namespace mds

#endif // MDS_SYSTEMTYPES_H

