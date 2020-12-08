//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/04/27                          \n
 *
 * $Id: mdsVolumeEdgeDetector.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * Description:
 * - Advanced volume edge detection algorithms.
 */

#ifndef MDS_DENSITYVOLUMEEDGEDETECTOR_H
#define MDS_DENSITYVOLUMEEDGEDETECTOR_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module provides 3D edge detection routines.
 */
class CVolumeEdgeDetector : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CVolumeEdgeDetector);

public:
    //! Default constructor
    CVolumeEdgeDetector(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CVolumeEdgeDetector();

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

    //! Should borders be detected?
    bool m_bDetectBorder;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeEdgeDetector::tSmartPtr  CVolumeEdgeDetectorPtr;


#endif // MDS_DENSITYVOLUMEEDGEDETECTOR_H

