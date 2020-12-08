//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)	\n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/14                          \n
 *
 * $Id: mdsRGBImage2Slice.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Converts input RGB image to medical slice.
 */

#ifndef MDS_RGBIMAGE2SLICE_H
#define MDS_RGBIMAGE2SLICE_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Converts input RGB image to medical slice.
 */
class CRGBImage2Slice : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CRGBImage2Slice);

public:
    //! Default constructor
    CRGBImage2Slice(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CRGBImage2Slice();

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
    //! Module parameters.
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CRGBImage2Slice::tSmartPtr  CRGBImage2SlicePtr;


#endif // MDS_RGBIMAGE2SLICE_H

