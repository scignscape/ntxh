//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * File:    mdsSegMethod.cpp                    \n
 * Section: mSliceSeg                           \n
 * Date:    2004/03/01                          \n
 *
 * $Id: mdsSegMethod.cpp 2100 2012-02-17 07:36:55Z spanel $
 *
 * File description:
 * - Sample implementation of an image segmentation method.
 */

#include "mdsSegMethod.h"


namespace mds
{
namespace imseg
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
bool CSegMethod::operator()(const CSegMethod::tImage& MDS_UNUSED(SrcImage),
                            CSegMethod::tImage& MDS_UNUSED(DstImage)
                            )
{
    // Segmentation ...

    return true;
}


} // namespace imseg
} // namespace mds

