//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2008-2009 by Radek Barton      \n
 *
 * Author:  Radek Barton, ibarton@fit.vutbr.cz  \n
 * Date:    2008/11/10                          \n
 *
 * $Id: mdsGZipCompressor.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Channel compression tools with gzip compression.
 */

#ifndef MDS_GZIPCOMPRESSOR_H
#define MDS_GZIPCOMPRESSOR_H

#include "mdsCompressor.h"

//#include <MDSTk/Base/mdsData.h>
#include <MDSTk/Base/mdsStaticData.h>

#include <zlib.h>


namespace mds
{
namespace mod
{

//==============================================================================
/*!
 * Class providing gzip compression.
 */
class MDS_MODULE_EXPORT CGZipCompressor : public CChannelCompressor
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CGZipCompressor);

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
    virtual int read(char * data, int length);

    //! Writes compressed data to the output channel.
    virtual bool write(const char * data, int length);

    //! Finalizes all writing operations (flushes internal buffers, etc.).
    virtual bool flush();

protected:
    //! Internal buffer size.
//    enum { BUFFER_SIZE = 64 * 1024 };
    enum { BUFFER_SIZE = 4 * 1024 };

    //! Storage used by internal buffers.
    typedef mds::base::CStaticData<char, BUFFER_SIZE> tData;

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
} // namespace mds

#endif // MDS_GZIPCOMPRESSOR_H
