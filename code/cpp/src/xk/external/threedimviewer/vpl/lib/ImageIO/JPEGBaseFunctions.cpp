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
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/12                          \n
 *
 * Description:
 * - Reading and writing of JPEG images.
 * - Based on libjpeg.
 */

#include <VPL/ImageIO/JPEGBaseFunctions.h>

#include <stdio.h>

// Include libjpeg header files
extern "C"
{
#include <jconfig.h>
#include <jerror.h>
#include <jpeglib.h>
}

#include <setjmp.h>

#ifdef _MSC_VER
// warning C4611: interaction between '_setjmp' and C++ object destruction is non-portable
#   pragma warning(disable : 4611)
#endif // _MSC_VER


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Global constants.
 */

//! I/O buffer size.
const size_t BUFFER_SIZE        = 4096;


//==============================================================================
/*
 * JPEG error handling functions and source manager.
 */

// Here's the extended error handler struct
struct SMyErrorMgr
{
    jpeg_error_mgr  m_Pub;
    jmp_buf         m_SetJmpBuffer;
};

typedef SMyErrorMgr *tMyErrorPtr;


// Here's the routine that will replace the standard error_exit method:
LOCAL(void)
myErrorExit(j_common_ptr pInfo)
{
    // cinfo->err really points to a SMyErrorMgr struct, so coerce pointer
    tMyErrorPtr pMyErr = (tMyErrorPtr)pInfo->err;

    // Always display the message
    // We could postpone this until after returning, if we chose
    (*pInfo->err->output_message)(pInfo);

    // Return control to the setjmp point
    longjmp(pMyErr->m_SetJmpBuffer, 1);
}


// Data pSource object for decompression
struct SMySourceMgr
{
    jpeg_source_mgr     m_Pub;
    JSAMPROW            m_IOBuffer;         // Buffer
    size_t              m_BufferWidth;      // Width of I/O buffer
    vpl::mod::CChannel  *m_pInputChannel;   // Input channel
};

typedef SMySourceMgr *tMySourcePtr;


LOCAL(void)
initSource(j_decompress_ptr pInfo)
{
    tMySourcePtr pSource = (tMySourcePtr)pInfo->src;

    // Allocate the memory
    pSource->m_IOBuffer = (JSAMPROW)(*pInfo->mem->alloc_large)((j_common_ptr)pInfo, JPOOL_IMAGE, BUFFER_SIZE * sizeof(JSAMPLE));
    pSource->m_BufferWidth = BUFFER_SIZE;
    pSource->m_Pub.next_input_byte = (JOCTET *)pSource->m_IOBuffer;
    pSource->m_Pub.bytes_in_buffer = 0;
}


LOCAL(boolean)
fillInputBuffer(j_decompress_ptr pInfo)
{
    tMySourcePtr pSource = (tMySourcePtr)pInfo->src;

    // Read data from the channel
    int iResult = pSource->m_pInputChannel->read((char *)pSource->m_IOBuffer, (int)BUFFER_SIZE * sizeof(JSAMPLE));

    // Set the buffer
    pSource->m_Pub.next_input_byte = (JOCTET *)pSource->m_IOBuffer;
    pSource->m_Pub.bytes_in_buffer = (size_t)iResult;

    // Error
    if( iResult == 0 )
    {
        *((JOCTET *)pSource->m_IOBuffer) = (JOCTET)JPEG_EOI;
        pSource->m_Pub.bytes_in_buffer = (size_t)1;
        WARNMS(pInfo, JERR_INPUT_EOF);
    }

    return TRUE;
}


LOCAL(void)
skipInputData(j_decompress_ptr pInfo, long int liNumBytes)
{
    if( liNumBytes <= 0L )
    {
        return;
    }
    tMySourcePtr pSource = (tMySourcePtr)pInfo->src;

    // Skip the data
    int iSkip, iResult;
    if( liNumBytes <= (long)pSource->m_Pub.bytes_in_buffer )
    {
        pSource->m_Pub.bytes_in_buffer -= (size_t)liNumBytes;
        pSource->m_Pub.next_input_byte += (size_t)liNumBytes;
    }
    else
    {
        iSkip = (int)liNumBytes - (int)pSource->m_Pub.bytes_in_buffer;
        pSource->m_Pub.bytes_in_buffer = 0;
        while( iSkip > 0 )
        {
            if( (iSkip - (int)BUFFER_SIZE) >= 0 )
            {
                iResult = pSource->m_pInputChannel->read((char *)pSource->m_IOBuffer, BUFFER_SIZE);
            }
            else
            {
                iResult = pSource->m_pInputChannel->read((char *)pSource->m_IOBuffer, iSkip);
            }
            iSkip -= iResult;
            if( iResult == 0 )
            {
                *((JOCTET *)pSource->m_IOBuffer) = (JOCTET)JPEG_EOI;
                pSource->m_Pub.bytes_in_buffer = (size_t)1;
                WARNMS(pInfo, JERR_INPUT_EOF);
                break;
            }
        }
    }
}


