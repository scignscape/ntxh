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
 * Date:    2004/08/10                       
 *
 * File description:
 * - Extends a given voxel value interval to the range 0..MAX.
 */

#ifndef VPL_VOLUMERANGE_H
#define VPL_VOLUMERANGE_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module extends a given voxel value interval to the range 0..MAX.
 */
class CVolumeRange : public vpl::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CVolumeRange);

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


#endif // VPL_VOLUMERANGE_H

