//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2020 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/22                          \n
 *
 * $Id: mdsVersion.h 2039 2011-12-28 14:00:13Z spanel $
 *
 * Description:
 * - Version information.
 */

#ifndef MDS_Version_H
#define MDS_Version_H

// Configuration file
#include <MDSTk/configure.h>

// STL
#include <string>


namespace mds
{

//==============================================================================
/*
 * MDSTk informations.
 */

//! MDSTk label
const std::string LABEL     = "MDSTk";

//! Helper macro converts its parameter to string literal.
#define MDS_MAKE_STRING(Param)  #Param
#define MDS_P2STR(Param)        MDS_MAKE_STRING(Param)

//! Current MDSTk version
const std::string VERSION   = MDS_P2STR(MDS_MAJOR_VERSION) "." MDS_P2STR(MDS_MINOR_VERSION) "." MDS_P2STR(MDS_PATCH_VERSION);

//! Listing of MDSTk authors
const std::string AUTHORS   = "Michal Spanel, et al., FIT BUT, Czech Republic";

//! E-mail of the MDSTk authors
const std::string EMAIL     = "spanel@fit.vutbr.cz";


} // namespace mds

#endif // MDS_Version_H

