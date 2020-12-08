//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/04/20                          \n
 *
 * $Id: mdsAnisotropic.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Anisotropic filtering based on the diffusion process.
 */

#ifndef MDS_IF_ANISOTROPIC_H
#define MDS_IF_ANISOTROPIC_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsImageFilter.h"

#include <cmath>


namespace mds
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
        MDS_ASSERT(dKappa > 0.0);
        
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
#include "mdsAnisotropic.hxx"


} // namespace img
} // namespace mds

#endif // MDS_IF_ANISOTROPIC_H

