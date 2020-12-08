//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * File:    mdsSegMethod.h                      \n
 * Section: mVolumeSeg                          \n
 * Date:    2005/01/25                          \n
 *
 * $Id: mdsSegMethod.h 967 2008-07-28 15:05:19Z spanel $
 *
 * File description:
 * - Sample implementation of a volume segmentation method.
 */

#ifndef MDS_SEGMETHOD_H
#define MDS_SEGMETHOD_H

#include <MDSTk/Base/mdsSetup.h>
#include <MDSTk/Image/mdsVolume.h>


namespace mds
{
namespace volseg
{

//==============================================================================
/*!
 * Class template providing volume segmentation functions.
 * - Sample code.
 * - Rename this class according to name of your segmentation method.
 */
class CSegMethod
{
public:
    //! Image type.
    typedef mds::img::CDVolume tVolume;

    //! Image pixel type.
    typedef mds::img::CDVolume::tVoxel tVoxel;

public:
    //! Constructor.
    CSegMethod() {}

    //! Virtual destructor.
    virtual ~CSegMethod() {}

    //! Initialization of the segmentation method.
    //! - Returns false on failure.
    bool init();

    //! Volume segmentation.
    //! - Voxel values of the output/destination volume represent segment indexes.
    //! - Returns false on failure.
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);
};


} // namespace volseg
} // namespace mds

#endif // MDS_SEGMETHOD_H

