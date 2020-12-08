//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/08                          \n
 *
 * $Id: mdsSliceOpticalFlow.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * Description:
 * - Optical flow estimation and visualization module.
 */

#ifndef MDS_SLICEOPTICALFLOW_H
#define MDS_SLICEOPTICALFLOW_H

// MDSTk
#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Optical flow estimation and visualization module.
 */
class CSliceOpticalFlow : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceOpticalFlow);

public:
    //! Default constructor
    CSliceOpticalFlow(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceOpticalFlow();

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
    //! Command line argument
    int m_iGrid;

    //! Command line argument
    int m_iLevels;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceOpticalFlow::tSmartPtr    CSliceOpticalFlowPtr;


#endif // MDS_SLICEOPTICALFLOW_H

