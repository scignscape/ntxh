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
 * Date:    2006/02/20                       
 *
 * Description:
 * - Image convolution functions.
 */


//==============================================================================
/*
 * Functions templates.
 */

template <typename R, class I>
inline R convolve(const CImageBase<I>& Image,
                  tSize x,
                  tSize y,
                  const CKernel2D& Kernel
                  )
{
    tSize Size = Kernel.getSize();
    tSize Half = Size >> 1;
    tSize Offset = Image.getYOffset() - Size * Image.getXOffset();

    tSize idx = Image.getIdx(x - Half, y - Half);
    const CKernel2D::tData *pK = Kernel.getPtr();

    R Sum = R(0);
    for( tSize j = 0; j < Size; ++j, idx += Offset )
    {
        for( tSize i = 0; i < Size; ++i, idx += Image.getXOffset() )
        {
            Sum += R(Image.at(idx)) * R(*(pK++));
        }
    }
    return Sum;
}


template <typename R, class I>
inline R convolveX(const CImageBase<I>& Image,
                   tSize x,
                   tSize y,
                   const CKernel1D& Kernel
                  )
{
    tSize Size = Kernel.getSize();
    tSize Half = Size >> 1;

    tSize idx = Image.getIdx(x - Half, y);
    const CKernel1D::tData *pK = Kernel.getPtr();

    R Sum = R(0);
    for( tSize i = 0; i < Size; ++i, idx += Image.getXOffset() )
    {
        Sum += R(Image.at(idx)) * R(*(pK++));
    }
    return Sum;
}


template <typename R, class I>
inline R convolveY(const CImageBase<I>& Image,
                   tSize x,
                   tSize y,
                   const CKernel1D& Kernel
                  )
{
    tSize Size = Kernel.getSize();
    tSize Half = Size >> 1;

    tSize idx = Image.getIdx(x, y - Half);
    const CKernel1D::tData *pK = Kernel.getPtr();

    R Sum = R(0);
    for( tSize i = 0; i < Size; ++i, idx += Image.getYOffset() )
    {
        Sum += R(Image.at(idx)) * R(*(pK++));
    }
    return Sum;
}


template <typename R, class I>
inline R convolve(const CImageBase<I>& Image,
                  const CPoint3D& Point,
                  const CKernel2D& Kernel
                 )
{
    typedef typename I::tPixel tPixel;
    const I& ImageImpl = Image.getImpl();

    tSize Size = Kernel.getSize();
    tSize Half = Size >> 1;

    CPoint3D Temp(0, Point.y() - Half);
    R Sum = R(0);
    for( tSize m = 0; m < Size; ++m )
    {
        Temp.x() = Point.x() - Half;
        for( tSize l = 0; l < Size; ++l )
        {
            Sum += R(ImageImpl.interpolate(Temp)) * R(Kernel.at(l, m));
            Temp.x() += 1.0f;
        }
        Temp.y() += 1.0f;
    }
    return Sum;
}


template <typename R, class I>
inline R convolveX(const CImageBase<I>& Image,
                   const CPoint3D& Point,
                   const CKernel1D& Kernel
                   )
{
    typedef typename I::tPixel tPixel;
    const I& ImageImpl = Image.getImpl();

    tSize Size = Kernel.getSize();
    tSize Half = Size >> 1;

    CPoint3D Temp(Point.x() - Half, Point.y());
    R Sum = R(0);
    for( tSize l = 0; l < Size; ++l )
    {
        Sum += R(ImageImpl.interpolate(Temp)) * R(Kernel.at(l));
        Temp.x() += 1.0;
    }
    return Sum;
}


template <typename R, class I>
inline R convolveY(const CImageBase<I>& Image,
                   const CPoint3D& Point,
                   const CKernel1D& Kernel
                  )
{
    typedef typename I::tPixel tPixel;
    const I& ImageImpl = Image.getImpl();

    tSize Size = Kernel.getSize();
    tSize Half = Size >> 1;

    CPoint3D Temp(Point.x(), Point.y() - Half);
    R Sum = R(0);
    for( tSize m = 0; m < Size; ++m )
    {
        Sum += R(ImageImpl.interpolate(Temp)) * R(Kernel.at(m));
        Temp.y() += 1.0;
    }
    return Sum;
}

