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
 * Copyright (c) 2003-2010 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/02/05                       
 *
 * Description:
 * - Image iterator definition.
 */

#ifndef VPL_IMAGEITERATOR_H
#define VPL_IMAGEITERATOR_H

#include <VPL/Base/IteratorBase.h>


namespace vpl
{

// Declare iterator traits first...
VPL_ITERATOR_TEMPLATE_TRAITS(img, CImageIterator)

namespace img
{

//==============================================================================
/*!
 * Iterator used to traverse image pixels by lines.
 * - Template parameter I is the image type.
 * - Parameter T is the image pixel type.
 */
template <class I, typename T>
class CImageIterator : public vpl::base::CIteratorBase<CImageIterator<I, T> >
{
public:
    //! Check that I is an image. You will see name of this enum somewhere
    //! in compiler error message if the type I is not image.
    enum { TEMPLATE_PARAMETER_IS_NOT_IMAGE = I::CLASS_IMAGE };

    //! Image type.
    typedef I tImage;

    //! Pixel type.
    typedef T tPixel;

public:
    //! Constructor.
    CImageIterator(tImage& Image)
        : m_Image(Image)
        , m_x(0)
        , m_y(0)
    {}

    //! Destructor.
    ~CImageIterator() {}

    //! Returns current iterator position.
    tSize x() const { return m_x; }
    tSize y() const { return m_y; }

    //! Moves iterator to the next pixel.
    void advance()
    {
        if( ++m_x >= m_Image.getXSize() )
        {
            m_x = 0;
            ++m_y;
        }
    }

    //! Returns true if the iterator points at the end.
    bool atEnd() const
    {
        return (m_y >= m_Image.getYSize());
    }

    //! Returns the current pixel value.
    const tPixel& value() const
    {
        return m_Image.at(m_x, m_y);
    }

    //! Returns reference to the current pixel.
    tPixel& valueRef() const
    {
        return m_Image.at(m_x, m_y);
    }

    //! Returns pointer to the current pixel.
    tPixel *valuePtr() const
    {
        return m_Image.getPtr(m_x, m_y);
    }

    //! Returns size of the image in pixels.
    tSize getSize() const
    {
        return m_Image.getXSize() * m_Image.getYSize();
    }

protected:
    //! Reference to the image.
    tImage& m_Image;

    //! Current iterator position.
    tSize m_x, m_y;

private:
    //! Private assignmet operator.
    CImageIterator& operator =(const CImageIterator& ) { return this; }
};


} // namespace img
} // namespace vpl

#endif // VPL_IMAGEITERATOR_H

