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
 * Date:    2004/12/23                          \n
 *
 * Description:
 * - Memory allocation and manipulation functions.
 */

//==============================================================================
/*
 * Function templates.
 */

template <typename T>
inline T *memAlloc(tSize Count)
{
#ifdef VPL_USE_ALIGNED_MEMORY_ALLOCATIONS
    T *p = static_cast<T *>(vmalloc(Count * sizeof(T)));
#else
    T *p = static_cast<T *>(std::malloc(Count * sizeof(T)));
#endif
    if( !p )
    {
        throw std::bad_alloc();
    }
    return p;
}


template <typename T>
inline T *memRealloc(T *pMem, tSize Count)
{
#ifdef VPL_USE_ALIGNED_MEMORY_ALLOCATIONS
    T *p = static_cast<T *>(vrealloc(static_cast<void *>(pMem), Count * sizeof(T)));
#else
    T *p = static_cast<T *>(std::realloc(static_cast<void *>(pMem), Count * sizeof(T)));
#endif
    if( !p )
    {
        throw std::bad_alloc();
    }
    return p;
}


template <typename T>
inline void memFree(T *pMem)
{
#ifdef VPL_USE_ALIGNED_MEMORY_ALLOCATIONS
    vfree(static_cast<void *>(pMem));
#else
    std::free(static_cast<void *>(pMem));
#endif
}


//==============================================================================
/*
 * Basic memory manipulation functions.
 */

template <typename T>
inline void memCopy(T *pDst, const T *pSrc, tSize Count)
{
    // Here we do not use the standard memcpy() function...
    //std::memcpy(static_cast<void *>(pDst), static_cast<const void *>(pSrc), Count * sizeof(T));

    vmemcpy(static_cast<void *>(pDst), static_cast<const void *>(pSrc), Count * sizeof(T));
}


template <typename T>
inline void memZero(T *pMem, tSize Count)
{
    // Here we do not use the standard memset() function...
    //std::memset(static_cast<void *>(pMem), 0, Count * sizeof(T));
    
    vmemzero(static_cast<void *>(pMem), Count * sizeof(T));
}


template <typename T>
inline void memSet(T *pMem, const T& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pMem++) = Value;
    }
}


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
 * Interleaved memory manipulation functions.
 */

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


template <typename T>
inline void memSparseSet(T *pMem, tSize Stride, const T& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *pMem = Value;
        pMem += Stride;
    }
}


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

template <typename T, typename U>
inline void memAdd(T *pMem, const U& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pMem++) += Value;
    }
}


template <typename T, typename U>
inline void memSub(T *pMem, const U& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pMem++) -= Value;
    }
}


template <typename T, typename U>
inline void memMult(T *pMem, const U& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pMem++) *= Value;
    }
}


template <typename T, typename U>
inline void memDiv(T *pMem, const U& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pMem++) /= Value;
    }
}


template <typename T, typename U>
inline void memVectAdd(T *pDst, const U *pSrc, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pDst++) += *(pSrc++);
    }
}


template <typename T, typename U, typename V>
inline void memVectMultAdd(T *pDst, const U *pSrc, const V& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pDst++) += Value * *(pSrc++);
    }
}


template <typename T, typename U>
inline void memVectSub(T *pDst, const U *pSrc, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pDst++) -= *(pSrc++);
    }
}


template <typename T, typename U>
inline void memVectMult(T *pDst, const U *pSrc, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *(pDst++) *= *(pSrc++);
    }
}


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
 * Extended interleaved memory manipulation functions.
 */

template <typename T, typename U>
inline void memSparseAdd(T *pMem, tSize Stride, const U& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *pMem += Value;
        pMem += Stride;
    }
}


template <typename T, typename U>
inline void memSparseSub(T *pMem, tSize Stride, const U& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *pMem -= Value;
        pMem += Stride;
    }
}


template <typename T, typename U>
inline void memSparseMult(T *pMem, tSize Stride, const U& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *pMem *= Value;
        pMem += Stride;
    }
}


template <typename T, typename U>
inline void memSparseDiv(T *pMem, tSize Stride, const U& Value, tSize Count)
{
    for( tSize i = 0; i < Count; ++i )
    {
        *pMem /= Value;
        pMem += Stride;
    }
}


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
