//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2010 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/02                          \n
 *
 * $Id: mdsInstantiations.cpp 1707 2010-05-05 11:00:46Z spanel $
 * 
 * Description:
 * - Definition of basic template instantiations.
 */

#include <MDSTk/Image/mdsImage.h>
#include <MDSTk/Image/mdsVolume.h>
#include <MDSTk/Image/mdsCvImage.h>


namespace mds
{
namespace img
{

//=============================================================================
/*
 * Basic template instantiations...
 */

#ifdef MDS_EXPLICIT_TEMPLATE_INSTANTIATION

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

#ifdef MDS_OPENCV_ENABLED

template class CvImage<tPixel8>;
template class CvImage<tPixel16>;
template class CvImage<tPixel32>;
template class CvImage<tFloatPixel>;
template class CvImage<tDensityPixel>;
template class CvImage<tRGBPixel>;
template class CvImage<tComplexPixel>;

#endif // MDS_OPENCV_ENABLED

#endif // MDS_EXPLICIT_TEMPLATE_INSTANTIATION


} // namespace img
} // namespace mds

