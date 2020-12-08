//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/16                          \n
 *
 * $Id: mdsInverse.h 2049 2012-01-09 13:04:08Z spanel $
 *
 * Description:
 * - Computes inverse of a square matrix.
 */

#ifndef MDS_MATRIXFUNCTIONS_INVERSE_H
#define MDS_MATRIXFUNCTIONS_INVERSE_H

#include <MDSTk/Base/mdsStaticAssert.h>
#include <MDSTk/Math/mdsBase.h>
#include <MDSTk/Math/mdsMatrixBase.h>
#include <MDSTk/Math/mdsVectorBase.h>
#include <MDSTk/Math/mdsMathExceptions.h>

#include <Eigen/LU>


namespace mds
{
namespace math
{

//==============================================================================
/*
 * Global functions.
 */

//! Inplace computation of a square matrix inverse.
//! - Throws warning on failure.
template <class M>
inline void inverse(CMatrixBase<M>& Matrix);


//==============================================================================
/*
 * Functions templates.
 */

// Include file containing methods templates
#include "mdsInverse.hxx"


} // namespace math
} // namespace mds

#endif // MDS_MATRIXFUNCTIONS_INVERSE_H

