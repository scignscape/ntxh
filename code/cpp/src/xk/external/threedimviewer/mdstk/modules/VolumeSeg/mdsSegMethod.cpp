//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * File:    mdsSegMethod.cpp                    \n
 * Section: mVolumeSeg                          \n
 * Date:    2005/01/25                          \n
 *
 * $Id: mdsSegMethod.cpp 2102 2012-02-17 09:12:21Z spanel $
 *
 * File description:
 * - Sample implementation of a volume segmentation method.
 */

#include "mdsSegMethod.h"


namespace mds
{
namespace volseg
{

//==============================================================================
/*
 * Implementation of the mds::CSegMethod.
 */

// Segmentation method initialization
bool CSegMethod::init()
{
    return true;
}


// Image segmentation method
bool CSegMethod::operator()(const CSegMethod::tVolume& MDS_UNUSED(SrcVolume),
                            CSegMethod::tVolume& MDS_UNUSED(DstVolume)
                            )
{
    // Segmentation ...
    
    return true;
}


} // namespace volseg
} // namespace mds

