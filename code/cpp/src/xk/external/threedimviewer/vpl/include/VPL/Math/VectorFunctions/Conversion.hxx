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
 * Date:    2006/09/15                       
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
    return CStaticVector<T,1>().set(tSize(0), Value);
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

