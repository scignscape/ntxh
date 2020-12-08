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
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/03/03                       
 *
 * Description:
 * - Channel compression tools.
 */

#include <VPL/Module/Compressor.h>
#include <VPL/Module/CompressorFactory.h>

#include <VPL/System/Memory.h>
#include <VPL/Math/Base.h>


namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Compressor creation function.
 */
CChannelCompressor *CChannelCompressor::create(int Method, CChannel *pChannel)
{
    CChannelCompressor *p = VPL_FACTORY(CCompressorFactory).create(Method);
    p->setChannel(pChannel);
    return p;
}


} // namespace mod
} // namespace vpl

