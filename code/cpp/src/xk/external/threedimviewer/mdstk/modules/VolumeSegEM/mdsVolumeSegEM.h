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

#ifndef MDS_VolumeSegEM_H
#define MDS_VolumeSegEM_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module provides voxel-based segmentation based on GMM+EM algorithm.
 */
class CVolumeSegEM : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CVolumeSegEM);

public:
    //! Default constructor
    CVolumeSegEM(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CVolumeSegEM();

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
    //! Sample command line argument
    int m_iClusters;
    double m_dMinAddChange;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeSegEM::tSmartPtr   CVolumeSegEMPtr;


#endif // MDS_VolumeSegEM_H

