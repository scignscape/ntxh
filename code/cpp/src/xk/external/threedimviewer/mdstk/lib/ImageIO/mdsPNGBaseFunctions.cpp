//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/12                          \n
 *
 * $Id: mdsPNGBaseFunctions.cpp 2103 2012-02-17 10:08:20Z spanel $
 *
 * Description:
 * - Reading and writing of PNG images.
 * - Based on libpng.
 */

#include <MDSTk/ImageIO/mdsPNGBaseFunctions.h>
#include <MDSTk/Base/mdsVersion.h>
#include <MDSTk/Base/mdsMemory.h>

// Include libpng and zlib header files
extern "C"
{
#include <zlib.h>
#include <png.h>
}

#include <setjmp.h>

#ifdef _MSC_VER
// warning C4611: interaction between '_setjmp' and C++ object destruction is non-portable
#   pragma warning(disable : 4611)
#endif // _MSC_VER


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Macro definitions.
 */

// Future versions of libpng will provide this macro:
#ifndef png_jmpbuf
#    define png_jmpbuf(png_ptr)        ((png_ptr)->jmpbuf)
#endif


//==============================================================================
/*
 * Global constants.
 */

//! Default gamma correction.
const double SCREEN_GAMMA       = 2.2;
const double FILE_GAMMA         = 0.45455;

//! Pixel conversion (RGB -> 0..65535).
const unsigned int R_WEIGHT     = 19660;
const unsigned int G_WEIGHT     = 38666;
const unsigned int B_WEIGHT     = 7209;


//==============================================================================
/*
 * Helper functions.
 */
void userReadData(png_structp pPNGStruct, png_bytep pData, png_size_t Length)
{
    // Get pointer to the input channel
    mds::mod::CChannel *pInputChannel = (mds::mod::CChannel *)png_get_io_ptr(pPNGStruct);
    MDS_CHECK(pInputChannel != NULL, return);

    // Read pData from the channel
    pInputChannel->read((char *)pData, (int)Length);
}


void userWriteData(png_structp pPNGStruct, png_bytep pData, png_size_t Length)
{
    // Get pointer to the output channel
    mds::mod::CChannel *pOutputChannel = (mds::mod::CChannel *)png_get_io_ptr(pPNGStruct);
    MDS_CHECK(pOutputChannel != NULL, return);

    // Write the pData to the channel
    pOutputChannel->write((char *)pData, (int)Length);
}


void userFlushData(png_structp)
{
    // Do nothing
}


//==============================================================================
/*
 * Implementation of global functions.
 */
