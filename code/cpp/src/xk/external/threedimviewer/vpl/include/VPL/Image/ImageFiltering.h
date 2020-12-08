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
 * - Predefined image filters.
 */

#ifndef VPL_ImageFiltering_H
#define VPL_ImageFiltering_H


//==============================================================================
/*
 * Include all predefined image filters.
 */

// General image filters.
#include "Filters/Convolution.h"
#include "Filters/Median.h"
#include "Filters/MinMax.h"

// Common image filters.
#include "Filters/Bilateral.h"
#include "Filters/Gaussian.h"
#include "Filters/LoG.h"
#include "Filters/DoG.h"

// Common image filters of concrete size.
#include "Filters/Laplacian.h"
#include "Filters/Prewit.h"
#include "Filters/Sobel.h"
#include "Filters/Roberts.h"
#include "Filters/Averaging.h"

// Local moments
#include "Filters/LocalMoments.h"

// Anisotropic filtering
#include "Filters/Anisotropic.h"


#endif // VPL_ImageFiltering_H

