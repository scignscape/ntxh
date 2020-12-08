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
 * Copyright (c) 2003-2009 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/12/19                       
 *
 * File description:
 * - Affine image transformation.
 */

#ifndef VPL_SliceAffineTransform_H
#define VPL_SliceAffineTransform_H

#include <VPL/Module/Module.h>


//==============================================================================
/*!
 * Module provides geometric transformations of an input image.
 */
class CSliceAffineTransform : public vpl::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    VPL_SHAREDPTR(CSliceAffineTransform);

public:
    //! Default constructor
    CSliceAffineTransform(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceAffineTransform();

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
    double m_dSX, m_dSY, m_dTX, m_dTY;
    bool m_bResize;
    int m_iMarginValue, m_iAlpha;
    std::string m_ssInterpolatorName;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceAffineTransform::tSmartPtr  CSliceAffineTransformPtr;


#endif // VPL_SliceAffineTransform_H

