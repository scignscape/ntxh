//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/22                          \n
 *
 * $Id: mdsSliceInfo.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Shows information on input slice.
 */

#ifndef MDS_SLICEINFO_H
#define MDS_SLICEINFO_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module reads an input slice and prints several information on it.
 */
class CSliceInfo : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceInfo);

public:
    //! Default constructor
    CSliceInfo(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceInfo();

protected:
    //! Virtual method called on startup
    virtual bool startup();

    //! Virtual method called by the processing thread
    virtual bool main();

    //! Called on console shutdown
    virtual void shutdown();

    //! Called on writing a usage statement
    virtual void writeExtendedUsage(std::ostream& Stream);
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceInfo::tSmartPtr   CSliceInfoPtr;


#endif // MDS_SLICEINFO_H

