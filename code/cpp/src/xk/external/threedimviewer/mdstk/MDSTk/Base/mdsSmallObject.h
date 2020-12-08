//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/12/01                          \n
 *
 * $Id: mdsSmallObject.h 1863 2010-08-31 20:40:15Z spanel $
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

#ifndef MDS_SMALLOBJECT_H
#define MDS_SMALLOBJECT_H

#include "mdsAssert.h"
#include "mdsTypes.h"
#include "mdsSingleton.h"
#include "mdsLock.h"

// STL
#include <cstddef>
#include <climits>
#include <vector>


namespace mds
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
const tSize DEFAULT_CHUNK_SIZE          = 4096;

//! Default maximal object size.
const tSize DEFAULT_MAX_OBJECT_SIZE     = 256;

//! Default object alignment.
const tSize DEFAULT_OBJECT_ALIGNMENT    = 4;

} // namespace SmallObject


//==============================================================================
/*!
 * Offers services for allocating small objects.
 */
class CSmallObjectAllocator
{
public:
    //! Constructor.
    CSmallObjectAllocator(tSize PageSize,
                          tSize MaxObjectSize,
                          tSize ObjectAlignSize
                         );

    //! Destructor.
    ~CSmallObjectAllocator();

    //! Allocates memory.
    //! - Uses an internal pool of CFixedAllocator objects.
    //! - Throws std::bad_alloc exception on failure.
    void *allocate(tSize NumBytes);

    //! Deallocates memory previously allocated with allocate().
    //! - Undefined behavior if you pass any other pointer.
    void deallocate(void *p, tSize NumBytes);

    //! Returns maximal allowed object size.
    tSize getMaxObjectSize() const { return m_MaxObjectSize; }

    //! Returns number of bytes between allocation boundaries.
    tSize getAlignment() const { return m_ObjectAlignSize; }

    //! Releases empty chunks from memory.
    bool trimExcessMemory();

private:
    //! Pool of all fixed allocators.
    CFixedAllocator *m_pPool;

    //! Maximal small object size.
    tSize m_MaxObjectSize;

    //! Object alignment.
    tSize m_ObjectAlignSize;

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
 */
template <tSize C, tSize M, tSize A>
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

        return CSingletonHolder<SMyAllocator>::getInstance().allocate(tSize(Size));
    }

    //! Allocates array-object.
    static void *operator new [](std::size_t Size)
    {
        tLock Lock;
        (void)Lock;

        return CSingletonHolder<SMyAllocator>::getInstance().allocate((tSize)Size);
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

        CSingletonHolder<SMyAllocator>::getInstance().deallocate(p, (tSize)Size);
    }

    //! Deallocates array-object.
    static void operator delete [](void *p, std::size_t Size)
    {
        tLock Lock;
        (void)Lock;

        CSingletonHolder<SMyAllocator>::getInstance().deallocate(p, (tSize)Size);
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
    CSmallObjectBase() {}

    //! Protected copy constructor.
    CSmallObjectBase(const CSmallObjectBase&) {}

    //! Protected assignment operator.
    CSmallObjectBase &operator =(const CSmallObjectBase&) { return *this; }

    //! Protected destructor.
    ~CSmallObjectBase() {}

private:
    //! Structure holding a small object allocator
    struct SMyAllocator : public CSmallObjectAllocator, public CSingleton<SL_ALLOCATOR>
    {
        //! Default constructor
        SMyAllocator() : CSmallObjectAllocator(C, M, A) {}
    };
};


//==============================================================================
/*!
 * Base class for polymorphic small objects providing fast allocations
 * and deallocations.
 */
template <tSize C = smallobj::DEFAULT_CHUNK_SIZE,
          tSize M = smallobj::DEFAULT_MAX_OBJECT_SIZE,
          tSize A = smallobj::DEFAULT_OBJECT_ALIGNMENT
          >
class CSmallObject : public CSmallObjectBase<C,M,A>
{
public:
    //! Virtual destructor.
    virtual ~CSmallObject() {}

protected:
    //! Protected default constructor.
    CSmallObject() {}

    //! Copy-constructor.
    CSmallObject(const CSmallObject&) {}

    //! Assignment operator.
    CSmallObject& operator =(const CSmallObject&) { return *this; }

};


//==============================================================================
/*!
 * Base class for small objects with value-type semantics - offers fast
 * allocations and deallocations. Destructor is non-virtual, inline,
 * and protected to prevent unintentional destruction through base class.
 * Default constructor is trivial.
 */
template <tSize C = smallobj::DEFAULT_CHUNK_SIZE,
          tSize M = smallobj::DEFAULT_MAX_OBJECT_SIZE,
          tSize A = smallobj::DEFAULT_OBJECT_ALIGNMENT
          >
class CSmallValueObject : public CSmallObjectBase<C,M,A>
{
protected:
    //! Protected default constructor.
    CSmallValueObject() {}

    //! Protected destructor.
    ~CSmallValueObject() {}

    //! Protected copy constructor.
    CSmallValueObject(const CSmallValueObject&) {}

    //! Protected assignment operator.
    CSmallValueObject& operator =(const CSmallValueObject&) { return *this; }
};


} // namespace base
} // namespace mds

#endif // MDS_SMALLOBJECT_H