bool loadGrayPNG(CImage16& Image, mds::mod::CChannel& Channel)
{
    // Check that input channel is connected
    if( !Channel.isConnected() )
    {
        return false;
    }

    // First do a quick check that the file really is a PNG image
    unsigned char pucSignature[8];
    int iResult = Channel.read((char *)pucSignature, 8);
    if( iResult != 8 )
    {
        return false;
    }
    if( !png_check_sig(pucSignature, 8) )
    {
        return false;
    }

    // Create libpng read structures
    png_structp pPNGStruct = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if( !pPNGStruct )
    {
        return false;
    }
    png_infop pPNGInfo = png_create_info_struct(pPNGStruct);
    if( !pPNGInfo )
    {
        png_destroy_read_struct(&pPNGStruct, (png_infopp)NULL, (png_infopp)NULL);
        return false;
    }

    // setjmp() must be called in every function that calls a PNG-reading libpng function
    if( setjmp(png_jmpbuf(pPNGStruct)) )
    {
        png_destroy_read_struct(&pPNGStruct, &pPNGInfo, (png_infopp)NULL);
        return false;
    }

    // Change the I/O method
    png_set_read_fn(pPNGStruct, (void *)&Channel, userReadData);

    // We already read the 8 signature bytes
    png_set_sig_bytes(pPNGStruct, 8);

    // Read all PNG info up to image pData
    png_read_info(pPNGStruct, pPNGInfo);

    // Alternatively, could make separate calls to png_get_image_width(),
    // etc., but want bit_depth and color_type for later [don't care about
    // compression_type and filter_type => NULLs]
    png_uint_32 u32Width, u32Height;
    int iBitDepth, iColorType;
    png_get_IHDR(pPNGStruct, pPNGInfo, &u32Width, &u32Height, &iBitDepth, &iColorType, NULL, NULL, NULL);

    // Expand grayscale images to the full 8 bits
    if( iColorType == PNG_COLOR_TYPE_GRAY && iBitDepth < 8 )
    {
        png_set_expand_gray_1_2_4_to_8(pPNGStruct);
    }

    // Transparent to alpha channel
    if( png_get_valid(pPNGStruct, pPNGInfo, PNG_INFO_tRNS) )
    {
        png_set_tRNS_to_alpha(pPNGStruct);
    }

    // Strip alpha channel
    if( iColorType & PNG_COLOR_MASK_ALPHA )
    {
        png_set_strip_alpha(pPNGStruct);
    }

    // Pallete to RGB conversion
/*    if( iColorType == PNG_COLOR_TYPE_PALETTE )
    {
        png_set_palette_to_rgb(pPNGStruct);
    }*/
    if( iColorType == PNG_COLOR_TYPE_PALETTE )
    {
        png_destroy_read_struct(&pPNGStruct, &pPNGInfo, (png_infopp)NULL);
        return false;
    }

    // Convert RGB and RGBA images to grayscale
    if( iColorType == PNG_COLOR_TYPE_RGB || iColorType == PNG_COLOR_TYPE_RGB_ALPHA )
    {
        png_set_rgb_to_gray_fixed(pPNGStruct, 1, -1, -1);
    }

    // Change big-endian number format to little-endian
    if( iBitDepth == 16 )
    {
        png_set_swap(pPNGStruct);
    }

    // Gamma correction
/*  double dGamma;
    if( png_get_gamma(pPNGStruct, pPNGInfo, &dGamma) )
    {
        png_set_gamma(pPNGStruct, SCREEN_GAMMA, dGamma);
    }
    else
    {
        png_set_gamma(pPNGStruct, SCREEN_GAMMA, FILE_GAMMA);
    }*/

    // Read updated info
    png_read_update_info(pPNGStruct, pPNGInfo);
    iBitDepth = png_get_bit_depth(pPNGStruct, pPNGInfo);
    
    // Recreate the slice of appropriate size
    Image.create((tSize)u32Width,
                 (tSize)u32Height,
                 Image.getMargin()
                 );
    Image.fillEntire(0);

    // Row pointers
    png_bytep *ppRowPointers = mds::base::memAlloc<png_bytep>(u32Height);
    for( png_uint_32 j = 0; j < u32Height; ++j )
    {
        ppRowPointers[j] = (png_bytep)png_malloc(pPNGStruct, png_get_rowbytes(pPNGStruct, pPNGInfo));
    }

    // Now we can go ahead and just read the whole image
    png_read_image(pPNGStruct, ppRowPointers);

    // 16 bits per pixel
    if( iBitDepth == 16 )
    {
        for( tSize y = 0; y < (tSize)u32Height; ++y )
        {
            png_uint_16p p = (png_uint_16p)ppRowPointers[y];
            for( tSize x = 0; x < (tSize)u32Width; ++x )
            {
                Image(x,y) = tPixel16(*p++);
            }
        }
    }

    // 8 bits per pixel
    else
    {
        for( tSize y = 0; y < (tSize)u32Height; ++y )
        {
            png_bytep p = ppRowPointers[y];
            for( tSize x = 0; x < (tSize)u32Width; ++x )
            {
                tPixel16 Value = tPixel16(*p++) * 257;
                Image(x,y) = Value;
            }
        }
    }

    // Delete raw pointers
    mds::base::memFree<png_bytep>(ppRowPointers);

    // And we're done!  (png_read_end() can be omitted if no processing of
    // post-IDAT text/time/etc. is desired)
//  png_read_end(pPNGStruct, pPNGInfo);

    // Destroy the read structures
    png_destroy_read_struct(&pPNGStruct, &pPNGInfo, (png_infopp)NULL);

    // Done
    return true;
}


