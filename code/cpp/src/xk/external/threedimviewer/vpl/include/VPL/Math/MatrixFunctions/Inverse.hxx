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

