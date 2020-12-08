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
 * Authors: Jiri Zahradka, xzahra14@stud.fit.vutbr.cz
 *          Michal Spanel, spanel@fit.vutbr.cz       
 * Date:    2008/01/06                               
 *
 * File description:
 * - Image segmentation using the Watershed Transform and subsequent
 *   region merging.
 */

#ifndef VPL_SliceSegWatersheds_H
#define VPL_SliceSegWatersheds_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module provides image segmentation based on Watershed transform.
 */
class CSliceSegWatersheds : public vpl::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CSliceSegWatersheds);

public:
    //! Default constructor.
    CSliceSegWatersheds(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CSliceSegWatersheds();

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
    bool m_bWatershedsOnly, m_bMerge;
    double m_dSimThreshold, m_dSimRatio;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceSegWatersheds::tSmartPtr    CSliceSegWatershedsPtr;


#endif // VPL_SliceSegWatersheds_H

