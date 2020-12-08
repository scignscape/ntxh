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
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/22                       
 *
 * File description:
 * - Extends a given pixel value interval to the range 0..MAX.
 */

#ifndef VPL_SLICERANGE_H
#define VPL_SLICERANGE_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module that extends a given interval of pixel values to the range 0..MAX.
 */
class CSliceRange : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSliceRange);

public:
    //! Default constructor
    CSliceRange(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceRange();

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
    int m_iMin, m_iMax, m_iMAX;
    bool m_bAuto;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceRange::tSmartPtr  CSliceRangePtr;


#endif // VPL_SLICERANGE_H

