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
 * Copyright (c) 2003-2007 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/04/17                       
 *
 * Description:
 * - Histogram equalization.
 */

#ifndef VPL_SLICEHISTEQUALIZATION_H
#define VPL_SLICEHISTEQUALIZATION_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module equalizes histogram of input slice.
 */
class CSliceHistEqualization : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSliceHistEqualization);

public:
    //! Default constructor
    CSliceHistEqualization(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceHistEqualization();

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
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceHistEqualization::tSmartPtr  CSliceHistEqualizationPtr;


#endif // VPL_SLICEHISTEQUALIZATION_H

