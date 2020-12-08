//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)      \n
 * Copyright (c) 2003-2005 by Michal Spanel       \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz    \n
 * Date:    2005/09/08                            \n
 *
 * $Id: mdsConvolution.hxx 2084 2012-02-13 10:23:58Z spanel $
 *
 * Description:
 * - Convolution image filter.
 */


//==============================================================================
/*
 * Methods templates.
 */

// Image filtering method
template <class I, template <typename> class N>
bool CConvolutionFilter<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
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

