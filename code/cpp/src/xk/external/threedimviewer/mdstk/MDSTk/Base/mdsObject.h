//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/11/22                          \n
 *
 * $Id: mdsObject.h 2091 2012-02-14 11:26:36Z spanel $
 *
 * Description:
 * - Implementation of an intrusive reference counting model.
 * - Derived classes can be handled using a reference counting smart pointer.
 */

#ifndef MDS_OBJECT_H
#define MDS_OBJECT_H

#include "mdsAssert.h"
#include "mdsBaseExport.h"

// Standard C++ Library
#include <new>
#include <cstddef>


namespace mds
{
namespace base
{

//==============================================================================
/*!
 * Base class providing intrusive reference counting model.
 * - It must be used as first, not virtual, base class.
 * - Mechanism used to determine if an object is on the heap is not functional
 *   when you use the operator new[] to allocate an array of objects! This may
 *   cause some memory leaks.
 */
class MDS_BASE_EXPORT CObject
{
public:
    //! Templates that require members of the CObject class can use
    //! this enum to check the existence.
    enum { CLASS_OBJECT };

    //! Signature used to recognize objects on the heap.
    enum { HEAP_OBJECT = 0x70616568 };

public:
    //! Allocates a new object on the heap.
    static void *operator new(std::size_t Size)
    {
        // Get block of correct size
        void *pBlock = ::operator new(Size);

        // Point into the object-to-be and set its heap object flag
        CObject *pObject = reinterpret_cast<CObject *>(pBlock);
        pObject->m_iHeapObject = HEAP_OBJECT;
        return pBlock;
    }

    //! Destructor.
    virtual ~CObject() { m_iHeapObject = 0; }

    //! Returns the number of references.
    int getReferencesCount() const
    {
        return m_iReferences;
    }

    //! Returns true if the object is allocated on the heap.
    bool isOnHeap() const
    {
        return (m_iHeapObject == HEAP_OBJECT);
    }

protected:
    //! Flag initialized if the object is on the heap.
    mutable int m_iHeapObject;

    //! The number of references to the object.
    //! - Zero if there is no reference.
    mutable int m_iReferences;

protected:
    //! Protected default constructor.
    //! - If the object is created statically, initialize the references counter
    //!   to one, otherwise to zero.
    CObject() : m_iReferences(isOnHeap() ? 0 : 1) {}

    //! Increase the reference counter.
    void addReference() const
    {
        ++m_iReferences;
    }

    //! Decrease the reference counter.
    //! - Returns true if the decremented number of references
    //!   is lower or equal to zero and object must be deleted.
    bool delReference() const
    {
        return ((--m_iReferences) == 0);
    }

    //! Protected copy constructor.
    CObject(const CObject&) : m_iReferences(isOnHeap() ? 0 : 1) {}

    //! Protected assignment operator.
    CObject& operator=(const CObject&) { return *this; }
};


} // namespace base
} // namespace mds

#endif // MDS_OBJECT_H

