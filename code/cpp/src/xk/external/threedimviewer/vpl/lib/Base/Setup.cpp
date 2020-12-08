//==============================================================================
/* This file is part of
 *
 * VPL - Voxel Processing Library
 * Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <VPL/Base/Setup.h>


namespace vpl
{

//=============================================================================
/*
 * OpenMP functions
 */

#ifdef _OPENMP

int ompDefaultSettings()
{
    omp_set_nested(1);
    //omp_set_max_active_levels(8);
    omp_set_dynamic(0);
    int iNumOfProcs = omp_get_num_procs();
    int iNumOfThreads = (iNumOfProcs > 2) ? (3 * iNumOfProcs / 4) : iNumOfProcs;
    omp_set_num_threads(iNumOfThreads);
    return iNumOfThreads;
}

int ompGetMaxThreads()
{
    return omp_get_max_threads();
}

int ompGetThreadNum()
{
    return omp_get_thread_num();
}


#else // _OPENMP not defined

int ompDefaultSettings()
{
    return -1;
}

int ompGetMaxThreads()
{
    return 1;
}

int ompGetThreadNum()
{
    return 0;
}

#endif // _OPENMP


} // namespace vpl
