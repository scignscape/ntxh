//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/27                          \n
 *
 * $Id: mdsCompressorFactory.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Channel compression tools.
 */

#ifndef MDS_CompressorFactory_H
#define MDS_CompressorFactory_H

#include <MDSTk/Base/mdsFactory.h>

#include "mdsCompressor.h"
#include "mdsRLECompressor.h"
#include "mdsGZipCompressor.h"
#include "mdsDensityCompressor.h"


namespace mds
{
namespace mod
{

//=============================================================================
/*!
 * Channel compressors creation factory.
 */
class CCompressorFactory : public mds::base::CFactory<CChannelCompressor, int>
{
public:
    //! Base class.
    typedef mds::base::CFactory<CChannelCompressor, int> tBase;

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
    MDS_PRIVATE_SINGLETON(CCompressorFactory);

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
} // namespace mds

#endif // MDS_CompressorFactory_H

