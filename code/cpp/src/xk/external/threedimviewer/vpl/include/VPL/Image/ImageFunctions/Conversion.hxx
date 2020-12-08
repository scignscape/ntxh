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
 * - Image conversion functions.
 */


//==============================================================================
/*
 * Functions templates.
 */

template <class I1, class I2>
inline bool convert(const CImageBase<I1>& SrcImage, CImageBase<I2>& DstImage)
{
    typedef typename I1::tPixel tSrcPixel;
    typedef typename I2::tPixel tDstPixel;
    const I1& SrcImageImpl = SrcImage.getImpl();
    I2& DstImageImpl = DstImage.getImpl();

    // Get size and margin of the source image
    tSize XSize = SrcImageImpl.getXSize();
    tSize YSize = SrcImageImpl.getYSize();
    tSize Margin = SrcImageImpl.getMargin();

    // Resize the destination image
    DstImageImpl.create(XSize, YSize, Margin);

    // Convert the source image
    XSize += Margin;
    YSize += Margin;
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = -Margin; j < YSize; ++j )
    {
        tSize idx1 = SrcImageImpl.getIdx(-Margin, j);
        tSize idx2 = DstImageImpl.getIdx(-Margin, j);
        for( tSize i = -Margin; i < XSize; ++i, idx1 += SrcImageImpl.getXOffset(), idx2 += DstImageImpl.getXOffset() )
        {
            DstImageImpl.at(idx2) = CPixelConversion<tSrcPixel,tDstPixel>::convert(SrcImageImpl.at(idx1));
        }
    }
    
    // O.K.
    return true;
}


template <class I>
inline void log(CImageBase<I>& Image)
{
    typedef typename I::tPixel tPixel;
    I& ImageImpl = Image.getImpl();

    static const tPixel PMin = CPixelTraits<tPixel>::getPixelMin();
    static const tPixel PRange = CPixelTraits<tPixel>::getPixelMax() - PMin;

    // Get size of the image
    tSize XSize = ImageImpl.getXSize();
    tSize YSize = ImageImpl.getYSize();

    // Maximal and minimal value in the image
    tPixel Max = getMax<tPixel>(Image);
    tPixel Min = getMin<tPixel>(Image);

    // Estimate the scaling constant
    double dScale = double(PRange) / std::log(1.0 + Max - Min);

    // Logarithmic operator
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < YSize; ++j )
    {
        tSize idx = ImageImpl.getIdx(0, j);
        for( tSize i = 0; i < XSize; ++i, idx += ImageImpl.getXOffset() )
        {
            ImageImpl.at(idx) = tPixel(std::log(1.0 + ImageImpl.at(idx) - Min) * dScale + PMin);
        }
    }
}


template <class I>
inline bool real(const CImageBase<CComplexImage>& SrcImage, CImageBase<I>& DstImage)
{
    typedef typename CComplexImage::tPixel tSrcPixel;
    typedef typename CComplexImage::tPixel::tComponent tComponent;
    typedef typename I::tPixel tDstPixel;
    
    const CComplexImage& SrcImageImpl = SrcImage.getImpl();
    I& DstImageImpl = DstImage.getImpl();

    // Get size and margin of the source image
    tSize XSize = SrcImageImpl.getXSize();
    tSize YSize = SrcImageImpl.getYSize();
    tSize Margin = SrcImageImpl.getMargin();

    // Resize the destination image
    DstImageImpl.create(XSize, YSize, Margin);
    
    // Convert the source image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < YSize; ++j )
    {
        tSize idx1 = SrcImageImpl.getIdx(0, j);
        tSize idx2 = DstImageImpl.getIdx(0, j);
        for( tSize i = -Margin; i < XSize; ++i, idx1 += SrcImageImpl.getXOffset(), idx2 += DstImageImpl.getXOffset() )
        {
            DstImageImpl.at(idx2) = CPixelConversion<tComponent,tDstPixel>::convert(SrcImageImpl.at(idx1).getReal());
        }
    }
    
    // O.K.
    return true;
}


