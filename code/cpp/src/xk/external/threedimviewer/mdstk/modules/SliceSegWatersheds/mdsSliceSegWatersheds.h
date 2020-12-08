//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)            \n
 * Copyright (c) 2003-2009 by Michal Spanel             \n
 *
 * Authors: Jiri Zahradka, xzahra14@stud.fit.vutbr.cz   \n
 *          Michal Spanel, spanel@fit.vutbr.cz          \n
 * Date:    2008/01/06                                  \n
 *
 * $Id: mdsSliceSegWatersheds.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Image segmentation using the Watershed Transform and subsequent
 *   region merging.
 */

#ifndef MDS_SliceSegWatersheds_H
#define MDS_SliceSegWatersheds_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module provides image segmentation based on Watershed transform.
 */
class CSliceSegWatersheds : public mds::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CSliceSegWatersheds);

public:
    //! Default constructor.
    CSliceSegWatersheds(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CSliceSegWatersheds();

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
    bool m_bWatershedsOnly, m_bMerge;
    double m_dSimThreshold, m_dSimRatio;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceSegWatersheds::tSmartPtr    CSliceSegWatershedsPtr;


#endif // MDS_SliceSegWatersheds_H

