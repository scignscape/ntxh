//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/08                          \n
 *
 * $Id: mdsAveraging.hxx 2084 2012-02-13 10:23:58Z spanel $
 * 
 * Description:
 * - Averaging image filters.
 */


//==============================================================================
/*
 * Methods templates.
 */

// Filter kernel
template <class I>
const CKernel2D::tData CAvg3Filter<I>::KERNEL[] =
{
    1.0f,  2.0f,  1.0f,
    2.0f,  4.0f,  2.0f,
    1.0f,  2.0f,  1.0f
};


// Image filtering method
template <class I>
bool CAvg3Filter<I>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = mds::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = mds::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    // Filter the image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            DstImage.set(x, y, getResponse(SrcImage, x, y));
        }
    }

    // O.K.
    return true;
}


// Image filter response
template <class I>
typename CAvg3Filter<I>::tPixel CAvg3Filter<I>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Output normalization
    static const CKernel2D::tData Denom = 1.0f / DENOM;

    // Filter kernel
    static const CKernel2D Kernel(KERNEL, getSize());

    // Compute filter response
    return tPixel(Denom * convolve<CKernel2D::tData>(SrcImage, x, y, Kernel));
}


// Filter kernel
template <class I>
const CKernel2D::tData CAvg5Filter<I>::KERNEL[] =
{
    1.0f,  2.0f,  3.0f,  2.0f,  1.0f,
    2.0f,  4.0f,  6.0f,  4.0f,  2.0f,
    3.0f,  6.0f,  9.0f,  6.0f,  3.0f,
    2.0f,  4.0f,  6.0f,  4.0f,  2.0f,
    1.0f,  2.0f,  3.0f,  2.0f,  1.0f
};


// Image filtering method
template <class I>
bool CAvg5Filter<I>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = mds::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = mds::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    // Filter the image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            DstImage.set(x, y, getResponse(SrcImage, x, y));
        }
    }

    // O.K.
    return true;
}


// Image filter response
template <class I>
typename CAvg5Filter<I>::tPixel CAvg5Filter<I>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Output normalization
    static const CKernel2D::tData Denom = 1.0f / DENOM;

    // Filter kernel
    static const CKernel2D Kernel(KERNEL, getSize());

    // Compute filter response
    return tPixel(Denom * convolve<CKernel2D::tData>(SrcImage, x, y, Kernel));
}


// Filter kernel
template <class I>
const CKernel2D::tData CAvg7Filter<I>::KERNEL[] =
{
    1.0f,  2.0f,  3.0f,  4.0f,  3.0f,  2.0f,  1.0f,
    2.0f,  4.0f,  6.0f,  8.0f,  6.0f,  4.0f,  2.0f,
    3.0f,  6.0f,  9.0f, 12.0f,  9.0f,  6.0f,  3.0f,
    4.0f,  8.0f, 12.0f, 16.0f, 12.0f,  8.0f,  4.0f,
    3.0f,  6.0f,  9.0f, 12.0f,  9.0f,  6.0f,  3.0f,
    2.0f,  4.0f,  6.0f,  8.0f,  6.0f,  4.0f,  2.0f,
    1.0f,  2.0f,  3.0f,  4.0f,  3.0f,  2.0f,  1.0f
};


// Image filtering method
template <class I>
bool CAvg7Filter<I>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = mds::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = mds::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

    // Filter the image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < YCount; ++y )
    {
        for( tSize x = 0; x < XCount; ++x )
        {
            DstImage.set(x, y, getResponse(SrcImage, x, y));
        }
    }

    // O.K.
    return true;
}


// Image filter response
template <class I>
typename CAvg7Filter<I>::tPixel CAvg7Filter<I>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Output normalization
    static const CKernel2D::tData Denom = 1.0f / DENOM;

    // Filter kernel
    static const CKernel2D Kernel(KERNEL, getSize());

    // Compute filter response
    return tPixel(Denom * convolve<CKernel2D::tData>(SrcImage, x, y, Kernel));
}

