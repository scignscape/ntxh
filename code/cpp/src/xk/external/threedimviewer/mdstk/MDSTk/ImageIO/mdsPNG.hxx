//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * File:    mdsPNG.hxx                          \n
 * Section: libImageIO                          \n
 * Date:    2007/06/12                          \n
 *
 * $Id: mdsPNG.hxx 2098 2012-02-16 23:50:36Z spanel $
 *
 * Description:
 * - Reading and writing of PNG images.
 */


//==============================================================================
/*
 * Reading PNG images.
 */

template <class I>
bool loadPNG(CImageBase<I>& Image, mds::mod::CChannel& Channel)
{
    I& ImageImpl = Image.getImpl();
    
    // Create helper grayscale image
    CImage16 HelperImage;
    
    // Load grayscale PNG
    if( !loadGrayPNG(HelperImage, Channel) )
    {
        return false;
    }
    
    // Convert ouput image
    ImageImpl.convert(HelperImage);
    return true;
}


template <>
bool loadPNG(CImageBase<CImage16>& Image, mds::mod::CChannel& Channel)
{
    CImage16& ImageImpl = Image.getImpl();
    
    return loadGrayPNG(ImageImpl, Channel);
}


template <>
bool loadPNG(CImageBase<CRGBImage>& Image, mds::mod::CChannel& Channel)
{
    CRGBImage& ImageImpl = Image.getImpl();
    
    return loadColorPNG(ImageImpl, Channel);
}


template <>
bool loadPNG(CImageBase<CComplexImage>& MDS_UNUSED(Image),
             mds::mod::CChannel& MDS_UNUSED(Channel)
             )
{
    MDS_THROW_ERROR("Cannot load complex image");
    
    return false;
}


//==============================================================================
/*
 * Writing PNG images.
 */

template <class I>
bool savePNG(const CImageBase<I>& Image, mds::mod::CChannel& Channel)
{
    const I& ImageImpl = Image.getImpl();
    
    // Create helper grayscale image
    CImage16 HelperImage;
    
    // Convert input image
    HelperImage.convert(ImageImpl);
    
    // Save the helper image
    return saveGrayPNG(HelperImage, Channel);
}


template <>
bool savePNG(const CImageBase<CImage16>& Image, mds::mod::CChannel& Channel)
{
    const CImage16& ImageImpl = Image.getImpl();
    
    return saveGrayPNG(ImageImpl, Channel);
}


template <>
bool savePNG(const CImageBase<CRGBImage>& Image, mds::mod::CChannel& Channel)
{
    const CRGBImage& ImageImpl = Image.getImpl();
    
    return saveColorPNG(ImageImpl, Channel);
}


template <>
bool savePNG(const CImageBase<CComplexImage>& MDS_UNUSED(Image),
             mds::mod::CChannel& MDS_UNUSED(Channel)
             )
{
    MDS_THROW_ERROR("Cannot save complex image");
    
    return false;
}

