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
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/18                       
 * 
 * Description:
 * - Type specific information.
 */


//==============================================================================
/*
 * Limits for the type vpl::sys::tInt8.
 */

template <>
inline vpl::sys::tInt8 CTypeTraits<vpl::sys::tInt8>::getMin()
{
    return vpl::sys::tInt8(-0x80);              // -128
}


template <>
inline vpl::sys::tInt8 CTypeTraits<vpl::sys::tInt8>::getMax()
{
    return vpl::sys::tInt8(0x7F);               // 127
}


template <>
inline vpl::sys::tInt8 CTypeTraits<vpl::sys::tInt8>::getZero()
{
    return vpl::sys::tInt8(0);
}


//==============================================================================
/*
 * Limits for the type vpl::sys::tUInt8.
 */

template <>
inline vpl::sys::tUInt8 CTypeTraits<vpl::sys::tUInt8>::getMin()
{
    return vpl::sys::tUInt8(0x00);              // 0
}


template <>
inline vpl::sys::tUInt8 CTypeTraits<vpl::sys::tUInt8>::getMax()
{
    return vpl::sys::tUInt8(0xff);              // 255
}


template <>
inline vpl::sys::tUInt8 CTypeTraits<vpl::sys::tUInt8>::getZero()
{
    return vpl::sys::tUInt8(0);
}


//==============================================================================
/*
 * Limits for the type vpl::sys::tInt16.
 */

template <>
inline vpl::sys::tInt16 CTypeTraits<vpl::sys::tInt16>::getMin()
{
    return vpl::sys::tInt16(-0x8000);           // -32768
}


template <>
inline vpl::sys::tInt16 CTypeTraits<vpl::sys::tInt16>::getMax()
{
    return vpl::sys::tInt16(0x7fff);            // 32767
}


template <>
inline vpl::sys::tInt16 CTypeTraits<vpl::sys::tInt16>::getZero()
{
    return vpl::sys::tInt16(0);
}


//==============================================================================
/*
 * Limits for the type vpl::sys::tUInt16.
 */

template <>
inline vpl::sys::tUInt16 CTypeTraits<vpl::sys::tUInt16>::getMin()
{
    return vpl::sys::tUInt16(0x0000);           // 0
}


template <>
inline vpl::sys::tUInt16 CTypeTraits<vpl::sys::tUInt16>::getMax()
{
    return vpl::sys::tUInt16(0xffff);           // 65535
}


template <>
inline vpl::sys::tUInt16 CTypeTraits<vpl::sys::tUInt16>::getZero()
{
    return vpl::sys::tUInt16(0);
}


//==============================================================================
/*
 * Limits for the type vpl::sys::tInt32.
 */

template <>
inline vpl::sys::tInt32 CTypeTraits<vpl::sys::tInt32>::getMin()
{
//    return vpl::sys::tInt32(-0x80000000);     // -2147483648
    return (std::numeric_limits<vpl::sys::tInt32>::min)();
}


template <>
inline vpl::sys::tInt32 CTypeTraits<vpl::sys::tInt32>::getMax()
{
    return vpl::sys::tInt32(0x7fffffff);        // 2147483647
}


template <>
inline vpl::sys::tInt32 CTypeTraits<vpl::sys::tInt32>::getZero()
{
    return vpl::sys::tInt32(0);
}


//==============================================================================
/*
 * Limits for the type vpl::sys::tUInt32.
 */

template <>
inline vpl::sys::tUInt32 CTypeTraits<vpl::sys::tUInt32>::getMin()
{
    return vpl::sys::tUInt32(0x00000000);       // 0
}


template <>
inline vpl::sys::tUInt32 CTypeTraits<vpl::sys::tUInt32>::getMax()
{
    return vpl::sys::tUInt32(0xffffffff);       // 4294967295
}


template <>
inline vpl::sys::tUInt32 CTypeTraits<vpl::sys::tUInt32>::getZero()
{
    return vpl::sys::tUInt32(0);
}

