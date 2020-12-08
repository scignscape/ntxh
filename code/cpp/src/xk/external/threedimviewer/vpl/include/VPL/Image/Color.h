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
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/04/25                          \n
 *
 * Description:
 * - RGBA color definition.
 */

#ifndef VPL_COLOR_H
#define VPL_COLOR_H

#include <VPL/Base/Types.h>
//#include <VPL/Base/SmallObject.h>

#include "RGBA.h"
#include "ImageExport.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * RGBA color definition.
 */
class VPL_IMAGE_EXPORT CColor /*: public vpl::base::CSmallValueObject<>*/ : public CRGBA
{
public:
    //! Default constructor.
    //! - Black color, alpha is set to 255.
    CColor() {}

    //! Constructor.
    //! - Separated RGBA color components.
    CColor(tComponent Red, tComponent Green, tComponent Blue, tComponent Alpha = 255)
        : CRGBA(Red, Green, Blue, Alpha)
    {}

    //! Constructor.
    //! - RGBA color.
    CColor(tRGBA Color) : CRGBA(Color) {}

    //! Copy constructor.
    CColor(const CColor& Color) : CRGBA(Color) {}

    //! Assignment operator.
    CColor& operator =(CColor Color)
    {
        m_rgba = Color.m_rgba;
        return *this;
    }

    //! Assignment operator.
    CColor& operator =(tRGBA Color)
    {
        m_rgba = Color;
        return *this;
    }
};


//==============================================================================
/*
 * Basic colors.
 */

 //! Several basic colors.
const CColor C_BLACK = CColor(0x00, 0x00, 0x00, 0xFF);
const CColor C_RED = CColor(0xFF, 0x00, 0x00, 0xFF);
const CColor C_GREEN = CColor(0x00, 0xFF, 0x00, 0xFF);
const CColor C_BLUE = CColor(0x00, 0x00, 0xFF, 0xFF);
const CColor C_WHITE = CColor(0xFF, 0xFF, 0xFF, 0xFF);
const CColor C_YELLOW = CColor(0xFF, 0xFF, 0x00, 0xFF);
const CColor C_MAGENTA = CColor(0xFF, 0x00, 0xFF, 0xFF);
const CColor C_CYAN = CColor(0x00, 0xFF, 0xFF, 0xFF);
const CColor C_GRAY = CColor(0x80, 0x80, 0x80, 0xFF);

} // namespace img
} // namespace vpl

#endif // VPL_COLOR_H

