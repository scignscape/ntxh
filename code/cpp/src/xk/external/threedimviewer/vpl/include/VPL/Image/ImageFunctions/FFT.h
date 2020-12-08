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
 * Copyright (c) 2003-2006 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/08/09                       
 * 
 * Description:
 * - Two-dimensional DFT (Discrete Fourier Transform).
 * - Fast routines of the well known FFTW library are used.
 */

#ifndef VPL_IMAGEFUNCTIONS_FFT_H
#define VPL_IMAGEFUNCTIONS_FFT_H

#include <VPL/Base/Assert.h>
#include <VPL/Base/StaticAssert.h>
#include <VPL/Math/Base.h>

#include "../Image.h"

// Include FFTW library if enabled
#ifdef VPL_FFTW_ENABLED
#   include <fftw3.h>
#endif // VPL_FFTW_ENABLED


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Global functions.
 */

//! Computes unnormalized two-dimensional discrete Fourier transform (DFT)
//! of a given source image.
//! - Returns false on failure.
template <class I>
inline bool fft(const CImageBase<I>& SrcImage, CComplexImage& DstImage);

//! Computes inverse two-dimensional discrete Fourier transform (inverse DFT)
//! of a given source image.
//! - Returns false on failure.
template <class I>
inline bool ifft(const CImageBase<I>& SrcImage, CComplexImage& DstImage);

//! Shift zero-frequency component to center of spectrum. Swaps the first
//! and third quadrants and the second and fourth quadrants.
//! - The function is similar to the MATLAB fftshift().
template <class I>
inline void fftShift(CImageBase<I>& Image);


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "FFT.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IMAGEFUNCTIONS_FFT_H

