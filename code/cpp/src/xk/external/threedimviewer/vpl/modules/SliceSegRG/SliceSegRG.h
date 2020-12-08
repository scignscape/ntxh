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
 *          Martin Skotnica, xskotn01@stud.fit.vutbr.cz  \n
 * Date:    2004/03/01                                
 *
 * Description:
 * - Simple region growing slice segmentation.
 */

#ifndef VPL_SLICESEGRG_H
#define VPL_SLICESEGRG_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module providing simple region growing slice segmentation.
 */
class CSliceSegRG : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSliceSegRG);

public:
    //! Default constructor
    CSliceSegRG(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceSegRG();

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
    int m_iThreshold;

    //! Command line argument
    double m_dWeightDiff;

    //! Command line argument
    double m_dWeightEdge;

    //! Command line argument
    bool m_bMerge;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceSegRG::tSmartPtr  CSliceSegRGPtr;


#endif // VPL_SLICESEGRG_H

