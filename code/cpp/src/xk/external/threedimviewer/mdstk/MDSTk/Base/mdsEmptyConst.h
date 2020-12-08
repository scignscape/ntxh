//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2012 by 3Dim Laboratory s.r.o. \n
 *
 * Author:  info@3dim-laboratory.cz             \n
 * Date:    2012/01/29                          \n
 *
 * $Id:$
 *
 * Description:
 * - Data allocator policy.
 */

#ifndef MDS_EmptyConst_H
#define MDS_EmptyConst_H

#include "mdsSetup.h"


namespace mds
{

//==============================================================================
/*
 * Global definitions.
 */

//! Enumeration constant used for calling empty constructor of a class
//! that doesn't initialize any class members! It is usually a parameter
//! of the class constructor.
//! - Use with care!
enum EEmptyConst
{
    EMPTY_CONST
};


} // namespace mds

#endif // MDS_EmptyConst_H

