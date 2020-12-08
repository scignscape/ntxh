//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/20                          \n
 *
 * $Id: mdsSliceView.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Reads an image slice from the input channel.
 * - Draws the slice using GLUT and OpenGL.
 */

#ifndef MDS_SLICEVIEW_H
#define MDS_SLICEVIEW_H

#include <MDSTk/Base/mdsTypes.h>
#include <MDSTk/Module/mdsView.h>
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsImageFunctions.h>


//==============================================================================
/*!
 * Module visualizes an input slice using GLUT and OpenGL.
 */
class CSliceView : public mds::mod::CView
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceView);

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
        MDS_ASSERT(m_pView);
        return m_pView;
    }

    //! Returns pointer to the input slice.
    mds::img::CSlice *getSlice(mds::tSize Index)
    {
        MDS_ASSERT(Index >=0 && Index < MAX_CHANNELS);
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
    mds::img::CSlice m_pSlices[MAX_CHANNELS];
};


//==============================================================================
/*!
 * Smart pointer to view application.
 */
typedef CSliceView::tSmartPtr   CSliceViewPtr;


#endif // MDS_SLICEVIEW_H

