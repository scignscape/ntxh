//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by PGMed@FIT         \n
 *
 * Author:  Radek Barton, ibarton@fit.vutbr.cz  \n
 * File:    mdsVolumeSubsampling.h              \n
 * Section: mVolumeSubsampling                  \n
 * Date:    2008/10/27                          \n
 *
 * $Id: mdsVolumeSubsampling.h 1455 2009-04-22 09:26:33Z spanel $
 *
 * File description:
 * - Volume subsampling using different algorithms.
 */

#ifndef MDS_VOLUMESUBSAMPLING_H
#define MDS_VOLUMESUBSAMPLING_H

#include <MDSTk/Base/mdsSetup.h>
#include <MDSTk/Module/mdsModule.h>

//==============================================================================
/*!
 * Module used for a volume subsampling.
 */
class CVolumeSubsampling : public mds::mod::CModule
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
    MDS_SHAREDPTR(CVolumeSubsampling);

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

#endif // MDS_VOLUMESUBSAMPLING_H