bool loadColorPNG(CRGBImage& Image, mds::mod::CChannel& Channel)
{
    // Check that input channel is connected
    if( !Channel.isConnected() )
    {
        return false;
    }

    // First do a quick check that the file really is a PNG image
    unsigned char pucSignature[8];
    int iResult = Channel.read((char *)pucSignature, 8);
    if( iResult != 8 )
    {
        return false;
    }
    if( !png_check_sig(pucSignature, 8) )
    {
        return false;
    }

    // Create libpng read structures
    png_structp pPNGStruct = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if( !pPNGStruct )
    {
        return false;
    }
    png_infop pPNGInfo = png_create_info_struct(pPNGStruct);
    if( !pPNGInfo )
    {
        png_destroy_read_struct(&pPNGStruct, (png_infopp)NULL, (png_infopp)NULL);
        return false;
    }

    // setjmp() must be called in every function that calls a PNG-reading libpng function
    if( setjmp(png_jmpbuf(pPNGStruct)) )
    {
        png_destroy_read_struct(&pPNGStruct, &pPNGInfo, (png_infopp)NULL);
        return false;
    }

    // Change the I/O method
    png_set_read_fn(pPNGStruct, (void *)&Channel, userReadData);

    // We already read the 8 signature bytes
    png_set_sig_bytes(pPNGStruct, 8);

    // Read all PNG info up to image pData
    png_read_info(pPNGStruct, pPNGInfo);

    // Alternatively, could make separate calls to png_get_image_width(),
    // etc., but want bit_depth and color_type for later [don't care about
    // compression_type and filter_type => NULLs]
    png_uint_32 u32Width, u32Height;
    int iBitDepth, iColorType;
    png_get_IHDR(pPNGStruct, pPNGInfo, &u32Width, &u32Height, &iBitDepth, &iColorType, NULL, NULL, NULL);

    // Expand grayscale images to the full 8 bits
    if( iColorType == PNG_COLOR_TYPE_GRAY && iBitDepth < 8 )
    {
        png_set_expand_gray_1_2_4_to_8(pPNGStruct);
    }

    // Transparent to alpha channel
    if( png_get_valid(pPNGStruct, pPNGInfo, PNG_INFO_tRNS) )
    {
        png_set_tRNS_to_alpha(pPNGStruct);
    }

    // Strip alpha channel
    if( iColorType & PNG_COLOR_MASK_ALPHA )
    {
        png_set_strip_alpha(pPNGStruct);
    }

    // Pallete to RGB conversion
    if( iColorType == PNG_COLOR_TYPE_PALETTE )
    {
        png_set_palette_to_rgb(pPNGStruct);
    }

    // Convert grayscale to RGB, RGBA
    if( iColorType == PNG_COLOR_TYPE_GRAY || iColorType == PNG_COLOR_TYPE_GRAY_ALPHA )
    {
        png_set_gray_to_rgb(pPNGStruct);
    }

    // Reduce 16-bit images to just 8-bit
    if( iBitDepth == 16 )
    {
        png_set_strip_16(pPNGStruct);
    }

    // Gamma correction
/*  double dGamma;
    if( png_get_gamma(pPNGStruct, pPNGInfo, &dGamma) )
    {
        png_set_gamma(pPNGStruct, SCREEN_GAMMA, dGamma);
    }
    else
    {
        png_set_gamma(pPNGStruct, SCREEN_GAMMA, FILE_GAMMA);
    }*/

    // Read updated info
    png_read_update_info(pPNGStruct, pPNGInfo);
    iBitDepth = png_get_bit_depth(pPNGStruct, pPNGInfo);

    // Recreate the slice of appropriate size
    Image.create((tSize)u32Width,
                 (tSize)u32Height,
                 Image.getMargin()
                 );
    Image.fillEntire(tRGBPixel(0, 0, 0));

    // Row pointers
    png_bytep *ppRowPointers = mds::base::memAlloc<png_bytep>(u32Height);
    for( png_uint_32 j = 0; j < u32Height; ++j )
    {
        ppRowPointers[j] = (png_bytep)png_malloc(pPNGStruct, png_get_rowbytes(pPNGStruct, pPNGInfo));
    }

    // Now we can go ahead and just read the whole image
    png_read_image(pPNGStruct, ppRowPointers);

    // Copy and normalize the image data
    tRGBPixel::tComponent r, g, b;
    if( iBitDepth == 8 )
    {
        for( tSize y = 0; y < (tSize)u32Height; ++y )
        {
            png_bytep p = ppRowPointers[y];
            for( tSize x = 0; x < (tSize)u32Width; ++x )
            {
                r = tRGBPixel::tComponent(*p++);
                g = tRGBPixel::tComponent(*p++);
                b = tRGBPixel::tComponent(*p++);
                Image(x,y) = tRGBPixel(r, g, b);
            }
        }
    }

    // Delete raw pointers
    mds::base::memFree<png_bytep>(ppRowPointers);

    // And we're done!  (png_read_end() can be omitted if no processing of
    // post-IDAT text/time/etc. is desired)
//  png_read_end(pPNGStruct, pPNGInfo);

    // Destroy the read structures
    png_destroy_read_struct(&pPNGStruct, &pPNGInfo, (png_infopp)NULL);

    // Done
    return (iBitDepth == 8);
}


