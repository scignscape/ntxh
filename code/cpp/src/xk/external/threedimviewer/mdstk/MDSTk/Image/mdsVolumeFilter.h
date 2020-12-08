//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/04                          \n
 *
 * $Id: mdsVolumeFilter.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Volume filtering functions.
 */

#ifndef MDS_VOLUMEFILTER_H
#define MDS_VOLUMEFILTER_H

#include "mdsImageTypes.h"
#include "mdsVolume.h"
#include "mdsFilterPolicy.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Base class for all volume filters.
 * - Parameter V is a volume type.
 */
template <class V>
struct CVolumeFilter
{
public:
    //! Check that type V is a volume. You will see name of this enum somewhere
    //! in compiler error message if the type V is not volume.
    enum { TEMPLATE_PARAMETER_IS_NOT_VOLUME = V::CLASS_VOLUME };

    //! Volume type.
    typedef typename V::tVolume tVolume;

    //! Volume voxel type.
    typedef typename V::tVoxel tVoxel;

public:
    //! Default constructor.
    CVolumeFilter() {}
    
    //! Virtual destructor.
    virtual ~CVolumeFilter() {} 
    
    //! Filtering of input/source volume.
    //! - Returns false on failure.
    virtual bool operator()(const tVolume& SrcVolume, tVolume& DstVolume) = 0;
};


//==============================================================================
/*!
 * Base class for all volume filters that normalize filter response using
 * a predefined policy.
 * - Parameter V is an volume type.
 * - Policy NormPolicy is used for filter response normalization.
 */
template <class V, template <typename> class NormPolicy>
class CNormVolumeFilter : public CVolumeFilter<V>, public NormPolicy<typename V::tVoxel>
{
public:
    //! Base types.
    typedef CVolumeFilter<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;

    //! Filter response type.
    typedef typename CPixelTraits<tVoxel>::tFilterResponse tResult;

    //! Filter response normalization function.
    using NormPolicy<typename V::tVoxel>::normalize;

public:
    //! Default constructor.
    CNormVolumeFilter() {}
    
    //! Virtual destructor.
    ~CNormVolumeFilter() {}

    //! Filtering of input/source volume.
    //! - Returns false on failure.
    virtual bool operator()(const tVolume& SrcVolume, tVolume& DstVolume) = 0;
};


} // namespace img
} // namespace mds

#endif // MDS_VOLUMEFILTER_H

