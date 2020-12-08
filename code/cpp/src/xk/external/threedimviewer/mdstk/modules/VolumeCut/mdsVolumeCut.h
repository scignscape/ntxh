//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/19                          \n
 *
 * $Id: mdsVolumeCut.h 1729 2010-06-03 05:36:23Z spanel $
 *
 * File description:
 * - Cuts a specified interval of voxels.
 */

#ifndef MDS_VOLUMECUT_H
#define MDS_VOLUMECUT_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module cuts a given interval of voxels.
 */
class CVolumeCut : public mds::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CVolumeCut);

public:
    //! Default constructor.
    CVolumeCut(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CVolumeCut();

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
    int m_iMin, m_iMax;
    int m_iMinX, m_iMaxX, m_iMinY, m_iMaxY, m_iMinZ, m_iMaxZ;
    int m_iBorder;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeCut::tSmartPtr   CVolumeCutPtr;


#endif // MDS_VOLUMECUT_H

