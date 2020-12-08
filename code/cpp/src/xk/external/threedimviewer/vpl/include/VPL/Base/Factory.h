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
 * Date:    2005/04/03                          \n
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
 * - Template definition of an object factory.
 */

#ifndef VPL_FACTORY_H
#define VPL_FACTORY_H

#include "Assert.h"
#include "Exception.h"
#include "Lock.h"
#include "Singleton.h"

// STL
#include <map>


namespace vpl
{
namespace base
{

//=============================================================================
/*
 * Global definitions.
 */

namespace Factory
{
    //! Exception thrown in case of an error.
    VPL_DECLARE_EXCEPTION(CCannotCreate, "Failed to create a new object")
}

//! Returns instance of a given object factory
#define VPL_FACTORY(T)  vpl::base::CSingletonHolder<T>::getInstance()


//=============================================================================
/*!
 * Implements a generic object factory.
 * - Parameter T is a base object type.
 * - Template parameter I is the object identifier type.
 * - An object creation function has no parameter and returns pointer
 *   to a newly created object of type T.
 */
template <class T, typename I>
class CFactory : public CLibrarySingleton, public CLibraryLockableClass<CFactory<T,I> >
{
public:
    //! Produced object type.
    typedef T tObject;

    //! Object identifier type.
    typedef I tIdentifier;

    //! Object creation function.
    typedef tObject *(*tCreationFunction)();

    //! Lock type.
    typedef typename CLibraryLockableClass<CFactory<T,I> >::CLock tLock;

public:
    //! Destructor.
    ~CFactory() {}

    //! Registers an object creation function.
    bool registerObject(const tIdentifier& Id, tCreationFunction Function)
    {
        VPL_CHECK(Function, return false);

        tLock Lock(*this);
        return (m_Functions.insert(typename tFunctions::value_type(Id, Function)).second);
    }

    //! Unregisters the object creation function.
    bool unregisterObject(const tIdentifier& Id)
    {
        tLock Lock(*this);
        return (m_Functions.erase(Id) == 1);
    }

    //! Creates a new object having the identifier 'Id'.
    tObject *create(const tIdentifier& Id)
    {
        tLock Lock(*this);
        typename tFunctions::const_iterator i = m_Functions.find(Id);
        if( i == m_Functions.end() )
        {
            throw Factory::CCannotCreate();
        }
        return (i->second)();
    }

protected:
    //! Map of creation functions
    typedef std::map<tIdentifier, tCreationFunction> tFunctions;

    //! Map of all registered creation functions
    tFunctions m_Functions;

protected:
    //! Private constructor
    CFactory() {}

    //! Allow factory instantiation using singleton holder
    VPL_PRIVATE_SINGLETON(CFactory);
};


} // namespace base
} // namespace vpl

#endif // VPL_FACTORY_H

