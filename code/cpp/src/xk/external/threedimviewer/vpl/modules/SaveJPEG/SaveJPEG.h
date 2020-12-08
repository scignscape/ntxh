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
 * Date:    2004/03/31                       
 *
 * File description:
 * - Converts an input slice to JPEG image format.
 */

#ifndef VPL_SAVEJPEG_H
#define VPL_SAVEJPEG_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module converts an input slice to JPEG image.
 */
class CSaveJPEG : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSaveJPEG);

public:
    //! Default constructor
    CSaveJPEG(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSaveJPEG();

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
    //! Value of the image format argument.
    std::string m_ssFormat;
    int m_iQuality;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSaveJPEG::tSmartPtr    CSaveJPEGPtr;


#endif // VPL_SAVEJPEG_H

