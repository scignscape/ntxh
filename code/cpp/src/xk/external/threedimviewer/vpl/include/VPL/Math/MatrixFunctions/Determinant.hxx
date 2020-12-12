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


//==============================================================================
/*
 * Functions templates.
 */

template <typename R, class M>
inline R getDeterminant(const CMatrixBase<M>& Matrix)
{
    const M& MatrixImpl = Matrix.getImpl();

    // Check that the matrix is square
    if( !MatrixImpl.isSquare() )
    {
        throw CMathFunctionFailed();
    }

    // Size of the matrix
    switch( MatrixImpl.getNumOfRows() )
    {
        // The matrix 1x1
        case 1:
            return R(MatrixImpl(0,0));

        // The matrix 2x2
        case 2:
        {
            R Result = R(MatrixImpl(0,0) * MatrixImpl(1,1));
            Result -= R(MatrixImpl(0,1) * MatrixImpl(1,0));
            return Result;
        }

        // The matrix 3x3
        case 3:
        {
            R Result = R(MatrixImpl(0,0) * MatrixImpl(1,1) * MatrixImpl(2,2));
            Result += R(MatrixImpl(0,1) * MatrixImpl(1,2) * MatrixImpl(2,0));
            Result += R(MatrixImpl(0,2) * MatrixImpl(1,0) * MatrixImpl(2,1));
            Result -= R(MatrixImpl(0,2) * MatrixImpl(1,1) * MatrixImpl(2,0));
            Result -= R(MatrixImpl(0,0) * MatrixImpl(1,2) * MatrixImpl(2,1));
            Result -= R(MatrixImpl(0,1) * MatrixImpl(1,0) * MatrixImpl(2,2));
            return Result;
        }

        // The matrix nxn
        default:
            return R(MatrixImpl.asEigen().determinant());
    }
}
