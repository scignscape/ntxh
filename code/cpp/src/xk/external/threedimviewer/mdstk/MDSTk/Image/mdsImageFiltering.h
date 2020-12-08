//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/06                          \n
 *
 * $Id: mdsImageFiltering.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Predefined image filters.
 */

#ifndef MDS_ImageFiltering_H
#define MDS_ImageFiltering_H


//==============================================================================
/*
 * Include all predefined image filters.
 */

// General image filters.
#include "Filters/mdsConvolution.h"
#include "Filters/mdsMedian.h"
#include "Filters/mdsMinMax.h"

// Common image filters.
#include "Filters/mdsGaussian.h"
#include "Filters/mdsLoG.h"
#include "Filters/mdsDoG.h"

// Common image filters of concrete size.
#include "Filters/mdsLaplacian.h"
#include "Filters/mdsPrewit.h"
#include "Filters/mdsSobel.h"
#include "Filters/mdsRoberts.h"
#include "Filters/mdsAveraging.h"

// Local moments
#include "Filters/mdsLocalMoments.h"

// Anisotropic filtering
#include "Filters/mdsAnisotropic.h"


#endif // MDS_ImageFiltering_H

