//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/10                          \n
 *
 * $Id: mdsVolumeInfo.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * File description:
 * - Shows information on input volume.
 */

#ifndef MDS_VOLUMEINFO_H
#define MDS_VOLUMEINFO_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module prints several information on input volume data.
 */
class CVolumeInfo : public mds::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CVolumeInfo);

public:
    //! Default constructor.
    CVolumeInfo(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CVolumeInfo();

protected:
    //! Virtual method called on startup.
    virtual bool startup();

    //! Virtual method called by the processing thread.
    virtual bool main();

    //! Called on console shutdown.
    virtual void shutdown();

    //! Called on writing a usage statement.
    virtual void writeExtendedUsage(std::ostream& Stream);
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeInfo::tSmartPtr  CVolumeInfoPtr;


#endif // MDS_VOLUMEINFO_H

