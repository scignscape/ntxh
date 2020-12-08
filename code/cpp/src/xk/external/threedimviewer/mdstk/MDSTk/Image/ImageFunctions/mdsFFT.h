//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/08/09                          \n
 *
 * $Id: mdsFFT.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Two-dimensional DFT (Discrete Fourier Transform).
 * - Fast routines of the well known FFTW library are used.
 */

#ifndef MDS_IMAGEFUNCTIONS_FFT_H
#define MDS_IMAGEFUNCTIONS_FFT_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsStaticAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsImage.h"

// Include FFTW library if enabled
#ifdef MDS_FFTW_ENABLED
#   include <fftw3.h>
#endif // MDS_FFTW_ENABLED


namespace mds
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
#include "mdsFFT.hxx"


} // namespace img
} // namespace mds

#endif // MDS_IMAGEFUNCTIONS_FFT_H

