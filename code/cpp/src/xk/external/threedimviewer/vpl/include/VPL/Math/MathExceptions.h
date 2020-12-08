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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/07/06                          \n
 *
 * Description:
 * - Exceptions thrown by matrix functions.
 */

#ifndef VPL_MathExceptions_H
#define VPL_MathExceptions_H

#include <VPL/Base/Exception.h>


namespace vpl
{
namespace math
{

//=============================================================================
/*
 * Basic math exceptions.
 */

//! Exception thrown in case of failed multiplication, e.g. dimensions
//! of multiplied matrices do not match.
VPL_DECLARE_EXCEPTION(CMultFailed, "Multiplication has failed, dimensions do not match")

//! Exception thrown if the matrix cannot be transposed.
VPL_DECLARE_EXCEPTION(CTransposeFailed, "Failed to transpose a matrix")

//! Exception thrown if the matrix cannot be inverted.
VPL_DECLARE_EXCEPTION(CInverseFailed, "Failed to invert a matrix")

//! Sparse system solver error.
VPL_DECLARE_EXCEPTION(CSparseSolverFailed, "Failed to solve sparse system")

//! Math function failed.
VPL_DECLARE_EXCEPTION(CMathFunctionFailed, "Math function failed")


} // namespace math
} // namespace vpl

#endif // VPL_MathExceptions_H

