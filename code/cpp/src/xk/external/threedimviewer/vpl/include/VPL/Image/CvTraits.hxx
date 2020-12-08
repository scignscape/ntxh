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
 * Date:    2010/01/18                       
 *
 * Description:
 * - OpenCV specific image pixel traits.
 */


//==============================================================================
/*
 * Type traits for the tPixel8 pixel type.
 */

template <>
inline int CvTraits<tPixel8>::getDepth()
{
    return IPL_DEPTH_8U;
}


template <>
inline int CvTraits<tPixel8>::getChannels()
{
    return 1;
}


template <>
inline int CvTraits<tPixel8>::convWidthStep(int Bytes)
{
    return Bytes;
}


//==============================================================================
/*
 * Type traits for the tPixel16 pixel type.
 */

template <>
inline int CvTraits<tPixel16>::getDepth()
{
    return IPL_DEPTH_16U;
}


template <>
inline int CvTraits<tPixel16>::getChannels()
{
    return 1;
}


template <>
inline int CvTraits<tPixel16>::convWidthStep(int Bytes)
{
    return (Bytes >> 1);
}


//==============================================================================
/*
 * Type traits for the tPixel32 pixel type.
 */

template <>
inline int CvTraits<tPixel32>::getDepth()
{
    return IPL_DEPTH_32S;
}


template <>
inline int CvTraits<tPixel32>::getChannels()
{
    return 1;
}


template <>
inline int CvTraits<tPixel32>::convWidthStep(int Bytes)
{
    return (Bytes >> 2);
}


//==============================================================================
/*
 * Type traits for the tFloatPixel pixel type.
 */

template <>
inline int CvTraits<tFloatPixel>::getDepth()
{
    return IPL_DEPTH_32F;
}


template <>
inline int CvTraits<tFloatPixel>::getChannels()
{
    return 1;
}


template <>
inline int CvTraits<tFloatPixel>::convWidthStep(int Bytes)
{
    return (Bytes >> 2);
}


//==============================================================================
/*
 * Type traits for the tDensityPixel pixel type.
 */

template <>
inline int CvTraits<tDensityPixel>::getDepth()
{
    return IPL_DEPTH_16S;
}


template <>
inline int CvTraits<tDensityPixel>::getChannels()
{
    return 1;
}


template <>
inline int CvTraits<tDensityPixel>::convWidthStep(int Bytes)
{
    return (Bytes >> 1);
}


//==============================================================================
/*
 * Type traits for the tRGBPixel pixel type.
 */

template <>
inline int CvTraits<tRGBPixel>::getDepth()
{
    return IPL_DEPTH_8U;
}


template <>
inline int CvTraits<tRGBPixel>::getChannels()
{
    return 4;
}


template <>
inline int CvTraits<tRGBPixel>::convWidthStep(int Bytes)
{
    return (Bytes >> 2);
}


//==============================================================================
/*
 * Type traits for the tComplexPixel pixel type.
 */

template <>
inline int CvTraits<tComplexPixel>::getDepth()
{
    return IPL_DEPTH_32F;
}


template <>
inline int CvTraits<tComplexPixel>::getChannels()
{
    return 2;
}


template <>
inline int CvTraits<tComplexPixel>::convWidthStep(int Bytes)
{
    return (Bytes >> 3);
}
