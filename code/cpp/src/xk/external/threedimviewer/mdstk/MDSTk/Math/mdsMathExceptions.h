//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/07/06                          \n
 *
 * $Id: mdsMathExceptions.h 2094 2012-02-16 01:54:45Z spanel $
 *
 * Description:
 * - Exceptions thrown by matrix functions.
 */

#ifndef MDS_MathExceptions_H
#define MDS_MathExceptions_H

#include <MDSTk/Base/mdsException.h>


namespace mds
{
namespace math
{

//=============================================================================
/*
 * Basic math exceptions.
 */

//! Exception thrown in case of failed multiplication, e.g. dimensions
//! of multiplied matrices do not match.
MDS_DECLARE_EXCEPTION(CMultFailed, "Multiplication has failed, dimensions do not match")

//! Exception thrown if the matrix cannot be transposed.
MDS_DECLARE_EXCEPTION(CTransposeFailed, "Failed to transpose a matrix")

//! Exception thrown if the matrix cannot be inverted.
MDS_DECLARE_EXCEPTION(CInverseFailed, "Failed to invert a matrix")

//! Sparse system solver error.
MDS_DECLARE_EXCEPTION(CSparseSolverFailed, "Failed to solve sparse system")

//! Math function failed.
MDS_DECLARE_EXCEPTION(CMathFunctionFailed, "Math function failed")


} // namespace math
} // namespace mds

#endif // MDS_MathExceptions_H

