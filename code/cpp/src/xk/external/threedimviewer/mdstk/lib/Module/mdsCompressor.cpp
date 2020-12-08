//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/03/03                          \n
 *
 * $Id: mdsCompressor.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Channel compression tools.
 */

#include <MDSTk/Module/mdsCompressor.h>
#include <MDSTk/Module/mdsCompressorFactory.h>

#include <MDSTk/Base/mdsMemory.h>
#include <MDSTk/Math/mdsBase.h>


namespace mds
{
namespace mod
{

//==============================================================================
/*
 * Compressor creation function.
 */
CChannelCompressor *CChannelCompressor::create(int Method, CChannel *pChannel)
{
    CChannelCompressor *p = MDS_FACTORY(CCompressorFactory).create(Method);
    p->setChannel(pChannel);
    return p;
}


} // namespace mod
} // namespace mds

