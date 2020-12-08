//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)     \n
 * Copyright (c) 2011 by 3Dim Laboratory s.r.o.  \n
 *
 * Author:  info@3dim-laboratory.cz              \n
 * Date:    2011/11/17                           \n
 *
 * $Id:$
 */

#ifndef MDS_PartedData_H
#define MDS_PartedData_H

#include "mdsRefData.h"

#include "mdsGlobalLog.h"


namespace mds
{
namespace base
{

//==============================================================================
/*
 * Global constants.
 */

//! Namespace containing constants used by the CPartedData<> allocator.
namespace PartedData
{
    //! Divisor used to calculate an index j of a concrete data block
    //! for a specified data element i: j = i / BLOCK_SIZE = i >> DIV_SHIFT
    const tSize DIV_SHIFT   = 24;

    //! Data block size in elements.
    //! - The block size must be a power of two!
    const tSize BLOCK_SIZE  = 1 << DIV_SHIFT;

    //! Mask used to calculate an index k of a subscripted element i
    //! within a data block: k = i % BLOCK_SIZE = i & MOD_MASK
    const tSize MOD_MASK    = BLOCK_SIZE - 1;
}


//==============================================================================
/*!
 * Class template managing references to a block of memory that is allocated 
 * in parts as a sequence of smaller memory blocks.
 * - Functions malloc() and free() are used internally.
 * - Provides own data reference counting mechanism.
 */
template <typename T>
class CPartedData : public CDataAllocator<T>
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
    inline CPartedData();

    //! This constructor does no allocation of the data.
    //! - Be sure that one of the methods create(...) is called somewhere.
    //! - Use with care!
    inline explicit CPartedData(EEmptyConst);

    //! Constructor that allocates a given size of data.
    //! - Data of the zero size can be allocated.
    inline explicit CPartedData(tSize Size);

    //! Constructor that copies a specified data.
    inline CPartedData(tConstDataPtr pData, tSize Size);

    //! Constructor copies a given data.
    inline CPartedData(const CPartedData& Data);

    //! Constructor which makes reference to an existing data.
    //! - Usage: CPartedData(Data, REFERENCE).
    inline CPartedData(const CPartedData& Data, EMakeRef);

    //! Destructor deallocates the data if the number of references
    //! decreases to zero.
    inline ~CPartedData();

    //! Assignment operator.
    //! - Makes copy of the data.
    inline CPartedData& operator=(const CPartedData& Data);

    //! Allocates data of a given size.
    //! - In case of several references to the existing data, the reference
    //!   counter is decremented and new data are allocated.
    //! - Returns reference to this.
    inline CPartedData& create(tSize Size);

    //! Allocates data and copies the specified data to it.
    //! - Returns reference to this.
    inline CPartedData& create(tConstDataPtr pData, tSize Size);

    //! Allocates data and copies the specified data.
    //! - Returns reference to this.
    inline CPartedData& create(const CPartedData& Data);

    //! Makes a new reference to existing data.
    //! - Eventually deallocates the associated data.
    //! - Returns reference to this.
    inline CPartedData& create(const CPartedData& Data, EMakeRef);

    //! Initializes the data.
    inline CPartedData& fill(const tData& Value);


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
        return at(i);
    }
    const tData& operator ()(tSize i) const
    {
        return at(i);
    }

    //! Returns reference to the element [i].
    tData& at(tSize i)
    {
        return m_pRef->m_ppData[i >> PartedData::DIV_SHIFT][i & PartedData::MOD_MASK];
    }
    const tData& at(tSize i) const
    {
        return m_pRef->m_ppData[i >> PartedData::DIV_SHIFT][i & PartedData::MOD_MASK];
    }

    //! Returns pointer to the given element.
    tDataPtr getPtr(tSize i)
    {
        return m_pRef->m_ppData[i >> PartedData::DIV_SHIFT] + (i & PartedData::MOD_MASK);
    }
    tConstDataPtr getPtr(tSize i) const
    {
        return m_pRef->m_ppData[i >> PartedData::DIV_SHIFT] + (i & PartedData::MOD_MASK);
    }

    //! Sets the element of matrix at the position [i].
    CPartedData& set(tSize i, const T& Value)
    {
        at(i) = Value;
        return *this;
    }

    //! Returns pointer to the beginning of the data.
    tDataPtr getPtr()
    {
        return m_pRef->m_ppData[0];
    }
    tConstDataPtr getPtr() const
    {
        return m_pRef->m_ppData[0];
    }

    //! Returns true if the specified range of elements lie within
    //! a continuous block of memory.
    bool isWithinBlock(tSize i, tSize j) const
    {
        return (i >> PartedData::DIV_SHIFT) == (j >> PartedData::DIV_SHIFT);
    }


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
    //! Vector of allocated data blocks.
    typedef tDataPtr *tDataBlocks;
    
    //! Structure containing information on allocated data
    //! and the number of references.
    struct SRefInfo
    {
        //! Total size of the allocated data.
        tSize m_Size;
        
        //! The number of references to the data.
        //! - Zero if there is no reference.
        int m_iReferences;
        
        //! Number of data blocks.
        tSize m_NumOfBlocks;
        
        //! Pointers to the allocated data blocks.
        tDataBlocks m_ppData;
        
        //! Constructor that allocates a given size of data.
        //! - Allocation of the zero size data is allowed.
        inline SRefInfo(tSize Size);
        
        //! Destructor deallocates all the data blocks.
        inline ~SRefInfo();
        
        //! Resizes the data.
        //! - Function doesn't take care of the number of references.
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
#include "mdsPartedData.hxx"


} // namespace base
} // namespace mds

#endif // MDS_PartedData_H

