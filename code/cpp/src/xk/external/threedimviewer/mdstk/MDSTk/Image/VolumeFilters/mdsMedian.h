//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/01/29                          \n
 *
 * $Id: mdsMedian.h 2106 2012-02-18 21:55:47Z spanel $
 * 
 * Description:
 * - Volume median filter definition.
 */

#ifndef MDS_VF_MEDIAN_H
#define MDS_VF_MEDIAN_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsTypes.h>
#include <MDSTk/Base/mdsData.h>
#include <MDSTk/Math/mdsBase.h>
#include <MDSTk/Module/mdsProgress.h>

#include "../mdsVolumeFilter.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Template providing median volume filtering functions.
 * - Parameter V is a used volume type.
 */
template <class V>
class CVolumeMedianFilter : public CVolumeFilter<V>, public mds::mod::CProgress
{
public:
    //! Volume filter base.
    typedef CVolumeFilter<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;

public:
    //! Constructor that creates a new median filter.
    //! - Parameter 'Size' is a window size and it must be an odd number.
    CVolumeMedianFilter(tSize Size)
        : m_MedianSize(Size)
        , m_Data(Size * Size * Size * ompGetMaxThreads())
    {
        MDS_ASSERT((Size % 2) == 1);
    }

    //! Destructor
    ~CVolumeMedianFilter() {}


    //! Median volume filtering
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    tVoxel getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Sets the windows size
    void setSize(tSize Size)
    {
        MDS_ASSERT((Size % 2) == 1);

        m_MedianSize = Size;
        m_Data.create(Size * Size * Size * ompGetMaxThreads());
    }

protected:
    //! Median filter size
    tSize m_MedianSize;

    //! Internal data buffer
    mds::base::CData<tVoxel> m_Data;
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsMedian.hxx"


} // namespace img
} // namespace mds

#endif // MDS_VF_MEDIAN_H

