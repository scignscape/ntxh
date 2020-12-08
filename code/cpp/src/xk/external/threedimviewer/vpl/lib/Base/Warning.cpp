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
 * Date:    2003/10/23                       
 * 
 * Description:
 * - Warning class.
 */

#include <VPL/Base/Warning.h>


namespace vpl
{
namespace base
{

//==============================================================================
/*
 * Methods of the class vpl::CWarning.
 */
void CWarning::print(std::ostream& Stream) const
{
    Stream << '<' << m_sFilename << '>'
    << '<' << m_iLine << '>'
    << " Warning: " << m_sReason
    << std::endl;
}


std::ostream& operator <<(std::ostream& Stream, const CWarning& Warning)
{
    Warning.print(Stream);
    return Stream;
}


} // namespace base
} // namespace vpl

