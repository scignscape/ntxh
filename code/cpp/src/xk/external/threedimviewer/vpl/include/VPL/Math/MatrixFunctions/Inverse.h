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
 * - Computes inverse of a square matrix.
 */

#ifndef VPL_MATRIXFUNCTIONS_INVERSE_H
#define VPL_MATRIXFUNCTIONS_INVERSE_H

#include <VPL/Base/StaticAssert.h>
#include <VPL/Math/Base.h>
#include <VPL/Math/MatrixBase.h>
#include <VPL/Math/VectorBase.h>
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

//! Inplace computation of a square matrix inverse.
//! - Throws warning on failure.
template <class M>
inline void inverse(CMatrixBase<M>& Matrix);


//==============================================================================
/*
 * Functions templates.
 */

// Include file containing methods templates
#include "Inverse.hxx"


} // namespace math
} // namespace vpl

#endif // VPL_MATRIXFUNCTIONS_INVERSE_H
