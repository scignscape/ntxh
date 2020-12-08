//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/18                          \n
 *
 * $Id: mdsPixelTraits.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Pixel types traits
 */

#ifndef MDS_PIXELTRAITS_H
#define MDS_PIXELTRAITS_H

#include <MDSTk/Base/mdsTypeTraits.h>

#include "mdsPixelTypes.h"


namespace mds
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
class CPixelTraits : public mds::CTypeTraits<T>
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
#include "mdsPixelTraits.hxx"


} // namespace mds

#endif // MDS_PIXELTRAITS_H

