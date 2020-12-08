//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2011 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2011/05/28                          \n
 *
 * $Id:$
 *
 * Description:
 * - Please, use this header file to include Eigen3 core!
 */

#ifndef MDS_EigenCore_H
#define MDS_EigenCore_H

#include <MDSTk/Base/mdsSetup.h>

// Disable annoying warnings in Eigen code
#if defined(_WIN32) && defined(_MSC_VER)
#   pragma warning( disable: 4308 )
#   pragma warning( disable: 4307 )
#endif // _MSC_VER

// Eigen3
#include <Eigen/Core>

// MDSTk-specific definitions
#include "mdsEigenNumTraits.h"


#endif // MDS_EigenCore_H
