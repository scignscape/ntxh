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
 * Copyright (c) 2003-2009 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/12/16                       
 *
 * Description:
 * - Geometrical image transformations.
 */

#ifndef VPL_ImageTransform_H
#define VPL_ImageTransform_H

#include "../ImageTypes.h"
#include "../Image.h"

#include "Interpolate.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Global definitions.
 */

namespace ImageTransform
{
    //! Image transformation settings...
    enum EOptions
    {
        RESIZE = 1,         //! Resize the destination image automatically.
        FILL_MARGIN = 2     //! Fill the destination image automatically.
    };
}


//==============================================================================
/*!
 * Base class for all geometrical image transformations.
 * - Policy Interpolator is used for pixel value interpolation.
 */
template <class I, template <class> class Interpolator>
class CImageTransform : public Interpolator<I>
{
public:
    //! Check that I is an image. You will see name of this enum somewhere
    //! in compiler error message if the type I is not image.
    enum { TEMPLATE_PARAMETER_IS_NOT_IMAGE = I::CLASS_IMAGE };

    //! Image type.
    typedef typename I::tImage tImage;

    //! Image pixel type.
    typedef typename I::tPixel tPixel;

    //! Interpolation function.
    using Interpolator<I>::interpolate;

public:
    //! Default constructor.
    CImageTransform(int Flags = 0)
        : m_Options(Flags)
        , m_MarginValue(CPixelTraits<tPixel>::getPixelMin())
    {}

    //! Virtual destructor.
    virtual ~CImageTransform() {}

    //! Applies the geometrical transformation to an input image.
    //! - Returns false on failure.
    virtual bool operator()(const tImage& SrcImage, tImage& DstImage) = 0;

    //! Sets transformation settings.
    CImageTransform& setOptions(int Flags)
    {
        m_Options = Flags;
        return *this;
    }

    //! Checks if a given option is enabled.
    bool checkOption(int Flag)
    {
        return (m_Options & Flag) == Flag;
    }

    //! Enables automatic correction of the output image size.
    CImageTransform& resize()
    {
        m_Options |= ImageTransform::RESIZE;
        return *this;
    }

    //! Sets pixel value used to fill image margin.
    CImageTransform& fillMargin(tPixel Value)
    {
        m_MarginValue = Value;
        m_Options |= ImageTransform::FILL_MARGIN;
        return *this;
    }

protected:
    //! Transformation settings.
    int m_Options;

    //! Pixel value used to fill image margin.
    tPixel m_MarginValue;
};


} // namespace img
} // namespace vpl

#endif // VPL_ImageTransform_H

