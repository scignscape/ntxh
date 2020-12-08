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
 * Date:    2003/12/22                       
 *
 * File description:
 * - Shows information on input slice.
 */

#ifndef VPL_SLICEINFO_H
#define VPL_SLICEINFO_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module reads an input slice and prints several information on it.
 */
class CSliceInfo : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSliceInfo);

public:
    //! Default constructor
    CSliceInfo(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceInfo();

protected:
    //! Virtual method called on startup
    virtual bool startup();

    //! Virtual method called by the processing thread
    virtual bool main();

    //! Called on console shutdown
    virtual void shutdown();

    //! Called on writing a usage statement
    virtual void writeExtendedUsage(std::ostream& Stream);
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceInfo::tSmartPtr   CSliceInfoPtr;


#endif // VPL_SLICEINFO_H

