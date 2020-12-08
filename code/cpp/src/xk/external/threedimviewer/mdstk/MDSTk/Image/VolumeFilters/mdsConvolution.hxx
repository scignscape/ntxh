//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/04                          \n
 *
 * $Id: mdsConvolution.hxx 2065 2012-02-02 23:29:38Z spanel $
 * 
 * Description:
 * - Convolution volume filter.
 */


//==============================================================================
/*
 * Methods templates.
 */

// Volume filtering method
template <class V, template <typename> class N>
bool CVolumeConvolutionFilter<V,N>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
{
    // Volume size
    tSize XCount = mds::math::getMin(SrcVolume.getXSize(), DstVolume.getXSize());
    tSize YCount = mds::math::getMin(SrcVolume.getYSize(), DstVolume.getYSize());
    tSize ZCount = mds::math::getMin(SrcVolume.getZSize(), DstVolume.getZSize());

    // Filter the image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize z = 0; z < ZCount; ++z )
    {
        for( tSize y = 0; y < YCount; ++y )
        {
            for( tSize x = 0; x < XCount; ++x )
            {
                tResult Value = getResponse(SrcVolume, x, y, z);
                DstVolume.set(x, y, z, base::normalize(Value));
            }
        }
    }

    // O.K.
    return true;
}