LOCAL(void)
term_source(j_decompress_ptr)
{
    // No operation
}


//==============================================================================
/*
 * Implementation of global functions.
 */
bool loadGrayJPEG(CImage8& Image, vpl::mod::CChannel& Channel)
{
    // Check libjpeg sample bitdepth
    VPL_CHECK(CPixelTraits<tPixel8>::getPixelMax() == MAXJSAMPLE, return false);

    // Check that input channel is connected
    if( !Channel.isConnected() )
    {
        return false;
    }

    // JPEG structures
    jpeg_decompress_struct pInfo;

    // Set error handler
    SMyErrorMgr JErr;
    pInfo.err = jpeg_std_error(&JErr.m_Pub);
    JErr.m_Pub.error_exit = myErrorExit;

    // Establish the setjmp return context for myErrorExit to use
    if( setjmp(JErr.m_SetJmpBuffer) )
    {
        // If we get here, the JPEG code has signaled an error
        // We need to clean up the JPEG object, close the input file, and return
        jpeg_destroy_decompress(&pInfo);
        return false;
    }

    // Create decompression object
    jpeg_create_decompress(&pInfo);

    // Create data pSource manager
    tMySourcePtr pSource = (tMySourcePtr)(*pInfo.mem->alloc_small)((j_common_ptr)&pInfo, JPOOL_IMAGE, sizeof(SMySourceMgr));

    // Initialize the pSource manager
    pSource->m_pInputChannel = &Channel;
    pSource->m_Pub.init_source = initSource;
    pSource->m_Pub.fill_input_buffer = fillInputBuffer;
    pSource->m_Pub.skip_input_data = skipInputData;
    pSource->m_Pub.term_source = term_source;
    pSource->m_Pub.resync_to_restart = jpeg_resync_to_restart;
    pInfo.src = (jpeg_source_mgr *)pSource;

    // Read file parameters with jpeg_read_header()
    jpeg_read_header(&pInfo, TRUE);

    // Set the output colorspace
    pInfo.out_color_space = JCS_GRAYSCALE;
    jpeg_calc_output_dimensions(&pInfo);

    // Start decompressor
    jpeg_start_decompress(&pInfo);

    // Recreate the slice of appropriate size
    Image.resize((tSize)pInfo.output_width,
                 (tSize)pInfo.output_height,
                 Image.getMargin()
                 );
    Image.fillEntire(0);

    // JSAMPLEs per row in output buffer
    int iRowStride = pInfo.output_width * pInfo.output_components;

    // Make a one-row-high sample array that will go away when done with image
    JSAMPARRAY pBuffer = (*pInfo.mem->alloc_sarray)((j_common_ptr)&pInfo, JPOOL_IMAGE, iRowStride, 1);

    // Read the JPEG image data
    for( tSize j = 0; pInfo.output_scanline < pInfo.output_height; ++j )
    {
        // jpeg_read_scanlines expects an array of pointers to scanlines.
        // Here the array is only one element long, but you could ask for
        // more than one scanline at a time if that's more convenient.
        jpeg_read_scanlines(&pInfo, pBuffer, 1);

        // Convert the JPEG image data
        JSAMPLE *p = pBuffer[0];
        for( tSize i = 0; i < (tSize)pInfo.output_width; ++i )
        {
            Image(i,j) = tPixel8(*p++);
        }
    }

    // Finish decompression
    jpeg_finish_decompress(&pInfo);

    // Release JPEG decompression object
    // This is an important step since it will release a good deal of memory
    jpeg_destroy_decompress(&pInfo);

    // Check to see whether any corrupt-data warnings occurred
    return (JErr.m_Pub.num_warnings == 0);
}


