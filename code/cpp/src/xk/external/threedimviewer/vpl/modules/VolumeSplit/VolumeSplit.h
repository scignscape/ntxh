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
 * Date:    2004/07/30                       
 *
 * File description:
 * - Splits an input volume into several slices.
 */

#ifndef VPL_VOLUMESPLIT_H
#define VPL_VOLUMESPLIT_H

#include <VPL/Module/Module.h>
#include <VPL/Image/Slice.h>


//==============================================================================
/*!
 * Module splits an input volume into a sequence of slices.
 */
class CVolumeSplit : public vpl::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CVolumeSplit);

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
    vpl::img::EPlane m_ePlane;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeSplit::tSmartPtr     CVolumeSplitPtr;


#endif // VPL_VOLUMESPLIT_H

