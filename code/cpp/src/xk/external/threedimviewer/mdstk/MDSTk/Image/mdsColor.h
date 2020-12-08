//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/04/25                          \n
 *
 * $Id: mdsColor.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - RGBA color definition.
 */

#ifndef MDS_COLOR_H
#define MDS_COLOR_H

#include <MDSTk/Base/mdsTypes.h>
//#include <MDSTk/Base/mdsSmallObject.h>

#include "mdsRGBA.h"
#include "mdsImageExport.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * RGBA color definition.
 */
class MDS_IMAGE_EXPORT CColor /*: public mds::base::CSmallValueObject<>*/ : public CRGBA
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
const CColor C_BLACK    (0x00, 0x00, 0x00, 0xFF);
const CColor C_RED      (0xFF, 0x00, 0x00, 0xFF);
const CColor C_GREEN    (0x00, 0xFF, 0x00, 0xFF);
const CColor C_BLUE     (0x00, 0x00, 0xFF, 0xFF);
const CColor C_WHITE    (0xFF, 0xFF, 0xFF, 0xFF);
const CColor C_YELLOW   (0xFF, 0xFF, 0x00, 0xFF);
const CColor C_MAGENTA  (0xFF, 0x00, 0xFF, 0xFF);
const CColor C_CYAN     (0x00, 0xFF, 0xFF, 0xFF);
const CColor C_GRAY     (0x80, 0x80, 0x80, 0xFF);


} // namespace img
} // namespace mds

#endif // MDS_COLOR_H

