//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/08                          \n
 *
 * $Id: mdsLogChannel.cpp 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Output logging channel.
 */

#include <MDSTk/Base/mdsLogChannel.h>


namespace mds
{
namespace base
{

//==============================================================================
/*
 * Implementation of the class mds::base::CLogChannelFStream.
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
} // namespace mds

