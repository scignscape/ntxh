//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/18                          \n
 *
 * $Id: mdsRGBA.h 2121 2012-02-21 02:01:58Z spanel $
 *
 * Description:
 * - Structure encapsulating RGBA values.
 */

#ifndef MDS_RGBA_H
#define MDS_RGBA_H

#include <MDSTk/Base/mdsTypes.h>

#include "mdsImageExport.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Structure encapsulating RGBA values.
 */
class MDS_IMAGE_EXPORT CRGBA
{
public:
    //! Single RGBA component type.
    typedef mds::sys::tUInt8 tComponent;

    //! RGBA represented as unsigned long.
    typedef mds::sys::tUInt32 tRGBA;

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
    tComponent& getRed() { return m_Components[0]; }

    //! Returns reference to the green component.
    const tComponent& getGreen() const { return m_Components[1]; }
    tComponent& getGreen(){ return m_Components[1]; }

    //! Returns reference to the blue component.
    const tComponent& getBlue() const { return m_Components[2]; }
    tComponent& getBlue() { return m_Components[2]; }

    //! Returns reference to the alpha component.
    const tComponent& getAlpha() const { return m_Components[3]; }
    tComponent& getAlpha() { return m_Components[3]; }

    //! Returns reference to the all RGBA components.
    const tRGBA& getRGBA() const { return m_rgba; }
    tRGBA& getRGBA() { return m_rgba; }


    //! Returns reference to the red component.
    const tComponent& r() const { return m_Components[0]; }
    tComponent& r() { return m_Components[0]; }

    //! Returns reference to the green component.
    const tComponent& g() const { return m_Components[1]; }
    tComponent& g(){ return m_Components[1]; }

    //! Returns reference to the blue component.
    const tComponent& b() const { return m_Components[2]; }
    tComponent& b() { return m_Components[2]; }

    //! Returns reference to the alpha component.
    const tComponent& a() const { return m_Components[3]; }
    tComponent& a() { return m_Components[3]; }

    //! Returns reference to the all RGBA components.
    const tRGBA& rgba() const { return m_rgba; }
    tRGBA& rgba() { return m_rgba; }

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
    friend bool operator ==(const CRGBA& l, const CRGBA& r)
    {
        return (l.r() == r.r() && l.g() == r.g() && l.b() == r.b());
    }
    friend bool operator !=(const CRGBA& l, const CRGBA& r)
    {
        return (l.r() != r.r() || l.g() != r.g() || l.b() != r.b());
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
} // namespace mds

#endif // MDS_RGBA_H

