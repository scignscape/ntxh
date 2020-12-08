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

#ifndef VPL_MEMORY_H
#define VPL_MEMORY_H

#include <VPL/Base/Assert.h>
#include <VPL/Base/Types.h>
#include <VPL/Base/BaseExport.h>

// STL
#include <new>
#include <cstdlib>
#include <cstring>

// Windows version
#if defined(_WIN32) && defined(VPL_USE_ALIGNED_MEMORY_ALLOCATIONS)
#   include <windows.h>
#   include <malloc.h>
#endif


namespace vpl
{
namespace sys
{

//==============================================================================
/*
 * Memory allocation functions.
 */

//! Default memory alignment for image data to guarantee the memory
//! will be aligned to a typical cache line size (64 bytes by default).
const std::size_t DEFAULT_MEMORY_ALIGNMENT = 64;

//! Aligned memory allocation function.
VPL_BASE_EXPORT void *vmalloc(std::size_t NumOfBytes, std::size_t Alignment = DEFAULT_MEMORY_ALIGNMENT);

//! Aligned alternative to realloc().
VPL_BASE_EXPORT void *vrealloc(void *pMem, std::size_t NumOfBytes, std::size_t Alignment = DEFAULT_MEMORY_ALIGNMENT);

//! Aligned alternative to free().
VPL_BASE_EXPORT void vfree(void *pMem);

//! Allocates memory.
//! - Throws std::bad_alloc exception on failure.
template <typename T>
inline T *memAlloc(tSize Count);

//! Reallocates memory.
//! - Returns a valid pointer if the size is zero!
//! - Throws std::bad_alloc exception on failure.
template <typename T>
inline T *memRealloc(T *pMem, tSize Count);

//! De-allocates memory.
template <typename T>
inline void memFree(T *pMem);


//==============================================================================
/*
 * Basic memory manipulation functions.
 */

//! VPL alternative to memcpy.
VPL_BASE_EXPORT void vmemcpy(void *pDst, const void *pSrc, std::size_t NumOfBytes);

//! Function zeros a given block of memory.
VPL_BASE_EXPORT void vmemzero(void *pMem, std::size_t NumOfBytes);

//! Copies memory.
template <typename T>
inline void memCopy(T *pDst, const T *pSrc, tSize Count);

//! Zeros memory.
template <typename T>
inline void memZero(T *pMem, tSize Count);

//! Initializes memory.
template <typename T>
inline void memSet(T *pMem, const T& Value, tSize Count);

//! Swaps content of two memory blocks.
template <typename T>
inline void memSwap(T *p1, T *p2, tSize Count);


//==============================================================================
/*
 * Interleaved memory manipulation functions.
 */

//! Copies memory.
template <typename T>
inline void memSparseCopy(T *pDst, tSize DstStride, const T *pSrc, tSize SrcStride, tSize Count);

//! Initializes memory.
template <typename T>
inline void memSparseSet(T *pMem, tSize Stride, const T& Value, tSize Count);

//! Swaps content of two memory blocks.
template <typename T>
inline void memSparseSwap(T *p1, tSize Stride1, const T *p2, tSize Stride2, tSize Count);


//==============================================================================
/*
 * Extended memory manipulation functions.
 */

//! Adds Value to all memory elements.
template <typename T, typename U>
inline void memAdd(T *pMem, const U& Value, tSize Count);

//! Subtracts Value from memory elements.
template <typename T, typename U>
inline void memSub(T *pMem, const U& Value, tSize Count);

//! Multiples memory elements by Value.
template <typename T, typename U>
inline void memMult(T *pMem, const U& Value, tSize Count);

//! Divides memory elements by Value.
template <typename T, typename U>
inline void memDiv(T *pMem, const U& Value, tSize Count);


//! Adds memory elements pointed to by pSrc to pDst.
template <typename T, typename U>
inline void memVectAdd(T *pDst, const U *pSrc, tSize Count);

//! Adds memory elements pointed to by pSrc and multiplied by Value to pDst.
template <typename T, typename U, typename V>
inline void memVectMultAdd(T *pDst, const U *pSrc, const V& Value, tSize Count);

//! Subtracts memory elements pointed to by 'pSrc' from 'pDst'.
//! - Result is stored in 'pDst'.
template <typename T, typename U>
inline void memVectSub(T *pDst, const U *pSrc, tSize Count);

//! Multiples memory elements pointed to by 'pDst' by 'pSrc' elements.
template <typename T, typename U>
inline void memVectMult(T *pDst, const U *pSrc, tSize Count);

//! Divides memory elements pointed to by 'pDst' by 'pSrc' elements.
template <typename T, typename U>
inline void memVectDiv(T *pDst, const U *pSrc, tSize Count);


//==============================================================================
/*
 * Interleaved extended memory manipulation functions.
 */

//! Adds Value to all memory elements.
template <typename T, typename U>
inline void memSparseAdd(T *pMem, tSize Stride, const U& Value, tSize Count);

//! Subtracts Value from memory elements.
template <typename T, typename U>
inline void memSparseSub(T *pMem, tSize Stride, const U& Value, tSize Count);

//! Multiples memory elements by Value.
template <typename T, typename U>
inline void memSparseMult(T *pMem, tSize Stride, const U& Value, tSize Count);

//! Divides memory elements by Value.
template <typename T, typename U>
inline void memSparseDiv(T *pMem, tSize Stride, const U& Value, tSize Count);


//! Adds memory elements pointed to by 'pSrc' to 'pDst'.
template <typename T, typename U>
inline void memVectSparseAdd(T *pDst, tSize DstStride, const U *pSrc, tSize SrcStride, tSize Count);

//! Adds memory elements pointed to by 'pSrc' and multiplied by Value to 'pDst'.
template <typename T, typename U, typename V>
inline void memVectSparseMultAdd(T *pDst, tSize DstStride, const U *pSrc, tSize SrcStride, const V& Value, tSize Count);

//! Subtracts memory elements pointed to by 'pSrc' from 'pDst'.
//! - Result is stored in 'pDst'.
template <typename T, typename U>
inline void memVectSparseSub(T *pDst, tSize DstStride, const U *pSrc, tSize SrcStride, tSize Count);

//! Multiples memory elements pointed to by 'pDst' by 'pSrc' elements.
template <typename T, typename U>
inline void memVectSparseMult(T *pDst, tSize DstStride, const U *pSrc, tSize SrcStride, tSize Count);

//! Divides memory elements pointed to by 'pDst' by 'pSrc' elements.
template <typename T, typename U>
inline void memVectSparseDiv(T *pDst, tSize DstStride, const U *pSrc, tSize SrcStride, tSize Count);


//==============================================================================
/*
 * Function templates
 */

// Include file containing function templates
#include "Memory.hxx"


} // namespace sys
} // namespace vpl

#endif // VPL_MEMORY_H
