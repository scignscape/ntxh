//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/04                          \n
 *
 * $Id: mdsConvolution.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Convolution volume filter.
 */

#ifndef MDS_VF_CONVOLUTION_H
#define MDS_VF_CONVOLUTION_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsVolumeFilter.h"
#include "../mdsVolumeFunctions.h"
#include "../mdsKernel.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * General convolution volume filter.
 * - Parameter V is a used volume type.
 */
template <class V, template <typename> class N = CDefaultFilterPolicy>
class CVolumeConvolutionFilter
    : public CNormVolumeFilter<V,N>
    , public CKernel3D
{
public:
    //! Volume filter base.
    typedef CNormVolumeFilter<V,N> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;
    typedef typename base::tResult tResult;

public:
    //! Constructor that creates a new 2D convolution kernel
    //! - Parameter 'Size' must be an odd number
    CVolumeConvolutionFilter(tSize Size) : CKernel3D(Size) {}

    //! Constructor
    CVolumeConvolutionFilter(tSize Size, const tData& Value)
        : CKernel3D(Size, Value)
    {}

    //! Constructor
    CVolumeConvolutionFilter(const tConstDataPtr pData, tSize Size)
        : CKernel3D(pData, Size)
    {}

    //! Constructor
    //! - Filter is based on a given convolution kernel
    CVolumeConvolutionFilter(const CKernel3D& k) : CKernel3D(k) {}

    //! Destructor
    ~CVolumeConvolutionFilter() {}


    //! Filtering of input/source volume. Point filter responses are written
    //! to the destination volume.
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    tResult getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
    {
        // Compute filter response
        return convolve<tResult>(SrcVolume, x, y, z, *this);
    }
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates.
#include "mdsConvolution.hxx"


} // namespace img
} // namespace mds

#endif // MDS_VOLUMEFILTER_H

