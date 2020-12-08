//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/02/05                          \n
 *
 * $Id: mdsImageIterator.h 2092 2012-02-15 12:50:59Z spanel $
 *
 * Description:
 * - Image iterator definition.
 */

#ifndef MDS_IMAGEITERATOR_H
#define MDS_IMAGEITERATOR_H

#include <MDSTk/Base/mdsIteratorBase.h>


namespace mds
{

// Declare iterator traits first...
MDS_ITERATOR_TEMPLATE_TRAITS(img, CImageIterator)

namespace img
{

//==============================================================================
/*!
 * Iterator used to traverse image pixels by lines.
 * - Template parameter I is the image type.
 * - Parameter T is the image pixel type.
 */
template <class I, typename T>
class CImageIterator : public mds::base::CIteratorBase<CImageIterator<I, T> >
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
} // namespace mds

#endif // MDS_IMAGEITERATOR_H

