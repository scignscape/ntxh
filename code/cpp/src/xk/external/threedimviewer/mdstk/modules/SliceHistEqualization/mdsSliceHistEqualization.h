//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/04/17                          \n
 *
 * $Id: mdsSliceHistEqualization.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * Description:
 * - Histogram equalization.
 */

#ifndef MDS_SLICEHISTEQUALIZATION_H
#define MDS_SLICEHISTEQUALIZATION_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module equalizes histogram of input slice.
 */
class CSliceHistEqualization : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceHistEqualization);

public:
    //! Default constructor
    CSliceHistEqualization(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceHistEqualization();

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
    //! Command line arguments
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceHistEqualization::tSmartPtr  CSliceHistEqualizationPtr;


#endif // MDS_SLICEHISTEQUALIZATION_H

