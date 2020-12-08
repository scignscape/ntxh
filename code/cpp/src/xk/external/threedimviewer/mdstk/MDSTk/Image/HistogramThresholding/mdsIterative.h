//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/07/21                          \n
 *
 * $Id: mdsIterative.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Iterative histogram thresholding.
 */

#ifndef MDS_IterativeThresholding_H
#define MDS_IterativeThresholding_H

#include <MDSTk/Math/mdsVector.h>

#include "../mdsHistogramBase.h"
#include "../mdsImageFunctional.h"


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Global functions.
 */

//! Finds "optimal" thresholds using the iterative method.
template <class H>
inline bool findThresholdsIterative(const CHistogramBase<H>& Histogram,
                                    int NumOfThresholds,
                                    CMultiThresholding<typename H::tItem>& Thresholds
                                    );


//==============================================================================
/*
 * Method templates.
 */

// Include file containing function implementation
#include "mdsIterative.hxx"


} // namespace img
} // namespace mds

#endif // MDS_IterativeThresholding_H

