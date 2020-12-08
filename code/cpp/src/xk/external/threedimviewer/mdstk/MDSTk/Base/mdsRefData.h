//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/11/22                          \n
 *
 * $Id: mdsRefData.h 2065 2012-02-02 23:29:38Z spanel $
 *
 * Description:
 * - Class template managing references to 1D data array.
 * - Functions malloc() and free() are used internally.
 * - Provides own data reference counting mechanism.
 */

#ifndef MDS_RefData_H
#define MDS_RefData_H

#include "mdsData.h"


namespace mds
{

//==============================================================================
/*
 * Global constants.
 */

//! Enumeration constant used for making reference to data. It is usually
//! the last parameter of a constructor. So, there are two constructor
//! types. First is used to make a new copy of an object,
//! second to make a new reference.
enum EMakeRef
{
    REFERENCE
};


namespace base
{

//==============================================================================
/*!
 * Class template managing references to a block of memory.
 * - Functions malloc() and free() are used internally.
 * - Provides own data reference counting mechanism.
 */
template <typename T>
class CRefData : public CDataAllocator<T>
{
public:
    // Base types
    typedef CDataAllocator<T> base;
    typedef typename base::tData tData;
    typedef typename base::tDataPtr tDataPtr;
    typedef typename base::tConstData tConstData;
    typedef typename base::tConstDataPtr tConstDataPtr;

public:
    //! Default constructor allocates data of zero length.
    inline CRefData();

    //! This constructor does no allocation of the data.
    //! - Be sure that one of the methods create(...) is called somewhere.
    //! - Use with care!
    inline explicit CRefData(EEmptyConst);

    //! Constructor that allocates a given size of data.
    //! - Data of the zero size can be allocated.
    inline explicit CRefData(tSize Size);

    //! Constructor that copies a specified data.
    inline CRefData(tConstDataPtr pData, tSize Size);

    //! Constructor copies a given data.
    inline CRefData(const CRefData& Data);

    //! Constructor which makes reference to an existing data.
    //! - Usage: CRefData(Data, REFERENCE).
    inline CRefData(const CRefData& Data, EMakeRef);

    //! Destructor deallocates the data if the number of references
    //! decreases to zero.
    inline ~CRefData();

    //! Assignment operator.
    //! - Makes copy of the data.
    inline CRefData& operator=(const CRefData& Data);

    //! Allocates data of a given size.
    //! - In case of several references to the existing data, the reference
    //!   counter is decremented and new data are allocated.
    //! - Returns reference to this.
    inline CRefData& create(tSize Size);

    //! Allocates data and copies the specified data to it.
    //! - Returns reference to this.
    inline CRefData& create(tConstDataPtr pData, tSize Size);

    //! Allocates data and copies the specified data.
    //! - Returns reference to this.
    inline CRefData& create(const CRefData& Data);

    //! Makes a new reference to existing data.
    //! - Eventually deallocates the associated data.
    //! - Returns reference to this.
    inline CRefData& create(const CRefData& Data, EMakeRef);

    //! Initializes the data.
    inline CRefData& fill(const tData& Value);


    //! Returns data size.
    tSize getSize() const
    {
        return (m_pRef) ? m_pRef->m_Size : 0;
    }

    //! Returns the number of references to the data.
    int getNumOfReferences() const
    {
        return (m_pRef) ? m_pRef->m_iReferences : 0;
    }

    //! Returns reference to the subscripted element [i].
    tData& operator ()(tSize i)
    {
        return m_pRef->m_pData[i];
    }
    const tData& operator ()(tSize i) const
    {
        return m_pRef->m_pData[i];
    }

    //! Returns reference to the element [i].
    tData& at(tSize i)
    {
        return m_pRef->m_pData[i];
    }
    const tData& at(tSize i) const
    {
        return m_pRef->m_pData[i];
    }

    //! Returns pointer to the given element.
    tDataPtr getPtr(tSize i)
    {
        return (m_pRef->m_pData + i);
    }
    tConstDataPtr getPtr(tSize i) const
    {
        return (m_pRef->m_pData + i);
    }

    //! Sets the element of matrix at the position [i].
    CRefData& set(tSize i, const T& Value)
    {
        m_pRef->m_pData[i] = Value;
        return *this;
    }

    //! Returns pointer to the data.
    tDataPtr getPtr()
    {
        return m_pRef->m_pData;
    }
    tConstDataPtr getPtr() const
    {
        return m_pRef->m_pData;
    }

    //! Returns true if the specified range of elements lie within
    //! a continuous block of memory.
    bool isWithinBlock(tSize i, tSize j) const { return true; }


    //! Calls function object for every element.
    template <class Function>
    inline Function forEach(Function Func);

    //! Calls function object for every element.
    template <class Function>
    inline Function forEach(Function Func) const;


    //! Calls function object for every element.
    template <class Function>
    inline Function forRange(tSize i, tSize j, Function Func);

    //! Calls function object for every element.
    template <class Function>
    inline Function forRange(tSize i, tSize j, Function Func) const;

protected:
    //! Structure containing information on allocated data
    //! and the number of references to this data.
    struct SRefInfo
    {
        //! Size of the allocated data.
        tSize m_Size;

        //! Pointer to the allocated data.
        tDataPtr m_pData;

        //! The number of references to the data.
        //! - Zero if there is no reference.
        int m_iReferences;

        //! Constructor that allocates a given size of data.
        //! - Allocation of the zero size data is allowed.
        inline SRefInfo(tSize Size);

        //! Destructor.
        //! - Deallocates the data.
        inline ~SRefInfo();
        
        //! Resizes the data.
        //! - Function doesn't check the number of references.
        inline void resize(tSize Size);
    };

    //! Pointer to the structure containing the referenced data.
    SRefInfo *m_pRef;
};


//==============================================================================
/*
 * Method templates
 */

// Include file containing method templates
#include "mdsRefData.hxx"


} // namespace base
} // namespace mds

#endif // MDS_RefData_H

