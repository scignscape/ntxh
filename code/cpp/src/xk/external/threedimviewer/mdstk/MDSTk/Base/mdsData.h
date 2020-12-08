//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/11/23                          \n
 *
 * $Id: mdsData.h 2091 2012-02-14 11:26:36Z spanel $
 *
 * Description:
 * - Template providing data allocation functions.
 * - Functions malloc() and free() are used internally.
 */

#ifndef MDS_Data_H
#define MDS_Data_H

#include "mdsAssert.h"
#include "mdsTypes.h"
#include "mdsMemory.h"
#include "mdsException.h"
#include "mdsDataAllocator.h"


namespace mds
{
namespace base
{

//==============================================================================
/*!
 * Class template providing data allocation functions.
 * - Functions malloc() and free() are used internally to allocate
 *   continuous block of memory.
 */
template <typename T>
class CData : public CDataAllocator<T>
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
    inline CData();

    //! This constructor does no allocation of the data.
    //! - Be sure that one of the methods create() is called somewhere later.
    //! - Use with care!
    inline explicit CData(EEmptyConst);

    //! Constructor that allocates a given size of data.
    //! - Data of the zero size can be also allocated.
    inline explicit CData(tSize Size);

    //! Constructor that copies a specified data.
    inline CData(tConstDataPtr pData, tSize Size);

    //! Constructor copies a given data.
    inline CData(const CData& Data);

    //! Destructor.
    //! - Deallocates the data.
    inline ~CData();

    //! Assignment operator.
    CData& operator =(const CData& Data);

    //! Allocates memory for data of a given size.
    //! - Returns reference to this.
    inline CData& create(tSize Size);

    //! Allocates memory and copies the specified data.
    //! - Returns reference to this.
    inline CData& create(tConstDataPtr pData, tSize Size);

    //! Allocates memory and copies the specified data.
    //! - Returns reference to this.
    inline CData& create(const CData& Data);

    //! Fills the entire data.
    inline CData& fill(const tData& Value);


    //! Returns size of the data.
    tSize getSize() const { return m_Size; }

    //! Returns reference to the subscripted element [i].
    tData& operator ()(tSize i)
    {
        return m_pData[i];
    }
    const tData& operator ()(tSize i) const
    {
        return m_pData[i];
    }

    //! Returns reference to the element [i].
    tData& at(tSize i)
    {
        return m_pData[i];
    }
    const tData& at(tSize i) const
    {
        return m_pData[i];
    }

    //! Returns pointer to the element [i].
    tDataPtr getPtr(tSize i)
    {
        return (m_pData + i);
    }
    tConstDataPtr getPtr(tSize i) const
    {
        return (m_pData + i);
    }

    //! Sets the element of matrix at the position [i].
    CData& set(tSize i, const T& Value)
    {
        m_pData[i] = Value;
        return *this;
    }

    //! Returns pointer to the data.
    tDataPtr getPtr()
    {
        return m_pData;
    }
    tConstDataPtr getPtr() const
    {
        return m_pData;
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


    //! Calls function object for all elements in the range <i, j>.
    template <class Function>
    inline Function forRange(tSize i, tSize j, Function Func);

    //! Calls function object for all elements in the range <i, j>.
    template <class Function>
    inline Function forRange(tSize i, tSize j, Function Func) const;

protected:
    //! Size of the allocated data.
    tSize m_Size;

    //! Pointer to the allocated data.
    tDataPtr m_pData;
};


//==============================================================================
/*
 * Method templates
 */

// Include file containing method templates
#include "mdsData.hxx"


} // namespace base
} // namespace mds

#endif // MDS_Data_H

