//==============================================================================
/* This file comes from MDSTk software and was modified for
 * 
 * VPL - Voxel Processing Library
 * Changes are Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 * 
 * The original MDSTk legal notice can be found below.
 * 
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/19                       
 *
 * File description:
 * - Cuts a specified interval of voxels.
 */

#ifndef VPL_VOLUMECUT_H
#define VPL_VOLUMECUT_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module cuts a given interval of voxels.
 */
class CVolumeCut : public vpl::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CVolumeCut);

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
    vpl::tSize m_iMin, m_iMax;
	vpl::tSize m_iMinX, m_iMaxX, m_iMinY, m_iMaxY, m_iMinZ, m_iMaxZ;
	vpl::tSize m_iBorder;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeCut::tSmartPtr   CVolumeCutPtr;


#endif // VPL_VOLUMECUT_H

