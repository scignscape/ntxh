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
 * Date:    2004/03/30                          \n
 *
 * File description:
 * - Converts an input slice to PNG image format.
 */

#ifndef VPL_SAVEPNG_H
#define VPL_SAVEPNG_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module converts an input slice to the PNG image format.
 */
class CSavePNG : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSavePNG);

public:
    //! Default constructor
    CSavePNG(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSavePNG();

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
typedef CSavePNG::tSmartPtr     CSavePNGPtr;


#endif // VPL_SAVEPNG_H