//==============================================================================
/*
 * Implementation of global functions.
 */
bool saveGrayPNG(const CImage16& Image, mds::mod::CChannel& Channel)
{
    // Check that input channel is connected
    if( !Channel.isConnected() )
    {
        return false;
    }

    // Create and initialize the png_struct with the desired error handler
    // functions.  If you want to use the default stderr and longjump method,
    // you can supply NULL for the last three parameters
    png_structp pPNGStruct = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if( !pPNGStruct )
    {
        return false;
    }

    // Allocate/initialize the image information pData
    png_infop pPNGInfo = png_create_info_struct(pPNGStruct);
    if( !pPNGInfo )
    {
        png_destroy_write_struct(&pPNGStruct,  (png_infopp)NULL);
        return false;
    }

    // Set error handling. REQUIRED if you aren't supplying your own
    // error handling functions in the png_create_write_struct() call
    if( setjmp(png_jmpbuf(pPNGStruct)) )
    {
        png_destroy_write_struct(&pPNGStruct, &pPNGInfo);
        return false;
    }

    // Change the I/O method
    png_set_write_fn(pPNGStruct, (void *)&Channel, userWriteData, userFlushData);

    // Set the image information here.  Width and u32Height are up to 2^31,
    // iBitDepth is one of 1, 2, 4, 8, or 16, but valid values also depend on
    // the iColorType selected. iColorType is one of PNG_COLOR_TYPE_GRAY,
    // PNG_COLOR_TYPE_GRAY_ALPHA, PNG_COLOR_TYPE_PALETTE, PNG_COLOR_TYPE_RGB,
    // or PNG_COLOR_TYPE_RGB_ALPHA.  interlace is either PNG_INTERLACE_NONE or
    // PNG_INTERLACE_ADAM7, and the compression_type and filter_type MUST
    // currently be PNG_COMPRESSION_TYPE_BASE and PNG_FILTER_TYPE_BASE. REQUIRED
    png_uint_32 u32Width = (png_uint_32)Image.getXSize();
    png_uint_32 u32Height = (png_uint_32)Image.getYSize();
    png_set_IHDR(pPNGStruct,
                 pPNGInfo,
                 u32Width,
                 u32Height,
                 16,
                 PNG_COLOR_TYPE_GRAY,
                 PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_BASE,
                 PNG_FILTER_TYPE_BASE
                 );

    // Optional significant bit chunk
    // if we are dealing with a grayscale image then
    png_color_8 SigBit;
    SigBit.gray = 16;
    png_set_sBIT(pPNGStruct, pPNGInfo, &SigBit);

    // Optional gamma chunk is strongly suggested if you have any guess
    // as to the correct gamma of the image
//  png_set_gama(pPNGStruct, pPNGInfo, SCREEN_GAMMA);

    static char pcProject[] = "Project";
    static char pcContact[] = "Contact";
    static char pcDesc[] = "Description";
    static char pcData[] = "Image data";

    // Optionally write comments into the image
    png_text_struct pPNGTextStruct[3];
    pPNGTextStruct[0].key = pcProject;
    pPNGTextStruct[0].text = (char *)LABEL.c_str();
    pPNGTextStruct[0].compression = PNG_TEXT_COMPRESSION_NONE;
    pPNGTextStruct[1].key = pcContact;
    pPNGTextStruct[1].text = (char *)AUTHORS.c_str();
    pPNGTextStruct[1].compression = PNG_TEXT_COMPRESSION_NONE;
    pPNGTextStruct[2].key = pcDesc;
    pPNGTextStruct[2].text = pcData;
    pPNGTextStruct[2].compression = PNG_TEXT_COMPRESSION_NONE;
#ifdef PNG_iTXt_SUPPORTED
    pPNGTextStruct[0].lang = NULL;
    pPNGTextStruct[1].lang = NULL;
    pPNGTextStruct[2].lang = NULL;
#endif
    png_set_text(pPNGStruct, pPNGInfo, pPNGTextStruct, 3);

    // Write the file header information
    png_write_info(pPNGStruct, pPNGInfo);

    // Shift the pixels up to a legal bit depth and fill in
    // as appropriate to correctly scale the image.
    png_set_shift(pPNGStruct, &SigBit);

    // Swap bytes of 16-bit files to most significant byte first
    png_set_swap(pPNGStruct);

    // Row pointers
    png_bytep *ppRowPointers = mds::base::memAlloc<png_bytep>(u32Height);
    for( png_uint_32 j = 0; j < u32Height; ++j )
    {
        ppRowPointers[j] = (png_bytep)png_malloc(pPNGStruct, png_get_rowbytes(pPNGStruct, pPNGInfo));
    }

    // Copy and normalize the image data
    for( tSize y = 0; y < (tSize)u32Height; ++y )
    {
        png_uint_16p p = (png_uint_16p)ppRowPointers[y];
        for( tSize x = 0; x < (tSize)u32Width; ++x )
        {
            tPixel16 Value = Image(x,y);
            *(p++) = (png_uint_16)Value;
        }
    }

    // Write the entire image
    png_write_image(pPNGStruct, ppRowPointers);

    // Delete raw pointers
    mds::base::memFree<png_bytep>(ppRowPointers);

    // Clean up after the write, and free any memory allocated
    png_destroy_write_struct(&pPNGStruct, &pPNGInfo);

    // Done
    return true;
}


