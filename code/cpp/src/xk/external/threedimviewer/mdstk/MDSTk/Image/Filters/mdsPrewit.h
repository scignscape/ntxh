//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/15                          \n
 *
 * $Id: mdsPrewit.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Prewit gradient edge detectors.
 */

#ifndef MDS_IF_PREWIT_H
#define MDS_IF_PREWIT_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsImageFilter.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Prewit gradient edge detector (horizontal version).
 * - Parameter I is a used image type.
 * - Policy N is used for filter response normalization.
 * - Kernel definition: \n
 *   1 [ -1  0  1 ] \n
 *   - [ -1  0  1 ] \n
 *   3 [ -1  0  1 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CPrewitX : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 3;

public:
    //! Default constructor.
    CPrewitX() {}

    //! Destructor.
    ~CPrewitX() {}

    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    inline tResult getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns filter standard deviation.
    tSize getSize() const { return 3; }
};


//==============================================================================
/*!
 * Prewit gradient edge detector (vertical edges).
 * - Parameter I is a used image type.
 * - Policy N is used for filter response normalization.
 * - Kernel definition: \n
 *   1 [ -1 -1 -1 ] \n
 *   - [  0  0  0 ] \n
 *   3 [  1  1  1 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CPrewitY : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response
    static const int DENOM = 3;

public:
    //! Default constructor.
    CPrewitY() {}

    //! Destructor.
    ~CPrewitY() {}

    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns filter response at specified image point.
    //! - Value is not normalized!
    inline tResult getResponse(const tImage& SrcImage, tSize x, tSize y);

    //! Returns filter standard deviation.
    tSize getSize() const { return 3; }
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsPrewit.hxx"


} // namespace img
} // namespace mds

#endif // MDS_IF_PREWIT_H

