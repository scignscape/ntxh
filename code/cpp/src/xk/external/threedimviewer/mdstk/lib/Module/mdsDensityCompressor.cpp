//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/23                          \n
 *
 * $Id: mdsDensityCompressor.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Density data compression tools.
 */

#include <MDSTk/Module/mdsDensityCompressor.h>

#include <MDSTk/Math/mdsBase.h>


namespace mds
{
namespace mod
{

//==============================================================================
/*
 * Methods of the class mds::mod::CRLE8Compression.
 */
CDensityCompressor::CDensityCompressor(CChannel *pChannel) : CChannelCompressor(CC_DENSITY, pChannel)
{
    m_Predictor.setChannel(&m_Compressor);
    if( pChannel )
    {
//        m_Predictor.setChannel(pChannel);
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
//        m_Predictor.setChannel(pChannel);
        m_Compressor.setChannel(pChannel);
    }
}


int CDensityCompressor::read(char *pcData, int iLength)
{
    return m_Predictor.read(pcData, iLength);
}


bool CDensityCompressor::write(const char *pcData, int iLength)
{
    return m_Predictor.write(pcData, iLength);
}


} // namespace mod
} // namespace mds

