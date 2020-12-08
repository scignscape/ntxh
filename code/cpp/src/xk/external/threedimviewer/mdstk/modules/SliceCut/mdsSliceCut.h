//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/08/19                          \n
 *
 * $Id: mdsSliceCut.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Cuts a specified interval of pixels.
 */

#ifndef MDS_SLICECUT_H
#define MDS_SLICECUT_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module cuts (remains unchanged) a specified interval of pixels.
 */
class CSliceCut : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceCut);

public:
    //! Default constructor
    CSliceCut(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceCut();

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
    //! Module command line parameters values
    int m_iMin, m_iMax;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceCut::tSmartPtr    CSliceCutPtr;


#endif // MDS_SLICECUT_H

