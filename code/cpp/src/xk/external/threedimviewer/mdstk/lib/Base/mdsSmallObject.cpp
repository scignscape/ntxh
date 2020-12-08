//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/12/01                          \n
 *
 * $Id: mdsSmallObject.cpp 1863 2010-08-31 20:40:15Z spanel $
 * 
 * This code is based on The Loki Library which accompanies
 * the famous book:
 * Alexandrescu, Andrei. "Modern C++ Design: Generic Programming and Design
 *     Patterns Applied". Copyright (c) 2001. Addison-Wesley.
 *
 * The Loki Library
 * Copyright (c) 2001 by Andrei Alexandrescu
 * Permission to use, copy, modify, distribute and sell this software for any
 *     purpose is hereby granted without fee, provided that the above copyright
 *     notice appear in all copies and that both that copyright notice and this
 *     permission notice appear in supporting documentation.
 *
 * Description:
 * - Small object allocator providing fast allocations and deallocations.
 */

#include <MDSTk/Base/mdsSmallObject.h>

// STL
#include <vector>


namespace mds
{
namespace base
{

//==============================================================================
/*!
 * Class containing a memory chunk divided into a number of small blocks.
 */
class CChunk
{
private:
    //! Allocates system memory and initializes a chunk
    bool init(tSize BlockSize, unsigned char ucNumBlocks);

    //! Allocates memory block from a chunk
    //! - returns NULL if there is no space left in the chunk
    void *allocate(tSize BlockSize);

    //! Deallocates already assigned block
    void deallocate(void *p, tSize BlockSize);

    //! Prepares a linked list of all available blocks
    void reset(tSize BlockSize, unsigned char ucNumBlocks);

    //! Deallocates the system memory
    void release();

    //! Returns true if block at address 'p' is inside this chunk.
    bool hasBlock(void *p, tSize ChunkLength) const
    {
        unsigned char *puc = static_cast<unsigned char *>(p);
        return (m_pData <= puc) && (puc < m_pData + ChunkLength);
    }

    //! Returns true if chunk has available a given number of free blocks.
    bool hasAvailable(unsigned char ucNumBlocks) const
    {
        return (m_ucBlocksAvailable == ucNumBlocks);
    }

    //! Returns true if there is no free space in the chunk.
    bool isFilled() const
    {
        return (m_ucBlocksAvailable == 0);
    }

private:
    //! Pointer to the allocated memory chunk.
    unsigned char *m_pData;

    //! Index of the first available block in the chunk.
    unsigned char m_ucFirstAvailableBlock;

    //! The number of free blocks.
    unsigned char m_ucBlocksAvailable;

    // Friend classes.
    friend class CFixedAllocator;
};


//==============================================================================
/*!
 * Offers services for allocating fixed-sized objects. It has a container
 * of "containers" of fixed-size blocks.  The outer container has all the
 * chunks. The inner container is a chunk which owns some blocks.
 */
class CFixedAllocator
{
public:
    //! Default constructor.
    CFixedAllocator();

    //! Not implemented.
    ~CFixedAllocator();

    //! Initializes a fixed allocator by calculating number of blocks
    //! per chunk.
    void init(tSize BlockSize, tSize PageSize);

    //! Allocates a memory block
    void *allocate();

    //! Deallocates a memory block previously allocated with allocate. If
    //! the block is not owned by this fixed allocator, it returns false so
    //! that CSmallObjectAllocator can call the default deallocator. If the
    //! block was found, this returns true.
    bool deallocate(void *p, CChunk *pHint);

    //! Returns the block size
    tSize getBlockSize() const { return m_BlockSize; }

    //! Releases the memory used by the empty chunk.
    bool trimEmptyChunk();

    //! Releases unused spots from chunk list.  This takes constant time
    //! with respect to # of chunks, but actual time depends on underlying
    //! memory allocator.
    //! - Returns false if no unused spots, true if some found and released.
    bool trimChunkList( void );

    //! Returns number of empty chunks held by this allocator.
    tSize countEmptyChunks() const;

    //! Returns true if the block at address p is within a chunk owned by
    //! this fixed allocator.
    const CChunk *hasBlock(void *p) const;
    CChunk *hasBlock(void *p)
    {
        return const_cast<CChunk *>(const_cast<const CFixedAllocator *>(this)->hasBlock(p));
    }

private:
    //! Type of container used to hold chunks.
    typedef std::vector<CChunk> tChunks;

private:
    //! Block size
    tSize m_BlockSize;

