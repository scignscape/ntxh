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
 * Copyright (c) 2003-2009 by Michal Spanel        
 *
 * Authors: Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz     
 * Date:    2008/01/27                             
 *
 * File description:
 * - Statistical comparison of two images using histogram of LBP codes.
 */

#ifndef VPL_SliceLBPCompare_H
#define VPL_SliceLBPCompare_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Statistical comparison of two images using histogram of LBP codes.
 */
class CSliceLBPCompare : public vpl::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CSliceLBPCompare);

public:
    //! Default constructor.
    CSliceLBPCompare(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CSliceLBPCompare();

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
    //! Command line arguments.
    std::string m_ssMapping, m_ssMetrics;
    int m_X, m_Y, m_Width, m_Height, m_NumOfSamples;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceLBPCompare::tSmartPtr CSliceLBPComparePtr;


#endif // VPL_SliceLBPCompare_H

