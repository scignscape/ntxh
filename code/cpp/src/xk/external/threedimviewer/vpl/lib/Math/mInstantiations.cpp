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
 * Copyright (c) 2010 by Michal Spanel       
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz
 * Date:    2010/01/02                       
 * 
 * Description:
 * - Definition of basic template instantiations.
 */

#include <VPL/Math/Matrix.h>
#include <VPL/Math/StaticMatrix.h>
#include <VPL/Math/Vector.h>
#include <VPL/Math/StaticVector.h>
#include <VPL/Math/SparseMatrix.h>
#include <VPL/Math/SparseMatrixAlt.h>


namespace vpl
{
namespace math
{

//=============================================================================
/*
 * Basic template instantiations...
 */

#ifdef VPL_EXPLICIT_TEMPLATE_INSTANTIATION

template class CVector<int>;
template class CVector<float>;
template class CVector<double>;

template class CStaticVector<int, 2>;
template class CStaticVector<int, 3>;
template class CStaticVector<int, 4>;
template class CStaticVector<float, 2>;
template class CStaticVector<float, 3>;
template class CStaticVector<float, 4>;
template class CStaticVector<double, 2>;
template class CStaticVector<double, 3>;
template class CStaticVector<double, 4>;

template class CMatrix<int>;
template class CMatrix<float>;
template class CMatrix<double>;

template class CStaticMatrix<int, 2, 2>;
template class CStaticMatrix<int, 3, 3>;
template class CStaticMatrix<int, 4, 4>;
template class CStaticMatrix<float, 2, 2>;
template class CStaticMatrix<float, 3, 3>;
template class CStaticMatrix<float, 4, 4>;
template class CStaticMatrix<double, 2, 2>;
template class CStaticMatrix<double, 3, 3>;
template class CStaticMatrix<double, 4, 4>;

template class CSparseMatrix<int>;
template class CSparseMatrix<float>;
template class CSparseMatrix<double>;

template class CSparseMatrixAlt<int>;
template class CSparseMatrixAlt<float>;
template class CSparseMatrixAlt<double>;

#endif // VPL_EXPLICIT_TEMPLATE_INSTANTIATION


} // namespace math
} // namespace vpl
