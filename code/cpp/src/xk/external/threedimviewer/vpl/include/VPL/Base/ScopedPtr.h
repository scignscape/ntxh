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
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/10/17                          \n
 *
 * Description:
 * - Base smart pointer which transfers ownership of a handled object.
 * - Pointer ownning the object has the bDestroy flag set to true.
 */

#ifndef VPL_ScopedPtr_H
#define VPL_ScopedPtr_H

#include "Assert.h"


namespace vpl
{
namespace base
{

//==============================================================================
/*
 * Global macros.
 */

//! Macro declares a class member tSmartPtr which can be later used to create
//! smart pointer to class T.
#define VPL_SCOPEDPTR(T) \
    typedef vpl::base::CScopedPtr<T> tSmartPtr; \
    friend class vpl::base::CScopedPtr<T>


//==============================================================================
/*!
 * Base smart pointer which transfers ownership of a handled object.
 * Once the pointer is initialized, it takes control over the pointer
 * including object deletion.
 * - Pointer ownning the object has a destroy flag set to true.
 */
template <typename T>
class CScopedPtr
{
public:
    //! Stored pointer type.
    typedef T *tPointer;

    //! Pointee type.
    typedef T tPointee;

public:
    //! Default constructor.
    //! - Internal pointer is initialized to the NULL!
    //! - Use with care!
    CScopedPtr() : m_pInstance(0), m_bDestroy(false) {}

    //! Constructor from a raw pointer.
    //! - NULL can be given too.
    explicit CScopedPtr(T *p) : m_pInstance(p), m_bDestroy(true) {}

    //! Copy constructor.
    //! - Transfers ownership from one pointer to another.
    CScopedPtr(CScopedPtr& p)
        : m_pInstance(p.m_pInstance)
        , m_bDestroy(p.m_bDestroy)
    {
        p.m_bDestroy = false;
    }

    //! Assignment operator.
    //! - Transfers ownership from one pointer to another.
    CScopedPtr& operator=(CScopedPtr& p)
    {
        if( this != &p )
        {
            if( m_bDestroy )
            {
                delete m_pInstance;
            }
            m_pInstance = p.m_pInstance;
            m_bDestroy = p.m_bDestroy;
            p.m_bDestroy = false;
        }
        return *this;
    }

    //! Assignment operator
    //! - Makes a reference to the object
    CScopedPtr& operator=(T *p)
    {
        if( m_pInstance != p )
        {
            if( m_bDestroy )
            {
                delete m_pInstance;
            }
            m_pInstance = p;
            m_bDestroy = true;
        }
        return *this;
    }

    //! Destructor
    ~CScopedPtr()
    {
        if( m_bDestroy )
        {
            m_bDestroy = false;
            delete m_pInstance;
        }
    }


    //! Conversion to the raw pointer
    operator T*() { return m_pInstance; }

    //! Added conversion to the void pointer to avoid raw pointer deletion
    operator void*() { return m_pInstance; }


    //! Returns pointer to the encapsulated object
    T *operator->() const { return m_pInstance; }

    //! Returns reference to the stored object
    T& operator*() const { return *m_pInstance; }


    //! Enables "if (!sp) ..."
    bool operator!() const { return (m_pInstance == 0); }


    //! Comparision operators
    inline friend bool operator==(const CScopedPtr& l, const T* r)
    {
        return (l.m_pInstance == r);
    }

    inline friend bool operator==(const T* l, const CScopedPtr& r)
    {
        return (r.m_pInstance == l);
    }

    inline friend bool operator!=(const CScopedPtr& l, const T* r)
    {
        return (l.m_pInstance != r);
    }

    inline friend bool operator!=(const T* l, const CScopedPtr& r)
    {
        return (r.m_pInstance != l);
    }

    inline friend bool operator<(const CScopedPtr& l, const T* r)
    {
        return (l.m_pInstance < r);
    }

    inline friend bool operator<(const T* l, const CScopedPtr& r)
    {
        return (r.m_pInstance > l);
    }

    //! Ambiquity buster that solves problem using comparision
    //! like "if( p == sp ) ..."
    template <typename U>
    inline friend bool operator==(const CScopedPtr& l, const U* r)
    {
        return (l.m_pInstance == r);
    }

    template <typename U>
    inline friend bool operator==(const U* l, const CScopedPtr& r)
    {
        return (r.m_pInstance == l);
    }

    template <typename U>
    inline friend bool operator!=(const CScopedPtr& l, const U* r)
    {
        return (l.m_pInstance != r);
    }

    template <typename U>
    inline friend bool operator!=(const U* l, const CScopedPtr& r)
    {
        return (r.m_pInstance != l);
    }

    template <typename U>
    inline friend bool operator<(const CScopedPtr& l, const U* r)
    {
        return (l.m_pInstance < r);
    }

    template <typename U>
    inline friend bool operator<(const U* l, const CScopedPtr& r)
    {
        return (r.m_pInstance > l);
    }

    //! Ambiguity buster solving the comparision of two smart pointers
    template <typename U>
    bool operator==(const CScopedPtr<U>& r) const
    {
        return (m_pInstance == r.m_pInstance);
    }

    template <typename U>
    bool operator!=(const CScopedPtr<U>& r) const
    {
        return (m_pInstance != r.m_pInstance);
    }

    template <typename U>
    bool operator<(const CScopedPtr<U>& r) const
    {
        return (m_pInstance < r.m_pInstance);
    }


    //! Returns pointer to the encapsulated object.
    T *get() { return m_pInstance; }
    const T *get() const { return m_pInstance; }

    //! Returns pointer to the encapsulated object and clears the m_bDestroy flag,
    //! therefore an user must handle the object deletion on his own.
    //! - Use with care!
    T *release()
    {
        m_bDestroy = false;
        return m_pInstance;
    }

    //! Sets the m_bDestroy flag.
    //! - Use with care!
    void setDestroyFlag() { m_bDestroy = true; }

    //! Deletes the encapsulated object if required and initializes
    //! the internal pointer to NULL.
    void destroy()
    {
        if( m_bDestroy )
        {
            delete m_pInstance;
        }
        m_pInstance = 0;
    }

private:
    //! Pointer to the encapsulated object.
    tPointer m_pInstance;

    //! If set to false, the object won't be deleted
    bool m_bDestroy;
};


} // namespace base
} // namespace vpl

#endif // VPL_ScopedPtr_H

