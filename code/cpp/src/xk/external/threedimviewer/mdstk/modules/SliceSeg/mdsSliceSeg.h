//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/03/01                          \n
 *
 * $Id: mdsSliceSeg.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Sample slice segmentation module.
 */

#ifndef MDS_SLICESEG_H
#define MDS_SLICESEG_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Sample module providing image segmentation method.
 */
class CSliceSeg : public mds::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CSliceSeg);

public:
    //! Default constructor.
    CSliceSeg(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CSliceSeg();

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
    //! Sample module command line argument.
    int m_iA;

    //! Sample module command line argument.
    bool m_bB;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceSeg::tSmartPtr    CSliceSegPtr;


#endif // MDS_SLICESEG_H

