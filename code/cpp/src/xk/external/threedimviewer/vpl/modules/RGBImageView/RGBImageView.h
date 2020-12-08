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
 * Copyright (c) 2003-2007 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/13                       
 *
 * File description:
 * - Reads RGB image from the input channel and draws it using GLUT and OpenGL.
 */

#ifndef VPL_RGBIMAGEVIEW_H
#define VPL_RGBIMAGEVIEW_H

#include <VPL/Base/Types.h>
#include <VPL/Module/View.h>
#include <VPL/Image/Image.h>
#include <VPL/Image/ImageFunctions.h>


//==============================================================================
/*!
 * Reads RGB image from the input channel and visualizes it using GLUT and OpenGL.
 */
class CRGBImageView : public vpl::mod::CView
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CRGBImageView);

public:
    //! Default constructor
    CRGBImageView(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CRGBImageView();

    //! Returns pointer to the current view.
    static CRGBImageView *getViewPtr()
    {
        VPL_ASSERT(m_pView);
        return m_pView;
    }

    //! Returns pointer to the input RGB image.
    vpl::img::CRGBImage *getRGBImage()
    {
        return m_spRGBImage;
    }

protected:
    //! Virtual method called on startup
    virtual bool startup();

    //! Virtual method called by the processing thread
    virtual bool main();

    //! Called on console shutdown
    virtual void shutdown();

    //! Called on writing a usage statement
    virtual void writeExtendedUsage(std::ostream& Stream);

protected:
    //! Static pointer to the created view.
    static CRGBImageView *m_pView;

    //! Input slice.
    vpl::img::CRGBImagePtr m_spRGBImage;
};


//==============================================================================
/*!
 * Smart pointer to view application.
 */
typedef CRGBImageView::tSmartPtr   CRGBImageViewPtr;


#endif // VPL_RGBIMAGEVIEW_H

