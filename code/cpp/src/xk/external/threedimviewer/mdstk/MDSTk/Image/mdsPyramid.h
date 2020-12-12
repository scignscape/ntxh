//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/04/20                          \n
 *
 * $Id: mdsPyramid.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Gaussian image pyramid.
 */

#ifndef MDS_PYRAMID_H
#define MDS_PYRAMID_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsTypes.h>
#include <MDSTk/Base/mdsSharedPtr.h>

#include "mdsImageBase.h"
#include "Filters/mdsGaussian.h"

// STL
#include <vector>


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Template providing pyramidal image representation.
 * - Parameter I means a used image type.
 */
template <class I>
class CPyramid : public mds::base::CObject
{
public:
    //! Check that I is an image. You will see name of this enum somewhere
    //! in compiler error message if the type I is not image.
    enum { TEMPLATE_PARAMETER_IS_NOT_IMAGE = I::CLASS_IMAGE };

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CPyramid);

    //! Image type.
    typedef typename I::tImage tImage;

    //! Image pixel type.
    typedef typename I::tPixel tPixel;

    //! Smart pointer to image.
    typedef typename I::tSmartPtr tImageSmartPtr;

    //! Sigma parameter of the Gaussian filter which is used to smooth images.
    static const double SIGMA;

public:
    //! Default constructor.
    CPyramid() : m_SubSampling(0), m_Levels(0), m_SmoothingFilter(SIGMA) {}

    //! Constructor.
    //! - Creates a new image pyramid based on a given image.
    //! - The original image forms the zero level of the created pyramid.
    CPyramid(tSize SubSampling,
             tSize Levels,
             const CImageBase<tImage>& Image
             );

    //! Destructor.
    virtual ~CPyramid();

    //! Creates a new image pyramid based on a given image.
    //! - The original image forms the zero level of the created pyramid.
    bool create(tSize SubSampling,
                tSize Levels,
                const CImageBase<tImage>& Image
                );


    //! Returns the number of pyramid levels.
    tSize getLevels() const { return m_Levels; }

    //! Returns pyramid subsampling rate.
    tSize getSubSampling() const { return m_SubSampling; }

    //! Returns reference to a specified image.
    tImage& getImage(tSize Level);
    const tImage& getImage(tSize Level) const;

    //! Returns pointer to a specified image.
    //! - NULL on failure.
    tImage *getImagePtr(tSize Level);

    //! Returns the image size of a specified pyramid level.
    tSize getXSize(tSize Level) const
    {
        return m_Images[Level]->getXSize();
    }
    tSize getYSize(tSize Level) const
    {
        return m_Images[Level]->getYSize();
    }

    //! Returns true if the pyramid is created.
    bool isCreated() const { return (m_Levels > 0); }

protected:
    //! Pyramid sub-sampling.
    tSize m_SubSampling;

    //! The number of pyramid levels.
    tSize m_Levels;

    //! Gaussian filter used for smoothing images.
    CGaussFilter<tImage> m_SmoothingFilter;

    //! Vector of subsampled images.
    std::vector<tImageSmartPtr> m_Images;
};


//==============================================================================
/*
 * Method templates.
 */

// Include file containing methods templates
#include "mdsPyramid.hxx"


//==============================================================================
/*
 * Basic template instances and type definitions.
 */

//! Pyramid of the grayscale image, 8-bits per pixel
typedef CPyramid<CImage8>   CImage8Pyramid;

//! Pyramid of the grayscale image, 16-bits per pixel
typedef CPyramid<CImage16>  CImage16Pyramid;

//! Pyramid of the float image
typedef CPyramid<CFImage>   CFImagePyramid;

//! Pyramid of the density image
typedef CPyramid<CDImage>   CDImagePyramid;


//==============================================================================
/*
 * Basic template instances and type definitions
 * - Using smart pointers
 */

//! Pyramid of the grayscale image, 8-bits per pixel
typedef CImage8Pyramid::tSmartPtr   CImage8PyramidPtr;

//! Pyramid of the grayscale image, 16-bits per pixel
typedef CImage16Pyramid::tSmartPtr  CImage16PyramidPtr;

//! Pyramid of the float image
typedef CFImagePyramid::tSmartPtr   CFImagePyramidPtr;

//! Pyramid of the density image
typedef CDImagePyramid::tSmartPtr   CDImagePyramidPtr;


} // namespace img
} // namespace mds

#endif // MDS_PYRAMID_H
