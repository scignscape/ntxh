//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)          \n
 * Copyright (c) 2003-2009 by Michal Spanel           \n
 *
 * Authors: Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz        \n
 * Date:    2008/01/27                                \n
 *
 * $Id: mdsSliceLBPCompare.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Statistical comparison of two images using histogram of LBP codes.
 */

#ifndef MDS_SliceLBPCompare_H
#define MDS_SliceLBPCompare_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Statistical comparison of two images using histogram of LBP codes.
 */
class CSliceLBPCompare : public mds::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CSliceLBPCompare);

public:
    //! Default constructor.
    CSliceLBPCompare(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CSliceLBPCompare();

protected:
    //! Virtual method called on startup.
    virtual bool startup();

    //! Virtual method called by the processing thread.
    virtual bool main();

    //! Called on console shutdown.
    virtual void shutdown();

    //! Called on writing an usage statement.
    virtual void writeExtendedUsage(std::ostream& Stream);

protected:
    //! Command line arguments.
    std::string m_ssMapping, m_ssMetrics;
    int m_X, m_Y, m_Width, m_Height, m_NumOfSamples;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceLBPCompare::tSmartPtr CSliceLBPComparePtr;


#endif // MDS_SliceLBPCompare_H

