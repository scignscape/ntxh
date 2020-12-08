//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/23                          \n
 *
 * $Id: mdsWarning.cpp 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Warning class.
 */

#include <MDSTk/Base/mdsWarning.h>


namespace mds
{
namespace base
{

//==============================================================================
/*
 * Methods of the class mds::CWarning.
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
} // namespace mds

