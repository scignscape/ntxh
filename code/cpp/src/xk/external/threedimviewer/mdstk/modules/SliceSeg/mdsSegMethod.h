//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * File:    mdsSegMethod.h                      \n
 * Section: mSliceSeg                           \n
 * Date:    2004/03/01                          \n
 *
 * $Id: mdsSegMethod.h 967 2008-07-28 15:05:19Z spanel $
 *
 * File description:
 * - Sample implementation of an image segmentation method.
 */

#ifndef MDS_SEGMETHOD_H
#define MDS_SEGMETHOD_H

#include <MDSTk/Base/mdsSetup.h>
#include <MDSTk/Image/mdsImage.h>


namespace mds
{
namespace imseg
{

//==============================================================================
/*!
 * Class template providing image segmentation functions.
 * - Sample code!
 * - Rename the class according to name of your segmentation method.
 */
class CSegMethod
{
public:
    //! Image type.
    typedef mds::img::CDImage tImage;

    //! Image pixel type.
    typedef mds::img::CDImage::tPixel tPixel;

public:
    //! Constructor.
    CSegMethod() {}

    //! Virtual destructor.
    virtual ~CSegMethod() {}

    //! Initialization of the segmentation method.
    //! - Returns false on failure.
    bool init();

    //! Segmentation of a given image.
    //! - Pixel values of the output/destination image represent segment indexes.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);
};


} // namespace mds
} // namespace imseg

#endif // MDS_SEGMETHOD_H

