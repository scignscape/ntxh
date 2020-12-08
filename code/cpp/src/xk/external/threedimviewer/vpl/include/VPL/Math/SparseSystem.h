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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by PGMed@FIT         \n
 *
 * Author:  Miroslav Svub, svub@fit.vutbr.cz    \n
 * Date:    2007/04/01                          \n
 * 
 * Description:
 * - Sparse system solver.
 */

#ifndef VPL_SPARSESYSTEM_H
#define VPL_SPARSESYSTEM_H

#include "MathExceptions.h"
#include "SparseMatrix.h"
#include "SparseMatrixAlt.h"
#include "UMFpack.h"


#ifdef VPL_UMFPACK_ENABLED

namespace vpl
{
namespace math
{

//==============================================================================
/*
 * Global functions.
 */

//! This function solves sparse linear system Ax = b.
template <typename T>
void solve(CSparseMatrixAlt<T>& A, CVector<T>& b, CVector<T>& x)
{
    throw vpl::base::CNotImplemented();
}


//! Defined for sparse systems of double values
template <>
void solve(CSparseMatrixAlt<double>& A, CVector<double>& b, CVector<double>& x)
{
    typedef CSparseMatrixAlt<double> tMatrix;

    // test if passed vectors have stride of 1, which allows to directly access storage memory
    if( b.getStride() > 1 || x.getStride() > 1 )
    {
        throw CSparseSolverFailed();
    }

    // test whether right hand side is suitable for matrix of the system
    if( b.getSize() != A.getNumOfCols() )
    {
        throw CSparseSolverFailed();
    }

    // cast non-zero iterator
    tMatrix::tIterator it(A);

    // resize solution vector if necessary
    if( x.getSize() != A.getNumOfCols() )
    {
        x.resize(A.getNumOfCols());
        x.fill(0.0);
    }

    // create auxiliary arrays to use when calling umfpack routines
    int * Ap     = new int[A.getNumOfCols() + 1];
    int * Ai     = new int[A.getNumOfNonDominant()];
    double * Ax  = new double[A.getNumOfNonDominant()];
    double * rhs = b.getPtr(0);
    double * sol = x.getPtr(0);

    // iterate over matrix and convert it into compressed column form
    int col = -1;
    int i   = 0;
    int j   = 0;

    col = it.col();
    Ap[j] = 0;
    while( it )
    {
        if( it.col() > col )
        {
            col = it.col();
            Ap[++j] = i;
        }

        Ai[i] = it.row();
        Ax[i] = *it;
        ++i;
        ++it;
    }
    Ap[++j] = i;

    // define some umfpack-ish stuff
    double *null = (double *)NULL;
    void *Symbolic, *Numeric ;

    // call umfpack's fill-up reducing column reordering procedure
    (void)umfpack_di_symbolic(A.getNumOfRows(), A.getNumOfCols(), Ap, Ai,
                              Ax, &Symbolic, null, null
                              );

    // perform LU factorization
    (void)umfpack_di_numeric(Ap, Ai, Ax, Symbolic, &Numeric, null, null);

    // get rid of temporary results
    umfpack_di_free_symbolic(&Symbolic);

    // solve LU factorized system
    (void)umfpack_di_solve(UMFPACK_A, Ap, Ai, Ax, sol, rhs, Numeric, null, null);

    // get rid of everything
    umfpack_di_free_numeric(&Numeric);

    // free everything
    delete[] Ap;
    delete[] Ai;
    delete[] Ax;
}


} // namespace math
} // namespace vpl

#endif // VPL_UMFPACK_ENABLED
#endif // VPL_SPARSESYSTEM_H

