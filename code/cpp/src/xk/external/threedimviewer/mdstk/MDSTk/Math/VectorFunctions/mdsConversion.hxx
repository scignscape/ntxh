//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/09/15                          \n
 *
 * $Id: mdsConversion.hxx 1718 2010-05-13 11:12:10Z spanel $
 *
 * Description:
 * - Vector conversion functions.
 */


//==============================================================================
/*
 * Helper functions.
 */

//! Specialization of the function.
template <typename T>
inline const T& makeVectorImpl(const T& Value, SVectorType)
{
    return Value;
}


//! Specialization of the function.
template <typename T>
inline T& makeVectorImpl(T& Value, SVectorType)
{
    return Value;
}


//! Specialization of the function.
template <typename T>
inline CStaticVector<T,1> makeVectorImpl(T& Value, SFundamentalType)
{
    return CStaticVector<T,1>().set(0, Value);
}


//! Specialization of the function.
template <typename T>
inline CStaticVector<T,1> makeVectorImpl(const T& Value, SFundamentalType)
{
    return CStaticVector<T,1>().set(0, Value);
}


//==============================================================================
/*
 * Functions templates.
 */

template <typename T>
inline typename SMakeVector<T>::tResult makeVector(const T& Value)
{
    typedef typename SMakeVector<T>::tType tType;

    return makeVectorImpl<T>(Value, tType());
}

