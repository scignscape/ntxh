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

#ifndef VPL_VectorFunctions_Conversion_H
#define VPL_VectorFunctions_Conversion_H

#include <VPL/Base/StaticAssert.h>
#include <VPL/Math/StaticVector.h>


namespace vpl
{
namespace math
{

//==============================================================================
/*
 * Helper definitions.
 */

//! Helper structure used to create vector from fundamental types.
struct SFundamentalType {};

//! Helper structure used to create vector from fundamental types.
struct SVectorType {};


//! Helper structure used to create vector from fundamental types.
template <typename T>
struct SMakeVector
{
    //! True if type T is fundamental.
    enum { isFundamental = vpl::CTypeTraits<T>::isFundamental };

    //! Type of the operation.
    typedef typename SSelect<isFundamental, SFundamentalType, SVectorType>::RESULT tType;

    //! Result of the operation.
    typedef typename SSelect<isFundamental, CStaticVector<T,1>, T>::RESULT tResult;
};


//==============================================================================
/*
 * Global functions.
 */

//! Returns reference to a vector.
//! - If type T is a fundamental type, static vector of size 1 is returned.
template <typename T>
inline typename SMakeVector<T>::tResult makeVector(const T& Value);


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "Conversion.hxx"


} // namespace math
} // namespace vpl

#endif // VPL_VectorFunctions_Conversion_H

