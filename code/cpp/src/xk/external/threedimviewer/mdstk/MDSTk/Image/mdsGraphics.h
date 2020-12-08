//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/04/25                          \n
 *
 * $Id: mdsGraphics.h 2100 2012-02-17 07:36:55Z spanel $
 * 
 * Description:
 * - Base class for all graphic primitives.
 */

#ifndef MDS_GRAPHICS_H
#define MDS_GRAPHICS_H

#include "mdsColor.h"
#include "mdsImageBase.h"
#include "mdsVolumeBase.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Base class for all graphic primitives.
 * - Base class takes a template parameter G. This parameter is the type
 *   of the class which derives from it (so called Barton-Nackman trick).
 */
template <class G>
class CGraphics
{
public:
    //! Graphic primitive type.
    typedef G tGraphics;

public:
    //! Default constructor.
    CGraphics() : m_Color(C_WHITE) {}

    //! Constructor.
    //! - Initializes the graphic primitive color.
    CGraphics(CColor Color) : m_Color(Color) {}

    //! Destructor.
    ~CGraphics() {}


    //! Returns reference to the graphic primitive implementation.
    tGraphics& getImpl()
    {
        return *static_cast<tGraphics *>(this);
    }
    const tGraphics& getImpl() const
    {
        return *static_cast<const tGraphics *>(this);
    }

    //! Draws the primitive to a given image.
    template <class I>
    void draw(CImageBase<I>& Image)
    {
        getImpl().draw(Image);
    }

    //! Draws the primitive to a given volume.
    template <class V>
    void draw(CVolumeBase<V>& Volume)
    {
        getImpl().draw(Volume);
    }


    //! Returns color of the graphic primitive.
    CColor getColor() { return m_Color; }

    //! Sets color of the graphic primitive.
    void setColor(CColor Color) { m_Color = Color; }

protected:
    //! Graphic primitive color.
    CColor m_Color;
};


} // namespace img
} // namespace mds

#endif // MDS_GRAPHICS_H

