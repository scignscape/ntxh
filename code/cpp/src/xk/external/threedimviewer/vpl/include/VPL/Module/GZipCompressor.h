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
 * Copyright (c) 2008-2009 by Radek Barton   
 *
 * Author:  Radek Barton, ibarton@fit.vutbr.cz  \n
 * Date:    2008/11/10                       
 *
 * Description:
 * - Channel compression tools with gzip compression.
 */

#ifndef VPL_GZIPCOMPRESSOR_H
#define VPL_GZIPCOMPRESSOR_H

#include "Compressor.h"

#include <VPL/Base/StaticData.h>

#include <zlib.h>


namespace vpl
{
namespace mod
{

//==============================================================================
/*!
 * Class providing gzip compression.
 */
class VPL_MODULE_EXPORT CGZipCompressor : public CChannelCompressor
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CGZipCompressor);

    //! Default compression level.
    static const unsigned int DEFAULT_COMPRESSION_LEVEL;

public:
    //! Default constructor.
    CGZipCompressor(CChannel * channel = NULL,
                    unsigned int level = DEFAULT_COMPRESSION_LEVEL
                    );

    //! Virtual destructor.
    virtual ~CGZipCompressor();

    //! Reads and decompresses data from the input channel.
    //! - In case of error or reading after end of input
    //!   the number of successfully readed bytes is returned.
    virtual tSize read(char * data, tSize length) override;

    //! Writes compressed data to the output channel.
    virtual bool write(const char * data, tSize length) override;

    //! Finalizes all writing operations (flushes internal buffers, etc.).
	virtual bool flush() override;

protected:
    //! Internal buffer size.
    enum { BUFFER_SIZE = 4 * 1024 };

    //! Storage used by internal buffers.
    typedef vpl::base::CStaticData<char, BUFFER_SIZE> tData;

protected:
    //! Internal buffers.
    tData m_compressionBuffer, m_readBuffer, m_decompressionBuffer;

    // ...
    tSize m_decompressedTotal, m_decompressedUsed;

    //! ZLib streams.
    z_stream m_compressionStream, m_decompressionStream;
};


//==============================================================================
/*!
 * Smart pointer to GZip compression channel.
 */
typedef CGZipCompressor::tSmartPtr  CGZipCompressorPtr;


} // namespace mod
} // namespace vpl

#endif // VPL_GZIPCOMPRESSOR_H
