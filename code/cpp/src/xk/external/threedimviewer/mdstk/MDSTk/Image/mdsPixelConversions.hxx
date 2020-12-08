//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)        \n
 * Copyright (c) 2003-2005 by Michal Spanel         \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz      \n
 * Date:    2005/09/12                              \n
 *
 * $Id: mdsPixelConversions.hxx 1707 2010-05-05 11:00:46Z spanel $
 *
 * Description:
 * - Pixel values conversions.
 */


//==============================================================================
/*
 * Primary implementation of the mds::CPixelConversion<T,R> class.
 */

template <typename T, typename R>
inline R CPixelConversion<T,R>::convert(const T& Value)
{
    static const R RMin = CPixelTraits<R>::getPixelMin();
    static const R RMax = CPixelTraits<R>::getPixelMax();

    static const T TMin = CPixelTraits<T>::getPixelMin();
    static const T TMax = CPixelTraits<T>::getPixelMax();
    
    static const float fRatio = (float(RMax) - RMin) / (float(TMax) - TMin);
    
    float fValue = float(Value) - TMin;
    return R(fRatio * fValue + RMin);
}


//==============================================================================
/*
 * Implementation of the mds::CPixelConversion<tRGBPixel,R> class.
 */

template <typename R>
inline R CPixelConversion<tRGBPixel,R>::convert(const tRGBPixel& Value)
{
    static const R RMin = CPixelTraits<R>::getPixelMin();
    static const R RMax = CPixelTraits<R>::getPixelMax();
    
    static const float fRatio = (float(RMax) - RMin) / 255.0f;
    
    float fValue = 0.3f * Value.b() + 0.59f * Value.g() + 0.11f * Value.r();    
    return R(fRatio * fValue + RMin);
}


template <>
inline tPixel8 CPixelConversion<tRGBPixel,tPixel8>::convert(const tRGBPixel& Value)
{
    float fValue = 0.3f * Value.b() + 0.59f * Value.g() + 0.11f * Value.r();
    
    return tPixel8(fValue);
}


//==============================================================================
/*
 * Implementation of the mds::CPixelConversion<T,tRGBPixel> class.
 */

template <typename T>
inline tRGBPixel CPixelConversion<T,tRGBPixel>::convert(const T& Value)
{
    static const T TMin = CPixelTraits<T>::getPixelMin();
    static const T TMax = CPixelTraits<T>::getPixelMax();
    
    static const float fRatio = 255.0f / (float(TMax) - TMin);
    
    float fValue = float(Value) - TMin;
    tRGBPixel::tComponent NewValue = tRGBPixel::tComponent(fRatio * fValue);
    return tRGBPixel(NewValue, NewValue, NewValue);
}


template <>
inline tRGBPixel CPixelConversion<tPixel8,tRGBPixel>::convert(const tPixel8& Value)
{
	return tRGBPixel(Value, Value, Value);
}


//==============================================================================
/*
 * Implementation of the mds::CPixelConversion<tComplexPixel,R> class.
 */

template <typename R>
inline R CPixelConversion<tComplexPixel,R>::convert(const tComplexPixel& Value)
{
    static const tComplexPixel TMin = CPixelTraits<tComplexPixel>::getPixelMin();
    static const tComplexPixel TRange = CPixelTraits<tComplexPixel>::getPixelMax() - TMin;

    static const R RMin = CPixelTraits<R>::getPixelMin();
    static const R RMax = CPixelTraits<R>::getPixelMax();

    static const float fRatio = (float(RMax) - RMin) / float(TRange.getReal());

    return R(fRatio * (Value.getReal() - TMin.getReal()) + RMin);
}


template <>
inline tFloatPixel CPixelConversion<tComplexPixel,tFloatPixel>::convert(const tComplexPixel& Value)
{
    return tFloatPixel(Value.getReal());
}


//==============================================================================
/*
 * Implementation of the mds::CPixelConversion<T,tComplexPixel> class.
 */

template <typename T>
inline tComplexPixel CPixelConversion<T,tComplexPixel>::convert(const T& Value)
{
    static const T TMin = CPixelTraits<T>::getPixelMin();
    static const T TMax = CPixelTraits<T>::getPixelMax();

    static const tComplexPixel RMin = CPixelTraits<tComplexPixel>::getPixelMin();
    static const tComplexPixel RRange = CPixelTraits<tComplexPixel>::getPixelMax() - RMin;

    static const float fRatio = float(RRange.getReal()) / (float(TMax) - TMin);
    
    return tComplexPixel(tComplexPixel::tComponent(fRatio * (float(Value) - TMin) + RMin.getReal()));
}


template <>
inline tComplexPixel CPixelConversion<tFloatPixel,tComplexPixel>::convert(const tFloatPixel& Value)
{
    return tComplexPixel(Value);
}


//template <>
inline tComplexPixel CPixelConversion<tRGBPixel,tComplexPixel>::convert(const tRGBPixel& Value)
{
    tFloatPixel fValue = CPixelConversion<tRGBPixel,tFloatPixel>::convert(Value);
    
    return tComplexPixel(fValue);
}


//template <>
inline tRGBPixel CPixelConversion<tComplexPixel,tRGBPixel>::convert(const tComplexPixel& Value)
{
    tPixel8 bValue = CPixelConversion<tComplexPixel,tPixel8>::convert(Value);
    
    return tRGBPixel(bValue, bValue, bValue);
}
