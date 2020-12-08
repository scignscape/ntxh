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
 * Date:    2009/03/23                       
 *
 * Description:
 * - Density data compression tools.
 */

#include <VPL/Module/DensityCompressor.h>

#include <VPL/Math/Base.h>


namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Methods of the class vpl::mod::CRLE8Compression.
 */
CDensityCompressor::CDensityCompressor(CChannel *pChannel) : CChannelCompressor(CC_DENSITY, pChannel)
{
    m_Predictor.setChannel(&m_Compressor);
    if( pChannel )
    {
        m_Compressor.setChannel(pChannel);
    }
}


CDensityCompressor::~CDensityCompressor()
{
}


void CDensityCompressor::setChannel(CChannel *pChannel)
{
    CChannelCompressor::setChannel(pChannel);
    if( pChannel )
    {
        m_Compressor.setChannel(pChannel);
    }
}


tSize CDensityCompressor::read(char *pcData, tSize iLength)
{
    return m_Predictor.read(pcData, iLength);
}


bool CDensityCompressor::write(const char *pcData, tSize iLength)
{
    return m_Predictor.write(pcData, iLength);
}


} // namespace mod
} // namespace vpl

