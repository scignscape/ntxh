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
 * Date:    2006/10/12                       
 *
 * Description:
 * - Computes eigenvalues and eigenvectors of a square symmetric matrix.
 */

#ifndef VPL_MatrixFunctions_Eig_H
#define VPL_MatrixFunctions_Eig_H

#include <VPL/Base/StaticAssert.h>
#include <VPL/Base/Templates.h>
#include <VPL/Math/MatrixBase.h>
#include <VPL/Math/VectorBase.h>
#include <VPL/Math/MathExceptions.h>

#include <Eigen/Eigenvalues>


namespace vpl
{
namespace math
{

//==============================================================================
/*
 * Global functions.
 */

//! Inplace computation of eigenvalues and eigenvectors of a square
//! symmetric matrix.
//! - Throws warning on failure.
template <class M, class V>
inline void eig(CMatrixBase<M>& Matrix, CVectorBase<V>& Values);


//==============================================================================
/*
 * Functions templates.
 */

// Include file containing methods templates
#include "Eig.hxx"


} // namespace math
} // namespace vpl

#endif // VPL_MatrixFunctions_Eig_H

