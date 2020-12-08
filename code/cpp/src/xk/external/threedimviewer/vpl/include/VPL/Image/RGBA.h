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
 * Date:    2004/05/18
 *
 * Description:
 * - Structure encapsulating RGBA values.
 */

#ifndef VPL_RGBA_H
#define VPL_RGBA_H

#include <VPL/Base/Types.h>

#include "ImageExport.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
* Structure encapsulating RGBA values.
*/
class VPL_IMAGE_EXPORT CRGBA
{
public:
    //! Single RGBA component type.
    typedef vpl::sys::tUInt8 tComponent;

    //! RGBA represented as unsigned long.
    typedef vpl::sys::tUInt32 tRGBA;

public:
    //! Default constructor.
    CRGBA() : m_rgba(0xff000000U) {}

    //! Constructor.
    CRGBA(tComponent Red, tComponent Green, tComponent Blue, tComponent Alpha = 255)
        : m_rgba((Alpha << 24) + (Blue << 16) + (Green << 8) + Red)
    {}

    //! Constructor
    CRGBA(tRGBA Value) : m_rgba(Value) {}

    //! Copy constructor.
    CRGBA(const CRGBA& v) : m_rgba(v.m_rgba) {}

    //! Assignment operators.
    CRGBA& operator =(CRGBA v)
    {
        m_rgba = v.m_rgba;
        return *this;
    }

    CRGBA& operator =(tRGBA v)
    {
        m_rgba = v;
        return *this;
    }


    //! Returns reference to the red component.
    const tComponent& getRed() const { return m_Components[0]; }
    //! Returns reference to the green component.
    const tComponent& getGreen() const { return m_Components[1]; }
    //! Returns reference to the blue component.
    const tComponent& getBlue() const { return m_Components[2]; }

    //! Returns reference to the alpha component.
    const tComponent& getAlpha() const { return m_Components[3]; }
    //! Returns reference to the all RGBA components.
    const tRGBA& getRGBA() const { return m_rgba; }

    //! Returns reference to the red component.
    const tComponent& r() const { return m_Components[0]; }
    //! Returns reference to the green component.
    const tComponent& g() const { return m_Components[1]; }

    //! Returns reference to the blue component.
    const tComponent& b() const { return m_Components[2]; }

    //! Returns reference to the alpha component.
    const tComponent& a() const { return m_Components[3]; }

    //! Returns reference to the all RGBA components.
    const tRGBA& rgba() const { return m_rgba; }

#ifndef SWIG
    //! Returns reference to the red component.
    tComponent& getRed() { return m_Components[0]; }
    //! Returns reference to the green component.
    tComponent& getGreen() { return m_Components[1]; }
    //! Returns reference to the blue component.
    tComponent& getBlue() { return m_Components[2]; }
    //! Returns reference to the alpha component.
    tComponent& getAlpha() { return m_Components[3]; }
    
    //! Returns reference to the all RGBA components.
    tRGBA& getRGBA() { return m_rgba; }
    
    //! Returns reference to the red component.
    tComponent& r() { return m_Components[0]; }
    //! Returns reference to the green component.
    tComponent& g() { return m_Components[1]; }
    //! Returns reference to the blue component.
    tComponent& b() { return m_Components[2]; }
    //! Returns reference to the alpha component.
    tComponent& a() { return m_Components[3]; }
    
    //! Returns reference to the all RGBA components.
    tRGBA& rgba() { return m_rgba; }
    
#endif

    //! Changes component values.
    CRGBA& set(tComponent Red, tComponent Green, tComponent Blue, tComponent Alpha = 255)
    {
        m_rgba = (Alpha << 24) + (Blue << 16) + (Green << 8) + Red;
        return *this;
    }
    
    //! Changes component value.
    CRGBA& setRed(tComponent Red)
    {
        m_Components[0] = Red;
        return *this;
    }
    CRGBA& setGreen(tComponent Green)
    {
        m_Components[1] = Green;
        return *this;
    }
    CRGBA& setBlue(tComponent Blue)
    {
        m_Components[2] = Blue;
        return *this;
    }
    CRGBA& setAlpha(tComponent Alpha)
    {
        m_Components[3] = Alpha;
        return *this;
    }
    
    //! Comparison operator
    bool operator ==(const CRGBA& r)
    {
        return (getRed() == r.r() && getGreen() == r.g() && getBlue() == r.b());
    }
    bool operator !=(const CRGBA& r)
    {
        return (getRed() != r.r() || getGreen() != r.g() || getBlue() != r.b());
    }
    
    protected:
        //! RGBA components.
        union
        {
            //! Separated RGBA components.
            tComponent m_Components[4];
    
            //! RGBa represented as a one unsigned long value.
            tRGBA m_rgba;
        };
    };
    
    
} // namespace img
} // namespace vpl

#endif // VPL_RGBA_H

