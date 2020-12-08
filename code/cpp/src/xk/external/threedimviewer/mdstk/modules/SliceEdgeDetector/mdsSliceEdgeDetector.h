//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/27                          \n
 *
 * $Id: mdsSliceEdgeDetector.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * Description:
 * - Advanced image edge detection algorithms.
 */

#ifndef MDS_SLICEEDGEDETECTOR_H
#define MDS_SLICEEDGEDETECTOR_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module provides image edge detection routines.
 */
class CSliceEdgeDetector : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceEdgeDetector);

public:
    //! Default constructor
    CSliceEdgeDetector(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceEdgeDetector();

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
    //! Value of the edge detector type argument.
    std::string m_ssDetectorName;

    //! Type specific arguments.
    double m_dSigma, m_dT1, m_dT2, m_dT;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceEdgeDetector::tSmartPtr   CSliceEdgeDetectorPtr;


#endif // MDS_SLICEEDGEDETECTOR_H

