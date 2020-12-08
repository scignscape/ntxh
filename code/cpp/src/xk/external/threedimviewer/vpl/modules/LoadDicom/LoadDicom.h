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
 * Date:    2003/12/18                       
 *
 * File description:
 * - Reads DICOM data from an input channel.
 * - Converts it to the image slice.
 */

#ifndef VPL_LOADDICOM_H
#define VPL_LOADDICOM_H

#include <VPL/Module/Module.h>

//==============================================================================
/*!
 * Module loads an image in DICOM format and converts it to the MDSTk image
 * - the vpl::img::CSlice class.
 */
class CLoadDicom : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CLoadDicom);

public:
    //! Default constructor
    CLoadDicom(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CLoadDicom();

protected:
    //! Virtual method called on startup
    virtual bool startup();

    //! Virtual method called by the processing thread
    virtual bool main();

    //! Called on console shutdown
    virtual void shutdown();

    //! Called on writing a usage statement
    virtual void writeExtendedUsage(std::ostream& Stream);
   
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CLoadDicom::tSmartPtr   CLoadDicomPtr;


#endif // VPL_LOADDICOM_H

