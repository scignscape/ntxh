//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/03                          \n
 *
 * $Id: mdsSliceFilter.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * Description:
 * - Several image filtering functions.
 */

#ifndef MDS_SLICEFILTER_H
#define MDS_SLICEFILTER_H

#include <MDSTk/Module/mdsModule.h>
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsImageFiltering.h>


//==============================================================================
/*!
 * Module provides several image filtering functions.
 */
class CSliceFilter : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceFilter);

public:
    //! Default constructor
    CSliceFilter(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceFilter();

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
    //! Value of the filter type argument.
    std::string m_ssFilterName;

    //! Filter response normalization function.
    mds::img::CUserFunc<mds::img::tDensityPixel>::tNormFunc m_NormFunc;

    //! Type specific arguments.
    double m_dSigma, m_dSigma2;
    int m_iSize;
    double m_dKappa;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceFilter::tSmartPtr     CSliceFilterPtr;


#endif // MDS_SLICEFILTER_H

