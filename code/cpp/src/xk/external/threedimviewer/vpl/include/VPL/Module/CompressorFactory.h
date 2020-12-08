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
 * Date:    2009/03/27                       
 *
 * Description:
 * - Channel compression tools.
 */

#ifndef VPL_CompressorFactory_H
#define VPL_CompressorFactory_H

#include <VPL/Base/Factory.h>

#include "Compressor.h"
#include "RLECompressor.h"
#include "GZipCompressor.h"
#include "DensityCompressor.h"


namespace vpl
{
namespace mod
{

//=============================================================================
/*!
 * Channel compressors creation factory.
 */
class CCompressorFactory : public vpl::base::CFactory<CChannelCompressor, int>
{
public:
    //! Base class.
    typedef vpl::base::CFactory<CChannelCompressor, int> tBase;

    //! Destructor.
    ~CCompressorFactory() {}

protected:
    //! Private constructor.
    CCompressorFactory()
    {
        // Register predefined creation functions.
        registerObject(CC_RAW, createRaw);
        registerObject(CC_RLE8, createRLE8);
        registerObject(CC_RLE16, createRLE16);
        registerObject(CC_GZIP, createGZip);
        registerObject(CC_DENSITY, createDensity);
    }

    //! Allow factory instantiation using singleton holder.
    VPL_PRIVATE_SINGLETON(CCompressorFactory);

private:
    // Creates one of the predefined channel compressors.
    static CChannelCompressor *createRaw()
    {
        return new CRawCompressor();
    }
    static CChannelCompressor *createRLE8()
    {
        return new CRLE8Compressor();
    }
    static CChannelCompressor *createRLE16()
    {
        return new CRLE16Compressor();
    }
    static CChannelCompressor *createGZip()
    {
        return new CGZipCompressor();
    }
    static CChannelCompressor *createDensity()
    {
        return new CDensityCompressor();
    }
};


} // namespace mod
} // namespace vpl

#endif // VPL_CompressorFactory_H

