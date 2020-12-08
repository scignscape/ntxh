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
 * Copyright (c) 2003-2010 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/09/02                       
 *
 * File description:
 * - Blending of two slices into one.
 */

#ifndef VPL_SliceBlending_H
#define VPL_SliceBlending_H


#include <VPL/Module/Module.h>

//==============================================================================
/*!
 * Module blends two slices.
 */
class CSliceBlending : public vpl::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CSliceBlending);

public:
    //! Default constructor.
    CSliceBlending(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CSliceBlending();

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
    double m_dAlpha;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceBlending::tSmartPtr  CSliceBlendingPtr;


#endif // VPL_SliceBlending_H

