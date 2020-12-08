//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/20                          \n
 *
 * $Id: mdsLaplacian.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Laplacian volume filters.
 */

#ifndef MDS_VF_LAPLACIAN_H
#define MDS_VF_LAPLACIAN_H

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
 * Laplacian volume filter (first version).
 * - Parameter V is a used volume type.
 * - Kernel definition: \n
 *    [ 0  0  0 ]   \n
 *    [ 0  1  0 ]   \n
 *    [ 0  0  0 ]   \n
 *   1 [ 0  1  0 ]  \n
 *   - [ 1 -6  1 ]  \n
 *  12 [ 0  1  0 ]  \n
 *      [ 0  0  0 ] \n
 *      [ 0  1  0 ] \n
 *      [ 0  0  0 ] \n
 */
template <class V, template <typename> class N = CDefaultFilterPolicy>
class CVolumeLaplaceFilter0 : public CNormVolumeFilter<V,N>
{
public:
    //! Volume filter base.
    typedef CNormVolumeFilter<V,N> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 12;

public:
    //! Default constructor.
    CVolumeLaplaceFilter0() {}

    //! Destructor.
    ~CVolumeLaplaceFilter0() {}

    //! Filtering of input/source volume.
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    tResult getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Returns filter standard deviation.
    tSize getSize() const { return 3; }

};


//==============================================================================
/*!
 * Laplacian volume filter (second version).
 * - Parameter V is a used volume type.
 * - Kernel definition: \n
 *     [ 1  1  1 ]    \n
 *     [ 1  1  1 ]    \n
 *     [ 1  1  1 ]    \n
 *    1 [ 1   1  1 ]  \n
 *   -- [ 1 -26  1 ]  \n
 *   52 [ 1   1  1 ]  \n
 *        [ 1  1  1 ] \n
 *        [ 1  1  1 ] \n
 *        [ 1  1  1 ] \n
 */
template <class V, template <typename> class N = CDefaultFilterPolicy>
class CVolumeLaplaceFilter1 : public CNormVolumeFilter<V,N>
{
public:
    //! Volume filter base.
    typedef CNormVolumeFilter<V,N> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 26;

    //! Filter kernel
    static const CKernel3D::tData KERNEL[];

public:
    //! Default constructor.
    CVolumeLaplaceFilter1() {}

    //! Destructor.
    ~CVolumeLaplaceFilter1() {}


    //! Filtering of input/source volume.
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    tResult getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Returns filter standard deviation.
    tSize getSize() const { return 3; }

};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsLaplacian.hxx"


} // namespace img
} // namespace mds

#endif // MDS_VF_LAPLACIAN_H

