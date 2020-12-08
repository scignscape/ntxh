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
 * Date:    2005/09/08                       
 * 
 * Description:
 * - Output logging channel.
 */

#include <VPL/Base/LogChannel.h>


namespace vpl
{
namespace base
{

//==============================================================================
/*
 * Implementation of the class vpl::base::CLogChannelFStream.
 */
CLogChannelFStream::CLogChannelFStream(const char *pcFileName)
    : CLogChannelOStream(m_FileStream)
{
    m_FileStream.open(pcFileName);
}


CLogChannelFStream::CLogChannelFStream(const std::string& ssFileName)
    : CLogChannelOStream(m_FileStream)
{
    m_FileStream.open(ssFileName.c_str());
}


CLogChannelFStream::~CLogChannelFStream()
{
    m_FileStream.close();
}


} // namespace base
} // namespace vpl

