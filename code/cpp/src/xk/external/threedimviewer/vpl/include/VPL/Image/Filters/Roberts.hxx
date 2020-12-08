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
 * Date:    2005/09/15                       
 * 
 * Description:
 * - Roberts cross operator.
 */


//==============================================================================
/*
 * Methods templates.
 */

// Image filtering method
template <class I, template <typename> class N>
bool CRobertsX<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = vpl::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = vpl::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

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
template <class I, template <typename> class N>
typename CRobertsX<I,N>::tResult CRobertsX<I,N>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Compute filter response
    return tResult(SrcImage(x, y)) - tResult(SrcImage(x + 1, y + 1));
}


// Image filtering method
template <class I, template <typename> class N>
bool CRobertsY<I,N>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image size
    tSize XCount = vpl::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = vpl::math::getMin(SrcImage.getYSize(), DstImage.getYSize());

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
template <class I, template <typename> class N>
typename CRobertsY<I,N>::tResult CRobertsY<I,N>::getResponse(const tImage& SrcImage, tSize x, tSize y)
{
    // Compute filter response
    return tResult(SrcImage(x, y)) - tResult(SrcImage(x - 1, y + 1));
}

