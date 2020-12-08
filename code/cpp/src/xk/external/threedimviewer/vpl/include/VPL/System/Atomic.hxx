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
 * Copyright (c) 2003-2009 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/30                       
 */


//==============================================================================
/*
 * Windows implementation of the class CAtomic.
 */

#ifdef _WIN32

inline CAtomic::CAtomic(unsigned Value) : m_Value(Value)
{
}


inline unsigned CAtomic::exchange(unsigned Value)
{
    return InterlockedExchange(&m_Value, long(Value));
}


inline unsigned CAtomic::load()
{
    return InterlockedExchangeAdd(&m_Value, 0L);
}


inline unsigned CAtomic::fetchAdd(unsigned Value)
{
    return InterlockedExchangeAdd(&m_Value, long(Value));
}


inline unsigned CAtomic::fetchSub(unsigned Value)
{
    return InterlockedExchangeAdd(&m_Value, -long(Value));
}


inline void CAtomic::operator =(unsigned Value)
{
    InterlockedExchange(&m_Value, long(Value));
}


inline unsigned CAtomic::operator ++()
{
    return InterlockedIncrement(&m_Value);
}


inline unsigned CAtomic::operator --()
{
    return InterlockedDecrement(&m_Value);
}


inline CAtomic::operator unsigned()
{
    return load();
}

#endif // _WIN32


//==============================================================================
/*
 * Linux and Mac implementation of the class CAtomic.
 */

#if defined(_LINUX) || defined(_MACOSX)

inline CAtomic::CAtomic(unsigned Value) : m_Value(Value)
{
}


inline unsigned CAtomic::exchange(unsigned Value)
{
    return __sync_lock_test_and_set(&m_Value, Value);
}


inline unsigned CAtomic::load()
{
    __sync_synchronize();
    return m_Value;
}


inline unsigned CAtomic::fetchAdd(unsigned Value)
{
    return __sync_fetch_and_add(&m_Value, Value);
}


inline unsigned CAtomic::fetchSub(unsigned Value)
{
    return __sync_fetch_and_sub(&m_Value, Value);
}


inline void CAtomic::operator =(unsigned Value)
{
    __sync_lock_test_and_set(&m_Value, Value);
}


inline unsigned CAtomic::operator ++()
{
    return __sync_add_and_fetch(&m_Value, 1);
}


inline unsigned CAtomic::operator --()
{
    return __sync_sub_and_fetch(&m_Value, 1);
}


inline CAtomic::operator unsigned()
{
    __sync_synchronize();
    return m_Value;
}

#endif // _LINUX || _MACOSX

