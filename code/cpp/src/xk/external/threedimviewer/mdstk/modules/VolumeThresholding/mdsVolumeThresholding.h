//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (C) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/19                          \n
 *
 * $Id: mdsVolumeThresholding.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * File description:
 * - Simple voxel value thresholding.
 */

#ifndef MDS_VOLUMETHRESHOLDING_H
#define MDS_VOLUMETHRESHOLDING_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module providing a simple voxel value thresholding.
 */
class CVolumeThresholding : public mds::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CVolumeThresholding);

public:
    //! Default constructor.
    CVolumeThresholding(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CVolumeThresholding();

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
    //! Value of the method type argument.
    std::string m_ssMethodName;

    //! Module command line arguments values
    int m_iMin, m_iMax, m_iN;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeThresholding::tSmartPtr  CVolumeThresholdingPtr;


#endif // MDS_VOLUMETHRESHOLDING_H

