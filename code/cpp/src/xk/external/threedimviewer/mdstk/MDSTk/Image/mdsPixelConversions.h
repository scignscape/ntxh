//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)		\n
 * Copyright (c) 2003-2005 by Michal Spanel			\n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz		\n
 * Date:    2004/05/18								\n
 *
 * $Id: mdsPixelConversions.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Pixel values conversions.
 */

#ifndef MDS_PIXELCONVERSIONS_H
#define MDS_PIXELCONVERSIONS_H

#include "mdsPixelTraits.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Template of a class for basic pixel conversions.
 * - Parameter T is a pixel type.
 * - R is a resulting pixel type.
 */
template <typename T, typename R>
class CPixelConversion
{
public:
	//! Input pixel type.
	typedef T tPixel;
    
    //! Output pixel type.
	typedef R tResult;

public:
	//! Method for pixel value conversion.
	inline static R convert(const T& Value);
};


//==============================================================================
/*!
 * Specialization of the template class CPixelConversion for both pixels
 * of a same type (no conversion).
 */
template <typename T>
class CPixelConversion<T,T>
{
public:
    //! Input pixel type.
    typedef T tPixel;
    
    //! Output pixel type.
    typedef T tResult;

public:
	//! Method for pixel value conversion.
	inline static T convert(const T& Value)
	{
		return Value;
	}
};


//==============================================================================
/*!
 * Specialization of the CPixelConversion class for the tRGBPixel type.
 */
template <typename R>
class CPixelConversion<tRGBPixel,R>
{
public:
    //! Input pixel type.
    typedef tRGBPixel tPixel;
    
    //! Output pixel type.
    typedef R tResult;

public:
	//! Method for pixel value conversion.
	//! - RGB pixel intesity is computed and returned.
	inline static R convert(const tRGBPixel& Value);
};


//! Specialization of the CPixelConversion class for the tRGBPixel type.
template <typename T>
class CPixelConversion<T,tRGBPixel>
{
public:
    //! Input pixel type.
    typedef T tPixel;
    
    //! Output pixel type.
    typedef tRGBPixel tResult;

public:
	//! Method for pixel value conversion.
	inline static tRGBPixel convert(const T& Value);
};


//! Full specialization of the CPixelConversion class for the tRGBPixel
//! type to prevent ambiquity.
template <>
class CPixelConversion<tRGBPixel,tRGBPixel>
{
public:
    //! Input pixel type.
    typedef tRGBPixel tPixel;
    
    //! Output pixel type.
    typedef tRGBPixel tResult;

public:
    //! Method for pixel value conversion.
    inline static tRGBPixel convert(const tRGBPixel& Value)
    {
        return Value;
    }
};


//==============================================================================
/*!
 * Specialization of the CPixelConversion class for the tComplexPixel type.
 */
template <typename R>
class CPixelConversion<tComplexPixel,R>
{
public:
    //! Input pixel type.
    typedef tComplexPixel tPixel;
    
    //! Output pixel type.
    typedef R tResult;

public:
    //! Method for pixel value conversion.
    //! - Real part of complex pixel is returned.
    inline static R convert(const tComplexPixel& Value);
};


//! Specialization of the CPixelConversion class for the tComplexPixel type.
template <typename T>
class CPixelConversion<T,tComplexPixel>
{
public:
    //! Input pixel type.
    typedef T tPixel;
    
    //! Output pixel type.
    typedef tComplexPixel tResult;

public:
    //! Method for pixel value conversion.
    inline static tComplexPixel convert(const T& Value);
};


//! Full specialization of the CPixelConversion class for the tComplexPixel
//! type to prevent ambiquity.
template <>
class CPixelConversion<tComplexPixel,tComplexPixel>
{
public:
    //! Input pixel type.
    typedef tComplexPixel tPixel;
    
    //! Output pixel type.
    typedef tComplexPixel tResult;

public:
    //! Method for pixel value conversion.
    inline static tComplexPixel convert(const tComplexPixel& Value)
    {
        return Value;
    }
};


//! Full specialization of the CPixelConversion class for the tComplexPixel
//! and tRGBPixel types to prevent ambiquity.
template <>
class CPixelConversion<tRGBPixel,tComplexPixel>
{
public:
    //! Input pixel type.
    typedef tRGBPixel tPixel;
    
    //! Output pixel type.
    typedef tComplexPixel tResult;

public:
    //! Method for pixel value conversion.
    inline static tComplexPixel convert(const tRGBPixel& Value);
};


//! Full specialization of the CPixelConversion class for the tComplexPixel
//! and tRGBPixel types to prevent ambiquity.
template <>
class CPixelConversion<tComplexPixel, tRGBPixel>
{
public:
    //! Input pixel type.
    typedef tComplexPixel tPixel;
    
    //! Output pixel type.
    typedef tRGBPixel tResult;

public:
    //! Method for pixel value conversion.
    inline static tRGBPixel convert(const tComplexPixel& Value);
};


//==============================================================================
/*
 * Include methods templates.
 */
#include "mdsPixelConversions.hxx"


} // namespace img
} // namespace mds

#endif // MDS_PIXELCONVERSIONS_H

