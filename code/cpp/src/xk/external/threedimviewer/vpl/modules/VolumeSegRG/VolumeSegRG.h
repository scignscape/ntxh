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
 * Author:   Michal Spanel, spanel@fit.vutbr.cz        
 *           Martin Skotnica, xskotn01@stud.fit.vutbr.cz  \n
 * Date:     2005/01/25                                
 *
 * File description:
 * - Simple region growing volume segmentation.
 */

#ifndef VPL_VOLUMESEGRG_H
#define VPL_VOLUMESEGRG_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module providing simple region growing slice segmentation.
 */
class CVolumeSegRG : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CVolumeSegRG);

public:
    //! Default constructor
    CVolumeSegRG(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CVolumeSegRG();

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
typedef CVolumeSegRG::tSmartPtr     CVolumeSegRGPtr;


#endif // VPL_VOLUMESEGRG_H

