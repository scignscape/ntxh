//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/18                          \n
 *
 * $Id: mdsPixelTraits.hxx 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Pixel types traits.
 */


namespace img
{

//==============================================================================
/*
 * Type traits for the tPixel8 pixel type.
 */

template <>
inline tPixel8 CPixelTraits<tPixel8>::getPixelMin()
{
    return tPixel8(0x00);       // 0
}


template <>
inline tPixel8 CPixelTraits<tPixel8>::getPixelMax()
{
    return tPixel8(0xff);       // 255
}


template <>
inline tPixel8 CPixelTraits<tPixel8>::getGray()
{
    return tPixel8(0x80);       // 128
}


template <>
inline const char *CPixelTraits<tPixel8>::getPixelName()
{
    return "tPixel8";
}


//==============================================================================
/*
 * Type traits for the tPixel16 pixel type.
 */

template <>
inline tPixel16 CPixelTraits<tPixel16>::getPixelMin()
{
    return tPixel16(0x0000);    // 0
}


template <>
inline tPixel16 CPixelTraits<tPixel16>::getPixelMax()
{
    return tPixel16(0xffff);    // 65535
}


template <>
inline tPixel16 CPixelTraits<tPixel16>::getGray()
{
    return tPixel16(0x8000);    // 32768
}


template <>
inline const char *CPixelTraits<tPixel16>::getPixelName()
{
    return "tPixel16";
}


//==============================================================================
/*
 * Type traits for the tPixel32 pixel type.
 */

template <>
inline tPixel32 CPixelTraits<tPixel32>::getPixelMin()
{
    return tPixel32(0x0);
}


template <>
inline tPixel32 CPixelTraits<tPixel32>::getPixelMax()
{
    return tPixel32(0xffffffff);
}


template <>
inline tPixel32 CPixelTraits<tPixel32>::getGray()
{
    return tPixel32(0x80000000);
}


template <>
inline const char *CPixelTraits<tPixel32>::getPixelName()
{
    return "tPixel32";
}


//==============================================================================
/*
 * Type traits for the tFloatPixel pixel type.
 */

template <>
inline tFloatPixel CPixelTraits<tFloatPixel>::getPixelMin()
{
    return -1.0f;
}


template <>
inline tFloatPixel CPixelTraits<tFloatPixel>::getPixelMax()
{
    return 1.0f;
}


template <>
inline tFloatPixel CPixelTraits<tFloatPixel>::getGray()
{
    return 0.0f;
}


template <>
inline const char *CPixelTraits<tFloatPixel>::getPixelName()
{
    return "tFloatPixel";
}


//==============================================================================
/*
 * Type traits for the tDensityPixel pixel type.
 */

template <>
inline tDensityPixel CPixelTraits<tDensityPixel>::getPixelMin()
{
//    return tDensityPixel(0x000);    // 0
    return tDensityPixel(-1500);
}


template <>
inline tDensityPixel CPixelTraits<tDensityPixel>::getPixelMax()
{
//    return tDensityPixel(0xfff);    // 4095
    return tDensityPixel(7000);
}


template <>
inline tDensityPixel CPixelTraits<tDensityPixel>::getGray()
{
//    return tDensityPixel(0x800);    // 2048
    return tDensityPixel(0);
}


template <>
inline const char *CPixelTraits<tDensityPixel>::getPixelName()
{
    return "tDensityPixel";
}


//==============================================================================
/*
 * Type traits for the tRGBPixel pixel type.
 */

template <>
inline tRGBPixel CPixelTraits<tRGBPixel>::getPixelMin()
{
    static tRGBPixel Min = 0xff000000;
    return Min;
}


template <>
inline tRGBPixel CPixelTraits<tRGBPixel>::getPixelMax()
{
    static tRGBPixel Max = 0xffffffff;
    return Max;
}


template <>
inline tRGBPixel CPixelTraits<tRGBPixel>::getGray()
{
    static tRGBPixel Gray = 0xff808080;
    return Gray;
}


template <>
inline const char *CPixelTraits<tRGBPixel>::getPixelName()
{
    return "tRGBPixel";
}


//==============================================================================
/*
 * Type traits for the tComplexPixel pixel type.
 */

template <>
inline tComplexPixel CPixelTraits<tComplexPixel>::getPixelMin()
{
    static tComplexPixel Min(-1.0, 0.0);
    return Min;
}


template <>
inline tComplexPixel CPixelTraits<tComplexPixel>::getPixelMax()
{
    static tComplexPixel Max(1.0, 0.0);
    return Max;
}


template <>
inline tComplexPixel CPixelTraits<tComplexPixel>::getGray()
{
    static tComplexPixel Gray(0.0, 0.0);
    return Gray;
}


template <>
inline const char *CPixelTraits<tComplexPixel>::getPixelName()
{
    return "tComplexPixel";
}

} // namespace img


//==============================================================================
/*
 * Type traits for the tRGBPixel pixel type.
 */

template <>
inline mds::img::tRGBPixel mds::CTypeTraits<mds::img::tRGBPixel>::getMin()
{
    static mds::img::tRGBPixel Min = 0xff000000;
    return Min;
}


template <>
inline mds::img::tRGBPixel mds::CTypeTraits<mds::img::tRGBPixel>::getMax()
{
    static mds::img::tRGBPixel Max = 0xffffffff;
    return Max;
}


template <>
inline mds::img::tRGBPixel mds::CTypeTraits<mds::img::tRGBPixel>::getZero()
{
    static mds::img::tRGBPixel Zero = 0xff000000;
    return Zero;
}

