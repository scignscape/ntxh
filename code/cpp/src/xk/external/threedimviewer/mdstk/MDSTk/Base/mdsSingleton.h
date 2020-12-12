//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/10/17                          \n
 *
 * $Id: mdsSingleton.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * This code is based on The Loki Library which accompanies
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
 * - Template definition of a singleton.
 * - The singleton has only one instance which is initialized
 *   at the first call to ::getInstance() method.
 */

#ifndef MDS_SINGLETON_H
#define MDS_SINGLETON_H

#include "mdsAssert.h"
#include "mdsLock.h"

// STL
#include <cstdlib>
#include <algorithm>
#include <list>


namespace mds
{
namespace base
{

//==============================================================================
/*
 * Global declarations.
 */

//! Default singleton longevity values.
enum ESingletonLongevity
{
    SL_DEFAULT      = 0x0000,
    SL_SHORT        = 0x0100,
    SL_MIDDLE       = 0x0200,
    SL_LONG         = 0x0400,
    SL_LIBRARY      = 0x0800,
    SL_ALLOCATOR    = 0xffff
};

//! Pointer to a void function.
typedef void (*tVoidFunction)();


//==============================================================================
/*
 * Global macros.
 */

//! Returns the singleton instance of a given class.
#define MDS_SINGLETON(T)            mds::base::CSingletonHolder<T>::getInstance()

//! Macro used to declare important singleton member which allows
//! instantiation only by CSingletonHolder. It should be located
//! in the private part of the singleton class as well as default constructor
//! and copy constructor.
#define MDS_PRIVATE_SINGLETON(T)    friend class mds::base::CSingletonHolder<T>


//==============================================================================
/*!
 * Singleton lifetime.
 */
class CSingletonLifetime
{
public:
    //! Default constructor.
    CSingletonLifetime() : m_iLongevity(SL_DEFAULT) {}

    //! Constructor.
    CSingletonLifetime(int iLongevity) : m_iLongevity(iLongevity) {}

    //! Destructor.
    virtual ~CSingletonLifetime() {}

    //! Compares the longevity.
    static bool compare(const CSingletonLifetime *lhs, const CSingletonLifetime *rhs)
    {
        return (lhs->m_iLongevity > rhs->m_iLongevity);
    }

private:
    //! Stored longevity.
    int m_iLongevity;
};


//==============================================================================
/*!
 * Concrete singleton destroyer which is used to delete a singleton instance.
 */
template <typename T>
class CSingletonDestroyer : public CSingletonLifetime
{
public:
    //! Pointer type.
    typedef T *tPointer;

public:
    //! Default constructor.
    CSingletonDestroyer(tPointer pInstance,
                        int iLongevity,
                        tVoidFunction pFunction
                        )
            : CSingletonLifetime(iLongevity)
            , m_pInstance(pInstance)
            , m_pFunction(pFunction)
    {
    }

    //! Virtual destructor.
    virtual ~CSingletonDestroyer()
    {
        m_pFunction();
    }

private:
    //! Pointer to a singleton instance.
    tPointer m_pInstance;

    //! Pointer to the singleton destruction function.
    tVoidFunction m_pFunction;
};


//==============================================================================
/*!
 * Provides singleton amenities for a type T. To protect that type from
 * spurious instantiations, you have to protect it yourself.
 */
template <typename T>
class CSingletonHolder : public CLibraryLockableClass<CSingletonHolder<T> >
{
public:
    //! Check that T is singleton. You will see name of this enum somewhere
    //! in compiler error message if the type T is not singleton.
    enum { TEMPLATE_PARAMETER_IS_NOT_SINGLETON = T::CLASS_SINGLETON };

    //! Singleton longevity.
    enum { LONGEVITY = T::LONGEVITY };

    //! Pointer type.
    typedef T *tPointer;

    //! Pointee type.
    typedef T tPointee;

    //! Lock type.
    typedef typename CLibraryLockableClass<CSingletonHolder<T> >::CLock tLock;

public:
    //! Returns reference to the singleton instance.
    static T& getInstance();

private:
    //! Pointer to the instance.
    static tPointer m_pInstance;

    //! Flag set to true if the instance has been destroyed.
    static bool m_bDestroyed;

private:
    //! Creates a new singleton instance.
    static void createInstance();

    //! Deletes the singleton instance.
    static void destroyInstance();

    //! Private constructor.
    CSingletonHolder();

    //! Private copy constructor.
    CSingletonHolder(const CSingletonHolder&);
};


//==============================================================================
/*!
 * Class from which an singleton must be derived. Private constructor
 * and private copy constructor have to be provided by that class
 * to avoid user defined singleton instances.
 */
template <int L>
class CSingleton
{
public:
    //! Templates that require members of the CSingleton class can use
    //! this enum to check the existence.
    enum { CLASS_SINGLETON };

    //! Object longevity.
    enum { LONGEVITY = L };
};


//==============================================================================
/*
 * Basic singleton instances.
 */

//! Default singleton class.
typedef CSingleton<SL_DEFAULT>    CDefaultSingleton;

//! Singleton having 'mds::SL_LIBRARY' system longevity.
typedef CSingleton<SL_LIBRARY>    CLibrarySingleton;


//=============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates.
#include "mdsSingleton.hxx"


} // namespace base
} // namespace mds

#endif // MDS_SINGLETON_H
