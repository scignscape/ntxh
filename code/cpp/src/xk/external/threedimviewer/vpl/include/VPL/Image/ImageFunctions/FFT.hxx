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


//==============================================================================
/*
 * Functions templates.
 */

#ifdef VPL_FFTW_ENABLED

template <class I>
inline bool fft(const CImageBase<I>& SrcImage, CComplexImage& DstImage)
{
    const I& SrcImageImpl = SrcImage.getImpl();

    // Check size of the complex image pixel type and the fftw_complex type
    // which is used by the FFTW library
    VPL_STATIC_ASSERT(sizeof(CComplexImage::tPixel) == sizeof(fftwf_complex), Cannot_compile_DFT_routines);

    // Get size and margin of the source image
    tSize ImageSize[2] = { SrcImageImpl.getYSize(), SrcImageImpl.getXSize() };
    tSize Margins = 2 * SrcImageImpl.getMargin();

    // Convert input image to the complex one
    DstImage.convert(SrcImageImpl);

    // Real image size
    tSize RealImageSize[2] = { ImageSize[0] + Margins, ImageSize[1] + Margins };

    // Create FFT plan for in-place two-dimensional DFT
    fftwf_plan Plan;
    Plan = fftwf_plan_many_dft(2, ImageSize, 1,
                               (fftwf_complex *)DstImage.getPtr(),
                               RealImageSize,
                               DstImage.getXOffset(),
                               0,
                               (fftwf_complex *)DstImage.getPtr(),
                               RealImageSize,
                               DstImage.getXOffset(),
                               0,
                               FFTW_FORWARD,
                               FFTW_ESTIMATE
                               );
    
    // Check that the plan was created
    if( !Plan )
    {
        return false;
    }
    
    // Execute the plan
    fftwf_execute(Plan);
    
    // Destroy the plan
    fftwf_destroy_plan(Plan);
    
    // O.K.
    return true;
}

#else // VPL_FFTW_ENABLED

template <class I>
inline bool fft(const CImageBase<I>& SrcImage, CComplexImage& DstImage)
{
    // Not implemented
    return false;
}

#endif // VPL_FFTW_ENABLED


//==============================================================================
/*
 * Inverse FFT.
 */

#ifdef VPL_FFTW_ENABLED

template <class I>
inline bool ifft(const CImageBase<I>& SrcImage, CComplexImage& DstImage)
{
    const I& SrcImageImpl = SrcImage.getImpl();

    // Check size of the complex image pixel type and the fftw_complex type
    // which is used by the FFTW library
    VPL_STATIC_ASSERT(sizeof(CComplexImage::tPixel) == sizeof(fftwf_complex), Cannot_compile_DFT_routines);

    // Get size and margin of the source image
    tSize ImageSize[2] = { SrcImageImpl.getYSize(), SrcImageImpl.getXSize() };
    tSize Margins = 2 * SrcImageImpl.getMargin();

    // Convert input image to the complex one
    DstImage.convert(SrcImageImpl);

    // Real image size
    tSize RealImageSize[2] = { ImageSize[0] + Margins, ImageSize[1] + Margins };

    // Create FFT plan for in-place two-dimensional DFT
    fftwf_plan Plan;
    Plan = fftwf_plan_many_dft(2, ImageSize, 1,
                               (fftwf_complex *)DstImage.getPtr(),
                               RealImageSize,
                               DstImage.getXOffset(),
                               0,
                               (fftwf_complex *)DstImage.getPtr(),
                               RealImageSize,
                               DstImage.getXOffset(),
                               0,
                               FFTW_BACKWARD,
                               FFTW_ESTIMATE
                               );
    
    // Check that the plan was created
    if( !Plan )
    {
        return false;
    }
    
    // Execute the plan
    fftwf_execute(Plan);
    
    // Normalize the output
    tComplexPixel::tComponent InvNorm = 1.0f / (ImageSize[0] * ImageSize[1]);
    DstImage *= InvNorm;
    
    // Destroy the plan
    fftwf_destroy_plan(Plan);
    
    // O.K.
    return true;
}

#else // VPL_FFTW_ENABLED

template <class I>
inline bool ifft(const CImageBase<I>& SrcImage, CComplexImage& DstImage)
{
    // Not implemented
    return false;
}

#endif // VPL_FFTW_ENABLED


//==============================================================================
/*
 * Function similar to the MATLAB fftshift().
 */

template <class I>
inline void fftShift(CImageBase<I>& Image)
{
    // Get size of the image
    tSize XSize = Image.getXSize();
    tSize YSize = Image.getYSize();
    
    // Half of the image size
    tSize XHalf = XSize / 2;
    tSize YHalf = YSize / 2;
    
    // Compute displacements
    tSize XShift = (2 * XHalf < XSize) ? XHalf + 1 : XHalf;
    tSize YShift = (2 * YHalf < YSize) ? YHalf + 1 : YHalf;
    
    // Swap quadrants
    for( tSize j = 0, jj = YShift; j < YHalf; j++, jj++ )
    {
        for( tSize i = 0, ii = XShift; i < XHalf; i++, ii++ )
        {
            vpl::math::swap2(Image(i, j), Image(ii, jj));
            vpl::math::swap2(Image(i, jj), Image(ii, j));
        }
    }
}

