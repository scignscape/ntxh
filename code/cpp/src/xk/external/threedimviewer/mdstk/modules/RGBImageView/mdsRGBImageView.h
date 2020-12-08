//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/13                          \n
 *
 * $Id: mdsRGBImageView.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Reads RGB image from the input channel and draws it using GLUT and OpenGL.
 */

#ifndef MDS_RGBIMAGEVIEW_H
#define MDS_RGBIMAGEVIEW_H

#include <MDSTk/Base/mdsTypes.h>
#include <MDSTk/Module/mdsView.h>
#include <MDSTk/Image/mdsImage.h>
#include <MDSTk/Image/mdsImageFunctions.h>


//==============================================================================
/*!
 * Reads RGB image from the input channel and visualizes it using GLUT and OpenGL.
 */
class CRGBImageView : public mds::mod::CView
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CRGBImageView);

public:
    //! Default constructor
    CRGBImageView(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CRGBImageView();

    //! Returns pointer to the current view.
    static CRGBImageView *getViewPtr()
    {
        MDS_ASSERT(m_pView);
        return m_pView;
    }

    //! Returns pointer to the input RGB image.
    mds::img::CRGBImage *getRGBImage()
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
    mds::img::CRGBImagePtr m_spRGBImage;
};


//==============================================================================
/*!
 * Smart pointer to view application.
 */
typedef CRGBImageView::tSmartPtr   CRGBImageViewPtr;


#endif // MDS_RGBIMAGEVIEW_H

