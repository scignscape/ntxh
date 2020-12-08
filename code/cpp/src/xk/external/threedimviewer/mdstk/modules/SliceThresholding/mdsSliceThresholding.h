//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2004 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/19                          \n
 *
 * $Id: mdsSliceThresholding.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Simple pixel value thresholding.
 */

#ifndef MDS_SLICETHRESHOLDING_H
#define MDS_SLICETHRESHOLDING_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module for a simple pixel values thresholding.
 */
class CSliceThresholding : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceThresholding);

public:
    //! Default constructor
    CSliceThresholding(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceThresholding();

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
    //! Value of the method type argument.
    std::string m_ssMethodName;

    //! Module command line arguments values
    int m_iMin, m_iMax, m_iN;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceThresholding::tSmartPtr   CSliceThresholdingPtr;


#endif // MDS_SLICETHRESHOLDING_H

