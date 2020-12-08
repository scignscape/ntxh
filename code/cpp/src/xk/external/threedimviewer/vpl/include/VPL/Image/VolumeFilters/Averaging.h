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
 * Date:    2005/09/20                       
 * 
 * Description:
 * - Averaging volume filters.
 */

#ifndef VPL_VF_AVERAGING_H
#define VPL_VF_AVERAGING_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../VolumeFilter.h"
#include "../VolumeFunctions.h"
#include "../Kernel.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Averaging image filter (3x3 version).
 * - Parameter V is a used image type.
 * - Kernel definition: \n
 *     [ 1  1  1 ]
 *     [ 1  2  1 ]
 *     [ 1  1  1 ]
 *    1 [ 1  2  1 ]  \n
 *   -- [ 2  4  2 ]  \n
 *   36 [ 1  2  1 ]  \n
 *       [ 1  1  1 ] \n
 *       [ 1  2  1 ] \n
 *       [ 1  1  1 ] \n
 */
template <class V>
class CVolumeAvg3Filter : public CVolumeFilter<V>
{
public:
    //! Volume filter base.
    typedef CVolumeFilter<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;

    //! Number used to divide filter response
    static const int DENOM = 36;

    //! Filter kernel
    static const CKernel3D::tData KERNEL[];

public:
    //! Default constructor.
    CVolumeAvg3Filter() {}

    //! Destructor.
    ~CVolumeAvg3Filter() {}

    //! Filtering of input/source volume. Point filter responses are written
    //! to the destination volume.
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    tVoxel getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Returns filter standard deviation.
    virtual tSize getSize() const { return 3; }

};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Averaging.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_VF_AVERAGING_H

