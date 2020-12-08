//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/06                          \n
 *
 * $Id: mdsVolumeFiltering.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Predefined volume filters.
 */

#ifndef MDS_VolumeFiltering_H
#define MDS_VolumeFiltering_H


//==============================================================================
/*
 * Include all predefined volume filters.
 */

// General volume filters
#include "VolumeFilters/mdsConvolution.h"
#include "VolumeFilters/mdsMedian.h"
#include "VolumeFilters/mdsMinMax.h"
#include "VolumeFilters/mdsMisc.h"

// Common volume filters.
#include "VolumeFilters/mdsGaussian.h"

// Common volume filters of concrete size
#include "VolumeFilters/mdsLaplacian.h"
#include "VolumeFilters/mdsPrewit.h"
#include "VolumeFilters/mdsSobel.h"
#include "VolumeFilters/mdsAveraging.h"

// Anisotropic filtering
#include "VolumeFilters/mdsAnisotropic.h"


#endif // MDS_VolumeFiltering_H

