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
 * Date:    2004/04/20                       
 * 
 * Description:
 * - Gaussian image pyramid.
 */


//=============================================================================
/*
 * Implementation of the vpl::CPyramid class template.
 */

//! Sigma parameter of the Gaussian filter which is used to smooth images.
template <class I>
const double CPyramid<I>::SIGMA = 1.5;


// Constructor
template <class I>
CPyramid<I>::CPyramid(tSize SubSampling,
                      tSize Levels,
                      const CImageBase<tImage>& Image
                      )
    : m_Levels(0)
    , m_SmoothingFilter(SIGMA + SubSampling)
{
    // Create a new image pyramid
    create(SubSampling, Levels, Image);
}


// Destructor
template <class I>
CPyramid<I>::~CPyramid()
{
    m_Images.clear();
}


// Creates a new image pyramid based on a given image
template <class I>
bool CPyramid<I>::create(tSize SubSampling,
                         tSize Levels,
                         const CImageBase<tImage>& Image
                         )
{
    VPL_CHECK(Levels >= 1 && SubSampling >= 2, return false);

    const I& ImageImpl = Image.getImpl();

    // Half of the pyramid subsampling rate
    tSize SubHalf = SubSampling / 2;

    // The image margin
    tSize Margin = ImageImpl.getMargin();

    // Destroy the old image pyramid
    m_Images.clear();

    // Zero pyramid level - copy the original image
    tImageSmartPtr spNewImage(new tImage(ImageImpl));
    m_Images.push_back(spNewImage);

    // Re-initialize the smoothing filter
    double dSigma = SIGMA + SubSampling;
    if( m_SmoothingFilter.getSigma() != dSigma )
    {
        m_SmoothingFilter.setSigma(dSigma);
    }

    // Helper smoothed image
    tImageSmartPtr spSmoothed(new tImage(ImageImpl.getXSize(), ImageImpl.getYSize(), Margin));

    // Create subsequent pyramid levels
    for( tSize i = 1; i < Levels; ++i )
    {
        // Get image on the previous pyramid level
        tImageSmartPtr spPrevious(m_Images[i - 1]);

        // Smooth image using Gaussian filter
        m_SmoothingFilter(*spPrevious, *spSmoothed);

        // Image size on the i-th pyramid level
        tSize sx = spPrevious->getXSize() / SubSampling;
        tSize sy = spPrevious->getYSize() / SubSampling;

        // Create a new image
        spNewImage = new tImage(sx, sy, Margin);
        m_Images.push_back(spNewImage);

        // Subsample image from the previous pyramid level
        for( tSize x = 0; x < sx; ++x )
        {
            for( tSize y = 0; y < sy; ++y )
            {
                tPixel Value = spPrevious->at(SubSampling * x + SubHalf,
                                              SubSampling * y + SubHalf
                                              );
                spNewImage->set(x, y, Value);
            }
        }
    }

    // Image pyramid has been created successfully
    m_SubSampling = SubSampling;
    m_Levels = Levels;

    // O.K.
    return true;
}


template <class I>
typename CPyramid<I>::tImage& CPyramid<I>::getImage(tSize Level)
{
    VPL_ASSERT(Level >= 0 && Level < m_Levels);

    return *(m_Images[Level]);
}


template <class I>
const typename CPyramid<I>::tImage& CPyramid<I>::getImage(tSize Level) const
{
    VPL_ASSERT(Level >= 0 && Level < m_Levels);

    return *(m_Images[Level]);
}


template <class I>
typename CPyramid<I>::tImage* CPyramid<I>::getImagePtr(tSize Level)
{
    if( Level < 0 || Level >= m_Levels )
    {
        return NULL;
    }

    return m_Images[Level];
}

