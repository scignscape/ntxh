//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/07/03                          \n
 *
 * $Id: mdsLandmarkDetector.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Functions for 3D landmark detection.
 */

#ifndef MDS_LandmarkDetector_H
#define MDS_LandmarkDetector_H

#include "mdsImageTypes.h"
#include "mdsVolume.h"
#include "mdsPoint3.h"

// STL
#include <vector>


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Base class for all 3D landmark detectors.
 * - Parameter V is a volume type.
 */
template <class V>
class CLandmarkDetector
{
public:
    //! Check that V is volume. You will see name of this enum somewhere
    //! in compiler error message if the type V is not volume.
    enum { TEMPLATE_PARAMETER_IS_NOT_VOLUME = V::CLASS_VOLUME };

    //! Volume type.
    typedef typename V::tVolume tVolume;

    //! Voxel type.
    typedef typename V::tVoxel tVoxel;

    //! Vector of found corners.
    typedef typename std::vector<CPoint3D> tCorners;

public:
    //! Default constructor.
    CLandmarkDetector() {}
    
    //! Virtual destructor.
    virtual ~CLandmarkDetector() {}

    //! Detects 3D corners in a given volume.
    //! - Returns false on failure. 
    virtual bool operator()(const tVolume& SrcVolume, tCorners& Corners) = 0;
};


} // namespace img
} // namespace mds

#endif // MDS_LandmarkDetector_H 

