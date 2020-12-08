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
 * Author:  Michal Spanel, spanel@fit.vutbr.cz      
 *          Miroslav Svub, xsvubm00@stud.fit.vutbr.cz  \n
 * Date:    2004/10/24                              
 *
 * File description:
 * - Simple segmentation method based on histogram thresholding.
 */

#ifndef VPL_SLICESEGHT_H
#define VPL_SLICESEGHT_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module provides segmentation method based on histogram thresholding.
 */
class CSliceSegHT : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSliceSegHT);

public:
    //! Default constructor
    CSliceSegHT(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceSegHT();

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
    //! Command line argument
    int m_iThresholds;

    //! Command line argument
    int m_iColumns;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceSegHT::tSmartPtr  CSliceSegHTPtr;


#endif // VPL_SLICESEGHT_H

