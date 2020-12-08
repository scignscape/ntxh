//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/15                          \n
 *
 * $Id: mdsStaticData.h 2092 2012-02-15 12:50:59Z spanel $
 *
 * Description:
 * - Class template providing data allocation functions.
 * - Implemented via static array.
 */

#ifndef MDS_StaticData_H
#define MDS_StaticData_H

#include "mdsAssert.h"
#include "mdsTypes.h"
#include "mdsMemory.h"
#include "mdsException.h"
#include "mdsMeta.h"
#include "mdsDataAllocator.h"


namespace mds
{
namespace base
{

//==============================================================================
/*
 * Global definitions.
 */

//! Exception thrown when you are trying increase size of a static memory block.
MDS_DECLARE_EXCEPTION(CBadStaticAlloc, "Cannot increase size of a static memory block")


//==============================================================================
/*!
 * Class template providing data allocation.
 * - Implemented via static array.
 */
template <typename T, tSize M>
class CStaticData : public CDataAllocator<T>
{
public:
    // Base types
    typedef CDataAllocator<T> base;
    typedef typename base::tData tData;
    typedef typename base::tDataPtr tDataPtr;
    typedef typename base::tConstData tConstData;
    typedef typename base::tConstDataPtr tConstDataPtr;

    //! Maximal allowed size of the memory block.
    enum { MAX_SIZE = M };

public:
    //! Default constructor initializes length of the data to MAX_SIZE.
    inline CStaticData();

    //! This constructor does noething.
    //! - Be sure that one of the methods create(...) is called somewhere.
    //! - Use with care!
    inline explicit CStaticData(EEmptyConst);

    //! Constructor initializes size of data.
    //! - Data of the zero size can be also created.
    //! - Throws mds::base::CBadStaticAlloc() on failure!
    inline explicit CStaticData(tSize Size);

    //! Constructor that copies a specified data.
    inline CStaticData(tConstDataPtr pData, tSize Size);

    //! Constructor copies a given data.
    inline CStaticData(const CStaticData& Data);

    //! Destructor.
    inline ~CStaticData();

    //! Assignment operator.
    inline CStaticData& operator =(const CStaticData& Data);

    //! Creates data of a given size.
    //! - Throws mds::base::CBadStaticAlloc() on failure!
    inline CStaticData& create(tSize Size);

    //! Copies the specified data.
    inline CStaticData& create(tConstDataPtr pData, tSize Size);

    //! Allocates memory and copies the specified data.
    inline CStaticData& create(const CStaticData& Data);

    //! Initializes the data.
    inline CStaticData& fill(const tData& Value);


    //! Returns current data size.
    tSize getSize() const { return m_Size; }

    //! Returns reference to the subscripted element [i].
    T& operator ()(tSize i)
    {
        return m_pData[i];
    }
    const T& operator ()(tSize i) const
    {
        return m_pData[i];
    }

    //! Returns reference to the element [i].
    T& at(tSize i)
    {
        return m_pData[i];
    }
    const T& at(tSize i) const
    {
        return m_pData[i];
    }

    //! Returns pointer to the element [i].
    T *getPtr(tSize i)
    {
        return (m_pData + i);
    }
    const T *getPtr(tSize i) const
    {
        return (m_pData + i);
    }

    //! Sets the element of matrix at the position [i].
    CStaticData& set(tSize i, const T& Value)
    {
        m_pData[i] = Value;
        return *this;
    }

    //! Returns pointer to the data.
    T *getPtr()
    {
        return m_pData;
    }
    const T *getPtr() const
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


    //! Calls function object for every element.
    template <class Function>
    inline Function forRange(tSize i, tSize j, Function Func);

    //! Calls function object for every element.
    template <class Function>
    inline Function forRange(tSize i, tSize j, Function Func) const;

protected:
    //! Current size.
    tSize m_Size;

    //! Statically allocated data.
    tData m_pData[M];
};


//==============================================================================
/*
 * Method templates
 */

// Include file containing method templates
#include "mdsStaticData.hxx"


} // namespace base
} // namespace mds

#endif // MDS_StaticData_H

