//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/20                          \n
 *
 * $Id: mdsImageFunctions.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Basic image functions and operations.
 */

#ifndef MDS_IMAGEFUNCTIONS_H
#define MDS_IMAGEFUNCTIONS_H


//==============================================================================
/*
 * Include all predefined image functions.
 */

// General image functions
#include "ImageFunctions/mdsGeneral.h"

// Special image functions
#include "ImageFunctions/mdsConvolution.h"

// Image conversion functions
#include "ImageFunctions/mdsConversion.h"

// Image histogram functions
#include "ImageFunctions/mdsHistogram.h"

// Connected Component Labeling
#include "ImageFunctions/mdsConnectedComponents.h"


#endif // MDS_IMAGEFUNCTIONS_H

