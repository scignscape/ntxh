//==============================================================================
/* This file is part of
 *
 * VPL - Voxel Processing Library
 * Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef VPL_ScopedLock_H
#define VPL_ScopedLock_H

#include <VPL/Base/Setup.h>

#include "Mutex.h"


namespace vpl
{
namespace sys
{

//==============================================================================
/*!
 * A simple mutex wrapper providing simple RAII-style mechanism for owning
 * a mutex for the duration of a scoped block. When the object is created,
 * it attempts to take ownership of the mutex it is given. 
 * When control leaves the scope in which the object was created,
 * the object is destructed and the mutex is released.
 */
template <class M>
class CScopedLock
{
public:
    //! Type of the underlying mutex.
    typedef M tMutex;

public:
    //! Default constructor takes ownership of the mutex.
    explicit CScopedLock(tMutex& Mutex) : m_Mutex(Mutex) { m_Mutex.lock(); }

    //! Destructor releases the mutex.
    //! - The behaviour is undefined when the mutex is destroyed earlier.
    ~CScopedLock() { m_Mutex.unlock(); }

private:
    //! Reference to the mutex.
    tMutex& m_Mutex;

    //! Private copy constructor.
    CScopedLock(const CScopedLock&);

    //! Private assignment operator.
    CScopedLock& operator=(const CScopedLock&);
};


//==============================================================================
/*
 * Type definitions.
 */

//! Standard lock guard based on the mutex implementation
//! from the VPL system library.
typedef CScopedLock<vpl::sys::CMutex> tScopedLock;


} // namespace sys
} // namespace vpl

#endif // VPL_ScopedLock_H
