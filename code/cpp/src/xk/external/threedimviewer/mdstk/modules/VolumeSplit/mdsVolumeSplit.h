//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/07/30                          \n
 *
 * $Id: mdsVolumeSplit.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * File description:
 * - Splits an input volume into several slices.
 */

#ifndef MDS_VOLUMESPLIT_H
#define MDS_VOLUMESPLIT_H

#include <MDSTk/Module/mdsModule.h>
#include <MDSTk/Image/mdsSlice.h>


//==============================================================================
/*!
 * Module splits an input volume into a sequence of slices.
 */
class CVolumeSplit : public mds::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CVolumeSplit);

public:
    //! Default constructor.
    CVolumeSplit(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CVolumeSplit();

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
    //! Module command line arguments.
    mds::img::EPlane m_ePlane;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeSplit::tSmartPtr     CVolumeSplitPtr;


#endif // MDS_VOLUMESPLIT_H

