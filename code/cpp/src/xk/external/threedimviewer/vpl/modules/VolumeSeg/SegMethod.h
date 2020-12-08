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
 * Date:    2005/01/25                       
 *
 * File description:
 * - Sample implementation of a volume segmentation method.
 */

#ifndef VPL_SEGMETHOD_H
#define VPL_SEGMETHOD_H

#include <VPL/Base/Setup.h>
#include <VPL/Image/Volume.h>


namespace vpl
{
namespace volseg
{

//==============================================================================
/*!
 * Class template providing volume segmentation functions.
 * - Sample code.
 * - Rename this class according to name of your segmentation method.
 */
class CSegMethod
{
public:
    //! Image type.
    typedef vpl::img::CDVolume tVolume;

    //! Image pixel type.
    typedef vpl::img::CDVolume::tVoxel tVoxel;

public:
    //! Constructor.
    CSegMethod() {}

    //! Virtual destructor.
    virtual ~CSegMethod() {}

    //! Initialization of the segmentation method.
    //! - Returns false on failure.
    bool init();

    //! Volume segmentation.
    //! - Voxel values of the output/destination volume represent segment indexes.
    //! - Returns false on failure.
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);
};


} // namespace volseg
} // namespace vpl

#endif // VPL_SEGMETHOD_H

