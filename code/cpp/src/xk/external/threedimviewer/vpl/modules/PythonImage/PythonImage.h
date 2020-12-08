//==============================================================================
/* This file is part of
*
* VPL - Voxel Processing Library
* Copyright 2017 3Dim Laboratory s.r.o.
* All rights reserved.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#ifndef VPL_PYTHONIMAGE_H
#define VPL_PYTHONIMAGE_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
* Module loads PNG image and converts it to the MDSTk format.
*/
class CPythonImage : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CPythonImage);

public:
    //! Default constructor
    CPythonImage(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CPythonImage();

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
    std::string m_ssSource;
};


//==============================================================================
/*!
* Smart pointer to console application.
*/
typedef CPythonImage::tSmartPtr     CPythonImagePtr;


#endif // VPL_PYTHONIMAGE_H

