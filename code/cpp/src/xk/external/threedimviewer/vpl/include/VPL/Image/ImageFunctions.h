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
 * Date:    2006/02/20                       
 *
 * Description:
 * - Basic image functions and operations.
 */

#ifndef VPL_IMAGEFUNCTIONS_H
#define VPL_IMAGEFUNCTIONS_H


//==============================================================================
/*
 * Include all predefined image functions.
 */

// General image functions
#include "ImageFunctions/General.h"

// Special image functions
#include "ImageFunctions/Convolution.h"

// Image conversion functions
#include "ImageFunctions/Conversion.h"

// Image histogram functions
#include "ImageFunctions/Histogram.h"

// Connected Component Labeling
#include "ImageFunctions/ConnectedComponents.h"


#endif // VPL_IMAGEFUNCTIONS_H

