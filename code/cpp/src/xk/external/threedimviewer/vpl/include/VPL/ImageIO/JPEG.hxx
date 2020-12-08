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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/12                          \n
 *
 * Description:
 * - Reading and writing of JPEG images.
 */


//==============================================================================
/*
 * Reading JPEG images.
 */

template <class I>
bool loadJPEG(CImageBase<I>& Image, vpl::mod::CChannel& Channel)
{
    I& ImageImpl = Image.getImpl();
    
    // Create helper grayscale image
    CImage8 HelperImage;
    
    // Load grayscale JPEG
    if( !loadGrayJPEG(HelperImage, Channel) )
    {
        return false;
    }
    
    // Convert ouput image
    ImageImpl.convert(HelperImage);
    return true;
}


template <>
bool loadJPEG(CImageBase<CImage8>& Image, vpl::mod::CChannel& Channel)
{
    CImage8& ImageImpl = Image.getImpl();
    
    return loadGrayJPEG(ImageImpl, Channel);
}


template <>
bool loadJPEG(CImageBase<CRGBImage>& Image, vpl::mod::CChannel& Channel)
{
    CRGBImage& ImageImpl = Image.getImpl();
    
    return loadColorJPEG(ImageImpl, Channel);
}


template <>
bool loadJPEG(CImageBase<CComplexImage>& VPL_UNUSED(Image),
              vpl::mod::CChannel& VPL_UNUSED(Channel)
              )
{
    VPL_THROW_ERROR("Cannot load complex image");
    
    return false;
}


//==============================================================================
/*
 * Writing JPEG images.
 */

template <class I>
bool saveJPEG(const CImageBase<I>& Image, vpl::mod::CChannel& Channel, int iQuality)
{
    const I& ImageImpl = Image.getImpl();
    
    // Create helper grayscale image
    CImage8 HelperImage;
    
    // Convert input image
    HelperImage.convert(ImageImpl);
    
    // Save the helper image
    return saveGrayJPEG(HelperImage, Channel, iQuality);
}


template <>
bool saveJPEG(const CImageBase<CImage8>& Image, vpl::mod::CChannel& Channel, int iQuality)
{
    const CImage8& ImageImpl = Image.getImpl();
    
    return saveGrayJPEG(ImageImpl, Channel, iQuality);
}


template <>
bool saveJPEG(const CImageBase<CRGBImage>& Image, vpl::mod::CChannel& Channel, int iQuality)
{
    const CRGBImage& ImageImpl = Image.getImpl();
    
    return saveColorJPEG(ImageImpl, Channel, iQuality);
}


template <>
bool saveJPEG(const CImageBase<CComplexImage>& VPL_UNUSED(Image),
              vpl::mod::CChannel& VPL_UNUSED(Channel),
              int VPL_UNUSED(iQuality)
              )
{
    VPL_THROW_ERROR("Cannot save complex image");
    
    return false;
}

