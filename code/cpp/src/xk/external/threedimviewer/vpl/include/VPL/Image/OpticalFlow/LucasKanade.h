//==============================================================================
/* This file comes from MDSTk software and was modified for
 * 
 * VPL - Voxel Processing Library
 * Changes are Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 * 
 * The original MDSTk legal notice can be found below.
 * 
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2008 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/03                       
 *
 * Description:
 * - Lucas-Kanade optical flow estimation method.
 */

#ifndef VPL_LucasKanade_H
#define VPL_LucasKanade_H

// MDSTk
#include <VPL/Base/Assert.h>
#include <VPL/Base/SharedPtr.h>
#include <VPL/Math/Base.h>
#include <VPL/Math/Matrix.h>
#include <VPL/Math/StaticVector.h>
#include <VPL/Math/StaticMatrix.h>
#include <VPL/Image/Image.h>
#include <VPL/Image/Kernels.h>
#include <VPL/Image/Pyramid.h>
#include <VPL/Image/Vector3.h>
#include <VPL/Image/Color.h>
#include <VPL/Image/Line.h>


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Class able to estimate point optical flow within a small image window
 * around a specified point.
 * - Lucas-Kanade flow estimation method.
 * - Template parameter I is an image type.
 */
template <class I>
class COpticalFlow : public vpl::base::CObject
{
public:
    //! Check that I is an image. You will see name of this enum somewhere
    //! in compiler error message if the type I is not image.
    enum { TEMPLATE_PARAMETER_IS_NOT_IMAGE = I::CLASS_IMAGE };

    //! Smart pointer type.
    //! - declares type tPointer.
    VPL_SHAREDPTR(COpticalFlow);

    //! Image type.
    typedef typename I::tImage tImage;

    //! Image pixel type.
    typedef typename I::tPixel tPixel;

    //! Smart pointer to image.
    typedef typename I::tSmartPtr tImageSmartPtr;

    //! Default size of the window that is used to estimate optical flow.
    static const tSize DEFAULT_WINDOW;

    //! Image pyramid.
    typedef vpl::img::CPyramid<tImage> tPyramid;

public:
    //! Constructor.
    COpticalFlow(tSize WindowSize = DEFAULT_WINDOW);

    //! Constructor.
    //! - Initial subpixel point position and window size.
    COpticalFlow(vpl::img::tCoordinate x,
                 vpl::img::tCoordinate y,
                 tSize WindowSize = DEFAULT_WINDOW
                 );

    //! Destructor.
    virtual ~COpticalFlow() {}


    //! Returns reference to the current point position.
    CPoint3D& getPosition() { return m_Point; }
    const CPoint3D& getPosition() const { return m_Point; }

    //! Returns reference to the estimated motion.
    CVector3D& getMotion() { return m_Motion; }
    const CVector3D& getMotion() const { return m_Motion; }

    //! Returns size of the used window.
    int getWindowSize() const { return m_WindowSize; }


    //! Estimates optical flow between two given images.
    //! - Both images are represented by the image pyramid.
    bool compute(const tPyramid& First, const tPyramid& Second);

    //! Moves point in the direction of the previously estimated optical flow.
    inline void warp();

    //! Clears the motion vector.
    inline void clear();


    //! Visualizes the estimated optical flow.
    //! - Draws a simple white line representing the estimated motion vector.
    bool visualize(tImage& Image);

protected:
    //! Subpixel point position.
    CPoint3D m_Point;

    //! Estimated optical flow.
    CVector3D m_Motion;

    //! Size of the window.
    tSize m_WindowSize;

    //! Helper matrixes.
    vpl::math::CDMatrix m_Ix, m_Iy, m_It;
};


//==============================================================================
/*
 * Method templates.
 */

// Include file containing methods templates
#include "LucasKanade.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_LucasKanade_H

