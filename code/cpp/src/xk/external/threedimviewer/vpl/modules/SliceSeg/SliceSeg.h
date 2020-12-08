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
 * Date:    2004/03/01                       
 *
 * File description:
 * - Sample slice segmentation module.
 */

#ifndef VPL_SLICESEG_H
#define VPL_SLICESEG_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Sample module providing image segmentation method.
 */
class CSliceSeg : public vpl::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CSliceSeg);

public:
    //! Default constructor.
    CSliceSeg(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CSliceSeg();

protected:
    //! Virtual method called on startup.
    virtual bool startup();

    //! Virtual method called by the processing thread.
    virtual bool main();

    //! Called on console shutdown.
    virtual void shutdown();

    //! Called on writing an usage statement.
    virtual void writeExtendedUsage(std::ostream& Stream);

protected:
    //! Sample module command line argument.
    int m_iA;

    //! Sample module command line argument.
    bool m_bB;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceSeg::tSmartPtr    CSliceSegPtr;


#endif // VPL_SLICESEG_H

