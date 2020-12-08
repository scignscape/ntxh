//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/09/02                          \n
 *
 * $Id: mdsSliceBlending.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Blending of two slices into one.
 */

#ifndef MDS_SliceBlending_H
#define MDS_SliceBlending_H


#include <MDSTk/Module/mdsModule.h>

//==============================================================================
/*!
 * Module blends two slices.
 */
class CSliceBlending : public mds::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CSliceBlending);

public:
    //! Default constructor.
    CSliceBlending(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CSliceBlending();

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
    //! Module command line parameters values.
    double m_dAlpha;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceBlending::tSmartPtr  CSliceBlendingPtr;


#endif // MDS_SliceBlending_H

