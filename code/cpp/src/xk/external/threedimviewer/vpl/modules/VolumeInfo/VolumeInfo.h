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
 * - Shows information on input volume.
 */

#ifndef VPL_VOLUMEINFO_H
#define VPL_VOLUMEINFO_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module prints several information on input volume data.
 */
class CVolumeInfo : public vpl::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CVolumeInfo);

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


#endif // VPL_VOLUMEINFO_H

