//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/02/12                          \n
 *
 * $Id: mdsSliceHistogram.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * Description:
 * - Shows histogram of an input slice.
 */

#ifndef MDS_SLICEHISTOGRAM_H
#define MDS_SLICEHISTOGRAM_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module prints histogram of the input slice.
 */
class CSliceHistogram : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceHistogram);

public:
    //! Default constructor
    CSliceHistogram(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceHistogram();

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
    //! Command line arguments
    int m_iBins;
    bool m_bEntropy;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceHistogram::tSmartPtr  CSliceHistogramPtr;


#endif // MDS_SLICEHISTOGRAM_H

