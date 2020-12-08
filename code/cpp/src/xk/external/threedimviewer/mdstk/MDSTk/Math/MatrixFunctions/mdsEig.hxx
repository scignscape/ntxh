//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/10/12                          \n
 *
 * $Id: mdsEig.hxx 2097 2012-02-16 20:19:05Z spanel $
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
    enum { Helper = mds::SCheckIdentity<tMatrixElement, tVectorElement>::RESULT };
    MDS_STATIC_ASSERT(Helper, Matrix_element_type_differs_from_vector_type);

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

