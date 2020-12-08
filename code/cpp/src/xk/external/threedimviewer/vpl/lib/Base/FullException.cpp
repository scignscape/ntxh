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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2008 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/04/24                          \n
 * 
 * Description:
 * - Complex exception class.
 */

#include <VPL/Base/FullException.h>


namespace vpl
{
namespace base
{

//==============================================================================
/*
 * Methods of the class vpl::base::CFullException.
 */
CFullException::CFullException(const std::string& sReason,
                               const std::string& sFilename,
                               int iLine
                               ) throw()
    : m_sReason(sReason)
    , m_sFilename(sFilename)
    , m_iLine(iLine)
{
}


CFullException::CFullException(const CFullException& e) throw()
    : m_sReason(e.m_sReason)
    , m_sFilename(e.m_sFilename)
    , m_iLine(e.m_iLine)
{
}

    
const char *CFullException::what( ) const throw()
{
    return m_sReason.c_str();
}


void CFullException::print(std::ostream& Stream) const
{
    Stream << '<' << m_sFilename << '>'
    << '<' << m_iLine << '>'
    << " Exception: " << m_sReason
    << std::endl;
}


std::ostream& operator <<(std::ostream& Stream, const CFullException& Exception)
{
    Exception.print(Stream);
    return Stream;
}


} // namespace base
} // namespace vpl

