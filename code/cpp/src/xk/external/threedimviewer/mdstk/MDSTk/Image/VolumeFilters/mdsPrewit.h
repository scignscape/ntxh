//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/20                          \n
 *
 * $Id: mdsPrewit.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Prewit gradient edge detectors.
 */

#ifndef MDS_VF_PREWIT_H
#define MDS_VF_PREWIT_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsVolumeFilter.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Prewit gradient edge detector (x-axis).
 * - Parameter V is a used image type.
 * - Kernel definition: \n
 *    [ -1  0  1 ]   \n
 *    [ -1  0  1 ]   \n
 *    [ -1  0  1 ]   \n
 *   1 [ -1  0  1 ]  \n
 *   - [ -1  0  1 ]  \n
 *   9 [ -1  0  1 ]  \n
 *      [ -1  0  1 ] \n
 *      [ -1  0  1 ] \n
 *      [ -1  0  1 ] \n
 */
template <class V, template <typename> class N = CDefaultFilterPolicy>
class CVolumePrewitX : public CNormVolumeFilter<V,N>
{
public:
    //! Volume filter base.
    typedef CNormVolumeFilter<V,N> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 9;

public:
    //! Default constructor.
    CVolumePrewitX() {}

    //! Destructor.
    ~CVolumePrewitX() {}

    //! Filtering of input/source volume.
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    inline tResult getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Returns filter standard deviation.
    tSize getSize() const { return 3; }

};


//==============================================================================
/*!
 * Prewit gradient edge detector (y-axis).
 * - Parameter V is a used image type.
 * - Kernel definition: \n
 *    [ -1 -1 -1 ]   \n
 *    [  0  0  0 ]   \n
 *    [  1  1  1 ]   \n
 *   1 [ -1 -1 -1 ]  \n
 *   - [  0  0  0 ]  \n
 *   9 [  1  1  1 ]  \n
 *      [ -1 -1 -1 ] \n
 *      [  0  0  0 ] \n
 *      [  1  1  1 ] \n
 */
template <class V, template <typename> class N = CDefaultFilterPolicy>
class CVolumePrewitY : public CNormVolumeFilter<V,N>
{
public:
    //! Volume filter base.
    typedef CNormVolumeFilter<V,N> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 9;

public:
    //! Default constructor.
    CVolumePrewitY() {}

    //! Destructor.
    ~CVolumePrewitY() {}

    //! Filtering of input/source volume.
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    inline tResult getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Returns filter standard deviation.
    tSize getSize() const { return 3; }

};


//==============================================================================
/*!
 * Prewit gradient edge detector (z-axis).
 * - Parameter V is a used image type.
 * - Kernel definition: \n
 *    [ -1 -1 -1 ]   \n
 *    [ -1 -1 -1 ]   \n
 *    [ -1 -1 -1 ]   \n
 *   1 [  0  0  0 ]  \n
 *   - [  0  0  0 ]  \n
 *   9 [  0  0  0 ]  \n
 *      [  1  1  1 ] \n
 *      [  1  1  1 ] \n
 *      [  1  1  1 ] \n
 */
template <class V, template <typename> class N = CDefaultFilterPolicy>
class CVolumePrewitZ : public CNormVolumeFilter<V,N>
{
public:
    //! Volume filter base.
    typedef CNormVolumeFilter<V,N> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 9;

public:
    //! Default constructor.
    CVolumePrewitZ() {}

    //! Destructor.
    ~CVolumePrewitZ() {}

    //! Filtering of input/source volume.
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    inline tResult getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Returns filter standard deviation.
    tSize getSize() const { return 3; }

};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsPrewit.hxx"


} // namespace img
} // namespace mds

#endif // MDS_VF_PREWIT_H

