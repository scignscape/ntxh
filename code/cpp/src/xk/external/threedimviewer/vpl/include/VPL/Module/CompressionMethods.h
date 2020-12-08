//==============================================================================
/* This file comes from MDSTk software and was modified for
 * 
 * VPL - Voxel Processing Library
 * Changes are Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 * 
 * The original MDSTk legal notice can be found below.
 * 
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2009 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/28                       
 *
 * Description:
 * - Basic channel compression methods.
 */

#ifndef VPL_CompressionMethods_H
#define VPL_CompressionMethods_H

#include <VPL/Base/Setup.h>


namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Compression type.
 */

//! Available basic channel compression methods.
enum EChannelCompression
{
    //! Raw/uncompressed data.
    CC_RAW      = 0,

    //! 8-bit RLE compression.
    CC_RLE8     = 1,

    //! 16-bit RLE compression.
    CC_RLE16    = 2,

    //! gzip (zlib) compression.
    CC_GZIP     = 3,

    //! bzip2 compression.
//    CC_BZIP2    = 4,

    //! Special compression of density data.
    CC_DENSITY  = 8
};


} // namespace mod
} // namespace vpl

#endif // VPL_CompressionMethods_H

