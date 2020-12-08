//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2010 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/18                          \n
 *
 * $Id: mdsCvTraits.h 1707 2010-05-05 11:00:46Z spanel $
 *
 * Description:
 * - OpenCV specific image pixel traits.
 */

#ifndef MDS_CvTraits_H
#define MDS_CvTraits_H

#include <MDSTk/Base/mdsSetup.h>

#ifdef MDS_OPENCV_ENABLED

// MDSTk pixel types
#include "mdsPixelTypes.h"

// OpenCV
#include <cxcore.h>


namespace mds
{
namespace img
{

//==============================================================================
/*
 * OpenCV specific image pixel traits.
 */
template <typename T>
class CvTraits
{
public:
    //! Returns depth for a corresponding OpenCV image.
    inline static int getDepth();

    //! Returns number of channels for a corresponding OpenCV image.
    inline static int getChannels();

    //! Returns pixel size in bytes.
    static int getPixelSize()
    {
        return ((getDepth() & 255) >> 3) * getChannels();
    }

    //! Returns offset (in pixels) betwen two neighbouring
    //! pixels in image column.
    inline static int convWidthStep(int Bytes);
};


//==============================================================================
/*
 * Include type traits for the predefined pixel types.
 */
#include "mdsCvTraits.hxx"


} // namespace img
} // namespace mds

#endif // MDS_OPENCV_ENABLED
#endif // MDS_CvTraits_H
