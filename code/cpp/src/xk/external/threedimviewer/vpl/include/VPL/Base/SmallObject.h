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
 * Date:    2004/12/01                          \n
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
 * - Small object allocator providing fast allocations and deallocations.
 */

#ifndef VPL_SMALLOBJECT_H
#define VPL_SMALLOBJECT_H

#include "Assert.h"
#include "Types.h"
#include "Singleton.h"
#include "Lock.h"

// STL
#include <cstddef>
#include <climits>
#include <vector>
#include <new>


namespace vpl
{
namespace base
{

//==============================================================================
/*
 * Classes declarations.
 */

//! Offers services for allocating fixed-sized objects.
class CFixedAllocator;


//==============================================================================
/*
 * Global constants.
 */

//! Namespace containing constants used by the small objects allocator.
namespace smallobj
{
    //! Default chunk/page size.
    const std::size_t DEFAULT_CHUNK_SIZE          = 4096;

    //! Default maximal object size.
    const std::size_t DEFAULT_MAX_OBJECT_SIZE     = 256;

    //! Default object alignment.
    const std::size_t DEFAULT_OBJECT_ALIGNMENT    = 8;

} // namespace SmallObject


//==============================================================================
/*!
 * Offers services for allocating small objects.
 */
class CSmallObjectAllocator
{
public:
    //! Constructor.
    CSmallObjectAllocator(std::size_t PageSize,
                          std::size_t MaxObjectSize,
                          std::size_t ObjectAlignSize
                          );

    //! Destructor.
    ~CSmallObjectAllocator();

    //! Allocates memory.
    //! - Uses an internal pool of CFixedAllocator objects.
    //! - Throws std::bad_alloc exception on failure.
    void *allocate(std::size_t NumBytes);

    //! Deallocates memory previously allocated with allocate().
    //! - Undefined behavior if you pass any other pointer.
    //! - This never throws.
    void deallocate(void *p, std::size_t NumBytes);

    //! Returns maximal allowed object size.
    std::size_t getMaxObjectSize() const { return m_MaxObjectSize; }

    //! Returns number of bytes between allocation boundaries.
    std::size_t getAlignment() const { return m_ObjectAlignSize; }

    //! Releases empty chunks from memory.
    bool trimExcessMemory();

private:
    //! Pool of all fixed allocators.
    CFixedAllocator *m_pPool;

    //! Maximal small object size.
    std::size_t m_MaxObjectSize;

    //! Object alignment.
    std::size_t m_ObjectAlignSize;

private:
    //! Default constructor is not implemented.
    CSmallObjectAllocator();

    //! Private copy constructor.
    CSmallObjectAllocator(const CSmallObjectAllocator&);

    //! Private assignment operator.
    void operator=(const CSmallObjectAllocator&);
};


//==============================================================================
/*!
 * Base class for small object allocation classes. The shared implementation
 * of the new and delete operators are here instead of being duplicated in both
 * CSmallObject or CSmallValueObject. This class is not meant to be used
 * directly by clients, or derived from by clients.
 * - Parameter C is the chunk size.
 * - Parameter M is the maximum small object size.
 * - Parameter A is the object allocator alignment.
 */
template <std::size_t C, std::size_t M, std::size_t A>
class CSmallObjectBase : public CLibraryLockableClass<CSmallObjectBase<C,M,A> >
{
public:
    //! Lock type
    typedef typename CLibraryLockableClass<CSmallObjectBase<C,M,A> >::CLock tLock;

public:
    //! Allocates a small object.
    static void *operator new(std::size_t Size)
    {
        tLock Lock;
        (void)Lock;

        return CSingletonHolder<SMyAllocator>::getInstance().allocate(std::size_t(Size));
    }

    //! Allocates array-object.
    static void *operator new [](std::size_t Size)
    {
        tLock Lock;
        (void)Lock;

        return CSingletonHolder<SMyAllocator>::getInstance().allocate((std::size_t)Size);
    }

