//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2004 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/19                          \n
 *
 * $Id: mdsSliceSubsampling.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Image subsampling using Gaussian pyramid.
 */

#ifndef MDS_SLICESUBSAMPLING_H
#define MDS_SLICESUBSAMPLING_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module for an image subsampling.
 */
class CSliceSubsampling : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceSubsampling);

public:
    //! Default constructor
    CSliceSubsampling(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceSubsampling();

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
    //! Module command line arguments values
    unsigned int m_uRate, m_uLevels;
    std::string  m_sAlgorithm;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceSubsampling::tSmartPtr    CSliceSubsamplingPtr;


#endif // MDS_SLICESUBSAMPLING_H

