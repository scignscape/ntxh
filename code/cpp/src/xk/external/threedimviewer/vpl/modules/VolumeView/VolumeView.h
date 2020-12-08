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
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/07/30                       
 *
 * File description:
 * - Reads a volume from the input channel.
 * - Visualizes it using GLUT and OpenGL.
 */

#ifndef VPL_VOLUMEVIEW_H
#define VPL_VOLUMEVIEW_H

#include <VPL/Module/View.h>
#include <VPL/Image/Slice.h>
#include <VPL/Image/DensityVolume.h>


//==============================================================================
/*!
 * Module visualizes input volume using GLUT and OpenGL.
 */
class CVolumeView : public vpl::mod::CView
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CVolumeView);

public:
    //! Default constructor.
    CVolumeView(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CVolumeView();

    //! Returns pointer to the current view.
    static CVolumeView *getViewPtr()
    {
        VPL_ASSERT(m_pView);
        return m_pView;
    }

    //! Returns pointer to the input volume.
    vpl::img::CDensityVolume *getVolume()
    {
        return &m_Volume;
    }

protected:
    //! Virtual method called on startup.
    virtual bool startup();

    //! Virtual method called by the processing thread.
    virtual bool main();

    //! Called on console shutdown.
    virtual void shutdown();

    //! Called on writing a usage statement.
    virtual void writeExtendedUsage(std::ostream& Stream);

protected:
    //! Static pointer to the created view.
    static CVolumeView *m_pView;

    //! Visualized volume.
    vpl::img::CDensityVolume m_Volume;
};


//==============================================================================
/*!
 * Smart pointer to view application.
 */
typedef CVolumeView::tSmartPtr  CVolumeViewPtr;


#endif // VPL_VOLUMEVIEW_H

