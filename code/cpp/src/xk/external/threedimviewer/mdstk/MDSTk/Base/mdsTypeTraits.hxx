//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/18                          \n
 *
 * $Id: mdsTypeTraits.hxx 1707 2010-05-05 11:00:46Z spanel $
 * 
 * Description:
 * - Type specific information.
 */


//==============================================================================
/*
 * Limits for the type mds::sys::tInt8.
 */

template <>
inline mds::sys::tInt8 CTypeTraits<mds::sys::tInt8>::getMin()
{
    return mds::sys::tInt8(-0x80);              // -128
}


template <>
inline mds::sys::tInt8 CTypeTraits<mds::sys::tInt8>::getMax()
{
    return mds::sys::tInt8(0x7F);               // 127
}


template <>
inline mds::sys::tInt8 CTypeTraits<mds::sys::tInt8>::getZero()
{
    return mds::sys::tInt8(0);
}


//==============================================================================
/*
 * Limits for the type mds::sys::tUInt8.
 */

template <>
inline mds::sys::tUInt8 CTypeTraits<mds::sys::tUInt8>::getMin()
{
    return mds::sys::tUInt8(0x00);              // 0
}


template <>
inline mds::sys::tUInt8 CTypeTraits<mds::sys::tUInt8>::getMax()
{
    return mds::sys::tUInt8(0xff);              // 255
}


template <>
inline mds::sys::tUInt8 CTypeTraits<mds::sys::tUInt8>::getZero()
{
    return mds::sys::tUInt8(0);
}


//==============================================================================
/*
 * Limits for the type mds::sys::tInt16.
 */

template <>
inline mds::sys::tInt16 CTypeTraits<mds::sys::tInt16>::getMin()
{
    return mds::sys::tInt16(-0x8000);           // -32768
}


template <>
inline mds::sys::tInt16 CTypeTraits<mds::sys::tInt16>::getMax()
{
    return mds::sys::tInt16(0x7fff);            // 32767
}


template <>
inline mds::sys::tInt16 CTypeTraits<mds::sys::tInt16>::getZero()
{
    return mds::sys::tInt16(0);
}


//==============================================================================
/*
 * Limits for the type mds::sys::tUInt16.
 */

template <>
inline mds::sys::tUInt16 CTypeTraits<mds::sys::tUInt16>::getMin()
{
    return mds::sys::tUInt16(0x0000);           // 0
}


template <>
inline mds::sys::tUInt16 CTypeTraits<mds::sys::tUInt16>::getMax()
{
    return mds::sys::tUInt16(0xffff);           // 65535
}


template <>
inline mds::sys::tUInt16 CTypeTraits<mds::sys::tUInt16>::getZero()
{
    return mds::sys::tUInt16(0);
}


//==============================================================================
/*
 * Limits for the type mds::sys::tInt32.
 */

template <>
inline mds::sys::tInt32 CTypeTraits<mds::sys::tInt32>::getMin()
{
//    return mds::sys::tInt32(-0x80000000);     // -2147483648
    return (std::numeric_limits<mds::sys::tInt32>::min)();
}


template <>
inline mds::sys::tInt32 CTypeTraits<mds::sys::tInt32>::getMax()
{
    return mds::sys::tInt32(0x7fffffff);        // 2147483647
}


template <>
inline mds::sys::tInt32 CTypeTraits<mds::sys::tInt32>::getZero()
{
    return mds::sys::tInt32(0);
}


//==============================================================================
/*
 * Limits for the type mds::sys::tUInt32.
 */

template <>
inline mds::sys::tUInt32 CTypeTraits<mds::sys::tUInt32>::getMin()
{
    return mds::sys::tUInt32(0x00000000);       // 0
}


template <>
inline mds::sys::tUInt32 CTypeTraits<mds::sys::tUInt32>::getMax()
{
    return mds::sys::tUInt32(0xffffffff);       // 4294967295
}


template <>
inline mds::sys::tUInt32 CTypeTraits<mds::sys::tUInt32>::getZero()
{
    return mds::sys::tUInt32(0);
}

