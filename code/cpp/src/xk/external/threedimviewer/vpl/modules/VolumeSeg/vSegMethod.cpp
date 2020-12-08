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

#include "SegMethod.h"


namespace vpl
{
namespace volseg
{

//==============================================================================
/*
 * Implementation of the vpl::CSegMethod.
 */

// Segmentation method initialization
bool CSegMethod::init()
{
    return true;
}


// Image segmentation method
bool CSegMethod::operator()(const CSegMethod::tVolume& VPL_UNUSED(SrcVolume),
                            CSegMethod::tVolume& VPL_UNUSED(DstVolume)
                            )
{
    // Segmentation ...
    
    return true;
}


} // namespace volseg
} // namespace vpl

