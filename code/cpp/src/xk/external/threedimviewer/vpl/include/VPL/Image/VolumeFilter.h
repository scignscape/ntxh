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
 * Date:    2004/05/04                       
 * 
 * Description:
 * - Volume filtering functions.
 */

#ifndef VPL_VOLUMEFILTER_H
#define VPL_VOLUMEFILTER_H

#include "ImageTypes.h"
#include "Volume.h"
#include "FilterPolicy.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Base class for all volume filters.
 * - Parameter V is a volume type.
 */
template <class V>
struct CVolumeFilter
{
public:
    //! Check that type V is a volume. You will see name of this enum somewhere
    //! in compiler error message if the type V is not volume.
    enum { TEMPLATE_PARAMETER_IS_NOT_VOLUME = V::CLASS_VOLUME };

    //! Volume type.
    typedef typename V::tVolume tVolume;

    //! Volume voxel type.
    typedef typename V::tVoxel tVoxel;

protected:
    //! Voxel real sizes
    double m_dDX, m_dDY, m_dDZ;

public:
    //! Default constructor.
    CVolumeFilter() : m_dDX(1.0f), m_dDY(1.0), m_dDZ(1.0) {}
    
    //! Virtual destructor.
    virtual ~CVolumeFilter() {} 
    
    //! Filtering of input/source volume.
    //! - Returns false on failure.
    virtual bool operator()(const tVolume& SrcVolume, tVolume& DstVolume) = 0;

    //! Get voxel sizes
    double getDX() const {return m_dDX;}
    double getDY() const {return m_dDY;}
    double getDZ() const {return m_dDZ;}

    //! Get filter size
    virtual tSize getSize() const { return 0; }

    //! Get needed margin size
    virtual tSize getNeededMargin() const { return getSize() >> 1; }

    //! Set voxel sizes
    void setVoxel(double dx, double dy, double dz)
    {
        VPL_ASSERT(dx > 0.0 && dy > 0.0 && dz > 0.0);
        m_dDX = dx;
        m_dDY = dy;
        m_dDZ = dz;
    }
};


//==============================================================================
/*!
 * Base class for all volume filters that normalize filter response using
 * a predefined policy.
 * - Parameter V is an volume type.
 * - Policy NormPolicy is used for filter response normalization.
 */
template <class V, template <typename> class NormPolicy>
class CNormVolumeFilter : public CVolumeFilter<V>, public NormPolicy<typename V::tVoxel>
{
public:
    //! Base types.
    typedef CVolumeFilter<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;

    //! Filter response type.
    typedef typename CPixelTraits<tVoxel>::tFilterResponse tResult;

    //! Filter response normalization function.
    using NormPolicy<typename V::tVoxel>::normalize;

public:
    //! Default constructor.
    CNormVolumeFilter() {}
    
    //! Virtual destructor.
    ~CNormVolumeFilter() {}

    //! Filtering of input/source volume.
    //! - Returns false on failure.
    virtual bool operator()(const tVolume& SrcVolume, tVolume& DstVolume) = 0;
};


} // namespace img
} // namespace vpl

#endif // VPL_VOLUMEFILTER_H

