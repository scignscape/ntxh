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
 * Date:    2006/03/30                       
 *
 * Description:
 * - Local moments (local texture features).
 */

#ifndef VPL_IF_LOCAL_MOMENTS_H
#define VPL_IF_LOCAL_MOMENTS_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "../ImageFilter.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Local moment.
 * - Parameter I is a used image type.
 * - Kernel definition: \n
 *   [ 1  1  1 ] \n
 *   [ 1  1  1 ] \n
 *   [ 1  1  1 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CLocalMoment00 : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response.
    static const int DENOM = 9;

public:
    //! Default constructor.
    CLocalMoment00() {}

    //! Destructor.
    ~CLocalMoment00() {}

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
 * Local moment.
 * - Parameter I is a used image type.
 * - Kernel definition: \n
 *   [ -1 -1 -1 ] \n
 *   [  0  0  0 ] \n
 *   [  1  1  1 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CLocalMoment10 : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response.
    static const int DENOM = 3;

public:
    //! Default constructor.
    CLocalMoment10() {}

    //! Destructor.
    ~CLocalMoment10() {}

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
 * Local moment.
 * - Parameter I is a used image type.
 * - Kernel definition: \n
 *   [ -1  0  1 ] \n
 *   [ -1  0  1 ] \n
 *   [ -1  0  1 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CLocalMoment01 : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response.
    static const int DENOM = 3;

public:
    //! Default constructor.
    CLocalMoment01() {}

    //! Destructor.
    ~CLocalMoment01() {}

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
 * Local moment.
 * - Parameter I is a used image type.
 * - Kernel definition: \n
 *   [  1  0 -1 ] \n
 *   [  0  0  0 ] \n
 *   [ -1  0  1 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CLocalMoment11 : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response.
    static const int DENOM = 2;

public:
    //! Default constructor.
    CLocalMoment11() {}

    //! Destructor.
    ~CLocalMoment11() {}

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
 * Local moment.
 * - Parameter I is a used image type.
 * - Kernel definition: \n
 *   [ 1  1  1 ] \n
 *   [ 0  0  0 ] \n
 *   [ 1  1  1 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CLocalMoment20 : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response.
    static const int DENOM = 6;

public:
    //! Default constructor.
    CLocalMoment20() {}

    //! Destructor.
    ~CLocalMoment20() {}

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
 * Local moment.
 * - Parameter I is a used image type.
 * - Kernel definition: \n
 *   [ 1  0  1 ] \n
 *   [ 1  0  1 ] \n
 *   [ 1  0  1 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CLocalMoment02 : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response.
    static const int DENOM = 6;

public:
    //! Default constructor.
    CLocalMoment02() {}

    //! Destructor.
    ~CLocalMoment02() {}

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
 * Local moment.
 * - Parameter I is a used image type.
 * - Kernel definition: \n
 *   [ 1  0  1 ] \n
 *   [ 0  0  0 ] \n
 *   [ 1  0  1 ] \n
 */
template <class I, template <typename> class N = CDefaultFilterPolicy>
class CLocalMoment22 : public CNormImageFilter<I,N>
{
public:
    //! Image filter base.
    typedef CNormImageFilter<I,N> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;
    typedef typename base::tResult tResult;

    //! Number used to divide filter response.
    static const int DENOM = 4;

public:
    //! Default constructor.
    CLocalMoment22() {}

    //! Destructor.
    ~CLocalMoment22() {}

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
#include "LocalMoments.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_IF_LOCAL_MOMENTS_H

