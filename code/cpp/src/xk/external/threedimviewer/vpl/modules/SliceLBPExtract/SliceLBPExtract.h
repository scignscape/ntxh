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
 * - Extracts LBP codes from an image.
 */

#ifndef VPL_SliceLBPExtract_H
#define VPL_SliceLBPExtract_H

#include <VPL/Base/Setup.h>
#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Extracts LBP codes from an input slice.
 */
class CSliceLBPExtract : public vpl::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CSliceLBPExtract);

public:
    //! Default constructor.
    CSliceLBPExtract(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CSliceLBPExtract();

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
    std::string m_ssMapping;
    int m_X, m_Y, m_Width, m_Height, m_NumOfSamples;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceLBPExtract::tSmartPtr CSliceLBPExtractPtr;


#endif // VPL_SliceLBPExtract_H

