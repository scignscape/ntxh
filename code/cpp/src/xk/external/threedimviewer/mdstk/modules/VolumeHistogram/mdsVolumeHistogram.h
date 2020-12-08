//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/02/11                          \n
 *
 * $Id: mdsVolumeHistogram.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * Description:
 * - Shows volume histogram.
 */

#ifndef MDS_VLMHISTOGRAM_H
#define MDS_VLMHISTOGRAM_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module prints histogram of input volume.
 */
class CVolumeHistogram : public mds::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CVolumeHistogram);

public:
    //! Default constructor.
    CVolumeHistogram(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CVolumeHistogram();

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
    //! Module parameters.
    int m_iBins;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeHistogram::tSmartPtr     CVolumeHistogramPtr;


#endif // MDS_VLMHISTOGRAM_H

