//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/22                          \n
 *
 * $Id: mdsBuildDate.h 2042 2012-01-01 13:42:42Z spanel $
 * 
 * Description:
 * - Date and time of the last compilation.
 */

#ifndef MDS_BuildDate_H
#define MDS_BuildDate_H

#include "mdsBaseExport.h"

// STL
#include <string>


namespace mds
{

//==============================================================================
/*
 * Build date and time
 */

//! Date of the compilation
MDS_BASE_EXPORT const std::string BUILD_DATE = __DATE__;

//! Time of the compilation
MDS_BASE_EXPORT const std::string BUILD_TIME = __TIME__;


} // namespace mds

#endif // MDS_BuildDate_H

