//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)     \n
 * Copyright (c) 2003-2010 by Michal Spanel      \n
 *
 * Author:   Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:     2010/06/25                          \n
 *
 * File description:
 * - Sample volume segmentation module.
 */

#ifndef MDS_VolumeSegFCM_H
#define MDS_VolumeSegFCM_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module provides voxel-based fuzzy C-means segmentation method.
 */
class CVolumeSegFCM : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CVolumeSegFCM);

public:
    //! Default constructor
    CVolumeSegFCM(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CVolumeSegFCM();

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
    int m_iClusters;
    double m_dWeight;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeSegFCM::tSmartPtr   CVolumeSegFCMPtr;


#endif // MDS_VolumeSegFCM_H

