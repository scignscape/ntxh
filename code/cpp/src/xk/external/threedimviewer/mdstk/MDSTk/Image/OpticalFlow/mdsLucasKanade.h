//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/03                          \n
 *
 * $Id: mdsLucasKanade.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Lucas-Kanade optical flow estimation method.
 */

#ifndef MDS_LucasKanade_H
#define MDS_LucasKanade_H

// MDSTk
#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsSharedPtr.h>
#include <MDSTk/Math/mdsBase.h>
#include <MDSTk/Math/mdsMatrix.h>
#include <MDSTk/Math/mdsStaticVector.h>
#include <MDSTk/Math/mdsStaticMatrix.h>
#include <MDSTk/Image/mdsImage.h>
#include <MDSTk/Image/mdsKernels.h>
#include <MDSTk/Image/mdsPyramid.h>
#include <MDSTk/Image/mdsVector3.h>
#include <MDSTk/Image/mdsColor.h>
#include <MDSTk/Image/mdsLine.h>


namespace mds
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
class COpticalFlow : public mds::base::CObject
{
public:
    //! Check that I is an image. You will see name of this enum somewhere
    //! in compiler error message if the type I is not image.
    enum { TEMPLATE_PARAMETER_IS_NOT_IMAGE = I::CLASS_IMAGE };

    //! Smart pointer type.
    //! - declares type tPointer.
    MDS_SHAREDPTR(COpticalFlow);

    //! Image type.
    typedef typename I::tImage tImage;

    //! Image pixel type.
    typedef typename I::tPixel tPixel;

    //! Smart pointer to image.
    typedef typename I::tSmartPtr tImageSmartPtr;

    //! Default size of the window that is used to estimate optical flow.
    static const tSize DEFAULT_WINDOW;

    //! Image pyramid.
    typedef mds::img::CPyramid<tImage> tPyramid;

public:
    //! Constructor.
    COpticalFlow(tSize WindowSize = DEFAULT_WINDOW);

    //! Constructor.
    //! - Initial subpixel point position and window size.
    COpticalFlow(mds::img::tCoordinate x,
                 mds::img::tCoordinate y,
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
    mds::math::CDMatrix m_Ix, m_Iy, m_It;
};


//==============================================================================
/*
 * Method templates.
 */

// Include file containing methods templates
#include "mdsLucasKanade.hxx"


} // namespace img
} // namespace mds

#endif // MDS_LucasKanade_H

