//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/10/14                          \n
 *
 * $Id: mdsSliceSegFCM.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * Description:
 * - Fuzzy C-means image segmentation.
 */

#ifndef MDS_SLICESEGFCM_H
#define MDS_SLICESEGFCM_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module provides pixel-based fuzzy C-means image segmentation.
 */
class CSliceSegFCM : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceSegFCM);

public:
    //! Default constructor
    CSliceSegFCM(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceSegFCM();

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
    double m_dWeight;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceSegFCM::tSmartPtr     CSliceSegFCMPtr;


#endif // MDS_SLICESEGFCM_H