bool loadColorJPEG(CRGBImage& Image, vpl::mod::CChannel& Channel)
{
    VPL_CHECK(MAXJSAMPLE == 255, return false);

    // Check that input channel is connected
    if( !Channel.isConnected() )
    {
        return false;
    }

    // JPEG structures
    jpeg_decompress_struct pInfo;

    // Set error handler
    SMyErrorMgr JErr;
    pInfo.err = jpeg_std_error(&JErr.m_Pub);
    JErr.m_Pub.error_exit = myErrorExit;

    // Establish the setjmp return context for myErrorExit to use
    if( setjmp(JErr.m_SetJmpBuffer) )
    {
        // If we get here, the JPEG code has signaled an error
        // We need to clean up the JPEG object, close the input file, and return
        jpeg_destroy_decompress(&pInfo);
        return false;
    }

    // Create decompression object
    jpeg_create_decompress(&pInfo);

    // Create data pSource manager
    tMySourcePtr pSource = (tMySourcePtr)(*pInfo.mem->alloc_small)((j_common_ptr)&pInfo, JPOOL_IMAGE, sizeof(SMySourceMgr));

    // Initialize the pSource manager
    pSource->m_pInputChannel = &Channel;
    pSource->m_Pub.init_source = initSource;
    pSource->m_Pub.fill_input_buffer = fillInputBuffer;
    pSource->m_Pub.skip_input_data = skipInputData;
    pSource->m_Pub.term_source = term_source;
    pSource->m_Pub.resync_to_restart = jpeg_resync_to_restart;
    pInfo.src = (jpeg_source_mgr *)pSource;

    // Read file parameters with jpeg_read_header()
    jpeg_read_header(&pInfo, TRUE);

    // Set the output colorspace
    pInfo.out_color_space = JCS_RGB;
    jpeg_calc_output_dimensions(&pInfo);

    // Start decompressor
    jpeg_start_decompress(&pInfo);

    // Recreate the slice of appropriate size
    Image.resize((tSize)pInfo.output_width,
                 (tSize)pInfo.output_height,
                 Image.getMargin()
                 );
    Image.fillEntire(tRGBPixel(0, 0, 0));

    // JSAMPLEs per row in output buffer
    int iRowStride = pInfo.output_width * pInfo.output_components;

    // Make a one-row-high sample array that will go away when done with image
    JSAMPARRAY pBuffer = (*pInfo.mem->alloc_sarray)((j_common_ptr)&pInfo, JPOOL_IMAGE, iRowStride, 1);

    // Read the JPEG image data
    tRGBPixel::tComponent r, g, b;
    for( tSize j = 0; pInfo.output_scanline < pInfo.output_height; ++j )
    {
        // jpeg_read_scanlines expects an array of pointers to scanlines.
        // Here the array is only one element long, but you could ask for
        // more than one scanline at a time if that's more convenient.
        jpeg_read_scanlines(&pInfo, pBuffer, 1);

        // Convert the JPEG image data
        JSAMPLE *p = pBuffer[0];
        for( tSize i = 0; i < (tSize)pInfo.output_width; ++i )
        {
            r = tRGBPixel::tComponent(*p++);
            g = tRGBPixel::tComponent(*p++);
            b = tRGBPixel::tComponent(*p++);
            Image(i,j) = tRGBPixel(r, g, b);
        }
    }

    // Finish decompression
    jpeg_finish_decompress(&pInfo);

    // Release JPEG decompression object
    // This is an important step since it will release a good deal of memory
    jpeg_destroy_decompress(&pInfo);

    // Check to see whether any corrupt-data warnings occurred
    return (JErr.m_Pub.num_warnings == 0);
}


//==============================================================================
/*
 * JPEG destination manager.
 */

// Data destination object for compression
struct SMyDestinationMgr
{
    jpeg_destination_mgr    m_Pub;
    JSAMPROW                m_IOBuffer;            // Buffer
    size_t                  m_BufferWidth;         // Width of I/O pBuffer
    vpl::mod::CChannel      *m_pOutputChannel;     // Input channel
};

typedef SMyDestinationMgr *tMyDestinationPtr;


LOCAL(void)
initDestination(j_compress_ptr pInfo)
{
    tMyDestinationPtr pDestination = (tMyDestinationPtr)pInfo->dest;

    // Allocate the memory
    pDestination->m_IOBuffer = (JSAMPROW)(*pInfo->mem->alloc_large)((j_common_ptr)pInfo, JPOOL_IMAGE, BUFFER_SIZE * sizeof(JSAMPLE));
    pDestination->m_BufferWidth = BUFFER_SIZE;
    pDestination->m_Pub.next_output_byte = (JOCTET *)pDestination->m_IOBuffer;
    pDestination->m_Pub.free_in_buffer = BUFFER_SIZE * sizeof(JSAMPLE);
}


