//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)       \n
 * Copyright (c) 2003-2007 by PGMed@FIT            \n
 *
 * Authors: Petr Hyna, xhynap00@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz     \n
 * Date:    2007/04/12                             \n
 *
 * $Id: mdsImageCornerDetector.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - More sophisticated functions for image corner detection.
 */

#ifndef MDS_IMAGECORNERDETECTOR_H
#define MDS_IMAGECORNERDETECTOR_H

#include "mdsImageTypes.h"
#include "mdsImage.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Base class for all image corner detectors.
 * - Parameter I is an image type.
 */
template <class I>
class CImageCornerDetector
{
public:
    //! Check that I is an image. You will see name of this enum somewhere
    //! in compiler error message if the type I is not image.
    enum { TEMPLATE_PARAMETER_IS_NOT_IMAGE = I::CLASS_IMAGE };

    //! Image type.
    typedef typename I::tImage tImage;

    //! Image pixel type.
    typedef typename I::tPixel tPixel;

public:
    //! Default constructor.
    CImageCornerDetector() {}
    
    //! Virtual destructor.
    virtual ~CImageCornerDetector() {}

    //! Corner detection in a given image.
    //! - Returns false on failure.
    virtual bool operator()(const tImage& SrcImage, tImage& DstImage) = 0;
};


} // namespace img
} // namespace mds

#endif // MDS_IMAGECORNERDETECTOR_H 

