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
 * Copyright (c) 2009 by Michal Spanel       
 *
 * Authors: Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/01/09                       
 *
 * Description:
 * - Basic feature vector characterizing an image region.
 * - May be extracted for any set of pixels.
 */

#ifndef VPL_PixelStats_H
#define VPL_PixelStats_H

#include "FeatureVector.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Feature vector containing basic statistics like mean value and variance.
 * It may be extracted from any set of image pixels.
 */
class CPixelStats : public CFeatureVector<double, 2>
{
public:
    //! Base class.
    typedef CFeatureVector<double, 2> tBase;

    //! Type representing a single feature value.
    typedef tBase::tFeature tFeature;

    //! Indexes of the most important features.
    enum
    {
        MEAN_VALUE  = 0,
        VARIANCE    = 1
    };

public:
    //! Default constructor.
    CPixelStats() : tBase(FeatureVector::NOT_EVALUATED) {}

    //! Copy constructor.
    CPixelStats(const CPixelStats& Stats) : tBase(Stats) {}

    //! Destructor.
    ~CPixelStats() {}

    //! Assignment operator.
    CPixelStats& operator =(const CPixelStats& Stats)
    {
        static_cast<tBase&>(*this) = static_cast<const tBase&>(Stats);
        return *this;
    }

    //! Returns mean value of all pixels.
    tFeature& getMean() { return at(MEAN_VALUE); }
    const tFeature& getMean() const { return at(MEAN_VALUE); }

    //! Sets the mean value.
    void setMean(const tFeature& Value) { set(tSize(MEAN_VALUE), Value); }

    //! Returns variance of all pixels.
    tFeature& getVariance() { return at(VARIANCE); }
    const tFeature& getVariance() const { return at(VARIANCE); }

    //! Sets the pixel value variance.
	void setVariance(const tFeature& Value) { set(tSize(VARIANCE), Value); }

    //! Returns the number of pixels counted.
    int getNumOfPixels() const { return getNumOfSamples(); }
};


} // namespace img
} // namespace vpl

#endif // VPL_PixelStats_H

