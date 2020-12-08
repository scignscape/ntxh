//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/15                          \n
 *
 * $Id: mdsGeneral.h 2049 2012-01-09 13:04:08Z spanel $
 *
 * Description:
 * - General vector functions.
 */

#ifndef MDS_VECTORFUNCTIONS_GENERAL_H
#define MDS_VECTORFUNCTIONS_GENERAL_H

#include <MDSTk/Base/mdsStaticAssert.h>
#include <MDSTk/Math/mdsBase.h>
#include <MDSTk/Math/mdsVectorBase.h>

// STL
#include <cmath>
#include <ostream>


namespace mds
{
namespace math
{

//==============================================================================
/*
 * Global functions.
 */

//! Returns inner product of two vectors.
//! - Takes into account only the overlapping part of both vectors.
template <typename R, class V1, class V2>
inline R getProd(const CVectorBase<V1>& Vector1, const CVectorBase<V2>& Vector2);

//! Sum of elements in the vector.
template <typename R, class V>
inline R getSum(const CVectorBase<V>& Vector);

//! Multiplication of all elements in the vector.
template <typename R, class V>
inline R getMult(const CVectorBase<V>& Vector);

//! Sum of squares of elements in the vector.
template <typename R, class V>
inline R getSumOfSquares(const CVectorBase<V>& Vector);

//! Normalized mean square error between two vectors - 1/N * sum((v1 - v2)^2).
template <typename R, class V1, class V2>
inline R getSquareError(const CVectorBase<V1>& Vector1, const CVectorBase<V2>& Vector2);

//! Normalized mean error between two vectors - 1/N * sum(abs(v1 - v2)).
template <typename R, class V1, class V2>
inline R getError(const CVectorBase<V1>& Vector1, const CVectorBase<V2>& Vector2);

//! Mean of vector elements.
template <typename R, class V>
inline R getMean(const CVectorBase<V>& Vector);

//! Variance of vector elements.
//! - Standard deviation is square root of the returned variance!
template <typename R, class V>
inline R getVariance(const CVectorBase<V>& Vector);

//! Minimum element in the vector
template <typename R, class V>
inline R getMin(const CVectorBase<V>& Vector);

//! Maximum element in the vector
template <typename R, class V>
inline R getMax(const CVectorBase<V>& Vector);

//! Prints the vector to a given output stream.
template <class V>
std::ostream& operator <<(std::ostream& Stream, const CVectorBase<V>& Vector);

//! Operation: R += A
template <class V1, class V2>
inline void inplaceAdd(CVectorBase<V2>& R, const CVectorBase<V1>& A);

//! Operation: R += A
template <class V1, class V2>
inline void inplaceSub(CVectorBase<V2>& R, const CVectorBase<V1>& A);

//! Operation: R += A * b
template <typename T, class V1, class V2>
inline void inplaceMultAdd(CVectorBase<V2>& R, const CVectorBase<V1>& A, const T& b);


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "mdsGeneral.hxx"


} // namespace math
} // namespace mds

#endif // MDS_VECTORFUNCTIONS_GENERAL_H