template <class I>
inline bool imag(const CImageBase<CComplexImage>& SrcImage, CImageBase<I>& DstImage)
{
    typedef typename CComplexImage::tPixel tSrcPixel;
    typedef typename CComplexImage::tPixel::tComponent tComponent;
    typedef typename I::tPixel tDstPixel;
    
    const CComplexImage& SrcImageImpl = SrcImage.getImpl();
    I& DstImageImpl = DstImage.getImpl();

    // Get size and margin of the source image
    tSize XSize = SrcImageImpl.getXSize();
    tSize YSize = SrcImageImpl.getYSize();
    tSize Margin = SrcImageImpl.getMargin();

    // Resize the destination image
    DstImageImpl.create(XSize, YSize, Margin);
    
    // Convert the source image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < YSize; ++j )
    {
        tSize idx1 = SrcImageImpl.getIdx(0, j);
        tSize idx2 = DstImageImpl.getIdx(0, j);
        for( tSize i = -Margin; i < XSize; ++i, idx1 += SrcImageImpl.getXOffset(), idx2 += DstImageImpl.getXOffset() )
        {
            DstImageImpl.at(idx2) = CPixelConversion<tComponent,tDstPixel>::convert(SrcImageImpl.at(idx1).getImag());
        }
    }
    
    // O.K.
    return true;
}


template <class I>
inline bool abs(const CImageBase<CComplexImage>& SrcImage, CImageBase<I>& DstImage)
{
    typedef typename CComplexImage::tPixel tSrcPixel;
    typedef typename CComplexImage::tPixel::tComponent tComponent;
    typedef typename I::tPixel tDstPixel;
    
    const CComplexImage& SrcImageImpl = SrcImage.getImpl();
    I& DstImageImpl = DstImage.getImpl();

    // Get size and margin of the source image
    tSize XSize = SrcImageImpl.getXSize();
    tSize YSize = SrcImageImpl.getYSize();
    tSize Margin = SrcImageImpl.getMargin();

    // Resize the destination image
    DstImageImpl.create(XSize, YSize, Margin);
    
    // Convert the source image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < YSize; ++j )
    {
        tSize idx1 = SrcImageImpl.getIdx(0, j);
        tSize idx2 = DstImageImpl.getIdx(0, j);
        for( tSize i = -Margin; i < XSize; ++i, idx1 += SrcImageImpl.getXOffset(), idx2 += DstImageImpl.getXOffset() )
        {
            DstImageImpl.at(idx2) = CPixelConversion<tComponent,tDstPixel>::convert(SrcImageImpl.at(idx1).getMag());
        }
    }
    
    // O.K.
    return true;
}


template <class I>
inline bool arg(const CImageBase<CComplexImage>& SrcImage, CImageBase<I>& DstImage)
{
    typedef typename CComplexImage::tPixel tSrcPixel;
    typedef typename CComplexImage::tPixel::tComponent tComponent;
    typedef typename I::tPixel tDstPixel;
    
    const CComplexImage& SrcImageImpl = SrcImage.getImpl();
    I& DstImageImpl = DstImage.getImpl();

    // Get size and margin of the source image
    tSize XSize = SrcImageImpl.getXSize();
    tSize YSize = SrcImageImpl.getYSize();
    tSize Margin = SrcImageImpl.getMargin();

    // Resize the destination image
    DstImageImpl.create(XSize, YSize, Margin);
    
    // Convert the source image
#pragma omp parallel for schedule(static) default(shared)
    for( tSize j = 0; j < YSize; ++j )
    {
        tSize idx1 = SrcImageImpl.getIdx(0, j);
        tSize idx2 = DstImageImpl.getIdx(0, j);
        for( tSize i = -Margin; i < XSize; ++i, idx1 += SrcImageImpl.getXOffset(), idx2 += DstImageImpl.getXOffset() )
        {
            DstImageImpl.at(idx2) = CPixelConversion<tComponent,tDstPixel>::convert(SrcImageImpl.at(idx1).getArg());
        }
    }

    // O.K.
    return true;
}

