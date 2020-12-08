//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 * 
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/11/29                          \n
 *
 * $Id: mdsStaticAssert.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Static assert macro definition
 */

#ifndef MDS_STATICASSERT_H
#define MDS_STATICASSERT_H

#include "mdsSetup.h"


namespace mds
{

//==============================================================================
/*!
 * Helper structure for the static assertation macro.
 */
template <int>
struct SCompileTimeError;

//! Specialization of the sCompileTimeError helper structure.
template <>
struct SCompileTimeError<true> {};


//==============================================================================
/*
 * Macros
 */

//! Static assertation macro. Parameter cond is a compile-time integral
//! or pointer expression. If cond is zero, msg will appear in a compile-time
//! error message.
#define MDS_STATIC_ASSERT(cond, msg) \
{ \
    mds::SCompileTimeError<((cond) != 0)> MDS_ERROR_##msg; (void)MDS_ERROR_##msg; \
}


} // namespace mds

#endif // MDS_STATICASSERT_H

