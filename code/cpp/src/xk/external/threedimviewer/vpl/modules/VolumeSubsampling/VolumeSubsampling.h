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
 * Copyright (c) 2003-2008 by PGMed@FIT      
 *
 * Author:  Radek Barton, ibarton@fit.vutbr.cz  \n
 * Date:    2008/10/27                       
 *
 * File description:
 * - Volume subsampling using different algorithms.
 */

#ifndef VPL_VOLUMESUBSAMPLING_H
#define VPL_VOLUMESUBSAMPLING_H

#include <VPL/Base/Setup.h>
#include <VPL/Module/Module.h>

//==============================================================================
/*!
 * Module used for a volume subsampling.
 */
class CVolumeSubsampling : public vpl::mod::CModule
{
  public:
    //! Type of the volume subsampling algorithm.
    enum ESubsamplingAlogorithm
    {
      ALG_NEAREST = 1,
      ALG_AVERAGE
    };

  public:
    //! Declare smart pointer to module.
    VPL_SHAREDPTR(CVolumeSubsampling);

  public:
    //! Default constructor.
    CVolumeSubsampling(const std::string & description);

    //! Virtual destructor.
    virtual ~CVolumeSubsampling();

  protected:
    //! Virtual method called on startup.
    virtual bool startup();

    //! Virtual method called by the processing thread.
    virtual bool main();

    //! Called on console shutdown.
    virtual void shutdown();

    //! Called on writing a usage statement.
    virtual void writeExtendedUsage(std::ostream& Stream);

  protected:
    //! Module command line arguments values.
    unsigned int levels;
    std::string  algorithm;
};

//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeSubsampling::tSmartPtr CVolumeSubsamplingPtr;

#endif // VPL_VOLUMESUBSAMPLING_H
