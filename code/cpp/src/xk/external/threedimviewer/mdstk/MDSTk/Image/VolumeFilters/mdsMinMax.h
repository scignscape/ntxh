//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/06/14                          \n
 *
 * $Id: mdsMinMax.h 2065 2012-02-02 23:29:38Z spanel $
 * 
 * Description:
 * - Volume min and max filters.
 */

#ifndef MDS_VF_MINMAX_H
#define MDS_VF_MINMAX_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsTypes.h>
#include <MDSTk/Base/mdsData.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsVolumeFilter.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Template providing min-value volume filtering functions.
 * - Parameter V is a used volume type.
 */
template <class V>
class CVolumeMinFilter : public CVolumeFilter<V>
{
public:
    //! Volume filter base.
    typedef CVolumeFilter<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;

public:
    //! Constructor that creates a new filter.
    //! - Parameter 'Size' is a window size and it must be an odd number.
    CVolumeMinFilter(tSize Size) : m_MinSize(Size)
    {
        MDS_ASSERT((Size % 2) == 1);
    }

    //! Destructor.
    ~CVolumeMinFilter() {}


    //! Min volume filtering.
    //! - Returns false on failure.
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    tVoxel getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Sets the windows size.
    void setSize(tSize Size)
    {
        MDS_ASSERT((Size % 2) == 1);

        m_MinSize = Size;
    }

protected:
    //! Min filter size.
    tSize m_MinSize;
};


//==============================================================================
/*!
 * Template providing max-value volume filtering functions.
 * - Parameter V is a used volume type.
 */
template <class V>
class CVolumeMaxFilter : public CVolumeFilter<V>
{
public:
    //! Volume filter base.
    typedef CVolumeFilter<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;

public:
    //! Constructor that creates a new filter.
    //! - Parameter 'Size' is a window size and it must be an odd number.
    CVolumeMaxFilter(tSize Size) : m_MaxSize(Size)
    {
        MDS_ASSERT((Size % 2) == 1);
    }

    //! Destructor.
    ~CVolumeMaxFilter() {}


    //! Max volume filtering.
    //! - Returns false on failure.
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    tVoxel getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Sets the windows size.
    void setSize(tSize Size)
    {
        MDS_ASSERT((Size % 2) == 1);

        m_MaxSize = Size;
    }

protected:
    //! Max filter size.
    tSize m_MaxSize;
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates.
#include "mdsMinMax.hxx"


} // namespace img
} // namespace mds

#endif // MDS_VF_MINMAX_H

