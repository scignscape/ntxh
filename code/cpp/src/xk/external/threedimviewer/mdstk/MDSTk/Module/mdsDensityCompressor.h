//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/04/28                          \n
 *
 * $Id: mdsDensityCompressor.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Density data compression tools.
 */

#ifndef MDS_DensityCompressor_H
#define MDS_DensityCompressor_H

#include "mdsRLECompressor.h"
#include "mdsGZipCompressor.h"
#include "mdsPredictor.h"

// STL
#include <string>


namespace mds
{
namespace mod
{

//==============================================================================
/*!
 * Class providing density data compression.
 */
class MDS_MODULE_EXPORT CDensityCompressor : public CChannelCompressor
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CDensityCompressor);

public:
    //! Constructor.
    CDensityCompressor(CChannel *pChannel = NULL);

    //! Destructor.
    virtual ~CDensityCompressor();

    // Virtual methods.
    virtual void setChannel(CChannel *pChannel);
    virtual int read(char *pcData, int iLength);
    virtual bool write(const char *pcData, int iLength);

protected:
    //! RLE compression.
    CRLE8Compressor m_Compressor;
//    CGZipCompressor m_Compressor;

    //! Density data predictor.
//    CByteTranspose<mds::img::tDensityPixel> m_Predictor;
    CDensityPredictor m_Predictor;
};


//==============================================================================
/*!
 * Smart pointer to density data compressor.
 */
typedef CDensityCompressor::tSmartPtr   CDensityCompressorPtr;


} // namespace mod
} // namespace mds

#endif // MDS_DensityCompressor_H

