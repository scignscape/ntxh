//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/04/17                          \n
 *
 * $Id: mdsVolumeHistEqualization.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * Description:
 * - Volume histogram equalization.
 */

#ifndef MDS_VLMHISTEQUALIZATION_H
#define MDS_VLMHISTEQUALIZATION_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module equalizes histogram of input volume.
 */
class CVolumeHistEqualization : public mds::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CVolumeHistEqualization);

public:
    //! Default constructor.
    CVolumeHistEqualization(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CVolumeHistEqualization();

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
    //! Module parameters.
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeHistEqualization::tSmartPtr     CVolumeHistEqualizationPtr;


#endif // MDS_VLMHISTEQUALIZATION_H

