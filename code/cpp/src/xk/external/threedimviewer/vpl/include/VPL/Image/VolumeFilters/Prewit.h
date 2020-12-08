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
 * - Prewit gradient edge detectors.
 */

#ifndef VPL_VF_PREWIT_H
#define VPL_VF_PREWIT_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../VolumeFilter.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Prewit gradient edge detector (x-axis).
 * - Parameter V is a used image type.
 * - Kernel definition: \n
 *    [ -1  0  1 ]
 *    [ -1  0  1 ]
 *    [ -1  0  1 ]
 *   1 [ -1  0  1 ]  \n
 *   - [ -1  0  1 ]  \n
 *   9 [ -1  0  1 ]  \n
 *      [ -1  0  1 ] \n
 *      [ -1  0  1 ] \n
 *      [ -1  0  1 ] \n
 */
template <class V, template <typename> class N = CDefaultFilterPolicy>
class CVolumePrewitX : public CNormVolumeFilter<V,N>
{
public:
    //! Volume filter base.
    typedef CNormVolumeFilter<V,N> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 9;

public:
    //! Default constructor.
    CVolumePrewitX() {}

    //! Destructor.
    ~CVolumePrewitX() {}

    //! Filtering of input/source volume.
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    inline tResult getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Returns filter standard deviation.
    virtual tSize getSize() const { return 3; }

};


//==============================================================================
/*!
 * Prewit gradient edge detector (y-axis).
 * - Parameter V is a used image type.
 * - Kernel definition: \n
 *    [ -1 -1 -1 ]
 *    [  0  0  0 ]
 *    [  1  1  1 ]
 *   1 [ -1 -1 -1 ]  \n
 *   - [  0  0  0 ]  \n
 *   9 [  1  1  1 ]  \n
 *      [ -1 -1 -1 ] \n
 *      [  0  0  0 ] \n
 *      [  1  1  1 ] \n
 */
template <class V, template <typename> class N = CDefaultFilterPolicy>
class CVolumePrewitY : public CNormVolumeFilter<V,N>
{
public:
    //! Volume filter base.
    typedef CNormVolumeFilter<V,N> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 9;

public:
    //! Default constructor.
    CVolumePrewitY() {}

    //! Destructor.
    ~CVolumePrewitY() {}

    //! Filtering of input/source volume.
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    inline tResult getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Returns filter standard deviation.
    virtual tSize getSize() const { return 3; }

};


//==============================================================================
/*!
 * Prewit gradient edge detector (z-axis).
 * - Parameter V is a used image type.
 * - Kernel definition: \n
 *    [ -1 -1 -1 ]
 *    [ -1 -1 -1 ]
 *    [ -1 -1 -1 ]
 *   1 [  0  0  0 ]  \n
 *   - [  0  0  0 ]  \n
 *   9 [  0  0  0 ]  \n
 *      [  1  1  1 ] \n
 *      [  1  1  1 ] \n
 *      [  1  1  1 ] \n
 */
template <class V, template <typename> class N = CDefaultFilterPolicy>
class CVolumePrewitZ : public CNormVolumeFilter<V,N>
{
public:
    //! Volume filter base.
    typedef CNormVolumeFilter<V,N> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 9;

public:
    //! Default constructor.
    CVolumePrewitZ() {}

    //! Destructor.
    ~CVolumePrewitZ() {}

    //! Filtering of input/source volume.
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    inline tResult getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Returns filter standard deviation.
    virtual tSize getSize() const { return 3; }

};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Prewit.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_VF_PREWIT_H

