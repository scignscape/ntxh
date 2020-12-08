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
 * Date:    2003/12/20                       
 *
 * File description:
 * - Reads an image slice from the input channel.
 * - Draws the slice using GLUT and OpenGL.
 */

#ifndef VPL_SLICEVIEW_H
#define VPL_SLICEVIEW_H

#include <VPL/Base/Types.h>
#include <VPL/Module/View.h>
#include <VPL/Image/Slice.h>
#include <VPL/Image/ImageFunctions.h>


//==============================================================================
/*!
 * Module visualizes an input slice using GLUT and OpenGL.
 */
class CSliceView : public vpl::mod::CView
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSliceView);

    //! Maximal number of input channels.
    static const int MAX_CHANNELS = 2;

public:
    //! Default constructor
    CSliceView(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceView();

    //! Returns pointer to the current view.
    static CSliceView *getViewPtr()
    {
        VPL_ASSERT(m_pView);
        return m_pView;
    }

    //! Returns pointer to the input slice.
    vpl::img::CSlice *getSlice(vpl::tSize Index)
    {
        VPL_ASSERT(Index >=0 && Index < MAX_CHANNELS);
        return (m_pSlices + Index);
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
    static CSliceView *m_pView;

    //! Input slices.
    vpl::img::CSlice m_pSlices[MAX_CHANNELS];
};


//==============================================================================
/*!
 * Smart pointer to view application.
 */
typedef CSliceView::tSmartPtr   CSliceViewPtr;


#endif // VPL_SLICEVIEW_H

