//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)       \n
 * Copyright (c) 2003-2007 by PGMed@FIT            \n
 *
 * Author:  Petr Hyna, xhynap00@stud.fit.vutbr.cz  \n
 *          (modified by Michal Spanel)            \n
 * Date:    2007/04/12                             \n
 *
 * $Id: mdsSliceCornerDetector.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * Description:
 * - Image corner detection algorithms.
 */

#ifndef MDS_SLICECORNERDETECTOR_H
#define MDS_SLICECORNERDETECTOR_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module provides image corner detection.
 */
class CSliceCornerDetector : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceCornerDetector);

public:
    //! Default constructor
    CSliceCornerDetector(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceCornerDetector();

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
    //! Value of the Corner detector type argument.
    std::string m_ssDetectorName;

    //! Type specific arguments.
    double m_dSigma;
    double m_dK, m_dT, m_dW;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceCornerDetector::tSmartPtr   CSliceCornerDetectorPtr;


#endif // MDS_SLICECORNERDETECTOR_H

