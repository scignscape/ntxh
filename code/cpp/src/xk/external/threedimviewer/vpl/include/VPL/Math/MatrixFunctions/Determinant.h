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
 * Date:    2006/02/16                       
 *
 * Description:
 * - Computes determinant of a square matrix.
 */

#ifndef VPL_MatrixFunctions_Determinant_H
#define VPL_MatrixFunctions_Determinant_H

#include <VPL/Base/StaticAssert.h>
#include <VPL/Math/MatrixBase.h>
#include <VPL/Math/MathExceptions.h>

#include <Eigen/LU>


namespace vpl
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
#include "Determinant.hxx"


} // namespace math
} // namespace vpl

#endif // VPL_MatrixFunctions_Determinant_H

