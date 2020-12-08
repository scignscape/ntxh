//==============================================================================
/* This file is part of
 *
 * VPL - Voxel Processing Library
 * Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <VPL/System/Memory.h>

// Windows version
#ifdef _WIN32
#   include <windows.h>
#   include <malloc.h>
#else // Non-windows version
#   include <stdint.h>
#endif


namespace vpl
{
namespace sys
{

//==============================================================================
/*
 * Memory allocation functions.
 */

#ifdef _WIN32
    //! Minimum number of bytes to be allocated using Windows _aligned_malloc()
    const std::size_t DEFAULT_PADDING = 16;
#endif


void *vmalloc(std::size_t NumOfBytes, std::size_t Alignment)
{
#ifdef _WIN32
    // _aligned_malloc() cannot allocate zero size memory so an extra padding is added
    return _aligned_malloc(NumOfBytes + DEFAULT_PADDING, Alignment);
#else
    // Allocate a bit longer memory block
    unsigned char *pOrig = static_cast<unsigned char *>(std::malloc(NumOfBytes + Alignment));
    if( !pOrig )
    {
        return NULL;
    }

    // Align the pointer
    uintptr_t np = reinterpret_cast<uintptr_t>(pOrig + Alignment) & (~static_cast<uintptr_t>(Alignment - 1));
    unsigned char *p = reinterpret_cast<unsigned char *>(np);

    // Store the padding size
    *(p-1) = p - pOrig;

    // Return the aligned pointer
    return static_cast<void *>(p);
#endif
}


void *vrealloc(void *pMem, std::size_t NumOfBytes, std::size_t Alignment)
{
#ifdef _WIN32
    // _aligned_malloc() cannot allocate zero size memory so an extra padding is added
    return _aligned_realloc(pMem, NumOfBytes + DEFAULT_PADDING, Alignment);
#else
    // Create pointer to bytes
    unsigned char *p = static_cast<unsigned char *>(pMem);
    unsigned char *pOrig = p;

    // If the pointer is not NULL, get the original pointer by subtracting the padding
    if( p != NULL )
    {
        pOrig = p - *(p-1);
    }
    
    // Call realloc to get more memory plus the extra padding
    unsigned char *pNew = static_cast<unsigned char *>(std::realloc(pOrig, NumOfBytes + Alignment));
    if( !pNew )
    {
        return NULL;
    }

    // Align the new pointer
    if( !pOrig )
    {
        uintptr_t np = reinterpret_cast<uintptr_t>(pNew + Alignment) & (~static_cast<uintptr_t>(Alignment - 1));
        p = reinterpret_cast<unsigned char *>(np);
    }
    else
    {
        // Won't be always aligned (e.g. when realloc copies data to a newly allocated block of memory)!
        p = pNew + (p - pOrig);
    }
    
    // Store the padding size
    *(p-1) = p - pNew;

    // Return the aligned pointer
    return static_cast<void *>(p);
#endif
}


void vfree(void *pMem)
{
#ifdef _WIN32
    _aligned_free(pMem);
#else
    // Create pointer to bytes
    unsigned char *p = static_cast<unsigned char *>(pMem);
    unsigned char *pOrig = p;

    // If the pointer is not NULL, get the original pointer by subtracting the padding
    if( p != NULL )
    {
        pOrig = p - *(p-1);
    }

    // Free the original pointer
    std::free(static_cast<unsigned char *>(pOrig));
#endif
}


//==============================================================================
/*
 * Basic memory manipulation functions.
 */

void vmemcpy(void *pDst, const void *pSrc, std::size_t NumOfBytes)
{
    // Check if we can copy the data per integers
    if( (NumOfBytes & (sizeof(int) - 1)) == 0 )
    {
        int *dst = reinterpret_cast<int *>(pDst);
        const int *src = reinterpret_cast<const int *>(pSrc);
        for( std::size_t i = 0; i < NumOfBytes; i += sizeof(int) )
        {
            *(dst++) = *(src++);
        }
    }
    else
    {
        char *dst = reinterpret_cast<char *>(pDst);
        const char *src = reinterpret_cast<const char *>(pSrc);
        for( std::size_t i = 0; i < NumOfBytes; ++i )
        {
            *(dst++) = *(src++);
        }
    }
}


void vmemzero(void *pMem, std::size_t NumOfBytes)
{
    // Check if we can zero the data per integers
    if( (NumOfBytes & (sizeof(int) - 1)) == 0 )
    {
        int *p = reinterpret_cast<int *>(pMem);
        for( std::size_t i = 0; i < NumOfBytes; i += sizeof(int) )
        {
            *(p++) = 0;
        }
    }
    else
    {
        char *p = reinterpret_cast<char *>(pMem);
        for( std::size_t i = 0; i < NumOfBytes; ++i )
        {
            *(p++) = 0;
        }
    }
}


} // namespace sys
} // namespace vpl
