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
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/18                       
 *
 * Description:
 * - Pixel types traits
 */

#ifndef VPL_PIXELTRAITS_H
#define VPL_PIXELTRAITS_H

#include <VPL/Base/TypeTraits.h>

#include "PixelTypes.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Templates for specification of filter response type.
 */

//! Primary template.
//! - Parameter T is concrete pixel type.
template <typename T>
struct SIsFilterable
{
    enum { RESULT = false };
    typedef T tFilterResponse;
};


//! Macro to specialize filter response types.
#define FILTER_RESPONSE_TYPE(T, R) \
    template <> \
    struct SIsFilterable<T> \
    { \
        enum { RESULT = true }; \
        typedef R tFilterResponse; \
    }


FILTER_RESPONSE_TYPE(tPixel8, float);
FILTER_RESPONSE_TYPE(tPixel16, float);
FILTER_RESPONSE_TYPE(tPixel32, float);
FILTER_RESPONSE_TYPE(tFloatPixel, float);
FILTER_RESPONSE_TYPE(tDensityPixel, float);


//==============================================================================
/*
 * Image pixel type traits.
 */
template <typename T>
class CPixelTraits : public vpl::CTypeTraits<T>
{
public:
    //! Simple pixel type checks.
    enum { isFilterable = SIsFilterable<T>::RESULT };

    //! Filter response type.
    typedef typename SIsFilterable<T>::tFilterResponse tFilterResponse;

public:
    //! Minimal pixel value.
    inline static T getPixelMin();

    //! Maximal pixel value.
    inline static T getPixelMax();

    //! Returns value corresponding to the gray color.
    inline static T getGray();

    //! Returns pixel name.
    inline static const char *getPixelName();
};

} // namespace img


//==============================================================================
/*
 * Include type traits for the predefined pixel types.
 */
#include "PixelTraits.hxx"


} // namespace vpl

#endif // VPL_PIXELTRAITS_H

