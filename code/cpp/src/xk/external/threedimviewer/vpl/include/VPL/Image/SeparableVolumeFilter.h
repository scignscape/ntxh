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

#ifndef SeparableVolumeFilter_H_included
#define SeparableVolumeFilter_H_included

#include <VPL/Image/VolumeFilter.h>
#include <VPL/Image/Kernel.h>

namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Separable volume filter template base class.
 */
template <class V>
class CSeparableVolumeFilter : public CVolumeFilter<V>
{
public:
    //! Volume filter base.
    typedef CVolumeFilter<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;
    
public:
    //! Basic constructor
    CSeparableVolumeFilter() 
        : m_kernelX(1)
        , m_kernelY(1)
        , m_kernelZ(1)
        , m_scaleX(1.0)
        , m_scaleY(1.0)
        , m_scaleZ(1.0)
    {}

protected:
    //! Initialize kernels on given size
    void initKernels(tSize sx, tSize sy, tSize sz)
    {
        // Only create kernels
        m_kernelX.resize(sx);
        m_kernelY.resize(sy);
        m_kernelZ.resize(sz);
    }

    //! Initialize kernels - compute kernels size from the maximal kernel size and pixel sizes
    void initKernels(tSize Size)
    {
        double max_size(std::max(base::m_dDX, std::max(base::m_dDZ, base::m_dDY)));

        VPL_ASSERT(max_size > 0.0 && Size > 0);

        m_scaleX = max_size / base::m_dDX;

        tSize xsize(Size * m_scaleX);
        if((xsize % 2) != 1) ++xsize;

        m_scaleY = max_size / base::m_dDY;

        tSize ysize(Size * m_scaleY);
        if((ysize % 2) != 1) ++ysize;

        m_scaleZ = max_size / base::m_dDZ;

        tSize zsize(Size * m_scaleZ);
        if((zsize % 2) != 1) ++zsize;

        // Create kernels
        m_kernelX.resize(xsize);
        m_kernelY.resize(ysize);
        m_kernelZ.resize(zsize);
    }

protected:
    //! Kernels
    CKernel1D m_kernelX, m_kernelY, m_kernelZ;

    //! Scaling coefficients
    double m_scaleX, m_scaleY, m_scaleZ;
};


} // namespace img
} // namespace vpl

// SeparableVolumeFilter_H_included
#endif
