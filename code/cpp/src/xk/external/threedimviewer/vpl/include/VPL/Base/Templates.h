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
 * Modified by:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:         2004/12/13                       
 *
 * This code is inspired with The Loki Library which accompanies
 * the famous book:
 * Alexandrescu, Andrei. "Modern C++ Design: Generic Programming and Design
 *     Patterns Applied". Copyright (c) 2001. Addison-Wesley.
 *
 * The Loki Library
 * Copyright (c) 2001 by Andrei Alexandrescu
 * Permission to use, copy, modify, distribute and sell this software for any
 *     purpose is hereby granted without fee, provided that the above copyright
 *     notice appear in all copies and that both that copyright notice and this
 *     permission notice appear in supporting documentation.
 *
 * Description:
 * - Basic templates.
 */

#ifndef VPL_TEMPLATES_H
#define VPL_TEMPLATES_H

#include "Setup.h"
#include "BaseExport.h"


namespace vpl
{

//==============================================================================
/*
 * Helper types
 */

//! Used as a placeholder for "no type here".
struct tNull {};


//==============================================================================
/*!
 * Selects one of two types based upon a boolean constant.
 * Result evaluates to T if Flag is true, and to U otherwise.
 */
template <bool Flag, typename T, typename U>
struct SSelect
{
    typedef T RESULT;
};


//! Partial specialization for false 'Flag'.
template <typename T, typename U>
struct SSelect<false, T, U>
{
    typedef U RESULT;
};


//==============================================================================
/*!
 * Selects one of two integers based upon a boolean constant.
 * Result evaluates to T if Flag is true, and to U otherwise.
 */
template <bool Flag, int T, int U>
struct SSelectInt
{
    enum { RESULT = T };
};


//! Partial specialization for false 'Flag'.
template <int T, int U>
struct SSelectInt<false, T, U>
{
    enum { RESULT = U };
};


//==============================================================================
/*!
 * Checks if template parameters T and U are identical.
 */
template <typename T, typename U>
struct SCheckIdentity
{
    enum { RESULT = false };
};


//! Partial specialization.
template <typename T>
struct SCheckIdentity<T, T>
{
    enum { RESULT = true };
};


//==============================================================================
/*!
 * Converts integer value to type.
 */
template <int Value>
struct SInt2Type
{
    enum { VALUE = Value };
};


//==============================================================================
/*!
 * Checks if a given type is integer and compares the value.
 */
template <class T, int i>
struct SIsIntType
{
    enum { RESULT = false };
};

//! Partial specialization!
template <int i>
struct SIsIntType<SInt2Type<i>, i>
{
    enum { RESULT = true };
};


//==============================================================================
/*!
 * Checks if a given type is not integer.
 */
template <class T, int i>
struct SNotIntType
{
    enum { RESULT = !SIsIntType<T, i>::RESULT };
};


//==============================================================================
/*!
 * Checks convertibility of T type to U type.
 */
template <class T, class U>
class SIsConversion
{
protected:
   typedef char tSmall;
   class tBig { char m_Dummy[2]; };

   static tSmall test(U);
   static tBig test(...);
   static T makeT();

public:
   enum { RESULT = sizeof(test(makeT())) == sizeof(tSmall) };
};


//==============================================================================
/*!
 * Checks if T class is derived from U class.
 */
template <class T, class U>
struct SIsDerived
{
    enum { RESULT = SIsConversion<const T*, const U*>::RESULT && !SCheckIdentity<const U*, const void*>::RESULT };
};


} // namespace vpl

#endif // VPL_TEMPLATES_H

