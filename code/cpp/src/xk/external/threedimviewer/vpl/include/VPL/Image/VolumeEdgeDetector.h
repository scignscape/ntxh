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
 * Date:    2006/04/24                       
 * 
 * Description:
 * - More sophisticated functions for volume edge detection.
 */

#ifndef VPL_VOLUMEEDGEDETECTOR_H
#define VPL_VOLUMEEDGEDETECTOR_H

#include "ImageTypes.h"
#include "Volume.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Base class for all volume edge detectors.
 * - Parameter V is volume type.
 */
template <typename V>
class CVolumeEdgeDetector
{
public:
    //! Check that V is a volume. You will see name of this enum somewhere
    //! in compiler error message if the type V is not volume.
    enum { TEMPLATE_PARAMETER_IS_NOT_VOLUME = V::CLASS_VOLUME };

    //! Volume type.
    typedef typename V::tVolume tVolume;

    //! Voxel type.
    typedef typename V::tVoxel tVoxel;

public:
    //! Default constructor.
    CVolumeEdgeDetector() {}
    
    //! Virtual destructor.
    virtual ~CVolumeEdgeDetector() {}
    
    //! Edge detection in a given volume.
    //! - Returns false on failure.
    virtual bool operator()(const tVolume& SrcVolume, tVolume& DstVolume) = 0;
};


} // namespace img
} // namespace vpl

#endif // VPL_VOLUMEEDGEDETECTOR_H

