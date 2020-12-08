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
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2009 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/23                       
 *
 * Description:
 * - RLE channel compression tools.
 */

#include <VPL/Module/RLECompressor.h>

#include <VPL/System/Memory.h>
#include <VPL/Math/Base.h>


namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Methods of the class vpl::mod::CRLE8Compression.
 */
CRLE8Compressor::CRLE8Compressor(CChannel *pChannel)
    : CChannelCompressor(CC_RLE8, pChannel)
    , m_iNumOfUnreadBytes(0)
{
}


CRLE8Compressor::~CRLE8Compressor()
{
    this->flush();
}


tSize CRLE8Compressor::read(char *pcData, tSize iLength)
{
    VPL_CHECK((m_Type & CH_IN) && pcData && iLength > 0, return 0);

    tLock Lock(*this);

    // The number of bytes to read
    tSize iCount = iLength;

    // All data can be found in the internal buffer
    if( m_iNumOfUnreadBytes >= iLength )
    {
        if( *m_pcBuffer & 0x80 )
        {
            vpl::sys::memSet(pcData, *(m_pcBuffer + 1), iLength);
        }
        else
        {
            tSize iResult = m_spChannel->read(pcData, iLength);
            if( iResult < iLength )
            {
                m_iNumOfUnreadBytes -= iResult;
                return iResult;
            }
        }

        m_iNumOfUnreadBytes -= iLength;
        return iLength;
    }

    // Part of required data can be found in the buffer
    else if ( m_iNumOfUnreadBytes > 0 )
    {
        if( *m_pcBuffer & 0x80 )
        {
            vpl::sys::memSet(pcData, *(m_pcBuffer + 1), m_iNumOfUnreadBytes);
        }
        else
        {
            tSize iResult = m_spChannel->read(pcData, m_iNumOfUnreadBytes);
            if( iResult < m_iNumOfUnreadBytes )
            {
                m_iNumOfUnreadBytes -= iResult;
                return iResult;
            }
        }

        iCount -= m_iNumOfUnreadBytes;
        pcData += m_iNumOfUnreadBytes;
        m_iNumOfUnreadBytes = 0;
    }

    // Read and uncompress the data
    while( iCount > 0 )
    {
        if( m_spChannel->read(m_pcBuffer, 2) != 2 )
        {
            return (iLength - iCount);
        }

        tSize iBlockSize = tSize(*m_pcBuffer & 0x7F);
        tSize iSize = vpl::math::getMin(iBlockSize, iCount);
        m_iNumOfUnreadBytes = iBlockSize - iSize;

        if( *m_pcBuffer & 0x80 )
        {
            vpl::sys::memSet(pcData, *(m_pcBuffer + 1), iSize);
        }
        else
        {
            *pcData = *(m_pcBuffer + 1);
            tSize iResult = m_spChannel->read(pcData + 1, iSize - 1);
            if( iResult < iSize - 1 )
            {
                m_iNumOfUnreadBytes = iBlockSize - iResult - 1;
                return (iCount + iResult + 1);
            }
        }

        iCount -= iSize;
        pcData += iSize;
    }

    return iLength;
}

//#undef assert
//#define assert(x) { if(!(x)) abort(); }

