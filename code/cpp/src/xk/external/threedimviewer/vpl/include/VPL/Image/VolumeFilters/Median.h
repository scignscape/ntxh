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
 * Date:    2005/01/29                       
 * 
 * Description:
 * - Volume median filter definition.
 */

#ifndef VPL_VF_MEDIAN_H
#define VPL_VF_MEDIAN_H

#include <VPL/Base/Assert.h>
#include <VPL/Base/Types.h>
#include <VPL/Base/Data.h>
#include <VPL/Math/Base.h>
#include <VPL/Module/Progress.h>

// Median computation routine is used from image filter
#include <VPL/Image/Filters/Median.h>

#include "../VolumeFilter.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Template providing median volume filtering functions.
 * - Parameter V is a used volume type.
 */
template <class V>
class CVolumeMedianFilter : public CVolumeFilter<V>, public vpl::mod::CProgress
{
public:
    //! Volume filter base.
    typedef CVolumeFilter<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;

public:
    //! Constructor that creates a new median filter.
    //! - Parameter 'Size' is a window size and it must be an odd number.
    CVolumeMedianFilter(tSize Size)
        : m_MedianSize(Size)
        , m_Data(Size * Size * Size * ompGetMaxThreads())
    {
        VPL_ASSERT((Size % 2) == 1);
    }

    //! Destructor
    ~CVolumeMedianFilter() {}


    //! Median volume filtering
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    tVoxel getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Sets the windows size
    void setSize(tSize Size)
    {
        VPL_ASSERT((Size % 2) == 1);

        m_MedianSize = Size;
        m_Data.create(Size * Size * Size * ompGetMaxThreads());
    }

    //! Get filter size
    virtual tSize getSize() const {return m_MedianSize;}

protected:
    //! Median filter size
    tSize m_MedianSize;

    //! Internal data buffer
    vpl::base::CData<tVoxel> m_Data;
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Median.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_VF_MEDIAN_H

