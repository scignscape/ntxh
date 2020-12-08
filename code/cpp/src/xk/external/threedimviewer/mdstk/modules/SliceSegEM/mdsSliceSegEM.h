//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/11/02                          \n
 *
 * $Id: mdsSliceSegEM.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * Description:
 * - Image segmentation based on EM algorithm.
 */

#ifndef MDS_SLICESEGEM_H
#define MDS_SLICESEGEM_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module provides pixel-based GMM+EM segmentation.
 */
class CSliceSegEM : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceSegEM);

public:
    //! Default constructor
    CSliceSegEM(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceSegEM();

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
    int m_iClusters;
    double m_dMinSigma, m_dMinAddChange;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceSegEM::tSmartPtr  CSliceSegEMPtr;


#endif // MDS_SLICESEGEM_H

