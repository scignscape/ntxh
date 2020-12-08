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
 * Author:  Michal Spanel, spanel@fit.vutbr.cz   
 * Date:    2008/07/24                           
 *
 * Based on the code by Ali Rahimi, ali@mit.edu, Jun 2001. 
 *
 * Description:
 * - Connected Components Labeling
 */

#ifndef VPL_ImageFunctions_ConnectedComponents_H
#define VPL_ImageFunctions_ConnectedComponents_H

#include <VPL/Math/Base.h>

#include "../ImageBase.h"
#include "../ImageFunctional.h"
#include "../Utilities/BlobLabeling.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Global functions.
 */

//! Implementation of the well known Connected Components Labeling algorithm.
//! - It produces a labeled image.
//! - Function object F is used to evaluate similarity of two neighbouring
//!   image pixels. It must return true if both pixels fall to the same
//!   region.
template <class I1, class I2, class F>
inline bool findConnectedComponents(const CImageBase<I1>& SrcImage,
                                    CImageBase<I2>& LabelImage,
                                    F CompareFunc = F()
                                    );


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "ConnectedComponents.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_ImageFunctions_ConnectedComponents_H

