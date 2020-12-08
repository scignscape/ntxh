//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/12/16                          \n
 *
 * $Id: mdsImageTransform.h 2098 2012-02-16 23:50:36Z spanel $
 *
 * Description:
 * - Geometrical image transformations.
 */

#ifndef MDS_ImageTransform_H
#define MDS_ImageTransform_H

#include "../mdsImageTypes.h"
#include "../mdsImage.h"

#include "mdsInterpolate.h"


namespace mds
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
} // namespace mds

#endif // MDS_ImageTransform_H