    //! Placement single-object new merely calls global placement new.
    static void *operator new(std::size_t Size, void *pPlace)
    {
        return ::operator new(Size, pPlace);
    }

    //! Placement array-object new merely calls global placement new.
    static void *operator new [](std::size_t Size, void *pPlace)
    {
        return ::operator new(Size, pPlace);
    }

    //! Deallocates small object.
    static void operator delete(void *p, std::size_t Size)
    {
        tLock Lock;
        (void)Lock;

        CSingletonHolder<SMyAllocator>::getInstance().deallocate(p, (std::size_t)Size);
    }

    //! Deallocates array-object.
    static void operator delete [](void *p, std::size_t Size)
    {
        tLock Lock;
        (void)Lock;

        CSingletonHolder<SMyAllocator>::getInstance().deallocate(p, (std::size_t)Size);
    }

    //! Placement single-object delete merely calls global placement delete.
    static void operator delete(void *p, void *pPlace)
    {
        ::operator delete(p, pPlace);
    }

    //! Placement array-object delete merely calls global placement delete.
    static void operator delete [](void *p, void *pPlace)
    {
        ::operator delete(p, pPlace);
    }

protected:
    //! Protected default constructor.
    inline CSmallObjectBase() {}

    //! Protected copy constructor.
    inline CSmallObjectBase(const CSmallObjectBase&) {}

    //! Protected assignment operator.
    inline CSmallObjectBase &operator =(const CSmallObjectBase&) { return *this; }

    //! Protected destructor.
    inline ~CSmallObjectBase() {}

private:
    //! Structure holding a small object allocator
    struct SMyAllocator : public CSmallObjectAllocator, public CSingleton<SL_ALLOCATOR>
    {
        //! Default constructor
        inline SMyAllocator() : CSmallObjectAllocator(C, M, A) {}
    };
};


//==============================================================================
/*!
 * Base class for polymorphic small objects providing fast allocations
 * and deallocations.
 * Copy-constructor and copy-assignment operator are not implemented
 * since polymorphic classes almost always disable those operations.
 */
template <std::size_t C = smallobj::DEFAULT_CHUNK_SIZE,
          std::size_t M = smallobj::DEFAULT_MAX_OBJECT_SIZE,
          std::size_t A = smallobj::DEFAULT_OBJECT_ALIGNMENT
          >
class CSmallObject : public CSmallObjectBase<C,M,A>
{
public:
    //! Virtual destructor.
    virtual ~CSmallObject() {}

protected:
    //! Protected default constructor.
    inline CSmallObject() {}

private:
    //! Copy-constructor is not implemented.
    CSmallObject(const CSmallObject&);

    //! Assignment operator is not implemented.
    CSmallObject& operator =(const CSmallObject&);
};


//==============================================================================
/*!
 * Base class for small objects with value-type semantics - offers fast
 * allocations and deallocations.
 * Destructor is non-virtual, inline, and protected to prevent unintentional
 * destruction through base class. Default constructor is trivial.
 */
template <std::size_t C = smallobj::DEFAULT_CHUNK_SIZE,
          std::size_t M = smallobj::DEFAULT_MAX_OBJECT_SIZE,
          std::size_t A = smallobj::DEFAULT_OBJECT_ALIGNMENT
          >
class CSmallValueObject : public CSmallObjectBase<C,M,A>
{
protected:
    //! Protected default constructor.
    inline CSmallValueObject() {}

    //! Protected destructor.
    inline ~CSmallValueObject() {}

    //! Protected copy constructor.
    inline CSmallValueObject(const CSmallValueObject&) {}

    //! Protected assignment operator.
    inline CSmallValueObject& operator =(const CSmallValueObject&) { return *this; }
};


} // namespace base
} // namespace vpl

#endif // VPL_SMALLOBJECT_H

