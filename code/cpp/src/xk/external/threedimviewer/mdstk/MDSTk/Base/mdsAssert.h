//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/16                          \n
 *
 * $Id: mdsAssert.h 1707 2010-05-05 11:00:46Z spanel $
 *
 * Description:
 * - Assert macro definition.
 */

#ifndef MDS_ASSERT_H
#define MDS_ASSERT_H

#include "mdsSetup.h"

// STL
#include <cassert>


//==============================================================================
/*
 * Macros
 */

//! Assertion macro.
#ifdef _DEBUG
#	define MDS_ASSERT(cond)		assert(cond)
#else
#	define MDS_ASSERT(cond)
#endif

//! Condition checking macro.
#define MDS_CHECK(cond, stmt)	{ if( (!(cond)) ) { stmt; } }


#endif // MDS_ASSERT_H