// output is
// 0x80 + cnt | char - when char repeats cnt times (up to 127x)
// cnt | char1 | char2 | char3 | ... - for a sequence of uncompressed cnt chars (up to 127x)
bool CRLE8Compressor::write(const char *pcData, tSize iLength)
{
    VPL_CHECK((m_Type & CH_OUT) && pcData && iLength >= 0, return false);

    tLock Lock(*this);
    
    if (1) // new more effective and faster implementation
    {
        #define MAX_REPEAT  0x7f // max length of rle sequence
        
        unsigned char* acSource = (unsigned char *)pcData;
        unsigned char* acDest = (unsigned char *)m_pWriteBuffer;
        unsigned int iPrevious = *acSource;
        acSource++;
        unsigned int iRep = 0;
        unsigned char* pUncomp = nullptr;
        while ((acSource - (unsigned char *)pcData) < iLength)
        {
            unsigned int iActual = *acSource;
            acSource++;
            // iPrevious and iActual were not written yet

            // iPrevious has to be written
            if (iActual != iPrevious) // start/continue with sequence of uncompressed
            {
                if (nullptr != pUncomp) // continue with uncompressed
                {
                    *acDest = iPrevious;
                    acDest++;
                    if (acDest - pUncomp - 1 == MAX_REPEAT) // reached maximum sequence len? save 
                    {
                        assert(0 == iRep);
                        *pUncomp = acDest - pUncomp - 1; // update count of uncompressed bytes
                        pUncomp = nullptr;

                        // save to channel when buffer is "full" (there's extra space for MAX_REPEAT+1)
                        if (acDest - m_pWriteBuffer >= WRITE_TRIGGER)
                        {
                            if (!m_spChannel->write((char*)m_pWriteBuffer, acDest - m_pWriteBuffer))
                                return false;
                            acDest = m_pWriteBuffer;
                        }
                    }
                }
                else
                {
                    if (iRep>0) // finish compressed sequence
                    {
                        /*if (iRep<2) // when the repeat count is low handle it as uncompressed
                        {
                            iRep++;
                            pUncomp = acDest;
                            acDest++;
                            for (int i = 0; i < iRep; i++)
                            {
                                *acDest = iPrevious;
                                acDest++;
                            }
                            iRep = 0;
                        }
                        else*/
                        {
                            iRep++;
                            assert(iRep <= MAX_REPEAT);
                            *acDest = (char)iRep | 0x80;
                            acDest++;
                            *acDest = iPrevious;
                            acDest++;
                            iRep = 0;

                            // save to channel when buffer is "full" (there's extra space for MAX_REPEAT+1)
                            if (acDest - m_pWriteBuffer >= WRITE_TRIGGER)
                            {
                                if (!m_spChannel->write((char*)m_pWriteBuffer, acDest - m_pWriteBuffer))
                                    return false;
                                acDest = m_pWriteBuffer;
                            }
                        }
                    }
                    else // start a new uncompressed sequence
                    {
                        pUncomp = acDest;
                        acDest++;
                        *acDest = iPrevious;
                        acDest++;                        
                    }
                }
                iPrevious = iActual; // prepare for next loop
            }
            else // they do match
            {
                if (nullptr != pUncomp) // finish any existing uncompressed sequence
                {
                    assert(0 == iRep);
                    *pUncomp = acDest - pUncomp - 1; // update count of uncompressed bytes
                    assert(*pUncomp > 0 && *pUncomp <= MAX_REPEAT);
                    pUncomp = nullptr;

                    // save to channel when buffer is "full" (there's extra space for MAX_REPEAT+1)
                    if (acDest - m_pWriteBuffer >= WRITE_TRIGGER)
                    {
                        if (!m_spChannel->write((char*)m_pWriteBuffer, acDest - m_pWriteBuffer))
                            return false;
                        acDest = m_pWriteBuffer;
                    }
                }
                assert(iRep < MAX_REPEAT);
                iRep++; // encode via repeat
                if (iRep == MAX_REPEAT) // dump to output
                {
                    *acDest = (char)iRep | 0x80;
                    acDest++;
                    *acDest = iPrevious;
                    acDest++;
                    iRep = 0;

                    // save to channel when buffer is "full" (there's extra space for MAX_REPEAT+1)
                    if (acDest - m_pWriteBuffer >= WRITE_TRIGGER)
                    {
                        if (!m_spChannel->write((char*)m_pWriteBuffer, acDest - m_pWriteBuffer))
                            return false;
                        acDest = m_pWriteBuffer;
                    }
                }
                iPrevious = iActual;
            }
        } 

        // contents of iPrevious was not written yet, add it and write any pending data

        if (iRep > 0) // finish compressed sequence
        {
            iRep++;
            assert(nullptr == pUncomp);
            assert(iRep <= MAX_REPEAT);
            *acDest = (char)iRep | 0x80;
            acDest++;
            *acDest = iPrevious;
            acDest++;
            iRep = 0;
        }
        else
        if (nullptr != pUncomp) // finish any existing uncompressed sequence
        {
            assert(0 == iRep);
            *acDest = iPrevious; // add pending entry
            acDest++;
            *pUncomp = acDest - pUncomp - 1; // update count of uncompressed bytes
            assert(*pUncomp > 0 && *pUncomp <= MAX_REPEAT);
            pUncomp = nullptr;
        }
        else // single remaining char - uncompressed
        {
            *acDest = 0x1;
            acDest++;
            *acDest = iPrevious;
            acDest++;
        }

        // write to channel rest of the buffer
        return m_spChannel->write((char*)m_pWriteBuffer, acDest - m_pWriteBuffer);
    }

    // older implementation
    EState eState = S_BEGIN;
    tSize iCount = 0;

    for( tSize i = 0; i < iLength; ++i )
    {
        char Byte = *(pcData + i);

        switch( eState )
        {
            case S_BEGIN:
                eState = S_FIRST;
                *(m_pcBuffer + 1) = Byte;
                break;

            case S_FIRST:
                if( Byte == *(m_pcBuffer + 1) )
                {
                    eState = S_COMPRESSIBLE;
                    iCount = 2;
                }
                else
                {
                    eState = S_UNCOMPRESSIBLE;
                    *(m_pcBuffer + 2) = Byte;
                    iCount = 2;
                }
                break;

            case S_COMPRESSIBLE:
                if( Byte == *(m_pcBuffer + 1) && iCount < BUFFER_SIZE )
                {
                    ++iCount;
                }
                else
                {
                    *m_pcBuffer = (char)iCount | 0x80;
                    if( !m_spChannel->write(m_pcBuffer, 2) )
                    {
                        return false;
                    }
                    eState = S_FIRST;
                    *(m_pcBuffer + 1) = Byte;
                }
                break;

            case S_UNCOMPRESSIBLE:
                if( Byte != *(m_pcBuffer + iCount) && iCount < BUFFER_SIZE )
                {
                    ++iCount;
                    *(m_pcBuffer + iCount) = Byte;
                }
                else
                {
                    *m_pcBuffer = (char)iCount;
                    if( !m_spChannel->write(m_pcBuffer, iCount + 1) )
                    {
                        return false;
                    }
                    eState = S_FIRST;
                    *(m_pcBuffer + 1) = Byte;
                }
                break;
        }
    }

    switch( eState )
    {
        case S_FIRST:
            *m_pcBuffer = 0x01;
            return m_spChannel->write(m_pcBuffer, 2);
            break;

        case S_COMPRESSIBLE:
            *m_pcBuffer = char(iCount) | 0x80;
            return m_spChannel->write(m_pcBuffer, 2);
            break;

        case S_UNCOMPRESSIBLE:
            *m_pcBuffer = char(iCount);
            return m_spChannel->write(m_pcBuffer, iCount + 1);
            break;

        default:
            break;
    }

    // O.K.
    return true;
}


