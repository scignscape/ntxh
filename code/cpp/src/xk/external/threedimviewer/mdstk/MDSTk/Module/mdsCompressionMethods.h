//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/28                          \n
 *
 * $Id: mdsCompressionMethods.h 2091 2012-02-14 11:26:36Z spanel $
 *
 * Description:
 * - Basic channel compression methods.
 */

#ifndef MDS_CompressionMethods_H
#define MDS_CompressionMethods_H

#include <MDSTk/Base/mdsSetup.h>


namespace mds
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
} // namespace mds

#endif // MDS_CompressionMethods_H

