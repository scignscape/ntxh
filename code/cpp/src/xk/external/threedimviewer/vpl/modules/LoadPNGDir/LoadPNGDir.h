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
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/11/01                          \n
 *
 * File description:
 * - Loads all PNG images from a given directory.
 * - Converts them to the slice format.
 */

#ifndef VPL_LoadPNGDir_H
#define VPL_LoadPNGDir_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module loads JPEG images from a specified directory and converts them
 * to the sequence of MDSTk images.
 */
class CLoadPNGDir : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CLoadPNGDir);

public:
    //! Default constructor
    CLoadPNGDir(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CLoadPNGDir();

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
    //! Arguments...
    std::string m_ssFormat, m_ssDir, m_ssFileMask;

    //! Loads all images from a directory.
    //! - Returns the number of successfully loaded images.
    template <class ImageType>
    int loadImagesFromDir(ImageType& AuxImage);
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CLoadPNGDir::tSmartPtr    CLoadPNGDirPtr;


#endif // VPL_LoadPNGDir_H

