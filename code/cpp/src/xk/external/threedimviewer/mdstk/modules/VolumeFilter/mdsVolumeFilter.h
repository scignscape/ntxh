//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/01/26                          \n
 *
 * $Id: mdsVolumeFilter.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * Description:
 * - Several volume filtering functions.
 */

#ifndef MDS_VLMFILTER_H
#define MDS_VLMFILTER_H

#include <MDSTk/Module/mdsModule.h>
#include <MDSTk/Image/mdsDensityVolume.h>
#include <MDSTk/Image/mdsVolumeFiltering.h>


//==============================================================================
/*!
 * Module providing several volume filtering functions.
 */
class CVolumeFilter : public mds::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CVolumeFilter);

public:
    //! Default constructor.
    CVolumeFilter(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CVolumeFilter();

protected:
    //! Virtual method called on startup.
    virtual bool startup();

    //! Virtual method called by the processing thread.
    virtual bool main();

    //! Called on console shutdown.
    virtual void shutdown();

    //! Called on writing a usage statement.
    virtual void writeExtendedUsage(std::ostream& Stream);

protected:
    //! Value of the filter type argument.
    std::string m_ssFilterName;

    //! Filter response normalization function.
    mds::img::CUserFunc<mds::img::tDensityPixel>::tNormFunc m_NormFunc;

    //! Type specific arguments.
    int m_iSize;
    double m_dSigma;
    double m_dKappa;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeFilter::tSmartPtr    CVolumeFilterPtr;


#endif // MDS_VLMFILTER_H

