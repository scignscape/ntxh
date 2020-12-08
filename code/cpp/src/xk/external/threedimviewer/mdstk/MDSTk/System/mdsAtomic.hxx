//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * File:    mdsAtomic.hxx                       \n
 * Section: libSystem                           \n
 * Date:    2009/03/30                          \n
 *
 * $Id: mdsAtomic.hxx 1444 2009-04-20 13:18:02Z spanel $
 *
 * Description:
 * - Atomic operations.
 */


//==============================================================================
/*
 * Windows implementation of the class CAtomic.
 */

#ifdef _WIN32

inline CAtomic::CAtomic(unsigned Value) : m_Value(Value)
{
}


inline unsigned CAtomic::set(unsigned Value)
{
    return InterlockedExchange(&m_Value, long(Value));
}


inline unsigned CAtomic::get()
{
//    MemoryBarrier();
//    return static_cast<unsigned const volatile &>(m_Value);
    return InterlockedExchangeAdd(&m_Value, 0L);
}


inline unsigned CAtomic::add(unsigned Value)
{
    return InterlockedExchangeAdd(&m_Value, long(Value));
}


inline unsigned CAtomic::sub(unsigned Value)
{
    return InterlockedExchangeAdd(&m_Value, -long(Value));
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
    return get();
}

#endif // _WIN32


//==============================================================================
/*
 * Linux implementation of the class CAtomic.
 */

#ifdef _LINUX

inline CAtomic::CAtomic(unsigned Value) : m_Value(Value)
{
}


inline unsigned CAtomic::set(unsigned Value)
{
    return __sync_lock_test_and_set(&m_Value, Value);
}


inline unsigned CAtomic::get()
{
    __sync_synchronize();
    return m_Value;
}


inline unsigned CAtomic::add(unsigned Value)
{
    return __sync_fetch_and_add(&m_Value, Value);
}


inline unsigned CAtomic::sub(unsigned Value)
{
    return __sync_fetch_and_sub(&m_Value, Value);
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

#endif // _LINUX

