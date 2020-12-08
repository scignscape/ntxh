//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/10/12                          \n
 *
 * $Id: mdsEig.h 2089 2012-02-14 00:13:24Z spanel $
 *
 * Description:
 * - Computes eigenvalues and eigenvectors of a square symmetric matrix.
 */

#ifndef MDS_MatrixFunctions_Eig_H
#define MDS_MatrixFunctions_Eig_H

#include <MDSTk/Base/mdsStaticAssert.h>
#include <MDSTk/Base/mdsTemplates.h>
#include <MDSTk/Math/mdsMatrixBase.h>
#include <MDSTk/Math/mdsVectorBase.h>
#include <MDSTk/Math/mdsMathExceptions.h>

#include <Eigen/Eigenvalues>


namespace mds
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
#include "mdsEig.hxx"


} // namespace math
} // namespace mds

#endif // MDS_MatrixFunctions_Eig_H