//==============================================================================
/*
 * Methods of the class vpl::mod::CRLE16Compression.
 */
CRLE16Compressor::CRLE16Compressor(CChannel *pChannel)
    : CChannelCompressor(CC_RLE16, pChannel)
    , m_iNumOfUnreadBytes(0)
{
}


CRLE16Compressor::~CRLE16Compressor()
{
    this->flush();
}


tSize CRLE16Compressor::read(char *pcData, tSize iLength)
{
    VPL_CHECK((m_Type & CH_IN) && pcData && iLength > 0 && (iLength % 2) == 0, return 0);

    tLock Lock(*this);

    // The number of words to read
    tSize iCount = iLength >> 1;

    // Pointers to the data
    vpl::sys::tUInt16 *pu16Data = (vpl::sys::tUInt16 *)pcData;
    vpl::sys::tUInt16 *pu16Buffer = (vpl::sys::tUInt16 *)(m_pcBuffer + 1);

    // All data can be found in the internal buffer
    if( m_iNumOfUnreadBytes >= iLength )
    {
        if( *m_pcBuffer & 0x80 )
        {
            vpl::sys::memSet(pu16Data, *pu16Buffer, iLength >> 1);
        }
        else
        {
            tSize iResult = m_spChannel->read(pcData, iLength);
            if( iResult < iLength )
            {
                m_iNumOfUnreadBytes -= iResult;
                return iResult;
            }
        }

        m_iNumOfUnreadBytes -= iLength;
        return iLength;
    }

    // Part of required data can be found in the buffer
    else if ( m_iNumOfUnreadBytes > 0 )
    {
        VPL_ASSERT(m_iNumOfUnreadBytes % 2 == 0);
        tSize iNumOfUnreadWords = m_iNumOfUnreadBytes >> 1;

        if( *m_pcBuffer & 0x80 )
        {
            vpl::sys::memSet(pu16Data, *pu16Buffer, iNumOfUnreadWords);
        }
        else
        {
            tSize iResult = m_spChannel->read(pcData, m_iNumOfUnreadBytes);
            if( iResult < m_iNumOfUnreadBytes )
            {
                m_iNumOfUnreadBytes -= iResult;
                return iResult;
            }
        }

        iCount -= iNumOfUnreadWords;
        pu16Data += iNumOfUnreadWords;
        m_iNumOfUnreadBytes = 0;
    }

    // Read and uncompress the data
    while( iCount > 0 )
    {
        if( m_spChannel->read(m_pcBuffer, 3) != 3 )
        {
            return (iLength - iCount);
        }

        tSize iBlockSize = tSize(*m_pcBuffer & 0x7F);
        tSize iSize = vpl::math::getMin(iBlockSize, iCount);
        m_iNumOfUnreadBytes = (iBlockSize - iSize) << 1;

        if( *m_pcBuffer & 0x80 )
        {
            vpl::sys::memSet(pu16Data, *pu16Buffer, iSize);
        }
        else
        {
            *pu16Data = *pu16Buffer;
            tSize iTemp = (iSize - 1) << 1;
            tSize iResult = m_spChannel->read((char *)(pu16Data + 1), iTemp);
            if( iResult < iTemp )
            {
                m_iNumOfUnreadBytes = (iBlockSize << 1) - iResult - 2;
                return (iCount << 1) + iResult + 2;
            }
        }

        iCount -= iSize;
        pu16Data += iSize;
    }

    return iLength;
}


