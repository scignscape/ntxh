//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)       \n
 * Copyright (c) 2003-2007 by Michal Spanel        \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz     \n
 * Date:    2007/07/03                             \n
 *
 * $Id: mdsVolumeLandmarkDetector.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * Description:
 * - Volume landmark ("3D corner") detection algorithms.
 */

#ifndef MDS_DENSITYVOLUMELANDMARKDETECTOR_H
#define MDS_DENSITYVOLUMELANDMARKDETECTOR_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module provides volume landmark ("3D corner") detection.
 */
class CVolumeLandmarkDetector : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CVolumeLandmarkDetector);

public:
    //! Default constructor
    CVolumeLandmarkDetector(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CVolumeLandmarkDetector();

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
    //! Value of the corner detector type argument.
    std::string m_ssDetectorName;

    //! Type specific arguments.
    int m_iSize;
    double m_dW, m_dEdge, m_dT;
    bool m_bDraw, m_bCornerness;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeLandmarkDetector::tSmartPtr   CVolumeLandmarkDetectorPtr;


#endif // MDS_DENSITYVOLUMELANDMARKDETECTOR_H

