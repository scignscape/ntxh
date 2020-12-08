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
 * Date:    2009/04/28                       
 *
 * Description:
 * - Density data compression tools.
 */

#ifndef VPL_DensityCompressor_H
#define VPL_DensityCompressor_H

#include "RLECompressor.h"
#include "GZipCompressor.h"
#include "Predictor.h"

// STL
#include <string>


namespace vpl
{
namespace mod
{

//==============================================================================
/*!
 * Class providing density data compression.
 */
class VPL_MODULE_EXPORT CDensityCompressor : public CChannelCompressor
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CDensityCompressor);

public:
    //! Constructor.
    CDensityCompressor(CChannel *pChannel = NULL);

    //! Destructor.
    virtual ~CDensityCompressor();

    // Virtual methods.
	virtual void setChannel(CChannel *pChannel) override;
	virtual tSize read(char *pcData, tSize iLength) override;
	virtual bool write(const char *pcData, tSize iLength) override;

protected:
    //! RLE compression.
    CRLE8Compressor m_Compressor;

    //! Density data predictor.
    CDensityPredictor m_Predictor;
};


//==============================================================================
/*!
 * Smart pointer to density data compressor.
 */
typedef CDensityCompressor::tSmartPtr   CDensityCompressorPtr;


} // namespace mod
} // namespace vpl

#endif // VPL_DensityCompressor_H

