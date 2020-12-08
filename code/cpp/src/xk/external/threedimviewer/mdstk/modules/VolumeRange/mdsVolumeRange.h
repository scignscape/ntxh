//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/10                          \n
 *
 * $Id: mdsVolumeRange.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * File description:
 * - Extends a given voxel value interval to the range 0..MAX.
 */

#ifndef MDS_VOLUMERANGE_H
#define MDS_VOLUMERANGE_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module extends a given voxel value interval to the range 0..MAX.
 */
class CVolumeRange : public mds::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CVolumeRange);

public:
    //! Default constructor.
    CVolumeRange(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CVolumeRange();

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
    bool m_bAuto, m_bCopy;
    int m_iMin, m_iMax, m_iMAX;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeRange::tSmartPtr     CVolumeRangePtr;


#endif // MDS_VOLUMERANGE_H

