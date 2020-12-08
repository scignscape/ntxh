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
 * Date:    2006/02/12                       
 *
 * Description:
 * - Base class for all vectors.
 */

#ifndef VPL_QUATERNIONBASE_H
#define VPL_QUATERNIONBASE_H

#include <VPL/Base/Setup.h>
#include <VPL/Base/Scalar.h>

namespace vpl
{
namespace math
{

//==============================================================================
/*!
 * Traits used to implement curiously recurring template pattern for vectors.
 */
template <typename M>
struct CQuaternionTraits
{
    //! Quaternion coefficient type.
    typedef tNull tElement;   
};

//! Helper macro used to declare vector traits before a vector class template.
#define VPL_QUATERNION_TRAITS(QuaternionClass) \
    template <typename T> class QuaternionClass; \
    template <typename T> \
    struct CQuaternionTraits<QuaternionClass<T> > \
    { \
    typedef T tElement; \
};

template <class Q>
class CQuaternionBase 
{
public:
    //! Quaternion class type
    typedef Q tQuaternion;

    //! Element type
    typedef typename CQuaternionTraits<Q>::tElement tElement;

public:
    //! Returns reference to the quaternion implementation
    tQuaternion& getImpl() { return *static_cast<tQuaternion *>(*this); }

    //! Return const reference to the quaternion implementation
    const tQuaternion& getImpl() const { return *static_cast<const tQuaternion *>(this); }



}; // class CQuaternionBase


}   // namespace math
}   // namespace vpl

// VPL_QUATERNIONBASE_H
#endif

