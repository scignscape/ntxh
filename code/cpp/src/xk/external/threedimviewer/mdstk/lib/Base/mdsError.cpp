//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/27                          \n
 *
 * $Id: mdsError.cpp 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Error class.
 */

#include <MDSTk/Base/mdsError.h>


namespace mds
{
namespace base
{

//==============================================================================
/*
 * Methods of the class mds::CError.
 */
void CError::print(std::ostream& Stream) const
{
    Stream << '<' << m_sFilename << '>'
        << '<' << m_iLine << '>'
        << " Error: " << m_sReason
        << std::endl;
}


std::ostream& operator <<(std::ostream& Stream, const CError& Error)
{
    Error.print(Stream);
    return Stream;
}


} // namespace base
} // namespace mds

