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
 * Date:    2005/09/06                       
 * 
 * Description:
 * - Predefined volume filters.
 */

#ifndef VPL_VolumeFiltering_H
#define VPL_VolumeFiltering_H


//==============================================================================
/*
 * Include all predefined volume filters.
 */

// General volume filters
#include "VolumeFilters/Convolution.h"
#include "VolumeFilters/Median.h"
#include "VolumeFilters/MinMax.h"
#include "VolumeFilters/Misc.h"

// Common volume filters.
#include "VolumeFilters/Gaussian.h"
#include "VolumeFilters/Bilateral.h"

// Common volume filters of concrete size
#include "VolumeFilters/Laplacian.h"
#include "VolumeFilters/Prewit.h"
#include "VolumeFilters/Sobel.h"
#include "VolumeFilters/Averaging.h"

// Anisotropic filtering
#include "VolumeFilters/Anisotropic.h"


#endif // VPL_VolumeFiltering_H