bool CRLE16Compressor::write(const char *pcData, tSize iLength)
{
    VPL_CHECK((m_Type & CH_OUT) && pcData && iLength >= 0 && (iLength % 2) == 0, return false);

    tLock Lock(*this);

    // The number of bytes to write
    tSize iWordLength = iLength >> 1;

    // Pointer to the data
    vpl::sys::tUInt16 *pu16Data = (vpl::sys::tUInt16 *)pcData;
    vpl::sys::tUInt16 *pu16Buffer = (vpl::sys::tUInt16 *)(m_pcBuffer + 1);

    EState eState = S_BEGIN;
    int iCount = 0;

    for( tSize i = 0; i < iWordLength; ++i )
    {
        vpl::sys::tUInt16 Word = *(pu16Data + i);

        switch( eState )
        {
            case S_BEGIN:
                eState = S_FIRST;
                *pu16Buffer = Word;
                break;

            case S_FIRST:
                if( Word == *pu16Buffer )
                {
                    eState = S_COMPRESSIBLE;
                    iCount = 2;
                }
                else
                {
                    eState = S_UNCOMPRESSIBLE;
                    *(pu16Buffer + 1) = Word;
                    iCount = 2;
                }
                break;

            case S_COMPRESSIBLE:
                if( Word == *pu16Buffer && iCount < BUFFER_SIZE )
                {
                    ++iCount;
                }
                else
                {
                    *m_pcBuffer = (char)iCount | 0x80;
                    if( !m_spChannel->write(m_pcBuffer, 3) )
                    {
                        return false;
                    }
                    eState = S_FIRST;
                    *pu16Buffer = Word;
                }
                break;

            case S_UNCOMPRESSIBLE:
                if( Word != *(pu16Buffer + iCount - 1) && iCount < BUFFER_SIZE )
                {
                    ++iCount;
                    *(pu16Buffer + iCount - 1) = Word;
                }
                else
                {
                    *m_pcBuffer = (char)iCount;
                    if( !m_spChannel->write(m_pcBuffer, (iCount << 1) + 1) )
                    {
                        return false;
                    }
                    eState = S_FIRST;
                    *pu16Buffer = Word;
                }
                break;
        }
    }

    switch( eState )
    {
        case S_FIRST:
            *m_pcBuffer = 0x01;
            return m_spChannel->write(m_pcBuffer, 3);
            break;

        case S_COMPRESSIBLE:
            *m_pcBuffer = (char)iCount | 0x80;
            return m_spChannel->write(m_pcBuffer, 3);
            break;

        case S_UNCOMPRESSIBLE:
            *m_pcBuffer = (char)iCount;
            return m_spChannel->write(m_pcBuffer, (iCount << 1) + 1);
            break;

        default:
            break;
    }

    // O.K.
    return true;
}


} // namespace mod
} // namespace vpl

