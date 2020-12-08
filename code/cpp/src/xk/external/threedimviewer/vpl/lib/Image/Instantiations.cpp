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
 * Copyright (c) 2010 by Michal Spanel       
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/02                       
 * 
 * Description:
 * - Definition of basic template instantiations.
 */

#include <VPL/Image/Image.h>
#include <VPL/Image/Volume.h>
#include <VPL/Image/CvImage.h>


namespace vpl
{
namespace img
{

//=============================================================================
/*
 * Basic template instantiations...
 */

#ifdef VPL_EXPLICIT_TEMPLATE_INSTANTIATION

template class CImage<tPixel8>;
template class CImage<tPixel16>;
template class CImage<tPixel32>;
template class CImage<tFloatPixel>;
template class CImage<tDensityPixel>;
template class CImage<tRGBPixel>;
template class CImage<tComplexPixel>;

template class CVolume<tPixel8>;
template class CVolume<tPixel16>;
template class CVolume<tPixel32>;
template class CVolume<tFloatPixel>;
template class CVolume<tDensityPixel>;
template class CVolume<tRGBPixel>;

#ifdef VPL_OPENCV_ENABLED

template class CvImage<tPixel8>;
template class CvImage<tPixel16>;
template class CvImage<tPixel32>;
template class CvImage<tFloatPixel>;
template class CvImage<tDensityPixel>;
template class CvImage<tRGBPixel>;
template class CvImage<tComplexPixel>;

#endif // VPL_OPENCV_ENABLED

#endif // VPL_EXPLICIT_TEMPLATE_INSTANTIATION


} // namespace img
} // namespace vpl

