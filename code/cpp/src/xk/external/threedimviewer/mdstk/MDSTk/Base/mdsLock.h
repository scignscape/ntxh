//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * File:    mdsLock.h                           \n
 * Section: libBase                             \n
 * Date:    2004/12/13                          \n
 *
 * $Id: mdsLock.h 2091 2012-02-14 11:26:36Z spanel $
 * 
 * Description:
 * - Object and class level locking.
 */

#ifndef MDS_LOCK_H
#define MDS_LOCK_H

#include "mdsSetup.h"

#include <MDSTk/System/mdsCriticalSection.h>


namespace mds
{
namespace base
{

//==============================================================================
/*!
 * A single-threaded model with no locking.
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
        CLock(T& MDS_UNUSED(Host)) {}
    };

public:
    //! Locks the object.
    static void lock() {}

    //! Locks the object.
    static void unlock() {}
};


//==============================================================================
/*!
 * Implements a object-level locking scheme.
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
        CLock(T& Host) : m_Host(Host) { m_Host.m_CritSec.enter(); }

        //! Destructor which unlocks the host object.
        ~CLock() { m_Host.m_CritSec.leave(); }

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
    void lock() { m_CritSec.enter(); }

    //! Locks the object.
    void unlock() { m_CritSec.leave(); }

private:
    //! Critical section used for locking.
    mds::sys::CCriticalSection m_CritSec;

    // Friend classes.
    friend class CLock;
};


//==============================================================================
/*!
 * Implements a class-level locking scheme.
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
        CLock() { getImpl().enter(); }

        //! Constructor. Locks the host class.
        CLock(T& MDS_UNUSED(Host))
        {
            getImpl().enter();
        }

        //! Destructor which unlocks the host class.
        ~CLock() { getImpl().leave(); }

    private:
        //! Private copy constructor.
        CLock(const CLock&);

        //! Private assignment operator.
        CLock& operator=(const CLock&);
    };

public:
    //! Locks the object.
    static void lock() { getImpl().enter(); }

    //! Locks the object.
    static void unlock() { getImpl().leave(); }

private:
    // TODO: Remade this provisory solution which may cause memory leaks.
    struct CDestroyer
    {
        mds::sys::CCriticalSection *m_pCritSec;

        CDestroyer() {}

        ~CDestroyer()
        {
            delete m_pCritSec;
        }
    };

    static CDestroyer m_Impl;

    struct CCreator
    {
        CCreator(CDestroyer& Impl)
        {
            Impl.m_pCritSec = new mds::sys::CCriticalSection;
        }

        ~CCreator() {}
    };

    static mds::sys::CCriticalSection& getImpl()
    {
        static CCreator CCreator(m_Impl);
        return *m_Impl.m_pCritSec;
    }

    //! Returns reference to the critical section.
/*  static CCriticalSection& getImpl()
    {
        static CCriticalSection m_CritSec;
        return m_CritSec;
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
#ifndef MDS_MULTITHREADED

    //! Class that comes to be mds::base::CLockableClass<T> if the
    //! multithreaded library is compiled and mds::base::CNoLocking<T>
    //! otherwise.
    template <class T>
    struct CLibraryLockableObject : public CNoLocking<T> {};
    
    //! Class that comes to be mds::base::CLockableClass<T> if the
    //! multithreaded library is compiled and mds::base::CNoLocking<T>
    //! otherwise.
    template <class T>
    struct CLibraryLockableClass : public CNoLocking<T> {};

// Multithreaded version of the library
#else

    //! Class that comes to be mds::base::CLockableClass<T> if the
    //! multithreaded library is compiled and mds::base::CNoLocking<T>
    //! otherwise.
    template <class T>
    struct CLibraryLockableObject : public CLockableObject<T> {};
    
    //! Class that comes to be mds::base::CLockableClass<T> if the
    //! multithreaded library is compiled and mds::base::CNoLocking<T>
    //! otherwise.
    template <class T>
    struct CLibraryLockableClass : public CLockableClass<T> {};

#endif


} // namespace base
} // namespace mds

#endif // MDS_LOCK_H

