//==============================================================================
/* This file is part of
 *
 * VPL - Voxel Processing Library
 * Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SeparableImageFilter_H_included
#define SeparableImageFilter_H_included

#include <VPL/Image/ImageFilter.h>
#include <VPL/Image/Kernel.h>

namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Separable image filter template base class.
 */
template <class I>
class CSeparableImageFilter : public CImageFilter<I>
{
public:
    //! Image filter base.
    typedef CImageFilter<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;

public:
    //! Basic constructor
    CSeparableImageFilter() 
        : m_kernelX(1)
        , m_kernelY(1)
        , m_scaleX(1.0)
        , m_scaleY(1.0)
    {}

protected:
    //! Initialize kernels on given size
    void initKernels(tSize sx, tSize sy)
    {
        // Only create kernels
        m_kernelX.resize(sx);
        m_kernelY.resize(sy);
    }

    //! Initialize kernels - compute kernels size from the maximal kernel size and pixel sizes
    void initKernels(tSize Size)
    {
        double max_size(std::max(base::m_dDX, base::m_dDY));

        VPL_ASSERT(max_size > 0.0 && Size > 0);

        m_scaleX = max_size / base::m_dDX;

        vpl::tSize xsize(tSize(Size * m_scaleX));
        if((xsize % 2) != 1) ++xsize;

        m_scaleY = max_size / base::m_dDY;

        vpl::tSize ysize(tSize(Size * m_scaleY));
        if((ysize % 2) != 1) ++ysize;

        // Create kernels
        m_kernelX.resize(xsize);
        m_kernelY.resize(ysize);
    }

protected:
    //! Kernels
    CKernel1D m_kernelX, m_kernelY;

    //! Scaling coefficients
    double m_scaleX, m_scaleY;
};


} // namespace img
} // namespace vpl

#endif // SeparableImageFilter_H_included
