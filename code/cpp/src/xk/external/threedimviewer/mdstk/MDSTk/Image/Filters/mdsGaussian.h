//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/08                          \n
 *
 * $Id: mdsGaussian.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Gaussian smoothing filter.
 */

#ifndef MDS_IF_GAUSSIAN_H
#define MDS_IF_GAUSSIAN_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsImageFilter.h"
#include "../mdsImageFunctions.h"
#include "../mdsKernel.h"

#include <cmath>


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Gaussian smoothing filter.
 * - Parameter I is a used image type.
 * - Policy N is used for filter response normalization.
 * - Its kernel is defined by the following function: \n
 *                         1                 (x^2 + y^2)  \n
 *   G_sigma(x,y) = ---------------- * exp(- -----------) \n
 *                  2 * pi * sigma^2         2 * sigma^2  \n
 */
template <class I>
class CGaussFilter : public CImageFilter<I>, public CKernel2D
{
public:
    //! Image filter base.
    typedef CImageFilter<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;

public:
    //! Constructor that creates Gaussian filter having a specified standard
    //! deviation ("sigma" parameter).
    CGaussFilter(double dSigma) : CKernel2D(sigma2Size(dSigma))
    {
        MDS_ASSERT(dSigma > 0.0);

        initKernel(dSigma);
    }

    //! Constructor that creates Gaussian filter having the standard
    //! deviation corresponding to a given kernel size.
    CGaussFilter(tSize Size) : CKernel2D(Size)
    {
        initKernel(size2Sigma(Size));
    }

    //! Destructor
    ~CGaussFilter() {}


    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    tPixel getResponse(const tImage& SrcImage, tSize x, tSize y)
    {
        // Compute filter response
        return tPixel(convolve<CKernel2D::tData>(SrcImage, x, y, *this));
    }

    //! Returns filter standard deviation.
    double getSigma() const { return m_dSigma; }

    //! Returns filter standard deviation.
    tSize getSize() const { return sigma2Size(m_dSigma); }

    //! Sets the filter size.
    inline void resize(tSize Size);

    //! Sets the filter standard deviation.
    inline void setSigma(double dSigma);


    //! Returns kernel size corresponding to a given sigma parameter.
    inline static tSize sigma2Size(double dSigma);

    //! Returns sigma parametr according to a given kernel size.
    inline static double size2Sigma(tSize Size);

    //! Returns value of the Gaussian function.
    inline static double getGaussianFuncValue(double dX,
                                              double dY,
                                              double dSigma
                                              );

protected:
    //! Standard deviation ("sigma") of the Gaussian filter.
    double m_dSigma;

protected:
    //! Computes the Gaussian filter kernel.
    void initKernel(double dSigma);
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsGaussian.hxx"


} // namespace img
} // namespace mds

#endif // MDS_IF_GAUSSIAN_H

