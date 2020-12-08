//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/16                          \n
 *
 * $Id: mdsInverse.hxx 2123 2012-02-22 10:28:33Z spanel $
 *
 * Description:
 * - Computes inverse of a square matrix.
 */


//==============================================================================
/*
 * Functions templates.
 */

template <class M>
inline void inverse(CMatrixBase<M>& Matrix)
{
    M& MatrixImpl = Matrix.getImpl();

    // Check that the matrix is square
    if( !MatrixImpl.isSquare() )
    {
        throw CInverseFailed();
    }

    MatrixImpl.asEigen() = MatrixImpl.asEigen().inverse().eval();
}

