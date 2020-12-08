//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)        \n
 * Copyright (c) 2003-2008 by Michal Spanel         \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz      \n
 * Date:    2008/07/24                              \n
 *
 * $Id: mdsConnectedComponents.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Based on the code by Ali Rahimi, ali@mit.edu, Jun 2001. 
 *
 * Description:
 * - Connected Components Labeling
 */

#ifndef MDS_ImageFunctions_ConnectedComponents_H
#define MDS_ImageFunctions_ConnectedComponents_H

#include <MDSTk/Math/mdsBase.h>

#include "../mdsImageBase.h"
#include "../mdsImageFunctional.h"
#include "../Utilities/mdsBlobLabeling.h"


namespace mds
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
#include "mdsConnectedComponents.hxx"


} // namespace img
} // namespace mds

#endif // MDS_ImageFunctions_ConnectedComponents_H