LOCAL(boolean)
emptyOutputBuffer(j_compress_ptr pInfo)
{
    tMyDestinationPtr pDestination = (tMyDestinationPtr)pInfo->dest;

    // Write data to the channel
    bool iResult = pDestination->m_pOutputChannel->write((char *)pDestination->m_IOBuffer, (int)BUFFER_SIZE * sizeof(JSAMPLE));

    // Set the pBuffer
    pDestination->m_Pub.next_output_byte = (JOCTET *)pDestination->m_IOBuffer;
    pDestination->m_Pub.free_in_buffer = BUFFER_SIZE * sizeof(JSAMPLE);

    // Error
    if( !iResult )
    {
        WARNMS(pInfo, JERR_FILE_WRITE);
    }

    return TRUE;
}


LOCAL(void)
termDestination(j_compress_ptr pInfo)
{
    tMyDestinationPtr pDestination = (tMyDestinationPtr)pInfo->dest;

    // Size of the rest of the data in the pBuffer
    int iSize = (int)BUFFER_SIZE * sizeof(JSAMPLE) - (int)pDestination->m_Pub.free_in_buffer;
    if( iSize <= 0 )
    {
        return;
    }

    // Write remainder data to the channel
    bool bResult = pDestination->m_pOutputChannel->write((char *)pDestination->m_IOBuffer, iSize);

    // Set the buffer
    pDestination->m_Pub.next_output_byte = (JOCTET *)pDestination->m_IOBuffer;
    pDestination->m_Pub.free_in_buffer = BUFFER_SIZE * sizeof(JSAMPLE);

    // Error
    if( !bResult )
    {
        WARNMS(pInfo, JERR_FILE_WRITE);
    }
}


//==============================================================================
/*
 * Implementation of global functions.
 */
bool saveGrayJPEG(const CImage8& Image, vpl::mod::CChannel& Channel, int iQuality)
{
    // Check libjpeg sample bitdepth
    VPL_CHECK(CPixelTraits<tPixel8>::getPixelMax() == MAXJSAMPLE, return false);

    // Check that input channel is connected
    if( !Channel.isConnected() )
    {
        return false;
    }

    // JPEG compression structure
    struct jpeg_compress_struct pInfo;

    // Set error handler
    SMyErrorMgr JErr;
    pInfo.err = jpeg_std_error(&JErr.m_Pub);
    JErr.m_Pub.error_exit = myErrorExit;

    // Establish the setjmp return context for myErrorExit to use
    if( setjmp(JErr.m_SetJmpBuffer) )
    {
        // If we get here, the JPEG code has signaled an error
        // We need to clean up the JPEG object, close the input file, and return
        jpeg_destroy_compress(&pInfo);
        return false;
    }

    // Create compression object
    jpeg_create_compress(&pInfo);

    // Create data destination manager
    tMyDestinationPtr pDestination = (tMyDestinationPtr)(*pInfo.mem->alloc_small)((j_common_ptr)&pInfo, JPOOL_IMAGE, sizeof(SMyDestinationMgr));

    // Initialize the pDestination manager
    pDestination->m_pOutputChannel = &Channel;
    pDestination->m_Pub.init_destination = initDestination;
    pDestination->m_Pub.empty_output_buffer = emptyOutputBuffer;
    pDestination->m_Pub.term_destination = termDestination;
    pInfo.dest = (jpeg_destination_mgr *)pDestination;

    // First we supply a description of the input image.
    // Four fields of the pInfo struct must be filled in:
    pInfo.image_width = (JDIMENSION)Image.getXSize();
    pInfo.image_height = (JDIMENSION)Image.getYSize();
    pInfo.input_components = 1;
    pInfo.in_color_space = JCS_GRAYSCALE;

    // Now use the library's routine to set default compression parameters.
    // (You must set at least pInfo.in_color_space before calling this,
    // since the defaults depend on the source color space.)
    jpeg_set_defaults(&pInfo);

    // Now you can set any non-default parameters you wish to.
    // Here we just illustrate the use of quality (quantization table) scaling:
    jpeg_set_quality(&pInfo, iQuality, TRUE);

    // Start the compressor
    // TRUE ensures that we will write a complete interchange-JPEG file.
    // Pass TRUE unless you are very sure of what you're doing.
    jpeg_start_compress(&pInfo, TRUE);

    // JSAMPLEs per row in image_buffer
    int iRowStride = (int)Image.getXSize();

    // Make a one-row-high sample array that will go away when done with image
    JSAMPARRAY pBuffer = (*pInfo.mem->alloc_sarray)((j_common_ptr)&pInfo, JPOOL_IMAGE, iRowStride, 1);

    // Image data compression
    for( tSize j = 0; pInfo.next_scanline < pInfo.image_height; ++j )
    {
        // Image data conversion
        JSAMPLE *p = pBuffer[0];
        for( tSize i = 0; i < (tSize)pInfo.image_width; ++i )
        {
            *(p++) = (JSAMPLE)Image.at(i,j);
        }

        // jpeg_write_scanlines expects an array of pointers to scanlines.
        // Here the array is only one element long, but you could pass
        // more than one scanline at a time if that's more convenient.
        jpeg_write_scanlines(&pInfo, pBuffer, 1);
    }

    // Finish compression
    jpeg_finish_compress(&pInfo);

    // Release JPEG compression object.
    // This is an important step since it will release a good deal of memory.
    jpeg_destroy_compress(&pInfo);

    // And we're done!
    return (JErr.m_Pub.num_warnings == 0);
}


