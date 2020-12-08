//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/27                          \n
 *
 * $Id: mdsRLECompressor.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - RLE compression tools.
 */

#ifndef MDS_RLECompressor_H
#define MDS_RLECompressor_H

#include "mdsCompressor.h"

// STL
#include <string>


namespace mds
{
namespace mod
{

//==============================================================================
/*!
 * Class providing 8-bit RLE compression.
 */
class MDS_MODULE_EXPORT CRLE8Compressor : public CChannelCompressor
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CRLE8Compressor);

public:
    //! Constructor.
    CRLE8Compressor(CChannel *pChannel = NULL);

    //! Destructor.
    virtual ~CRLE8Compressor();

    // Virtual methods.
    virtual int read(char *pcData, int iLength);
    virtual bool write(const char *pcData, int iLength);

protected:
    //! Size of the internal buffer.
    enum { BUFFER_SIZE = 0x7F };

    //! RLE compressor states.
    enum EState
    {
        S_BEGIN, S_FIRST, S_COMPRESSIBLE, S_UNCOMPRESSIBLE
    };

    //! Helper buffer of data bytes.
    char m_pcBuffer[BUFFER_SIZE + 1];

    //! The number of remaining unread bytes in the last block.
    int m_iNumOfUnreadBytes;
};


//==============================================================================
/*!
 * Smart pointer to 8-bit RLE compressor.
 */
typedef CRLE8Compressor::tSmartPtr     CRLE8CompressorPtr;


//==============================================================================
/*!
 * Class providing 16-bit RLE compression.
 */
class MDS_MODULE_EXPORT CRLE16Compressor : public CChannelCompressor
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CRLE16Compressor);

public:
    //! Constructor.
    CRLE16Compressor(CChannel *pChannel = NULL);

    //! Destructor.
    virtual ~CRLE16Compressor();

    // Virtual methods.
    virtual int read(char *pcData, int iLength);
    virtual bool write(const char *pcData, int iLength);

protected:
    //! Size of the internal buffer.
    enum { BUFFER_SIZE = 0x7F };

    //! RLE compressor states.
    enum EState
    {
        S_BEGIN, S_FIRST, S_COMPRESSIBLE, S_UNCOMPRESSIBLE
    };

    //! Helper array of data bytes.
    char m_pcBuffer[2 * BUFFER_SIZE + 1];

    //! The number of remaining unread words in the last block.
    int m_iNumOfUnreadBytes;
};


//==============================================================================
/*!
 * Smart pointer to the 16-bit RLE compressor.
 */
typedef CRLE16Compressor::tSmartPtr    CRLE16CompressorPtr;


} // namespace mod
} // namespace mds

#endif // MDS_RLECompressor_H

