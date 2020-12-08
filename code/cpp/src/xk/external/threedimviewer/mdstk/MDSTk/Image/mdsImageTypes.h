//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/24                          \n
 *
 * $Id: mdsImageTypes.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Basic types used by the image library.
 */

#ifndef MDS_IMAGETYPES_H
#define MDS_IMAGETYPES_H

#include <MDSTk/Base/mdsSetup.h>


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Additional types definitions.
 */

//! Coordinate of a point in 2D (image) and 3D (volume) space.
typedef double  tCoordinate;

//! Type of convolution kernel data element.
typedef float   tConvKernelData;


} // namespace img
} // namespace mds

#endif // MDS_IMAGETYPES_H

