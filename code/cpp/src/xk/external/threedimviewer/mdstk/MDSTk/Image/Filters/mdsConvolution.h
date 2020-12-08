//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/08                          \n
 *
 * $Id: mdsConvolution.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Convolution image filter.
 */

#ifndef MDS_IF_CONVOLUTION_H
#define MDS_IF_CONVOLUTION_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsImageFilter.h"
#include "../mdsImageFunctions.h"
#include "../mdsKernel.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * General convolution filter.
 * - Parameter I is a used image type
 * - Policy N is used for filter response normalization.
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CConvolutionFilter
    : public CNormImageFilter<I,N>
    , public CKernel2D
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

public:
    //! Constructor that creates a new 2D convolution kernel
    //! - Parameter 'Size' must be an odd number
    CConvolutionFilter(tSize Size)
        : CKernel2D(Size) 
    {}

    //! Constructor
    CConvolutionFilter(tConstDataPtr pData, tSize Size)
        : CKernel2D(pData, Size)
    {}

    //! Constructor
    //! - Filter is based on a given convolution kernel
    CConvolutionFilter(const CKernel2D& k)
        : CKernel2D(k) 
    {}

    //! Destructor
    ~CConvolutionFilter() {}


    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tResult getResponse(const tImage& SrcImage, tSize x, tSize y)
    {
        // Compute filter response
        return convolve<tResult>(SrcImage, x, y, *this);
    }
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsConvolution.hxx"


} // namespace img
} // namespace mds

#endif // MDS_IF_CONVOLUTION_H

