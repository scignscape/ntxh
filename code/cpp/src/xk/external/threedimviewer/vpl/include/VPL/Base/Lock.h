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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/12/13                          \n
 * 
 * Description:
 * - Object and class level locking.
 */

#ifndef VPL_LOCK_H
#define VPL_LOCK_H

#include "Setup.h"

#include <VPL/System/Mutex.h>


namespace vpl
{
namespace base
{

//==============================================================================
/*!
 * Object and class level locking.
 * This class implements a single-threaded model with no locking.
 */
template <class T>
class CNoLocking
{
public:
    //! Object of this class ensures mutual access, if created at the beginning
    //! of some method of the class T.
    class CLock
    {
    public:
        //! Default constructor. No synchronization.
        CLock() {}

        //! Constructor. No synchronization.
        CLock(T& VPL_UNUSED(Host)) {}
    };

public:
    //! Locks the object.
    static void lock() {}

    //! Locks the object.
    static void unlock() {}
};


//==============================================================================
/*!
 * Object and class level locking.
 * This class implements an object-level locking scheme.
 */
template <class T>
class CLockableObject
{
public:
    //! Object of this class ensures mutual access, if created at the beginning
    //! of some method of the class T.
    class CLock
    {
    public:
        //! Default constructor. Locks the host object.
        CLock(T& Host) : m_Host(Host) { m_Host.m_Mutex.lock(); }

        //! Destructor which unlocks the host object.
        ~CLock() { m_Host.m_Mutex.unlock(); }

    private:
        //! Host object.
        CLockableObject& m_Host;

    private:
        //! Private copy constructor.
        CLock(const CLock&);

        //! Private assignment operator.
        CLock& operator=(const CLock&);
    };

public:
    //! Locks the object.
    void lock() { m_Mutex.lock(); }

    //! Locks the object.
    void unlock() { m_Mutex.unlock(); }

private:
    //! Critical section used for locking.
    vpl::sys::CMutex m_Mutex;

    // Friend classes.
    friend class CLock;
};


//==============================================================================
/*!
 * Object and class level locking.
 * This class implements a class-level locking scheme.
 */
template <class T>
class CLockableClass
{
public:
    //! Object of this class ensures mutual access, if created at the beginning
    //! of some method of the class T.
    class CLock
    {
    public:
        //! Default constructor. Locks the host class.
        CLock() { getImpl().lock(); }

        //! Constructor. Locks the host class.
        CLock(T& VPL_UNUSED(Host)) { getImpl().lock(); }

        //! Destructor which unlocks the host class.
        ~CLock() { getImpl().unlock(); }

    private:
        //! Private copy constructor.
        CLock(const CLock&);

        //! Private assignment operator.
        CLock& operator=(const CLock&);
    };

public:
    //! Locks the object.
    static void lock() { getImpl().lock(); }

    //! Locks the object.
    static void unlock() { getImpl().unlock(); }

private:
    // TODO: Remade this provisory solution which may cause memory leaks.
    struct CDestroyer
    {
        vpl::sys::CMutex *m_pMutex;

        CDestroyer() : m_pMutex(0) {}

        ~CDestroyer()
        {
            if( m_pMutex )
            {
                delete m_pMutex;
            }
        }
    };

    struct CCreator
    {
        CCreator(CDestroyer& Impl)
        {
            Impl.m_pMutex = new vpl::sys::CMutex;
        }

        ~CCreator() {}
    };

    static CDestroyer m_Impl;

    //! Returns reference to the class-level instance of a mutex.
    static vpl::sys::CMutex& getImpl()
    {
        static CCreator CCreator(m_Impl);
        return *m_Impl.m_pMutex;
    }

/*    static CMutex& getImpl()
    {
        static CMutex m_Mutex;
        return m_Mutex;
    }*/

    // Friend classes
    friend class CLock;
};


template <class T>
typename CLockableClass<T>::CDestroyer CLockableClass<T>::m_Impl;


//==============================================================================
/*
 * Locks used by the the MDSTk library.
 */

// Singlethreaded version of the library
#ifndef VPL_MULTITHREADED

    //! Class that comes to be vpl::base::CLockableClass<T> if the
    //! multithreaded library is compiled and vpl::base::CNoLocking<T>
    //! otherwise.
    template <class T>
    struct CLibraryLockableObject : public CNoLocking<T> {};
    
    //! Class that comes to be vpl::base::CLockableClass<T> if the
    //! multithreaded library is compiled and vpl::base::CNoLocking<T>
    //! otherwise.
    template <class T>
    struct CLibraryLockableClass : public CNoLocking<T> {};

// Multithreaded version of the library
#else

    //! Class that comes to be vpl::base::CLockableClass<T> if the
    //! multithreaded library is compiled and vpl::base::CNoLocking<T>
    //! otherwise.
    template <class T>
    struct CLibraryLockableObject : public CLockableObject<T> {};
    
    //! Class that comes to be vpl::base::CLockableClass<T> if the
    //! multithreaded library is compiled and vpl::base::CNoLocking<T>
    //! otherwise.
    template <class T>
    struct CLibraryLockableClass : public CLockableClass<T> {};

#endif


} // namespace base
} // namespace vpl

#endif // VPL_LOCK_H

