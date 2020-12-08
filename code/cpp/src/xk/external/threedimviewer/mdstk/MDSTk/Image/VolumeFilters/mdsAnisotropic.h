//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/05/03                          \n
 *
 * $Id: mdsAnisotropic.h 2106 2012-02-18 21:55:47Z spanel $
 *
 * Description:
 * - Anisotropic filtering based on the diffusion process.
 */

#ifndef MDS_VF_ANISOTROPIC_H
#define MDS_VF_ANISOTROPIC_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>
#include <MDSTk/Module/mdsProgress.h>

#include "../mdsVolumeFilter.h"

#include <cmath>


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Anisotropic filtering based on the diffusion process.
 * - Parameter V represents a volume type.
 */
template <class V>
class CVolumeAnisotropicFilter : public CVolumeFilter<V>, public mds::mod::CProgress
{
public:
    //! Volume filter base.
    typedef CVolumeFilter<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;

    // Integration constant chosen according to the number of neighbours.
    static const double DT;

    // Minimal change of the flow during the iterative diffusion. 
    static const double MIN_CHANGE;

    //! Size of the processing block (volume window). The input volume
    //! is divided into smaller blocks - cubes for the processing.
    //! - This is used to reduce amount of the memory required by the
    //!   filtering.
    enum { BLOCK_SIZE = 32 };

public:
    //! Constructor.
    CVolumeAnisotropicFilter(double dKappa, tSize NumOfIters = -1)
        : m_dKappa(dKappa)
        , m_NumOfIters(NumOfIters)
    {
        MDS_ASSERT(dKappa > 0.0);
        
        m_dInvKappa = (m_dKappa > 0.0) ? 1.0 / m_dKappa : 1.0;
    }

    //! Destructor
    ~CVolumeAnisotropicFilter() {}

    //! Filtering of input/source volume. Point filter responses are written
    //! to the destination volume.
    //! - Returns false on failure.
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

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

#endif // MDS_VF_ANISOTROPIC_H

