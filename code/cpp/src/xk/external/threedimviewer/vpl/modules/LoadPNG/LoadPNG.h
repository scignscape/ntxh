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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/03/29                          \n
 *
 * File description:
 * - Reads PNG image from an input channel.
 * - Converts it to the slice format.
 */

#ifndef VPL_LOADPNG_H
#define VPL_LOADPNG_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module loads PNG image and converts it to the MDSTk format.
 */
class CLoadPNG : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CLoadPNG);

public:
    //! Default constructor
    CLoadPNG(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CLoadPNG();

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
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CLoadPNG::tSmartPtr     CLoadPNGPtr;


#endif // VPL_LOADPNG_H

