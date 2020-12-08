//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/15                          \n
 *
 * $Id: mdsSobel.hxx 2084 2012-02-13 10:23:58Z spanel $
 * 
 * Description:
 * - Sobel operator.
 */


//==============================================================================
/*
 * Methods templates.
 */

// Image filtering method
template <typename I, template <typename> class N>
bool CSobelX<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
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
            tResult Value = getResponse(SrcImage, x, y);
            DstImage.set(x, y, base::normalize(Value));
        }
    }

    // O.K.
    return true;
}


// Image filter response
template <typename I, template <typename> class N>
inline typename CSobelX<I,N>::tResult CSobelX<I,N>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        2 * tResult(SrcImage(x + 1, y))
                        + tResult(SrcImage(x + 1, y - 1))
                        + tResult(SrcImage(x + 1, y + 1))
                        - 2 * tResult(SrcImage(x - 1, y))
                        - tResult(SrcImage(x - 1, y - 1))
                        - tResult(SrcImage(x - 1, y + 1))
                        );
    return Value;
}


// Image filtering method
template <typename I, template <typename> class N>
bool CSobelY<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
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
            tResult Value = getResponse(SrcImage, x, y);
            DstImage.set(x, y, base::normalize(Value));
        }
    }

    // O.K.
    return true;
}


// Image filter response
template <typename I, template <typename> class N>
inline typename CSobelY<I,N>::tResult CSobelY<I,N>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Output normalization
    static const tResult Denom = 1.0f / DENOM;

    // Compute filter response
    tResult Value = Denom * (
                        2 * tResult(SrcImage(x, y + 1))
                        + tResult(SrcImage(x + 1, y + 1))
                        + tResult(SrcImage(x - 1, y + 1))
                        - 2 * tResult(SrcImage(x, y - 1))
                        - tResult(SrcImage(x + 1, y - 1))
                        - tResult(SrcImage(x - 1, y - 1))
                     );
    return Value;
}

