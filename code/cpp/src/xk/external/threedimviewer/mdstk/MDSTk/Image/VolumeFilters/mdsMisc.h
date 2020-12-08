//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/08/10                          \n
 *
 * $Id: mdsMisc.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Miscellaneous filters and operators.
 */

#ifndef MDS_VF_MISC_H
#define MDS_VF_MISC_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsVolumeFilter.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Operator computes image derivatives in x direction.
 * - Parameter V is a used image type.
 * - Kernel definition: \n
 *   1/7 [ -1 -2 -4 0 4 2 1 ] \n
 */
template <class V, template <typename> class N = CDefaultFilterPolicy>
class CVolumeDiffXFilter : public CNormVolumeFilter<V,N>
{
public:
    //! Volume filter base.
    typedef CNormVolumeFilter<V,N> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 7;

public:
    //! Default constructor.
    CVolumeDiffXFilter() {}

    //! Destructor.
    ~CVolumeDiffXFilter() {}

    //! Filtering of input/source volume.
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    inline tResult getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Returns filter size.
    tSize getSize() const { return 7; }
};


//==============================================================================
/*!
 * Operator computes image derivatives in y direction.
 * - Parameter V is a used image type.
 * - Kernel definition: \n
 *   1/7 [ -1 -2 -4 0 4 2 1 ] \n
 */
template <class V, template <typename> class N = CDefaultFilterPolicy>
class CVolumeDiffYFilter : public CNormVolumeFilter<V,N>
{
public:
    //! Volume filter base.
    typedef CNormVolumeFilter<V,N> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 7;

public:
    //! Default constructor.
    CVolumeDiffYFilter() {}

    //! Destructor.
    ~CVolumeDiffYFilter() {}

    //! Filtering of input/source volume.
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    inline tResult getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Returns filter size.
    tSize getSize() const { return 7; }
};


//==============================================================================
/*!
 * Operator computes image derivatives in z direction.
 * - Parameter V is a used image type.
 * - Kernel definition: \n
 *   1/7 [ -1 -2 -4 0 4 2 1 ] \n
 */
template <class V, template <typename> class N = CDefaultFilterPolicy>
class CVolumeDiffZFilter : public CNormVolumeFilter<V,N>
{
public:
    //! Volume filter base.
    typedef CNormVolumeFilter<V,N> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 7;

public:
    //! Default constructor.
    CVolumeDiffZFilter() {}

    //! Destructor.
    ~CVolumeDiffZFilter() {}

    //! Filtering of input/source volume.
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    inline tResult getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Returns filter size.
    tSize getSize() const { return 7; }
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsMisc.hxx"


} // namespace img
} // namespace mds

#endif // MDS_VF_MISC_H

