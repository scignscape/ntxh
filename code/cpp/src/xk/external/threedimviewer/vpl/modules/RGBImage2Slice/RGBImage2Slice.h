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
 * Medical Data Segmentation Toolkit (MDSTk)	\n
 * Copyright (c) 2003-2007 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/14                       
 *
 * File description:
 * - Converts input RGB image to medical slice.
 */

#ifndef VPL_RGBIMAGE2SLICE_H
#define VPL_RGBIMAGE2SLICE_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Converts input RGB image to medical slice.
 */
class CRGBImage2Slice : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CRGBImage2Slice);

public:
    //! Default constructor
    CRGBImage2Slice(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CRGBImage2Slice();

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
    //! Module parameters.
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CRGBImage2Slice::tSmartPtr  CRGBImage2SlicePtr;


#endif // VPL_RGBIMAGE2SLICE_H

