//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/10/17                          \n
 *
 * $Id: mdsSharedPtr.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Smart pointer to a shared object providing intrusive reference counting.
 */

#ifndef MDS_SharedPtr_H
#define MDS_SharedPtr_H

#include "mdsAssert.h"
#include "mdsObject.h"


namespace mds
{
namespace base
{

//==============================================================================
/*
 * Global macros.
 */

//! Macro declares a class member tSmartPtr which can be later used to create
//! smart pointer to class T.
#define MDS_SHAREDPTR(T) \
    typedef mds::base::CSharedPtr<T> tSmartPtr; \
    friend class mds::base::CSharedPtr<T>


//==============================================================================
/*!
 * Smart pointer to a shared object providing intrusive reference counting.
 * Once the pointer is initialized, it takes control over the object deletion.
 */
template <typename T>
class CSharedPtr
{
public:
    //! Check that T is derived from CObject class. Otherwise, you will see
    //! name of this enum somewhere in compiler error message.
    enum { TEMPLATE_PARAMETER_IS_NOT_OBJECT = T::CLASS_OBJECT };

    //! Stored pointer type.
    typedef T *tPointer;

    //! Pointee type.
    typedef T tPointee;

public:
    //! Default constructor.
    //! - Internal pointer is initialized to the NULL.
    //! - Use with care!
//    CSharedPtr() : m_pInstance(0) {}

    //! Default constructor.
    //! - Uses default pointee type constructor.
    CSharedPtr() : m_pInstance(new T())
    {
        m_pInstance->addReference();
    }

    //! Constructor from a raw pointer.
    //! - NULL can be given.
    CSharedPtr(T *p) : m_pInstance(p)
    {
        if( m_pInstance )
        {
            m_pInstance->addReference();
        }
    }

    //! Constructor from a raw pointer.
/*    CSharedPtr(const T *p) : m_pInstance(const_cast<T *>(p))
    {
        if( m_pInstance )
        {
            m_pInstance->addReference();
        }
    }*/

    //! Copy constructor.
    //! - Makes a new reference to the object.
    CSharedPtr(const CSharedPtr& p) : m_pInstance(p.m_pInstance)
    {
        if( m_pInstance )
        {
            m_pInstance->addReference();
        }
    }

    //! Assignment operator.
    //! - Makes a new reference to the object.
    CSharedPtr& operator=(const CSharedPtr& p)
    {
        if( this != &p )
        {
            if( m_pInstance && m_pInstance->delReference() )
            {
                delete m_pInstance;
            }
            m_pInstance = p.m_pInstance;
            if( m_pInstance )
            {
                m_pInstance->addReference();
            }
        }
        return *this;
    }

    //! Assignment operator.
    //! - Makes a new reference to the object.
    CSharedPtr& operator=(T *p)
    {
        if( m_pInstance != p )
        {
            if( m_pInstance && m_pInstance->delReference() )
            {
                delete m_pInstance;
            }
            m_pInstance = p;
            if( m_pInstance )
            {
                m_pInstance->addReference();
            }
        }
        return *this;
    }

    //! Assignment operator.
    //! - Makes a new reference to the object.
/*    CSharedPtr& operator=(const T *p)
    {
        if( m_pInstance != p )
        {
            if( m_pInstance && m_pInstance->delReference() )
            {
                delete m_pInstance;
            }
            m_pInstance = const_cast<T *>(p);
            if( m_pInstance )
            {
                m_pInstance->addReference();
            }
        }
        return *this;
    }*/

    //! Destructor.
    ~CSharedPtr()
    {
        if( m_pInstance && m_pInstance->delReference() )
        {
            delete m_pInstance;
        }
    }


    //! Conversion to the raw pointer.
    operator T*() { return m_pInstance; }

    //! Added conversion to the void pointer to avoid raw pointer deletion.
    operator void*() { return m_pInstance; }


    //! Returns pointer to the encapsulated object.
    T *operator->() const { return m_pInstance; }

    //! Returns reference to the stored object.
    T& operator*() const { return *m_pInstance; }


    //! Enables "if (!sp) ...".
    bool operator!() const { return (m_pInstance == 0); }


    //! Comparision operators.
    inline friend bool operator==(const CSharedPtr& l, const T* r)
    {
        return (l.m_pInstance == r);
    }

    inline friend bool operator==(const T* l, const CSharedPtr& r)
    {
        return (r.m_pInstance == l);
    }

    inline friend bool operator!=(const CSharedPtr& l, const T* r)
    {
        return (l.m_pInstance != r);
    }

    inline friend bool operator!=(const T* l, const CSharedPtr& r)
    {
        return (r.m_pInstance != l);
    }

    inline friend bool operator<(const CSharedPtr& l, const T* r)
    {
        return (l.m_pInstance < r);
    }

    inline friend bool operator<(const T* l, const CSharedPtr& r)
    {
        return (r.m_pInstance > l);
    }

    //! Ambiquity buster that solves problem using comparision
    //! like "if( p == sp ) ...".
    template<typename U>
    inline friend bool operator==(const CSharedPtr& l, const U* r)
    {
        return (l.m_pInstance == r);
    }

    template<typename U>
    inline friend bool operator==(const U* l, const CSharedPtr& r)
    {
        return (r.m_pInstance == l);
    }

    template<typename U>
    inline friend bool operator!=(const CSharedPtr& l, const U* r)
    {
        return (l.m_pInstance != r);
    }

    template<typename U>
    inline friend bool operator!=(const U* l, const CSharedPtr& r)
    {
        return (r.m_pInstance != l);
    }

    template<typename U>
    inline friend bool operator<(const CSharedPtr& l, const U* r)
    {
        return (l.m_pInstance < r);
    }

    template<typename U>
    inline friend bool operator<(const U* l, const CSharedPtr& r)
    {
        return (r.m_pInstance > l);
    }

    //! Ambiguity buster solving the comparision of two smart pointers.
    template<typename U>
    bool operator==(const CSharedPtr<U>& r) const
    {
        return (m_pInstance == r.m_pInstance);
    }

    template<typename U>
    bool operator!=(const CSharedPtr<U>& r) const
    {
        return (m_pInstance != r.m_pInstance);
    }

    template<typename U>
    bool operator<(const CSharedPtr<U>& r) const
    {
        return (m_pInstance < r.m_pInstance);
    }


    //! Returns pointer to the encapsulated object.
    T *get() { return m_pInstance; }
    const T *get() const { return m_pInstance; }

    //! Returns pointer to the encapsulated object and decreases the reference
    //! counter. Sets the internal pointer to NULL to avoid destruction
    //! of the object.
    //! - Use with care!
    T *release()
    {
        T *pTemp = m_pInstance;
        if( m_pInstance )
        {
            m_pInstance->delReference();
            m_pInstance = 0;
        }
        return pTemp;
    }

private:
    //! Pointer to the encapsulated object.
    T *m_pInstance;
};


} // namespace base
} // namespace mds

#endif // MDS_SharedPtr_H

