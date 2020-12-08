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


//==============================================================================
/*
 * Functions templates.
 */

template <class M, class V>
inline void eig(CMatrixBase<M>& Matrix, CVectorBase<V>& Values)
{
    typedef typename M::tElement tMatrixElement;
    M& MatrixImpl = Matrix.getImpl();

    typedef typename V::tElement tVectorElement;
    V& ValuesImpl = Values.getImpl();

    // Check matrix and vector elements types
    enum { Helper = vpl::SCheckIdentity<tMatrixElement, tVectorElement>::RESULT };
    VPL_STATIC_ASSERT(Helper, Matrix_element_type_differs_from_vector_type);

    // Check that the matrix is square
    if( !MatrixImpl.isSquare() )
    {
        throw CMathFunctionFailed();
    }

    Eigen::SelfAdjointEigenSolver<typename M::tStorage> Solver(MatrixImpl.asEigen(), Eigen::ComputeEigenvectors);
    if( Solver.info() != Eigen::Success )
    {
        throw CMathFunctionFailed();
    }

    MatrixImpl.asEigen() = Solver.eigenvectors();
    ValuesImpl.asEigen() = Solver.eigenvalues();
}

