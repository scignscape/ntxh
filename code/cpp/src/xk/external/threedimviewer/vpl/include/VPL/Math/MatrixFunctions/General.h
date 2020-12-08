//==============================================================================
/* This file comes from MDSTk software and was modified for
 * 
 * VPL - Voxel Processing Library
 * Changes are Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 * 
 * The original MDSTk legal notice can be found below.
 * 
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2010 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/15                       
 *
 * Description:
 * - General matrix functions.
 */

#ifndef VPL_MATRIXFUNCTIONS_GENERAL_H
#define VPL_MATRIXFUNCTIONS_GENERAL_H

#include <VPL/Base/StaticAssert.h>
#include <VPL/Math/Base.h>
#include <VPL/Math/VectorBase.h>

// STL
#include <cmath>


namespace vpl
{
namespace math
{

//==============================================================================
/*
 * Global functions.
 */

//! Inner product of two matrices.
template <typename R, class M1, class M2>
inline R getProduct(const CMatrixBase<M1>& Matrix1, const CMatrixBase<M2>& Matrix2);

//! Normalized mean square error between elements of two matrices - 1/N * sum((m1 - m2)^2).
template <typename R, class M1, class M2>
inline R getSquareError(const CMatrixBase<M1>& Matrix1, const CMatrixBase<M2>& Matrix2);

//! Returns sum of all matrix elements.
template <typename R, class M>
inline R getSum(const CMatrixBase<M>& Matrix);

//! Returns result of multiplication of all matrix elements.
template <typename R, class M>
inline R getMult(const CMatrixBase<M>& Matrix);

//! Returns sum of squares of the matrix elements.
template <typename R, class M>
inline R getSumOfSquares(const CMatrixBase<M>& Matrix);

//! Returns trace of the square matrix.
//! - Trace of an n-by-n square matrix A is defined to be the sum
//!   of the elements on the main diagonal.
//! - If the matrix is not square, only its square part is taken.
template <typename R, class M>
inline R getTrace(const CMatrixBase<M>& Matrix);

//! Mean value of matrix elements.
template <typename R, class M>
inline R getMean(const CMatrixBase<M>& Matrix);

//! Variance of matrix elements.
//! - Standard deviation is square root of the returned variance!
template <typename R, class M>
inline R getVariance(const CMatrixBase<M>& Matrix);

//! Minimum value in the matrix.
template <typename R, class M>
inline R getMin(const CMatrixBase<M>& Matrix);

//! Maximum value in the matrix.
template <typename R, class M>
inline R getMax(const CMatrixBase<M>& Matrix);

//! Prints the matrix to a given output stream.
template <class M>
std::ostream& operator <<(std::ostream& Stream, const CMatrixBase<M>& Matrix);


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "General.hxx"


} // namespace math
} // namespace vpl

#endif // VPL_MATRIXFUNCTIONS_GENERAL_H