    //! The number of all blocks in the chunk
    unsigned char m_ucNumBlocks;

    //! Vector of all chunks
    tChunks m_Chunks;

    //! Last chunk used for allocation and deallocation
    CChunk* m_pAllocChunk, *m_pDeallocChunk;

    //! Pointer to the only empty Chunk if there is one, else NULL.
    CChunk *m_pEmptyChunk;

private:
    //! Performs deallocation. Assumes m_dealloc_chunk points
    //! to the correct chunk.
    void doDeallocate(void *p);

    //! Creates an empty chunk and adds it to the end of the chunk list.
    //! All calls to the lower-level memory allocation functions occur inside
    //! this function, and so the only try-catch block is inside here.
    bool makeNewChunk();

    //! Finds the chunk corresponding to a pointer
    CChunk *vicinityFind(void *p);

private:
    //! Not implemented.
    CFixedAllocator(const CFixedAllocator&);

    //! Not implemented.
    CFixedAllocator& operator=(const CFixedAllocator&);
};


//==============================================================================
/*
 * Implementation of the mds::CChunk class.
 */
bool CChunk::init(tSize BlockSize, unsigned char ucNumBlocks)
{
    MDS_ASSERT(BlockSize > 0 && ucNumBlocks > 0);

    // Overflow check
    const tSize AllocSize = BlockSize * ucNumBlocks;
    MDS_ASSERT(AllocSize / BlockSize == ucNumBlocks);

    // Allocate the chunk
    m_pData = (unsigned char *)malloc(AllocSize);
    if( !m_pData )
    {
        return false;
    }

    // Prepare it for usage
    reset(BlockSize, ucNumBlocks);
    return true;
}


void CChunk::reset(tSize BlockSize, unsigned char ucNumBlocks)
{
    MDS_ASSERT(BlockSize > 0 && ucNumBlocks > 0);

    m_ucFirstAvailableBlock = 0;
    m_ucBlocksAvailable = ucNumBlocks;

    unsigned char *p = m_pData;
    for( unsigned char i = 0; i != ucNumBlocks; p += BlockSize )
    {
        *p = ++i;
    }
}


void CChunk::release()
{
    MDS_ASSERT(m_pData);

    free((void *)m_pData);
}


void *CChunk::allocate(tSize BlockSize)
{
    if( isFilled() )
    {
        return NULL;
    }

    unsigned char *p = m_pData + (m_ucFirstAvailableBlock * BlockSize);
    m_ucFirstAvailableBlock = *p;
    --m_ucBlocksAvailable;

    return p;
}


void CChunk::deallocate(void *p, tSize BlockSize)
{
    MDS_ASSERT(p >= m_pData);

    unsigned char *pTemp = static_cast<unsigned char *>(p);

    // Alignment check
    MDS_ASSERT((pTemp - m_pData) % BlockSize == 0);

    *pTemp = m_ucFirstAvailableBlock;
    m_ucFirstAvailableBlock = static_cast<unsigned char>((pTemp - m_pData) / BlockSize);

    // Truncation check
    MDS_ASSERT(m_ucFirstAvailableBlock == (pTemp - m_pData) / BlockSize);

    ++m_ucBlocksAvailable;
}


//==============================================================================
/*
 * Implementation of the mds::CFixedAllocator class.
 */
CFixedAllocator::CFixedAllocator()
    : m_BlockSize(0)
    , m_ucNumBlocks(0)
    , m_Chunks(0)
    , m_pAllocChunk(NULL)
    , m_pDeallocChunk(NULL)
    , m_pEmptyChunk(NULL)
{
}


CFixedAllocator::~CFixedAllocator()
{
    tChunks::iterator itEnd = m_Chunks.end();
    tChunks::iterator it = m_Chunks.begin();
    for( ; it != itEnd; ++it )
    {
        it->release();
    }
}


void CFixedAllocator::init(tSize BlockSize, tSize PageSize)
{
    MDS_ASSERT(BlockSize > 0 && PageSize >= BlockSize);
    m_BlockSize = BlockSize;

    tSize NumBlocks = PageSize / m_BlockSize;
    if( NumBlocks > UCHAR_MAX )
    {
        NumBlocks = UCHAR_MAX;
    }
    else if( NumBlocks < 8 )
    {
        NumBlocks = 8;
    }

    m_ucNumBlocks = static_cast<unsigned char>(NumBlocks);
    MDS_ASSERT(m_ucNumBlocks == NumBlocks);
}


tSize CFixedAllocator::countEmptyChunks() const
{
    return (!m_pEmptyChunk) ? 0 : 1;
}


const CChunk *CFixedAllocator::hasBlock(void *p) const
{
    const tSize ChunkLength = m_ucNumBlocks * m_BlockSize;
    tChunks::const_iterator it = m_Chunks.begin();
    tChunks::const_iterator itEnd = m_Chunks.end();
    for( ; it != itEnd; ++it )
    {
        const CChunk& Chunk = *it;
        if( Chunk.hasBlock(p, ChunkLength) )
        {
            return &Chunk;
        }
    }
    return NULL;
}


bool CFixedAllocator::trimEmptyChunk()
{
    // Prove either m_pEmptyChunk points nowhere, or points to a truly empty chunk
    MDS_ASSERT(!m_pEmptyChunk || m_pEmptyChunk->hasAvailable(m_ucNumBlocks));

    if( !m_pEmptyChunk )
    {
        return false;
    }

    // If m_pEmptyChunk points to valid chunk, then chunk list is not empty.
    MDS_ASSERT(!m_Chunks.empty());

    // And there should be exactly 1 empty chunk.
    MDS_ASSERT(countEmptyChunks() == 1);

    CChunk *pLastChunk = &m_Chunks.back();
    if( pLastChunk != m_pEmptyChunk )
    {
        std::swap(*m_pEmptyChunk, *pLastChunk);
    }
    MDS_ASSERT(pLastChunk->hasAvailable(m_ucNumBlocks));
    pLastChunk->release();
    m_Chunks.pop_back();

    if( m_Chunks.empty() )
    {
        m_pAllocChunk = NULL;
        m_pDeallocChunk = NULL;
    }
    else
    {
        if( m_pDeallocChunk == m_pEmptyChunk )
        {
            m_pDeallocChunk = &m_Chunks.front();
            MDS_ASSERT(m_pDeallocChunk->m_ucBlocksAvailable < m_ucNumBlocks);
        }
        if( m_pAllocChunk == m_pEmptyChunk )
        {
            m_pAllocChunk = &m_Chunks.back();
            MDS_ASSERT(m_pAllocChunk->m_ucBlocksAvailable < m_ucNumBlocks);
        }
    }

    m_pEmptyChunk = NULL;
    MDS_ASSERT(countEmptyChunks() == 0);

    return true;
}


bool CFixedAllocator::trimChunkList()
{
    if( m_Chunks.empty() )
    {
        MDS_ASSERT(!m_pAllocChunk);
        MDS_ASSERT(!m_pDeallocChunk);
    }

    if( m_Chunks.size() == m_Chunks.capacity() )
    {
        return false;
    }

    // Use the "make-a-temp-and-swap" trick to remove excess capacity
    tChunks(m_Chunks).swap(m_Chunks);

    return true;
}


bool CFixedAllocator::makeNewChunk()
{
    bool bAllocated = false;
    try
    {
        std::size_t Size = m_Chunks.size();

        // Calling m_Chunks.reserve *before* creating and initializing the new
        // chunk means that nothing is leaked by this function in case an
        // exception is thrown from reserve.
        if( m_Chunks.capacity() == Size )
        {
            if( Size == 0 )
            {
                Size = 4;
            }
            m_Chunks.reserve(Size * 2);
        }
        CChunk NewChunk;
        bAllocated = NewChunk.init(m_BlockSize, m_ucNumBlocks);
        if( bAllocated )
        {
            m_Chunks.push_back(NewChunk);
        }
    }
    catch( ... )
    {
        bAllocated = false;
    }
    if( !bAllocated )
    {
        return false;
    }

    m_pAllocChunk = &m_Chunks.back();
    m_pDeallocChunk = &m_Chunks.front();
    return true;
}


void *CFixedAllocator::allocate()
{
    // Prove either m_pEmptyChunk points nowhere, or points to a truly empty chunk
    MDS_ASSERT(!m_pEmptyChunk || m_pEmptyChunk->hasAvailable(m_ucNumBlocks));

    if( !m_pAllocChunk || m_pAllocChunk->isFilled() )
    {
        if( m_pEmptyChunk )
        {
            m_pAllocChunk = m_pEmptyChunk;
            m_pEmptyChunk = NULL;
        }
        else
        {
            tChunks::iterator it = m_Chunks.begin();
            for( ;; ++it )
            {
                if( m_Chunks.end() == it )
                {
                    if( !makeNewChunk() )
                    {
                        return NULL;
                    }
                    break;
                }
                if( !it->isFilled() )
                {
                    m_pAllocChunk = &*it;
                    break;
                }
            }
        }
    }
    else if( m_pAllocChunk == m_pEmptyChunk )
    {
        // Detach m_pEmptyChunk from m_pAllocChunk, because after calling
        // allocate, the chunk is no longer empty
        m_pEmptyChunk = NULL;
    }

    MDS_ASSERT(m_pAllocChunk && !m_pAllocChunk->isFilled());
    void *pPlace = m_pAllocChunk->allocate(m_BlockSize);

    return pPlace;
}


bool CFixedAllocator::deallocate(void *p, CChunk *pHint)
{
    CChunk *pFoundChunk = (!pHint) ? vicinityFind(p) : pHint;
    if( !pFoundChunk )
    {
        return false;
    }

    MDS_ASSERT(pFoundChunk->hasBlock(p, m_ucNumBlocks * m_BlockSize));
    m_pDeallocChunk = pFoundChunk;

    doDeallocate(p);

    return true;
}


CChunk *CFixedAllocator::vicinityFind(void *p)
{
    if( m_Chunks.empty() )
    {
        return NULL;
    }

    MDS_ASSERT(m_pDeallocChunk);

    const tSize ChunkLength = m_ucNumBlocks * m_BlockSize;
    CChunk *lo = m_pDeallocChunk;
    CChunk *hi = m_pDeallocChunk + 1;
    const CChunk * loBound = &m_Chunks.front();
    const CChunk * hiBound = &m_Chunks.back() + 1;

    // Special case: m_pDeallocChunk is the last in the array
    if( hi == hiBound )
    {
        hi = NULL;
    }

    for( ;; )
    {
        if( lo )
        {
            if( lo->hasBlock(p, ChunkLength) )
            {
                return lo;
            }
            if( lo == loBound )
            {
                lo = NULL;
                if( NULL == hi )
                {
                    break;
                }
            }
            else
            {
                --lo;
            }
        }

        if( hi )
        {
            if( hi->hasBlock(p, ChunkLength) )
            {
                return hi;
            }
            if( ++hi == hiBound )
            {
                hi = NULL;
                if( NULL == lo )
                {
                    break;
                }
            }
        }
    }

    return NULL;
}


void CFixedAllocator::doDeallocate(void *p)
{
    // Prove either m_pEmptyChunk points nowhere, or points to a truly empty chunk
    MDS_ASSERT(!m_pEmptyChunk || m_pEmptyChunk->hasAvailable(m_ucNumBlocks));

    // Call into the chunk, will adjust the inner list but won't release memory
    m_pDeallocChunk->deallocate(p, m_BlockSize);

    if( m_pDeallocChunk->hasAvailable(m_ucNumBlocks) )
    {
        MDS_ASSERT(m_pEmptyChunk != m_pDeallocChunk);

        // m_pDeallocChunk is empty, but a chunk is only released if there are 2
        // empty chunks. Since m_pEmptyChunk may only point to a previously
        // cleared chunk, if it points to something else besides m_pDeallocChunk,
        // then CFixedAllocator currently has 2 empty chunks.
        if( m_pEmptyChunk )
        {
            // If last chunk is empty, just change what m_pDeallocChunk
            // points to, and release the last.  Otherwise, swap an empty
            // chunk with the last, and then release it.
            CChunk *pLastChunk = &m_Chunks.back();
            if( pLastChunk == m_pDeallocChunk )
            {
                m_pDeallocChunk = m_pEmptyChunk;
            }
            else if( pLastChunk != m_pEmptyChunk )
            {
                std::swap(*m_pEmptyChunk, *pLastChunk);
            }
            MDS_ASSERT(pLastChunk->hasAvailable(m_ucNumBlocks));
            pLastChunk->release();
            m_Chunks.pop_back();
            if( (m_pAllocChunk == pLastChunk) || m_pAllocChunk->isFilled() )
            {
                m_pAllocChunk = m_pDeallocChunk;
            }
        }
        m_pEmptyChunk = m_pDeallocChunk;
    }

    // Prove either m_pEmptyChunk points nowhere, or points to a truly empty Chunk.
    MDS_ASSERT(!m_pEmptyChunk || (m_pEmptyChunk->hasAvailable(m_ucNumBlocks)));
}


//! Calculates index into array where a CFixedAllocator of NumBytes is located.
inline tSize getOffset(tSize NumBytes, tSize Alignment)
{
    const tSize AlignExtra = Alignment - 1;
    return (NumBytes + AlignExtra) / Alignment;
}


//==============================================================================
/*
 * Implementation of the mds::base::CSmallObjectAllocator class.
 */
CSmallObjectAllocator::CSmallObjectAllocator(tSize PageSize,
                                             tSize MaxObjectSize,
                                             tSize ObjectAlignSize
                                             )
    : m_MaxObjectSize(MaxObjectSize)
    , m_ObjectAlignSize(ObjectAlignSize)
{
    MDS_ASSERT(m_ObjectAlignSize > 0);

    const tSize AllocCount = getOffset(m_MaxObjectSize, m_ObjectAlignSize);
    m_pPool = new CFixedAllocator[AllocCount];

    for( tSize i = 0; i < AllocCount; ++i )
    {
        m_pPool[i].init((i + 1) * m_ObjectAlignSize, PageSize);
    }
}


CSmallObjectAllocator::~CSmallObjectAllocator()
{
    delete[] m_pPool;
}


bool CSmallObjectAllocator::trimExcessMemory()
{
    bool bFound = false;
    const tSize AllocCount = getOffset(getMaxObjectSize(), getAlignment());
    tSize i = 0;
    for( ; i < AllocCount; ++i )
    {
        if( m_pPool[i].trimEmptyChunk() )
        {
            bFound = true;
        }
    }
    for( i = 0; i < AllocCount; ++i )
    {
        if( m_pPool[i].trimChunkList() )
        {
            bFound = true;
        }
    }
    return bFound;
}


void *CSmallObjectAllocator::allocate(tSize NumBytes)
{
    if( NumBytes > getMaxObjectSize() )
    {
        void *p = malloc(NumBytes);
        if( !p )
        {
            throw std::bad_alloc();
        }
        return p;
    }

    MDS_ASSERT(m_pPool);
    if( NumBytes == 0 )
    {
        NumBytes = 1;
    }

    const tSize Index = getOffset(NumBytes, getAlignment()) - 1;
    const tSize AllocCount = getOffset(getMaxObjectSize(), getAlignment());
    (void)AllocCount;
    MDS_ASSERT(Index < AllocCount);

    CFixedAllocator &Allocator = m_pPool[Index];
    MDS_ASSERT(Allocator.getBlockSize() >= NumBytes);
    MDS_ASSERT(Allocator.getBlockSize() < NumBytes + getAlignment());
    void *pPlace = Allocator.allocate();

    if( !pPlace && trimExcessMemory() )
    {
        pPlace = Allocator.allocate();
    }
    if( !pPlace )
    {
        throw std::bad_alloc();
    }

    return pPlace;
}


void CSmallObjectAllocator::deallocate(void *p, tSize NumBytes)
{
    if( !p )
    {
        return;
    }

    if( NumBytes > getMaxObjectSize() )
    {
        free(p);
        return;
    }

    MDS_ASSERT(m_pPool);
    if( NumBytes == 0 )
    {
        NumBytes = 1;
    }

    const tSize Index = getOffset(NumBytes, getAlignment()) - 1;
    const tSize AllocCount = getOffset(getMaxObjectSize(), getAlignment());
    (void)AllocCount;
    MDS_ASSERT(Index < AllocCount);

    CFixedAllocator &Allocator = m_pPool[Index];
    MDS_ASSERT(Allocator.getBlockSize() >= NumBytes);
    MDS_ASSERT(Allocator.getBlockSize() < NumBytes + getAlignment());

    const bool bFound = Allocator.deallocate(p, NULL);
    (void)bFound;
    MDS_ASSERT(bFound);
}


} // namespace base
} // namespace mds

