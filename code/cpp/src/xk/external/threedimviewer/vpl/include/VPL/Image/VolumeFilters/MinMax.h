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
 * Copyright (c) 2003-2006 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/06/14                       
 * 
 * Description:
 * - Volume min and max filters.
 */

#ifndef VPL_VF_MINMAX_H
#define VPL_VF_MINMAX_H

#include <VPL/Base/Assert.h>
#include <VPL/Base/Types.h>
#include <VPL/Base/Data.h>
#include <VPL/Math/Base.h>

#include "../VolumeFilter.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Template providing min-value volume filtering functions.
 * - Parameter V is a used volume type.
 */
template <class V>
class CVolumeMinFilter : public CVolumeFilter<V>
{
public:
    //! Volume filter base.
    typedef CVolumeFilter<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;

public:
    //! Constructor that creates a new filter.
    //! - Parameter 'Size' is a window size and it must be an odd number.
    CVolumeMinFilter(tSize Size) : m_MinSize(Size)
    {
        VPL_ASSERT((Size % 2) == 1);
    }

    //! Destructor.
    ~CVolumeMinFilter() {}


    //! Min volume filtering.
    //! - Returns false on failure.
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    tVoxel getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Sets the windows size.
    void setSize(tSize Size)
    {
        VPL_ASSERT((Size % 2) == 1);

        m_MinSize = Size;
    }

    //! Get filter size
    virtual tSize getSize() const {return 0;}

protected:
    //! Min filter size.
    tSize m_MinSize;
};


//==============================================================================
/*!
 * Template providing max-value volume filtering functions.
 * - Parameter V is a used volume type.
 */
template <class V>
class CVolumeMaxFilter : public CVolumeFilter<V>
{
public:
    //! Volume filter base.
    typedef CVolumeFilter<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;

public:
    //! Constructor that creates a new filter.
    //! - Parameter 'Size' is a window size and it must be an odd number.
    CVolumeMaxFilter(tSize Size) : m_MaxSize(Size)
    {
        VPL_ASSERT((Size % 2) == 1);
    }

    //! Destructor.
    ~CVolumeMaxFilter() {}


    //! Max volume filtering.
    //! - Returns false on failure.
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    tVoxel getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Sets the windows size.
    void setSize(tSize Size)
    {
        VPL_ASSERT((Size % 2) == 1);

        m_MaxSize = Size;
    }

    //! Get filter size
    virtual tSize getSize() const {return 0;}

protected:
    //! Max filter size.
    tSize m_MaxSize;
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates.
#include "MinMax.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_VF_MINMAX_H

