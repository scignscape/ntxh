//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2010 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/02                          \n
 *
 * $Id: mdsInstantiations.cpp 2079 2012-02-06 21:46:08Z spanel $
 * 
 * Description:
 * - Definition of basic template instantiations.
 */

#include <MDSTk/Math/mdsMatrix.h>
#include <MDSTk/Math/mdsStaticMatrix.h>
#include <MDSTk/Math/mdsVector.h>
#include <MDSTk/Math/mdsStaticVector.h>
#include <MDSTk/Math/mdsSparseMatrix.h>
#include <MDSTk/Math/mdsSparseMatrixAlt.h>


namespace mds
{
namespace math
{

//=============================================================================
/*
 * Basic template instantiations...
 */

#ifdef MDS_EXPLICIT_TEMPLATE_INSTANTIATION

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

#endif // MDS_EXPLICIT_TEMPLATE_INSTANTIATION


} // namespace math
} // namespace mds
