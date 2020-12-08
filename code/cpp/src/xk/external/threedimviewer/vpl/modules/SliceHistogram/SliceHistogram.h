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
 * Date:    2005/02/12                       
 *
 * Description:
 * - Shows histogram of an input slice.
 */

#ifndef VPL_SLICEHISTOGRAM_H
#define VPL_SLICEHISTOGRAM_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module prints histogram of the input slice.
 */
class CSliceHistogram : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSliceHistogram);

public:
    //! Default constructor
    CSliceHistogram(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceHistogram();

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
    int m_iBins;
    bool m_bEntropy;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceHistogram::tSmartPtr  CSliceHistogramPtr;


#endif // VPL_SLICEHISTOGRAM_H

