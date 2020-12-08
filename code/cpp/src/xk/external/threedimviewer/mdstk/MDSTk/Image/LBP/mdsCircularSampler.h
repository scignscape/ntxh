//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)          \n
 * Copyright (c) 2003-2009 by Michal Spanel           \n
 *
 * Authors: Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz        \n
 * Date:    2008/03/09                                \n
 *
 * $Id: mdsCircularSampler.h 2100 2012-02-17 07:36:55Z spanel $
 *
 * This code is partially based on the free software
 * Cpplibs C++ libraries and PRAPI - The Pattern Recognition Application
 *   Programmer's Interface.
 *
 * The Cpplibs and PRAPI suite
 * Copyright (C) 2001 Topi M�enp�� and Jaakko Viertola
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *       1.Redistributions of source code must retain all copyright
 *         notices, this list of conditions and the following disclaimer.
 *       2.Redistributions in binary form must reproduce the above
 *         copyright notice, this list of conditions and the following
 *         disclaimer in the documentation and/or other materials provided
 *         with the distribution.
 *       3.The name(s) of the author(s) may not be used to endorse or
 *         promote products derived from this software without specific
 *         prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS
 *   OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT,
 *   INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 *   STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 *   IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 *
 * Description:
 * - Circle sampling of image pixels given a radius and a number of samples.
 */

#ifndef MDS_LBP_CircularSampler_H
#define MDS_LBP_CircularSampler_H

#include <MDSTk/Image/mdsImage.h>
#include <MDSTk/Image/mdsPoint3.h>

// STL
#include <vector>
#include <cmath>


namespace mds
{
namespace lbp
{

//=============================================================================
/*
 * Definition of constants, etc.
 */

namespace CircularSampler
{
    //! Default samples count (as in original LBP).
    const int DEFAULT_NUM_OF_SAMPLES = 8;

    //! Default radius (as in original LBP).
    const mds::img::tCoordinate DEFAULT_RADIUS = 1.0;
}


//=============================================================================
/*!
 * Class for getting along samples in a circular neighborhood around
 * a given center pixel. Samples are equally spaced pixels on a circle
 * of a specified radius. Number of samples and the radius can be set.
 * Samples which don't exactly fit the pixel grid are interpolated.
 * - Template parameter I is an image type.
 */
template <class I>
class CCircularSampler
{
public:
    //! Check that I is an image. You will see name of this enum somewhere
    //! in compiler error message if the type I is not image.
    enum { TEMPLATE_PARAMETER_IS_NOT_IMAGE = I::CLASS_IMAGE };

    //! Image type.
    typedef typename I::tImage tImage;

    //! Image pixel type.
    typedef typename I::tPixel tPixel;

    //! Float coordinates.
    mds::img::tCoordinate tCoordinate;

    //! Vector of samples.
    typedef std::vector<tPixel> tSamples;

public:
    //! Default constructor.
    CCircularSampler(int NumOfSamples = CircularSampler::DEFAULT_NUM_OF_SAMPLES,
                     mds::img::tCoordinate Radius = CircularSampler::DEFAULT_RADIUS
                     )
        : m_Radius(Radius)
        , m_NumOfSamples(NumOfSamples)
        , m_spImage(NULL)
    {
        MDS_ASSERT(Radius > 0.0 && NumOfSamples > 0);

        updateCoords();
    }

    //! Destructor.
    ~CCircularSampler() {}

    //! Sets the image.
    CCircularSampler& setImage(tImage *pImage)
    {
        MDS_ASSERT(pImage && pImage->getMargin() >= getMinMargin());

        m_spImage = pImage;
//        updateCoords();
        return *this;
    }


    //! Returns samples count.
    int getNumOfSamples() const { return m_NumOfSamples; }

    //! Returns radius of the neighbourhood.
	mds::img::tCoordinate getRadius() const { return m_Radius; }

	//! Returns margin needed for sampled pixels to be inside an image.
	mds::tSize getMinMargin() const { return mds::tSize(std::ceil(m_Radius)); }


    //! Applies a given functor to all samples in circular neighbourhood
    //! of a given center pixel.
    template <class Function>
    inline Function forEach(tSize x, tSize y, Function Func);

    //! Returns samples from circular neighborhood of a given center pixel.
    inline bool getSamples(tSize x, tSize y, tSamples& Result);

    //! Returns value of the center pixel.
    inline tPixel getCenter(tSize x, tSize y);

protected:
    //! Relative coordinates of samples.
    typedef std::vector<mds::img::CPoint3D> tCoords;

protected:
    //! Neighbourhood radius.
    mds::img::tCoordinate m_Radius;

    //! Number of samples.
    int m_NumOfSamples;

    //! Image to obtain samples from.
    typename tImage::tSmartPtr m_spImage;

    //! Relative coordinates of points to be sampled. First one has coordinates
    //! [radius,0], others following CCW.
    tCoords m_Coords;

    //! Update relative coordinates of samples.
    inline void updateCoords();
};


//=============================================================================
/*
 * Implementation of methods.
 */

#include "mdsCircularSampler.hxx"


} // namespace lbp
} // namespace mds

#endif // MDS_LBP_CircularSampler_H
