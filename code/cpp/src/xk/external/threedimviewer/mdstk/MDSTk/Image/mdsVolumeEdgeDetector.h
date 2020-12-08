//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/04/24                          \n
 *
 * $Id: mdsVolumeEdgeDetector.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - More sophisticated functions for volume edge detection.
 */

#ifndef MDS_VOLUMEEDGEDETECTOR_H
#define MDS_VOLUMEEDGEDETECTOR_H

#include "mdsImageTypes.h"
#include "mdsVolume.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Base class for all volume edge detectors.
 * - Parameter V is volume type.
 */
template <typename V>
class CVolumeEdgeDetector
{
public:
    //! Check that V is a volume. You will see name of this enum somewhere
    //! in compiler error message if the type V is not volume.
    enum { TEMPLATE_PARAMETER_IS_NOT_VOLUME = V::CLASS_VOLUME };

    //! Volume type.
    typedef typename V::tVolume tVolume;

    //! Voxel type.
    typedef typename V::tVoxel tVoxel;

public:
    //! Default constructor.
    CVolumeEdgeDetector() {}
    
    //! Virtual destructor.
    virtual ~CVolumeEdgeDetector() {}
    
    //! Edge detection in a given volume.
    //! - Returns false on failure.
    virtual bool operator()(const tVolume& SrcVolume, tVolume& DstVolume) = 0;
};


} // namespace img
} // namespace mds

#endif // MDS_VOLUMEEDGEDETECTOR_H