bool saveColorPNG(const CRGBImage& Image, mds::mod::CChannel& Channel)
{
    // Check that input channel is connected
    if( !Channel.isConnected() )
    {
        return false;
    }

    // Create and initialize the png_struct with the desired error handler
    // functions.  If you want to use the default stderr and longjump method,
    // you can supply NULL for the last three parameters
    png_structp pPNGStruct = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if( !pPNGStruct )
    {
        return false;
    }

    // Allocate/initialize the image information pData
    png_infop pPNGInfo = png_create_info_struct(pPNGStruct);
    if( !pPNGInfo )
    {
        png_destroy_write_struct(&pPNGStruct,  (png_infopp)NULL);
        return false;
    }

    // Set error handling. REQUIRED if you aren't supplying your own
    // error handling functions in the png_create_write_struct() call
    if( setjmp(png_jmpbuf(pPNGStruct)) )
    {
        png_destroy_write_struct(&pPNGStruct, &pPNGInfo);
        return false;
    }

    // Change the I/O method
    png_set_write_fn(pPNGStruct, (void *)&Channel, userWriteData, userFlushData);

    // Set the image information here.  Width and u32Height are up to 2^31,
    // iBitDepth is one of 1, 2, 4, 8, or 16, but valid values also depend on
    // the iColorType selected. iColorType is one of PNG_COLOR_TYPE_GRAY,
    // PNG_COLOR_TYPE_GRAY_ALPHA, PNG_COLOR_TYPE_PALETTE, PNG_COLOR_TYPE_RGB,
    // or PNG_COLOR_TYPE_RGB_ALPHA.  interlace is either PNG_INTERLACE_NONE or
    // PNG_INTERLACE_ADAM7, and the compression_type and filter_type MUST
    // currently be PNG_COMPRESSION_TYPE_BASE and PNG_FILTER_TYPE_BASE. REQUIRED
    png_uint_32 u32Width = (png_uint_32)Image.getXSize();
    png_uint_32 u32Height = (png_uint_32)Image.getYSize();
    png_set_IHDR(pPNGStruct,
                 pPNGInfo,
                 u32Width,
                 u32Height,
                 8,
                 PNG_COLOR_TYPE_RGB,
                 PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_BASE,
                 PNG_FILTER_TYPE_BASE
                 );

    // Optional significant bit chunk
    // if we are dealing with a grayscale image then
    png_color_8 SigBit;
    SigBit.red = 8;
    SigBit.green = 8;
    SigBit.blue = 8;
    png_set_sBIT(pPNGStruct, pPNGInfo, &SigBit);

    // Optional gamma chunk is strongly suggested if you have any guess
    // as to the correct gamma of the image
//  png_set_gama(pPNGStruct, pPNGInfo, SCREEN_GAMMA);

    static char pcProject[] = "Project";
    static char pcContact[] = "Contact";
    static char pcDesc[] = "Description";
    static char pcData[] = "Image data";

    // Optionally write comments into the image
    png_text_struct pPNGTextStruct[3];
    pPNGTextStruct[0].key = pcProject;
    pPNGTextStruct[0].text = (char *)LABEL.c_str();
    pPNGTextStruct[0].compression = PNG_TEXT_COMPRESSION_NONE;
    pPNGTextStruct[1].key = pcContact;
    pPNGTextStruct[1].text = (char *)AUTHORS.c_str();
    pPNGTextStruct[1].compression = PNG_TEXT_COMPRESSION_NONE;
    pPNGTextStruct[2].key = pcDesc;
    pPNGTextStruct[2].text = pcData;
    pPNGTextStruct[2].compression = PNG_TEXT_COMPRESSION_NONE;
#ifdef PNG_iTXt_SUPPORTED
    pPNGTextStruct[0].lang = NULL;
    pPNGTextStruct[1].lang = NULL;
    pPNGTextStruct[2].lang = NULL;
#endif
    png_set_text(pPNGStruct, pPNGInfo, pPNGTextStruct, 3);

    // Write the file header information
    png_write_info(pPNGStruct, pPNGInfo);

    // Shift the pixels up to a legal bit depth and fill in
    // as appropriate to correctly scale the image.
    png_set_shift(pPNGStruct, &SigBit);

    // Swap bytes of 16-bit files to most significant byte first
//    png_set_swap(pPNGStruct);

    // Row pointers
    png_bytep *ppRowPointers = mds::base::memAlloc<png_bytep>(u32Height);
    for( png_uint_32 j = 0; j < u32Height; ++j )
    {
        ppRowPointers[j] = (png_bytep)png_malloc(pPNGStruct, png_get_rowbytes(pPNGStruct, pPNGInfo));
    }

    // Copy and normalize the image data
    for( tSize y = 0; y < (tSize)u32Height; ++y )
    {
        png_bytep p = ppRowPointers[y];
        for( tSize x = 0; x < (tSize)u32Width; ++x )
        {
            tRGBPixel Value = Image(x,y);
            *(p++) = (png_byte)Value.r();
            *(p++) = (png_byte)Value.g();
            *(p++) = (png_byte)Value.b();
        }
    }

    // Write the entire image
    png_write_image(pPNGStruct, ppRowPointers);

    // Delete raw pointers
    mds::base::memFree<png_bytep>(ppRowPointers);

    // Clean up after the write, and free any memory allocated
    png_destroy_write_struct(&pPNGStruct, &pPNGInfo);

    // Done
    return true;
}


} // namespace img
} // namespace mds

