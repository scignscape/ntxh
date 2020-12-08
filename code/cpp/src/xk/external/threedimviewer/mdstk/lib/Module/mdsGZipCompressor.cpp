//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2008-2008 by Radek Barton      \n
 *
 * Author:  Radek Barton, ibarton@fit.vutbr.cz  \n
 * Date:    2008/11/10                          \n
 *
 * $Id: mdsGZipCompressor.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Channel compression tools with gzip compression.
 */

#include <MDSTk/Module/mdsGZipCompressor.h>
#include <MDSTk/Base/mdsMemory.h>


namespace mds
{
namespace mod
{

//=============================================================================
/*
 * Implementation of the class CGZipCompressor.
 */

const unsigned int CGZipCompressor::DEFAULT_COMPRESSION_LEVEL = 6;

CGZipCompressor::CGZipCompressor(CChannel * channel, unsigned int level)
    : CChannelCompressor(CC_GZIP, channel)
    , m_decompressedTotal(0)
    , m_decompressedUsed(0)
    , m_compressionStream()
    , m_decompressionStream()
{
    int result = Z_OK;

    // Initialize write zlib stream.
    m_compressionStream.zalloc = Z_NULL;
    m_compressionStream.zfree = Z_NULL;
    m_compressionStream.opaque = Z_NULL;
    result = deflateInit(&m_compressionStream, level);

    // Check result.
    MDS_ASSERT(result == Z_OK);

    // Initialize read zlib stream.
    m_decompressionStream.zalloc = Z_NULL;
    m_decompressionStream.zfree = Z_NULL;
    m_decompressionStream.opaque = Z_NULL;
    result = inflateInit(&m_decompressionStream);

    // Check result.
    MDS_ASSERT(result == Z_OK);
}


CGZipCompressor::~CGZipCompressor()
{
    // Flush uncompressed/undecompressed data to output channel.
    this->flush();

    // Deinitialize streams.
    deflateEnd(&m_compressionStream);
    inflateEnd(&m_decompressionStream);
}


int CGZipCompressor::read(char * data, int length)
{
    // Check inputs.
    MDS_CHECK((m_Type & CH_IN) && data && (length >= 0), return false);

    // FIXME: Read and write buffer can be locked separately but it needs to
    // derive them from lockable object (char * currently).
    // Lock internal buffers.
    tLock lock(*this);

    tSize written = 0;
    int result = Z_OK;
    while( true )
    {
        // Check if there is enough decompressed data for read request.
        tSize decompressed_size = m_decompressedTotal - m_decompressedUsed;
        tSize rest = length - written;
        if( rest <= decompressed_size )
        {
            // Copy them to output.
            mds::base::memCopy<char>(data + written, m_decompressionBuffer.getPtr(m_decompressedUsed), rest);
            m_decompressedUsed += rest;
            written += rest;
            return written;
        }
        else
        {
            // Copy what we have to clean decompression buffer.
            mds::base::memCopy<char>(data + written, m_decompressionBuffer.getPtr(m_decompressedUsed), decompressed_size);
            m_decompressedUsed = 0;
            written += decompressed_size;

            // Check if everything is decompressed.
            if( m_decompressionStream.avail_in == 0 )
            {
                // Read next block from input channel.
                tSize read = m_spChannel->read(m_readBuffer.getPtr(), m_readBuffer.getSize());
                if( read != 0 )
                {
                    // Prepare stream input buffer.
                    m_decompressionStream.avail_in = uInt(read);
                    m_decompressionStream.next_in = reinterpret_cast<Bytef *>(m_readBuffer.getPtr());
                }
                else
                {
                    // Nothing to read or decompress.
                    if( result == Z_STREAM_END )
                    {
                        return written;
                    }
                }
            }

            // Decompress to buffer.
            m_decompressionStream.avail_out = uInt(BUFFER_SIZE);
            m_decompressionStream.next_out = reinterpret_cast<Bytef *>(m_decompressionBuffer.getPtr());

            // Decompress with zlib.
            result = inflate(&m_decompressionStream, Z_NO_FLUSH);
//            result = inflate(&m_decompressionStream, Z_SYNC_FLUSH);

            // Check output.
            switch( result )
            {
                case Z_STREAM_ERROR:
                case Z_NEED_DICT:
                case Z_DATA_ERROR:
                case Z_MEM_ERROR:
                {
                  // Error.
                  return written;
                }
            }

            // Now there are data in decompression buffer for next cycle.
            m_decompressedTotal = uInt(BUFFER_SIZE) - m_decompressionStream.avail_out;
            m_decompressedUsed = 0;

            if( result == Z_STREAM_END )
            {
                // Prepare for next stream.
                uInt avail_in = m_decompressionStream.avail_in;
                Bytef * next_in = m_decompressionStream.next_in;
                inflateReset(&m_decompressionStream);
                m_decompressionStream.avail_in = avail_in;
                m_decompressionStream.next_in = next_in;
            }
        }
    }
}


bool CGZipCompressor::write(const char * data, int length)
{
    // Check inputs.
    MDS_CHECK((m_Type & CH_OUT) && data && (length >= 0), return false);

    // FIXME: Read and write buffer can be locked separately but it needs to
    // derive them from lockable object (char * currently).
    // Lock internal buffers.
    tLock lock(*this);

    // Prepare stream input buffer.
    m_compressionStream.avail_in = uInt(length);
    m_compressionStream.next_in = const_cast<Bytef *>(reinterpret_cast<const Bytef *>(data));

    // Compress stream ouput buffer and write it to channel.
    while( m_compressionStream.avail_in > 0 )
    {
        // Prepare for next block compression.
        m_compressionStream.avail_out = uInt(BUFFER_SIZE);
        m_compressionStream.next_out = reinterpret_cast<Bytef *>(m_compressionBuffer.getPtr());

        // Compress with zlib.
        int result = deflate(&m_compressionStream, Z_NO_FLUSH);

        // Check result.
        switch( result )
        {
            case Z_STREAM_ERROR:
            {
                return false;
            }
        }

        // Write compressed data to output channel.
        int output_length = BUFFER_SIZE - int(m_compressionStream.avail_out);
        if( output_length > 0 )
        {
            if( !m_spChannel->write(m_compressionBuffer.getPtr(), output_length) )
            {
                return false;
            }
        }
    }

    // O.K.
    return true;
}


bool CGZipCompressor::flush()
{
    // Flush the write stream.
    if( m_Type & CH_OUT )
    {
        int output_length = 0;
        do {
            // Prepare for next block compression.
            m_compressionStream.avail_out = uInt(BUFFER_SIZE);
            m_compressionStream.next_out = reinterpret_cast<Bytef *>(m_compressionBuffer.getPtr());

            // Compress with zlib.
            int result = deflate(&m_compressionStream, Z_FINISH);
//            int result = deflate(&m_compressionStream, Z_FULL_FLUSH);

            // Check result.
            switch (result)
            {
                case Z_STREAM_ERROR:
                {
                    return false;
                }
            }

            // Write compressed data to output channel.
            output_length = BUFFER_SIZE - int(m_compressionStream.avail_out);
            if( output_length > 0 )
            {
                if( !m_spChannel->write(m_compressionBuffer.getPtr(), output_length) )
                {
                    return false;
                }
            }
        }
    //    while( m_compressionStream.avail_out == 0 );
        while( output_length > 0 );

        // Prepare for new compression.
//        deflateReset(&m_compressionStream);
    }

    if( m_Type & CH_IN )
    {
        // Prepare for new compression.
//        inflateReset(&m_decompressionStream);
    }

    // Call the parent method
    return CChannelCompressor::flush();
}


} // namespace mod
} // namespace mds

