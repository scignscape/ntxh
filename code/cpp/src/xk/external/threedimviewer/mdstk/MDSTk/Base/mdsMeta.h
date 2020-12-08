//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/07/16                          \n
 *
 * $Id: mdsMeta.h 1707 2010-05-05 11:00:46Z spanel $
 *
 * Description:
 * - Elementary metaprograms.
 */

#ifndef MDS_Meta_H
#define MDS_Meta_H

#include "mdsAssert.h"
#include "mdsStaticAssert.h"
#include "mdsTypeTraits.h"


namespace mds
{
namespace base
{

//==============================================================================
/*
 * Templates for dot product calculation.
 */

//! Calculates dot product of two vectors.
//! - Primary template.
template <int N, typename T>
struct CMetaDotProduct
{
    static T getResult(T *a, T *b)
    {
        return *a * *b + CMetaDotProduct<N-1,T>::getResult(a+1,b+1);
    }
};

//! Calculates dot product of two vectors.
//! - Partial specialization as end criteria.
template <typename T>
struct CMetaDotProduct<1,T>
{
    static T getResult(T* a, T* b)
    {
        return *a * *b;
    }
};

//! Calculates dot product of two vectors.
//! - Uses loop unrolling.
template <bool UseMeta, int N, typename T>
struct CMetaDotProductImpl
{
    static T getResult(T *a, T *b)
    {
        return CMetaDotProduct<N,T>::getResult(a,b);
    }
};

//! Calculates dot product of two vectors.
//! - Partial specialization.
//! - Common loop variant.
template <int N, typename T>
struct CMetaDotProductImpl<false,N,T>
{
    static T getResult(T* a, T* b)
    {
        T Result = T();
        for( int i = 0; i < N; ++i, ++a, ++b )
        {
            Result += *a * *b;
        }
        return Result;
    }
};

//! Calculates dot product of two vectors.
//! - Convenience function
template <int N, typename T>
inline T metaDotProduct(T* a, T* b)
{
    MDS_ASSERT(a && b);
    MDS_STATIC_ASSERT(CTypeTraits<T>::isFundamental,
                      VECTOR_ELEMENT_IS_NOT_A_FUNDAMENTAL_TYPE
                      );

    enum { UseMeta = N < 64 };
    return CMetaDotProductImpl<UseMeta,N,T>::getResult(a,b);
}


//==============================================================================
/*
 * Templates applying functor to a sequence of elements.
 */

//! Applies functor to a sequence of numbers.
//! - Primary template.
template <int N, typename T, class F>
struct CMetaForEach
{
    static void apply(T *p, F& Func)
    {
        Func(*p);
        CMetaForEach<N-1,T,F>::apply(p+1, Func);
    }
};

//! Applies functor to a sequence of numbers.
//! - Partial specialization as end criteria.
template <typename T, class F>
struct CMetaForEach<1,T,F>
{
    static void apply(T *p, F& Func)
    {
        Func(*p);
    }
};

//! Applies functor to a sequence of numbers.
//! - Uses loop unrolling.
template <bool UseMeta, int N, typename T, class F>
struct CMetaForEachImpl
{
    static void apply(T *p, F& Func)
    {
        CMetaForEach<N,T,F>::apply(p, Func);
    }
};

//! Applies functor to a sequence of numbers.
//! - Partial specialization.
//! - Common loop variant.
template <int N, typename T, class F>
struct CMetaForEachImpl<false,N,T,F>
{
    static void apply(T *p, F& Func)
    {
        for( int i = 0; i < N; ++i, ++p )
        {
            Func(*p);
        }
    }
};

//! Applies functor to a sequence of numbers.
//! - Convenience function.
template <int N, typename T, class Function>
inline Function metaForEach(T *p, Function Func)
{
    MDS_ASSERT(p);

    enum { UseMeta = N < 64 };
    CMetaForEachImpl<UseMeta,N,T,Function>::apply(p, Func);

    return Func;
}


} // namespace base
} // namespace mds

#endif // MDS_Meta_H

