//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)	\n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/22                          \n
 *
 * $Id: mdsSliceRange.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Extends a given pixel value interval to the range 0..MAX.
 */

#ifndef MDS_SLICERANGE_H
#define MDS_SLICERANGE_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module that extends a given interval of pixel values to the range 0..MAX.
 */
class CSliceRange : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceRange);

public:
    //! Default constructor
    CSliceRange(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceRange();

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
    //! Module parameters.
    int m_iMin, m_iMax, m_iMAX;
    bool m_bAuto;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceRange::tSmartPtr  CSliceRangePtr;


#endif // MDS_SLICERANGE_H

