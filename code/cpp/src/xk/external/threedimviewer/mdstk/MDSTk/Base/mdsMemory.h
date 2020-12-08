//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/12/23                          \n
 *
 * $Id: mdsMemory.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Memory allocation and manipulation functions.
 */

#ifndef MDS_MEMORY_H
#define MDS_MEMORY_H

#include "mdsAssert.h"
#include "mdsTypes.h"

// STL
#include <new>
#include <cstdlib>
#include <cstring>


namespace mds
{
namespace base
{

//==============================================================================
/*
 * Memory allocation functions.
 */

//! Allocates memory.
//! - Throws std::bad_alloc exception on failure.
template <typename T>
inline T *memAlloc(tSize Count)
{
    T *p = static_cast<T *>(malloc(Count * sizeof(T)));
    if( !p )
    {
        throw std::bad_alloc();
    }
    return p;
}


//! Reallocates memory.
//! - Returns a valid pointer if the size is zero!
//! - Throws std::bad_alloc exception on failure.
template <typename T>
inline T *memRealloc(T *pMem, tSize Count)
{
    T *p = static_cast<T *>(realloc(static_cast<void *>(pMem), (Count + 4) * sizeof(T)));
    if( !p )
    {
        throw std::bad_alloc();
    }
    return p;
}


//! De-allocates memory.
template <typename T>
inline void memFree(T *pMem)
{
    free(static_cast<void *>(pMem));
}


//==============================================================================
/*
 * Basic memory manipulation functions.
 */

//! Copies memory.
template <typename T>
inline void memCopy(T *pDst, const T *pSrc, tSize Count)
{
    memcpy(static_cast<void *>(pDst), static_cast<const void *>(pSrc), Count * sizeof(T));
}


//! Copies memory.
template <typename T>
inline void memLoopCopy(T *pDst, const T *pSrc, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pDst++) = *(pSrc++);
    }
}


//! Initializes memory.
template <typename T>
inline void memSet(T *pMem, const T& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pMem++) = Value;
    }
}


//! Swaps content of two memory blocks.
template <typename T>
inline void memSwap(T *p1, T *p2, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        T Temp = *p1;
        *(p1++) = *p2;
        *(p2++) = Temp;
    }
}


//==============================================================================
/*
 * Basic memory manipulation functions.
 * - Sparse data vector.
 */

//! Copies memory.
template <typename T>
inline void memSparseCopy(T *pDst, tSize DstStride, const T *pSrc, tSize SrcStride, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *pDst = *pSrc;
        pDst += DstStride;
        pSrc += SrcStride;
    }
}


//! Initializes memory.
template <typename T>
inline void memSparseSet(T *pMem, tSize Stride, const T& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *pMem = Value;
        pMem += Stride;
    }
}


//! Swaps content of two memory blocks.
template <typename T>
inline void memSparseSwap(T *p1, tSize Stride1, const T *p2, tSize Stride2, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        T Temp = *p1;
        *p1 = *p2;
        *p2 = Temp;
        p1 += Stride1;
        p2 += Stride2;
    }
}


//==============================================================================
/*
 * Extended memory manipulation functions.
 */

//! Adds Value to all memory elements.
template <typename T, typename U>
inline void memAdd(T *pMem, const U& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pMem++) += Value;
    }
}


//! Subtracts Value from memory elements.
template <typename T, typename U>
inline void memSub(T *pMem, const U& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pMem++) -= Value;
    }
}


//! Multiples memory elements by Value.
template <typename T, typename U>
inline void memMult(T *pMem, const U& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pMem++) *= Value;
    }
}


//! Divides memory elements by Value.
template <typename T, typename U>
inline void memDiv(T *pMem, const U& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pMem++) /= Value;
    }
}


//! Adds memory elements pointed to by pSrc to pDst.
template <typename T, typename U>
inline void memVectAdd(T *pDst, const U *pSrc, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pDst++) += *(pSrc++);
    }
}


//! Adds memory elements pointed to by pSrc and multiplied by Value to pDst.
template <typename T, typename U, typename V>
inline void memVectMultAdd(T *pDst, const U *pSrc, const V& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pDst++) += Value * *(pSrc++);
    }
}


//! Subtracts memory elements pointed to by 'pSrc' from 'pDst'.
//! - Result is stored in 'pDst'.
template <typename T, typename U>
inline void memVectSub(T *pDst, const U *pSrc, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pDst++) -= *(pSrc++);
    }
}


//! Multiples memory elements pointed to by 'pDst' by 'pSrc' elements.
template <typename T, typename U>
inline void memVectMult(T *pDst, const U *pSrc, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pDst++) *= *(pSrc++);
    }
}


//! Divides memory elements pointed to by 'pDst' by 'pSrc' elements.
template <typename T, typename U>
inline void memVectDiv(T *pDst, const U *pSrc, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pDst++) /= *(pSrc++);
    }
}


//==============================================================================
/*
 * Extended memory manipulation functions.
 * - Sparse vector of data.
 */

//! Adds Value to all memory elements.
template <typename T, typename U>
inline void memSparseAdd(T *pMem, tSize Stride, const U& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *pMem += Value;
        pMem += Stride;
    }
}


//! Subtracts Value from memory elements.
template <typename T, typename U>
inline void memSparseSub(T *pMem, tSize Stride, const U& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *pMem -= Value;
        pMem += Stride;
    }
}


//! Multiples memory elements by Value.
template <typename T, typename U>
inline void memSparseMult(T *pMem, tSize Stride, const U& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *pMem *= Value;
        pMem += Stride;
    }
}


//! Divides memory elements by Value.
template <typename T, typename U>
inline void memSparseDiv(T *pMem, tSize Stride, const U& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *pMem /= Value;
        pMem += Stride;
    }
}


//! Adds memory elements pointed to by 'pSrc' to 'pDst'.
template <typename T, typename U>
inline void memVectSparseAdd(T *pDst, tSize DstStride, const U *pSrc, tSize SrcStride, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *pDst += *pSrc;
        pDst += DstStride;
        pSrc += SrcStride;
    }
}


//! Adds memory elements pointed to by 'pSrc' and multiplied by Value to 'pDst'.
template <typename T, typename U, typename V>
inline void memVectSparseMultAdd(T *pDst, tSize DstStride, const U *pSrc, tSize SrcStride, const V& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *pDst += Value * *pSrc;
        pDst += DstStride;
        pSrc += SrcStride;
    }
}


//! Subtracts memory elements pointed to by 'pSrc' from 'pDst'.
//! - Result is stored in 'pDst'.
template <typename T, typename U>
inline void memVectSparseSub(T *pDst, tSize DstStride, const U *pSrc, tSize SrcStride, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *pDst -= *pSrc;
        pDst += DstStride;
        pSrc += SrcStride;
    }
}


//! Multiples memory elements pointed to by 'pDst' by 'pSrc' elements.
template <typename T, typename U>
inline void memVectSparseMult(T *pDst, tSize DstStride, const U *pSrc, tSize SrcStride, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *pDst *= *pSrc;
        pDst += DstStride;
        pSrc += SrcStride;
    }
}


//! Divides memory elements pointed to by 'pDst' by 'pSrc' elements.
template <typename T, typename U>
inline void memVectSparseDiv(T *pDst, tSize DstStride, const U *pSrc, tSize SrcStride, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *pDst /= *pSrc;
        pDst += DstStride;
        pSrc += SrcStride;
    }
}


} // namespace base
} // namespace mds

#endif // MDS_MEMORY_H

