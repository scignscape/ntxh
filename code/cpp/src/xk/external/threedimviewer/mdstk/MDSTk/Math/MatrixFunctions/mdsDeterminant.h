//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/16                          \n
 *
 * $Id: mdsDeterminant.h 2049 2012-01-09 13:04:08Z spanel $
 *
 * Description:
 * - Computes determinant of a square matrix.
 */

#ifndef MDS_MatrixFunctions_Determinant_H
#define MDS_MatrixFunctions_Determinant_H

#include <MDSTk/Base/mdsStaticAssert.h>
#include <MDSTk/Math/mdsMatrixBase.h>
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

//! Returns determinant of a square matrix.
template <typename R, class M>
inline R getDeterminant(const CMatrixBase<M>& Matrix);


//==============================================================================
/*
 * Functions templates.
 */

// Include file containing methods templates
#include "mdsDeterminant.hxx"


} // namespace math
} // namespace mds

#endif // MDS_MatrixFunctions_Determinant_H

