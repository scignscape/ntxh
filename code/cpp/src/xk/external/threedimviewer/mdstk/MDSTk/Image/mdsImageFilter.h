//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/04                          \n
 *
 * $Id: mdsImageFilter.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Image filtering functions.
 */

#ifndef MDS_IMAGEFILTER_H
#define MDS_IMAGEFILTER_H

#include "mdsImageTypes.h"
#include "mdsImage.h"
#include "mdsFilterPolicy.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Base class for all image filters.
 * - Parameter I is an image type.
 */
template <class I>
class CImageFilter
{
public:
    //! Check that I is an image. You will see name of this enum somewhere
    //! in compiler error message if the type I is not image.
    enum { TEMPLATE_PARAMETER_IS_NOT_IMAGE = I::CLASS_IMAGE };

    //! Image type.
    typedef typename I::tImage tImage;

    //! Image pixel type.
    typedef typename I::tPixel tPixel;
  
public:
    //! Default constructor.
    CImageFilter() {}
    
    //! Virtual destructor.
    virtual ~CImageFilter() {}
    
    //! Filtering of input/source image.
    //! - Returns false on failure.
    virtual bool operator()(const tImage& SrcImage, tImage& DstImage) = 0;
};


//==============================================================================
/*!
 * Base class for all image filters that normalize filter response using
 * a predefined policy.
 * - Parameter I is an image type.
 * - Policy NormPolicy is used for filter response normalization.
 */
template <class I, template <typename> class NormPolicy>
class CNormImageFilter : public CImageFilter<I>, public NormPolicy<typename I::tPixel>
{
public:
    //! Base types.
    typedef CImageFilter<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    
    //! Filter response type.
    typedef typename CPixelTraits<tPixel>::tFilterResponse tResult;
    
    //! Filter response normalization function.
    using NormPolicy<typename I::tPixel>::normalize;
    
public:
    //! Default constructor.
    CNormImageFilter() {}
    
    //! Virtual destructor.
    virtual ~CNormImageFilter() {}

    //! Filtering of input/source image.
    //! - Returns false on failure.
    virtual bool operator()(const tImage& SrcImage, tImage& DstImage) = 0;
};


} // namespace img
} // namespace mds

#endif // MDS_IMAGEFILTER_H

