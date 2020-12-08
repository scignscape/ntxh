//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/20                          \n
 *
 * $Id: mdsAveraging.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Averaging volume filters.
 */

#ifndef MDS_VF_AVERAGING_H
#define MDS_VF_AVERAGING_H

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
 * Averaging image filter (3x3 version).
 * - Parameter V is a used image type.
 * - Kernel definition: \n
 *     [ 1  1  1 ]   \n
 *     [ 1  2  1 ]   \n
 *     [ 1  1  1 ]   \n
 *    1 [ 1  2  1 ]  \n
 *   -- [ 2  4  2 ]  \n
 *   36 [ 1  2  1 ]  \n
 *       [ 1  1  1 ] \n
 *       [ 1  2  1 ] \n
 *       [ 1  1  1 ] \n
 */
template <class V>
class CVolumeAvg3Filter : public CVolumeFilter<V>
{
public:
    //! Volume filter base.
    typedef CVolumeFilter<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;

    //! Number used to divide filter response
    static const int DENOM = 36;

    //! Filter kernel
    static const CKernel3D::tData KERNEL[];

public:
    //! Default constructor.
    CVolumeAvg3Filter() {}

    //! Destructor.
    ~CVolumeAvg3Filter() {}

    //! Filtering of input/source volume. Point filter responses are written
    //! to the destination volume.
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    tVoxel getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Returns filter standard deviation.
    tSize getSize() const { return 3; }

};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsAveraging.hxx"


} // namespace img
} // namespace mds

#endif // MDS_VF_AVERAGING_H

