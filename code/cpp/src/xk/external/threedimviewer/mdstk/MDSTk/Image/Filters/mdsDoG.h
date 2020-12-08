//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/10/07                          \n
 *
 * $Id: mdsDoG.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Difference of Gaussians filter.
 */

#ifndef MDS_IF_DOG_H
#define MDS_IF_DOG_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsImageFilter.h"
#include "../Filters/mdsGaussian.h"

#include <cmath>


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Difference of Gaussians image filter.
 * - Parameter I is a used image type.
 * - Policy N is used for filter response normalization.
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CDoGFilter : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

public:
    //! Constructor that creates DoG filter.
    CDoGFilter(double dSigma1 = 1.0, double dSigma2 = 1.5)
        : m_Gaussian1(dSigma1)
        , m_Gaussian2(dSigma2)
    {}

    //! Destructor
    ~CDoGFilter() {}


    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tResult getResponse(const tImage& SrcImage, tSize x, tSize y)
    {
        // Compute filter response
        return tResult(m_Gaussian2.getResponse(SrcImage, x, y)) - tResult(m_Gaussian1.getResponse(SrcImage, x, y));
    }

    //! Returns filter standard deviations.
    inline void getSigmas(double& dSigma1, double& dSigma2) const;

    //! Sets the standard deviations.
    inline void setSigmas(double dSigma1, double dSigma2);

protected:
    //! Gaussian filters.
    CGaussFilter<I> m_Gaussian1, m_Gaussian2;
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsDoG.hxx"


} // namespace img
} // namespace mds

#endif // MDS_IF_DOG_H

