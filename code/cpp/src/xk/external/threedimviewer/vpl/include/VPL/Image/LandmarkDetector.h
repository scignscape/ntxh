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
 * Copyright (c) 2003-2008 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/07/03                       
 *
 * Description:
 * - Functions for 3D landmark detection.
 */

#ifndef VPL_LandmarkDetector_H
#define VPL_LandmarkDetector_H

#include "ImageTypes.h"
#include "Volume.h"
#include "Point3.h"

// STL
#include <vector>


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Base class for all 3D landmark detectors.
 * - Parameter V is a volume type.
 */
template <class V>
class CLandmarkDetector
{
public:
    //! Check that V is volume. You will see name of this enum somewhere
    //! in compiler error message if the type V is not volume.
    enum { TEMPLATE_PARAMETER_IS_NOT_VOLUME = V::CLASS_VOLUME };

    //! Volume type.
    typedef typename V::tVolume tVolume;

    //! Voxel type.
    typedef typename V::tVoxel tVoxel;

    //! Vector of found corners.
    typedef typename std::vector<CPoint3D> tCorners;

public:
    //! Default constructor.
    CLandmarkDetector() {}
    
    //! Virtual destructor.
    virtual ~CLandmarkDetector() {}

    //! Detects 3D corners in a given volume.
    //! - Returns false on failure. 
    virtual bool operator()(const tVolume& SrcVolume, tCorners& Corners) = 0;
};


} // namespace img
} // namespace vpl

#endif // VPL_LandmarkDetector_H 