bool saveColorJPEG(const CRGBImage& Image, vpl::mod::CChannel& Channel, int iQuality)
{
    VPL_CHECK(MAXJSAMPLE == 255, return false);

    // Check that input channel is connected
    if( !Channel.isConnected() )
    {
        return false;
    }

    // JPEG compression structure
    struct jpeg_compress_struct pInfo;

    // Set error handler
    SMyErrorMgr JErr;
    pInfo.err = jpeg_std_error(&JErr.m_Pub);
    JErr.m_Pub.error_exit = myErrorExit;

    // Establish the setjmp return context for myErrorExit to use
    if( setjmp(JErr.m_SetJmpBuffer) )
    {
        // If we get here, the JPEG code has signaled an error
        // We need to clean up the JPEG object, close the input file, and return
        jpeg_destroy_compress(&pInfo);
        return false;
    }

    // Create compression object
    jpeg_create_compress(&pInfo);

    // Create data pDestination manager
    tMyDestinationPtr pDestination = (tMyDestinationPtr)(*pInfo.mem->alloc_small)((j_common_ptr)&pInfo, JPOOL_IMAGE, sizeof(SMyDestinationMgr));

    // Initialize the pDestination manager
    pDestination->m_pOutputChannel = &Channel;
    pDestination->m_Pub.init_destination = initDestination;
    pDestination->m_Pub.empty_output_buffer = emptyOutputBuffer;
    pDestination->m_Pub.term_destination = termDestination;
    pInfo.dest = (jpeg_destination_mgr *)pDestination;

    // First we supply a description of the input image.
    // Four fields of the pInfo struct must be filled in:
    pInfo.image_width = (JDIMENSION)Image.getXSize();
    pInfo.image_height = (JDIMENSION)Image.getYSize();
    pInfo.input_components = 3;
    pInfo.in_color_space = JCS_RGB;

    // Now use the library's routine to set default compression parameters.
    // (You must set at least pInfo.in_color_space before calling this,
    // since the defaults depend on the source color space.)
    jpeg_set_defaults(&pInfo);

    // Now you can set any non-default parameters you wish to.
    // Here we just illustrate the use of quality (quantization table) scaling:
    jpeg_set_quality(&pInfo, iQuality, TRUE);

    // Start the compressor
    // TRUE ensures that we will write a complete interchange-JPEG file.
    // Pass TRUE unless you are very sure of what you're doing.
    jpeg_start_compress(&pInfo, TRUE);

    // JSAMPLEs per row in image_buffer
    int iRowStride = (int)Image.getXSize() * 3;

    // Make a one-row-high sample array that will go away when done with image
    JSAMPARRAY pBuffer = (*pInfo.mem->alloc_sarray)((j_common_ptr)&pInfo, JPOOL_IMAGE, iRowStride, 1);

    // Image data compression
    for( tSize j = 0; pInfo.next_scanline < pInfo.image_height; ++j )
    {
        // Image data conversion
        JSAMPLE *p = pBuffer[0];
        for( tSize i = 0; i < (tSize)pInfo.image_width; ++i )
        {
            tRGBPixel Pixel = Image.at(i,j);
            *(p++) = (JSAMPLE)Pixel.r();
            *(p++) = (JSAMPLE)Pixel.g();
            *(p++) = (JSAMPLE)Pixel.b();
        }

        // jpeg_write_scanlines expects an array of pointers to scanlines.
        // Here the array is only one element long, but you could pass
        // more than one scanline at a time if that's more convenient.
        jpeg_write_scanlines(&pInfo, pBuffer, 1);
    }

    // Finish compression
    jpeg_finish_compress(&pInfo);

    // Release JPEG compression object.
    // This is an important step since it will release a good deal of memory.
    jpeg_destroy_compress(&pInfo);

    // And we're done!
    return (JErr.m_Pub.num_warnings == 0);
}


} // namespace img
} // namespace vpl

