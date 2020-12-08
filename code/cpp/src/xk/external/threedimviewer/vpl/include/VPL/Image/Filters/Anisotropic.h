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
 * Copyright (c) 2003-2007 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/04/20                       
 *
 * Description:
 * - Anisotropic filtering based on the diffusion process.
 */

#ifndef VPL_IF_ANISOTROPIC_H
#define VPL_IF_ANISOTROPIC_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../ImageFilter.h"

#include <cmath>


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Anisotropic filtering based on the diffusion process.
 * - Parameter I is a used image type.
 */
template <class I>
class CAnisotropicFilter : public CImageFilter<I>
{
public:
    //! Base types.
    typedef CImageFilter<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;

    // Integration constant chosen according to the number of neighbours.
    static const double DT;

    // Minimal change of the flow during the iterative diffusion. 
    static const double MIN_CHANGE;

public:
    //! Constructor.
    CAnisotropicFilter(double dKappa, tSize NumOfIters = -1)
        : m_dKappa(dKappa)
        , m_NumOfIters(NumOfIters)
    {
        VPL_ASSERT(dKappa > 0.0);
        
        m_dInvKappa = (m_dKappa > 0.0) ? 1.0 / m_dKappa : 1.0;
    }

    //! Destructor
    ~CAnisotropicFilter() {}


    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns number of iterations of diffusion process.
    tSize getNumOfIters() const { return m_NumOfIters; }

    //! Sets the number of iterations of diffusion process.
    void setNumOfIters(tSize NumOfIters) { m_NumOfIters = NumOfIters; }

protected:
    //! Filter parameters.
    double m_dKappa, m_dInvKappa;

    //! Number of iterations of the diffusion process.
    tSize m_NumOfIters;

protected:
    //! Returns value of the diffusion function.
    inline double getDiffusionStrength(double dGrad);
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Anisotropic.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IF_ANISOTROPIC_H

