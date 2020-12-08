//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/23                          \n
 *
 * $Id: mdsRLECompressor.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - RLE channel compression tools.
 */

#include <MDSTk/Module/mdsRLECompressor.h>

#include <MDSTk/Base/mdsMemory.h>
#include <MDSTk/Math/mdsBase.h>


namespace mds
{
namespace mod
{

//==============================================================================
/*
 * Methods of the class mds::mod::CRLE8Compression.
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


int CRLE8Compressor::read(char *pcData, int iLength)
{
    MDS_CHECK((m_Type & CH_IN) && pcData && iLength > 0, return 0);

    tLock Lock(*this);

    // The number of bytes to read
    int iCount = iLength;

    // All data can be found in the internal buffer
    if( m_iNumOfUnreadBytes >= iLength )
    {
        if( *m_pcBuffer & 0x80 )
        {
            mds::base::memSet(pcData, *(m_pcBuffer + 1), iLength);
        }
        else
        {
            int iResult = m_spChannel->read(pcData, iLength);
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
            mds::base::memSet(pcData, *(m_pcBuffer + 1), m_iNumOfUnreadBytes);
        }
        else
        {
            int iResult = m_spChannel->read(pcData, m_iNumOfUnreadBytes);
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

        int iBlockSize = (int)(*m_pcBuffer & 0x7F);
        int iSize = mds::math::getMin(iBlockSize, iCount);
        m_iNumOfUnreadBytes = iBlockSize - iSize;

        if( *m_pcBuffer & 0x80 )
        {
            mds::base::memSet(pcData, *(m_pcBuffer + 1), iSize);
        }
        else
        {
            *pcData = *(m_pcBuffer + 1);
            int iResult = m_spChannel->read(pcData + 1, iSize - 1);
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


bool CRLE8Compressor::write(const char *pcData, int iLength)
{
    MDS_CHECK((m_Type & CH_OUT) && pcData && iLength >= 0, return false);

    tLock Lock(*this);

    EState eState = S_BEGIN;
    int iCount = 0;

    for( int i = 0; i < iLength; ++i )
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
 * Methods of the class mds::mod::CRLE16Compression.
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


int CRLE16Compressor::read(char *pcData, int iLength)
{
    MDS_CHECK((m_Type & CH_IN) && pcData && iLength > 0 && (iLength % 2) == 0, return 0);

    tLock Lock(*this);

    // The number of words to read
    int iCount = iLength >> 1;

    // Pointers to the data
    mds::sys::tUInt16 *pu16Data = (mds::sys::tUInt16 *)pcData;
    mds::sys::tUInt16 *pu16Buffer = (mds::sys::tUInt16 *)(m_pcBuffer + 1);

    // All data can be found in the internal buffer
    if( m_iNumOfUnreadBytes >= iLength )
    {
        if( *m_pcBuffer & 0x80 )
        {
            mds::base::memSet(pu16Data, *pu16Buffer, iLength >> 1);
        }
        else
        {
            int iResult = m_spChannel->read(pcData, iLength);
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
        MDS_ASSERT(m_iNumOfUnreadBytes % 2 == 0);
        int iNumOfUnreadWords = m_iNumOfUnreadBytes >> 1;

        if( *m_pcBuffer & 0x80 )
        {
            mds::base::memSet(pu16Data, *pu16Buffer, iNumOfUnreadWords);
        }
        else
        {
            int iResult = m_spChannel->read(pcData, m_iNumOfUnreadBytes);
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

        int iBlockSize = (int)(*m_pcBuffer & 0x7F);
        int iSize = mds::math::getMin(iBlockSize, iCount);
        m_iNumOfUnreadBytes = (iBlockSize - iSize) << 1;

        if( *m_pcBuffer & 0x80 )
        {
            mds::base::memSet(pu16Data, *pu16Buffer, iSize);
        }
        else
        {
            *pu16Data = *pu16Buffer;
            int iTemp = (iSize - 1) << 1;
            int iResult = m_spChannel->read((char *)(pu16Data + 1), iTemp);
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


bool CRLE16Compressor::write(const char *pcData, int iLength)
{
    MDS_CHECK((m_Type & CH_OUT) && pcData && iLength >= 0 && (iLength % 2) == 0, return false);

    tLock Lock(*this);

    // The number of bytes to write
    int iWordLength = iLength >> 1;

    // Pointer to the data
    mds::sys::tUInt16 *pu16Data = (mds::sys::tUInt16 *)pcData;
    mds::sys::tUInt16 *pu16Buffer = (mds::sys::tUInt16 *)(m_pcBuffer + 1);

    EState eState = S_BEGIN;
    int iCount = 0;

    for( int i = 0; i < iWordLength; ++i )
    {
        mds::sys::tUInt16 Word = *(pu16Data + i);

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
} // namespace mds

