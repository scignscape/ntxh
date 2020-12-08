//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/07/30                          \n
 *
 * $Id: mdsVolumeView.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * File description:
 * - Reads a volume from the input channel.
 * - Visualizes it using GLUT and OpenGL.
 */

#ifndef MDS_VOLUMEVIEW_H
#define MDS_VOLUMEVIEW_H

#include <MDSTk/Module/mdsView.h>
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsDensityVolume.h>


//==============================================================================
/*!
 * Module visualizes input volume using GLUT and OpenGL.
 */
class CVolumeView : public mds::mod::CView
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CVolumeView);

public:
    //! Default constructor.
    CVolumeView(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CVolumeView();

    //! Returns pointer to the current view.
    static CVolumeView *getViewPtr()
    {
        MDS_ASSERT(m_pView);
        return m_pView;
    }

    //! Returns pointer to the input volume.
    mds::img::CDensityVolume *getVolume()
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
    mds::img::CDensityVolume m_Volume;
};


//==============================================================================
/*!
 * Smart pointer to view application.
 */
typedef CVolumeView::tSmartPtr  CVolumeViewPtr;


#endif // MDS_VOLUMEVIEW_H

