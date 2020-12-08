//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/02/10                          \n
 *
 * $Id: mdsVolumeHistogram.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Volume histogram computation and equalization.
 */

#ifndef MDS_VOLUMEHISTOGRAM_H
#define MDS_VOLUMEHISTOGRAM_H

#include "mdsHistogram.h"
#include "mdsVolume.h"


namespace mds
{
namespace img
{

//==============================================================================
/*
 * Basic template instances and type definitions.
 */

//! Histogram of the grayscale volume, 8-bits per pixel
typedef CFullHistogram<CVolume8>        CVolume8Histogram;

//! Histogram of the grayscale volume, 16-bits per pixel
typedef CFullHistogram<CVolume16>       CVolume16Histogram;

//! Histogram of the density volume
typedef CFullHistogram<CDVolume>        CDVolumeHistogram;

//! Histogram of the float volume
typedef CHistogram<CFVolume>            CFVolumeHistogram;


} // namespace img
} // namespace mds

#endif // MDS_VOLUMEHISTOGRAM_H

