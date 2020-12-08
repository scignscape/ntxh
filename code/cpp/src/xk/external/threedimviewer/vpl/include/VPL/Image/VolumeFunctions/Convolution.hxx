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
 * Date:    2006/02/21                       
 *
 * Description:
 * - Volume convolution functions.
 */


//==============================================================================
/*
 * Functions templates.
 */
template <typename R, class V>
inline R convolve(const CVolumeBase<V>& Volume,
                  tSize x,
                  tSize y,
                  tSize z,
                  const CKernel3D& Kernel
                  )
{
    tSize Size = Kernel.getSize();
    tSize Half = Size >> 1;
    tSize YOffset = Volume.getYOffset() - Size * Volume.getXOffset();
    tSize ZOffset = Volume.getZOffset() - Size * Volume.getYOffset();

    tSize idx = Volume.getIdx(x - Half, y - Half, z - Half);
    const CKernel3D::tData *pK = Kernel.getPtr();

    R Sum = R(0);
    for( tSize k = 0; k < Size; ++k, idx += ZOffset )
    {
        for( tSize j = 0; j < Size; ++j, idx += YOffset )
        {
            for( tSize i = 0; i < Size; ++i, idx += Volume.getXOffset() )
            {
                Sum += R(Volume.at(idx)) * R(*(pK++));
            }
        }
    }
    return Sum;
}


template <typename R, class V>
inline R convolveXY(const CVolumeBase<V>& Volume,
                    tSize x,
                    tSize y,
                    tSize z,
                    const CKernel2D& Kernel
                    )
{
    tSize Size = Kernel.getSize();
    tSize Half = Size >> 1;
    tSize Offset = Volume.getYOffset() - Size * Volume.getXOffset();

    tSize idx = Volume.getIdx(x - Half, y - Half, z);
    const CKernel2D::tData *pK = Kernel.getPtr();

    R Sum = R(0);
    for( tSize j = 0; j < Size; ++j, idx += Offset )
    {
        for( tSize i = 0; i < Size; ++i, idx += Volume.getXOffset() )
        {
            Sum += R(Volume.at(idx)) * R(*(pK++));
        }
    }
    return Sum;
}


template <typename R, class V>
inline R convolveXZ(const CVolumeBase<V>& Volume,
                    tSize x,
                    tSize y,
                    tSize z,
                    const CKernel2D& Kernel
                    )
{
    tSize Size = Kernel.getSize();
    tSize Half = Size >> 1;
    tSize Offset = Volume.getZOffset() - Size * Volume.getXOffset();

    tSize idx = Volume.getIdx(x - Half, y, z - Half);
    const CKernel2D::tData *pK = Kernel.getPtr();

    R Sum = R(0);
    for( tSize j = 0; j < Size; ++j, idx += Offset )
    {
        for( tSize i = 0; i < Size; ++i, idx += Volume.getXOffset() )
        {
            Sum += R(Volume.at(idx)) * R(*(pK++));
        }
    }
    return Sum;
}


template <typename R, class V>
inline R convolveYZ(const CVolumeBase<V>& Volume,
                    tSize x,
                    tSize y,
                    tSize z,
                    const CKernel2D& Kernel
                    )
{
    tSize Size = Kernel.getSize();
    tSize Half = Size >> 1;
    tSize Offset = Volume.getZOffset() - Size * Volume.getYOffset();

    tSize idx = Volume.getIdx(x, y - Half, z - Half);
    const CKernel2D::tData *pK = Kernel.getPtr();

    R Sum = R(0);
    for( tSize j = 0; j < Size; ++j, idx += Offset )
    {
        for( tSize i = 0; i < Size; ++i, idx += Volume.getYOffset() )
        {
            Sum += R(Volume.at(idx)) * R(*(pK++));
        }
    }
    return Sum;
}


template <typename R, class V>
inline R convolveX(const CVolumeBase<V>& Volume,
                   tSize x,
                   tSize y,
                   tSize z,
                   const CKernel1D& Kernel
                   )
{
    tSize Size = Kernel.getSize();
    tSize Half = Size >> 1;

    tSize idx = Volume.getIdx(x - Half, y, z);
    const CKernel1D::tData *pK = Kernel.getPtr();

    R Sum = R(0);
    for( tSize i = 0; i < Size; ++i, idx += Volume.getXOffset() )
    {
        Sum += R(Volume.at(idx)) * R(*(pK++));
    }
    return Sum;
}


template <typename R, class V>
inline R convolveY(const CVolumeBase<V>& Volume,
                   tSize x,
                   tSize y,
                   tSize z,
                   const CKernel1D& Kernel
                   )
{
    tSize Size = Kernel.getSize();
    tSize Half = Size >> 1;

    tSize idx = Volume.getIdx(x, y - Half, z);
    const CKernel1D::tData *pK = Kernel.getPtr();

    R Sum = R(0);
    for( tSize i = 0; i < Size; ++i, idx += Volume.getYOffset() )
    {
        Sum += R(Volume.at(idx)) * R(*(pK++));
    }
    return Sum;
}


template <typename R, class V>
inline R convolveZ(const CVolumeBase<V>& Volume,
                   tSize x,
                   tSize y,
                   tSize z,
                   const CKernel1D& Kernel
                  )
{
    tSize Size = Kernel.getSize();
    tSize Half = Size >> 1;

    tSize idx = Volume.getIdx(x, y, z - Half);
    const CKernel1D::tData *pK = Kernel.getPtr();

    R Sum = R(0);
    for( tSize i = 0; i < Size; ++i, idx += Volume.getZOffset() )
    {
        Sum += R(Volume.at(idx)) * R(*(pK++));
    }
    return Sum;
}

