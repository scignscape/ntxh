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
 * Date:    2009/03/27                       
 *
 * Description:
 * - RLE compression tools.
 */

#ifndef VPL_RLECompressor_H
#define VPL_RLECompressor_H

#include "Compressor.h"

// STL
#include <string>


namespace vpl
{
namespace mod
{

//==============================================================================
/*!
 * Class providing 8-bit RLE compression.
 */
class VPL_MODULE_EXPORT CRLE8Compressor : public CChannelCompressor
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CRLE8Compressor);

public:
    //! Constructor.
    CRLE8Compressor(CChannel *pChannel = NULL);

    //! Destructor.
    virtual ~CRLE8Compressor();

    // Virtual methods.
    virtual tSize read(char *pcData, tSize iLength) override;
	virtual bool write(const char *pcData, tSize iLength) override;

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
    tSize m_iNumOfUnreadBytes;


    //! Write buffer for the new implementation
    #define WRITE_TRIGGER   256
    unsigned char m_pWriteBuffer[WRITE_TRIGGER + 128]; // buffer has space for one extra sequence
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
class VPL_MODULE_EXPORT CRLE16Compressor : public CChannelCompressor
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CRLE16Compressor);

public:
    //! Constructor.
    CRLE16Compressor(CChannel *pChannel = NULL);

    //! Destructor.
    virtual ~CRLE16Compressor();

    // Virtual methods.
	virtual tSize read(char *pcData, tSize iLength) override;
	virtual bool write(const char *pcData, tSize iLength) override;

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
    tSize m_iNumOfUnreadBytes;
};


//==============================================================================
/*!
 * Smart pointer to the 16-bit RLE compressor.
 */
typedef CRLE16Compressor::tSmartPtr    CRLE16CompressorPtr;


} // namespace mod
} // namespace vpl

#endif // VPL_RLECompressor_H

